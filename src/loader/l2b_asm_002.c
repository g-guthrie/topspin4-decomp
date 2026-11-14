/* Loader_DLL.xex 0x831404A0-0x83185D64, executable version 0.0.0.3. */
/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Loader_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char lbl_830009F8[];
extern char lbl_830080C4[];
extern char lbl_8352C070[];
extern char lbl_83531658[];
extern char lbl_8353165C[];
extern char lbl_8353168C[];
ts4_word KeSetEvent();
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_830AAAE8();
ts4_word fn_830AF1B8();
ts4_word fn_83120518();
ts4_word fn_83120540();
ts4_word fn_83140430();
ts4_word fn_8314E0B8();
ts4_word fn_8314E408();
ts4_word fn_8315C708();
ts4_word fn_83161840();
ts4_word fn_831618A0();
ts4_word fn_83161AE8();
ts4_word fn_83162A98();
ts4_word fn_83162D10();
ts4_word fn_83162D28();
ts4_word fn_83162DD0();
ts4_word fn_83162DF0();
ts4_word fn_831655F8();
ts4_word fn_83165620();
ts4_word fn_83166018();
ts4_word fn_83166248();
ts4_word fn_83166680();
ts4_word fn_83174C98();
ts4_word fn_83174D10();
ts4_word fn_83178920();
ts4_word fn_83179690();
ts4_word fn_83179D30();
ts4_word fn_8317BF40();
ts4_word fn_8317CF18();
ts4_word fn_8317DA38();
ts4_word fn_83184ED8();
ts4_word fn_833E3A30();
ts4_word fn_833E3AD0();
ts4_word fn_833E4608();

/* Loader_DLL.xex 0x831404A0: call_seq fn_83140430, u32@0x4, u32@0x0 */
ts4_word ts4l_call_seq_fn_83140430_831404A0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_83140430((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)1;
    return t1;
}

/* Loader_DLL.xex 0x831404E8: call_seq fn_83140430, u32@0x4, u32@0x0 */
ts4_word ts4l_call_seq_fn_83140430_831404E8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_83140430((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)2;
    return t1;
}

/* Loader_DLL.xex 0x83140530: call_seq fn_83140430, u32@0x4, u32@0x0 */
ts4_word ts4l_call_seq_fn_83140430_83140530(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_83140430((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)3;
    return t1;
}

/* Loader_DLL.xex 0x831405C0: call_seq fn_83140430, u32@0x4, u32@0x0 */
ts4_word ts4l_call_seq_fn_83140430_831405C0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_83140430((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)6;
    return t1;
}

/* Loader_DLL.xex 0x831407F0: call_seq fn_83140430, u32@0x4, u32@0x0 */
ts4_word ts4l_call_seq_fn_83140430_831407F0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_83140430((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)9;
    return t1;
}

/* Loader_DLL.xex 0x8314E1A0: if_get  */
ts4_word ts4l_if_get_8314E1A0(ts4_word a0, ts4_word a1)
{
    float t1;
    float t2;
    float t3;
    float t4;
    float t5;
    float t6;

    t1 = *(float *)((char *)(ts4_word)(a1) + 0);
    t2 = *(float *)((char *)(ts4_word)(a0) + 0);
    if (!(t1 < t2)) {
        t3 = *(float *)((char *)(ts4_word)(a0) + 8);
        if (!(t1 > t3)) {
            t4 = *(float *)((char *)(ts4_word)(a1) + 4);
            t5 = *(float *)((char *)(ts4_word)(a0) + 4);
            if (!(t4 < t5)) {
                t6 = *(float *)((char *)(ts4_word)(a0) + 12);
                if (!(t4 > t6)) {
                    return 1;
                }
                return 0;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

/* Loader_DLL.xex 0x83150F98: if_get u32@0x48, u32@0x44, u32@0x44, u32@0x44, u32@0x48, u32@0x48 */
void ts4l_if_get_u32_off48_83150F98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 72);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 68) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 68));
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 68);
    if ((ts4_word)t4 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t4) + 72) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 72));
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((ts4_word)t7 == (ts4_word)a1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 68));
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t10 == (ts4_word)a1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 72));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 72) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83152DD0: set u16@0x0, u32@0x48, u32@0x4c, u32@0x50, u32@0x58, u8@0x54 */
void ts4l_set_u16_off0_83152DD0(ts4_word a0)
{
    float t1;

    *(unsigned short *)((char *)(ts4_word)(a0) + 0) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    t1 = *(float *)lbl_830009F8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 56) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 60) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 64) = t1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)0;
    *(float *)((char *)(ts4_word)(a0) + 68) = t1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 46) = (unsigned short)0;
    *(float *)((char *)(ts4_word)(a0) + 8) = t1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 48) = (unsigned short)0;
    *(float *)((char *)(ts4_word)(a0) + 12) = t1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 50) = (unsigned short)0;
    *(float *)((char *)(ts4_word)(a0) + 16) = t1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 52) = (unsigned short)0;
    *(float *)((char *)(ts4_word)(a0) + 20) = t1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 2) = (unsigned short)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 85) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 44) = (unsigned short)0;
    return;
}

