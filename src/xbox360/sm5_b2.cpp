/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
#include "ts4_vector.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct VT { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual int m12(int a, int b); virtual int m13(); virtual int m14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual int m19(int a, int b, int c); };
extern "C" {
extern char *lbl_88D45AD4;
extern char *lbl_88D45B1C;
extern char lbl_880FC790[], lbl_880FC780[], g_ts4_tsu_format[], lbl_880EAD84[], lbl_880EA5E4[], lbl_880EF510[], lbl_880E4BA0[];
extern void fn_8822A1E8(void *, void *, u8);
extern void fn_88712108(void *, void *);
extern void fn_8875DCD8(void *, void *, int);
extern void ts4_format_text(char *, u32, const char *, ...);
extern void fn_88778BE8(void *, int);
extern void ts4_tailcall_fn_88584548_8857AFE8(int);
extern void ts4_destroy_owned_object(void *);
extern void fn_8860BBD8(void *);
extern void ts4_forward_varargs_88606270(void *, int, const char *, void *);
extern void fn_881AAF10(void *, void *);
extern void fn_887A3FE8(void *);
extern void fn_8879A380(void *);
extern void fn_88617D88(void *);
extern void fn_8857BA40(void *, int, int);
extern VT *lbl_88D45A24;
extern float lbl_8814B440;
extern int lbl_88C6C220, lbl_88C6C21C;
extern void __eieio(void);
extern void fn_88151AE0(void *, int);
extern void RtlLeaveCriticalSection(void *);

/* Swing_DLL.xex 0x88718618 */
void ts4_call_with_two_const_vectors_88718618(void *s) { __vector4 v[2]; v[0] = *(__vector4*)lbl_880FC790; v[1] = *(__vector4*)lbl_880FC780; fn_88712108(s, v); }
/* Swing_DLL.xex 0x8877A218 */
void ts4_init_two_sub_records_8877A218(char *s, u8 a) { *(u32*)(*(char**)(s+0x28)+4) = 0xA0BDE62Eu; (*(char**)(s+0x28))[8] = 0; (*(char**)(s+0x28))[9] = 0; (*(char**)(s+0x28))[0x10] = a; *(u32*)(*(char**)(s+0x24)) = 0; *(u32*)(*(char**)(s+0x24)+4) = 0; (*(char**)(s+0x24))[8] = 0; }
/* Swing_DLL.xex 0x887CF990 */
char **ts4_find_in_ptr_vector_by_key_887CF990(char *s, u32 *key) { u32 k = *key; if (k) { char ***p = *(char****)(s+0x40); char ***e = *(char****)(s+0x44); if (p != e) { do { if (*(u32*)((char*)*p + 0x2c) == k) return (char**)p; p++; } while (p != e); } } return *(char***)(s+0x44); }
}
