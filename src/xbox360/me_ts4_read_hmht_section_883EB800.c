/* Swing_DLL.xex 0x883EB800: reads an 'hmht' section: a u16 count, a 0x18-byte lookup object (vtable lbl_880391A0) set up by
 * fn_883E4DC0, then count 0x38-byte entries (vtable lbl_880398D4), each preceded by an ' mht' header and read by fn_883E9328. agAD: /O1. */
typedef struct Hdr { unsigned int magic; unsigned int tag; } Hdr;
typedef struct Ctx { int pad; void *heap; } Ctx;
typedef struct Lookup { const void *vt; int pad4; int a, b, c, d; } Lookup;
typedef struct Entry { const void *vt; int pad4; int f8; char pad[0x38 - 0xc]; } Entry;
typedef struct Sect { int hdr[2]; Entry *entries; unsigned int count; Lookup *lookup; } Sect;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039A20[];
extern const void *lbl_880391A0[];
extern const void *lbl_880398D4[];
int fn_883E7828(Hdr *h, void *stream, unsigned int version);
int fn_883194F0(void *stream, void *dst, unsigned int size, unsigned int count, int a);
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
void *ts4_tailcall_fn_88315C60_88316068(void *heap, unsigned int size, const char *file, int line, int flags);
int fn_883E4DC0(Lookup *l, unsigned int count, void *f1, void *f2);
int fn_883E9328(void *owner, Entry *e, Hdr *h, void *stream, unsigned int version);
unsigned int ts4_get_u32_off0_883E9070(void *p);
unsigned int ts4_get_u32_off0_883E5008(void *p);

int fn_883EB800(Sect *s, int unused, void *stream, unsigned int version)
{
    Hdr h;
    unsigned short n;
    unsigned int i;
    int r;
    Lookup *l;
    r = fn_883E7828(&h, stream, version);
    if (r)
        return r;
    if (h.tag != 0x686d6874)
        return 0x21;
    n = 0;
    r = fn_883194F0(stream, &n, 2, 1, 0);
    if (r)
        return r;
    s->count = n;
    l = (Lookup *)fn_88315C60(lbl_88B3302C->heap, 0x18, lbl_88039A20, 0x5a7, 0, 0);
    if (l) {
        l->a = 0;
        l->b = 0;
        l->c = 0;
        l->d = 0;
        l->vt = lbl_880391A0;
    } else
        l = 0;
    s->lookup = l;
    if (!l)
        return 0x2c;
    r = fn_883E4DC0(l, s->count, (void *)ts4_get_u32_off0_883E9070, (void *)ts4_get_u32_off0_883E5008);
    if (r)
        return r;
    s->entries = (Entry *)ts4_tailcall_fn_88315C60_88316068(lbl_88B3302C->heap, s->count * 0x38, lbl_88039A20, 0x5ae, 0);
    if (!s->entries)
        return 0x2c;
    for (i = 0; i < s->count; i++) {
        Entry *e = &s->entries[i];
        if (e) {
            e->vt = lbl_880398D4;
            e->f8 = 0;
        }
    }
    for (i = 0; i < s->count; i++) {
        r = fn_883E7828(&h, stream, version);
        if (r)
            return r;
        if (h.tag != 0x206d6874)
            return 0x21;
        r = fn_883E9328((char *)s - 8, &s->entries[i], &h, stream, version);
        if (r)
            return r;
    }
    return 0;
}
