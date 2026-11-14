/* SM1 (/O1): call a vtable slot of the object at ctx->+0xb0; success (zero) when it is absent. */
typedef struct Ts4VObj3 { int (**vt)(); } Ts4VObj3;
typedef struct Ts4Ctx3 { int pad; struct { char pad[0xb0]; Ts4VObj3 *obj; } *ctx; } Ts4Ctx3;
#define CALL_CTX_OBJ_SLOT(NAME, SLOT) \
    int NAME(Ts4Ctx3 *t) { \
        int r; \
        if (t->ctx->obj != 0) { \
            r = ((int (*)(Ts4VObj3 *))t->ctx->obj->vt[SLOT / 4])(t->ctx->obj); \
            if (r != 0) return r; \
        } \
        return 0; \
    }

/* Swing_DLL.xex 0x883FF290 */
CALL_CTX_OBJ_SLOT(ts4_call_ctx_obj_slot_checked_883FF290, 0x4)
/* Swing_DLL.xex 0x883FF2E0 */
CALL_CTX_OBJ_SLOT(ts4_call_ctx_obj_slot_checked_883FF2E0, 0x8)
/* Swing_DLL.xex 0x883FF390 */
CALL_CTX_OBJ_SLOT(ts4_call_ctx_obj_slot_checked_883FF390, 0x0)
