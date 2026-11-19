/* 0x884F7D18: calls the module export with ordinal 0x48C through a cached pointer (lbl_88D270B4), resolving it first with ts4_if_call_seq_u32_off0_884F4560; E_FAIL when it cannot be resolved. */
/* Matched on /O1 (agAF). Same source as 0x884F4630. */
typedef long (*Fn)(void *a, void *b);
extern Fn lbl_88D270B4;
extern int ts4_if_call_seq_u32_off0_884F4560(int ordinal, Fn *slot);
long fn_884F7D18(void *a, void *b)
{
    if (!lbl_88D270B4)
        ts4_if_call_seq_u32_off0_884F4560(0x48c, &lbl_88D270B4);
    if (lbl_88D270B4)
        return lbl_88D270B4(a, b);
    return 0x80004005;
}
