/* NEAR MISS draft (not built, not counted). See docs/agents/matching-tips.md, "Near misses parked". */
struct Scene;
extern "C" { void ts4_if_atomic_interlocked_dec_881876D0(Scene *p);
void *ts4_assign_text_from_c_string(void *out, const char *s);
void fn_88640510(void *mgr, void *text, Scene **out, int flag);
extern void *lbl_88D45290; }
struct Ref { Scene *p; Ref() : p(0) {} ~Ref() { if (p) ts4_if_atomic_interlocked_dec_881876D0(p); } };
struct Obj { char pad[0x19c]; Scene *f19c; unsigned char f1a0; };
struct Arg { char pad[0x18]; char name[1]; };
static inline void find(void *m, Ref *out, const char *n){ int txt; out->p = 0; fn_88640510(m, ts4_assign_text_from_c_string(&txt, n), &out->p, 0); }
struct Ref2 { Scene *p; ~Ref2() { if (p) ts4_if_atomic_interlocked_dec_881876D0(p); } };
extern "C" void f(Obj *o, Arg *x){ Ref2 r; find(lbl_88D45290, (Ref *)&r, x->name);
 if (r.p != o->f19c) { o->f19c = r.p; o->f1a0 = 1; } }