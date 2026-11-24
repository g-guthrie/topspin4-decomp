/* Swing_DLL.xex 0x88636DC8: constructor; base ts4 ctor, vtable, clears +0x20..+0x28 and the flag at +0x1c, and registers
 * itself as lbl_88D45B1C->+0x21c when that slot is empty. agO: LTCG only (plain 7 off). */
extern char lbl_880F7BDC[];
typedef struct Ts4Globals { char pad[0x21c]; int current; } Ts4Globals;
extern Ts4Globals *lbl_88D45B1C;
void fn_88617D88(void *self);
typedef struct State { int f20; int f24; int f28; } State;
static __forceinline void state_init(State *s) { s->f20 = 0; s->f24 = 0; s->f28 = 0; }
typedef struct Obj { void *vtbl; char pad[0x18]; unsigned char b1c; char pad2[3]; State st; } Obj;

Obj *fn_88636DC8(Obj *self)
{
    Ts4Globals *g;
    fn_88617D88(self);
    self->vtbl = lbl_880F7BDC;
    state_init(&self->st);
    g = lbl_88D45B1C;
    if (g->current == 0)
        g->current = (int)self;
    self->b1c = 0;
    return self;
}
