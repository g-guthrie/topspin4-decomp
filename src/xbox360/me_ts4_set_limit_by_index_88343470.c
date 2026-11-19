/* 0x88343470: Stores value into one of three float limits chosen by index; limit 0 is first clamped to count*K1 - K2 where count comes from the context at +0x4a4. Out-of-range index is ignored; always returns 0. */
/* Matched on /Oc (agAH). switch with cases 0/1/2 and no default. Writing the clamp bound with explicit parentheses around the product, repeated in the test and the assignment, keeps fmuls+fsubs twice instead of a fused fmsubs and a CSE. */
extern const float lbl_88001978;
extern const float lbl_88028DFC;
typedef struct Ctx { char pad[0x4a4]; int count; } Ctx;
typedef struct Obj { char pad0[0x14]; Ctx *ctx; char pad1[0x144 - 0x18]; float limits[3]; } Obj;

int fn_88343470(Obj *o, unsigned int which, float value)
{
    int count = o->ctx->count;
    switch (which) {
    case 0:
        if (value >= ((float)count * lbl_88001978) - lbl_88028DFC)
            value = ((float)count * lbl_88001978) - lbl_88028DFC;
        o->limits[0] = value;
        break;
    case 1:
        o->limits[1] = value;
        break;
    case 2:
        o->limits[2] = value;
        break;
    }
    return 0;
}
