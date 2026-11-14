/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct VT { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual int m12(int a, int b); };
extern "C" {
extern char *lbl_88D45AD4;
extern char *lbl_88D45B1C;
extern char g_ts4_tsu_format[], lbl_880EAD84[], lbl_880EA5E4[];
extern void fn_8822A1E8(void *, void *, u8);
extern void fn_8875DCD8(void *, void *, int);
extern void ts4_format_text(char *, u32, const char *, ...);
extern void ts4_forward_varargs_88606270(void *, int, const char *, void *);
extern void fn_881AAF10(void *, void *);
extern void fn_88617D88(void *);
extern char *fn_88617D88r(void *);
extern void fn_8857BA40(void *, int, int);
extern VT *lbl_88D45A24;
extern void __eieio(void);
#pragma intrinsic(__eieio)
extern void RtlLeaveCriticalSection(void *);
extern void fn_88778BE8(void *, int);
extern void ts4_tailcall_fn_88584548_8857AFE8(int);
extern int lbl_88C6C220, lbl_88C6C21C;
extern float lbl_8814B440;

/* Swing_DLL.xex 0x887CE408 */
int ts4_check_hash_pair_887CE408(char *s) { if (*(u32*)(*(char**)(s+0x38)+0x2c) == 0x1DCA7285u && (*(char**)(s+0x34))[0x1c]) return 0x99F8C8F0u == *(u32*)(*(char**)(s+0x3c)+0x2cc); return 0; }
/* Swing_DLL.xex 0x887CE9B8 */
bool ts4_float_ge_then_ne_887CE9B8(float *p) { int a = lbl_88C6C220; int b = (*p >= lbl_8814B440) ? lbl_88C6C21C : a; return b != a; }
}
