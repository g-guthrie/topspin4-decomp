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
extern char lbl_88CAD32C[];
extern char lbl_88D4589C[];
ts4_word fn_88164000();
ts4_word fn_8819B448();
ts4_word fn_8819C360();
ts4_word fn_88280ED8();
ts4_word fn_88421338();
ts4_word fn_8857ACB8();
ts4_word fn_88608590();
ts4_word fn_88628C48();
ts4_word fn_8869D0C8();
ts4_word fn_886A70C8();
ts4_word fn_88923530();
ts4_word fn_8895BE40();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_if_atomic_interlocked_dec_88151988();
ts4_word ts4_if_call_seq_u32_off0_8816D140();
ts4_word ts4_if_get_u32_offc_8819B6C0();
ts4_word ts4_if_get_u32_offc_8819C5F0();
ts4_word ts4_tailcall_fn_88564B00_88564770();

/* Swing_DLL.xex 0x8819B0C8: if_call_seq u32@0x0, u32@0x0, u32@0xc, u32@0xc, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8819B0C8(ts4_word a0, ts4_word a1)
{
    ts4_word q71;
    ts4_word q70;
    ts4_word t1;
    ts4_word t2;
    int t4;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    q71 = t1 + -16;
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    q70 = t2 + -16;
    if ((ts4_word)(q70) != (ts4_word)(q71)) {
        t4 = *(ts4_word *)((char *)(ts4_word)((q71)) + 12);
        if ((int)t4 >= 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)((q70)) + 0)) == (ts4_word)(*(ts4_word *)((char *)(ts4_word)((q71)) + 0))) {
            t9 = ts4_if_get_u32_offc_8819B6C0((ts4_word)(q70), (ts4_word)t2);
            ts4_if_atomic_interlocked_dec_88151988((ts4_word)(q71));
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(t9 + 16);
            return a0;
        }
        fn_8819B448((ts4_word)a0, (ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + -12)));
    }
    return a0;
}

/* Swing_DLL.xex 0x8819C190: if_call_seq u32@0x0, u32@0x0, u32@0xc, u32@0xc, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8819C190(ts4_word a0, ts4_word a1)
{
    ts4_word q71;
    ts4_word q70;
    ts4_word t1;
    ts4_word t2;
    int t4;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    q71 = t1 + -16;
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    q70 = t2 + -16;
    if ((ts4_word)(q70) != (ts4_word)(q71)) {
        t4 = *(ts4_word *)((char *)(ts4_word)((q71)) + 12);
        if ((int)t4 >= 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)((q70)) + 0)) == (ts4_word)(*(ts4_word *)((char *)(ts4_word)((q71)) + 0))) {
            t9 = ts4_if_get_u32_offc_8819C5F0((ts4_word)(q70), (ts4_word)t2);
            ts4_if_atomic_interlocked_dec_88151988((ts4_word)(q71));
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(t9 + 16);
            return a0;
        }
        fn_8819C360((ts4_word)a0, (ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + -12)));
    }
    return a0;
}

/* Swing_DLL.xex 0x884222B0: if_get fn_88421338, u32@lbl_88CAD32C, u32@0x0, u32@0x3c, vcall, u32@0x0 */
void ts4_if_get_fn_88421338_884222B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word q70;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    if ((ts4_word)a1 != 0) {
        t1 = fn_88421338((ts4_word)a1);
        q70 = t1 + 1;
        t2 = *(ts4_word *)lbl_88CAD32C;
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 60))))((ts4_word)t2, (ts4_word)(q70));
        t6 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t6) + 8))))((ts4_word)a3, (ts4_word)t7, (ts4_word)a2, (ts4_word)a1, (ts4_word)(q70), (ts4_word)t5);
    }
    return;
}

/* Swing_DLL.xex 0x8861B790: if_call_seq u8@0x824, u32@0x8, u32@0x4, u32@0x8, u32@0x4, fn_88280ED8 */
void ts4_if_call_seq_u8_off824_8861B790(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word q70;
    unsigned char t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 2084);
    if ((ts4_word)t1 == 1) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        if ((ts4_word)t5 == (ts4_word)t4) {
            fn_88280ED8((ts4_word)a0, (ts4_word)t5);
        }
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        q70 = t8 + 12;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(q70);
        t9 = ts4_tailcall_fn_88564B00_88564770((ts4_word)a2);
        *(ts4_word *)((char *)(ts4_word)((q70)) + -8) = (ts4_word)t9;
        t10 = fn_88608590((ts4_word)0, (ts4_word)a2);
        *(ts4_word *)((char *)(ts4_word)((q70)) + -4) = (ts4_word)t10;
        *(ts4_word *)((char *)(ts4_word)((q70)) + -12) = (ts4_word)a1;
    }
    return;
}

