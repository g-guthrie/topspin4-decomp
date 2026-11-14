/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char ts4_addr_lbl_8803A308_88AFF638[];
extern char ts4_addr_lbl_8803A308_88AFF650[];
extern char ts4_addr_lbl_8803A308_88AFF668[];
extern char ts4_addr_lbl_8803A308_88AFF680[];
extern char ts4_addr_lbl_8803A308_88AFF698[];
extern char lbl_88042110[];
extern char lbl_8805E7C8[];
extern char lbl_8805FDA0[];
extern char lbl_88060748[];
extern char lbl_88060834[];
extern char lbl_88061D40[];
extern char lbl_88062F30[];
extern char lbl_8806301C[];
extern char lbl_880645E0[];
extern char lbl_88064E78[];
extern char lbl_88066590[];
extern char lbl_88066FE0[];
extern char lbl_88068838[];
extern char lbl_88B97D68[];
extern char lbl_88B97D74[];
extern char lbl_88B97E9C[];
extern char lbl_88B984D0[];
extern char lbl_88B98550[];
extern char lbl_88B9860C[];
extern char lbl_88B98B44[];
extern char lbl_88B98F50[];
extern char lbl_88B98F54[];
extern char lbl_88B9928C[];
extern char lbl_88B994BC[];
extern char lbl_88B994C0[];
extern char lbl_88B994C4[];
extern char lbl_88B9BBA8[];
extern char lbl_88B9BC50[];
extern char lbl_88B9BD70[];
extern char lbl_88B9BDE8[];
extern char lbl_88B9BE90[];
extern char lbl_88B9BEA8[];
extern char lbl_88B9BF50[];
extern char lbl_88B9BF98[];
extern char lbl_88B9C070[];
extern char lbl_88B9C0E8[];
extern char lbl_88B9C100[];
extern char lbl_88B9C178[];
extern char lbl_88B9C1D8[];
extern char lbl_88B9C298[];
extern char lbl_88B9C670[];
extern char lbl_88B9C6D4[];
extern char lbl_88B9CAB4[];
extern char lbl_88B9CEE0[];
extern char lbl_88B9D270[];
extern char lbl_88B9D368[];
extern char lbl_88B9D3A0[];
extern char lbl_88B9D3BC[];
extern char lbl_88B9E6BC[];
extern char lbl_88B9E6D8[];
extern char lbl_88B9E834[];
extern char lbl_88B9E9C0[];
extern char lbl_88B9EC88[];
extern char lbl_88B9EDC4[];
extern char lbl_88B9EFC4[];
extern char lbl_88B9F0D0[];
extern char lbl_88B9FCA8[];
extern char lbl_88BA007C[];
extern char lbl_88BA0114[];
extern char lbl_88BA0238[];
extern char lbl_88BA07C8[];
extern char lbl_88BA07D4[];
extern char lbl_88BA08FC[];
extern char lbl_88BA0F30[];
extern char lbl_88BA0FB0[];
extern char lbl_88BA106C[];
extern char lbl_88BA15A4[];
extern char lbl_88BA19B0[];
extern char lbl_88BA19B4[];
extern char lbl_88BA1CEC[];
extern char lbl_88BA1F1C[];
extern char lbl_88BA1F20[];
extern char lbl_88BA1F24[];
extern char lbl_88BA37C8[];
extern char lbl_88BA3810[];
extern char lbl_88BA3888[];
extern char lbl_88BA39C0[];
extern char lbl_88BA3A38[];
extern char lbl_88BA3BB8[];
extern char lbl_88BA3CA8[];
extern char lbl_88BA3DB0[];
extern char lbl_88BA3ED0[];
extern char lbl_88BA3F00[];
extern char lbl_88BA3FC0[];
extern char lbl_88BA4098[];
extern char lbl_88BA40C8[];
extern char lbl_88BA40F8[];
extern char lbl_88BA4128[];
extern char lbl_88BA41A0[];
extern char lbl_88BA41E8[];
extern char lbl_88BA4260[];
extern char lbl_88BA4290[];
extern char lbl_88BA4338[];
extern char lbl_88BA43F8[];
extern char lbl_88BA44A0[];
extern char lbl_88BA45F0[];
extern char lbl_88BA4698[];
extern char lbl_88BA47D0[];
extern char lbl_88BA4848[];
extern char lbl_88BA48F0[];
extern char lbl_88BA4908[];
extern char lbl_88BA49B0[];
extern char lbl_88BA49F8[];
extern char lbl_88BA4AD0[];
extern char lbl_88BA4B48[];
extern char lbl_88BA4B60[];
extern char lbl_88BA4BD8[];
extern char lbl_88BA4C38[];
extern char lbl_88BA4CF8[];
extern char lbl_88BA5118[];
extern char lbl_88BA517C[];
extern char lbl_88BA555C[];
extern char lbl_88BA5A60[];
extern char lbl_88BA5E3C[];
extern char lbl_88BA5F94[];
extern char lbl_88BA60BC[];
extern char lbl_88BA6978[];
extern char lbl_88BA74E0[];
extern char lbl_88BA74E4[];
extern char lbl_88BA7AC0[];
extern char lbl_88BA7B44[];
extern char lbl_88BA7BFC[];
extern char lbl_88BA8110[];
extern char lbl_88BA8208[];
extern char lbl_88BA8254[];
extern char lbl_88BA9218[];
extern char lbl_88BA9760[];
extern char lbl_88BA9B34[];
extern char lbl_88BA9CF0[];
extern char lbl_88BAA280[];
extern char lbl_88BAA28C[];
extern char lbl_88BAA3B4[];
extern char lbl_88BAA9E8[];
extern char lbl_88BAAA68[];
extern char lbl_88BAAB24[];
extern char lbl_88BAB05C[];
extern char lbl_88BAB468[];
extern char lbl_88BAB804[];
extern char lbl_88BAD2E0[];
extern char lbl_88BAD328[];
extern char lbl_88BAD3A0[];
extern char lbl_88BAD4D8[];
extern char lbl_88BAD550[];
extern char lbl_88BAD6D0[];
extern char lbl_88BAD7C0[];
extern char lbl_88BAD8C8[];
extern char lbl_88BAD9E8[];
extern char lbl_88BADA18[];
extern char lbl_88BADAD8[];
extern char lbl_88BADBB0[];
extern char lbl_88BADBE0[];
extern char lbl_88BADC10[];
extern char lbl_88BADC40[];
extern char lbl_88BADCB8[];
extern char lbl_88BADD00[];
extern char lbl_88BADD78[];
extern char lbl_88BADE38[];
extern char lbl_88BADF10[];
extern char lbl_88BADFD0[];
extern char lbl_88BAE078[];
extern char lbl_88BAE1C8[];
extern char lbl_88BAE270[];
extern char lbl_88BAE3A8[];
extern char lbl_88BAE420[];
extern char lbl_88BAE4C8[];
extern char lbl_88BAE4E0[];
extern char lbl_88BAE588[];
extern char lbl_88BAE5D0[];
extern char lbl_88BAE6A8[];
extern char lbl_88BAE720[];
extern char lbl_88BAE738[];
extern char lbl_88BAE7B0[];
extern char lbl_88BAECA8[];
extern char lbl_88BAED0C[];
extern char lbl_88BAF0EC[];
extern char lbl_88BAFA2C[];
extern char lbl_88BAFB84[];
extern char lbl_88BAFCC4[];
extern char lbl_88BB0580[];
extern char lbl_88BB0DB0[];
extern char lbl_88BB0FB4[];
extern char lbl_88BB1330[];
extern char lbl_88BB148C[];
extern char lbl_88BB1618[];
extern char lbl_88BB18E0[];
extern char lbl_88BB1A1C[];
extern char lbl_88BB1C1C[];
extern char lbl_88BB1D28[];
extern char lbl_88BB1D8C[];
extern char lbl_88BB30FC[];
extern char lbl_88BB3638[];
extern char lbl_88BB3644[];
extern char lbl_88BB385C[];
extern char lbl_88BB3D00[];
extern char lbl_88BB4008[];
extern char lbl_88BB400C[];
extern char lbl_88BB44DC[];
extern char lbl_88BB46B8[];
extern char lbl_88BB4EA8[];
extern char lbl_88BB4EDC[];
extern char lbl_88BB5320[];
extern char lbl_88BB6D58[];
extern char lbl_88BB6DA0[];
extern char lbl_88BB6E18[];
extern char lbl_88BB6F50[];
extern char lbl_88BB6FC8[];
extern char lbl_88BB7160[];
extern char lbl_88BB7250[];
extern char lbl_88BB7358[];
extern char lbl_88BB7508[];
extern char lbl_88BB7628[];
extern char lbl_88BB7658[];
extern char lbl_88BB7718[];
extern char lbl_88BB77F0[];
extern char lbl_88BB7820[];
extern char lbl_88BB7850[];
extern char lbl_88BB7880[];
extern char lbl_88BB78F8[];
extern char lbl_88BB7940[];
extern char lbl_88BB79B8[];
extern char lbl_88BB7A78[];
extern char lbl_88BB7B50[];
extern char lbl_88BB7C10[];
extern char lbl_88BB7CB8[];
extern char lbl_88BB7E08[];
extern char lbl_88BB7EB0[];
extern char lbl_88BB7FE8[];
extern char lbl_88BB8060[];
extern char lbl_88BB8108[];
extern char lbl_88BB8120[];
extern char lbl_88BB81C8[];
extern char lbl_88BB8210[];
extern char lbl_88BB82E8[];
extern char lbl_88BB8360[];
extern char lbl_88BB8378[];
extern char lbl_88BB83F0[];
extern char lbl_88BB88E8[];
extern char lbl_88BB894C[];
extern char lbl_88BB8D2C[];
extern char lbl_88BB9684[];
extern char lbl_88BB97DC[];
extern char lbl_88BB994C[];
extern char lbl_88BBA1D8[];
extern char lbl_88BBAA20[];
extern char lbl_88BBAC24[];
extern char lbl_88BBB090[];
extern char lbl_88BBB21C[];
extern char lbl_88BBB3A8[];
extern char lbl_88BBB688[];
extern char lbl_88BBB7C4[];
extern char lbl_88BBB9C4[];
extern char lbl_88BBBAD0[];
extern char lbl_88BBBB34[];
extern char lbl_88BBCF64[];
extern char lbl_88BBD4A0[];
extern char lbl_88BBD4AC[];
extern char lbl_88BBD604[];
extern char lbl_88BBDC58[];
extern char lbl_88BBDFC0[];
extern char lbl_88BBDFC4[];
extern char lbl_88BBE4DC[];
extern char lbl_88BBE6B8[];
extern char lbl_88BBEEA8[];
extern char lbl_88BBEEDC[];
extern char lbl_88BBF338[];
extern char lbl_88BBFE10[];
extern char lbl_88BC0E98[];
extern char lbl_88BC0EE0[];
extern char lbl_88BC0F58[];
extern char lbl_88BC1090[];
extern char lbl_88BC1138[];
extern char lbl_88BC12D0[];
extern char lbl_88BC13C0[];
extern char lbl_88BC14C8[];
extern char lbl_88BC1678[];
extern char lbl_88BC1798[];
extern char lbl_88BC17C8[];
extern char lbl_88BC1888[];
extern char lbl_88BC1960[];
extern char lbl_88BC1990[];
extern char lbl_88BC19C0[];
extern char lbl_88BC19F0[];
extern char lbl_88BC1A68[];
extern char lbl_88BC1AB0[];
extern char lbl_88BC1B28[];
extern char lbl_88BC1BE8[];
extern char lbl_88BC1CC0[];
extern char lbl_88BC1DB0[];
extern char lbl_88BC1E88[];
extern char lbl_88BC1FF0[];
extern char lbl_88BC2098[];
extern char lbl_88BC21D0[];
extern char lbl_88BC2248[];
extern char lbl_88BC22F0[];
extern char lbl_88BC2308[];
extern char lbl_88BC23B0[];
extern char lbl_88BC23F8[];
extern char lbl_88BC24D0[];
extern char lbl_88BC2548[];
extern char lbl_88BC2560[];
extern char lbl_88BC25D8[];
extern char lbl_88BC2A58[];
extern char lbl_88BC2C08[];
extern char lbl_88BC2C6C[];
extern char lbl_88BC304C[];
extern char lbl_88BC39A4[];
extern char lbl_88BC3AFC[];
extern char lbl_88BC3C6C[];
extern char lbl_88BC44F8[];
extern char lbl_88BC4D40[];
extern char lbl_88BC4F5C[];
extern char lbl_88BC53C8[];
extern char lbl_88BC5554[];
extern char lbl_88BC56E0[];
extern char lbl_88BC59C0[];
extern char lbl_88BC5AFC[];
extern char lbl_88BC5CFC[];
extern char lbl_88BC5E08[];
extern char lbl_88BC5E6C[];
extern char lbl_88BC729C[];
extern char lbl_88BC77D8[];
extern char lbl_88BC77E4[];
extern char lbl_88BC793C[];
extern char lbl_88BC7F90[];
extern char lbl_88BC82F8[];
extern char lbl_88BC82FC[];
extern char lbl_88BC8814[];
extern char lbl_88BC88D4[];
extern char lbl_88BC8E0C[];
extern char lbl_88BC9218[];
extern char lbl_88BC95CC[];
extern char lbl_88BCB1D0[];
extern char lbl_88BCB218[];
extern char lbl_88BCB290[];
extern char lbl_88BCB3C8[];
extern char lbl_88BCB470[];
extern char lbl_88BCB608[];
extern char lbl_88BCB6F8[];
extern char lbl_88BCB800[];
extern char lbl_88BCB9B0[];
extern char lbl_88BCBAD0[];
extern char lbl_88BCBB00[];
extern char lbl_88BCBBC0[];
extern char lbl_88BCBC98[];
extern char lbl_88BCBCC8[];
extern char lbl_88BCBCF8[];
extern char lbl_88BCBD28[];
extern char lbl_88BCBDA0[];
extern char lbl_88BCBDE8[];
extern char lbl_88BCBE60[];
extern char lbl_88BCBF20[];
extern char lbl_88BCBFF8[];
extern char lbl_88BCC0E8[];
extern char lbl_88BCC1C0[];
extern char lbl_88BCC328[];
extern char lbl_88BCC3D0[];
extern char lbl_88BCC508[];
extern char lbl_88BCC580[];
extern char lbl_88BCC628[];
extern char lbl_88BCC640[];
extern char lbl_88BCC6E8[];
extern char lbl_88BCC730[];
extern char lbl_88BCC808[];
extern char lbl_88BCC880[];
extern char lbl_88BCC898[];
extern char lbl_88BCC910[];
extern char lbl_88C6B4AC[];
extern char lbl_88CE375C[];
extern char lbl_88CE3C24[];
extern char lbl_88CE8304[];
extern char lbl_88CE882C[];
extern char lbl_88CED47C[];
extern char lbl_88CF2564[];
extern char lbl_88CF785C[];
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word fn_88563470();
ts4_word ts4_loop_get_u32_off8_889319A0();
ts4_word fn_88933EF8();
ts4_word fn_88936AF0();
ts4_word fn_88939040();
ts4_word fn_889393C0();
ts4_word ts4_if_call_seq_fn_88933EF8_889396A8();

