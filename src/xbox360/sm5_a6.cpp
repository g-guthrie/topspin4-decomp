/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct R12 { u64 a; u32 b; };
struct VT { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual int m7(int a, int b); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual R12 m16(); };
struct E32 { char p[0xc]; u32 k; char q[0x14]; };
extern "C" {
extern char lbl_880F3388[], lbl_88C47630[];
extern E32 lbl_88C6C948[];
extern void *lbl_88D45B38;
extern float lbl_8814B910;
extern double floor(float);
extern char *g_ts4_session_context;
extern void fn_88703AC0(u64, u64);
extern void fn_886131F0(void *, void *, u32);
extern void fn_885651F8(void *);
extern void fn_887DD110(void *, u32, u8, int);
extern void fn_88150600(void *, void *);
/* Swing_DLL.xex 0x88713C18 */
void ts4_forward_virtual16_result_88713C18(VT *s) { R12 *r = &(R12&)s->m16(); fn_88703AC0(r->a, (u64)r->b << 32); }
/* Swing_DLL.xex 0x887789F8 */
int ts4_forward_virtual7_to_child_887789F8(char *s, int a, int i) { int o = *(int*)(s+0x18); if (o) return ((VT*)o)->m7(a, ((int*)lbl_88C47630)[i]); return ((VT*)*(VT**)(s+0x10))->m7(a, i); }
/* Swing_DLL.xex 0x887DF0C0 */
void ts4_store_byte_and_call_887DF0C0(char *s, u8 a, int b) { u64 t[2]; s[0x74] = a; fn_887DD110(t, *(u32*)(s+0x20), a, b); }
}
