#!/usr/bin/env python3
"""Havok binary packfile reader (layout as found in Top Spin 4, Havok-5.5.0-r1, Xbox 360).

All structure here was measured from the game's files; see docs/havok.md.

File header (0x40 bytes, integers in the file's byte order):
  0x00 u32 magic0 = 0x57E0E057     0x04 u32 magic1 = 0x10C0C010
  0x08 u32 user_tag                0x0C u32 file_version (5 for Havok 5.5)
  0x10 u8[4] layout rules: pointer size, little-endian flag, reuse-padding flag,
       empty-base-class flag (Xbox 360: 04 00 00 01)
  0x14 u32 num_sections            0x18 u32 contents_section_index
  0x1C u32 contents_section_offset 0x20 u32 contents_classname_section_index
  0x24 u32 contents_classname_section_offset
  0x28 char[16] contents version string ("Havok-5.5.0-r1")
  0x38 u32 flags                   0x3C u32 pad
Section headers follow (0x30 bytes each):
  char[20] name (NUL padded, last byte 0xFF), then u32 absolute_data_start and the
  section-relative offsets local_fixups, global_fixups, virtual_fixups, exports,
  imports, end.
Fixup tables (section relative; entries with first word 0xFFFFFFFF are padding):
  local   (src, dst)                 pointer at src -> same section offset dst
  global  (src, dst_section, dst)    pointer at src -> other section offset dst
  virtual (src, cn_section, cn_off)  an object of class <name at cn_off> starts at src
"""
import struct

MAGIC = (0x57E0E057, 0x10C0C010)
SECTION_HEADER_SIZE = 0x30


class Section:
    def __init__(self, name, start, local, glob, virt, exports, imports, end):
        self.name, self.start = name, start
        self.local_off, self.global_off, self.virtual_off = local, glob, virt
        self.exports_off, self.imports_off, self.end_off = exports, imports, end

    @property
    def data_size(self):
        return self.local_off

    def __repr__(self):
        return "<Section %s @0x%X data=0x%X end=0x%X>" % (self.name, self.start, self.local_off, self.end_off)


def _table(buf, base, start, end, width, endian):
    """Read fixed-width u32 tuples from [start, end), skipping 0xFFFFFFFF padding."""
    out = []
    fmt = endian + "%dI" % width
    step = 4 * width
    p = base + start
    stop = base + end
    while p + step <= stop:
        t = struct.unpack_from(fmt, buf, p)
        p += step
        if t[0] == 0xFFFFFFFF:
            continue
        out.append(t)
    return out


