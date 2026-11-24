/* Swing_DLL.xex 0x889A0740: when the state change count (+0x430) is non-zero: fetch the local 256-bit mask through context vtable slot 30, call 889A0698 when 88150940 reports it differs from the owner mask (+0x2c, returns 1), then combine the owner and local masks with 88150B70 and copy words 3-6 of the result to state+0x420.
 * /Oc. The change count is unsigned (cmplwi); the 32-byte locals are zeroed word by word. */
typedef struct Bits256 { unsigned int w[8]; } Bits256;
typedef struct SessionState { char pad[0x420]; unsigned int caps[4]; unsigned int changeCount; } SessionState;
typedef struct SessionContext SessionContext;
typedef struct SessionContextVtbl { void *slots[30]; void (*getLocalMask)(SessionContext *ctx, Bits256 *out); } SessionContextVtbl;
struct SessionContext { SessionContextVtbl *vtbl; char pad[0x3c - 0x4]; SessionState *state; };
typedef struct MaskOwner { char pad[0x2c]; Bits256 mask; } MaskOwner;
extern SessionContext *g_ts4_session_context;
unsigned char fn_88150940(const Bits256 *a, const Bits256 *b);
Bits256 *fn_88150B70(Bits256 *out, const Bits256 *a, const Bits256 *b);
void fn_889A0698(MaskOwner *o);

int fn_889A0740(MaskOwner *o)
{
    SessionContext *ctx = g_ts4_session_context;
    SessionState *st = ctx->state;
    int changed = 0;
    if (st->changeCount) {
        Bits256 local;
        Bits256 combined;
        local.w[0] = 0;
        local.w[1] = 0;
        local.w[2] = 0;
        local.w[3] = 0;
        local.w[4] = 0;
        local.w[5] = 0;
        local.w[6] = 0;
        local.w[7] = 0;
        ctx->vtbl->getLocalMask(ctx, &local);
        if (fn_88150940(&o->mask, &local)) {
            changed = 1;
            fn_889A0698(o);
        }
        fn_88150B70(&combined, &o->mask, &local);
        st->caps[0] = combined.w[3];
        st->caps[1] = combined.w[4];
        st->caps[2] = combined.w[5];
        st->caps[3] = combined.w[6];
    }
    return changed;
}
