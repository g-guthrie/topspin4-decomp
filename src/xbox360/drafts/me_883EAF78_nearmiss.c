/* NEAR MISS (agAD, b167): /O1, 92 off but only stack slots differ: the target places n/items (0x58/0x5c) below the header (0x60), and the table copy at 0x68.
 * With scalar n/items locals the frame shrinks to 0xd0 (target 0xe0). */
/* Swing_DLL.xex 0x883EAF78: walks the sub-chunks of a section until the stream reaches its end: an 'ltne' chunk reads a
 * (count, items) name table (fn_883E7C98), builds a 0x18-byte lookup over it (vtable lbl_880391A0) and registers every item;
 * when lbl_88CAC988 flag 0x80AC bit 2 is set it also calls ts4_if_call_seq_u32_off4_883E6250. Other chunks are skipped. agAD: /O1. */
typedef struct Hdr { unsigned int size; unsigned int tag; } Hdr;
typedef struct Ctx { int pad; void *heap; } Ctx;
typedef struct Lookup { const void *vt; int pad4; int a, b, c, d; } Lookup;
typedef struct Item { unsigned int id; unsigned int key; } Item;
typedef struct Table { unsigned int count; Item *items; } Table;
typedef struct Sect { int hdr[2]; Lookup *lookup; Table table; } Sect;
extern Ctx *lbl_88B3302C;
extern char *lbl_88CAC988;
extern const char lbl_8803A020[];
extern const void *lbl_880391A0[];
int ts4_if_get_u32_off188_88319E00(void *stream, unsigned int *pos);
int fn_883E7828(Hdr *h, void *stream, unsigned int version);
int fn_883E7C98(Item **items, unsigned int *count, Hdr *h, void *stream, unsigned int version);
int fn_88319C40(void *stream, unsigned int size, unsigned int count);
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
int fn_883E4DC0(Lookup *l, unsigned int count, void *f1, void *f2);
int fn_883E4EC8(Lookup *l, unsigned int *key, unsigned int value);
void ts4_if_call_seq_u32_off4_883E6250(Table *t);
unsigned int ts4_get_u32_off0_883E8B80(void *p);
unsigned int ts4_get_u32_off0_883E5008(void *p);

int fn_883EAF78(Sect *s, const Hdr *sect, void *stream, unsigned int version)
{
    unsigned int end, pos;
    Table nt;
    Hdr h;
    Table t;
    Table *tp;
    unsigned int i;
    Lookup *l;
    int r;
    r = ts4_if_get_u32_off188_88319E00(stream, &end);
    if (r)
        return r;
    end = end + sect->size - 8;
    r = ts4_if_get_u32_off188_88319E00(stream, &pos);
    if (r)
        return r;
    while (pos < end) {
        r = fn_883E7828(&h, stream, version);
        if (r)
            return r;
        if (h.tag == 0x6c746e65) {
            fn_883E7C98(&nt.items, &nt.count, &h, stream, version);
            t = nt;
            tp = &s->table;
            *tp = t;
            l = (Lookup *)fn_88315C60(lbl_88B3302C->heap, 0x18, lbl_8803A020, 0x3fd, 0, 0);
            if (l) {
                l->vt = lbl_880391A0;
                l->a = 0;
                l->b = 0;
                l->c = 0;
                l->d = 0;
            } else
                l = 0;
            s->lookup = l;
            if (!l)
                return 0x2c;
            r = fn_883E4DC0(l, t.count, (void *)ts4_get_u32_off0_883E8B80, (void *)ts4_get_u32_off0_883E5008);
            if (r)
                return r;
            for (i = 0; i < t.count; i++) {
                r = fn_883E4EC8(s->lookup, &t.items[i].key, t.items[i].key);
                if (r)
                    return r;
            }
            if (*(unsigned int *)(lbl_88CAC988 + 0x80ac) & 4)
                ts4_if_call_seq_u32_off4_883E6250(tp);
        } else {
            r = fn_88319C40(stream, h.size - 8, 1);
            if (r)
                return r;
        }
        r = ts4_if_get_u32_off188_88319E00(stream, &pos);
        if (r)
            return r;
    }
    return 0;
}
