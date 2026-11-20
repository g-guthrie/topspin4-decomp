/* Swing_DLL.xex 0x8862A190: constructor; base fn_8861B128, clears the state block at +0x24, sets the vtable, constructs the members
 * at +0x2c and +0x80. agO from agL's 3-off draft: the forceinline state_init keeps the target store order; plain and LTCG. */
extern char lbl_880F83C0[];
void fn_8861B128(void *self);
void ts4_call_seq_fn_88617D88_8892AFF0(void *member);
void ts4_sbuf_ctor_init_88281740(void *member);

typedef struct State { unsigned char b24; unsigned char b25; char pad2[2]; int i28; } State;
static __forceinline void state_init(State *s) { s->b24 = 0; s->b25 = 0; s->i28 = 0; }
typedef struct Obj { void *vtbl; char pad[0x20]; State st; char m2c[0x54]; char m80[4]; } Obj;

/* Constructor: base, vtable, clear the flags and counter, construct the members at +0x2c and +0x80. */
Obj *fn_8862A190(Obj *self)
{
    fn_8861B128(self);
    state_init(&self->st);
    self->vtbl = lbl_880F83C0;
    ts4_call_seq_fn_88617D88_8892AFF0(self->m2c);
    ts4_sbuf_ctor_init_88281740(self->m80);
    return self;
}