/* Swing_DLL.xex 0x889330B0: if_get u8@0x5c, u8@0x5c, ts4_loop_get_u32_off8_889319A0 */
ts4_word ts4_if_get_u8_off5c_889330B0(ts4_word a0, ts4_word a1)
{
    unsigned char t2;

    if ((ts4_word)a1 == 0) {
        return a0;
    }
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 92);
    if ((ts4_word)t2 == 0) {
        return a0;
    }
    return ts4_loop_get_u32_off8_889319A0((ts4_word)(a0 + 72), (ts4_word)a1);
}

/* Swing_DLL.xex 0x88939B50: loop_call_seq u32@0x4, fn_88933EF8, fn_88936AF0, u32@0x8, fn_88933EF8, fn_88933EF8 */
ts4_word ts4_loop_call_seq_u32_off4_88939B50(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word p8;
    ts4_word lv10;
    ts4_word p12;
    ts4_word t1;
    ts4_word t2;
    int t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t21;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t2 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)(t1 & 0x1));
    }
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    t6 = fn_88933EF8((ts4_word)a1, (ts4_word)3);
    if ((ts4_word)(t6 & 0xff) != 0) {
        if ((int)t5 < 0) {
            p7 = (ts4_word)1;
            p8 = (ts4_word)(-(int)t5);
        } else {
            p7 = (ts4_word)0;
            p8 = (ts4_word)t5;
        }
        t9 = fn_88933EF8((ts4_word)a1, (ts4_word)3);
        if ((ts4_word)(t9 & 0xff) != 0) {
            lv10 = (ts4_word)0;
            do {
                fn_88936AF0((ts4_word)a1, (ts4_word)((p8 >> lv10) & 0x1));
                p12 = (ts4_word)(lv10 + 1);
                lv10 = p12;
            } while ((ts4_word)p12 < 3);
        }
        fn_88936AF0((ts4_word)a1, (ts4_word)p7);
    }
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 1036)));
    t21 = fn_88939040((ts4_word)a1, (ts4_word)(a0 + 12), (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 1036)));
    return t21;
}

/* Swing_DLL.xex 0x889B04B0: loop_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_loop_get_u32_off0_889B04B0(ts4_word a0, ts4_word a1)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word lv15;
    ts4_word p17;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;
    ts4_word t9;
    int t10;
    ts4_word t11;
    ts4_word t14;
    ts4_word t25;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    t9 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1072)));
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 1076);
    t11 = fn_88933EF8((ts4_word)t9, (ts4_word)2);
    if ((ts4_word)(t11 & 0xff) != 0) {
        if ((int)t10 < 0) {
            p12 = (ts4_word)1;
            p13 = (ts4_word)(-(int)t10);
        } else {
            p12 = (ts4_word)0;
            p13 = (ts4_word)t10;
        }
        t14 = fn_88933EF8((ts4_word)t9, (ts4_word)2);
        if ((ts4_word)(t14 & 0xff) != 0) {
            lv15 = (ts4_word)0;
            do {
                fn_88936AF0((ts4_word)t9, (ts4_word)((p13 >> lv15) & 0x1));
                p17 = (ts4_word)(lv15 + 1);
                lv15 = p17;
            } while ((ts4_word)p17 < 2);
        }
        fn_88936AF0((ts4_word)t9, (ts4_word)p12);
    }
    t25 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)t9, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1080)));
    return t25;
}

/* Swing_DLL.xex 0x88A52678: addr lbl_88B9BBA8, u32@lbl_88B97D68, u32@0x68 */
void ts4_addr_lbl_88B9BBA8_88A52678(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9BBA8) + 104) = (ts4_word)(*(ts4_word *)lbl_88B97D68);
    return;
}

/* Swing_DLL.xex 0x88A52780: addr lbl_88B9BC50, u32@lbl_88B97D68, u32@0xb0 */
void ts4_addr_lbl_88B9BC50_88A52780(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9BC50) + 176) = (ts4_word)(*(ts4_word *)lbl_88B97D68);
    return;
}

/* Swing_DLL.xex 0x88A52C98: addr lbl_88B9BD70, u32@lbl_88B97D68, u32@0x68 */
void ts4_addr_lbl_88B9BD70_88A52C98(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9BD70) + 104) = (ts4_word)(*(ts4_word *)lbl_88B97D68);
    return;
}