/* Swing_DLL.xex 0x8862D238: if_get fn_88628C48, fn_88923530, u32@0x0, lbl_880C1320, u32@0x0, u32@0x60 */
ts4_word ts4_if_get_fn_88628C48_8862D238(ts4_word a0, ts4_args3 sp1)
{
    ts4_word q70;
    ts4_word p5;
    ts4_word t1;
    ts4_word t3;
    int t4;
    ts4_word t8;

    t1 = sp1.w[2];
    fn_88628C48((ts4_word)a0, sp1);
    t3 = fn_88923530((ts4_word)t1, sp1, (ts4_word)((2648702976) | 41202));
    q70 = t3 + 32;
    t4 = *(ts4_word *)((char *)(ts4_word)((q70)) + 0);
    if ((int)t4 != -1) {
        p5 = (ts4_word)(t4 + (q70));
    } else {
        p5 = (ts4_word)(ts4_word)lbl_880C1320;
    }
    t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 96))))((ts4_word)a0, (ts4_word)p5, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x8862D2B8: if_get fn_88628C48, fn_88923530, u32@0x0, lbl_880C1320, u32@0x0, u32@0x60 */
ts4_word ts4_if_get_fn_88628C48_8862D2B8(ts4_word a0, ts4_args3 sp1)
{
    ts4_word q70;
    ts4_word p5;
    ts4_word t1;
    ts4_word t3;
    int t4;
    ts4_word t8;

    t1 = sp1.w[2];
    fn_88628C48((ts4_word)a0, sp1);
    t3 = fn_88923530((ts4_word)t1, sp1, (ts4_word)((1400373248) | 3527));
    q70 = t3 + 40;
    t4 = *(ts4_word *)((char *)(ts4_word)((q70)) + 0);
    if ((int)t4 != -1) {
        p5 = (ts4_word)(t4 + (q70));
    } else {
        p5 = (ts4_word)(ts4_word)lbl_880C1320;
    }
    t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 96))))((ts4_word)a0, (ts4_word)p5, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x88656900: if_get u32@0x1c, u32@0x30, vcall, u32@0x78, u32@0x0, u32@0x4c */
void ts4_if_get_u32_off1c_88656900(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word q70;
    ts4_word t3;
    ts4_word t7;
    ts4_word t8;
    ts4_word t11;
    unsigned char t12;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 48))))((ts4_word)(a0 + 28));
    if ((ts4_word)(t3 & 0xff) != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 120)) == (ts4_word)a2) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0))) + 76))))((ts4_word)(a0 + 28), (ts4_word)0);
        q70 = t7 + 24;
        t8 = *(ts4_word *)((char *)(ts4_word)((q70)) + 4);
        if ((ts4_word)a1 < (ts4_word)t8) {
            t11 = *(ts4_word *)((char *)(ts4_word)((q70)) + 0);
            t12 = *(unsigned char *)((char *)(ts4_word)((t11 + (q70))) + a1);
            if ((int)(255 - t12) >= 1) {
                *(unsigned char *)((char *)(ts4_word)((t11 + (q70))) + a1) = (unsigned char)(t12 + 1);
                return;
            }
            *(unsigned char *)((char *)(ts4_word)((t11 + (q70))) + a1) = (unsigned char)255;
            return;
        }
        return;
    }
    return;
}

/* Swing_DLL.xex 0x886AA6D0: if_call_seq u32@0x64, fn_886A70C8, fn_8869D0C8, u32@0x78, u8@0x444, u8@0x444 */
void ts4_if_call_seq_u32_off64_886AA6D0(ts4_word a0)
{
    ts4_word q70;
    ts4_word p11;
    ts4_word t4;
    unsigned char t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    int t10;

    fn_886A70C8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 100)));
    fn_8869D0C8((ts4_word)a0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    t5 = *(unsigned char *)((char *)(ts4_word)(t4) + 1092);
    if ((ts4_word)t5 != 0) {
        *(unsigned char *)((char *)(ts4_word)(t4) + 1092) = (unsigned char)0;
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 48);
        t9 = *(ts4_word *)((char *)(ts4_word)(t7) + 16);
        q70 = t9 + -1;
        t10 = *(ts4_word *)((char *)(ts4_word)(t8) + 724);
        p11 = (ts4_word)t10;
        if ((int)(q70) >= (int)t10) {
            p11 = (ts4_word)(q70);
        }
        *(ts4_word *)((char *)(ts4_word)(t8) + 724) = (ts4_word)p11;
    }
    return;
}

/* Swing_DLL.xex 0x886F1540: if_get u32@0x110, u8@0x115, u32@0x110, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off110_886F1540(ts4_word a0)
{
    ts4_word q70;
    ts4_word t1;
    unsigned char t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 272);
    q70 = t1 + -1;
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 277);
    *(ts4_word *)((char *)(ts4_word)(a0) + 272) = (ts4_word)(q70);
    if ((ts4_word)t2 == 0) {
        return;
    }
    if ((int)(q70) != 0) {
        return;
    }
    ((void (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x886F3718: if_get u32@0x30, u32@0xc, u32@0x0, u32@0xc, u32@0x0, lbl_880C1320 */
