/* Loader_DLL.xex 0x83450758-0x835169B0, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char lbl_8306F7CC[];
extern char lbl_8306F7EC[];
extern char lbl_8307AA18[];
extern char lbl_8352BF70[];
extern char lbl_8352FB20[];
extern char lbl_8352FF3C[];
extern char lbl_8352FF54[];
extern char lbl_83530034[];
extern char lbl_8353004C[];
extern char lbl_83530064[];
extern char lbl_8353007C[];
extern char lbl_8353009C[];
extern char lbl_835300B4[];
extern char lbl_835300CC[];
extern char lbl_835300E4[];
extern char lbl_835300FC[];
extern char lbl_83530114[];
extern char lbl_8353012C[];
extern char lbl_83530144[];
extern char lbl_83530190[];
extern char lbl_835301A8[];
extern char lbl_83530224[];
extern char lbl_8353023C[];
extern char lbl_83530254[];
extern char lbl_8353026C[];
extern char lbl_83530284[];
extern char lbl_8353029C[];
extern char lbl_835302B4[];
extern char lbl_835302CC[];
extern char lbl_835302E4[];
extern char lbl_835302FC[];
extern char lbl_83530314[];
extern char lbl_8353032C[];
extern char lbl_83530348[];
extern char lbl_83530394[];
extern char lbl_835303E0[];
extern char lbl_835303F8[];
extern char lbl_83530410[];
extern char lbl_83530428[];
extern char lbl_83530F30[];
extern char lbl_83530F40[];
extern char lbl_83530F50[];
extern char lbl_83530F74[];
extern char lbl_83530F8C[];
extern char lbl_83530FA4[];
extern char lbl_83530FBC[];
extern char lbl_83530FD4[];
extern char lbl_83530FEC[];
extern char lbl_83531020[];
extern char lbl_8353104C[];
extern char lbl_835310AC[];
extern char lbl_835310B8[];
extern char lbl_835310D0[];
extern char lbl_835310E8[];
extern char lbl_83531108[];
extern char lbl_83531134[];
extern char lbl_83531160[];
extern char lbl_83531194[];
extern char lbl_8353130C[];
extern char lbl_83531674[];
extern char lbl_8353AE5C[];
extern char lbl_835439F8[];
ts4_word fn_830F7600();
ts4_word fn_830F7A08();
ts4_word fn_83109770();
ts4_word fn_831186D0();
ts4_word fn_83119710();
ts4_word fn_83119798();
ts4_word fn_8311B1D8();
ts4_word fn_8311D3F8();
ts4_word fn_83122B58();
ts4_word fn_8313FCF0();
ts4_word fn_83140C58();
ts4_word fn_83143150();
ts4_word fn_8315B4F8();
ts4_word fn_8315F8E8();
ts4_word fn_833E08D8();
ts4_word fn_83440030();
ts4_word fn_83445FC0();
ts4_word fn_83449D78();
ts4_word fn_8348AD98();

/* Loader_DLL.xex 0x83450758: get u8@0x61c, lbl_8307AA18, fn_83445FC0 */
ts4_word ts4_get_u8_off61c_83450758(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1564);
    return fn_83445FC0((ts4_word)a0, (ts4_word)(t1 + (ts4_word)lbl_8307AA18), (ts4_word)(8 - t1));
}

