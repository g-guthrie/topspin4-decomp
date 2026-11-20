/* OP1: stats-row value >= tuning limit.
 *
 * The number of locals declared before `e` is load-bearing: with `tab` and `l`
 * split out (e is the 8th symbol, counting the parameter) the final load is
 * `lfsx f13, e, off` as in the target; with fewer locals it becomes
 * `lfsx f13, off, e` (see docs/agents/near-misses/OP1.md). */
struct Op1Lim { char pad[0x14]; float limit; };
struct Op1Idx { char pad[0x28]; int idx; };
struct Op1IdxOwn { char pad[0x4c]; struct Op1Idx *p4c; };
struct Op1RelH { int rel; };
struct Op1Tab { char pad[0x5c]; struct Op1RelH hdr; };
struct Op1Chk { char pad[0xc]; struct Op1Lim *lim; struct Op1Tab *tab; char pad2[0xc]; struct Op1IdxOwn *own; };

/* Swing_DLL.xex 0x8865B658 */
int ts4_value_at_least_8865B658(struct Op1Chk *s)
{
    struct Op1IdxOwn *own = s->own;
    struct Op1Tab *tab = s->tab;
    struct Op1Lim *l = s->lim;
    struct Op1RelH *h = &tab->hdr;
    float lim = l->limit;
    int idx = own->p4c->idx;
    char *e = (char *)h + (idx * 0x134 + h->rel);   /* 0x134-byte row */
    int off = *(int *)e;                            /* self-relative value offset */
    float *pv = (float *)(e + off);
    float v = *pv;
    if (v >= lim) return 1;
    return 0;
}
