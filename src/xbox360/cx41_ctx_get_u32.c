/* context only: model of 0x888C0E18 (supplies its register usage to LTCG callers) */
#ifdef _MSC_VER
typedef unsigned int ts4_word;
#else
typedef unsigned long ts4_word;
#endif
extern char lbl_88D45B1C[];
#ifdef _MSC_VER
__declspec(noinline)
#endif
ts4_word ts4_if_get_u32_lbl_88D45B1C_888C0E18(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636);
    p3 = (ts4_word)0;
    if (((ts4_word)a1 != (ts4_word)t2 && (ts4_word)a1 != (ts4_word)((2187984896) | 26323)) && (ts4_word)a1 == (ts4_word)((1186791424) | 6071)) {
        p3 = (ts4_word)1;
    }
    if ((ts4_word)(p3 & 0xff) != 1) {
        return p3;
    }
    *(volatile unsigned char *)(*(ts4_word *)(*(ts4_word *)(*(ts4_word *)(a0 + 4) + 68) + 16) + 68) = (unsigned char)1;
    return p3;
}