/* Loader_DLL.xex 0x83153D88: if_get u32@0x1c, u32@0x1c, u32@0x18, u32@0x18, u32@0x18, u32@0xd4 */
void ts4l_if_get_u32_off1c_83153D88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t2;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 == 0) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 28);
    if ((ts4_word)t2 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    } else {
        *(ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    if ((ts4_word)t7 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t7) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 28) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a1) + 40) = (unsigned char)0;
    return;
}

/* Loader_DLL.xex 0x83153E08: if_get u32@0x0, u32@0x4, u32@0x4, u32@0x14, u32@0x4, u32@0x14 */
void ts4l_if_get_u32_off0_83153E08(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 == 0) {
        return;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    if ((ts4_word)t3 == (ts4_word)a1) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    if ((ts4_word)t6 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t6) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    if ((ts4_word)t9 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(t9) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    return;
}

/* Loader_DLL.xex 0x831548B0: set u16@0x0, u32@0x48, u32@0x4c, u32@0x50, u32@0x58, u8@0x54 */
void ts4l_set_u16_off0_831548B0(ts4_word a0)
{
    float t1;

    *(unsigned short *)((char *)(ts4_word)(a0) + 0) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    t1 = *(float *)lbl_830009F8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 56) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 60) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 64) = t1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)0;
    *(float *)((char *)(ts4_word)(a0) + 68) = t1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 46) = (unsigned short)0;
    *(float *)((char *)(ts4_word)(a0) + 8) = t1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 48) = (unsigned short)0;
    *(float *)((char *)(ts4_word)(a0) + 12) = t1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 50) = (unsigned short)0;
    *(float *)((char *)(ts4_word)(a0) + 16) = t1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 52) = (unsigned short)0;
    *(float *)((char *)(ts4_word)(a0) + 20) = t1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 2) = (unsigned short)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 85) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 44) = (unsigned short)0;
    return;
}

/* Loader_DLL.xex 0x83159330: if_call_seq u32@0x0, fn_830AF1B8, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off0_83159330(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p4 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        t2 = fn_830AF1B8((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x83159378: if_call_seq u32@0x0, fn_830AF1B8, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off0_83159378(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p4 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        t2 = fn_830AF1B8((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x831593C0: if_call_seq u32@0x0, fn_830AF1B8, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off0_831593C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p4 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        t2 = fn_830AF1B8((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x83159408: if_call_seq u32@0x0, fn_830AF1B8, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off0_83159408(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p4 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        t2 = fn_830AF1B8((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x83159748: if_call_seq u32@lbl_83531658, fn_830AF1B8, u32@lbl_83531658, u32@lbl_8353165C, fn_830AF1B8, u32@lbl_8353165C */
ts4_word ts4l_if_call_seq_u32_lbl_83531658_83159748(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_83531658;
    if ((ts4_word)t1 != 0) {
        fn_830AF1B8((ts4_word)t1);
        *(ts4_word *)lbl_83531658 = (ts4_word)0;
    }
    t4 = *(ts4_word *)lbl_8353165C;
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = fn_830AF1B8((ts4_word)t4);
        *(ts4_word *)lbl_8353165C = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x8315ADE0: if_call_seq u32@0x0, u32@0x0, fn_830AF1B8, u32@0x0, u32@0x4, fn_830AF1B8 */
ts4_word ts4l_if_call_seq_u32_off0_8315ADE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t2;
    ts4_word t5;
    ts4_word t8;
    ts4_word t11;
    ts4_word t14;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((ts4_word)t2 != 0) {
            fn_830AF1B8((ts4_word)t2);
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        }
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        if ((ts4_word)t5 != 0) {
            fn_830AF1B8((ts4_word)t5);
            *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        }
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t8 != 0) {
            fn_830AF1B8((ts4_word)t8);
            *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
        }
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        if ((ts4_word)t11 != 0) {
            fn_830AF1B8((ts4_word)t11);
            *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
        }
        t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        if ((ts4_word)t14 != 0) {
            fn_8314E0B8((ts4_word)t14);
        }
        fn_83120540((ts4_word)a0);
    }
    return 0;
}

