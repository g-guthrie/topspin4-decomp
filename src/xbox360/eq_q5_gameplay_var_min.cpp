/* Q5 equivalent tier: script variable "min" node, 0x887F8920 (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * Passes tools/fn_equiv.py; it is NOT a byte match. The original is LTCG code: with
 * `tools/fn_check_ltcg.py --context src/xbox360/cx40_ctx_c.c` this source is 14 off, all one register
 * swap (self and the running minimum trade r7/r8; ts4_set_u32_off0_887F7B18 only clobbers r10/r11, so both live in
 * volatile registers across the call). Two perm_auto --ltcg runs (1339 and 1126 candidates) stopped
 * at 3 off, and only with dead self aliases.
 * fn_equiv: seed 1, 3000 trials (the mode byte is random, so few trials reach the two modes).
 *
 * Behaviour: the node record (self->desc) holds a relative-offset list of input slots and an
 * output slot whose byte 1 selects a mode through the hash selector. Mode 0x95B29297: take the
 * minimum of the input variables (relative-offset int table in the context's variable block),
 * store it in the output variable and notify the sink (virtual slot +0x34). Mode 0xCD0B222F:
 * hand off to fn_881B53A0. Always returns 1.
 * Sister 0x887F8A50 is the same with the comparison reversed (maximum: `if (m < v) m = v`). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Q5Rel { int off; } Q5Rel;
typedef struct Q5Node { u8 b0; u8 kind; u16 index; } Q5Node;
typedef struct Q5Desc { Q5Rel items; int count; int pad8; Q5Rel node; } Q5Desc;
typedef struct Q5Blk { char p0[0x24]; Q5Rel vars; } Q5Blk;
typedef struct Q5Ctx { char p0[0x1c]; struct { char p0[0x20]; Q5Blk *blk; } *db; } Q5Ctx;
class Q5Sink {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30();
    virtual void notify(u32 a, u32 b); /* +0x34 */
};
typedef struct Q5Op { char p0[8]; u32 w8; char pc[0x14]; Q5Ctx *ctx; Q5Sink *sink; Q5Desc *desc; u32 w2c; } Q5Op;
extern "C" u32 *ts4_set_u32_off0_887F7B18(u32 *, u8);
extern "C" void fn_881B53A0(Q5Op *);
static void *q5_rel(Q5Rel *r) { return (char *)r + r->off; }
/* byte-gap: 75 off; LTCG register swap of self and the running minimum (r7/r8); 14 off under fn_check_ltcg */
extern "C" u32 ts4_var_min_node_887F8920(Q5Op *self)
{
    Q5Desc *d = self->desc;
    u32 tmp;
    switch (*ts4_set_u32_off0_887F7B18(&tmp, ((Q5Node *)q5_rel(&d->node))->kind)) {
    case 0x95B29297u: {
        int m = 0, i;
        for (i = 0; i < d->count; i++) {
            int *p = &((int *)q5_rel(&self->ctx->db->blk->vars))[((Q5Node *)q5_rel(&d->items))[i].index];
            if (i == 0) m = *p;
            else { int v = *p; if (m >= v) m = v; }
        }
        { Q5Node *n = (Q5Node *)q5_rel(&d->node); ((int *)q5_rel(&self->ctx->db->blk->vars))[n->index] = m; }
        { Q5Sink *k = self->sink; k->notify(self->w8, self->w2c); }
        break; }
    case 0xCD0B222Fu:
        fn_881B53A0(self);
        break;
    }
    return 1;
}
