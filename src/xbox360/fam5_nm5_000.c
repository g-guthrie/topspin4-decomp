/* Small functions produced by the asm2c translator (FAM4 fork) and verified
   byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).
   FAM5: near misses of the translator fixed by a per-function search over
   source-level variants (commutative operand order, int-widened byte/half
   locals, address of a parameter instead of a stack copy, ...).
   The original address is in the comment above each definition. Parameters
   are untyped words (a0 = this/first argument); field accesses are by byte
   offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;
typedef struct ts4_args3 { ts4_word w[3]; } ts4_args3;

extern char lbl_880C1320[];
extern char lbl_880D35A0[];
extern char lbl_880F0158[];
extern char lbl_880F0164[];
extern char lbl_880F016C[];
extern char lbl_88D458AC[];
extern char lbl_88D458B0[];
ts4_word fn_881643D0();
ts4_word fn_8816CAA0();
ts4_word fn_88755168();
ts4_word fn_88761508();
ts4_word fn_889123A0();
ts4_word fn_88923238();
ts4_word fn_889489E0();
ts4_word fn_88949908();
ts4_word fn_889C7AB0();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_gp0_xdata_get_bool_88163C60();
ts4_word ts4_handle_forward_88150770();
ts4_word ts4_handle_forward_88610A48();

/* Swing_DLL.xex 0x8817E678: if_set u32@0x0, u32@0x0, u32@0x28, vcall, u32@0x0, u8@0x0 */
void ts4_if_set_u32_off0_8817E678(ts4_word a0, ts4_args3 sp1, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char b70;
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t8;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = sp1.w[0];
    t2 = sp1.w[1];
    b70 = !((ts4_word)t1 != 0) || ((ts4_word)t2 == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b70;
    if ((ts4_word)(p5 & 0xff) == 0) {
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)t1, (ts4_word)(ts4_word)&sp1, (ts4_word)t2, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t8;
        *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(t8) + 0));
        *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(t8) + 0));
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 6) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88411CB8: if_set u8@0x0 */
void ts4_if_set_u8_off0_88411CB8(ts4_word a0, int a1)
{
    unsigned char b70;
    ts4_word p2;

    b70 = !(((((int)a1 != 0 && (int)a1 != 1) && (int)a1 != 2) && (int)a1 != 3) && (int)a1 != 4) || ((int)a1 == 5);
    p2 = (ts4_word)b70;
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)p2;
    return;
}

/* Swing_DLL.xex 0x8865FA70: if_get u32@0x0, u32@0x48, u32@0x78, u32@0x0, u32@0x40, u8@0x8d */
void ts4_if_get_u32_off0_8865FA70(ts4_word a0)
{
    unsigned char b70;
    ts4_word p14;
    ts4_word t1;
    ts4_word t2;
    int t4;
    unsigned char t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    float t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 72);
    t4 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 120))) + 0);
    if ((int)t4 != 2) {
        return;
    }
    t8 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 64))) + 141);
    if ((ts4_word)t8 == 0) {
        return;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(t1) + 116);
    t10 = *(ts4_word *)((char *)(ts4_word)(t1) + 136);
    t11 = *(ts4_word *)((char *)(ts4_word)(t9) + 1804);
    t12 = *(float *)((char *)(ts4_word)(t10) + 76);
    b70 = !((((((((ts4_word)t11 != (ts4_word)((2569142272) | 22748) && (ts4_word)t11 != (ts4_word)((1708916736) | 39514)) && (ts4_word)t11 != (ts4_word)((1259470848) | 8101)) && (ts4_word)t11 != (ts4_word)((2685403136) | 4383)) && (ts4_word)t11 != (ts4_word)((3252813824) | 43618)) && (ts4_word)t11 != (ts4_word)((4196466688) | 11414)) && (ts4_word)t11 != (ts4_word)((1926496256) | 60865)) && (ts4_word)t11 != (ts4_word)((652935168) | 32834)) || ((ts4_word)t11 == (ts4_word)((398852096) | 49123));
    p14 = (ts4_word)b70;
    if ((ts4_word)(p14 & 0xff) == 0) {
        return;
    }
    *(float *)((char *)(ts4_word)(t9) + 3876) = ((*(float *)((char *)(ts4_word)(t9) + 3876)) + t12);
    return;
}

