/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct Pair { char *b; char *e; };
struct S28 { char p[0x24]; int f24; Pair str; };
extern "C" {
extern char *lbl_88D41FC4;
/* Swing_DLL.xex 0x88779648 */
void ts4_clear_string_set_f24_88779648(S28 *s, int a) { Pair *p = &s->str; if (p->b != p->e) { *p->b = 0; p->e = p->b; } s->f24 = a; }
}
