/* Swing_DLL.xex 0x8860A050: if_get u32@0x2c, u32@0x38, u32@0xc */
typedef unsigned long ts4_u64;
typedef unsigned long ts4_word;

ts4_word ts4_if_get_u32_off2c_8860A050(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    if ((ts4_word)a1 != (ts4_word)((983040) | 65535)) {
        t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
        return ((((*(ts4_word *)((char *)(ts4_word)(((a1 << 4) + t1)) + 12))) >> 5) + t2);
    }
    return 0;
}