/* Swing_DLL.xex 0x88A53140: addr lbl_88B9BDE8, u32@lbl_88B97D68, u32@0x20 */
void ts4_addr_lbl_88B9BDE8_88A53140(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9BDE8) + 32) = (ts4_word)(*(ts4_word *)lbl_88B97D68);
    return;
}

/* Swing_DLL.xex 0x88A53328: addr lbl_88B9BE90, u32@lbl_88B97D74, u32@0x8 */
void ts4_addr_lbl_88B9BE90_88A53328(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9BE90) + 8) = (ts4_word)(*(ts4_word *)lbl_88B97D74);
    return;
}

/* Swing_DLL.xex 0x88A53AA0: addr lbl_88B9BEA8, u32@lbl_88B97E9C, u32@0x50 */
void ts4_addr_lbl_88B9BEA8_88A53AA0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9BEA8) + 80) = (ts4_word)(*(ts4_word *)lbl_88B97E9C);
    return;
}

/* Swing_DLL.xex 0x88A54228: addr lbl_88B9BF50, u32@lbl_88B984D0, u32@0x8 */
void ts4_addr_lbl_88B9BF50_88A54228(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9BF50) + 8) = (ts4_word)(*(ts4_word *)lbl_88B984D0);
    return;
}

/* Swing_DLL.xex 0x88A54400: addr lbl_88B9BF98, u32@lbl_88B98550, u32@0x68 */
void ts4_addr_lbl_88B9BF98_88A54400(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9BF98) + 104) = (ts4_word)(*(ts4_word *)lbl_88B98550);
    return;
}

/* Swing_DLL.xex 0x88A54828: addr lbl_88B9C070, u32@lbl_88B9860C, u32@0x50 */
void ts4_addr_lbl_88B9C070_88A54828(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9C070) + 80) = (ts4_word)(*(ts4_word *)lbl_88B9860C);
    return;
}

/* Swing_DLL.xex 0x88A55398: addr lbl_88B9C0E8, u32@lbl_88B98B44, u32@0x8 */
void ts4_addr_lbl_88B9C0E8_88A55398(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9C0E8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B98B44);
    return;
}

/* Swing_DLL.xex 0x88A55498: addr lbl_88B9C100, u32@lbl_88B98F50, u32@0x20 */
void ts4_addr_lbl_88B9C100_88A55498(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9C100) + 32) = (ts4_word)(*(ts4_word *)lbl_88B98F50);
    return;
}

/* Swing_DLL.xex 0x88A557E8: addr lbl_88B9C178, u32@lbl_88B98F54, u32@0x38 */
void ts4_addr_lbl_88B9C178_88A557E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9C178) + 56) = (ts4_word)(*(ts4_word *)lbl_88B98F54);
    return;
}

/* Swing_DLL.xex 0x88A55B70: addr lbl_88B9C1D8, u32@lbl_88B9928C, u32@0x8 */
void ts4_addr_lbl_88B9C1D8_88A55B70(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9C1D8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B9928C);
    return;
}

/* Swing_DLL.xex 0x88A56220: get u32@lbl_88B994C4, lbl_88B9C298, u32@lbl_88B994C0, u32@lbl_88B994BC, u32@0x50, u32@0x140 */
void ts4_get_u32_lbl_88B994C4_88A56220(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B994C4;
    t2 = *(ts4_word *)lbl_88B994C0;
    t3 = *(ts4_word *)lbl_88B994BC;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9C298) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9C298) + 320) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9C298) + 752) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x88A582C0: call_seq lbl_8805E7C8, lbl_8805FDA0, lbl_88CE375C, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF638, fn_88563470 */
ts4_word ts4_call_seq_lbl_8805E7C8_88A582C0(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CE375C, (ts4_word)(ts4_word)lbl_8805FDA0, (ts4_word)4, (ts4_word)(ts4_word)lbl_8805E7C8);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF638);
    return t2;
}

/* Swing_DLL.xex 0x88A58378: addr lbl_88BA37C8, u32@lbl_88B9C670, u32@0x38 */
void ts4_addr_lbl_88BA37C8_88A58378(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA37C8) + 56) = (ts4_word)(*(ts4_word *)lbl_88B9C670);
    return;
}

/* Swing_DLL.xex 0x88A584E0: addr lbl_88BA3810, u32@lbl_88B9C6D4, u32@0x8 */
void ts4_addr_lbl_88BA3810_88A584E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA3810) + 8) = (ts4_word)(*(ts4_word *)lbl_88B9C6D4);
    return;
}

/* Swing_DLL.xex 0x88A58C88: addr lbl_88BA3888, u32@lbl_88B9CAB4, u32@0x128 */
void ts4_addr_lbl_88BA3888_88A58C88(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA3888) + 296) = (ts4_word)(*(ts4_word *)lbl_88B9CAB4);
    return;
}

/* Swing_DLL.xex 0x88A58E80: call_seq lbl_88060834, lbl_88B9CEE0, lbl_88042110, lbl_88CE3C24, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88060834_88A58E80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CE3C24, (ts4_word)(ts4_word)lbl_88042110, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88060834, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B9CEE0, (ts4_word)14, (ts4_word)((ts4_word)lbl_88060834 + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A59218: addr lbl_88BA39C0, u32@lbl_88B9D270, u32@0x68 */
void ts4_addr_lbl_88BA39C0_88A59218(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA39C0) + 104) = (ts4_word)(*(ts4_word *)lbl_88B9D270);
    return;
}

/* Swing_DLL.xex 0x88A59390: addr lbl_88BA3A38, u32@lbl_88B9D368, u32@0x8 */
void ts4_addr_lbl_88BA3A38_88A59390(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA3A38) + 8) = (ts4_word)(*(ts4_word *)lbl_88B9D368);
    return;
}

/* Swing_DLL.xex 0x88A59498: addr lbl_88BA3BB8, u32@lbl_88B9D3A0, u32@0x68 */
void ts4_addr_lbl_88BA3BB8_88A59498(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA3BB8) + 104) = (ts4_word)(*(ts4_word *)lbl_88B9D3A0);
    return;
}

/* Swing_DLL.xex 0x88A59DC8: addr lbl_88BA3CA8, u32@lbl_88B9D3BC, u32@0x50 */
void ts4_addr_lbl_88BA3CA8_88A59DC8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA3CA8) + 80) = (ts4_word)(*(ts4_word *)lbl_88B9D3BC);
    return;
}

/* Swing_DLL.xex 0x88A5AB80: addr lbl_88BA3DB0, u32@lbl_88B9E6BC, u32@0x50 */
void ts4_addr_lbl_88BA3DB0_88A5AB80(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA3DB0) + 80) = (ts4_word)(*(ts4_word *)lbl_88B9E6BC);
    return;
}

/* Swing_DLL.xex 0x88A5AC80: addr lbl_88BA3ED0, u32@lbl_88B9E6D8, u32@0x20 */
void ts4_addr_lbl_88BA3ED0_88A5AC80(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA3ED0) + 32) = (ts4_word)(*(ts4_word *)lbl_88B9E6D8);
    return;
}

/* Swing_DLL.xex 0x88A5B168: addr lbl_88BA3F00, u32@lbl_88B9E834, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88BA3F00_88A5B168(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B9E834;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA3F00) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA3F00) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A5B348: addr lbl_88BA3FC0, u32@lbl_88B9E9C0, u32@0x50 */
void ts4_addr_lbl_88BA3FC0_88A5B348(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA3FC0) + 80) = (ts4_word)(*(ts4_word *)lbl_88B9E9C0);
    return;
}

/* Swing_DLL.xex 0x88A5B6E0: addr lbl_88BA4098, u32@lbl_88B9EC88, u32@0x20 */
void ts4_addr_lbl_88BA4098_88A5B6E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4098) + 32) = (ts4_word)(*(ts4_word *)lbl_88B9EC88);
    return;
}

/* Swing_DLL.xex 0x88A5B768: addr lbl_88BA40C8, u32@lbl_88B9EC88, u32@0x20 */
void ts4_addr_lbl_88BA40C8_88A5B768(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA40C8) + 32) = (ts4_word)(*(ts4_word *)lbl_88B9EC88);
    return;
}

/* Swing_DLL.xex 0x88A5B860: addr lbl_88BA40F8, u32@lbl_88B9EC88, u32@0x20 */
void ts4_addr_lbl_88BA40F8_88A5B860(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA40F8) + 32) = (ts4_word)(*(ts4_word *)lbl_88B9EC88);
    return;
}

/* Swing_DLL.xex 0x88A5BEA8: addr lbl_88BA4128, u32@lbl_88B9EDC4, u32@0x8 */
void ts4_addr_lbl_88BA4128_88A5BEA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4128) + 8) = (ts4_word)(*(ts4_word *)lbl_88B9EDC4);
    return;
}

/* Swing_DLL.xex 0x88A5C018: addr lbl_88BA41A0, u32@lbl_88B9EFC4, u32@0x20 */
void ts4_addr_lbl_88BA41A0_88A5C018(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA41A0) + 32) = (ts4_word)(*(ts4_word *)lbl_88B9EFC4);
    return;
}

/* Swing_DLL.xex 0x88A5C180: addr lbl_88BA41E8, u32@lbl_88B9F0D0, u32@0x8 */
void ts4_addr_lbl_88BA41E8_88A5C180(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA41E8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B9F0D0);
    return;
}

/* Swing_DLL.xex 0x88A5CF30: addr lbl_88BA4260, u32@lbl_88B9FCA8, u32@0x8 */
void ts4_addr_lbl_88BA4260_88A5CF30(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4260) + 8) = (ts4_word)(*(ts4_word *)lbl_88B9FCA8);
    return;
}