class Packfile:
    """Parsed packfile. Pointers are resolved as (section_index, offset) pairs.

    obj_class: {(sec, off): class_name}   from virtual fixups
    pointers:  {(sec, off): (sec2, off2)} from local + global fixups
    """

    def __init__(self, data):
        self.data = bytes(data)
        m0, m1 = struct.unpack_from(">II", self.data, 0)
        if (m0, m1) != MAGIC:
            m0, m1 = struct.unpack_from("<II", self.data, 0)
            if (m0, m1) != MAGIC:
                raise ValueError("not a Havok packfile")
        rules = self.data[0x10:0x14]
        self.ptr_size, self.little_endian, self.reuse_padding, self.empty_base = rules
        self.e = "<" if self.little_endian else ">"
        e = self.e
        (self.user_tag, self.file_version) = struct.unpack_from(e + "2I", self.data, 8)
        (self.num_sections, self.contents_section, self.contents_offset,
         self.contents_cn_section, self.contents_cn_offset) = struct.unpack_from(e + "5I", self.data, 0x14)
        self.version = self.data[0x28:0x38].split(b"\0")[0].decode("latin-1")
        self.flags = struct.unpack_from(e + "I", self.data, 0x38)[0]
        self.sections = []
        for i in range(self.num_sections):
            p = 0x40 + i * SECTION_HEADER_SIZE
            name = self.data[p:p + 20].split(b"\0")[0].decode("latin-1")
            vals = struct.unpack_from(e + "7I", self.data, p + 20)
            self.sections.append(Section(name, *vals))
        self._fixups()

    def section_index(self, name):
        for i, s in enumerate(self.sections):
            if s.name == name:
                return i
        return None

    def _fixups(self):
        e = self.e
        self.pointers = {}
        self.obj_class = {}
        self.local_fixups, self.global_fixups, self.virtual_fixups = [], [], []
        for si, s in enumerate(self.sections):
            loc = _table(self.data, s.start, s.local_off, s.global_off, 2, e)
            glo = _table(self.data, s.start, s.global_off, s.virtual_off, 3, e)
            vir = _table(self.data, s.start, s.virtual_off, s.exports_off, 3, e)
            for src, dst in loc:
                self.pointers[(si, src)] = (si, dst)
            for src, dsec, dst in glo:
                self.pointers[(si, src)] = (dsec, dst)
            for src, csec, coff in vir:
                self.obj_class[(si, src)] = self.cstring(csec, coff)
            self.local_fixups.append(loc)
            self.global_fixups.append(glo)
            self.virtual_fixups.append(vir)

    # --- raw access -------------------------------------------------------
    def abs(self, sec, off):
        return self.sections[sec].start + off

    def u8(self, sec, off):
        return self.data[self.abs(sec, off)]

    def u16(self, sec, off):
        return struct.unpack_from(self.e + "H", self.data, self.abs(sec, off))[0]

    def s16(self, sec, off):
        return struct.unpack_from(self.e + "h", self.data, self.abs(sec, off))[0]

    def u32(self, sec, off):
        return struct.unpack_from(self.e + "I", self.data, self.abs(sec, off))[0]

    def s32(self, sec, off):
        return struct.unpack_from(self.e + "i", self.data, self.abs(sec, off))[0]

    def f32(self, sec, off):
        return struct.unpack_from(self.e + "f", self.data, self.abs(sec, off))[0]

    def floats(self, sec, off, n):
        return list(struct.unpack_from(self.e + "%df" % n, self.data, self.abs(sec, off)))

    def raw(self, sec, off, n):
        a = self.abs(sec, off)
        return self.data[a:a + n]

    def cstring(self, sec, off):
        a = self.abs(sec, off)
        return self.data[a:self.data.index(b"\0", a)].decode("latin-1")

    def ptr(self, sec, off):
        """Resolve the pointer stored at (sec, off), or None if it is null/unfixed."""
        return self.pointers.get((sec, off))

    def string_ptr(self, sec, off):
        t = self.ptr(sec, off)
        return None if t is None else self.cstring(*t)

    # --- class names ------------------------------------------------------
    def classnames(self):
        """List of (offset, signature, name) from the __classnames__ section."""
        si = self.section_index("__classnames__")
        if si is None:
            return []
        s = self.sections[si]
        buf = self.data[s.start:s.start + s.data_size]
        out, p = [], 0
        while p + 5 <= len(buf):
            sig = struct.unpack_from(self.e + "I", buf, p)[0]
            if sig == 0xFFFFFFFF or buf[p + 4] != 0x09:
                break
            end = buf.index(b"\0", p + 5)
            out.append((p + 5, sig, buf[p + 5:end].decode("latin-1")))
            p = end + 1
        return out

    def objects(self, class_name=None, section=None):
        """Objects (sec, off) in file order, optionally filtered by class name."""
        out = []
        for key, cn in self.obj_class.items():
            if class_name is not None and cn != class_name:
                continue
            if section is not None and key[0] != section:
                continue
            out.append(key)
        return sorted(out)

    def contents(self):
        """(sec, off, class_name) of the top-level object."""
        return (self.contents_section, self.contents_offset,
                self.cstring(self.contents_cn_section, self.contents_cn_offset))
