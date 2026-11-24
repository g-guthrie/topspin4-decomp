/* SM1 /O1 batch d. */
/* Swing_DLL.xex 0x883FF3E0: vtable slot 8 result plus the field at +0x20 */
typedef struct Ts4VField20 { int (**vt)(); char pad[0x1c]; int extra; } Ts4VField20;
int ts4_vcall_slot8_plus_field20_883FF3E0(Ts4VField20 *t) { return ((int (*)(Ts4VField20 *))t->vt[8])(t) + t->extra; }
