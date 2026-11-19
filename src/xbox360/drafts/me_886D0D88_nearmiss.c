/* NEAR MISS fn_886D0D88: 33 off (0x70 vs 0x94): the target materialises both handle-valid bools ((id + 1) != 0 via subic/subfe) before branching; every C/C++ form here folds them into compares. LTCG + primer, /Oc. */
/* Swing_DLL.xex 0x886D0D88: compare against a key: when both handles are valid, ask the comparer;
   otherwise test the time against this entry's limit. */
typedef unsigned char ts4_u8;
struct Ts4KeyA { int id; ts4_u8 pad_04[0x18]; float limit; };
struct Ts4KeyB { int id; };
ts4_u8 fn_886CB778(struct Ts4KeyA *a, struct Ts4KeyB *b);

ts4_u8 ts4_key_before_886D0D88(struct Ts4KeyA *a, float t, struct Ts4KeyB *b)
{
    ts4_u8 va = a->id != -1;
    ts4_u8 vb = b->id != -1;
    if (va && vb)
        return fn_886CB778(a, b) != 0;
    return t < a->limit;
}
