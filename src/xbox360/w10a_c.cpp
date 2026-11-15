/* W10A: pooled message-object allocation (Swing_DLL.xex 0x889C0A40). The singleton getter is defined here as in fam3_msg_dtor.cpp so the compiler knows its register use (copy: do not integrate twice). Plain route, C++, /Oc. */
typedef unsigned int u32;
#ifdef _MSC_VER
typedef unsigned W10Size;
#define W10_NOINLINE __declspec(noinline)
#else
typedef __SIZE_TYPE__ W10Size;
#define W10_NOINLINE
#endif
struct Ts4BumpPool {
    char storage[0x400];
    char *cursor;
    int remaining;
};
static void *lbl_88D45B10;
extern "C" {
extern Ts4BumpPool lbl_88D429F0;
extern char lbl_88D49304[];
}
inline void *operator new(W10Size, Ts4BumpPool &pool)
{
    char *block = pool.cursor;
    pool.cursor = block + 8;
    pool.remaining -= 8;
    return block;
}
struct Ts4MsgPoolService {
    void *vtbl;
    Ts4MsgPoolService() { vtbl = lbl_88D49304; }
};
extern "C" W10_NOINLINE Ts4MsgPoolService *ts4_msg_pool_service_get_8864DFF0(void)
{
    Ts4MsgPoolService *service = (Ts4MsgPoolService *)lbl_88D45B10;
    if (!service) {
        service = new (lbl_88D429F0) Ts4MsgPoolService;
        lbl_88D45B10 = service;
    }
    return service;
}
struct A3Obj { char pad[0x7c]; void *w7c; char pad2[0x234 - 0x80]; unsigned char b234; char pad3[3];
  A3Obj(void *a); };
extern "C" void fn_8864C170(A3Obj *o, void *a);
inline A3Obj::A3Obj(void *a) { fn_8864C170(this, a); w7c = this; b234 = 0; }
inline void *operator new(W10Size n, Ts4BumpPool &p, int)
{
    char *b = p.cursor;
    p.cursor = b + n;
    p.remaining -= n;
    return b;
}
extern "C" A3Obj *ts4_pool_new_obj_889C0A40(void *a)
{
    Ts4BumpPool *pool = &lbl_88D429F0;
    pool->cursor = (char *)pool;
    pool->remaining = 0x400;
    ts4_msg_pool_service_get_8864DFF0();
    return new (*pool, 0) A3Obj(a);
}
