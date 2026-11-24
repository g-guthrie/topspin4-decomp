/* Swing_DLL.xex 0x884C91E0: if_get u32@0x18 (nonzero -> vcall slot 0xc on it) */
typedef unsigned long ts4_word;

ts4_word ts4_if_get_u32_offc_884C91E0(ts4_word a0)
{
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)) != 0) {
        return ((ts4_word (*)(void *))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))))) + 0))) + 12))))(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 24)))));
    }
    return 0;
}
