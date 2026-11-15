#!/usr/bin/env python3
"""Write an Xbox 360 XEX2 whose image is an (edited) decompressed memory image.

The output keeps every header of the original XEX and only rewrites the base-file-format
header (optional header 0x3FF) so that the image is stored *unencrypted and uncompressed*:

  original 0x3FF (0x24 bytes): size=0x24, encryption=1 (AES-128-CBC), compression=2 (LZX, 0x8000
                                window, block size + SHA-1 chain)
  basic    0x3FF (0x10 bytes): size=0x10, encryption=0, compression=1 (basic), one block
                                {data_size = image size, zero_size = 0}
  none     0x3FF (0x08 bytes): size=0x08, encryption=0, compression=0   (--compression none)

Header fields changed (everything else, including the 0x3000-byte header size, the optional-header
table, import libraries, execution info, security info with its page descriptors, RSA signature and
file key, is copied byte for byte):
  * the 0x3FF block as above; bytes left over from the old 0x24-byte block are zeroed;
    the optional-header table offset of 0x3FF does not move, so nothing else shifts.
Nothing else changes: image size and load address are unchanged, so the image length must equal the
original image size.  Page-descriptor SHA-1 hashes, the header hash and the RSA signature are NOT
recomputed (they are stale); Xenia does not check them, a real console would refuse the file.

What Xenia needs (read from xenia src/xenia/cpu/xex_module.cc): for basic compression it sums
data_size+zero_size over (info_size-8)/8 blocks, allocates sum(page_descriptor.page_count) heap pages
(64 KiB each below 0x90000000), copies each block when encryption is 0; for compression 0 it copies
file_size-header_size bytes.  Hashes and signatures are never examined.  Then it checks the MZ/PE
headers inside the image.

Reading side: the repo's tools/xex_patch.py (Xex/base_image) decodes basic+unencrypted files, so
`verify()` re-reads the output with it.  The retail key (needed only to read the ORIGINAL xex) is
loaded at run time from the local jeff checkout via xex_patch.load_retail_key; it is never stored.

  python3 tools/xex_write.py extract ORIG.xex IMAGE_OUT
  python3 tools/xex_write.py write   ORIG.xex IMAGE OUT.xex [--compression basic|none]
Output paths must be under work/modpatch/.
"""
from __future__ import annotations

import argparse
import hashlib
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import xex_patch  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT_ROOT = os.path.join(ROOT, "work", "modpatch")
FILE_FORMAT_KEY = 0x3FF


def check_out_path(path):
    p = os.path.realpath(path)
    root = os.path.realpath(OUT_ROOT)
    if os.path.commonpath([p, root]) != root or p == root:
        raise SystemExit("refusing: output must be a file under %s" % root)
    return p


def decode_image(xex_bytes, retail_key=None):
    """Decompressed, decrypted memory image of an XEX (original LZX/AES or one written by write_xex)."""
    x = xex_patch.Xex(xex_bytes)
    enc, _comp, _ff = x.file_format()
    if retail_key is None:
        if enc == 0:
            retail_key = b"\0" * 16  # the session key is unused for unencrypted images
        else:
            retail_key = xex_patch.load_retail_key(xex_patch.DEFAULT_KEY_SRC)
    if enc == 0:
        # unencrypted: the AES session key is not needed, so do not require the `cryptography` package
        saved = xex_patch.aes_ecb_dec
        xex_patch.aes_ecb_dec = lambda key, block: b"\0" * 16
        try:
            img, _session = xex_patch.base_image(x, retail_key)
        finally:
            xex_patch.aes_ecb_dec = saved
        return img
    img, _session = xex_patch.base_image(x, retail_key)
    return img


def build_file_format(compression, image_size):
    if compression == "basic":
        return struct.pack(">IHHII", 0x10, 0, 1, image_size, 0)
    if compression == "none":
        return struct.pack(">IHH", 8, 0, 0)
    raise ValueError("compression must be basic or none")


def write_xex(orig, image, compression="basic"):
    """Return the bytes of a new XEX: original headers + `image` stored raw."""
    x = xex_patch.Xex(orig)
    if len(image) != x.image_size:
        raise ValueError("image is %#x bytes, XEX image size is %#x (growing the image is not supported)"
                         % (len(image), x.image_size))
    if image[:2] != b"MZ":
        raise ValueError("image does not start with an MZ header")
    off = x.opt[FILE_FORMAT_KEY]
    old_size = struct.unpack_from(">I", orig, off)[0]
    new = build_file_format(compression, len(image))
    if len(new) > old_size:
        raise ValueError("new file-format block does not fit")
    hdr = bytearray(orig[:x.data_off])
    hdr[off:off + old_size] = new + b"\0" * (old_size - len(new))
    return bytes(hdr) + bytes(image)


def verify(out_bytes, image, orig=None):
    """Re-read `out_bytes` with the repo's XEX reader; return a dict of facts, raise on mismatch."""
    got = decode_image(out_bytes)
    if got != image:
        first = next(i for i in range(len(image)) if got[i] != image[i])
        raise AssertionError("round trip differs at image offset %#x" % first)
    x = xex_patch.Xex(out_bytes)
    enc, comp, ff = x.file_format()
    facts = dict(encryption=enc, compression=comp, file_format_size=len(ff),
                 image_sha256=hashlib.sha256(got).hexdigest(), file_size=len(out_bytes))
    if orig is not None:
        o = xex_patch.Xex(orig)
        # headers other than the 0x3FF block must be unchanged
        ho, hn = bytearray(orig[:o.data_off]), bytearray(out_bytes[:x.data_off])
        s = o.opt[FILE_FORMAT_KEY]
        n = struct.unpack_from(">I", orig, s)[0]
        ho[s:s + n] = hn[s:s + n] = b"\0" * n
        if ho != hn:
            raise AssertionError("header bytes outside the 0x3FF block changed")
        facts["header_unchanged_outside_3FF"] = True
    return facts


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    e = sub.add_parser("extract")
    e.add_argument("xex")
    e.add_argument("image_out")
    w = sub.add_parser("write")
    w.add_argument("xex")
    w.add_argument("image")
    w.add_argument("out")
    w.add_argument("--compression", choices=["basic", "none"], default="basic")
    a = ap.parse_args(argv)
    orig = open(a.xex, "rb").read()
    if a.cmd == "extract":
        out = check_out_path(a.image_out)
        os.makedirs(os.path.dirname(out), exist_ok=True)
        open(out, "wb").write(decode_image(orig))
        print("wrote", out)
        return 0
    image = open(a.image, "rb").read()
    out = check_out_path(a.out)
    data = write_xex(orig, image, a.compression)
    if a.compression == "basic":
        print(verify(data, image, orig))
    os.makedirs(os.path.dirname(out), exist_ok=True)
    open(out, "wb").write(data)
    print("wrote", out, len(data), "bytes")
    return 0


if __name__ == "__main__":
    sys.exit(main())
