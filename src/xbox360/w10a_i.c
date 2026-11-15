/* W10A: clears the entry whose key matches and notifies (Swing_DLL.xex 0x88656468). LTCG route. */
struct A14Sub;
typedef struct A14Vt { void *pad0[12]; unsigned char (*slot12)(struct A14Sub *); void *pad1[6]; void *(*slot19)(struct A14Sub *, int); } A14Vt;
typedef struct A14Sub { A14Vt *vt; } A14Sub;
typedef struct A14E { unsigned char pad[0x18]; unsigned w18; } A14E;
typedef struct A14Hdr { int rel; unsigned count; } A14Hdr;
typedef struct A14R { unsigned char pad[0x48]; A14Hdr h; } A14R;
typedef struct A14O { unsigned char pad[0x1c]; A14Sub sub; } A14O;
extern void ts4_zero_record_886562A0(A14O *s, int i);
void ts4_clear_entry_by_key_88656468(A14O *s, unsigned key)
{
    A14Sub *sub = &s->sub;
    if (sub->vt->slot12(sub)) {
        A14R *r = (A14R *)sub->vt->slot19(sub, 0);
        A14Hdr *h = &r->h;
        A14E *end, *begin;
        int i = 0;
        end = 0;
        if (h->rel != -1) end = (A14E *)((char *)h + (h->count * 0x1c + h->rel));
        begin = 0;
        if (h->rel != -1) begin = (A14E *)((char *)h + h->rel);
        for (; end != begin; begin++, i++) {
            if (key == begin->w18) {
                begin->w18 = 0;
                ts4_zero_record_886562A0(s, i);
                return;
            }
        }
    }
}
