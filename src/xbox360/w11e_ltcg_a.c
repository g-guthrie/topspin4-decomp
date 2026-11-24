/*
 * W11E (LTCG route): 0x886E39A8. Check with
 *   tools/fn_check_ltcg.py src/xbox360/w11e_ltcg_a.c ts4_run_scoped_worker_886E39A8=0x886E39A8
 *     --context flags(/Ob1):src/xbox360/sc1_ltcg_a.c --include ts4_init_state_8864A920
 *     --context src/xbox360/pp1_pool_primer.c --flags /Oc
 * The real init callee (sc1_ltcg_a.c) keeps r4/r6 alive, so ctx and self are not saved.
 */
struct W11eCtx { char pad[0x148]; unsigned w148; };
struct W11eOwn { char pad[0x14]; unsigned w14; };
extern void ts4_init_state_8864A920(void *s);
extern void fn_8864A770(void *w, unsigned a, unsigned *req, unsigned b);
extern void fn_8864A5E8(void *w);
extern void ts4_if_call_seq_u32_off40_8864A8A8(void *w);

/* Swing_DLL.xex 0x886E39A8: build a worker state, run it with ctx->w148 and a 0x20 request, finish and tear down */
void ts4_run_scoped_worker_886E39A8(struct W11eOwn *self, struct W11eCtx *ctx)
{
    unsigned char worker[0xc0];
    unsigned request;
    ts4_init_state_8864A920(worker);
    request = 0x20;
    fn_8864A770(worker, ctx->w148, &request, self->w14);
    fn_8864A5E8(worker);
    ts4_if_call_seq_u32_off40_8864A8A8(worker);
}
