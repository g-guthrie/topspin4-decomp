/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct VT12 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void m12(); };
struct S28 { char p[0x24]; int f24; char *b; char *e; };
struct P8 { int a, b; };
struct P8u { u64 a; };
extern "C" {
extern long _InterlockedExchange(volatile long *t, long v);
#pragma intrinsic(_InterlockedExchange)
extern char *lbl_88D41FC4;
extern char *lbl_88D45B1C;
/* Swing_DLL.xex 0x88778970 */
void ts4_forward_virtual12_if_unset_88778970(char *s) { if (*(int*)(s+0x18)) return; int p = *(int*)(s+0x10); if (p) ((VT12*)p)->m12(); }
/* Swing_DLL.xex 0x88778BB8 */
void ts4_atomic_clear_a8_88778BB8(char *s) { volatile long z = 0; _InterlockedExchange((volatile long*)(s+0xa8), z); }
/* Swing_DLL.xex 0x8877B118 */
int ts4_set_global_flag_274_8877B118(void) { volatile bool t = true; lbl_88D45B1C[0x274] = t; return 0; }
}
