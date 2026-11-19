/* 0x8859F380: returns entry k-1 of the 8-entry table lbl_88C326D4 for k in 1..8, else 0 */
/* Matched on /Os plain and LTCG (work/army/ME/v.py chk). */
extern const int lbl_88C326D4[];
int ts4_table_1_8_8859F380(unsigned k) { int r = 0; if (k >= 1 && k <= 8) r = lbl_88C326D4[k - 1]; return r; }
