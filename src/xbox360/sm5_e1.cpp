/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct R12 { u64 a; u32 b; };
struct VT7 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual R12 m7(); };
extern "C" {
extern char *lbl_88D45AD4;
extern char *lbl_88D45A4C;
extern void fn_886F6348(void *, int);
extern u32 fn_88608590(int, u32);
extern void fn_88713970(u64, u64, int, int, int);
extern void ts4_if_call_seq_ts4_handle_forward_88150770_88703E18(void *);
extern void fn_88713F18(void *, u32, float);
extern void fn_887208D0(void *);
extern void ts4_if_get_u32_off34_88717650(void *);
extern void fn_8874B668(void *, int, int, int);
extern void fn_88750150(int, int, int, int, int);
extern void *memcpy(void *, const void *, unsigned int);

/* Swing_DLL.xex 0x887001C8 */
void ts4_set_active_slot_887001C8(int a) { if (a != -1) { char *o = *(char**)(lbl_88D45AD4 + 0x2c); if (a != *(int*)(o+0x38)) fn_886F6348(o, a); *(int*)(o+0x38) = a; } }
/* Swing_DLL.xex 0x88717110 */
void ts4_call_with_virtual7_result_88717110(char *s, int a) { char *o = *(char**)s; s[0xd] = 0; R12 *r = &(R12&)((VT7*)o)->m7(); fn_88713970(r->a, (u64)r->b << 32, 0, a, 0); }
/* Swing_DLL.xex 0x88750DD0 */
void ts4_step_mod2_88750DD0(char *s) { int m = *(int*)(s+0x30) % 2; fn_8874B668(s, *(int*)(s+0x34) * m, *(int*)(s+0x38), *(int*)(s+0x3c)); *(int*)(s+0x30) = m + 1; }
/* Swing_DLL.xex 0x88751458 */
void ts4_call_with_copied_block_88751458(char *s) { int buf[0x7c/4]; char *g = lbl_88D45A4C; memcpy(buf, g + 0x8c, 0x7c); fn_88750150(*(int*)(s+0x10), buf[0], buf[1], buf[2], *(int*)(g+0x110)); }
}
