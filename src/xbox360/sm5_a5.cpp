/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct R12 { u64 a; u32 b; };
struct VT { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual int m7(int a, int b); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual R12 m16(); };
extern "C" {
extern char *lbl_88D45AD4;
extern char lbl_880F3388[], lbl_88C47630[], lbl_88C6C948[], lbl_880D85CC[], lbl_880D82D0[], lbl_880E4BA0[];
extern void *lbl_88D45B38;
extern float lbl_8814B910;
extern double floor(float);
extern void fn_88703AC0(u64, u64);
extern void fn_88707360(void *, int, int, int);
extern void fn_88290568(void *, int, void *, int, int);
extern void ts4_if_call_seq_fn_881F04B8_886131F0(void *, void *, u32);
extern void fn_885651F8(void *);
extern char *g_ts4_session_context;
extern void fn_8862C0E8(void *, void *);
extern void fn_8862BE08(void *, void *);
extern void fn_88169350(void *, void *);
extern void fn_887934A8(void *);
extern int fn_88923530(u64, u64, u32);
extern void fn_88150600(void *, void *);
extern int fn_887CE478(void *, void *, int);
extern void fn_887DD110(void *, u32, int, int);
extern void ts4_if_call_seq_NtSetEvent_8857C1F8(void *);

/* Swing_DLL.xex 0x887935C8 */
int ts4_call_chain_return_zero_887935C8(void) { u64 t1; void *t2; fn_8862BE08(&t1, lbl_880D82D0); fn_88169350(&t2, &t1); fn_887934A8(t2); return 0; }
/* Swing_DLL.xex 0x887CDBC0 */
int ts4_set_slot_if_empty_887CDBC0(char *s, int i, u32 v) { if (i >= 0 && i < 4) { u32 *p = (u32*)s + i + 2; if (*p == 0) { *p = v; return 1; } } return 0; }
/* Swing_DLL.xex 0x887CDCC0 */
void ts4_fill_record_from_rel_table_887CDCC0(char *s, u32 *r, u32 a, int b) { r[8] = a; r[6] = b; r[7] = 0; char *q = *(char**)(s+0x2c) + 0x220; char *e = q + (b*16 + *(int*)q); r[5] = *(u32*)(e + *(int*)e); }
/* Swing_DLL.xex 0x887CE548 */
void ts4_set_flag_pair_887CE548(char *s, u8 *p, u8 a, bool b) { if (!p) return; p[4] = a; p[5] = b && !a; }
/* Swing_DLL.xex 0x887D1F80 */
int ts4_forward_with_key_if_hash_mismatch_887D1F80(char *s, char *k) { if (*(u32*)(*(char**)(s+0x30)+0x1c) != 0x1436B81Au) { *(u32*)(k+0x30)=0x836DEAF2u; return fn_887CE478(s,k,0);} return 0; }
/* Swing_DLL.xex 0x887EA7D0 */
void ts4_set_state_and_signal_event_887EA7D0(char *s, u32 v) { u8 st = s[1]; *(u32*)(s+4) = v; volatile bool t = true; s[0] = t; if (st == 1) ts4_if_call_seq_NtSetEvent_8857C1F8(*(void**)(s+8)); }
}
