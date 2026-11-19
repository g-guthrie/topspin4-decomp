/* NEAR MISS (agO round 3, 2026-11-19): 2 off on plain and LTCG (/Oc): stb +0x10 and addi r3,r3,0x18 are swapped.
 * Lookalike of 88889240; the state_init/pv form there makes this one worse (10 off). */
/* Swing_DLL.xex 0x8860C2E0: constructor; float g_ts4_script_constants[79] at +4, clears +8/+0xc and the flags at +0x10/+0x11, sets the
 * vtable and the inner lock vtable lbl_880D1F0C at +0x14, initialises the critical section at +0x18. agO: lookalike of 88889240. */
extern char lbl_880F78DC[];
extern char lbl_880D1F0C[];
extern float g_ts4_script_constants[];
void RtlInitializeCriticalSection(void *cs);
typedef struct Obj { void *vtbl; float f4; int f8; int fc; unsigned char b10; unsigned char b11; char pad[2]; void *lockvt; char cs[0x1c]; } Obj;

Obj *fn_8860C2E0(Obj *self)
{
    self->f4 = g_ts4_script_constants[79];
    self->f8 = 0;
    self->vtbl = lbl_880F78DC;
    self->fc = 0;
    self->b10 = 0;
    self->b11 = 0;
    self->lockvt = lbl_880D1F0C;
    RtlInitializeCriticalSection(self->cs);
    return self;
}
