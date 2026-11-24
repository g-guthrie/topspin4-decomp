/* CW35 part l: LTCG route; the context stub makes the callee opaque but register-preserving for r4. */
typedef struct Out { int v[2]; } Out;
extern void ts4_call_seq_u32_off0_881B1A98(Out *out, void *self, int v);
extern int ts4_tbl_count_flag1_888657C8(void);

/* 0x887A7668: forward the flag-1 entry count (self stays in r4 across the argument-less callee) */
int ts4_script_count_flag1_887A7668(void *self)
{
    Out o;
    ts4_call_seq_u32_off0_881B1A98(&o, self, ts4_tbl_count_flag1_888657C8());
    return 1;
}
