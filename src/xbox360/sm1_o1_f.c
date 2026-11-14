/* SM1 /O1 batch f. */
#include "ts4_vector.h"

/* Swing_DLL.xex 0x883ED550: set or clear bit 1 of the flag byte at +0x20 */
typedef struct Ts4Flags20 { char pad[0x20]; unsigned char flags; } Ts4Flags20;
int ts4_set_flag_bit1_off20_883ED550(Ts4Flags20 *t, unsigned char on) { if (on) t->flags |= 2; else t->flags &= 0xfd; return 0; }

/* 0x882AC048 / 0x882AC058: call the shared vector routine with a constant vector argument */
extern int fn_882ABE80(void *, __vector4);
extern __vector4 lbl_88001A30;
extern __vector4 lbl_88001A40;
int ts4_call_with_const_vector_a_882AC048(void *t) { return fn_882ABE80(t, lbl_88001A30); }
int ts4_call_with_const_vector_b_882AC058(void *t) { return fn_882ABE80(t, lbl_88001A40); }