/* Swing_DLL.xex 0x886F80E8: if_set ts4_handle_forward_88150770, u32@0x0, u32@0x0, u32@0x50, vcall */
void ts4_if_set_ts4_handle_forward_88150770_886F80E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char b70;
    ts4_word p5;
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;

    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t2 = loc50[0];
    t3 = loc50[1];
    b70 = !((ts4_word)t2 != 0) || ((ts4_word)t3 == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b70;
    if ((ts4_word)(p5 & 0xff) == 0) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 80))))((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t3, (ts4_word)1);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88700B78: if_call_seq ts4_handle_forward_88150770, ts4_gp0_xdata_get_bool_88163C60, u8@0x1f */
void ts4_if_call_seq_ts4_handle_forward_88150770_88700B78(ts4_word a0, ts4_args3 sp1)
{
    unsigned char b70;
    ts4_word p5;
    ts4_word p7;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    loc50[0] = (ts4_word)((1434255360) | 24457);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    t3 = loc58[1];
    b70 = !((ts4_word)t2 != 0) || ((ts4_word)t3 == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b70;
    if ((ts4_word)(p5 & 0xff) == 0) {
        if ((ts4_word)t3 == (ts4_word)((983040) | 65535)) {
            p7 = (ts4_word)0;
        } else {
            t6 = ts4_gp0_xdata_get_bool_88163C60((ts4_word)(ts4_word)&loc58[0]);
            p7 = (ts4_word)t6;
        }
        *(unsigned char *)((char *)(ts4_word)(a0) + 31) = (unsigned char)p7;
    }
    return;
}

/* Swing_DLL.xex 0x88700C18: if_call_seq ts4_handle_forward_88150770, ts4_gp0_xdata_get_bool_88163C60, u8@0x1e */
void ts4_if_call_seq_ts4_handle_forward_88150770_88700C18(ts4_word a0, ts4_args3 sp1)
{
    unsigned char b70;
    ts4_word p5;
    ts4_word p7;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    loc50[0] = (ts4_word)((4196401152) | 1773);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    t3 = loc58[1];
    b70 = !((ts4_word)t2 != 0) || ((ts4_word)t3 == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b70;
    if ((ts4_word)(p5 & 0xff) == 0) {
        if ((ts4_word)t3 == (ts4_word)((983040) | 65535)) {
            p7 = (ts4_word)0;
        } else {
            t6 = ts4_gp0_xdata_get_bool_88163C60((ts4_word)(ts4_word)&loc58[0]);
            p7 = (ts4_word)t6;
        }
        *(unsigned char *)((char *)(ts4_word)(a0) + 30) = (unsigned char)p7;
    }
    return;
}

/* Swing_DLL.xex 0x88700CB8: if_call_seq ts4_handle_forward_88150770, ts4_gp0_xdata_get_bool_88163C60, u8@0x1d */
void ts4_if_call_seq_ts4_handle_forward_88150770_88700CB8(ts4_word a0, ts4_args3 sp1)
{
    unsigned char b70;
    ts4_word p5;
    ts4_word p7;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    loc50[0] = (ts4_word)((3480879104) | 10951);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    t3 = loc58[1];
    b70 = !((ts4_word)t2 != 0) || ((ts4_word)t3 == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b70;
    if ((ts4_word)(p5 & 0xff) == 0) {
        if ((ts4_word)t3 == (ts4_word)((983040) | 65535)) {
            p7 = (ts4_word)0;
        } else {
            t6 = ts4_gp0_xdata_get_bool_88163C60((ts4_word)(ts4_word)&loc58[0]);
            p7 = (ts4_word)t6;
        }
        *(unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)p7;
    }
    return;
}

/* Swing_DLL.xex 0x88722610: if_get ts4_handle_forward_88150770, u32@0x0, u32@0x50, vcall, ts4_assign_formatted_text, lbl_880F0158 */
void ts4_if_get_ts4_handle_forward_88150770_88722610(ts4_word a0, ts4_word a1)
{
    unsigned char b70;
    ts4_word p5;
    ts4_word loc50[2];
    ts4_word loc68[3];
    ts4_word loc58[3];
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_word t19;
    int t22;

    loc50[0] = (ts4_word)((4191879168) | 33337);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc68[0], (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc68[0];
    t3 = loc68[1];
    b70 = !((ts4_word)t2 != 0) || ((ts4_word)t3 == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b70;
    if ((ts4_word)(p5 & 0xff) == 0) {
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 80))))((ts4_word)t2, (ts4_word)(ts4_word)&loc68[0], (ts4_word)t3, (ts4_word)1);
        ts4_assign_formatted_text((ts4_word)(ts4_word)&loc58[0], (ts4_word)t8);
        t10 = fn_881643D0((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880F0158);
        if ((ts4_word)(t10 & 0xff) != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)1;
            *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)1;
        } else {
            t11 = fn_881643D0((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880F0164);
            if ((ts4_word)(t11 & 0xff) != 0) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)1;
                *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
            } else {
                t12 = fn_881643D0((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880F016C);
                if ((ts4_word)(t12 & 0xff) != 0) {
                    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)1;
                    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
                } else {
                    t13 = fn_881643D0((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880D35A0);
                    if ((ts4_word)(t13 & 0xff) != 0) {
                        *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
                        *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
                    }
                }
            }
        }
        t19 = loc58[0];
        ts4_destroy_owned_object((ts4_word)t19);
    }
    t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((int)t22 == 8) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x88731540: if_addr ts4_handle_forward_88150770, lbl_880C1320, u32@0x0, u32@0x50, vcall, fn_8816CAA0 */
void ts4_if_addr_ts4_handle_forward_88150770_88731540(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char b70;
    ts4_word p5;
    ts4_word p10;
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;

    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t2 = loc50[0];
    t3 = loc50[1];
    b70 = !((ts4_word)t2 != 0) || ((ts4_word)t3 == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b70;
    if ((ts4_word)(p5 & 0xff) == 0) {
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 80))))((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t3, (ts4_word)1);
        p10 = (ts4_word)t8;
    } else {
        p10 = (ts4_word)(ts4_word)lbl_880C1320;
    }
    fn_8816CAA0((ts4_word)a2, (ts4_word)p10);
    return;
}

