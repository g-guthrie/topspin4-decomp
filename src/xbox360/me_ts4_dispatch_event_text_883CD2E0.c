/* 0x883CD2E0: resolves the context of a (88309A30, fn_883CB130); kind 2 formats x into a 256-byte buffer (88309A18/883099E8/88309A00) and reports it through ts4_call_cb_883C7220(ctx, 0, buf, len); kind 3 reports (0xB, x, y); always returns 0 */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
#ifdef _MSC_VER
#define PTR_INT(p) ((int)(p))
#else
#define PTR_INT(p) ((int)(long)(p))
#endif
typedef struct Ctx { char pad[0x74]; void *cb; } Ctx;
void ts4_if_tailcall_fn_883179C0_88309A30(void *a, void **obj);
int fn_883CB130(void *obj, Ctx **ctx);
void ts4_if_tailcall_fn_88317860_88309A18(void *a, void **h);
void ts4_if_tailcall_fn_88316C80_883099E8(void *h, int x, void **v);
void ts4_if_tailcall_fn_88316D00_88309A00(void *h, void *v, char *buf, int size, int *len, int mode);
void ts4_call_cb_883C7220(Ctx *ctx, int code, int a, int b);
int ts4_dispatch_event_text_883CD2E0(void *a, int kind, int x, int y)
{
    void *obj;
    Ctx *ctx;
    void *h;
    int len;
    void *v;
    char buf[0x100];
    ts4_if_tailcall_fn_883179C0_88309A30(a, &obj);
    if (fn_883CB130(obj, &ctx) == 0) {
        if (kind == 2) {
            ts4_if_tailcall_fn_88317860_88309A18(a, &h);
            ts4_if_tailcall_fn_88316C80_883099E8(h, x, &v);
            ts4_if_tailcall_fn_88316D00_88309A00(h, v, buf, 0x100, &len, 2);
            if (ctx->cb)
                ts4_call_cb_883C7220(ctx, 0, PTR_INT(buf), len);
        } else if (kind == 3) {
            if (ctx->cb)
                ts4_call_cb_883C7220(ctx, 0xb, x, y);
        }
    }
    return 0;
}