/* Loader_DLL.xex 0x8315C8F0: if_call_seq u32@0xa8, fn_8314E408, u32@0xa8, fn_8315C708 */
ts4_word ts4l_if_call_seq_u32_offa8_8315C8F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
    if ((ts4_word)t1 != 0) {
        fn_8314E408((ts4_word)t1, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)0;
    }
    t4 = fn_8315C708((ts4_word)a0);
    return t4;
}

/* Loader_DLL.xex 0x8315E760: if_call_seq u32@0xc, fn_830AAAE8, u32@0xc, u32@0x8 */
ts4_word ts4l_if_call_seq_u32_offc_8315E760(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_830AAAE8((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return p3;
}

/* Loader_DLL.xex 0x8315F358: call_seq u32@0x4, fn_83162A98, u32@0x0 */
ts4_word ts4l_call_seq_u32_off4_8315F358(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    t1 = fn_83162A98((ts4_word)a1, (ts4_word)(a0 + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    return a0;
}

/* Loader_DLL.xex 0x8315F3A8: call_seq u32@0x4, fn_831618A0, u32@0x0 */
ts4_word ts4l_call_seq_u32_off4_8315F3A8(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;

    loc50[0] = (ts4_word)0;
    t2 = fn_831618A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(ts4_word)&loc50[0]);
    t3 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t2;
    return (t3 != 0);
}

/* Loader_DLL.xex 0x8315F468: if_call_seq u32@0x4, u32@0x4, fn_83161AE8, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off4_8315F468(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p2;
    ts4_word t3;

    (void)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    p2 = (ts4_word)0;
    if ((ts4_word)a1 != 0) {
        p2 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    }
    t3 = fn_83161AE8((ts4_word)p2, (ts4_word)a1, (ts4_word)a3, (ts4_word)a4, (ts4_word)(a0 + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
    return a0;
}

/* Loader_DLL.xex 0x8315F4D0: call_seq u32@0x4, u32@0x4, fn_83162DD0, u32@0x0 */
ts4_word ts4l_call_seq_u32_off4_8315F4D0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    t2 = fn_83162DD0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)), (ts4_word)(a0 + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t2;
    return a0;
}

/* Loader_DLL.xex 0x8315F6B8: if_call_seq u32@0x4, fn_83162D28, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off4_8315F6B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p2;
    ts4_word t3;

    if ((ts4_word)a3 != 0) {
        p2 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 4));
    } else {
        p2 = (ts4_word)0;
    }
    t3 = fn_83162D28((ts4_word)a1, (ts4_word)a2, (ts4_word)p2, (ts4_word)(a0 + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
    return a0;
}

/* Loader_DLL.xex 0x83161A88: if_call_seq u32@0x0, fn_83161840, u32@0x44, fn_83120540, fn_83165620 */
ts4_word ts4l_if_call_seq_u32_off0_83161A88(ts4_word a0)
{
    ts4_word t3;
    ts4_word t6;

    fn_83161840((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t3 != 0) {
        fn_83120540((ts4_word)t3);
    }
    t6 = fn_83165620((ts4_word)(a0 + 92));
    return t6;
}

/* Loader_DLL.xex 0x83162E58: call_seq u32@lbl_8352C070, fn_83162D10, u32@0x0, fn_83166248, fn_83166018, fn_833E4608 */
ts4_word ts4l_call_seq_u32_lbl_8352C070_83162E58(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[10];
    ts4_word t5;

    loc50[7] = (ts4_word)(*(ts4_word *)lbl_8352C070);
    fn_83162D10((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)a0;
    fn_83166248((ts4_word)(ts4_word)&loc50[0]);
    fn_83166018((ts4_word)(a1 + 4), (ts4_word)(ts4_word)&loc50[0]);
    t5 = loc50[7];
    fn_833E4608((ts4_word)t5);
    return 0;
}

/* Loader_DLL.xex 0x83162F50: if_call_seq u32@0x0, u32@0x0, fn_83162DF0, fn_83120540 */
ts4_word ts4l_if_call_seq_u32_off0_83162F50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((ts4_word)t2 != 0) {
            fn_83162DF0((ts4_word)t2);
        }
        fn_83120540((ts4_word)a0);
    }
    return 0;
}

/* Loader_DLL.xex 0x83163AE0: call_seq fn_833E3A30, u32@0x0, fn_83120518, u32@0x124, fn_831655F8, u32@0x198 */
ts4_word ts4l_call_seq_fn_833E3A30_83163AE0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;

    fn_833E3A30((ts4_word)a1, (ts4_word)0, (ts4_word)416);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)a0;
    t2 = fn_83120518((ts4_word)4096);
    *(ts4_word *)((char *)(ts4_word)(a1) + 292) = (ts4_word)t2;
    t3 = fn_831655F8((ts4_word)1, (ts4_word)(a1 + 384));
    *(ts4_word *)((char *)(ts4_word)(a1) + 408) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 412) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 296) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 300) = (ts4_word)0;
    return t3;
}

