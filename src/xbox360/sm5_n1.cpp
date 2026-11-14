/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned int u32;
extern "C" {
/* Swing_DLL.xex 0x887E9BF8 */
void ts4_init_flag_and_zero_887E9BF8(char *s) { volatile bool t = false; *(int*)(s+4)=0; *(bool*)s = t; }
/* Swing_DLL.xex 0x887EA1C0 */
void ts4_set_bool_true_c_887EA1C0(char *s) { volatile bool t = true; *(bool*)(s+0xc) = t; }
}
