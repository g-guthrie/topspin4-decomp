#!/usr/bin/env python3
"""Top Spin 4 mesh / material / scene parsers (Xbox 360 retail disc, Pam engine).

Everything is big endian.  Pointers inside the XBin images are self relative: a
pointer word at address A holding r points at A + r (0xFFFFFFFF means "none"); an
array descriptor is 12 bytes ``{rel, count, capacity}`` whose elements start at
``descriptor address + rel``.

Mesh record ("CMeshData", 0x60 bytes, offsets from the record start S):

  +0x00..0x14  six string pointers: version, date, user, computer, max path, max file
  +0x18        -1
  +0x1C        pointer to the group array descriptor (groups are 0x38 bytes)
  +0x20        pointer to the bone-name array descriptor (skinned meshes) or -1
  +0x24        pointer to bounds data (not decoded)
  +0x28..0x4C  ten vertex-element slots, each a pointer to a cell holding a pointer to
               the format name (or -1): position, normal, tangent, colour, texcoord0-3,
               blend weights, blend indices.  Order and usages confirmed against the
               vertex declaration builder fn_88749920 (D3DDECLUSAGE 0, 3, 6, 10, 5x4, 1, 2)
  +0x50        pointer to the vertex array descriptor (count = vertices, raw bytes follow)
  +0x54        u32 tag (hash of the vertex layout)
  +0x58        pointer to the mesh name
  +0x5C        pointer (unused here)

Group (0x38 bytes): index array descriptor (u16 indices), -1/0, 0, 0, pointer to bounds,
1, pointer to group name, pointer to primitive type name ("TriStrip" or
"IndexedTriList"), 1, 0, primitive count, index count.

Vertex element formats (names from the string table at 0x880D3854..0x880D3908 in
Swing_DLL, sizes from the D3DDECLTYPE encodings in fn_88749920):
  C3DVector 12 (3 x f32)  C2DVector 8  C4DVector 16  Float16_2 4  Float16_4 8
  Dec3N 4 (2_10_10_10 signed normalised, x = bits 0-9)  D3DColor 4 (ARGB)
  UShort4N 8 (4 x u16 / 65535)  UByte4 4

Standard library only.
"""
import re
import struct
import zlib

NONE = 0xFFFFFFFF

SLOT_USAGES = ["position", "normal", "tangent", "color", "uv0", "uv1", "uv2", "uv3", "weights", "indices"]
FORMAT_SIZES = {
    "C3DVector": 12, "C2DVector": 8, "C4DVector": 16, "Float16_2": 4, "Float16_4": 8,
    "Dec3N": 4, "D3DColor": 4, "UShort4N": 8, "UByte4": 4,
}


def u32(d, o):
    return struct.unpack_from(">I", d, o)[0]


def cstr(d, o):
    return d[o:d.index(b"\0", o)].decode("latin-1")


def ptr(d, a):
    """Resolve the self-relative pointer word at address a (None for -1); relative values are signed."""
    r = u32(d, a)
    if r == NONE:
        return None
    return a + (r - (1 << 32) if r >= 1 << 31 else r)


def array(d, a):
    """Return (element_address, count) of the 12-byte array descriptor at a."""
    rel, count, _cap = struct.unpack_from(">iII", d, a)
    return a + rel, count


def half(h):
    s = -1.0 if h & 0x8000 else 1.0
    e = (h >> 10) & 31
    m = h & 1023
    if e == 0:
        return s * m * 2.0 ** -24
    if e == 31:
        return s * (float("inf") if m == 0 else float("nan"))
    return s * (1 + m / 1024.0) * 2.0 ** (e - 15)


def dec3n(v):
    """Xbox 360 DEC3N: three signed 10-bit normalised components, x in the low bits."""
    out = []
    for sh in (0, 10, 20):
        c = (v >> sh) & 0x3FF
        if c >= 512:
            c -= 1024
        out.append(max(-1.0, c / 511.0))
    return tuple(out)


def decode_attr(fmt, raw):
    if fmt == "C3DVector":
        return struct.unpack(">3f", raw)
    if fmt == "C2DVector":
        return struct.unpack(">2f", raw)
    if fmt == "C4DVector":
        return struct.unpack(">4f", raw)
    if fmt == "Float16_2":
        return tuple(half(h) for h in struct.unpack(">2H", raw))
    if fmt == "Float16_4":
        return tuple(half(h) for h in struct.unpack(">4H", raw))
    if fmt == "Dec3N":
        return dec3n(struct.unpack(">I", raw)[0])
    if fmt == "D3DColor":
        a, r, g, b = raw
        return (r / 255.0, g / 255.0, b / 255.0, a / 255.0)
    if fmt == "UShort4N":
        return tuple(x / 65535.0 for x in struct.unpack(">4H", raw))
    if fmt == "UByte4":
        return tuple(raw)
    raise ValueError(fmt)