/* Loader_DLL.xex 0x834546F0: call_seq fn_83449D78, fn_83440030 */
ts4_word ts4_call_seq_fn_83449D78_834546F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    fn_83449D78((ts4_word)a0);
    t2 = fn_83440030((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return t2;
}

/* Loader_DLL.xex 0x8348B090: if_call_seq fn_830F7A08, fn_8348AD98, fn_830F7600, fn_8348AD98 */
ts4_word ts4_if_call_seq_fn_830F7A08_8348B090(void)
{
    ts4_word p3;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    int t4;
    ts4_word t5;

    t1 = fn_830F7A08();
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8348AD98((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    t4 = fn_830F7600((ts4_word)p3);
    p6 = (ts4_word)t4;
    if ((int)t4 != 0) {
        t5 = fn_8348AD98((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x835165B8: addr lbl_8352FF54, fn_83140C58 */
ts4_word ts4_addr_lbl_8352FF54_835165B8(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8352FF54);
}

/* Loader_DLL.xex 0x835165C8: addr lbl_8352FF3C, fn_83140C58 */
ts4_word ts4_addr_lbl_8352FF3C_835165C8(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8352FF3C);
}

/* Loader_DLL.xex 0x835165D8: addr lbl_8353007C, fn_83140C58 */
ts4_word ts4_addr_lbl_8353007C_835165D8(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8353007C);
}

/* Loader_DLL.xex 0x835165E8: addr lbl_83530064, fn_83140C58 */
ts4_word ts4_addr_lbl_83530064_835165E8(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530064);
}

/* Loader_DLL.xex 0x835165F8: addr lbl_8353004C, fn_83140C58 */
ts4_word ts4_addr_lbl_8353004C_835165F8(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8353004C);
}

/* Loader_DLL.xex 0x83516608: addr lbl_83530034, fn_83140C58 */
ts4_word ts4_addr_lbl_83530034_83516608(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530034);
}

/* Loader_DLL.xex 0x83516618: addr lbl_8353009C, fn_83140C58 */
ts4_word ts4_addr_lbl_8353009C_83516618(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8353009C);
}

/* Loader_DLL.xex 0x83516628: addr lbl_835300CC, fn_83140C58 */
ts4_word ts4_addr_lbl_835300CC_83516628(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835300CC);
}

/* Loader_DLL.xex 0x83516638: addr lbl_835300B4, fn_83140C58 */
ts4_word ts4_addr_lbl_835300B4_83516638(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835300B4);
}

/* Loader_DLL.xex 0x83516648: addr lbl_8353012C, fn_83140C58 */
ts4_word ts4_addr_lbl_8353012C_83516648(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8353012C);
}

/* Loader_DLL.xex 0x83516658: addr lbl_83530114, fn_83140C58 */
ts4_word ts4_addr_lbl_83530114_83516658(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530114);
}

/* Loader_DLL.xex 0x83516668: addr lbl_835300FC, fn_83140C58 */
ts4_word ts4_addr_lbl_835300FC_83516668(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835300FC);
}

/* Loader_DLL.xex 0x83516678: addr lbl_835300E4, fn_83140C58 */
ts4_word ts4_addr_lbl_835300E4_83516678(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835300E4);
}

/* Loader_DLL.xex 0x83516688: addr lbl_83530144, fn_83140C58 */
ts4_word ts4_addr_lbl_83530144_83516688(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530144);
}

/* Loader_DLL.xex 0x83516698: addr lbl_835301A8, fn_83140C58 */
ts4_word ts4_addr_lbl_835301A8_83516698(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835301A8);
}

/* Loader_DLL.xex 0x835166A8: addr lbl_83530190, fn_83140C58 */
ts4_word ts4_addr_lbl_83530190_835166A8(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530190);
}

/* Loader_DLL.xex 0x835166B8: addr lbl_83530224, fn_83140C58 */
ts4_word ts4_addr_lbl_83530224_835166B8(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530224);
}

/* Loader_DLL.xex 0x835166C8: addr lbl_83530254, fn_83140C58 */
ts4_word ts4_addr_lbl_83530254_835166C8(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530254);
}

/* Loader_DLL.xex 0x835166D8: addr lbl_8353023C, fn_83140C58 */
ts4_word ts4_addr_lbl_8353023C_835166D8(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8353023C);
}

/* Loader_DLL.xex 0x835166E8: addr lbl_8353026C, fn_83140C58 */
ts4_word ts4_addr_lbl_8353026C_835166E8(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8353026C);
}

/* Loader_DLL.xex 0x835166F8: addr lbl_8353029C, fn_83140C58 */
ts4_word ts4_addr_lbl_8353029C_835166F8(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8353029C);
}

/* Loader_DLL.xex 0x83516708: addr lbl_83530284, fn_83140C58 */
ts4_word ts4_addr_lbl_83530284_83516708(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530284);
}

/* Loader_DLL.xex 0x83516718: addr lbl_8353032C, fn_83140C58 */
ts4_word ts4_addr_lbl_8353032C_83516718(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8353032C);
}

