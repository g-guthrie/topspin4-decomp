/* Residue pass (tools/ltcg_ctx_find.py): the original keeps r4, r9 and r10 across
 * ts4_state_flag_8865DA28, which only the LTCG link (callee body visible) can do.
 * Check: python3 tools/fn_check_ltcg.py src/xbox360/q5s_res_stroke_query.c \
 *        ts4_stroke_query_886A80F0=0x886A80F0 --flags /Oc --include ts4_state_flag_8865DA28 \
 *        --context src/xbox360/jt_switch_flags.c --context src/xbox360/pp1_pool_primer.c */
typedef unsigned char u8;
typedef struct Q5ResStroke { char pad[0x1c]; void *query; char pad20[4]; void *state; char pad28[0x18];
    int count; } Q5ResStroke;
extern int ts4_state_flag_8865DA28(const char *object);
extern int fn_886A58F0(void *query);

/* Swing_DLL.xex 0x886A80F0: run the stroke query (0x886A58F0 on +0x1c) when the state flag of +0x24 is
 * clear and either `force` is set or the counter at +0x40 exceeds 5; else 0. The result variable is set
 * to 0 before the first call (li r9 kept across it) and the flag is narrowed to a byte only where it is
 * tested, after `go` is computed. */
int ts4_stroke_query_886A80F0(Q5ResStroke *self, u8 force)
{
    int result = 0;
    int busy = ts4_state_flag_8865DA28((const char *)self->state);
    u8 go = (force != 0 || self->count > 5) ? 1 : 0;
    if (!(u8)busy && go)
        result = fn_886A58F0(self->query);
    return result;
}
