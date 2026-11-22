/* Q5h4 equivalent tier: script variable "max" node, sister of 0x887F8920 (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * Clone of eq_q5_gameplay_var_min.cpp for the sister 0x887F8A50. Passes tools/fn_equiv.py; it is NOT a byte match
 * (the template is LTCG code, 14 off under fn_check_ltcg).
 *
 * Behaviour: the node record (self->desc) holds a relative-offset list of input slots and an output slot whose
 * byte 1 selects a mode through the hash selector. Mode 0x95B29297: take the MAXIMUM of the input variables
 * (relative-offset int table in the context's variable block), store it in the output variable and notify the sink
 * (virtual slot +0x34). Mode 0xCD0B222F: hand off to fn_881B5150. Always returns 1.
 * The only difference from the minimum is the comparison: `if (m < v) m = v` instead of `if (m >= v) m = v`. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Q5h4Rel { int off; } Q5h4Rel;
typedef struct Q5h4Node { u8 b0; u8 kind; u16 index; } Q5h4Node;
typedef struct Q5h4Desc { Q5h4Rel items; int count; int pad8; Q5h4Rel node; } Q5h4Desc;
typedef struct Q5h4Blk { char p0[0x24]; Q5h4Rel vars; } Q5h4Blk;
typedef struct Q5h4Ctx { char p0[0x1c]; struct { char p0[0x20]; Q5h4Blk *blk; } *db; } Q5h4Ctx;
class Q5h4Sink {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30();
    virtual void notify(u32 a, u32 b); /* +0x34 */
};
typedef struct Q5h4Op { char p0[8]; u32 w8; char pc[0x14]; Q5h4Ctx *ctx; Q5h4Sink *sink; Q5h4Desc *desc; u32 w2c; } Q5h4Op;
extern "C" u32 *ts4_set_u32_off0_887F7B18(u32 *, u8);
extern "C" void fn_881B5150(Q5h4Op *);
static void *q5h4_rel(Q5h4Rel *r) { return (char *)r + r->off; }
/* byte-gap: 75 off; LTCG template; 14 off under fn_check_ltcg (sister of 0x887F8920) */
extern "C" u32 ts4_var_max_node_887F8A50(Q5h4Op *self)
{
    Q5h4Desc *d = self->desc;
    u32 tmp;
    switch (*ts4_set_u32_off0_887F7B18(&tmp, ((Q5h4Node *)q5h4_rel(&d->node))->kind)) {
    case 0x95B29297u: {
        int m = 0, i;
        for (i = 0; i < d->count; i++) {
            int *p = &((int *)q5h4_rel(&self->ctx->db->blk->vars))[((Q5h4Node *)q5h4_rel(&d->items))[i].index];
            if (i == 0) m = *p;
            else { int v = *p; if (m < v) m = v; }
        }
        { Q5h4Node *n = (Q5h4Node *)q5h4_rel(&d->node); ((int *)q5h4_rel(&self->ctx->db->blk->vars))[n->index] = m; }
        { Q5h4Sink *k = self->sink; k->notify(self->w8, self->w2c); }
        break; }
    case 0xCD0B222Fu:
        fn_881B5150(self);
        break;
    }
    return 1;
}