/* Swing_DLL.xex 0x88757BB0: if_get ts4_handle_forward_88150770, u32@0x0, u32@0x50, vcall, ts4_assign_formatted_text, fn_88755168 */
void ts4_if_get_ts4_handle_forward_88150770_88757BB0(ts4_args3 sp0)
{
    unsigned char b70;
    ts4_word p5;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word loc68[3];
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;
    ts4_word t11;

    loc50[0] = (ts4_word)((4262526976) | 53560);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    t3 = loc58[1];
    b70 = !((ts4_word)t2 != 0) || ((ts4_word)t3 == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b70;
    if ((ts4_word)(p5 & 0xff) == 0) {
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 80))))((ts4_word)t2, (ts4_word)(ts4_word)&loc58[0], (ts4_word)t3, (ts4_word)1);
        ts4_assign_formatted_text((ts4_word)(ts4_word)&loc68[0], (ts4_word)t8);
        fn_88755168((ts4_word)(ts4_word)&loc68[0]);
        t11 = loc68[0];
        ts4_destroy_owned_object((ts4_word)t11);
    }
    return;
}

/* Swing_DLL.xex 0x88762578: if_get ts4_handle_forward_88150770, u32@0x0, u32@0x50, vcall, fn_88761508 */
void ts4_if_get_ts4_handle_forward_88150770_88762578(ts4_args3 sp0)
{
    unsigned char b70;
    ts4_word p5;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;

    loc50[0] = (ts4_word)((4262526976) | 53560);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    t3 = loc58[1];
    b70 = !((ts4_word)t2 != 0) || ((ts4_word)t3 == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b70;
    if ((ts4_word)(p5 & 0xff) == 0) {
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 80))))((ts4_word)t2, (ts4_word)(ts4_word)&loc58[0], (ts4_word)t3, (ts4_word)1);
        fn_88761508((ts4_word)t8);
    }
    return;
}

/* Swing_DLL.xex 0x888B02A0: if_get ts4_handle_forward_88610A48, ts4_handle_forward_88150770, u32@0x0, u32@0x28, vcall, u32@0xb0 */
void ts4_if_get_ts4_handle_forward_88610A48_888B02A0(ts4_word a0, ts4_args3 sp1)
{
    unsigned char b70;
    ts4_word p6;
    ts4_word loc50[1];
    ts4_word loc68[3];
    ts4_word loc54[1];
    ts4_word loc58[3];
    ts4_word t3;
    ts4_word t4;
    ts4_word t9;
    ts4_word t11;
    ts4_word t12;

    loc50[0] = (ts4_word)((364773376) | 17005);
    ts4_handle_forward_88610A48((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    loc54[0] = (ts4_word)((3495231488) | 35585);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc54[0]);
    t3 = loc58[0];
    t4 = loc58[1];
    b70 = !((ts4_word)t3 != 0) || ((ts4_word)t4 == (ts4_word)((983040) | 65535));
    p6 = (ts4_word)b70;
    if ((ts4_word)(p6 & 0xff) == 0) {
        t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 40))))((ts4_word)t3, (ts4_word)(ts4_word)&loc58[0], (ts4_word)t4, (ts4_word)4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 176) = (ts4_word)t9;
    }
    t11 = sp1.w[2];
    t12 = sp1.w[1];
    *(ts4_word *)((char *)(ts4_word)(a0) + 180) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 36)) + t12);
    return;
}

/* Swing_DLL.xex 0x88922468: loop_get u32@0x58, u32@0x54, u32@0x0, u32@0x0, u32@0x3c, vcall */
ts4_word ts4_loop_get_u32_off58_88922468(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    p8 = (ts4_word)0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 60))))((ts4_word)t4, (ts4_word)a1);
        } while ((ts4_word)t7 == 0 && (ts4_word)(lv3 += 4) != (ts4_word)t1);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x889229C0: loop_get u32@0x20, u32@0x1c, u32@0x0, u32@0x14, vcall */
