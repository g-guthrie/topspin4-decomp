/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern "C" {
extern int lbl_88C6C21C, lbl_88C6C220;
extern float lbl_8814B440;
/* Swing_DLL.xex 0x887CF938 */
char **ts4_find_ptr_by_key_pair_887CF938(char *s, u32 *key, u32 x) { u32 k = *key; if (k) { char **p = *(char***)(s+0x40); char **e = *(char***)(s+0x44); if (p != e) { do { char *o = *p; if (*(u32*)(o+0x2c) == k && *(u32*)(o+0x10) == x) return p; p++; } while (p != e); } } return *(char***)(s+0x44); }
/* Swing_DLL.xex 0x887E9720 */
char **ts4_find_in_range_887E9720(char ***s, u32 *key, int b, u32 c) { char **p = s[0]; char **e = s[1]; for (; p != e; p++) { char *o = *p; if (*(u32*)(o+0x14) == *key && *(int*)(o+0x10) == b && (c == 0 || c == *(u32*)(o+0x1c))) return p; } return p; }
/* Swing_DLL.xex 0x887E9CE8 */
char *ts4_find_entry_887E9CE8(char *s, u32 a, u32 b, u32 *key) { char **p = *(char***)(s+0x4c); char **e = *(char***)(s+0x50); for (; p != e; p++) { char *o = *p; if (*(u32*)o == *key && *(u32*)(o+8) == a && *(u32*)(o+4) == b) return o; } return 0; }
}