/* Loader_DLL.xex 0x83163B58: if_call_seq u32@0x124, fn_83120540, u32@0x124, fn_83165620, u32@0x198, fn_83120540 */
ts4_word ts4l_if_call_seq_u32_off124_83163B58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 292);
    if ((ts4_word)t1 != 0) {
        fn_83120540((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 292) = (ts4_word)0;
    }
    fn_83165620((ts4_word)(a0 + 384));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 408);
    if ((ts4_word)t5 != 0) {
        fn_83120540((ts4_word)t5);
        *(ts4_word *)((char *)(ts4_word)(a0) + 408) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 412) = (ts4_word)0;
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 296);
    p10 = (ts4_word)t8;
    if ((ts4_word)t8 != 0) {
        t9 = fn_83120540((ts4_word)t8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 296) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 300) = (ts4_word)0;
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Loader_DLL.xex 0x831662D0: loop_call_seq u32@0x8, u32@0x4, fn_83120540, fn_83120540 */
ts4_word ts4l_loop_call_seq_u32_off8_831662D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p6;
    ts4_word p7;
    ts4_word t2;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p7 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(lv1) + 8);
        fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 4)));
        t5 = fn_83120540((ts4_word)lv1);
        p6 = (ts4_word)t2;
        lv1 = p6;
        p7 = (ts4_word)t5;
    }
    return p7;
}

/* Loader_DLL.xex 0x83166328: loop_call_seq u32@0xc, u32@0x8, u32@0x4, fn_83120540, fn_83120540, u32@0x10 */
ts4_word ts4l_loop_call_seq_u32_offc_83166328(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv2;
    ts4_word p7;
    ts4_word p8;
    ts4_word lv11;
    ts4_word p16;
    ts4_word p17;
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t10;
    ts4_word t12;
    ts4_word t15;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p8 = (ts4_word)a0;
    lv2 = (ts4_word)t1;
    while ((ts4_word)lv2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(lv2) + 8);
        fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 4)));
        t6 = fn_83120540((ts4_word)lv2);
        p7 = (ts4_word)t3;
        lv2 = p7;
        p8 = (ts4_word)t6;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p17 = (ts4_word)p8;
    lv11 = (ts4_word)t10;
    while ((ts4_word)lv11 != 0) {
        t12 = *(ts4_word *)((char *)(ts4_word)(lv11) + 8);
        fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv11) + 4)));
        t15 = fn_83120540((ts4_word)lv11);
        p16 = (ts4_word)t12;
        lv11 = p16;
        p17 = (ts4_word)t15;
    }
    return p17;
}

/* Loader_DLL.xex 0x83166790: if_call_seq u32@lbl_8353168C, u32@lbl_8353168C, fn_83166680, u32@lbl_8353168C */
ts4_word ts4l_if_call_seq_u32_lbl_8353168C_83166790(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_8353168C;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)lbl_8353168C = (ts4_word)-1;
        t2 = fn_83166680((ts4_word)t1);
        *(ts4_word *)lbl_8353168C = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x83169F30: loop_set u16@0x0, u16@0x0, u16@0x0, u32@0x16a4, u32@0x16a0, u16@0x48c */
