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

extern char lbl_8803CB5C[];
extern char lbl_8803DE18[];
extern char lbl_8803DE28[];
extern char lbl_8803F9E8[];
extern char lbl_8803FC80[];
extern char lbl_8803FCA0[];
extern char lbl_88040CE8[];
extern char lbl_88040CF8[];
extern char lbl_88040D08[];
extern char lbl_88040D18[];
extern char lbl_88041554[];
extern char lbl_88041928[];
extern char lbl_88041AA4[];
extern char lbl_88041AE8[];
extern char lbl_88042C0C[];
extern char lbl_8804375C[];
extern char lbl_88043778[];
extern char lbl_88043788[];
extern char lbl_8804379C[];
extern char lbl_880437AC[];
extern char lbl_880D98CC[];
extern char lbl_880D98E0[];
extern char lbl_880E1DE4[];
extern char lbl_880F10A0[];
extern char lbl_88D45B1C[];
extern char lbl_88D4DAD8[];
ts4_word XNetLogonGetTitleID();
ts4_word fn_881C31D0();
ts4_word fn_881CECD0();
ts4_word fn_88321A38();
ts4_word fn_88382FB0();
ts4_word fn_88426178();
ts4_word fn_88431250();
ts4_word fn_884F1E18();
ts4_word fn_88580EB8();
ts4_word fn_885E75E0();
ts4_word fn_885E76A0();
ts4_word fn_885E76C0();
ts4_word fn_8862C0E8();
ts4_word fn_886A0EC8();
ts4_word fn_886B6448();
ts4_word fn_887013A8();
ts4_word fn_88907570();
ts4_word ts4_acquire_item_88200D60();
ts4_word ts4_assign_text_from_c_string();
ts4_word ts4_call_seq_fn_88428B48_88433568();
ts4_word ts4_call_seq_u32_off0_8819AD80();
ts4_word ts4_call_with_header_word_885690C8();
ts4_word ts4_find_entry_by_name_884278D0();
ts4_word ts4_get_fn_8864F6E8_88650C70();
ts4_word ts4_get_u32_lbl_88D4E11C_88581A90();
ts4_word ts4_get_u32_off0_88428980();
ts4_word ts4_get_u32_off0_884289A8();
ts4_word ts4_get_u32_off0_884289C8();
ts4_word ts4_get_u32_off0_88428A18();
ts4_word ts4_get_u32_off0_88428B30();
ts4_word ts4_get_u32_off4_88428AC0();
ts4_word ts4_get_u32_off7c_8846AA28();
ts4_word ts4_get_u32_off8_88426140();
ts4_word ts4_get_u32_off8_885E7620();
ts4_word ts4_get_u32_off8_885E7640();
ts4_word ts4_handle_forward_88150770();
ts4_word ts4_handle_forward_88610A48();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word ts4_if_call_seq_u32_off0_881FFDC0();
ts4_word ts4_if_call_seq_u32_off4_88428890();
ts4_word ts4_if_get_u32_off0_8816CE90();
ts4_word ts4_index_u16_array_at_field0_884289F8();
ts4_word ts4_tailcall_MmFreePhysicalMemory_8857B158();
ts4_word ts4_tailcall_memcpy_88421450();

/* Swing_DLL.xex 0x881FFD28: if_call_seq ts4_if_call_seq_u32_off0_881FFDC0, ts4_acquire_item_88200D60, u32@0x0, ts4_if_atomic_interlocked_dec_881876D0, ts4_acquire_item_88200D60, u32@0x0 */
void ts4_if_call_seq_ts4_if_call_seq_u32_off0_881FFDC0_881FFD28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t12;

    ts4_if_call_seq_u32_off0_881FFDC0((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
    t2 = ts4_acquire_item_88200D60((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a3);
    t3 = loc50[0];
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    if ((ts4_word)t3 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t3);
        loc50[0] = (ts4_word)0;
    }
    if ((ts4_word)t4 != 0) {
        fn_881C31D0((ts4_word)(fn_881CECD0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_acquire_item_88200D60((ts4_word)(ts4_word)&loc54[0], (ts4_word)a0, (ts4_word)a3))) + 0)))), (ts4_word)a2, (ts4_word)0);
        t12 = loc54[0];
        if ((ts4_word)t12 != 0) {
            ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t12);
        }
    }
    return;
}

/* Swing_DLL.xex 0x883295F0: call_seq fn_88382FB0, fn_88321A38 */
void ts4_call_seq_fn_88382FB0_883295F0(ts4_word a0)
{

    fn_88321A38((ts4_word)a0, (ts4_word)(fn_88382FB0()), (ts4_word)0);
    return;
}

