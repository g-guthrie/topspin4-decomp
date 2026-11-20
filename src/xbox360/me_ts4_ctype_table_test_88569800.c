/* 0x88569800: iswctype-style test: table lbl_88C311F8[c] & mask for c < 0x100, 0 for WEOF (0xffff) and wider characters */
/* Matched on /Os plain and LTCG (work/army/ME/v.py chk). */
extern unsigned short *lbl_88C311F8;
int ts4_ctype_table_test_88569800(unsigned short c, unsigned short mask)
{
    if (c != 0xffff && c < 0x100) return lbl_88C311F8[c] & mask;
    return 0;
}