class Group:
    def __init__(self, name, prim, indices):
        self.name = name
        self.prim = prim
        self.indices = indices

    def triangles(self):
        """Return a flat triangle list (degenerate and primitive-restart triangles removed)."""
        idx = self.indices
        tris = []
        if self.prim == "TriStrip":
            for i in range(len(idx) - 2):
                a, b, c = idx[i], idx[i + 1], idx[i + 2]
                if a == b or b == c or a == c or 0xFFFF in (a, b, c):
                    continue
                tris.append((a, b, c) if i % 2 == 0 else (a, c, b))
        else:
            for i in range(0, len(idx) - 2, 3):
                a, b, c = idx[i:i + 3]
                if a != b and b != c and a != c:
                    tris.append((a, b, c))
        return tris


class Mesh:
    """Decoded mesh record: attribute lists plus groups (submeshes)."""

    def __init__(self):
        self.name = ""
        self.header = []
        self.formats = {}
        self.stride = 0
        self.vertex_count = 0
        self.groups = []
        self.bones = []
        self.attrs = {}
        self.base_offset = 0

    def positions(self):
        return self.attrs["position"]


def parse_mesh(d, s):
    """Parse the mesh record at file offset s of an XBin image ``d``."""
    m = Mesh()
    m.base_offset = s
    m.header = [cstr(d, ptr(d, s + 4 * i)) for i in range(6)]
    # vertex element formats
    off = 0
    layout = []
    for i, usage in enumerate(SLOT_USAGES):
        p = ptr(d, s + 0x28 + 4 * i)
        if p is None:
            continue
        name = cstr(d, ptr(d, p))
        layout.append((usage, name, off))
        off += FORMAT_SIZES[name]
        m.formats[usage] = name
    m.stride = off
    vp = ptr(d, s + 0x50)
    vdata, vcount = array(d, vp)
    m.vertex_count = vcount
    raw = d[vdata:vdata + vcount * m.stride]
    for usage, name, o in layout:
        n = FORMAT_SIZES[name]
        m.attrs[usage] = [decode_attr(name, raw[i * m.stride + o:i * m.stride + o + n]) for i in range(vcount)]
    m.name = cstr(d, ptr(d, s + 0x58))
    gp = ptr(d, s + 0x1C)
    gdata, gcount = array(d, gp)
    for gi in range(gcount):
        g = gdata + 0x38 * gi
        idata, icount = array(d, g)
        indices = list(struct.unpack_from(">%dH" % icount, d, idata))
        m.groups.append(Group(cstr(d, ptr(d, g + 0x20)), cstr(d, ptr(d, g + 0x24)), indices))
    bp = ptr(d, s + 0x20)
    if bp is not None:
        bdata, bcount = array(d, bp)
        m.bones = [cstr(d, ptr(d, bdata + 4 * i)) for i in range(bcount)]
    return m


def mesh_records(d):
    """Yield the file offsets of all mesh records in a PackedMeshes / single mesh xbin."""
    sig_b = u32(d, 4)
    if sig_b == 0x3F65F116:      # PackedMeshes.xbin: root is an array of 0x60 byte records
        base, count = array(d, 0x14)
        return [base + 0x60 * i for i in range(count)]
    return [0x14]                # single mesh (player body parts)


# --- PAM-XDT (binary XML) -----------------------------------------------------------------------

XDT_ELEMENTS = [
    "Hierarchy", "Command", "Camera", "Child", "Light", "SRP", "WorldSRP", "Scale", "Rot", "Pos", "Anim",
    "BBox", "Min", "Max", "Center", "Group", "Geometry", "UserProperties", "ShaderLODList", "ShaderLOD",
    "Particle_View", "ExportHeader", "Lights",
]
XDT_ATTRS = [
    "Name", "Mesh", "Material", "X", "Y", "Z", "RestoreAtEnd", "LowPriority", "ScaleEnable", "RotEnable",
    "PosEnable", "LODLevel", "LODLevelCount", "Distance1", "Distance2", "Distance3", "Distance4", "Distance5",
    "Distance6", "Distance7", "FullLODs", "AlwaysVisible", "ShaderLOD", "MaterialDefault", "MaterialLow",
    "Version", "Date", "UserName", "ComputerName", "MaxFilePath", "MaxFileName",
]
XDT_NAMES = {zlib.crc32(n.encode()): n for n in XDT_ELEMENTS + XDT_ATTRS}
XDT_ELEMENT_HASHES = {zlib.crc32(n.encode()) for n in XDT_ELEMENTS}