/* Swing_DLL.xex 0x8841D598: if_set u32@0x8, lbl_8803DE18, u16@0x6, u32@0x0, u16@0x4, u16@0x4 */
void ts4_if_set_u32_off8_8841D598(ts4_word a0, ts4_word a1)
{
    unsigned short t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803DE18;
    if ((ts4_word)a1 == 0) {
        return;
    }
    t2 = *(unsigned short *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t2 == 0) {
        return;
    }
    *(short *)((char *)(ts4_word)(a1) + 6) = (short)((*(short *)((char *)(ts4_word)(a1) + 6)) + 1);
    return;
}

/* Swing_DLL.xex 0x8841E468: if_set u32@0x8, lbl_8803DE28, u16@0x6, u32@0x0, u16@0x4, u16@0x6 */
void ts4_if_set_u32_off8_8841E468(ts4_word a0, ts4_word a1)
{
    unsigned short t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803DE28;
    t1 = *(unsigned short *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(short *)((char *)(ts4_word)(a1) + 6) = (short)((*(short *)((char *)(ts4_word)(a1) + 6)) + 1);
    return;
}

/* Swing_DLL.xex 0x8842DCA0: if_call_seq u32@0x4, lbl_8803FC80, fn_88431250, u8@0x0, u32@0x4, lbl_8803F9E8 */
void ts4_if_call_seq_u32_off4_8842DCA0(ts4_word a0, ts4_word a1)
{
    ts4_word p10;
    ts4_word p13;
    ts4_word p16;
    ts4_word loc50[1];
    ts4_word loc60[2];
    ts4_word loc58[2];
    ts4_word loc54[1];
    ts4_word loc68[2];
    ts4_word t2;
    unsigned char t3;
    ts4_word t5;
    unsigned char t6;
    ts4_word t8;
    unsigned char t9;
    ts4_word t22;
    ts4_word t24;

    t2 = fn_88431250((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(ts4_word)lbl_8803FC80);
    t3 = *(unsigned char *)((char *)(ts4_word)(t2) + 0);
    if ((ts4_word)t3 != 0) {
        p16 = (ts4_word)(ts4_word)lbl_88040D18;
    } else {
        t5 = fn_88431250((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(ts4_word)lbl_8803F9E8);
        t6 = *(unsigned char *)((char *)(ts4_word)(t5) + 0);
        if ((ts4_word)t6 != 0) {
            p13 = (ts4_word)(ts4_word)lbl_88040D08;
        } else {
            t8 = fn_88431250((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(ts4_word)lbl_8803FCA0);
            t9 = *(unsigned char *)((char *)(ts4_word)(t8) + 0);
            if ((ts4_word)t9 != 0) {
                p10 = (ts4_word)(ts4_word)lbl_88040CF8;
            } else {
                p10 = (ts4_word)(ts4_word)lbl_88040CE8;
            }
            p13 = (ts4_word)p10;
        }
        p16 = (ts4_word)p13;
    }
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_get_u32_off0_88428B30((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1)), (ts4_word)(ts4_word)lbl_880E1DE4);
    ts4_find_entry_by_name_884278D0((ts4_word)(ts4_get_u32_off8_88426140((ts4_word)(ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&loc58[0])))), (ts4_word)p16, (ts4_word)(ts4_word)&loc54[0]);
    t22 = loc54[0];
    t24 = ts4_get_u32_off0_88428A18((ts4_word)(ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc68[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_880E1DE4)), (ts4_word)0);
    *(unsigned char *)((char *)(ts4_word)(t24) + 0) = (unsigned char)t22;
    return;
}

/* Swing_DLL.xex 0x88433330: if_call_seq lbl_8803CB5C, ts4_if_call_seq_u32_off4_88428890, lbl_88042C0C, ts4_if_call_seq_u32_off4_88428890, lbl_88041554, ts4_if_call_seq_u32_off4_88428890 */
void ts4_if_call_seq_lbl_8803CB5C_88433330(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc60[4];
    ts4_word t4;
    unsigned char t5;
    ts4_word t6;
    ts4_word t9;
    unsigned char t10;
    ts4_word t11;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803CB5C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88042C0C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041554);
    t4 = ts4_get_u32_off0_884289A8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    t5 = *(unsigned char *)((char *)(ts4_word)(t4) + 0);
    if ((ts4_word)t5 != 0) {
        t6 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
        *(short *)((char *)(ts4_word)(t6) + 0) = (short)((*(short *)((char *)(ts4_word)(t6) + 0)) | 1);
    }
    t9 = ts4_get_u32_off0_884289A8((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
    t10 = *(unsigned char *)((char *)(ts4_word)(t9) + 0);
    if ((ts4_word)t10 != 0) {
        t11 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
        *(short *)((char *)(ts4_word)(t11) + 0) = (short)((*(short *)((char *)(ts4_word)(t11) + 0)) | 2);
    }
    return;
}

/* Swing_DLL.xex 0x884335F8: call_seq lbl_88041928, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_call_seq_fn_88428B48_88433568 */
void ts4_call_seq_lbl_88041928_884335F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word loc58[3];

    ts4_call_seq_fn_88428B48_88433568((ts4_word)(ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041928)), (ts4_word)(ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041928)), (ts4_word)a2);
    return;
}

