/* 0x8842CEF8: same as 8842CE08 with the id cached in lbl_88B3D1DC */
/* Matched on /O1 (agAH). /O1, 8842CE08 template. */
typedef struct Ref { void *a; void *b; } Ref;
extern const char lbl_88040B78[];
extern const char lbl_88040B80[];
extern unsigned short lbl_88B3D1DC;
extern Ref *ts4_if_call_seq_u32_off4_88428890(Ref *out, void *src, const char *name);
extern unsigned short ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480(Ref *r);
extern Ref *ts4_if_call_seq_u32_off4_88428AC8(Ref *out, Ref *r, const char *name);
extern void *ts4_call_seq_u32_off4_88428B48(Ref *out, Ref *r);
extern int fn_8842B568(void *node, void *obj, void *arg);
int fn_8842CEF8(void *self, void **src, void *arg)
{
    Ref r, r2, r3;
    ts4_if_call_seq_u32_off4_88428890(&r, src, lbl_88040B78);
    if (lbl_88B3D1DC == 0xFFFF)
        lbl_88B3D1DC = ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480(&r);
    return fn_8842B568(ts4_call_seq_u32_off4_88428B48(&r3, ts4_if_call_seq_u32_off4_88428AC8(&r2, &r, lbl_88040B80)), *src, arg);
}
