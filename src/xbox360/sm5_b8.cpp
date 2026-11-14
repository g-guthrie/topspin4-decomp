/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct R12 { u64 a; u32 b; };
extern "C" {
extern char lbl_880D85CC[], lbl_880EE24C[];
extern void fn_8862C0E8(R12 *, void *);
extern int fn_88923530(u32, u64, u64, u32);
/* Swing_DLL.xex 0x8878EB10 */
int ts4_lookup_by_hash_f895ecb1_8878EB10(void) { R12 r; fn_8862C0E8(&r, lbl_880D85CC); return fn_88923530(r.b, r.a, (u64)r.b << 32, 0xF895ECB1u); }
/* Swing_DLL.xex 0x887906F8 */
void ts4_set_id_from_hash_4b9173e_887906F8(char *s, int a) { R12 r; *(int*)(s+8) = a; fn_8862C0E8(&r, lbl_880EE24C); *(int*)(s+0x3c34) = fn_88923530(r.b, r.a, (u64)r.b << 32, 0x4B9173Eu); }
}