void ts4_if_get_u32_off30_886F3718(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word q70;
    ts4_word p6;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    int t5;
    ts4_word t7;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 48);
    if ((ts4_word)t1 == 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        q70 = t4 + 44;
        t5 = *(ts4_word *)((char *)(ts4_word)((q70)) + 0);
        if ((int)t5 != -1) {
            p6 = (ts4_word)(t5 + (q70));
        } else {
            p6 = (ts4_word)(ts4_word)lbl_880C1320;
        }
        t7 = fn_88608590((ts4_word)0, (ts4_word)p6);
        loc50[0] = (ts4_word)t7;
        t10 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 48))))((ts4_word)a2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(a1 + 36), (ts4_word)a3);
        *(ts4_word *)((char *)(ts4_word)(a1) + 48) = (ts4_word)t10;
    }
    return;
}

/* Swing_DLL.xex 0x887FFCB8: if_call_seq u8@0x8c8, u32@0xb0, u32@0xa4, u32@0x9c, u32@0x0, u32@0xb0 */
void ts4_if_call_seq_u8_off8c8_887FFCB8(ts4_word a0)
{
    ts4_word q70;
    ts4_word p10;
    ts4_word p16;
    unsigned char t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    int t9;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;
    int t15;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 2248);
    if ((ts4_word)t1 != 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
        q70 = t6 + 40;
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 164);
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
        t9 = *(ts4_word *)((char *)(ts4_word)((q70)) + 0);
        p10 = (ts4_word)0;
        if ((int)t9 != -1) {
            p10 = (ts4_word)(t9 + (q70));
        }
        fn_8857ACB8((ts4_word)p10, (ts4_word)t7, (ts4_word)(t8 << 6));
        t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
        t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
        t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
        t15 = *(ts4_word *)((char *)(ts4_word)(t12) + 0);
        p16 = (ts4_word)0;
        if ((int)t15 != -1) {
            p16 = (ts4_word)(t15 + t12);
        }
        fn_8857ACB8((ts4_word)p16, (ts4_word)t14, (ts4_word)(t13 << 6));
    }
    return;
}

/* Swing_DLL.xex 0x88957C58: if_call_seq u32@0x3c, u32@0x0, lbl_880C1320, ts4_assign_formatted_text */
ts4_word ts4_if_call_seq_u32_off3c_88957C58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word q70;
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 60);
    q70 = t1 + 28;
    t2 = *(ts4_word *)((char *)(ts4_word)((q70)) + 0);
    if ((int)t2 != -1) {
        p3 = (ts4_word)(t2 + (q70));
    } else {
        p3 = (ts4_word)(ts4_word)lbl_880C1320;
    }
    ts4_assign_formatted_text((ts4_word)a0, (ts4_word)p3, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x88958408: if_call_seq u32@0x3c, u32@0x0, lbl_880C1320, u32@lbl_88D4589C, fn_88164000, ts4_if_call_seq_u32_off0_8816D140 */
ts4_word ts4_if_call_seq_u32_off3c_88958408(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word q70;
    ts4_word p3;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t7;

    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 60);
    q70 = t1 + 20;
    t2 = *(ts4_word *)((char *)(ts4_word)((q70)) + 0);
    if ((int)t2 != -1) {
        p3 = (ts4_word)(t2 + (q70));
    } else {
        p3 = (ts4_word)(ts4_word)lbl_880C1320;
    }
    t5 = fn_88164000((ts4_word)(ts4_word)&loc50[0], (ts4_word)((*(ts4_word *)lbl_88D4589C) + 40), (ts4_word)p3, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t2);
    ts4_if_call_seq_u32_off0_8816D140((ts4_word)a0, (ts4_word)t5);
    t7 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t7);
    return a0;
}

/* Swing_DLL.xex 0x88963C70: loop_call_seq u32@0x2c, u32@0x0, u32@0x2c, u32@0x0, u32@0x4, fn_8895BE40 */
void ts4_loop_call_seq_u32_off2c_88963C70(ts4_word a0)
{
    ts4_word q71;
    ts4_word q70;
    ts4_word p3;
    ts4_word lv4;
    ts4_word p9;
    ts4_word p11;
    ts4_word t1;
    int t2;
    ts4_word t5;
    int t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    q70 = t1 + 12;
    t2 = *(ts4_word *)((char *)(ts4_word)((q70)) + 0);
    p3 = (ts4_word)0;
    if ((int)t2 != -1) {
        p3 = (ts4_word)(t2 + (q70));
    }
    lv4 = (ts4_word)p3;
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        q71 = t5 + 12;
        t6 = *(ts4_word *)((char *)(ts4_word)((q71)) + 0);
        p9 = (ts4_word)0;
        if ((int)t6 != -1) {
            p9 = (ts4_word)((((*(ts4_word *)((char *)(ts4_word)((q71)) + 4)) << 3) + t6) + (q71));
        }
        if ((ts4_word)lv4 == (ts4_word)p9) {
            return;
        }
        fn_8895BE40((ts4_word)a0, (ts4_word)lv4);
        p11 = (ts4_word)(lv4 + 8);
        lv4 = p11;
    } while (1);
}