/* Swing_DLL.xex 0x88A5DA60: addr lbl_88BA4290, u32@lbl_88BA0114, u32@lbl_88BA007C, u32@0x8, u32@0x20 */
void ts4_addr_lbl_88BA4290_88A5DA60(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88BA0114;
    t2 = *(ts4_word *)lbl_88BA007C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4290) + 8) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4290) + 32) = (ts4_word)t2;
    return;
}

/* Swing_DLL.xex 0x88A5DAF8: addr lbl_88BA4338, u32@lbl_88BA007C, u32@0x80 */
void ts4_addr_lbl_88BA4338_88A5DAF8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4338) + 128) = (ts4_word)(*(ts4_word *)lbl_88BA007C);
    return;
}

/* Swing_DLL.xex 0x88A5DC00: addr lbl_88BA43F8, u32@lbl_88BA07C8, u32@0x80 */
void ts4_addr_lbl_88BA43F8_88A5DC00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA43F8) + 128) = (ts4_word)(*(ts4_word *)lbl_88BA07C8);
    return;
}

/* Swing_DLL.xex 0x88A5DEB8: addr lbl_88BA44A0, u32@lbl_88BA0238, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88BA44A0_88A5DEB8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BA0238;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA44A0) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA44A0) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A5DF50: addr lbl_88BA45F0, u32@lbl_88BA07C8, u32@0x68 */
void ts4_addr_lbl_88BA45F0_88A5DF50(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA45F0) + 104) = (ts4_word)(*(ts4_word *)lbl_88BA07C8);
    return;
}

/* Swing_DLL.xex 0x88A5E058: addr lbl_88BA4698, u32@lbl_88BA07C8, u32@0xc8 */
void ts4_addr_lbl_88BA4698_88A5E058(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4698) + 200) = (ts4_word)(*(ts4_word *)lbl_88BA07C8);
    return;
}

/* Swing_DLL.xex 0x88A5E570: addr lbl_88BA47D0, u32@lbl_88BA07C8, u32@0x68 */
void ts4_addr_lbl_88BA47D0_88A5E570(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA47D0) + 104) = (ts4_word)(*(ts4_word *)lbl_88BA07C8);
    return;
}

/* Swing_DLL.xex 0x88A5EA18: addr lbl_88BA4848, u32@lbl_88BA07C8, u32@0x20 */
void ts4_addr_lbl_88BA4848_88A5EA18(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4848) + 32) = (ts4_word)(*(ts4_word *)lbl_88BA07C8);
    return;
}

/* Swing_DLL.xex 0x88A5EC00: addr lbl_88BA48F0, u32@lbl_88BA07D4, u32@0x8 */
void ts4_addr_lbl_88BA48F0_88A5EC00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA48F0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BA07D4);
    return;
}

/* Swing_DLL.xex 0x88A5F378: addr lbl_88BA4908, u32@lbl_88BA08FC, u32@0x50 */
void ts4_addr_lbl_88BA4908_88A5F378(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4908) + 80) = (ts4_word)(*(ts4_word *)lbl_88BA08FC);
    return;
}

/* Swing_DLL.xex 0x88A5FB00: addr lbl_88BA49B0, u32@lbl_88BA0F30, u32@0x8 */
void ts4_addr_lbl_88BA49B0_88A5FB00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA49B0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BA0F30);
    return;
}

/* Swing_DLL.xex 0x88A5FCD8: addr lbl_88BA49F8, u32@lbl_88BA0FB0, u32@0x68 */
void ts4_addr_lbl_88BA49F8_88A5FCD8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA49F8) + 104) = (ts4_word)(*(ts4_word *)lbl_88BA0FB0);
    return;
}

/* Swing_DLL.xex 0x88A60100: addr lbl_88BA4AD0, u32@lbl_88BA106C, u32@0x50 */
void ts4_addr_lbl_88BA4AD0_88A60100(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4AD0) + 80) = (ts4_word)(*(ts4_word *)lbl_88BA106C);
    return;
}

/* Swing_DLL.xex 0x88A60C70: addr lbl_88BA4B48, u32@lbl_88BA15A4, u32@0x8 */
void ts4_addr_lbl_88BA4B48_88A60C70(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4B48) + 8) = (ts4_word)(*(ts4_word *)lbl_88BA15A4);
    return;
}

/* Swing_DLL.xex 0x88A60D70: addr lbl_88BA4B60, u32@lbl_88BA19B0, u32@0x20 */
void ts4_addr_lbl_88BA4B60_88A60D70(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4B60) + 32) = (ts4_word)(*(ts4_word *)lbl_88BA19B0);
    return;
}

/* Swing_DLL.xex 0x88A610C0: addr lbl_88BA4BD8, u32@lbl_88BA19B4, u32@0x38 */
void ts4_addr_lbl_88BA4BD8_88A610C0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4BD8) + 56) = (ts4_word)(*(ts4_word *)lbl_88BA19B4);
    return;
}

/* Swing_DLL.xex 0x88A61448: addr lbl_88BA4C38, u32@lbl_88BA1CEC, u32@0x8 */
void ts4_addr_lbl_88BA4C38_88A61448(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4C38) + 8) = (ts4_word)(*(ts4_word *)lbl_88BA1CEC);
    return;
}

/* Swing_DLL.xex 0x88A61AF8: get u32@lbl_88BA1F24, lbl_88BA4CF8, u32@lbl_88BA1F20, u32@lbl_88BA1F1C, u32@0x50, u32@0x140 */
void ts4_get_u32_lbl_88BA1F24_88A61AF8(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88BA1F24;
    t2 = *(ts4_word *)lbl_88BA1F20;
    t3 = *(ts4_word *)lbl_88BA1F1C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4CF8) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4CF8) + 320) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BA4CF8) + 824) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x88A63B98: call_seq lbl_88060748, lbl_88061D40, lbl_88CE8304, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF650, fn_88563470 */
ts4_word ts4_call_seq_lbl_88060748_88A63B98(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CE8304, (ts4_word)(ts4_word)lbl_88061D40, (ts4_word)4, (ts4_word)(ts4_word)lbl_88060748);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF650);
    return t2;
}

/* Swing_DLL.xex 0x88A63C50: addr lbl_88BAD2E0, u32@lbl_88BA5118, u32@0x38 */
void ts4_addr_lbl_88BAD2E0_88A63C50(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAD2E0) + 56) = (ts4_word)(*(ts4_word *)lbl_88BA5118);
    return;
}

/* Swing_DLL.xex 0x88A63DB8: addr lbl_88BAD328, u32@lbl_88BA517C, u32@0x8 */
void ts4_addr_lbl_88BAD328_88A63DB8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAD328) + 8) = (ts4_word)(*(ts4_word *)lbl_88BA517C);
    return;
}

/* Swing_DLL.xex 0x88A64560: addr lbl_88BAD3A0, u32@lbl_88BA555C, u32@0x128 */
void ts4_addr_lbl_88BAD3A0_88A64560(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAD3A0) + 296) = (ts4_word)(*(ts4_word *)lbl_88BA555C);
    return;
}

/* Swing_DLL.xex 0x88A64838: call_seq lbl_8806301C, lbl_88BA5A60, lbl_88042110, lbl_88CE882C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8806301C_88A64838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CE882C, (ts4_word)(ts4_word)lbl_88042110, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8806301C, (ts4_word)1, (ts4_word)(ts4_word)lbl_88BA5A60, (ts4_word)14, (ts4_word)((ts4_word)lbl_8806301C + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A64D98: addr lbl_88BAD4D8, u32@lbl_88BA5E3C, u32@0x68 */
void ts4_addr_lbl_88BAD4D8_88A64D98(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAD4D8) + 104) = (ts4_word)(*(ts4_word *)lbl_88BA5E3C);
    return;
}

/* Swing_DLL.xex 0x88A64F10: addr lbl_88BAD550, u32@lbl_88BA5F94, u32@0x8 */
void ts4_addr_lbl_88BAD550_88A64F10(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAD550) + 8) = (ts4_word)(*(ts4_word *)lbl_88BA5F94);
    return;
}

/* Swing_DLL.xex 0x88A65018: addr lbl_88BAD6D0, u32@lbl_88BA60BC, u32@0x68 */
void ts4_addr_lbl_88BAD6D0_88A65018(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAD6D0) + 104) = (ts4_word)(*(ts4_word *)lbl_88BA60BC);
    return;
}

/* Swing_DLL.xex 0x88A659B8: addr lbl_88BAD7C0, u32@lbl_88BA6978, u32@0x50 */
void ts4_addr_lbl_88BAD7C0_88A659B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAD7C0) + 80) = (ts4_word)(*(ts4_word *)lbl_88BA6978);
    return;
}

/* Swing_DLL.xex 0x88A667E0: addr lbl_88BAD8C8, u32@lbl_88BA74E0, u32@0x50 */
void ts4_addr_lbl_88BAD8C8_88A667E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAD8C8) + 80) = (ts4_word)(*(ts4_word *)lbl_88BA74E0);
    return;
}

/* Swing_DLL.xex 0x88A66AB0: addr lbl_88BAD9E8, u32@lbl_88BA74E4, u32@0x20 */
void ts4_addr_lbl_88BAD9E8_88A66AB0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAD9E8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BA74E4);
    return;
}

/* Swing_DLL.xex 0x88A66F98: addr lbl_88BADA18, u32@lbl_88BA7AC0, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88BADA18_88A66F98(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BA7AC0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BADA18) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BADA18) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A67178: addr lbl_88BADAD8, u32@lbl_88BA7B44, u32@0x50 */
void ts4_addr_lbl_88BADAD8_88A67178(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BADAD8) + 80) = (ts4_word)(*(ts4_word *)lbl_88BA7B44);
    return;
}

/* Swing_DLL.xex 0x88A67510: addr lbl_88BADBB0, u32@lbl_88BA7BFC, u32@0x20 */
void ts4_addr_lbl_88BADBB0_88A67510(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BADBB0) + 32) = (ts4_word)(*(ts4_word *)lbl_88BA7BFC);
    return;
}

