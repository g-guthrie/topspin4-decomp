/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct R12 { u64 a; u32 b; };
struct VT3 { virtual void f0(); virtual void f1(); virtual void f2(); virtual int m3(int a); };
struct Bf3 { u32 pad:29; u32 v:3; };
struct O38 { char p0[0x10]; u64 flags; char p1[0x2930]; Bf3 bf; };
struct E98 { char p[0x74]; u32 k; char q[0x15 - 0x0 + 0x98 - 0x74 - 4 - 0x15 + 0x15 - 0x15]; };
extern "C" {
extern char *lbl_88D45AD4;
extern char lbl_880F2190[], lbl_880F216C[], lbl_880EE24C[];
extern void fn_88707360(void *, void *, int, int);
extern void fn_88290568(void *, int, void *, int, int);
extern char fn_88162C60(void *);
extern void fn_88150600(void *, int);
extern int fn_8872F390(void *);
extern int ts4_if_get_u32_off0_8871E468(void *);
extern void ts4_call_seq_lbl_880F2148_88736F30(void *);
extern void fn_88222D28(void *);
extern void fn_88744C70(void *);
extern void fn_8862C0E8(void *, void *);
extern int fn_88923530(u64, u64, u32);
extern int fn_88923530b(u64, u64, u32);
/* Swing_DLL.xex 0x887146C0 */
void ts4_select_slot_or_forward_887146C0(char *s, int a, int i) { char *o = *(char**)(lbl_88D45AD4 + 0x28); if (*(int*)(o+0x110) != a) { fn_88707360(o, s, a, i); return; } fn_88290568(*(void**)(lbl_88D45AD4 + 0x15720), 0xb5, o + i*64 + 0x50, 4, 0x60000); }
/* Swing_DLL.xex 0x88736ED8 */
int ts4_refresh_and_call_virtual3_88736ED8(VT3 *s, int a) { u8 r = fn_88162C60((char*)s + 8); u8 e = (r == 0); fn_88150600((char*)s + 8, a); return s->m3(e); }
}
