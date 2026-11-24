/* PR2: CLoadingManager (vtable 0x880DB408) slot 13, the "loading screen is up" poll. C++: the scene
 * references are ref-counted smart pointers copied by value, so the conditional temporaries and their
 * destruction flags come from the compiler. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
extern "C" long _InterlockedIncrement(volatile long *value);
#pragma intrinsic(_InterlockedIncrement)
#else
static inline long _InterlockedIncrement(volatile long *value) { return ++*value; }
#endif
struct Scene { u8 pad0[4]; volatile long refs; u8 pad8[0x58]; u8 name[0x44]; u8 bA4; };
extern "C" void ts4_if_atomic_interlocked_dec_881876D0(Scene *p);
extern "C" u8 ts4_cstr_differs_8817E0D0(void *s, const char *t);
struct SceneRef {
    Scene *p;
    SceneRef(const SceneRef &o) : p(o.p) { if (p) _InterlockedIncrement(&p->refs); }
    ~SceneRef() { if (p) ts4_if_atomic_interlocked_dec_881876D0(p); }
    Scene *operator->() const { return p; }
};
struct SceneStack { u8 pad[0x50]; SceneRef top; SceneRef current() { return top; } };
struct ScriptEngine { u8 pad[0x6c]; SceneStack *scenes; };
struct SaveQueue { u8 pad[0x69]; u8 b69; };
extern "C" void *lbl_88D45A60;
extern "C" ScriptEngine *lbl_88D41FC4;
extern "C" SaveQueue *lbl_88D45A0C;
extern "C" const char lbl_880D82C4[];
extern "C" int ts4_obj_sub_vcall_count_887E9778(SaveQueue *q);
extern "C" void fn_887EB080(SaveQueue *q);

/* 0x888CD978: CLoadingManager vtable slot 13. Ready (returns 1) when there is no RUI manager, or the top scene
 * of the script engine's scene stack ([[0x88D41FC4]+0x6c]+0x50) is S4Loading and activated (+0xA4), and the
 * save queue [0x88D45A0C] has no pending actions. On ready it flushes the save queue and clears its +0x69. */
extern "C" u8 ts4_loading_mgr_ready_888CD978(void)
{
    u8 ok = 1;
    if (lbl_88D45A60 != 0) {
        SceneStack *s = lbl_88D41FC4->scenes;
        if (s->current().p && (ts4_cstr_differs_8817E0D0(s->current()->name, lbl_880D82C4) || !s->current()->bA4))
            ok = 0;
    }
    if (0 < ts4_obj_sub_vcall_count_887E9778(lbl_88D45A0C))
        ok = 0;
    if (ok) {
        fn_887EB080(lbl_88D45A0C);
        lbl_88D45A0C->b69 = 0;
    }
    return ok;
}
