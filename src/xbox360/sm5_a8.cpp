/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct E32 { char p[0xc]; u32 k; char q[0x10]; };
extern "C" {
extern E32 lbl_88C6C948[];
extern char *g_ts4_session_context;
/* Swing_DLL.xex 0x887797E0 */
E32 *ts4_find_entry_by_key_stride32_887797E0(u32 k) { E32 *r = 0; for (u32 i = 0; i < 21; i++) { if (k == lbl_88C6C948[i].k) { r = &lbl_88C6C948[i]; break; } } return r; }
#define G char *a = *(char**)(g_ts4_session_context+0x68); char *b = *(char**)(g_ts4_session_context+0x6c); char *q = a + 0x220;
}
