/* OP1: clear the 0x40-byte records of a self-relative array, then the word at hdr+0xc.
 *
 * PADDING FORM. The seven dead locals in OP1_SYMBOL_PAD do not generate code.
 * They only advance the function-local symbol numbering so that `hdr` is
 * numbered like in the original, which gives the target's
 * `add r11, r9, r11` (i*0x40, hdr->rel) instead of (hdr->rel, i*0x40)
 * (see docs/agents/near-misses/OP1.md). Assignment order, not declaration
 * order, sets the numbering; locals of inlined helpers do not count. */
struct Op1Rec40 { int w[16]; };
struct Op1RelHdr40 { int rel; unsigned count; };
struct Op1Holder { char pad[0x4c]; struct Op1RelHdr40 hdr; };
struct Op1Own { char pad[0x28]; struct Op1Holder *h; };

#define OP1_SYMBOL_PAD int op1_p0 = 0, op1_p1 = 0, op1_p2 = 0, op1_p3 = 0, op1_p4 = 0, op1_p5 = 0, op1_p6 = 0
#define OP1_SYMBOL_PAD_USE (void)op1_p0; (void)op1_p1; (void)op1_p2; (void)op1_p3; (void)op1_p4; (void)op1_p5; (void)op1_p6

/* Swing_DLL.xex 0x88668D70 */
void ts4_clear_records_88668D70(struct Op1Own *s)
{
    OP1_SYMBOL_PAD;
    struct Op1RelHdr40 *hdr = &s->h->hdr;
    unsigned n = hdr->count;
    unsigned i;
    int *tail = (int *)((char *)hdr + 0xc);
    for (i = 0; i != n; i++) {
        struct Op1Rec40 *r = (struct Op1Rec40 *)((char *)hdr + (i * 0x40 + (unsigned)hdr->rel));
        r->w[0] = 0; r->w[1] = 0; r->w[2] = 0; r->w[3] = 0;
        r->w[4] = 0; r->w[5] = 0; r->w[6] = 0; r->w[7] = 0;
        r->w[8] = 0; r->w[9] = 0; r->w[10] = 0; r->w[11] = 0;
        r->w[13] = 0; r->w[14] = 0; r->w[12] = 0; r->w[15] = 0;
    }
    *tail = 0;
    OP1_SYMBOL_PAD_USE;
}