/* Loader_DLL.xex 0x83516728: addr lbl_83530314, fn_83140C58 */
ts4_word ts4_addr_lbl_83530314_83516728(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530314);
}

/* Loader_DLL.xex 0x83516738: addr lbl_835302FC, fn_83140C58 */
ts4_word ts4_addr_lbl_835302FC_83516738(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835302FC);
}

/* Loader_DLL.xex 0x83516748: addr lbl_835302E4, fn_83140C58 */
ts4_word ts4_addr_lbl_835302E4_83516748(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835302E4);
}

/* Loader_DLL.xex 0x83516758: addr lbl_835302CC, fn_83140C58 */
ts4_word ts4_addr_lbl_835302CC_83516758(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835302CC);
}

/* Loader_DLL.xex 0x83516768: addr lbl_835302B4, fn_83140C58 */
ts4_word ts4_addr_lbl_835302B4_83516768(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835302B4);
}

/* Loader_DLL.xex 0x83516778: addr lbl_83530348, fn_83140C58 */
ts4_word ts4_addr_lbl_83530348_83516778(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530348);
}

/* Loader_DLL.xex 0x83516788: addr lbl_83530394, fn_83140C58 */
ts4_word ts4_addr_lbl_83530394_83516788(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530394);
}

/* Loader_DLL.xex 0x83516798: fn  */
void ts4_fn_83516798(void)
{
    return;
}

/* Loader_DLL.xex 0x835167A0: addr lbl_835303E0, fn_83140C58 */
ts4_word ts4_addr_lbl_835303E0_835167A0(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835303E0);
}

/* Loader_DLL.xex 0x835167B0: addr lbl_835303F8, fn_83140C58 */
ts4_word ts4_addr_lbl_835303F8_835167B0(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835303F8);
}

/* Loader_DLL.xex 0x835167C0: addr lbl_83530410, fn_83140C58 */
ts4_word ts4_addr_lbl_83530410_835167C0(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530410);
}

/* Loader_DLL.xex 0x835167D0: addr lbl_83530428, fn_83140C58 */
ts4_word ts4_addr_lbl_83530428_835167D0(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530428);
}

/* Loader_DLL.xex 0x835167E0: addr lbl_8352FB20, fn_83109770 */
ts4_word ts4_addr_lbl_8352FB20_835167E0(void)
{
    return fn_83109770((ts4_word)(ts4_word)lbl_8352FB20);
}

/* Loader_DLL.xex 0x835167F0: addr lbl_83530F74, fn_83140C58 */
ts4_word ts4_addr_lbl_83530F74_835167F0(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530F74);
}

/* Loader_DLL.xex 0x83516800: addr lbl_83530F8C, fn_83140C58 */
ts4_word ts4_addr_lbl_83530F8C_83516800(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530F8C);
}

/* Loader_DLL.xex 0x83516810: addr lbl_83530FA4, fn_83140C58 */
ts4_word ts4_addr_lbl_83530FA4_83516810(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530FA4);
}

/* Loader_DLL.xex 0x83516820: addr lbl_83530FBC, fn_83140C58 */
ts4_word ts4_addr_lbl_83530FBC_83516820(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530FBC);
}

/* Loader_DLL.xex 0x83516830: addr lbl_83530FD4, fn_83140C58 */
ts4_word ts4_addr_lbl_83530FD4_83516830(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530FD4);
}

/* Loader_DLL.xex 0x83516840: addr lbl_83530FEC, fn_83140C58 */
ts4_word ts4_addr_lbl_83530FEC_83516840(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_83530FEC);
}

/* Loader_DLL.xex 0x83516850: addr lbl_83530F50, fn_831186D0 */
ts4_word ts4_addr_lbl_83530F50_83516850(void)
{
    return fn_831186D0((ts4_word)(ts4_word)lbl_83530F50);
}

/* Loader_DLL.xex 0x83516860: addr lbl_83530F30, fn_83119710 */
ts4_word ts4_addr_lbl_83530F30_83516860(void)
{
    return fn_83119710((ts4_word)(ts4_word)lbl_83530F30);
}

/* Loader_DLL.xex 0x83516870: addr lbl_83530F40, fn_83119798 */
ts4_word ts4_addr_lbl_83530F40_83516870(void)
{
    return fn_83119798((ts4_word)(ts4_word)lbl_83530F40);
}