void ts4l_loop_set_u16_off0_83169F30(ts4_word a0)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;
    ts4_word c4;
    ts4_word lv5;
    ts4_word p6;
    ts4_word c7;
    ts4_word lv8;
    ts4_word p9;

    c1 = (ts4_word)286;
    lv2 = (ts4_word)(a0 + 136);
    do {
        *(unsigned short *)((char *)(ts4_word)((lv2 + 4)) + 0) = (unsigned short)0;
        p3 = (ts4_word)(lv2 + 4);
        lv2 = p3;
    } while (--c1 != 0);
    c4 = (ts4_word)30;
    lv5 = (ts4_word)(a0 + 2428);
    do {
        *(unsigned short *)((char *)(ts4_word)((lv5 + 4)) + 0) = (unsigned short)0;
        p6 = (ts4_word)(lv5 + 4);
        lv5 = p6;
    } while (--c4 != 0);
    c7 = (ts4_word)19;
    lv8 = (ts4_word)(a0 + 2672);
    do {
        *(unsigned short *)((char *)(ts4_word)((lv8 + 4)) + 0) = (unsigned short)0;
        p9 = (ts4_word)(lv8 + 4);
        lv8 = p9;
    } while (--c7 != 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 5796) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 5792) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 1164) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 5800) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 5784) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8316F2A0: if_call_seq u32@0x20, lbl_830080C4, u32@0x0, RtlEnterCriticalSection, RtlLeaveCriticalSection */
ts4_word ts4l_if_call_seq_u32_off20_8316F2A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p4;
    int t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830080C4;
    p4 = (ts4_word)a0;
    if ((int)t1 != 0) {
        RtlEnterCriticalSection((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t1);
        t3 = RtlLeaveCriticalSection((ts4_word)(a0 + 4));
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x8317A058: if_call_seq u32@0x25c, u32@0x288, fn_83179690, fn_83179D30, u32@0x260, u32@0x288 */
ts4_word ts4l_if_call_seq_u32_off25c_8317A058(ts4_word a0)
{
    ts4_word p7;
    ts4_word p13;
    ts4_word p14;
    int t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t10;
    ts4_word t12;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 604);
    if ((int)t1 != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 648);
        if ((ts4_word)t5 != 0) {
            p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 0));
        } else {
            p7 = (ts4_word)0;
        }
        t8 = *(ts4_word *)((char *)(ts4_word)(p7) + 20);
        if ((ts4_word)t8 != 255) {
            *(ts4_word *)((char *)(ts4_word)(p7) + 20) = (ts4_word)(t8 + -1);
        }
        t10 = *(ts4_word *)((char *)(ts4_word)(p7) + 0);
        t12 = fn_83174D10((ts4_word)(a0 + 140), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(p7) + 24)), (ts4_word)t10);
        p13 = (ts4_word)t12;
        p14 = (ts4_word)0;
    } else {
        t3 = fn_83179690((ts4_word)(a0 + 624));
        t4 = fn_83179D30((ts4_word)(a0 + 664), (ts4_word)t3);
        *(ts4_word *)((char *)(ts4_word)(a0) + 608) = (ts4_word)0;
        p13 = (ts4_word)t4;
        p14 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 452) = (ts4_word)p14;
    *(ts4_word *)((char *)(ts4_word)(a0) + 456) = (ts4_word)p14;
    *(ts4_word *)((char *)(ts4_word)(a0) + 464) = (ts4_word)p14;
    return p13;
}

/* Loader_DLL.xex 0x8317D2E0: call_seq fn_8317BF40, fn_8317BF40, u32@0xf8, u32@0xfc, u32@0x100, u32@0x104 */
ts4_word ts4l_call_seq_fn_8317BF40_8317D2E0(ts4_word a0, ts4_word a1)
{
    fn_8317BF40((ts4_word)a0);
    fn_8317BF40((ts4_word)(a0 + 124));
    *(ts4_word *)((char *)(ts4_word)(a0) + 248) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 252) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 256) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 260) = (ts4_word)0;
    return a0;
}