/* Swing_DLL.xex 0x88A67598: addr lbl_88BADBE0, u32@lbl_88BA7BFC, u32@0x20 */
void ts4_addr_lbl_88BADBE0_88A67598(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BADBE0) + 32) = (ts4_word)(*(ts4_word *)lbl_88BA7BFC);
    return;
}

/* Swing_DLL.xex 0x88A67690: addr lbl_88BADC10, u32@lbl_88BA7BFC, u32@0x20 */
void ts4_addr_lbl_88BADC10_88A67690(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BADC10) + 32) = (ts4_word)(*(ts4_word *)lbl_88BA7BFC);
    return;
}

/* Swing_DLL.xex 0x88A67CD8: addr lbl_88BADC40, u32@lbl_88BA8110, u32@0x8 */
void ts4_addr_lbl_88BADC40_88A67CD8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BADC40) + 8) = (ts4_word)(*(ts4_word *)lbl_88BA8110);
    return;
}

/* Swing_DLL.xex 0x88A67E48: addr lbl_88BADCB8, u32@lbl_88BA8208, u32@0x20 */
void ts4_addr_lbl_88BADCB8_88A67E48(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BADCB8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BA8208);
    return;
}

/* Swing_DLL.xex 0x88A67FB0: addr lbl_88BADD00, u32@lbl_88BA8254, u32@0x8 */
void ts4_addr_lbl_88BADD00_88A67FB0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BADD00) + 8) = (ts4_word)(*(ts4_word *)lbl_88BA8254);
    return;
}

/* Swing_DLL.xex 0x88A68C28: addr lbl_88BADD78, u32@lbl_88BA9218, u32@0x68 */
void ts4_addr_lbl_88BADD78_88A68C28(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BADD78) + 104) = (ts4_word)(*(ts4_word *)lbl_88BA9218);
    return;
}

/* Swing_DLL.xex 0x88A695F8: addr lbl_88BADE38, u32@lbl_88BA9760, u32@0x8 */
void ts4_addr_lbl_88BADE38_88A695F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BADE38) + 8) = (ts4_word)(*(ts4_word *)lbl_88BA9760);
    return;
}

/* Swing_DLL.xex 0x88A6A1C0: addr lbl_88BADF10, u32@lbl_88BA9B34, u32@0x80 */
void ts4_addr_lbl_88BADF10_88A6A1C0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BADF10) + 128) = (ts4_word)(*(ts4_word *)lbl_88BA9B34);
    return;
}

/* Swing_DLL.xex 0x88A6A2C8: addr lbl_88BADFD0, u32@lbl_88BAA280, u32@0x80 */
void ts4_addr_lbl_88BADFD0_88A6A2C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BADFD0) + 128) = (ts4_word)(*(ts4_word *)lbl_88BAA280);
    return;
}

/* Swing_DLL.xex 0x88A6A580: addr lbl_88BAE078, u32@lbl_88BA9CF0, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88BAE078_88A6A580(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BA9CF0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE078) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE078) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A6A618: addr lbl_88BAE1C8, u32@lbl_88BAA280, u32@0x68 */
void ts4_addr_lbl_88BAE1C8_88A6A618(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE1C8) + 104) = (ts4_word)(*(ts4_word *)lbl_88BAA280);
    return;
}

/* Swing_DLL.xex 0x88A6A720: addr lbl_88BAE270, u32@lbl_88BAA280, u32@0xc8 */
void ts4_addr_lbl_88BAE270_88A6A720(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE270) + 200) = (ts4_word)(*(ts4_word *)lbl_88BAA280);
    return;
}

/* Swing_DLL.xex 0x88A6AC38: addr lbl_88BAE3A8, u32@lbl_88BAA280, u32@0x68 */
void ts4_addr_lbl_88BAE3A8_88A6AC38(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE3A8) + 104) = (ts4_word)(*(ts4_word *)lbl_88BAA280);
    return;
}

/* Swing_DLL.xex 0x88A6B0E0: addr lbl_88BAE420, u32@lbl_88BAA280, u32@0x20 */
void ts4_addr_lbl_88BAE420_88A6B0E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE420) + 32) = (ts4_word)(*(ts4_word *)lbl_88BAA280);
    return;
}

/* Swing_DLL.xex 0x88A6B2C8: addr lbl_88BAE4C8, u32@lbl_88BAA28C, u32@0x8 */
void ts4_addr_lbl_88BAE4C8_88A6B2C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE4C8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BAA28C);
    return;
}

/* Swing_DLL.xex 0x88A6BA40: addr lbl_88BAE4E0, u32@lbl_88BAA3B4, u32@0x50 */
void ts4_addr_lbl_88BAE4E0_88A6BA40(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE4E0) + 80) = (ts4_word)(*(ts4_word *)lbl_88BAA3B4);
    return;
}

/* Swing_DLL.xex 0x88A6C1C8: addr lbl_88BAE588, u32@lbl_88BAA9E8, u32@0x8 */
void ts4_addr_lbl_88BAE588_88A6C1C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE588) + 8) = (ts4_word)(*(ts4_word *)lbl_88BAA9E8);
    return;
}

/* Swing_DLL.xex 0x88A6C3A0: addr lbl_88BAE5D0, u32@lbl_88BAAA68, u32@0x68 */
void ts4_addr_lbl_88BAE5D0_88A6C3A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE5D0) + 104) = (ts4_word)(*(ts4_word *)lbl_88BAAA68);
    return;
}

/* Swing_DLL.xex 0x88A6C7C8: addr lbl_88BAE6A8, u32@lbl_88BAAB24, u32@0x50 */
void ts4_addr_lbl_88BAE6A8_88A6C7C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE6A8) + 80) = (ts4_word)(*(ts4_word *)lbl_88BAAB24);
    return;
}

/* Swing_DLL.xex 0x88A6D338: addr lbl_88BAE720, u32@lbl_88BAB05C, u32@0x8 */
void ts4_addr_lbl_88BAE720_88A6D338(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE720) + 8) = (ts4_word)(*(ts4_word *)lbl_88BAB05C);
    return;
}

/* Swing_DLL.xex 0x88A6D438: addr lbl_88BAE738, u32@lbl_88BAB468, u32@0x20 */
void ts4_addr_lbl_88BAE738_88A6D438(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE738) + 32) = (ts4_word)(*(ts4_word *)lbl_88BAB468);
    return;
}

/* Swing_DLL.xex 0x88A6DAF8: addr lbl_88BAE7B0, u32@lbl_88BAB804, u32@0x8 */
void ts4_addr_lbl_88BAE7B0_88A6DAF8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BAE7B0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BAB804);
    return;
}

/* Swing_DLL.xex 0x88A70248: call_seq lbl_88062F30, lbl_880645E0, lbl_88CED47C, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF668, fn_88563470 */
ts4_word ts4_call_seq_lbl_88062F30_88A70248(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CED47C, (ts4_word)(ts4_word)lbl_880645E0, (ts4_word)4, (ts4_word)(ts4_word)lbl_88062F30);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF668);
    return t2;
}

/* Swing_DLL.xex 0x88A70300: addr lbl_88BB6D58, u32@lbl_88BAECA8, u32@0x38 */
void ts4_addr_lbl_88BB6D58_88A70300(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB6D58) + 56) = (ts4_word)(*(ts4_word *)lbl_88BAECA8);
    return;
}

/* Swing_DLL.xex 0x88A70468: addr lbl_88BB6DA0, u32@lbl_88BAED0C, u32@0x8 */
void ts4_addr_lbl_88BB6DA0_88A70468(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB6DA0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BAED0C);
    return;
}

/* Swing_DLL.xex 0x88A70C10: addr lbl_88BB6E18, u32@lbl_88BAF0EC, u32@0x128 */
void ts4_addr_lbl_88BB6E18_88A70C10(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB6E18) + 296) = (ts4_word)(*(ts4_word *)lbl_88BAF0EC);
    return;
}

/* Swing_DLL.xex 0x88A71448: addr lbl_88BB6F50, u32@lbl_88BAFA2C, u32@0x68 */
void ts4_addr_lbl_88BB6F50_88A71448(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB6F50) + 104) = (ts4_word)(*(ts4_word *)lbl_88BAFA2C);
    return;
}

/* Swing_DLL.xex 0x88A715C0: addr lbl_88BB6FC8, u32@lbl_88BAFB84, u32@0x8 */
void ts4_addr_lbl_88BB6FC8_88A715C0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB6FC8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BAFB84);
    return;
}

/* Swing_DLL.xex 0x88A716C8: addr lbl_88BB7160, u32@lbl_88BAFCC4, u32@0x68 */
void ts4_addr_lbl_88BB7160_88A716C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7160) + 104) = (ts4_word)(*(ts4_word *)lbl_88BAFCC4);
    return;
}

/* Swing_DLL.xex 0x88A72068: addr lbl_88BB7250, u32@lbl_88BB0580, u32@0x50 */
void ts4_addr_lbl_88BB7250_88A72068(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7250) + 80) = (ts4_word)(*(ts4_word *)lbl_88BB0580);
    return;
}

/* Swing_DLL.xex 0x88A72DB0: addr lbl_88BB7358, u32@lbl_88BB0DB0, u32@0x98 */
void ts4_addr_lbl_88BB7358_88A72DB0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7358) + 152) = (ts4_word)(*(ts4_word *)lbl_88BB0DB0);
    return;
}

/* Swing_DLL.xex 0x88A72EA8: addr lbl_88BB7508, u32@lbl_88BB0FB4, u32@0x50 */
void ts4_addr_lbl_88BB7508_88A72EA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7508) + 80) = (ts4_word)(*(ts4_word *)lbl_88BB0FB4);
    return;
}

