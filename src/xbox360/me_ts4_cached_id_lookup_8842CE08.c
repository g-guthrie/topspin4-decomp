/* 0x8842CE08: resolves the name lbl_88040B78 under src, caches its id in lbl_88B3D1D4 once, then looks up lbl_88040B80 below it and passes the node, *src and arg to fn_8842B568 */
/* Matched on /O1 (agAH). /O1; siblings 8842CE80 and 8842CEF8 differ only in the cache label. */
typedef struct Ref { void *a; void *b; } Ref;
extern const char lbl_88040B78[];
extern const char lbl_88040B80[];
extern unsigned short lbl_88B3D1D4;
extern Ref *ts4_if_call_seq_u32_off4_88428890(Ref *out, void *src, const char *name);
extern unsigned short ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480(Ref *r);
extern Ref *ts4_if_call_seq_u32_off4_88428AC8(Ref *out, Ref *r, const char *name);
extern void *ts4_call_seq_u32_off4_88428B48(Ref *out, Ref *r);
extern int fn_8842B568(void *node, void *obj, void *arg);
int fn_8842CE08(void *self, void **src, void *arg)
{
    Ref r, r2, r3;
    ts4_if_call_seq_u32_off4_88428890(&r, src, lbl_88040B78);
    if (lbl_88B3D1D4 == 0xFFFF)
        lbl_88B3D1D4 = ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480(&r);
    return fn_8842B568(ts4_call_seq_u32_off4_88428B48(&r3, ts4_if_call_seq_u32_off4_88428AC8(&r2, &r, lbl_88040B80)), *src, arg);
}