/* Loader_DLL.xex 0x8317DB48: if_call_seq fn_83174C98, fn_8317CF18, fn_8317DA38, u32@0x14c, fn_83178920 */
ts4_word ts4l_if_call_seq_fn_83174C98_8317DB48(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t6;

    fn_83174C98((ts4_word)a0, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)a2 != 0) {
        fn_8317CF18((ts4_word)(a0 + -140), (ts4_word)a1, (ts4_word)a2);
    }
    fn_8317DA38((ts4_word)(a0 + -140));
    t6 = fn_83178920((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 332)));
    return t6;
}

/* Loader_DLL.xex 0x8317E1A8: if_call_seq u16@0x0, u32@0x0, u16@0x10, u32@0x0, u16@0x0, u16@0x10 */
ts4_word ts4l_if_call_seq_u16_off0_8317E1A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word p9;
    ts4_word p11;
    unsigned short t1;
    ts4_word t2;
    unsigned short t6;
    ts4_word t13;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((ts4_word)t1 == 357) {
        p5 = (ts4_word)32;
    } else {
        if ((ts4_word)t1 == 1) {
            p4 = (ts4_word)18;
        } else {
            p4 = (ts4_word)((*(unsigned short *)((char *)(ts4_word)(a0) + 16)) + 18);
        }
        p5 = (ts4_word)p4;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)p5;
    t6 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t6 == 357) {
        p11 = (ts4_word)32;
    } else {
        if ((ts4_word)t6 == 1) {
            p9 = (ts4_word)16;
        } else {
            p9 = (ts4_word)((*(unsigned short *)((char *)(ts4_word)(a0) + 16)) + 18);
        }
        p11 = (ts4_word)p9;
    }
    fn_833E3AD0((ts4_word)a1, (ts4_word)a0, (ts4_word)p11);
    t13 = fn_833E3A30((ts4_word)(p11 + a1), (ts4_word)0, (ts4_word)(t2 - p11));
    return t13;
}

/* Loader_DLL.xex 0x831808E8: call_seq RtlEnterCriticalSection, u32@0x20, KeSetEvent, RtlLeaveCriticalSection */
ts4_word ts4l_call_seq_RtlEnterCriticalSection_831808E8(ts4_word a0)
{
    ts4_word t4;

    RtlEnterCriticalSection((ts4_word)(a0 + 36));
    KeSetEvent((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)), (ts4_word)1, (ts4_word)0);
    t4 = RtlLeaveCriticalSection((ts4_word)(a0 + 36));
    return t4;
}

/* Loader_DLL.xex 0x83185C28: if_call_seq fn_833E3A30, u32@0xd0, u32@0xb8, u32@0xbc, u32@0xc0, u32@0xc4 */
ts4_word ts4l_if_call_seq_fn_833E3A30_83185C28(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;
    ts4_word t8;
    ts4_word t11;
    ts4_word t14;
    ts4_word t17;
    ts4_word t20;
    ts4_word t23;
    ts4_word t27;

    fn_833E3A30((ts4_word)(a0 + 36), (ts4_word)0, (ts4_word)40);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 208);
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 196) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 220) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 232) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 236) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 240) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 244) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 248) = (ts4_word)0;
    if ((ts4_word)t2 != 0) {
        fn_83184ED8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)0;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 212);
    if ((ts4_word)t5 != 0) {
        fn_83184ED8((ts4_word)t5);
        *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)0;
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 216);
    if ((ts4_word)t8 != 0) {
        fn_83184ED8((ts4_word)t8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 216) = (ts4_word)0;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t11 != 0) {
        fn_83184ED8((ts4_word)t11);
        *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    if ((ts4_word)t14 != 0) {
        fn_83184ED8((ts4_word)t14);
        *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    }
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    if ((ts4_word)t17 != 0) {
        fn_83184ED8((ts4_word)t17);
        *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    }
    t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 152);
    if ((ts4_word)t20 != 0) {
        fn_83184ED8((ts4_word)t20);
        *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)0;
    }
    t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
    if ((ts4_word)t23 != 0) {
        fn_83184ED8((ts4_word)t23);
        *(ts4_word *)((char *)(ts4_word)(a0) + 176) = (ts4_word)0;
    }
    fn_833E3A30((ts4_word)(a0 + 76), (ts4_word)0, (ts4_word)36);
    t27 = fn_833E3A30((ts4_word)(a0 + 112), (ts4_word)0, (ts4_word)72);
    return t27;
}