/* Swing_DLL.xex 0x88433648: call_seq lbl_88041928, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_call_seq_fn_88428B48_88433568 */
void ts4_call_seq_lbl_88041928_88433648(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word loc58[3];

    ts4_call_seq_fn_88428B48_88433568((ts4_word)(ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041928)), (ts4_word)(ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041928)), (ts4_word)a2);
    return;
}

/* Swing_DLL.xex 0x884342A0: call_seq lbl_88041AA4, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off4_88428AC0, fn_88426178, ts4_get_u32_off0_88428980 */
void ts4_call_seq_lbl_88041AA4_884342A0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041AA4);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041AA4);
    ts4_tailcall_memcpy_88421450((ts4_word)(ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&loc58[0])), (ts4_word)(ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&loc50[0])), (ts4_word)(fn_88426178((ts4_word)(ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&loc50[0])))));
    return;
}

/* Swing_DLL.xex 0x88434328: if_call_seq lbl_880437AC, ts4_if_call_seq_u32_off4_88428890, lbl_8804379C, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_884289C8, ts4_get_u32_off0_884289C8 */
void ts4_if_call_seq_lbl_880437AC_88434328(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc60[4];
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    unsigned char t9;
    ts4_word t15;
    ts4_word t11;
    unsigned char t12;
    ts4_word t13;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880437AC);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8804379C);
    t3 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88043788);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88043778);
    t8 = ts4_get_u32_off0_884289A8((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
    t9 = *(unsigned char *)((char *)(ts4_word)(t8) + 0);
    if ((ts4_word)t9 != 0) {
        t15 = ts4_get_u32_off0_88428A18((ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)t9);
        *(unsigned char *)((char *)(ts4_word)(t15) + 0) = (unsigned char)3;
    } else {
        ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8804375C);
        t11 = ts4_get_u32_off0_884289A8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
        t12 = *(unsigned char *)((char *)(ts4_word)(t11) + 0);
        if ((ts4_word)t12 == 0) {
            t13 = ts4_get_u32_off0_88428A18((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
            *(unsigned char *)((char *)(ts4_word)(t13) + 0) = (unsigned char)1;
        }
    }
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041AE8);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041AE8);
    ts4_tailcall_memcpy_88421450((ts4_word)(ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&loc60[0])), (ts4_word)(ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&loc50[0])), (ts4_word)(fn_88426178((ts4_word)(ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&loc50[0])))));
    return;
}

/* Swing_DLL.xex 0x884352E8: if_call_seq lbl_8803CB5C, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_index_u16_array_at_field0_884289F8, ts4_index_u16_array_at_field0_884289F8, u16@0x0 */
void ts4_if_call_seq_lbl_8803CB5C_884352E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc58[2];
    ts4_word loc50[2];
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803CB5C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803CB5C);
    t3 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    t4 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    *(short *)((char *)(ts4_word)(t4) + 0) = (short)(*(short *)((char *)(ts4_word)(t3) + 0));
    if ((ts4_word)(a2 & 0xff) != 0) {
        t6 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
        *(short *)((char *)(ts4_word)(t6) + 0) = (short)((*(short *)((char *)(ts4_word)(t6) + 0)) | 2048);
    }
    return;
}

/* Swing_DLL.xex 0x88475AE8: if_get u16@0x4, u16@0x6, u16@0x6 */
void ts4_if_get_u16_off4_88475AE8(ts4_word a0)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(short *)((char *)(ts4_word)(a0) + 6) = (short)((*(short *)((char *)(ts4_word)(a0) + 6)) + 1);
    return;
}