/* Swing_DLL.xex 0x88A73178: addr lbl_88BB7628, u32@lbl_88BB1330, u32@0x20 */
void ts4_addr_lbl_88BB7628_88A73178(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7628) + 32) = (ts4_word)(*(ts4_word *)lbl_88BB1330);
    return;
}

/* Swing_DLL.xex 0x88A73660: addr lbl_88BB7658, u32@lbl_88BB148C, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88BB7658_88A73660(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BB148C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7658) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7658) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A73840: addr lbl_88BB7718, u32@lbl_88BB1618, u32@0x50 */
void ts4_addr_lbl_88BB7718_88A73840(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7718) + 80) = (ts4_word)(*(ts4_word *)lbl_88BB1618);
    return;
}

/* Swing_DLL.xex 0x88A73BD8: addr lbl_88BB77F0, u32@lbl_88BB18E0, u32@0x20 */
void ts4_addr_lbl_88BB77F0_88A73BD8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB77F0) + 32) = (ts4_word)(*(ts4_word *)lbl_88BB18E0);
    return;
}

/* Swing_DLL.xex 0x88A73C60: addr lbl_88BB7820, u32@lbl_88BB18E0, u32@0x20 */
void ts4_addr_lbl_88BB7820_88A73C60(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7820) + 32) = (ts4_word)(*(ts4_word *)lbl_88BB18E0);
    return;
}

/* Swing_DLL.xex 0x88A73D58: addr lbl_88BB7850, u32@lbl_88BB18E0, u32@0x20 */
void ts4_addr_lbl_88BB7850_88A73D58(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7850) + 32) = (ts4_word)(*(ts4_word *)lbl_88BB18E0);
    return;
}

/* Swing_DLL.xex 0x88A743A0: addr lbl_88BB7880, u32@lbl_88BB1A1C, u32@0x8 */
void ts4_addr_lbl_88BB7880_88A743A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7880) + 8) = (ts4_word)(*(ts4_word *)lbl_88BB1A1C);
    return;
}

/* Swing_DLL.xex 0x88A74510: addr lbl_88BB78F8, u32@lbl_88BB1C1C, u32@0x20 */
void ts4_addr_lbl_88BB78F8_88A74510(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB78F8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BB1C1C);
    return;
}

/* Swing_DLL.xex 0x88A74678: addr lbl_88BB7940, u32@lbl_88BB1D28, u32@0x8 */
void ts4_addr_lbl_88BB7940_88A74678(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7940) + 8) = (ts4_word)(*(ts4_word *)lbl_88BB1D28);
    return;
}

/* Swing_DLL.xex 0x88A75210: addr lbl_88BB79B8, u32@lbl_88BB1D8C, u32@0x68 */
void ts4_addr_lbl_88BB79B8_88A75210(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB79B8) + 104) = (ts4_word)(*(ts4_word *)lbl_88BB1D8C);
    return;
}

/* Swing_DLL.xex 0x88A75BE0: addr lbl_88BB7A78, u32@lbl_88BB30FC, u32@0x8 */
void ts4_addr_lbl_88BB7A78_88A75BE0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7A78) + 8) = (ts4_word)(*(ts4_word *)lbl_88BB30FC);
    return;
}

/* Swing_DLL.xex 0x88A767A8: addr lbl_88BB7B50, u32@lbl_88BB3638, u32@0x80 */
void ts4_addr_lbl_88BB7B50_88A767A8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7B50) + 128) = (ts4_word)(*(ts4_word *)lbl_88BB3638);
    return;
}

/* Swing_DLL.xex 0x88A768B0: addr lbl_88BB7C10, u32@lbl_88BB385C, u32@0x80 */
void ts4_addr_lbl_88BB7C10_88A768B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7C10) + 128) = (ts4_word)(*(ts4_word *)lbl_88BB385C);
    return;
}

/* Swing_DLL.xex 0x88A76B68: addr lbl_88BB7CB8, u32@lbl_88BB3644, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88BB7CB8_88A76B68(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BB3644;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7CB8) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7CB8) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A76C00: addr lbl_88BB7E08, u32@lbl_88BB385C, u32@0x68 */
void ts4_addr_lbl_88BB7E08_88A76C00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7E08) + 104) = (ts4_word)(*(ts4_word *)lbl_88BB385C);
    return;
}

/* Swing_DLL.xex 0x88A76D08: addr lbl_88BB7EB0, u32@lbl_88BB385C, u32@0xc8 */
void ts4_addr_lbl_88BB7EB0_88A76D08(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7EB0) + 200) = (ts4_word)(*(ts4_word *)lbl_88BB385C);
    return;
}

/* Swing_DLL.xex 0x88A77220: addr lbl_88BB7FE8, u32@lbl_88BB385C, u32@0x68 */
void ts4_addr_lbl_88BB7FE8_88A77220(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB7FE8) + 104) = (ts4_word)(*(ts4_word *)lbl_88BB385C);
    return;
}

/* Swing_DLL.xex 0x88A776C8: addr lbl_88BB8060, u32@lbl_88BB385C, u32@0x20 */
void ts4_addr_lbl_88BB8060_88A776C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB8060) + 32) = (ts4_word)(*(ts4_word *)lbl_88BB385C);
    return;
}

/* Swing_DLL.xex 0x88A778B0: addr lbl_88BB8108, u32@lbl_88BB3D00, u32@0x8 */
void ts4_addr_lbl_88BB8108_88A778B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB8108) + 8) = (ts4_word)(*(ts4_word *)lbl_88BB3D00);
    return;
}

/* Swing_DLL.xex 0x88A78028: addr lbl_88BB8120, u32@lbl_88BB4008, u32@0x50 */
void ts4_addr_lbl_88BB8120_88A78028(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB8120) + 80) = (ts4_word)(*(ts4_word *)lbl_88BB4008);
    return;
}

/* Swing_DLL.xex 0x88A787B0: addr lbl_88BB81C8, u32@lbl_88BB400C, u32@0x8 */
void ts4_addr_lbl_88BB81C8_88A787B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB81C8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BB400C);
    return;
}

/* Swing_DLL.xex 0x88A78988: addr lbl_88BB8210, u32@lbl_88BB44DC, u32@0x68 */
void ts4_addr_lbl_88BB8210_88A78988(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB8210) + 104) = (ts4_word)(*(ts4_word *)lbl_88BB44DC);
    return;
}

/* Swing_DLL.xex 0x88A78DB0: addr lbl_88BB82E8, u32@lbl_88BB46B8, u32@0x50 */
void ts4_addr_lbl_88BB82E8_88A78DB0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB82E8) + 80) = (ts4_word)(*(ts4_word *)lbl_88BB46B8);
    return;
}

/* Swing_DLL.xex 0x88A79920: addr lbl_88BB8360, u32@lbl_88BB4EA8, u32@0x8 */
void ts4_addr_lbl_88BB8360_88A79920(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB8360) + 8) = (ts4_word)(*(ts4_word *)lbl_88BB4EA8);
    return;
}

/* Swing_DLL.xex 0x88A79A20: addr lbl_88BB8378, u32@lbl_88BB4EDC, u32@0x20 */
void ts4_addr_lbl_88BB8378_88A79A20(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB8378) + 32) = (ts4_word)(*(ts4_word *)lbl_88BB4EDC);
    return;
}

/* Swing_DLL.xex 0x88A7A0E0: addr lbl_88BB83F0, u32@lbl_88BB5320, u32@0x8 */
void ts4_addr_lbl_88BB83F0_88A7A0E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BB83F0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BB5320);
    return;
}

/* Swing_DLL.xex 0x88A7C7D0: call_seq lbl_88064E78, lbl_88066590, lbl_88CF2564, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF680, fn_88563470 */
ts4_word ts4_call_seq_lbl_88064E78_88A7C7D0(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CF2564, (ts4_word)(ts4_word)lbl_88066590, (ts4_word)4, (ts4_word)(ts4_word)lbl_88064E78);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF680);
    return t2;
}

/* Swing_DLL.xex 0x88A7C888: addr lbl_88BC0E98, u32@lbl_88BB88E8, u32@0x38 */
void ts4_addr_lbl_88BC0E98_88A7C888(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC0E98) + 56) = (ts4_word)(*(ts4_word *)lbl_88BB88E8);
    return;
}

/* Swing_DLL.xex 0x88A7C9F0: addr lbl_88BC0EE0, u32@lbl_88BB894C, u32@0x8 */
void ts4_addr_lbl_88BC0EE0_88A7C9F0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC0EE0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BB894C);
    return;
}

/* Swing_DLL.xex 0x88A7D198: addr lbl_88BC0F58, u32@lbl_88BB8D2C, u32@0x128 */
void ts4_addr_lbl_88BC0F58_88A7D198(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC0F58) + 296) = (ts4_word)(*(ts4_word *)lbl_88BB8D2C);
    return;
}

/* Swing_DLL.xex 0x88A7D9D0: addr lbl_88BC1090, u32@lbl_88BB9684, u32@0x68 */
void ts4_addr_lbl_88BC1090_88A7D9D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1090) + 104) = (ts4_word)(*(ts4_word *)lbl_88BB9684);
    return;
}

/* Swing_DLL.xex 0x88A7DB48: addr lbl_88BC1138, u32@lbl_88BB97DC, u32@0x8 */
void ts4_addr_lbl_88BC1138_88A7DB48(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1138) + 8) = (ts4_word)(*(ts4_word *)lbl_88BB97DC);
    return;
}

/* Swing_DLL.xex 0x88A7DC50: addr lbl_88BC12D0, u32@lbl_88BB994C, u32@0x68 */
void ts4_addr_lbl_88BC12D0_88A7DC50(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC12D0) + 104) = (ts4_word)(*(ts4_word *)lbl_88BB994C);
    return;
}

/* Swing_DLL.xex 0x88A7E5F8: addr lbl_88BC13C0, u32@lbl_88BBA1D8, u32@0x50 */
void ts4_addr_lbl_88BC13C0_88A7E5F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC13C0) + 80) = (ts4_word)(*(ts4_word *)lbl_88BBA1D8);
    return;
}

