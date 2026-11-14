/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern "C" {
extern char *lbl_88D45AD4;
extern char lbl_880D6B70[];
extern char *lbl_88D45B1C;
extern char *lbl_88C46F42x;
extern u8 lbl_88C46F42;
extern char *g_ts4_session_context;
extern double fn_88564D28(void);
extern int fn_887CE478(void *, void *, int);

struct bf { u32 pad0:3; u32 v:8; u32 rest:21; };
struct obj1 { char p[0x10]; u64 flags; char q[0x2938]; u32 f; };
/* Swing_DLL.xex 0x88778738 */
void ts4_shift_bytes_down_by_0x26_clear_src_88778738(char *s) { for (int i=0;i<0x26;i++) { s[i] = s[0x26+i]; s[0x26+i]=0; } }
/* Swing_DLL.xex 0x88778848 */
int ts4_call_f64_to_int_88778848(void) { return (int)(float)fn_88564D28(); }
/* Swing_DLL.xex 0x887CF9D8 */
bool ts4_flag1c_set_and_flag1d_clear_887CF9D8(char *s) { char *p=*(char**)(s+0x11c); return p[0x1c] && !p[0x1d]; }
/* Swing_DLL.xex 0x887D1398 */
int ts4_set_key_and_forward_if_flag_d4_887D1398(char *s, char *k) { if (*(u8*)(*(char**)(s+0x34)+0xd4)) { *(u32*)(k+0x30)=0x6D91F16C; return fn_887CE478(s,k,0);} return 0; }
/* Swing_DLL.xex 0x887E9CC0 */
int ts4_rel_entry_field_c_887E9CC0(char *s, u32 x) { return *(int*)(*(char**)(*(char**)(s+0x30) + (x&0x3fff)*20 + 8)+0xc); }
}