/* Swing_DLL.xex 0x88475D10: if_call_seq u32@0x8, u32@0x84, u16@0x4, u16@0x6, u16@0x6, ts4_get_u32_off7c_8846AA28 */
void ts4_if_call_seq_u32_off8_88475D10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[2];
    int t1;
    unsigned short t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 132)) != 0) {
        loc50[1] = (ts4_word)a0;
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)29;
        ts4_get_u32_off7c_8846AA28((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        return;
    }
    t3 = *(unsigned short *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t3 != 0) {
        *(short *)((char *)(ts4_word)(a0) + 6) = (short)((*(short *)((char *)(ts4_word)(a0) + 6)) + 1);
    }
    return;
}

/* Swing_DLL.xex 0x884893D8: if_get u16@0x4, u16@0x6, u16@0x6 */
void ts4_if_get_u16_off4_884893D8(ts4_word a0)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(short *)((char *)(ts4_word)(a0) + 6) = (short)((*(short *)((char *)(ts4_word)(a0) + 6)) + 1);
    return;
}

/* Swing_DLL.xex 0x884D4C48: loop_call_seq fn_885E75E0, fn_885E76A0, ts4_get_u32_off8_885E7620, ts4_get_u32_off8_885E7640, fn_885E76C0, fn_885E76C0 */
void ts4_loop_call_seq_fn_885E75E0_884D4C48(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;

    t1 = fn_885E75E0((ts4_word)a1);
    fn_885E76A0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)t1);
    t3 = *(signed char *)((char *)loc50 + 0);
    if ((ts4_word)t3 != 0) {
        do {
            t4 = ts4_get_u32_off8_885E7620((ts4_word)a1, (ts4_word)t1);
            t5 = ts4_get_u32_off8_885E7640((ts4_word)a1, (ts4_word)t1);
            fn_885E76C0((ts4_word)(a0 + 44), (ts4_word)t4, (ts4_word)t5);
            fn_885E76C0((ts4_word)(a0 + 60), (ts4_word)t5, (ts4_word)t4);
            fn_885E76A0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)t1);
            t9 = *(signed char *)((char *)loc50 + 0);
        } while ((ts4_word)t9 != 0);
    }
    return;
}

/* Swing_DLL.xex 0x884F1EE8: call_seq XNetLogonGetTitleID, fn_884F1E18 */
void ts4_call_seq_XNetLogonGetTitleID_884F1EE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{

    fn_884F1E18((ts4_word)a0, (ts4_word)(XNetLogonGetTitleID((ts4_word)9)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    return;
}

/* Swing_DLL.xex 0x88652DC8: get fn_88650C70, ts4_handle_forward_88610A48, ts4_handle_forward_88150770, u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_fn_88650C70_88652DC8(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word loc58[3];
    ts4_word loc68[3];
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;

    (void)sp1.w[2];
    ts4_get_fn_8864F6E8_88650C70((ts4_word)a0, sp1);
    loc54[0] = (ts4_word)((3702915072) | 30512);
    loc50[0] = (ts4_word)((1020264448) | 27500);
    t4 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_handle_forward_88610A48((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0])), (ts4_word)(ts4_word)&loc54[0]);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 0);
    t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
    t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 40))))((ts4_word)t5, (ts4_word)t4, (ts4_word)t6, (ts4_word)4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t9;
    return;
}

/* Swing_DLL.xex 0x886BB698: if_call_seq u32@0x1c, u8@0x10, u32@0x50, u32@0x28, fn_886A0EC8, fn_886B6448 */
void ts4_if_call_seq_u32_off1c_886BB698(ts4_word a0)
{
    ts4_word t1;
    unsigned char t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 16);
    if ((ts4_word)t2 == 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 80);
        t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 40);
        fn_886B6448((ts4_word)((fn_886A0EC8((ts4_word)t3)) + 36), (ts4_word)(a0 + 80), (ts4_word)t1, (ts4_word)t4);
    }
    return;
}

/* Swing_DLL.xex 0x88727058: addr lbl_880F10A0, fn_8862C0E8, ts4_handle_forward_88610A48, ts4_handle_forward_88150770, u32@0x0, u32@0x28 */
void ts4_addr_lbl_880F10A0_88727058(void)
{
    ts4_word loc68[3];
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word loc78[3];
    ts4_word loc58[3];
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;

    fn_8862C0E8((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)lbl_880F10A0);
    loc54[0] = (ts4_word)((4094427136) | 52484);
    loc50[0] = (ts4_word)((3734700032) | 61892);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_handle_forward_88610A48((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc50[0])), (ts4_word)(ts4_word)&loc54[0]);
    t4 = loc58[0];
    t5 = loc58[1];
    t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 40))))((ts4_word)t4, (ts4_word)(ts4_word)&loc58[0], (ts4_word)t5, (ts4_word)1);
    *(unsigned char *)((char *)(ts4_word)(t8) + 0) = (unsigned char)0;
    fn_887013A8((ts4_word)0);
    return;
}

