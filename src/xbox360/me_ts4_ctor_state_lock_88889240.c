/* Swing_DLL.xex 0x88889240: constructor; base fn_8862AD78, vtable, clears the state words/flags at +0x14dc..+0x14f0, sets the
 * inner vtable at +0x14f4 and initialises the critical section at +0x14f8. agO: the void **pv store keeps the target order. */
extern char lbl_880DF260[];
extern char lbl_880D1F0C[];
void fn_8862AD78(void *self);
void RtlInitializeCriticalSection(void *cs);
typedef struct State { int a; int b; int c; unsigned char d; char pad[7]; unsigned char e; char pad2[3]; void *vt; } State;
static __forceinline void state_init(State *s) { s->a = 0; s->b = 0; s->c = 0; s->d = 0; s->e = 0; { void **pv = &s->vt; *pv = lbl_880D1F0C; } }
typedef struct Obj { void *vtbl; char pad[0x14d8]; State st; char cs[0x1c]; } Obj;

Obj *fn_88889240(Obj *self)
{
    fn_8862AD78(self);
    self->vtbl = lbl_880DF260;
    state_init(&self->st);
    RtlInitializeCriticalSection(self->cs);
    return self;
}