class XdtNode:
    def __init__(self, name):
        self.name = name
        self.attrs = {}
        self.children = []

    def find(self, name):
        for c in self.children:
            if c.name == name:
                return c
        return None

    def walk(self):
        yield self
        for c in self.children:
            yield from c.walk()


def parse_xdt(d):
    """Parse a ``PAM-XDT`` binary XML file into a tree of :class:`XdtNode`.

    Layout (big endian): ``"PAM-XDT\\0"``, u32 version (1), u32 4, u32 data_size,
    u32 token_size, then the *data* section (attribute values in document order, each
    4-byte aligned: strings NUL terminated, f32, one-byte booleans) followed by the token
    section of 12-byte tokens.  An element token is ``{crc32(name), nattrs, nchildren}``
    and is immediately followed by ``nattrs`` attribute tokens ``{crc32(name), type, size}``
    (type 4 = string of ``size`` bytes, 3 = f32, 1 = byte) and then by its ``nchildren``
    child elements.  Names are CRC-32 hashes; unknown hashes print as ``0x...``.
    """
    if d[:8] != b"PAM-XDT\0":
        raise ValueError("not PAM-XDT")
    a, b = struct.unpack_from(">II", d, 0x10)
    tpos = 0x18 + a
    ntok = b // 12
    toks = [struct.unpack_from(">III", d, tpos + 12 * i) for i in range(ntok)]
    idx = [0]
    state = {"pos": 0x18}

    def attr_value(k, n):
        p = state["pos"]
        if k == 4:
            v = d[p:p + n].rstrip(b"\0").decode("latin-1")
        elif k == 3 and n == 4:
            v = struct.unpack_from(">f", d, p)[0]
        elif n == 1:
            v = d[p]
        else:
            v = d[p:p + n]
        state["pos"] = (p + n + 3) & ~3
        return v

    def element():
        h, na, nc = toks[idx[0]]
        idx[0] += 1
        node = XdtNode(XDT_NAMES.get(h, "0x%08x" % h))
        for _ in range(na):
            h2, k2, n2 = toks[idx[0]]
            idx[0] += 1
            node.attrs[XDT_NAMES.get(h2, "0x%08x" % h2)] = attr_value(k2, n2)
        for _ in range(nc):
            node.children.append(element())
        return node

    return element()


def srp_params(node):
    """(scale, euler rotation in radians (x, y, z), position) of a node's ``SRP`` child."""
    s = node.find("SRP")
    sc, ro, po = (1.0, 1.0, 1.0), (0.0, 0.0, 0.0), (0.0, 0.0, 0.0)
    if s is not None:
        def vec(n, dflt):
            c = s.find(n)
            return tuple(c.attrs.get(k, dflt[i]) for i, k in enumerate("XYZ")) if c is not None else dflt
        sc, ro, po = vec("Scale", sc), vec("Rot", ro), vec("Pos", po)
    return sc, ro, po


srp_matrix = srp_params  # backwards compatible name


def mat4_mul(a, b):
    """4x4 row-major matrix product (row-vector convention: v' = v * M)."""
    return [sum(a[4 * r + k] * b[4 * k + c] for k in range(4)) for r in range(4) for c in range(4)]


def srp_row_matrix(sc, ro, po):
    """Row-vector (Direct3D style) matrix S * R * T with R = Rz(roll) * Rx(pitch) * Ry(yaw).

    This is the D3DXMatrixRotationYawPitchRoll convention (rot.y = yaw, rot.x = pitch,
    rot.z = roll, radians).  The Y-only case (all that the venue files use for placed
    objects) is exact; mixed axes are unverified.
    """
    import math
    cx, sx = math.cos(ro[0]), math.sin(ro[0])
    cy, sy = math.cos(ro[1]), math.sin(ro[1])
    cz, sz = math.cos(ro[2]), math.sin(ro[2])
    rx = [1, 0, 0, 0, 0, cx, sx, 0, 0, -sx, cx, 0, 0, 0, 0, 1]
    ry = [cy, 0, -sy, 0, 0, 1, 0, 0, sy, 0, cy, 0, 0, 0, 0, 1]
    rz = [cz, sz, 0, 0, -sz, cz, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]
    r = mat4_mul(mat4_mul(rz, rx), ry)
    s = [sc[0], 0, 0, 0, 0, sc[1], 0, 0, 0, 0, sc[2], 0, 0, 0, 0, 1]
    t = [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, po[0], po[1], po[2], 1]
    return mat4_mul(mat4_mul(s, r), t)