/* Swing_DLL.xex 0x88A7F340: addr lbl_88BC14C8, u32@lbl_88BBAA20, u32@0x98 */
void ts4_addr_lbl_88BC14C8_88A7F340(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC14C8) + 152) = (ts4_word)(*(ts4_word *)lbl_88BBAA20);
    return;
}

/* Swing_DLL.xex 0x88A7F438: addr lbl_88BC1678, u32@lbl_88BBAC24, u32@0x50 */
void ts4_addr_lbl_88BC1678_88A7F438(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1678) + 80) = (ts4_word)(*(ts4_word *)lbl_88BBAC24);
    return;
}

/* Swing_DLL.xex 0x88A7F780: addr lbl_88BC1798, u32@lbl_88BBB090, u32@0x20 */
void ts4_addr_lbl_88BC1798_88A7F780(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1798) + 32) = (ts4_word)(*(ts4_word *)lbl_88BBB090);
    return;
}

/* Swing_DLL.xex 0x88A7FC70: addr lbl_88BC17C8, u32@lbl_88BBB21C, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88BC17C8_88A7FC70(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BBB21C;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC17C8) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC17C8) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A7FE50: addr lbl_88BC1888, u32@lbl_88BBB3A8, u32@0x50 */
void ts4_addr_lbl_88BC1888_88A7FE50(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1888) + 80) = (ts4_word)(*(ts4_word *)lbl_88BBB3A8);
    return;
}

/* Swing_DLL.xex 0x88A801E8: addr lbl_88BC1960, u32@lbl_88BBB688, u32@0x20 */
void ts4_addr_lbl_88BC1960_88A801E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1960) + 32) = (ts4_word)(*(ts4_word *)lbl_88BBB688);
    return;
}

/* Swing_DLL.xex 0x88A80270: addr lbl_88BC1990, u32@lbl_88BBB688, u32@0x20 */
void ts4_addr_lbl_88BC1990_88A80270(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1990) + 32) = (ts4_word)(*(ts4_word *)lbl_88BBB688);
    return;
}

/* Swing_DLL.xex 0x88A80368: addr lbl_88BC19C0, u32@lbl_88BBB688, u32@0x20 */
void ts4_addr_lbl_88BC19C0_88A80368(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC19C0) + 32) = (ts4_word)(*(ts4_word *)lbl_88BBB688);
    return;
}

/* Swing_DLL.xex 0x88A809B0: addr lbl_88BC19F0, u32@lbl_88BBB7C4, u32@0x8 */
void ts4_addr_lbl_88BC19F0_88A809B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC19F0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BBB7C4);
    return;
}

/* Swing_DLL.xex 0x88A80B20: addr lbl_88BC1A68, u32@lbl_88BBB9C4, u32@0x20 */
void ts4_addr_lbl_88BC1A68_88A80B20(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1A68) + 32) = (ts4_word)(*(ts4_word *)lbl_88BBB9C4);
    return;
}

/* Swing_DLL.xex 0x88A80C88: addr lbl_88BC1AB0, u32@lbl_88BBBAD0, u32@0x8 */
void ts4_addr_lbl_88BC1AB0_88A80C88(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1AB0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BBBAD0);
    return;
}

/* Swing_DLL.xex 0x88A81820: addr lbl_88BC1B28, u32@lbl_88BBBB34, u32@0x68 */
void ts4_addr_lbl_88BC1B28_88A81820(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1B28) + 104) = (ts4_word)(*(ts4_word *)lbl_88BBBB34);
    return;
}

/* Swing_DLL.xex 0x88A82260: addr lbl_88BC1BE8, u32@lbl_88BBCF64, u32@0x8 */
void ts4_addr_lbl_88BC1BE8_88A82260(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1BE8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BBCF64);
    return;
}

/* Swing_DLL.xex 0x88A82E28: addr lbl_88BC1CC0, u32@lbl_88BBD4A0, u32@0x80 */
void ts4_addr_lbl_88BC1CC0_88A82E28(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1CC0) + 128) = (ts4_word)(*(ts4_word *)lbl_88BBD4A0);
    return;
}

/* Swing_DLL.xex 0x88A82F30: addr lbl_88BC1DB0, u32@lbl_88BBD604, u32@0xb0 */
void ts4_addr_lbl_88BC1DB0_88A82F30(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1DB0) + 176) = (ts4_word)(*(ts4_word *)lbl_88BBD604);
    return;
}

/* Swing_DLL.xex 0x88A831E8: addr lbl_88BC1E88, u32@lbl_88BBD4AC, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88BC1E88_88A831E8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BBD4AC;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1E88) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1E88) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A83280: addr lbl_88BC1FF0, u32@lbl_88BBD604, u32@0x68 */
void ts4_addr_lbl_88BC1FF0_88A83280(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC1FF0) + 104) = (ts4_word)(*(ts4_word *)lbl_88BBD604);
    return;
}

/* Swing_DLL.xex 0x88A83388: addr lbl_88BC2098, u32@lbl_88BBD604, u32@0xc8 */
void ts4_addr_lbl_88BC2098_88A83388(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC2098) + 200) = (ts4_word)(*(ts4_word *)lbl_88BBD604);
    return;
}

/* Swing_DLL.xex 0x88A83910: addr lbl_88BC21D0, u32@lbl_88BBD604, u32@0x68 */
void ts4_addr_lbl_88BC21D0_88A83910(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC21D0) + 104) = (ts4_word)(*(ts4_word *)lbl_88BBD604);
    return;
}

/* Swing_DLL.xex 0x88A83DB8: addr lbl_88BC2248, u32@lbl_88BBD604, u32@0x20 */
void ts4_addr_lbl_88BC2248_88A83DB8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC2248) + 32) = (ts4_word)(*(ts4_word *)lbl_88BBD604);
    return;
}

/* Swing_DLL.xex 0x88A83FA0: addr lbl_88BC22F0, u32@lbl_88BBDC58, u32@0x8 */
void ts4_addr_lbl_88BC22F0_88A83FA0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC22F0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BBDC58);
    return;
}

/* Swing_DLL.xex 0x88A84790: addr lbl_88BC2308, u32@lbl_88BBDFC0, u32@0x50 */
void ts4_addr_lbl_88BC2308_88A84790(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC2308) + 80) = (ts4_word)(*(ts4_word *)lbl_88BBDFC0);
    return;
}

/* Swing_DLL.xex 0x88A84F88: addr lbl_88BC23B0, u32@lbl_88BBDFC4, u32@0x8 */
void ts4_addr_lbl_88BC23B0_88A84F88(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC23B0) + 8) = (ts4_word)(*(ts4_word *)lbl_88BBDFC4);
    return;
}

/* Swing_DLL.xex 0x88A85160: addr lbl_88BC23F8, u32@lbl_88BBE4DC, u32@0x68 */
void ts4_addr_lbl_88BC23F8_88A85160(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC23F8) + 104) = (ts4_word)(*(ts4_word *)lbl_88BBE4DC);
    return;
}

/* Swing_DLL.xex 0x88A85588: addr lbl_88BC24D0, u32@lbl_88BBE6B8, u32@0x50 */
void ts4_addr_lbl_88BC24D0_88A85588(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC24D0) + 80) = (ts4_word)(*(ts4_word *)lbl_88BBE6B8);
    return;
}

/* Swing_DLL.xex 0x88A860F8: addr lbl_88BC2548, u32@lbl_88BBEEA8, u32@0x8 */
void ts4_addr_lbl_88BC2548_88A860F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC2548) + 8) = (ts4_word)(*(ts4_word *)lbl_88BBEEA8);
    return;
}

/* Swing_DLL.xex 0x88A861F8: addr lbl_88BC2560, u32@lbl_88BBEEDC, u32@0x20 */
void ts4_addr_lbl_88BC2560_88A861F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC2560) + 32) = (ts4_word)(*(ts4_word *)lbl_88BBEEDC);
    return;
}

/* Swing_DLL.xex 0x88A868B8: addr lbl_88BC25D8, u32@lbl_88BBF338, u32@0x8 */
void ts4_addr_lbl_88BC25D8_88A868B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC25D8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BBF338);
    return;
}

/* Swing_DLL.xex 0x88A87E38: addr lbl_88BC2A58, u32@lbl_88BBFE10, u32@0x80 */
void ts4_addr_lbl_88BC2A58_88A87E38(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BC2A58) + 128) = (ts4_word)(*(ts4_word *)lbl_88BBFE10);
    return;
}

/* Swing_DLL.xex 0x88A89278: call_seq lbl_88066FE0, lbl_88068838, lbl_88CF785C, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF698, fn_88563470 */
ts4_word ts4_call_seq_lbl_88066FE0_88A89278(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CF785C, (ts4_word)(ts4_word)lbl_88068838, (ts4_word)4, (ts4_word)(ts4_word)lbl_88066FE0);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF698);
    return t2;
}

/* Swing_DLL.xex 0x88A89330: addr lbl_88BCB1D0, u32@lbl_88BC2C08, u32@0x38 */
void ts4_addr_lbl_88BCB1D0_88A89330(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCB1D0) + 56) = (ts4_word)(*(ts4_word *)lbl_88BC2C08);
    return;
}

/* Swing_DLL.xex 0x88A89498: addr lbl_88BCB218, u32@lbl_88BC2C6C, u32@0x8 */
void ts4_addr_lbl_88BCB218_88A89498(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCB218) + 8) = (ts4_word)(*(ts4_word *)lbl_88BC2C6C);
    return;
}

/* Swing_DLL.xex 0x88A89C40: addr lbl_88BCB290, u32@lbl_88BC304C, u32@0x128 */
void ts4_addr_lbl_88BCB290_88A89C40(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCB290) + 296) = (ts4_word)(*(ts4_word *)lbl_88BC304C);
    return;
}

