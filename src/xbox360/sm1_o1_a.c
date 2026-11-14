/* SM1 /O1 batch a: small functions that were compiled with /O1 (record-form compares, conditional arms). */
typedef unsigned int u32;

/* Swing_DLL.xex 0x883C7078 */
void ts4_set_flag_bit17_off60_883C7078(char *p, unsigned char v) { u32 *w = (u32 *)(p + 0x60); if (v) *w |= 0x20000; else *w &= ~0x20000u; }