def hierarchy_world_matrices(root):
    """Yield (node, world_row_matrix) for every Group/Geometry-like node with an SRP, composed down the tree."""
    out = []
    ident = [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]

    def rec(node, parent):
        w = parent
        if node.find("SRP") is not None:
            w = mat4_mul(srp_row_matrix(*srp_params(node)), parent)
        out.append((node, w))
        for c in node.children:
            rec(c, w)

    rec(root, ident)
    return out


# --- PackedMaterials.bin -----------------------------------------------------------------------

MATERIAL_SINGLE = 0x44F681FD      # one material (0x70 byte header)
MATERIAL_MULTI = 0x64621D6E       # multi-material: sub-material array + name

SAMPLER_NAMES = [
    "DiffuseMap", "BumpMap", "FilterReflectMap", "ProjectedEnvLightMap", "ReflectGradientMap", "ReflectCubeMap",
    "AmbientCubeMap", "OrenNayarMap", "BlinnMap", "Cloudmap1", "ProjectedShadowMap", "ShadowDepthMap",
    "ShadowDepthMapPlayer", "ShadowDepthMapEnvir", "FluidMap", "WrinkleMap", "WrinkleMaskMap", "DropMap",
    "SpecularMap", "LightMap", "AmbientMap", "ModMap", "ReflecMap", "FilterRelfectMap", "AlbedoMap",
    "DynLightmap", "StatLightmap", "AmbientBottomMap", "DisplaceMap", "SphericalEnvMap", "ShinynessMap",
    "ProjectedEnvLightMap2", "DiffuseMap2", "BumpMap2", "OpacityMap", "SpecMap",
]
SAMPLER_BY_HASH = {zlib.crc32(n.encode()): n for n in SAMPLER_NAMES}


class Material:
    """Material with its texture slots: ``textures`` is a list of (slot name or hash, texture name)."""

    def __init__(self, name):
        self.name = name
        self.textures = []
        self.subs = []          # sub-materials (multi-material container)

    def texture(self, slot):
        for s, t in self.textures:
            if s == slot:
                return t
        return None

    def for_group(self, index):
        if self.subs:
            return self.subs[index % len(self.subs)] if index >= 0 else self.subs[0]
        return self


def _parse_single_material(d, o):
    m = Material(cstr(d, ptr(d, o + 0x60)))
    elems, count = array(d, o + 0x48)
    for k in range(count):
        e = elems + 0x5C * k
        h = u32(d, e + 12)
        name = cstr(d, e + 16) if d[e + 16] else ""
        m.textures.append((SAMPLER_BY_HASH.get(h, "0x%08x" % h), name))
    return m


def parse_packed_materials(d):
    """Parse PackedMaterials.bin (XBin root type 0xECC4F93B) -> list of :class:`Material`.

    Root: array descriptor at 0x14 of ``{rel, type}`` 8-byte entries.  Type 0x44F681FD is a single
    material: 0x70 byte header whose +0x48 descriptor points at texture slots (0x5C bytes
    each: 12 bytes sampler-state descriptor, u32 crc32(sampler name), 76 byte NUL padded texture
    name) and whose +0x60 pointer names the material.  Type 0x64621D6E is a multi-material:
    ``{rel, count, cap}`` of single materials (stride 0x70) at +0x00 and the container name
    pointer at +0x0C.
    """
    base, count = array(d, 0x14)
    out = []
    for i in range(count):
        a = base + 8 * i
        obj = ptr(d, a)
        typ = u32(d, a + 4)
        if typ == MATERIAL_SINGLE:
            out.append(_parse_single_material(d, obj))
        elif typ == MATERIAL_MULTI:
            m = Material(cstr(d, ptr(d, obj + 0x0C)))
            elems, n = array(d, obj)
            m.subs = [_parse_single_material(d, elems + 0x70 * k) for k in range(n)]
            out.append(m)
    return out


def xdt_material(node):
    """Interpret a ``PAM-XDT`` Material tree (player parts): returns a multi-:class:`Material`.

    Root ``Material`` (attr Name) -> sub-materials (attr Name) -> shader node -> sampler nodes (attr
    Name = sampler name, descendant string attribute = texture name).
    """
    root = Material(node.attrs.get("Name", ""))
    for sub in node.children:
        sm = Material(sub.attrs.get("Name", ""))
        for n in sub.walk():
            if n is sub or "Name" not in n.attrs or not n.children:
                continue
            strs = [v for d_ in n.walk() if d_ is not n for v in d_.attrs.values() if isinstance(v, str)]
            if n.attrs["Name"].endswith(("Map", "Map1", "Map2", "MapPlayer", "MapEnvir")) and strs:
                sm.textures.append((n.attrs["Name"], strs[0]))
        root.subs.append(sm)
    if not root.subs:
        root.subs = [Material(root.name)]
    return root