/* Swing_DLL.xex 0x88A8A478: addr lbl_88BCB3C8, u32@lbl_88BC39A4, u32@0x68 */
void ts4_addr_lbl_88BCB3C8_88A8A478(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCB3C8) + 104) = (ts4_word)(*(ts4_word *)lbl_88BC39A4);
    return;
}

/* Swing_DLL.xex 0x88A8A5F0: addr lbl_88BCB470, u32@lbl_88BC3AFC, u32@0x8 */
void ts4_addr_lbl_88BCB470_88A8A5F0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCB470) + 8) = (ts4_word)(*(ts4_word *)lbl_88BC3AFC);
    return;
}

/* Swing_DLL.xex 0x88A8A6F8: addr lbl_88BCB608, u32@lbl_88BC3C6C, u32@0x68 */
void ts4_addr_lbl_88BCB608_88A8A6F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCB608) + 104) = (ts4_word)(*(ts4_word *)lbl_88BC3C6C);
    return;
}

/* Swing_DLL.xex 0x88A8B0A0: addr lbl_88BCB6F8, u32@lbl_88BC44F8, u32@0x50 */
void ts4_addr_lbl_88BCB6F8_88A8B0A0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCB6F8) + 80) = (ts4_word)(*(ts4_word *)lbl_88BC44F8);
    return;
}

/* Swing_DLL.xex 0x88A8BDE8: addr lbl_88BCB800, u32@lbl_88BC4D40, u32@0x98 */
void ts4_addr_lbl_88BCB800_88A8BDE8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCB800) + 152) = (ts4_word)(*(ts4_word *)lbl_88BC4D40);
    return;
}

/* Swing_DLL.xex 0x88A8BEE0: addr lbl_88BCB9B0, u32@lbl_88BC4F5C, u32@0x50 */
void ts4_addr_lbl_88BCB9B0_88A8BEE0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCB9B0) + 80) = (ts4_word)(*(ts4_word *)lbl_88BC4F5C);
    return;
}

/* Swing_DLL.xex 0x88A8C228: addr lbl_88BCBAD0, u32@lbl_88BC53C8, u32@0x20 */
void ts4_addr_lbl_88BCBAD0_88A8C228(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCBAD0) + 32) = (ts4_word)(*(ts4_word *)lbl_88BC53C8);
    return;
}

/* Swing_DLL.xex 0x88A8C718: addr lbl_88BCBB00, u32@lbl_88BC5554, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88BCBB00_88A8C718(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BC5554;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCBB00) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCBB00) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A8C8F8: addr lbl_88BCBBC0, u32@lbl_88BC56E0, u32@0x50 */
void ts4_addr_lbl_88BCBBC0_88A8C8F8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCBBC0) + 80) = (ts4_word)(*(ts4_word *)lbl_88BC56E0);
    return;
}

/* Swing_DLL.xex 0x88A8CC90: addr lbl_88BCBC98, u32@lbl_88BC59C0, u32@0x20 */
void ts4_addr_lbl_88BCBC98_88A8CC90(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCBC98) + 32) = (ts4_word)(*(ts4_word *)lbl_88BC59C0);
    return;
}

/* Swing_DLL.xex 0x88A8CD18: addr lbl_88BCBCC8, u32@lbl_88BC59C0, u32@0x20 */
void ts4_addr_lbl_88BCBCC8_88A8CD18(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCBCC8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BC59C0);
    return;
}

/* Swing_DLL.xex 0x88A8CE10: addr lbl_88BCBCF8, u32@lbl_88BC59C0, u32@0x20 */
void ts4_addr_lbl_88BCBCF8_88A8CE10(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCBCF8) + 32) = (ts4_word)(*(ts4_word *)lbl_88BC59C0);
    return;
}

/* Swing_DLL.xex 0x88A8D458: addr lbl_88BCBD28, u32@lbl_88BC5AFC, u32@0x8 */
void ts4_addr_lbl_88BCBD28_88A8D458(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCBD28) + 8) = (ts4_word)(*(ts4_word *)lbl_88BC5AFC);
    return;
}

/* Swing_DLL.xex 0x88A8D5C8: addr lbl_88BCBDA0, u32@lbl_88BC5CFC, u32@0x20 */
void ts4_addr_lbl_88BCBDA0_88A8D5C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCBDA0) + 32) = (ts4_word)(*(ts4_word *)lbl_88BC5CFC);
    return;
}

/* Swing_DLL.xex 0x88A8D730: addr lbl_88BCBDE8, u32@lbl_88BC5E08, u32@0x8 */
void ts4_addr_lbl_88BCBDE8_88A8D730(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCBDE8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BC5E08);
    return;
}

/* Swing_DLL.xex 0x88A8E2C8: addr lbl_88BCBE60, u32@lbl_88BC5E6C, u32@0x68 */
void ts4_addr_lbl_88BCBE60_88A8E2C8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCBE60) + 104) = (ts4_word)(*(ts4_word *)lbl_88BC5E6C);
    return;
}

/* Swing_DLL.xex 0x88A8ED08: addr lbl_88BCBF20, u32@lbl_88BC729C, u32@0x8 */
void ts4_addr_lbl_88BCBF20_88A8ED08(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCBF20) + 8) = (ts4_word)(*(ts4_word *)lbl_88BC729C);
    return;
}

/* Swing_DLL.xex 0x88A8F8D0: addr lbl_88BCBFF8, u32@lbl_88BC77D8, u32@0xb0 */
void ts4_addr_lbl_88BCBFF8_88A8F8D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCBFF8) + 176) = (ts4_word)(*(ts4_word *)lbl_88BC77D8);
    return;
}

/* Swing_DLL.xex 0x88A8F9D8: addr lbl_88BCC0E8, u32@lbl_88BC793C, u32@0xb0 */
void ts4_addr_lbl_88BCC0E8_88A8F9D8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC0E8) + 176) = (ts4_word)(*(ts4_word *)lbl_88BC793C);
    return;
}

/* Swing_DLL.xex 0x88A8FC90: addr lbl_88BCC1C0, u32@lbl_88BC77E4, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88BCC1C0_88A8FC90(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88BC77E4;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC1C0) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC1C0) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A8FD28: addr lbl_88BCC328, u32@lbl_88BC793C, u32@0x68 */
void ts4_addr_lbl_88BCC328_88A8FD28(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC328) + 104) = (ts4_word)(*(ts4_word *)lbl_88BC793C);
    return;
}

/* Swing_DLL.xex 0x88A8FE30: addr lbl_88BCC3D0, u32@lbl_88BC793C, u32@0xc8 */
void ts4_addr_lbl_88BCC3D0_88A8FE30(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC3D0) + 200) = (ts4_word)(*(ts4_word *)lbl_88BC793C);
    return;
}

/* Swing_DLL.xex 0x88A903B8: addr lbl_88BCC508, u32@lbl_88BC793C, u32@0x68 */
void ts4_addr_lbl_88BCC508_88A903B8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC508) + 104) = (ts4_word)(*(ts4_word *)lbl_88BC793C);
    return;
}

/* Swing_DLL.xex 0x88A90860: addr lbl_88BCC580, u32@lbl_88BC793C, u32@0x20 */
void ts4_addr_lbl_88BCC580_88A90860(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC580) + 32) = (ts4_word)(*(ts4_word *)lbl_88BC793C);
    return;
}

/* Swing_DLL.xex 0x88A90A48: addr lbl_88BCC628, u32@lbl_88BC7F90, u32@0x8 */
void ts4_addr_lbl_88BCC628_88A90A48(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC628) + 8) = (ts4_word)(*(ts4_word *)lbl_88BC7F90);
    return;
}

/* Swing_DLL.xex 0x88A91238: addr lbl_88BCC640, u32@lbl_88BC82F8, u32@0x50 */
void ts4_addr_lbl_88BCC640_88A91238(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC640) + 80) = (ts4_word)(*(ts4_word *)lbl_88BC82F8);
    return;
}

/* Swing_DLL.xex 0x88A91A30: addr lbl_88BCC6E8, u32@lbl_88BC82FC, u32@0x8 */
void ts4_addr_lbl_88BCC6E8_88A91A30(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC6E8) + 8) = (ts4_word)(*(ts4_word *)lbl_88BC82FC);
    return;
}

/* Swing_DLL.xex 0x88A91C08: addr lbl_88BCC730, u32@lbl_88BC8814, u32@0x68 */
void ts4_addr_lbl_88BCC730_88A91C08(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC730) + 104) = (ts4_word)(*(ts4_word *)lbl_88BC8814);
    return;
}

/* Swing_DLL.xex 0x88A92030: addr lbl_88BCC808, u32@lbl_88BC88D4, u32@0x50 */
void ts4_addr_lbl_88BCC808_88A92030(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC808) + 80) = (ts4_word)(*(ts4_word *)lbl_88BC88D4);
    return;
}

/* Swing_DLL.xex 0x88A92BA0: addr lbl_88BCC880, u32@lbl_88BC8E0C, u32@0x8 */
void ts4_addr_lbl_88BCC880_88A92BA0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC880) + 8) = (ts4_word)(*(ts4_word *)lbl_88BC8E0C);
    return;
}

/* Swing_DLL.xex 0x88A92CA0: addr lbl_88BCC898, u32@lbl_88BC9218, u32@0x20 */
void ts4_addr_lbl_88BCC898_88A92CA0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC898) + 32) = (ts4_word)(*(ts4_word *)lbl_88BC9218);
    return;
}

/* Swing_DLL.xex 0x88A93360: addr lbl_88BCC910, u32@lbl_88BC95CC, u32@0x8 */
void ts4_addr_lbl_88BCC910_88A93360(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88BCC910) + 8) = (ts4_word)(*(ts4_word *)lbl_88BC95CC);
    return;
}