/* Loader_DLL.xex 0x83516880: addr lbl_83531020, fn_8311B1D8 */
ts4_word ts4_addr_lbl_83531020_83516880(void)
{
    return fn_8311B1D8((ts4_word)(ts4_word)lbl_83531020);
}

/* Loader_DLL.xex 0x83516890: addr lbl_8353104C, fn_8311D3F8 */
ts4_word ts4_addr_lbl_8353104C_83516890(void)
{
    return fn_8311D3F8((ts4_word)(ts4_word)lbl_8353104C);
}

/* Loader_DLL.xex 0x835168A0: addr lbl_835310B8, fn_83140C58 */
ts4_word ts4_addr_lbl_835310B8_835168A0(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835310B8);
}

/* Loader_DLL.xex 0x835168B0: addr lbl_835310D0, fn_83140C58 */
ts4_word ts4_addr_lbl_835310D0_835168B0(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835310D0);
}

/* Loader_DLL.xex 0x835168C0: addr lbl_835310E8, fn_83140C58 */
ts4_word ts4_addr_lbl_835310E8_835168C0(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_835310E8);
}

/* Loader_DLL.xex 0x835168D0: addr lbl_835310AC, fn_83122B58 */
ts4_word ts4_addr_lbl_835310AC_835168D0(void)
{
    return fn_83122B58((ts4_word)(ts4_word)lbl_835310AC);
}

/* Loader_DLL.xex 0x835168E0: addr lbl_83531108, fn_8313FCF0 */
ts4_word ts4_addr_lbl_83531108_835168E0(void)
{
    return fn_8313FCF0((ts4_word)(ts4_word)lbl_83531108);
}

/* Loader_DLL.xex 0x835168F0: addr lbl_83531134, fn_8313FCF0 */
ts4_word ts4_addr_lbl_83531134_835168F0(void)
{
    return fn_8313FCF0((ts4_word)(ts4_word)lbl_83531134);
}

/* Loader_DLL.xex 0x83516900: addr lbl_83531160, fn_8313FCF0 */
ts4_word ts4_addr_lbl_83531160_83516900(void)
{
    return fn_8313FCF0((ts4_word)(ts4_word)lbl_83531160);
}

/* Loader_DLL.xex 0x83516910: addr lbl_83531194, fn_83143150 */
ts4_word ts4_addr_lbl_83531194_83516910(void)
{
    return fn_83143150((ts4_word)(ts4_word)lbl_83531194);
}

/* Loader_DLL.xex 0x83516920: fn  */
void ts4_fn_83516920(void)
{
    return;
}

/* Loader_DLL.xex 0x83516928: addr lbl_8353130C, fn_8315F8E8 */
ts4_word ts4_addr_lbl_8353130C_83516928(void)
{
    return fn_8315F8E8((ts4_word)(ts4_word)lbl_8353130C);
}

/* Loader_DLL.xex 0x83516938: addr lbl_83531674, fn_8315B4F8 */
ts4_word ts4_addr_lbl_83531674_83516938(void)
{
    return fn_8315B4F8((ts4_word)(ts4_word)lbl_83531674);
}

/* Loader_DLL.xex 0x83516948: addr lbl_8353AE5C, fn_83140C58 */
ts4_word ts4_addr_lbl_8353AE5C_83516948(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8353AE5C);
}

/* Loader_DLL.xex 0x83516958: addr lbl_8306F7CC, u32@lbl_8352BF70 */
void ts4_addr_lbl_8306F7CC_83516958(void)
{
    *(ts4_word *)lbl_8352BF70 = (ts4_word)(ts4_word)lbl_8306F7CC;
    return;
}

/* Loader_DLL.xex 0x83516970: addr lbl_835439F8, lbl_8306F7EC, u32@lbl_835439F8, fn_833E08D8 */
ts4_word ts4_addr_lbl_835439F8_83516970(void)
{
    *(ts4_word *)lbl_835439F8 = (ts4_word)(ts4_word)lbl_8306F7EC;
    return fn_833E08D8((ts4_word)(ts4_word)lbl_835439F8);
}
