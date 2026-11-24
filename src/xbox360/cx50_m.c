/* CX50: entry removal, Swing_DLL.xex 0x889C72B8. */
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"
#pragma clang diagnostic ignored "-Wpointer-to-int-cast"
#endif
typedef unsigned char u8; typedef unsigned int u32;
#define W(o, off) (*(u32 *)((u8 *)(o) + (off)))
extern void ts4_registry_dispatch_888860A0(void *p);
extern void ts4_tsu_cleanup_end(void *p);
extern void fn_88562DC0(void *d, void *s, u32 n);
extern u8 *g_ts4_session_context;
/* 0x889C72B8: remove the entry matching the key from the vector at +0x30 */
u32 *ts4_cx50_remove_entry_889C72B8(u8 *self, u8 **key)
{
    u32 *vec = (u32 *)(self + 0x30);
    u32 *end = (u32 *)W(self, 0x34);
    u32 *p = (u32 *)W(self, 0x30);
    u8 *obj;
    u8 *a;
    u8 found;
    u32 *next;
    for (; p != end; p++) {
        obj = (u8 *)*p;
        a = (u8 *)W(obj, 0);
        if (a != 0) found = (W(a, 4) == W(*key, 4)); else found = 0;
        if (found) goto hit;
    }
    return 0;
hit:
    if (a != 0) {
        ((void (*)(void *))((u32 *)W(a, 0))[2])(a);
        ((void (*)(void *, void *))((u32 *)W(g_ts4_session_context, 0))[0x48 / 4])(g_ts4_session_context, (void *)W(obj, 0));
    }
    if (W(obj, 4) != 0) { ts4_registry_dispatch_888860A0((void *)W(obj, 4)); W(obj, 4) = 0; }
    ts4_tsu_cleanup_end(obj);
    next = p + 1;
    if (next != (u32 *)vec[1]) fn_88562DC0(p, next, (u32)(vec[1] - (u32)next));
    vec[1] -= 4;
    return p;
}
