/* W10A: singleton holder init (Swing_DLL.xex 0x886412C0); LTCG route only (the plain route schedules the heap load one slot early). */
typedef unsigned int u32;
extern char lbl_880F61D0[];
extern void *lbl_88D41F80;
extern void *lbl_88D41FC0;
extern void *lbl_88D45B38;
typedef struct A6O { void *vt; void *w4; } A6O;
extern void *fn_88198CE0(void *p);
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
extern void *fn_88640DC8(void *p);
extern void fn_88640A30(void *p);
extern void fn_881992A8(void *a, void *b);
A6O *ts4_singleton_init_886412C0(A6O *s)
{
    void *lock;
    void *n;
    void *old;
    void *fresh;
    s->vt = lbl_880F61D0;
    s->w4 = 0;
    lbl_88D41F80 = s;
    lock = fn_88198CE0(lbl_88D41FC0);
    n = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x4b0, 0x10, 0, 2);
    if (n) fresh = fn_88640DC8(n); else fresh = 0;
    old = s->w4;
    if (old) {
        fn_88640A30(old);
        fn_881992A8(0, old);
    }
    s->w4 = fresh;
    fn_88198CE0(lock);
    return s;
}