ts4_word ts4_loop_get_u32_off20_889229C0(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p7 = (ts4_word)0;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t2;
        do {
            t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0))) + 20))))((ts4_word)lv3, (ts4_word)a1);
        } while ((ts4_word)t6 == 0 && (ts4_word)t1 != (ts4_word)(lv3 += 12));
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x88948F30: if_call_seq u32@0x64, u32@lbl_88D458AC, u32@lbl_88D458B0, fn_88923238, u32@0x2c, ts4_handle_forward_88610A48 */
void ts4_if_call_seq_u32_off64_88948F30(ts4_word a0)
{
    unsigned char b70;
    ts4_word p8;
    ts4_word p14;
    ts4_word p15;
    ts4_word p18;
    ts4_word p19;
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_word t22;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)lbl_88D458AC;
        fn_88923238((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)(*(ts4_word *)lbl_88D458B0), (ts4_word)t2);
        t5 = loc50[0];
        t6 = loc50[1];
        b70 = !((ts4_word)t5 != 0) || ((ts4_word)t6 == (ts4_word)((983040) | 65535));
        p8 = (ts4_word)b70;
        p18 = (ts4_word)t6;
        p19 = (ts4_word)t5;
        if ((ts4_word)(p8 & 0xff) == 0) {
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
            p14 = (ts4_word)t6;
            p15 = (ts4_word)t5;
            if ((ts4_word)t9 != 0) {
                t10 = ts4_handle_forward_88610A48((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 44));
                t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 0);
                t12 = *(ts4_word *)((char *)(ts4_word)(t10) + 4);
                t13 = *(ts4_word *)((char *)(ts4_word)(t10) + 8);
                loc50[0] = (ts4_word)t11;
                loc50[1] = (ts4_word)t12;
                loc50[2] = (ts4_word)t13;
                p14 = (ts4_word)t12;
                p15 = (ts4_word)t11;
            }
            p18 = (ts4_word)p14;
            p19 = (ts4_word)p15;
        }
        t22 = loc50[2];
        *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)p19;
        *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)p18;
        *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)t22;
        fn_889489E0((ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x88949BE8: if_call_seq u32@0x3c, u32@lbl_88D458AC, u32@lbl_88D458B0, fn_88923238, u32@0x2c, ts4_handle_forward_88610A48 */
void ts4_if_call_seq_u32_off3c_88949BE8(ts4_word a0)
{
    unsigned char b70;
    ts4_word p8;
    ts4_word p14;
    ts4_word p15;
    ts4_word p18;
    ts4_word p19;
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_word t22;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)lbl_88D458AC;
        fn_88923238((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)(*(ts4_word *)lbl_88D458B0), (ts4_word)t2);
        t5 = loc50[0];
        t6 = loc50[1];
        b70 = !((ts4_word)t5 != 0) || ((ts4_word)t6 == (ts4_word)((983040) | 65535));
        p8 = (ts4_word)b70;
        p18 = (ts4_word)t6;
        p19 = (ts4_word)t5;
        if ((ts4_word)(p8 & 0xff) == 0) {
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
            p14 = (ts4_word)t6;
            p15 = (ts4_word)t5;
            if ((ts4_word)t9 != 0) {
                t10 = ts4_handle_forward_88610A48((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 44));
                t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 0);
                t12 = *(ts4_word *)((char *)(ts4_word)(t10) + 4);
                t13 = *(ts4_word *)((char *)(ts4_word)(t10) + 8);
                loc50[0] = (ts4_word)t11;
                loc50[1] = (ts4_word)t12;
                loc50[2] = (ts4_word)t13;
                p14 = (ts4_word)t12;
                p15 = (ts4_word)t11;
            }
            p18 = (ts4_word)p14;
            p19 = (ts4_word)p15;
        }
        t22 = loc50[2];
        *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)p19;
        *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)p18;
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)t22;
        fn_88949908((ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x889C7BE8: loop_call_seq u32@0x4, u32@0x8, u32@0x28, u32@0x24, u32@0x28, u32@0x24 */
void ts4_loop_call_seq_u32_off4_889C7BE8(ts4_word a0, ts4_word a1)
{
    ts4_word lv7;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4))) + 8);
    if ((ts4_word)t2 == (ts4_word)((230031360) | 29336)) {
        fn_889C7AB0();
        return;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t6 != (ts4_word)t5) {
        lv7 = (ts4_word)t6;
        do {
            t9 = fn_889123A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv7) + 0)), (ts4_word)a1);
        } while ((ts4_word)(t9 & 0xff) == 0 && (ts4_word)(lv7 += 4) != (ts4_word)t5);
    }
    return;
}
