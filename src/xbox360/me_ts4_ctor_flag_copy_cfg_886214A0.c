/* Swing_DLL.xex 0x886214A0: constructor; base fn_8861B128, clears the flag at +0x24, sets the vtable and copies
 * lbl_88D45B1C->+0x2a4 to +0x224. agO: lookalike of 8862A190; LTCG only (plain 5 off). */
extern char lbl_880F84F0[];
typedef struct Ts4Globals { char pad[0x2a4]; int f2a4; } Ts4Globals;
extern Ts4Globals *lbl_88D45B1C;
void fn_8861B128(void *self);

typedef struct Obj { void *vtbl; char pad[0x20]; unsigned char b24; char pad2[0x1ff]; int f224; } Obj;

Obj *fn_886214A0(Obj *self)
{
    fn_8861B128(self);
    self->b24 = 0;
    self->vtbl = lbl_880F84F0;
    self->f224 = lbl_88D45B1C->f2a4;
    return self;
}
