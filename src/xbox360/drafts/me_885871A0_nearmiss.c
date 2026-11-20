/* 0x885871A0: creates the record when fn_88584AE0 finds none and sets bit 0x40 of its byte 7 on success */
/* Near miss (agAH): /O1, 1 off at +0x30: the found branch targets the shared mr r3,r31 block in the target and the epilogue in ours. Early return, goto and inverted tests leave it. */
typedef struct Rec { char p[7]; unsigned char flags; } Rec;
typedef struct Ctx Ctx;
extern void *fn_88584AE0(Ctx *c, void *key, int z, void *b, Rec **out);
extern long fn_885869A8(Ctx *c, void *key, int z, void *a, void *b, Rec **rec);
long fn_885871A0(Ctx *c, void *key, void *a, void *b)
{
    Rec *rec;
    long hr = 0;
    if (!fn_88584AE0(c, key, 0, b, &rec)) {
        hr = fn_885869A8(c, key, 0, a, b, &rec);
        if (hr >= 0)
            rec->flags |= 0x40;
    }
    return hr;
}