/* Swing_DLL.xex 0x88884200: if_call_seq ts4_tailcall_MmFreePhysicalMemory_8857B158, ts4_get_u32_lbl_88D4E11C_88581A90, fn_88580EB8, ts4_call_with_header_word_885690C8 */
void ts4_if_call_seq_ts4_tailcall_MmFreePhysicalMemory_8857B158_88884200(ts4_word a0, int a1, int a2)
{

    if ((int)a1 == 0) {
        if ((int)a2 > 0) {
            ts4_call_with_header_word_885690C8((ts4_word)a0);
            return;
        }
        fn_88580EB8((ts4_word)(ts4_get_u32_lbl_88D4E11C_88581A90()), (ts4_word)0, (ts4_word)a0);
        return;
    }
    ts4_tailcall_MmFreePhysicalMemory_8857B158((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x88907390: if_call_seq u8@0x2c4, fn_881CECD0, fn_881C31D0 */
void ts4_if_call_seq_u8_off2c4_88907390(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 708);
    if ((ts4_word)t1 != 0) {
        fn_881C31D0((ts4_word)(fn_881CECD0((ts4_word)a1)), (ts4_word)a2, (ts4_word)0);
    }
    return;
}

/* Swing_DLL.xex 0x88908710: if_call_seq u32@0x18, u32@0x10, u32@0x58, lbl_880D98CC, fn_88907570, lbl_880D98E0 */
void ts4_if_call_seq_u32_off18_88908710(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    int t1;
    ts4_word t2;
    unsigned char t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
        fn_88907570((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 88)), (ts4_word)(ts4_word)lbl_880D98CC, (ts4_word)t2);
        ts4_assign_text_from_c_string((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D98E0);
        t6 = *(unsigned char *)((char *)(ts4_word)(a0) + 708);
        t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 92);
        if ((ts4_word)t6 != 0) {
            fn_881C31D0((ts4_word)(fn_881CECD0((ts4_word)t7)), (ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
        }
        ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc50[0]);
        *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x88913860: if_call_seq ts4_handle_forward_88150770, ts4_if_get_u32_off0_8816CE90, u32@lbl_88D45B1C, u32@0x234, u32@0x34, u32@0x1c */
void ts4_if_call_seq_ts4_handle_forward_88150770_88913860(ts4_word a0, ts4_args3 sp1)
{
    ts4_word p10;
    ts4_word p11;
    ts4_word loc50[2];
    ts4_word loc58[3];
    int t2;
    ts4_word t4;
    int t5;
    int t8;

    loc50[0] = (ts4_word)((3951886336) | 31247);
    t2 = ts4_if_get_u32_off0_8816CE90((ts4_word)(ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0])));
    t4 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 52);
    if ((int)t2 < (int)t5) {
        t8 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 48))) + (t2 << 2));
        p10 = (ts4_word)t8;
        if ((int)t8 == -1) {
            p10 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 28));
        }
        p11 = (ts4_word)p10;
    } else {
        p11 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 28));
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(((int)p11 * 196) + (*(ts4_word *)((char *)(ts4_word)(t4) + 60)));
    return;
}

/* Swing_DLL.xex 0x889D1A88: loop_call_seq u32@lbl_88D4DAD8, u32@0x1c, ts4_get_u32_lbl_88D4E11C_88581A90, fn_88580EB8, u32@lbl_88D4DAD8 */
void ts4_loop_call_seq_u32_lbl_88D4DAD8_889D1A88(ts4_word a0)
{
    ts4_word lv2;
    ts4_word p6;
    ts4_word t3;

    (void)a0;
    lv2 = (ts4_word)(*(ts4_word *)lbl_88D4DAD8);
    while ((ts4_word)lv2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(lv2) + 28);
        fn_88580EB8((ts4_word)(ts4_get_u32_lbl_88D4E11C_88581A90()), (ts4_word)0, (ts4_word)lv2);
        p6 = (ts4_word)t3;
        lv2 = p6;
    }
    *(ts4_word *)lbl_88D4DAD8 = (ts4_word)0;
    return;
}
