/* NEAR MISS (agAD, b166): /O1, 36 off. Swing_DLL.xex 0x883FA998: reads a name (alloc line 0x5e), a mode word, then a byte-swapped
 * value (modes 0/1) or an allocated blob (mode 2, line 0x9d). The target keeps two copies of the swap whose OR order differs;
 * MSVC merges our two cases in every operand order (a union int view splits them but gives srawi). */
typedef struct Obj { char p0[0x14]; void *name; unsigned mode; unsigned value; } Obj;
extern const char lbl_8803A06C[];
int fn_883194F0(void *stream, void *dst, unsigned int size, unsigned int count, int a);
void *ts4_if_get_u32_lbl_88B3302C_883D05C8(void *heap, int flags, unsigned size, const char *file, int line);
#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) & 0xff00) << 8) | ((x) << 24))
int fn_883FA998(Obj *o, void *s, int unused, void *heap)
{
    unsigned n;
    unsigned w;
    int r;
    r = fn_883194F0(s, &n, 4, 1, 0);
    if (r) return r;
    o->name = ts4_if_get_u32_lbl_88B3302C_883D05C8(heap, 0, n, lbl_8803A06C, 0x5e);
    if (!o->name) return 0x2c;
    r = fn_883194F0(s, o->name, 1, n, 0);
    if (r) return r;
    r = fn_883194F0(s, &o->mode, 4, 1, 0);
    if (r) return r;
    switch (o->mode) {
    case 0:
        r = fn_883194F0(s, &w, 1, 4, 0);
        if (r) return r;
        o->value = w;
        o->value = SWAP32(o->value);
        break;
    case 1:
        r = fn_883194F0(s, &w, 1, 4, 0);
        if (r) return r;
        o->value = w;
        o->value = SWAP32(o->value);
        break;
    case 2:
        r = fn_883194F0(s, &n, 4, 1, 0);
        if (r) return r;
        o->value = (unsigned)ts4_if_get_u32_lbl_88B3302C_883D05C8(heap, 0, n, lbl_8803A06C, 0x9d);
        if (!o->value) return 0x2c;
        r = fn_883194F0(s, (void *)o->value, 1, n, 0);
        if (r) return r;
        break;
    }
    return 0;
}

