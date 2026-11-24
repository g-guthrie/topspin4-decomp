/* 0x888CB4D0: copy a record inside a self-relative block and tag it with a mode hash (agAV).
 * The block at self->blk starts with a self-relative offset; the record at +0x190 is filled from the one at
 * +0x1f4 (ts4_rec_copy_88187900), then its id word is set to one of two name hashes picked by the global
 * flag lbl_88D45A60->flag (+0x1e), and the block's +0xc word is reset to -1.
 * The hash goes through a by-value Hash temporary: that gives the target's stack round trip
 * (addi r11,r1,0x50; stw; lwz 0(r11)). The first base use goes through an inline accessor so the second
 * rel load becomes a register copy (mr r9,r10). */
extern "C" void ts4_rec_copy_88187900(void *dst, void *src);
struct TS4ModeGlobals888CB4D0 { char p[0x1e]; unsigned char flag; };
extern "C" TS4ModeGlobals888CB4D0 *lbl_88D45A60;
struct TS4Hash888CB4D0 { unsigned int v; TS4Hash888CB4D0(unsigned int x) : v(x) {} };
struct TS4Rec888CB4D0 { int pad; unsigned int id; };
struct TS4Blk888CB4D0 { int rel; char p4[8]; int fc; char *base() { return (char *)this + rel; } };
struct TS4Owner888CB4D0 { char p[0x28]; TS4Blk888CB4D0 *blk; };
extern "C" void fn_888CB4D0(TS4Owner888CB4D0 *s) {
    TS4Rec888CB4D0 *e = (TS4Rec888CB4D0 *)(s->blk->base() + 0x190);
    ts4_rec_copy_88187900(e, (char *)s->blk + s->blk->rel + 0x1f4);
    TS4Hash888CB4D0 h = lbl_88D45A60->flag ? TS4Hash888CB4D0(0x45bf5377) : TS4Hash888CB4D0(0xbe5e43d9);
    e->id = h.v;
    s->blk->fc = -1;
}
