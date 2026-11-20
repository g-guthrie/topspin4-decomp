/* Loader_DLL.xex 0x832272F0-0x834009C8, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char fn_833F9998[];
extern char lbl_8300C968[];
extern char lbl_8302B4E0[];
extern char lbl_8302B968[];
extern char lbl_8305091C[];
extern char lbl_830522C8[];
extern char lbl_8306EF68[];
extern char lbl_8306F7D8[];
extern char lbl_8352C070[];
extern char lbl_8352C230[];
extern char lbl_8352C3D0[];
extern char lbl_8352CA04[];
extern char lbl_8352CD4C[];
extern char lbl_8352CD50[];
extern char lbl_8352CDB0[];
extern char lbl_83542C30[];
extern char lbl_83542C54[];
extern char lbl_83542CB0[];
extern char lbl_83542CB8[];
extern char lbl_83542CBC[];
extern char lbl_83542D60[];
extern char lbl_83543658[];
extern char lbl_835437C0[];
extern char lbl_83543A0C[];
extern char lbl_83543A14[];
extern char lbl_83543A34[];
extern char lbl_83543A38[];
extern char lbl_83543A44[];
extern char lbl_83544688[];
extern char lbl_8354468C[];
extern char lbl_835446E8[];
extern char lbl_8354B964[];
ts4_word KeBugCheck();
ts4_word KeTlsGetValue();
ts4_word KeTlsSetValue();
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_830E1C48();
ts4_word fn_83227008();
ts4_word fn_83231640();
ts4_word fn_83275698();
ts4_word fn_832863B0();
ts4_word fn_833541A0();
ts4_word fn_8335B4F8();
ts4_word fn_8336F310();
ts4_word fn_83397508();
ts4_word fn_8339BD30();
ts4_word fn_833A0010();
ts4_word fn_833C4190();
ts4_word fn_833C5798();
ts4_word fn_833C58C8();
ts4_word fn_833C61A0();
ts4_word fn_833C6360();
ts4_word fn_833CF9A8();
ts4_word fn_833D29E8();
ts4_word fn_833DF630();
ts4_word fn_833DFA98();
ts4_word fn_833DFC48();
ts4_word fn_833DFD38();
ts4_word fn_833DFFB0();
ts4_word fn_833E0048();
ts4_word fn_833E00B8();
ts4_word fn_833E0120();
ts4_word fn_833E0188();
ts4_word fn_833E03C8();
ts4_word fn_833E0AB0();
ts4_word fn_833E0D28();
ts4_word fn_833E1758();
ts4_word fn_833E2510();
ts4_word fn_833E25B8();
ts4_word fn_833E2998();
ts4_word fn_833E31E0();
ts4_word fn_833E3298();
ts4_word fn_833E3A30();
ts4_word fn_833E4DE0();
ts4_word fn_833E4F78();
ts4_word fn_833E5288();
ts4_word fn_833E53C0();
ts4_word fn_833E5838();
ts4_word fn_833E5B90();
ts4_word fn_833E5C38();
ts4_word fn_833E6748();
ts4_word fn_833E7E48();
ts4_word fn_833E8038();
ts4_word fn_833E8428();
ts4_word fn_833E8528();
ts4_word fn_833E87A8();
ts4_word fn_833E89B0();
ts4_word fn_833E8A28();
ts4_word fn_833EA200();
ts4_word fn_833EB108();
ts4_word fn_833F08C8();
ts4_word fn_833F13E0();
ts4_word fn_833F1420();
ts4_word fn_833F1488();
ts4_word fn_833F1760();
ts4_word fn_833F1768();
ts4_word fn_833F1780();
ts4_word fn_833F1A40();
ts4_word fn_833F1A48();
ts4_word fn_833F1A90();
ts4_word fn_833F1B30();
ts4_word fn_833F1C00();
ts4_word fn_833F1F08();
ts4_word fn_833F2000();
ts4_word fn_833F25C8();
ts4_word fn_833F26A0();
ts4_word fn_833F4E58();
ts4_word fn_833F5188();
ts4_word fn_833F8398();
ts4_word fn_833F8EC8();
ts4_word fn_833F9160();
ts4_word fn_833F92A0();
ts4_word fn_833F9420();
ts4_word fn_833F9520();
ts4_word fn_833F9FC8();
ts4_word fn_833FA078();
ts4_word fn_833FA478();
ts4_word fn_833FAC70();
ts4_word fn_833FACF0();
ts4_word fn_833FAF30();
ts4_word fn_833FAF88();
ts4_word fn_833FB038();
ts4_word fn_833FB0E8();
ts4_word fn_833FB560();
ts4_word fn_833FB7E0();
ts4_word fn_833FB8C8();
ts4_word fn_833FBC80();
ts4_word fn_833FBF60();
ts4_word fn_833FFC28();
ts4_word fn_8340C4F8();
ts4_word fn_8340D860();
ts4_word fn_834D38D8();

/* Loader_DLL.xex 0x832272F0: addr lbl_8302B4E0, u32@0x0, fn_83227008 */
ts4_word ts4_addr_lbl_8302B4E0_832272F0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302B4E0;
    return fn_83227008((ts4_word)a0);
}

/* Loader_DLL.xex 0x832333B8: call_seq lbl_8302B968, u32@0x0, fn_83231640, fn_83227008 */
ts4_word ts4_call_seq_lbl_8302B968_832333B8(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8302B968;
    fn_83231640((ts4_word)a0);
    t2 = fn_83227008((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x83236198: tailcall fn_83227008 */
ts4_word ts4_tailcall_fn_83227008_83236198(ts4_word a0)
{
    return fn_83227008((ts4_word)a0);
}

/* Loader_DLL.xex 0x8328B5B0: tailcall fn_832863B0 */
ts4_word ts4_tailcall_fn_832863B0_8328B5B0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_832863B0((ts4_word)a1);
}

/* Loader_DLL.xex 0x8328B5B8: if_get u32@0x3c, fn_832863B0, fn_83275698 */
ts4_word ts4_if_get_u32_off3c_8328B5B8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t1 != 0) {
        return fn_83275698((ts4_word)(a0 + 52), (ts4_word)a1);
    }
    return fn_832863B0((ts4_word)a1);
}

/* Loader_DLL.xex 0x83354340: call_seq fn_833541A0 */
ts4_word ts4_call_seq_fn_833541A0_83354340(void)
{
    ts4_word t1;

    t1 = fn_833541A0();
    return (t1 + 12);
}

/* Loader_DLL.xex 0x8335B358: tailcall fn_834D38D8 */
ts4_word ts4_tailcall_fn_834D38D8_8335B358(ts4_word a0, ts4_word a1)
{
    return fn_834D38D8((ts4_word)a1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x8335BE88: tailcall fn_8335B4F8 */
ts4_word ts4_tailcall_fn_8335B4F8_8335BE88(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_8335B4F8((ts4_word)a1, (ts4_word)0);
}

/* Loader_DLL.xex 0x8335BE98: tailcall fn_8335B4F8 */
ts4_word ts4_tailcall_fn_8335B4F8_8335BE98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    (void)a0;
    return fn_8335B4F8((ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)a7);
}

/* Loader_DLL.xex 0x8335C1C8: set u32@0x80, u32@0x7c, u32@0x40, u32@0x60, u32@0x4c */
void ts4_set_u32_off80_8335C1C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8335D0D0: set u32@0x3c, u32@0x44, u32@0x0, u32@0x48, u32@0x4c */
void ts4_set_u32_off3c_8335D0D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8335D248: fn  */
void ts4_fn_8335D248(void)
{
    return;
}

/* Loader_DLL.xex 0x8335D250: fn  */
void ts4_fn_8335D250(void)
{
    return;
}

/* Loader_DLL.xex 0x83361448: get u32@0x10 */
ts4_word ts4_get_u32_off10_83361448(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(a0) + 16))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83361458: get u32@0xc */
ts4_word ts4_get_u32_offc_83361458(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(a0) + 12))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8336E058: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_8336E058(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8336E190: set u32@0x3884 */
void ts4_set_u32_off3884_8336E190(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 14468) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x83371D18: set u32@0x38e0, u32@0x38dc, u32@0x38d8, fn_8336F310 */
ts4_word ts4_set_u32_off38e0_83371D18(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 14560) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 14556) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 14552) = (ts4_word)1;
    return fn_8336F310((ts4_word)a0);
}

/* Loader_DLL.xex 0x83371F18: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_83371F18(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x83379E68: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_83379E68(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x83393AD8: loop_get u16@0x2, u16@0x0 */
void ts4_loop_get_u16_off2_83393AD8(ts4_word a0, int a1)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p4;

    if ((int)a1 <= 0) {
        return;
    }
    c1 = (ts4_word)a1;
    lv2 = (ts4_word)(a0 + -2);
    do {
        *(unsigned short *)((char *)(ts4_word)((lv2 + 2)) + 0) = (unsigned short)((*(unsigned short *)((char *)(ts4_word)(lv2) + 2)) + 128);
        p4 = (ts4_word)(lv2 + 2);
        lv2 = p4;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x83395860: fn  */
ts4_word ts4_fn_83395860(ts4_word a0)
{
    return ((a0 + 4095) & 0xfffff000);
}

/* Loader_DLL.xex 0x83395870: get u32@0x18 */
ts4_word ts4_get_u32_off18_83395870(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Loader_DLL.xex 0x83395878: get u32@0x1c */
ts4_word ts4_get_u32_off1c_83395878(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 28));
}

/* Loader_DLL.xex 0x83395880: get u32@0x20, u32@0x18, u32@0xc */
ts4_word ts4_get_u32_off20_83395880(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    return ((((int)t1 * (int)a1) + (t2 << 3)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
}

/* Loader_DLL.xex 0x833958A0: get u32@0x24, u32@0x1c, u32@0x10 */
ts4_word ts4_get_u32_off24_833958A0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    return ((((int)t1 * (int)a1) + (t2 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
}

/* Loader_DLL.xex 0x833958C0: get u32@0x24, u32@0x1c, u32@0x14 */
ts4_word ts4_get_u32_off24_833958C0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    return ((((int)t1 * (int)a1) + (t2 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
}

/* Loader_DLL.xex 0x833959B8: set u32@lbl_83542CB8, u32@lbl_83542CBC */
ts4_word ts4_set_u32_lbl_83542CB8_833959B8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)lbl_83542CB8 = (ts4_word)a0;
    *(ts4_word *)lbl_83542CBC = (ts4_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x833974D0: get u16@0x2, lbl_8305091C */
ts4_word ts4_get_u16_off2_833974D0(ts4_word a0)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 2);
    return (*(unsigned char *)((char *)(ts4_word)(((((t1 << 25) | (t1 >> 7)) & 0x6) + ((t1 >> 3) & 0x1))) + (ts4_word)lbl_8305091C));
}

/* Loader_DLL.xex 0x83397990: tailcall fn_833C61A0 */
ts4_word ts4_tailcall_fn_833C61A0_83397990(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833C61A0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)8);
}

/* Loader_DLL.xex 0x83397998: tailcall fn_833C6360 */
ts4_word ts4_tailcall_fn_833C6360_83397998(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833C6360((ts4_word)(a0 + -5), (ts4_word)a1, (ts4_word)a2, (ts4_word)4);
}

/* Loader_DLL.xex 0x8339BEA8: if_get u32@lbl_83542D60, u32@lbl_83542C30, u32@lbl_83542C30, fn_83397508, fn_8339BD30 */
ts4_word ts4_if_get_u32_lbl_83542D60_8339BEA8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    int t1;
    int t3;

    t1 = *(ts4_word *)lbl_83542D60;
    if ((int)t1 != 0) {
        return fn_8339BD30((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
    }
    t3 = *(ts4_word *)lbl_83542C30;
    if ((int)t3 == 0) {
        return a0;
    }
    return fn_83397508((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x833A1F10: tailcall fn_833A0010 */
ts4_word ts4_tailcall_fn_833A0010_833A1F10(ts4_word a0)
{
    return fn_833A0010((ts4_word)a0);
}

/* Loader_DLL.xex 0x833A24D8: tailcall fn_833D29E8 */
ts4_word ts4_tailcall_fn_833D29E8_833A24D8(ts4_word a0)
{
    return fn_833D29E8((ts4_word)a0);
}

/* Loader_DLL.xex 0x833A24E0: set u32@0x47fc */
void ts4_set_u32_off47fc_833A24E0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 18428) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x833A3E70: loop_get u16@0x0 */
void ts4_loop_get_u16_off0_833A3E70(ts4_word a0, ts4_word a1)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p4;

    c1 = (ts4_word)64;
    lv2 = (ts4_word)a0;
    do {
        *(unsigned short *)((char *)(ts4_word)((a1 - a0)) + lv2) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(lv2) + 0));
        p4 = (ts4_word)(lv2 + 2);
        lv2 = p4;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x833C03F8: get u32@lbl_83542CB0, u32@lbl_83542C54 */
void ts4_get_u32_lbl_83542CB0_833C03F8(void)
{
    *(ts4_word *)lbl_83542C54 = (ts4_word)(((*(ts4_word *)lbl_83542CB0) << 3) + -8);
    return;
}

/* Loader_DLL.xex 0x833C0418: addr lbl_83543658, u32@lbl_835437C0, u32@0x0, u32@lbl_835437C0, u32@0x0 */
void ts4_addr_lbl_83543658_833C0418(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((int)(*(ts4_word *)lbl_835437C0) * 88)) + ((ts4_word)lbl_83543658 + 72)));
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((int)(*(ts4_word *)lbl_835437C0) * 88)) + ((ts4_word)lbl_83543658 + 76)));
    return;
}

/* Loader_DLL.xex 0x833C5000: call_seq fn_833C4190 */
ts4_word ts4_call_seq_fn_833C4190_833C5000(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word t1;

    t1 = fn_833C4190((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    return t1;
}

/* Loader_DLL.xex 0x833C5270: set u32@0xc, u32@0x10, u32@0x14, u32@0x2c */
void ts4_set_u32_offc_833C5270(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x833C5890: call_seq fn_833C5798 */
ts4_word ts4_call_seq_fn_833C5798_833C5890(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    t1 = fn_833C5798((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)8, (ts4_word)8, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
    return t1;
}

/* Loader_DLL.xex 0x833C5C98: call_seq fn_833C58C8 */
ts4_word ts4_call_seq_fn_833C58C8_833C5C98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    t1 = fn_833C58C8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)8, (ts4_word)8, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
    return t1;
}

/* Loader_DLL.xex 0x833C6758: set u32@0x0 */
void ts4_set_u32_off0_833C6758(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x833C92B8: set u32@0x8 */
void ts4_set_u32_off8_833C92B8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x833CC2F0: loop_get u16@0x2, u16@0x0 */
void ts4_loop_get_u16_off2_833CC2F0(ts4_word a0, int a1)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p4;

    if ((int)a1 <= 0) {
        return;
    }
    c1 = (ts4_word)a1;
    lv2 = (ts4_word)(a0 + -2);
    do {
        *(unsigned short *)((char *)(ts4_word)((lv2 + 2)) + 0) = (unsigned short)((*(unsigned short *)((char *)(ts4_word)(lv2) + 2)) + 128);
        p4 = (ts4_word)(lv2 + 2);
        lv2 = p4;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x833CD120: set u32@0xc */
void ts4_set_u32_offc_833CD120(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x833CF858: set u32@0x330 */
void ts4_set_u32_off330_833CF858(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 816) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x833D0CE0: tailcall fn_833CF9A8 */
ts4_word ts4_tailcall_fn_833CF9A8_833D0CE0(ts4_word a0, ts4_word a1)
{
    return fn_833CF9A8((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Loader_DLL.xex 0x833D0CE8: tailcall fn_833CF9A8 */
ts4_word ts4_tailcall_fn_833CF9A8_833D0CE8(ts4_word a0)
{
    return fn_833CF9A8((ts4_word)a0, (ts4_word)0, (ts4_word)0);
}

/* Loader_DLL.xex 0x833D2418: get u16@0x2, lbl_830522C8 */
ts4_word ts4_get_u16_off2_833D2418(ts4_word a0)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 2);
    return ((signed char)(*(unsigned char *)((char *)(ts4_word)(((((t1 << 25) | (t1 >> 7)) & 0x6) + ((t1 >> 3) & 0x1))) + (ts4_word)lbl_830522C8)));
}

/* Loader_DLL.xex 0x833D2440: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_set_u32_off0_833D2440(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x833D2460: set u32@0x14, u32@0x18, u8@0x1c, u32@0x20 */
void ts4_set_u32_off14_833D2460(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a2;
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x833D2478: set  */
void ts4_set_833D2478(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Loader_DLL.xex 0x833D2480: set  */
void ts4_set_833D2480(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4) = f1;
    return;
}

/* Loader_DLL.xex 0x833D2488: set  */
void ts4_set_833D2488(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Loader_DLL.xex 0x833D2490: set  */
void ts4_set_833D2490(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 12) = f1;
    return;
}

/* Loader_DLL.xex 0x833D2498: fn  */
ts4_word ts4_fn_833D2498(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x833D2830: get u32@0x1d4 */
ts4_word ts4_get_u32_off1d4_833D2830(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a2)) + 468))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x833D28C8: call_seq fn_830E1C48 */
ts4_word ts4_call_seq_fn_830E1C48_833D28C8(void)
{
    fn_830E1C48();
    return 0;
}

/* Loader_DLL.xex 0x833D33B8: get u32@0x20, u32@0xc */
ts4_word ts4_get_u32_off20_833D33B8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    return (((int)t1 * (int)a1) + (*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
}

/* Loader_DLL.xex 0x833D33D0: get u32@0x24, u32@0x10 */
ts4_word ts4_get_u32_off24_833D33D0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    return (((int)t1 * (int)a1) + (*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
}

/* Loader_DLL.xex 0x833D33E8: get u32@0x24, u32@0x14 */
ts4_word ts4_get_u32_off24_833D33E8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    return (((int)t1 * (int)a1) + (*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
}

/* Loader_DLL.xex 0x833D3400: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_833D3400(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x833D3418: set  */
void ts4_set_833D3418(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Loader_DLL.xex 0x833D3420: set  */
void ts4_set_833D3420(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4) = f1;
    return;
}

/* Loader_DLL.xex 0x833D3428: set  */
void ts4_set_833D3428(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Loader_DLL.xex 0x833D3430: set  */
void ts4_set_833D3430(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 12) = f1;
    return;
}

/* Loader_DLL.xex 0x833D3438: fn  */
ts4_word ts4_fn_833D3438(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x833D37A8: get u32@0x1d4 */
ts4_word ts4_get_u32_off1d4_833D37A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a2)) + 468))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x833D3EB0: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_833D3EB0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x833D3EC0: set  */
void ts4_set_833D3EC0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Loader_DLL.xex 0x833D3EC8: set  */
void ts4_set_833D3EC8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4) = f1;
    return;
}

/* Loader_DLL.xex 0x833D3ED0: set  */
void ts4_set_833D3ED0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Loader_DLL.xex 0x833D3ED8: set  */
void ts4_set_833D3ED8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 12) = f1;
    return;
}

/* Loader_DLL.xex 0x833D3EE0: fn  */
ts4_word ts4_fn_833D3EE0(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x833D42A0: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_833D42A0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x833D42C8: set  */
void ts4_set_833D42C8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Loader_DLL.xex 0x833D42D0: set  */
void ts4_set_833D42D0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4) = f1;
    return;
}

/* Loader_DLL.xex 0x833D42D8: set  */
void ts4_set_833D42D8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Loader_DLL.xex 0x833D42E0: set  */
void ts4_set_833D42E0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 12) = f1;
    return;
}

/* Loader_DLL.xex 0x833D42E8: fn  */
ts4_word ts4_fn_833D42E8(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x833D47F0: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_833D47F0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x833D4800: set  */
void ts4_set_833D4800(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Loader_DLL.xex 0x833D4808: set  */
void ts4_set_833D4808(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4) = f1;
    return;
}

/* Loader_DLL.xex 0x833D4810: set  */
void ts4_set_833D4810(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Loader_DLL.xex 0x833D4818: set  */
void ts4_set_833D4818(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 12) = f1;
    return;
}

/* Loader_DLL.xex 0x833D4820: fn  */
ts4_word ts4_fn_833D4820(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x833D4BE0: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_833D4BE0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x833D4BF0: set  */
void ts4_set_833D4BF0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Loader_DLL.xex 0x833D4BF8: set  */
void ts4_set_833D4BF8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4) = f1;
    return;
}

/* Loader_DLL.xex 0x833D4C00: set  */
void ts4_set_833D4C00(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Loader_DLL.xex 0x833D4C08: set  */
void ts4_set_833D4C08(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 12) = f1;
    return;
}

/* Loader_DLL.xex 0x833D4C10: fn  */
ts4_word ts4_fn_833D4C10(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x833D5050: set  */
void ts4_set_833D5050(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Loader_DLL.xex 0x833D5058: set  */
void ts4_set_833D5058(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4) = f1;
    return;
}

/* Loader_DLL.xex 0x833D5060: set  */
void ts4_set_833D5060(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Loader_DLL.xex 0x833D5068: set  */
void ts4_set_833D5068(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 12) = f1;
    return;
}

/* Loader_DLL.xex 0x833D5070: fn  */
ts4_word ts4_fn_833D5070(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x833D5408: get u32@0x1d4 */
ts4_word ts4_get_u32_off1d4_833D5408(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a2)) + 468))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x833D6CB0: get u16@0x2, lbl_8306EF68 */
ts4_word ts4_get_u16_off2_833D6CB0(ts4_word a0)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 2);
    return (*(unsigned char *)((char *)(ts4_word)(((((t1 << 25) | (t1 >> 7)) & 0x6) + ((t1 >> 3) & 0x1))) + (ts4_word)lbl_8306EF68));
}

/* Loader_DLL.xex 0x833D7058: set  */
void ts4_set_833D7058(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Loader_DLL.xex 0x833D7060: set  */
void ts4_set_833D7060(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4) = f1;
    return;
}

/* Loader_DLL.xex 0x833D7068: set  */
void ts4_set_833D7068(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Loader_DLL.xex 0x833D7070: set  */
void ts4_set_833D7070(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 12) = f1;
    return;
}

/* Loader_DLL.xex 0x833D7140: fn  */
ts4_word ts4_fn_833D7140(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x833D7A08: call_seq fn_833E3A30 */
ts4_word ts4_call_seq_fn_833E3A30_833D7A08(ts4_word a0)
{
    fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)132);
    return a0;
}

/* Loader_DLL.xex 0x833D89E0: get u32@0x1d4 */
ts4_word ts4_get_u32_off1d4_833D89E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a2)) + 468))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x833DB8A8: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_833DB8A8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x833DB8B8: set  */
void ts4_set_833DB8B8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Loader_DLL.xex 0x833DB8C0: set  */
void ts4_set_833DB8C0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4) = f1;
    return;
}

/* Loader_DLL.xex 0x833DB8C8: set  */
void ts4_set_833DB8C8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Loader_DLL.xex 0x833DB8D0: set  */
void ts4_set_833DB8D0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 12) = f1;
    return;
}

/* Loader_DLL.xex 0x833DB8D8: fn  */
ts4_word ts4_fn_833DB8D8(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x833DBC48: get u32@0x1d4 */
ts4_word ts4_get_u32_off1d4_833DBC48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a2)) + 468))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x833DECF8: loop_get u16@0x2, u16@0x0 */
void ts4_loop_get_u16_off2_833DECF8(ts4_word a0, int a1)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p4;

    if ((int)a1 <= 0) {
        return;
    }
    c1 = (ts4_word)a1;
    lv2 = (ts4_word)(a0 + -2);
    do {
        *(unsigned short *)((char *)(ts4_word)((lv2 + 2)) + 0) = (unsigned short)((*(unsigned short *)((char *)(ts4_word)(lv2) + 2)) + 128);
        p4 = (ts4_word)(lv2 + 2);
        lv2 = p4;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x833DF5A0: tailcall RtlEnterCriticalSection */
ts4_word ts4_tailcall_RtlEnterCriticalSection_833DF5A0(ts4_word a0)
{
    return RtlEnterCriticalSection((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x833DF5A8: tailcall RtlLeaveCriticalSection */
ts4_word ts4_tailcall_RtlLeaveCriticalSection_833DF5A8(ts4_word a0)
{
    return RtlLeaveCriticalSection((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x833DF878: tailcall fn_833DF630 */
ts4_word ts4_tailcall_fn_833DF630_833DF878(ts4_word a0)
{
    return fn_833DF630((ts4_word)2, (ts4_word)((458752) | 3), (ts4_word)a0);
}

/* Loader_DLL.xex 0x833DF890: tailcall fn_833DF630 */
ts4_word ts4_tailcall_fn_833DF630_833DF890(ts4_word a0)
{
    return fn_833DF630((ts4_word)2, (ts4_word)((458752) | 5), (ts4_word)a0);
}

/* Loader_DLL.xex 0x833DF8A8: tailcall fn_833DF630 */
ts4_word ts4_tailcall_fn_833DF630_833DF8A8(ts4_word a0)
{
    return fn_833DF630((ts4_word)2, (ts4_word)((458752) | 6), (ts4_word)a0);
}

/* Loader_DLL.xex 0x833DF8C0: tailcall fn_833DF630 */
ts4_word ts4_tailcall_fn_833DF630_833DF8C0(ts4_word a0)
{
    return fn_833DF630((ts4_word)2, (ts4_word)((458752) | 7), (ts4_word)a0);
}

/* Loader_DLL.xex 0x833E04B0: tailcall fn_833DFA98 */
ts4_word ts4_tailcall_fn_833DFA98_833E04B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_833DFA98((ts4_word)2, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Loader_DLL.xex 0x833E04D0: tailcall fn_833DFC48 */
ts4_word ts4_tailcall_fn_833DFC48_833E04D0(ts4_word a0)
{
    return fn_833DFC48((ts4_word)2, (ts4_word)a0);
}

/* Loader_DLL.xex 0x833E04E0: tailcall fn_833DFD38 */
ts4_word ts4_tailcall_fn_833DFD38_833E04E0(ts4_word a0, ts4_word a1)
{
    return fn_833DFD38((ts4_word)2, (ts4_word)0, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x833E04F8: tailcall fn_833E03C8 */
ts4_word ts4_tailcall_fn_833E03C8_833E04F8(ts4_word a0)
{
    return fn_833E03C8((ts4_word)2, (ts4_word)0, (ts4_word)a0);
}

/* Loader_DLL.xex 0x833E0508: tailcall fn_833DFFB0 */
ts4_word ts4_tailcall_fn_833DFFB0_833E0508(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_833DFFB0((ts4_word)2, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x833E0520: tailcall fn_833E0048 */
ts4_word ts4_tailcall_fn_833E0048_833E0520(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833E0048((ts4_word)2, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x833E0538: tailcall fn_833E00B8 */
ts4_word ts4_tailcall_fn_833E00B8_833E0538(ts4_word a0)
{
    return fn_833E00B8((ts4_word)2, (ts4_word)a0);
}

/* Loader_DLL.xex 0x833E05B0: tailcall fn_833E0120 */
ts4_word ts4_tailcall_fn_833E0120_833E05B0(ts4_word a0)
{
    return fn_833E0120((ts4_word)2, (ts4_word)a0);
}

/* Loader_DLL.xex 0x833E05C0: tailcall fn_833E0188 */
ts4_word ts4_tailcall_fn_833E0188_833E05C0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_833E0188((ts4_word)2, (ts4_word)a1, (ts4_word)a1);
}

/* Loader_DLL.xex 0x833E0758: tailcall fn_833E0AB0 */
ts4_word ts4_tailcall_fn_833E0AB0_833E0758(ts4_word a0)
{
    return fn_833E0AB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E0780: if_get u32@0x4, lbl_8306F7D8 */
ts4_word ts4_if_get_u32_off4_833E0780(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0) {
        return t1;
    }
    return (ts4_word)lbl_8306F7D8;
}

/* Loader_DLL.xex 0x833E0B70: fn  */
ts4_word ts4_fn_833E0B70(void)
{
    return 1;
}

/* Loader_DLL.xex 0x833E0B78: fn  */
void ts4_fn_833E0B78(void)
{
    return;
}

/* Loader_DLL.xex 0x833E0E80: tailcall fn_833E0D28 */
ts4_word ts4_tailcall_fn_833E0D28_833E0E80(ts4_word a0)
{
    return fn_833E0D28((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E0E88: tailcall fn_833E1758 */
ts4_word ts4_tailcall_fn_833E1758_833E0E88(ts4_word a0)
{
    return fn_833E1758((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E17B0: get u32@lbl_83543A34, u32@lbl_83543A34 */
ts4_word ts4_get_u32_lbl_83543A34_833E17B0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_83543A34;
    *(ts4_word *)lbl_83543A34 = (ts4_word)a0;
    return t1;
}

/* Loader_DLL.xex 0x833E17C8: get u32@lbl_83543A34 */
ts4_word ts4_get_u32_lbl_83543A34_833E17C8(void)
{
    return (*(ts4_word *)lbl_83543A34);
}

/* Loader_DLL.xex 0x833E25A8: tailcall fn_833E2510 */
ts4_word ts4_tailcall_fn_833E2510_833E25A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_833E2510((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)a3);
}

/* Loader_DLL.xex 0x833E2708: tailcall fn_833E25B8 */
ts4_word ts4_tailcall_fn_833E25B8_833E2708(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_833E25B8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)a4);
}

/* Loader_DLL.xex 0x833E3088: tailcall fn_833F1760 */
ts4_word ts4_tailcall_fn_833F1760_833E3088(ts4_word a0)
{
    return fn_833F1760((ts4_word)a0, (ts4_word)0, (ts4_word)10);
}

/* Loader_DLL.xex 0x833E3098: tailcall fn_833F1768 */
ts4_word ts4_tailcall_fn_833F1768_833E3098(ts4_word a0, ts4_word a1)
{
    return fn_833F1768((ts4_word)a0, (ts4_word)0, (ts4_word)10, (ts4_word)a1);
}

/* Loader_DLL.xex 0x833E30A8: tailcall fn_833F1760 */
ts4_word ts4_tailcall_fn_833F1760_833E30A8(ts4_word a0)
{
    return fn_833F1760((ts4_word)a0, (ts4_word)0, (ts4_word)10);
}

/* Loader_DLL.xex 0x833E30B8: tailcall fn_833F1768 */
ts4_word ts4_tailcall_fn_833F1768_833E30B8(ts4_word a0, ts4_word a1)
{
    return fn_833F1768((ts4_word)a0, (ts4_word)0, (ts4_word)10, (ts4_word)a1);
}

/* Loader_DLL.xex 0x833E30C8: tailcall fn_833F1A40 */
ts4_word ts4_tailcall_fn_833F1A40_833E30C8(ts4_word a0)
{
    return fn_833F1A40((ts4_word)a0, (ts4_word)0, (ts4_word)10);
}

/* Loader_DLL.xex 0x833E30D8: tailcall fn_833F1A48 */
ts4_word ts4_tailcall_fn_833F1A48_833E30D8(ts4_word a0, ts4_word a1)
{
    return fn_833F1A48((ts4_word)a0, (ts4_word)0, (ts4_word)10, (ts4_word)a1);
}

/* Loader_DLL.xex 0x833E3278: get u32@lbl_83543A0C, u32@lbl_83543A0C */
ts4_word ts4_get_u32_lbl_83543A0C_833E3278(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_83543A0C;
    *(ts4_word *)lbl_83543A0C = (ts4_word)a0;
    return t1;
}

/* Loader_DLL.xex 0x833E3290: tailcall fn_833E31E0 */
ts4_word ts4_tailcall_fn_833E31E0_833E3290(ts4_word a0)
{
    return fn_833E31E0((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E3458: tailcall fn_833E3298 */
ts4_word ts4_tailcall_fn_833E3298_833E3458(ts4_word a0)
{
    return fn_833E3298((ts4_word)a0, (ts4_word)1);
}

/* Loader_DLL.xex 0x833E4210: fn  */
void ts4_fn_833E4210(void)
{
    return;
}

/* Loader_DLL.xex 0x833E4218: addr lbl_8352CA04 */
ts4_word ts4_addr_lbl_8352CA04_833E4218(void)
{
    return (ts4_word)lbl_8352CA04;
}

/* Loader_DLL.xex 0x833E4608: if_get u32@lbl_8352C070, fn_833F4E58 */
ts4_word ts4_if_get_u32_lbl_8352C070_833E4608(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_8352C070;
    if ((ts4_word)a0 == (ts4_word)t1) {
        return a0;
    }
    return fn_833F4E58((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E4F30: if_tail fn_833E4DE0, fn_833E4DE0 */
ts4_word ts4_if_tail_fn_833E4DE0_833E4F30(int a0, ts4_word a1, ts4_word a2, int a3)
{
    if ((int)a3 == 10 && (int)a0 < 0) {
        return fn_833E4DE0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)1);
    }
    return fn_833E4DE0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Loader_DLL.xex 0x833E4F70: tailcall fn_833E4DE0 */
ts4_word ts4_tailcall_fn_833E4DE0_833E4F70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_833E4DE0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Loader_DLL.xex 0x833E50F0: tailcall fn_833E4F78 */
ts4_word ts4_tailcall_fn_833E4F78_833E50F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_833E4F78((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Loader_DLL.xex 0x833E53B8: tailcall fn_833E5288 */
ts4_word ts4_tailcall_fn_833E5288_833E53B8(ts4_word a0, ts4_word a1)
{
    return fn_833E5288((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Loader_DLL.xex 0x833E5640: tailcall fn_833E53C0 */
ts4_word ts4_tailcall_fn_833E53C0_833E5640(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833E53C0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x833E5648: tailcall fn_833E53C0 */
ts4_word ts4_tailcall_fn_833E53C0_833E5648(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833E53C0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x833E5650: tailcall fn_833E53C0 */
ts4_word ts4_tailcall_fn_833E53C0_833E5650(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833E53C0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)1);
}

/* Loader_DLL.xex 0x833E5658: tailcall fn_833E53C0 */
ts4_word ts4_tailcall_fn_833E53C0_833E5658(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833E53C0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)1);
}

/* Loader_DLL.xex 0x833E58E0: tailcall fn_833E5838 */
ts4_word ts4_tailcall_fn_833E5838_833E58E0(ts4_word a0, ts4_word a1)
{
    return fn_833E5838((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Loader_DLL.xex 0x833E58E8: call_seq fn_833E5838 */
ts4_word ts4_call_seq_fn_833E5838_833E58E8(ts4_word a0, ts4_word a1)
{
    fn_833E5838((ts4_word)a0, (ts4_word)-1, (ts4_word)a1);
    return a0;
}

/* Loader_DLL.xex 0x833E5C28: tailcall fn_833E5B90 */
ts4_word ts4_tailcall_fn_833E5B90_833E5C28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_833E5B90((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)a3);
}

/* Loader_DLL.xex 0x833E5D88: tailcall fn_833E5C38 */
ts4_word ts4_tailcall_fn_833E5C38_833E5D88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_833E5C38((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)a4);
}

/* Loader_DLL.xex 0x833E5E28: if_fn  */
ts4_word ts4_if_fn_833E5E28(ts4_word a0)
{
    ts4_word p1;

    if ((ts4_word)(a0 & 0xffff) == 65535) {
        return a0;
    }
    p1 = (ts4_word)(a0 & 0xffff);
    if ((ts4_word)(a0 & 0xffff) >= 65 && (ts4_word)(a0 & 0xffff) <= 90) {
        p1 = (ts4_word)((a0 & 0xffff) + 32);
    }
    return (p1 & 0xffff);
}

/* Loader_DLL.xex 0x833E5E50: if_fn  */
ts4_word ts4_if_fn_833E5E50(ts4_word a0)
{
    ts4_word p1;

    if ((ts4_word)(a0 & 0xffff) == 65535) {
        return a0;
    }
    p1 = (ts4_word)(a0 & 0xffff);
    if ((ts4_word)(a0 & 0xffff) >= 65 && (ts4_word)(a0 & 0xffff) <= 90) {
        p1 = (ts4_word)((a0 & 0xffff) + 32);
    }
    return (p1 & 0xffff);
}

/* Loader_DLL.xex 0x833E6238: tailcall fn_833E2998 */
ts4_word ts4_tailcall_fn_833E2998_833E6238(ts4_word a0)
{
    return fn_833E2998((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E6830: tailcall fn_833E6748 */
ts4_word ts4_tailcall_fn_833E6748_833E6830(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_833E6748((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)a3);
}

/* Loader_DLL.xex 0x833E7270: fn  */
ts4_word ts4_fn_833E7270(ts4_word a0)
{
    return (a0 + 32);
}

/* Loader_DLL.xex 0x833E72B8: if_fn  */
ts4_word ts4_if_fn_833E72B8(int a0)
{
    if ((int)a0 < 65) {
        return a0;
    }
    if ((int)a0 > 90) {
        return a0;
    }
    return (a0 + 32);
}

/* Loader_DLL.xex 0x833E72D0: fn  */
ts4_word ts4_fn_833E72D0(ts4_word a0)
{
    return (a0 + -32);
}

/* Loader_DLL.xex 0x833E7318: if_fn  */
ts4_word ts4_if_fn_833E7318(int a0)
{
    if ((int)a0 < 97) {
        return a0;
    }
    if ((int)a0 > 122) {
        return a0;
    }
    return (a0 + -32);
}

/* Loader_DLL.xex 0x833E7FA8: tailcall fn_833E7E48 */
ts4_word ts4_tailcall_fn_833E7E48_833E7FA8(ts4_word a0, ts4_word a1)
{
    return fn_833E7E48((ts4_word)a0, (ts4_word)a1, (ts4_word)64);
}

/* Loader_DLL.xex 0x833E8028: set u32@lbl_83543A14 */
void ts4_set_u32_lbl_83543A14_833E8028(ts4_word a0)
{
    *(ts4_word *)lbl_83543A14 = (ts4_word)a0;
    return;
}

/* Loader_DLL.xex 0x833E8088: tailcall fn_833E8038 */
ts4_word ts4_tailcall_fn_833E8038_833E8088(void)
{
    return fn_833E8038((ts4_word)0);
}

/* Loader_DLL.xex 0x833E8090: get u32@lbl_83543A14 */
ts4_word ts4_get_u32_lbl_83543A14_833E8090(void)
{
    return (*(ts4_word *)lbl_83543A14);
}

/* Loader_DLL.xex 0x833E8170: tailcall fn_833F92A0 */
ts4_word ts4_tailcall_fn_833F92A0_833E8170(ts4_word a0)
{
    return fn_833F92A0((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E81E0: tailcall fn_833F9520 */
ts4_word ts4_tailcall_fn_833F9520_833E81E0(ts4_word a0)
{
    return fn_833F9520((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E81E8: tailcall fn_833F9420 */
ts4_word ts4_tailcall_fn_833F9420_833E81E8(ts4_word a0)
{
    return fn_833F9420((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E82A0: fn  */
ts4_word ts4_fn_833E82A0(ts4_word a0)
{
    return (a0 + 8);
}

/* Loader_DLL.xex 0x833E82B8: fn  */
void ts4_fn_833E82B8(void)
{
    return;
}

/* Loader_DLL.xex 0x833E82C0: tailcall KeTlsGetValue */
ts4_word ts4_tailcall_KeTlsGetValue_833E82C0(ts4_word a0)
{
    return KeTlsGetValue((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E82C8: get u32@lbl_8352C230 */
ts4_word ts4_get_u32_lbl_8352C230_833E82C8(void)
{
    return (*(ts4_word *)lbl_8352C230);
}

/* Loader_DLL.xex 0x833E82D8: fn  */
ts4_word ts4_fn_833E82D8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x833E82E0: tailcall KeTlsSetValue */
ts4_word ts4_tailcall_KeTlsSetValue_833E82E0(ts4_word a0)
{
    return KeTlsSetValue((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E8598: tailcall fn_8340D860 */
ts4_word ts4_tailcall_fn_8340D860_833E8598(ts4_word a0)
{
    return fn_8340D860((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E85A0: fn  */
ts4_word ts4_fn_833E85A0(void)
{
    return -2;
}

/* Loader_DLL.xex 0x833E8680: tailcall KeBugCheck */
ts4_word ts4_tailcall_KeBugCheck_833E8680(void)
{
    return KeBugCheck((ts4_word)0);
}

/* Loader_DLL.xex 0x833E8688: tailcall KeBugCheck */
ts4_word ts4_tailcall_KeBugCheck_833E8688(void)
{
    return KeBugCheck((ts4_word)0);
}

/* Loader_DLL.xex 0x833E8690: tailcall fn_833F9160 */
ts4_word ts4_tailcall_fn_833F9160_833E8690(void)
{
    return fn_833F9160((ts4_word)8);
}

/* Loader_DLL.xex 0x833E8698: tailcall fn_833F8EC8 */
ts4_word ts4_tailcall_fn_833F8EC8_833E8698(void)
{
    return fn_833F8EC8((ts4_word)8);
}

/* Loader_DLL.xex 0x833E8970: tailcall fn_833E87A8 */
ts4_word ts4_tailcall_fn_833E87A8_833E8970(void)
{
    return fn_833E87A8((ts4_word)0, (ts4_word)0);
}

/* Loader_DLL.xex 0x833E8980: tailcall fn_833E87A8 */
ts4_word ts4_tailcall_fn_833E87A8_833E8980(void)
{
    return fn_833E87A8((ts4_word)1, (ts4_word)0);
}

/* Loader_DLL.xex 0x833E8990: tailcall fn_833E87A8 */
ts4_word ts4_tailcall_fn_833E87A8_833E8990(void)
{
    return fn_833E87A8((ts4_word)0, (ts4_word)1);
}

/* Loader_DLL.xex 0x833E89A0: tailcall fn_833E87A8 */
ts4_word ts4_tailcall_fn_833E87A8_833E89A0(void)
{
    return fn_833E87A8((ts4_word)1, (ts4_word)1);
}

/* Loader_DLL.xex 0x833E8C10: if_tailcall fn_833E8A28 */
ts4_word ts4_if_tailcall_fn_833E8A28_833E8C10(ts4_word a0)
{
    if ((ts4_word)a0 == (ts4_word)((3765239808) | 29539)) {
        return fn_833E8A28((ts4_word)((3765239808) | 29539));
    }
    return 0;
}

/* Loader_DLL.xex 0x833E8F10: set u32@lbl_83543A34 */
void ts4_set_u32_lbl_83543A34_833E8F10(ts4_word a0)
{
    *(ts4_word *)lbl_83543A34 = (ts4_word)a0;
    return;
}

/* Loader_DLL.xex 0x833E9D20: set u32@lbl_83543A38 */
void ts4_set_u32_lbl_83543A38_833E9D20(ts4_word a0)
{
    *(ts4_word *)lbl_83543A38 = (ts4_word)a0;
    return;
}

/* Loader_DLL.xex 0x833E9E28: get u32@lbl_83543A38, u32@lbl_83543A38 */
ts4_word ts4_get_u32_lbl_83543A38_833E9E28(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_83543A38;
    *(ts4_word *)lbl_83543A38 = (ts4_word)a0;
    return t1;
}

/* Loader_DLL.xex 0x833E9E40: get u32@lbl_83543A38 */
ts4_word ts4_get_u32_lbl_83543A38_833E9E40(void)
{
    return (*(ts4_word *)lbl_83543A38);
}

/* Loader_DLL.xex 0x833EA2F8: tailcall fn_833EA200 */
ts4_word ts4_tailcall_fn_833EA200_833EA2F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833EA200((ts4_word)a0, (ts4_word)a1, (ts4_word)0, (ts4_word)a2);
}

/* Loader_DLL.xex 0x833EA308: tailcall fn_833EA200 */
ts4_word ts4_tailcall_fn_833EA200_833EA308(ts4_word a0)
{
    return fn_833EA200((ts4_word)a0);
}

/* Loader_DLL.xex 0x833EB1D0: tailcall fn_833EB108 */
ts4_word ts4_tailcall_fn_833EB108_833EB1D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833EB108((ts4_word)a0, (ts4_word)a1, (ts4_word)0, (ts4_word)a2);
}

/* Loader_DLL.xex 0x833EB370: get u32@lbl_8352CA04, u32@0xbc */
ts4_word ts4_get_u32_lbl_8352CA04_833EB370(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_8352CA04)) + 188));
}

/* Loader_DLL.xex 0x833EFEE0: get u32@lbl_83543A44 */
ts4_word ts4_get_u32_lbl_83543A44_833EFEE0(void)
{
    return (*(ts4_word *)lbl_83543A44);
}

/* Loader_DLL.xex 0x833EFEF0: call_seq fn_833E8428 */
ts4_word ts4_call_seq_fn_833E8428_833EFEF0(void)
{
    ts4_word t1;

    t1 = fn_833E8428();
    return (t1 + 100);
}

/* Loader_DLL.xex 0x833EFF18: call_seq fn_833E8428 */
ts4_word ts4_call_seq_fn_833E8428_833EFF18(void)
{
    ts4_word t1;

    t1 = fn_833E8428();
    return (t1 + 96);
}

/* Loader_DLL.xex 0x833F0488: addr lbl_8352C3D0 */
ts4_word ts4_addr_lbl_8352C3D0_833F0488(void)
{
    return (ts4_word)lbl_8352C3D0;
}

/* Loader_DLL.xex 0x833F06C0: if_addr lbl_8352C3D0, RtlLeaveCriticalSection, u32@0xc, u32@0xc, fn_833F8EC8 */
ts4_word ts4_if_addr_lbl_8352C3D0_833F06C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    if ((ts4_word)a0 >= (ts4_word)(ts4_word)lbl_8352C3D0 && (ts4_word)a0 <= (ts4_word)((ts4_word)lbl_8352C3D0 + 608)) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t1 & 0xffff7fff);
        return fn_833F8EC8((ts4_word)(((int)(a0 - (ts4_word)lbl_8352C3D0) >> 5) + 16), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(t1 & 0xffff7fff));
    }
    return RtlLeaveCriticalSection((ts4_word)(a0 + 32));
}

/* Loader_DLL.xex 0x833F0CD0: tailcall fn_833F08C8 */
ts4_word ts4_tailcall_fn_833F08C8_833F0CD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_833F08C8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)0);
}

/* Loader_DLL.xex 0x833F0CD8: tailcall fn_833F08C8 */
ts4_word ts4_tailcall_fn_833F08C8_833F0CD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_833F08C8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)1);
}

/* Loader_DLL.xex 0x833F1770: tailcall fn_833F1488 */
ts4_word ts4_tailcall_fn_833F1488_833F1770(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833F1488((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)1);
}

/* Loader_DLL.xex 0x833F1778: tailcall fn_833F1488 */
ts4_word ts4_tailcall_fn_833F1488_833F1778(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833F1488((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)1);
}

/* Loader_DLL.xex 0x833F1A50: tailcall fn_833F1780 */
ts4_word ts4_tailcall_fn_833F1780_833F1A50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833F1780((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)1);
}

/* Loader_DLL.xex 0x833F1A58: tailcall fn_833F1780 */
ts4_word ts4_tailcall_fn_833F1780_833F1A58(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833F1780((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)1);
}

/* Loader_DLL.xex 0x833F1A60: tailcall fn_833FAF30 */
ts4_word ts4_tailcall_fn_833FAF30_833F1A60(ts4_word a0, ts4_word a1)
{
    return fn_833FAF30((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x833F1BE0: if_get  */
ts4_word ts4_if_get_833F1BE0(ts4_word a0)
{
    double t1;
    double t2;

    t1 = *(double *)((char *)(ts4_word)(a0) + 0);
    t2 = *(double *)lbl_8300C968;
    if (!(t1 < t2)) {
        return 1;
    }
    return 0;
}

/* Loader_DLL.xex 0x833F1C60: tailcall fn_833F1C00 */
ts4_word ts4_tailcall_fn_833F1C00_833F1C60(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833F1C00((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x833F1CA8: tailcall fn_833F1A90 */
ts4_word ts4_tailcall_fn_833F1A90_833F1CA8(ts4_word a0)
{
    return fn_833F1A90((ts4_word)a0, (ts4_word)0);
}

/* Loader_DLL.xex 0x833F1CB0: tailcall fn_833F1B30 */
ts4_word ts4_tailcall_fn_833F1B30_833F1CB0(ts4_word a0)
{
    return fn_833F1B30((ts4_word)a0, (ts4_word)0);
}

/* Loader_DLL.xex 0x833F1FF8: tailcall fn_833F1F08 */
ts4_word ts4_tailcall_fn_833F1F08_833F1FF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_833F1F08((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)0);
}

/* Loader_DLL.xex 0x833F2408: tailcall fn_833F2000 */
ts4_word ts4_tailcall_fn_833F2000_833F2408(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_833F2000((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)0);
}

/* Loader_DLL.xex 0x833F2698: tailcall fn_833F25C8 */
ts4_word ts4_tailcall_fn_833F25C8_833F2698(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_833F25C8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Loader_DLL.xex 0x833F27D0: tailcall fn_833F26A0 */
ts4_word ts4_tailcall_fn_833F26A0_833F27D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_833F26A0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)0);
}

/* Loader_DLL.xex 0x833F29F8: tailcall fn_833FB560 */
ts4_word ts4_tailcall_fn_833FB560_833F29F8(ts4_word a0)
{
    return fn_833FB560((ts4_word)a0);
}

/* Loader_DLL.xex 0x833F2A00: if_tailcall fn_833FB8C8 */
ts4_word ts4_if_tailcall_fn_833FB8C8_833F2A00(ts4_word a0)
{
    if ((ts4_word)(a0 & 0xffff) == 65535) {
        return a0;
    }
    return fn_833FB8C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x833F3BA0: tailcall fn_833FB560 */
ts4_word ts4_tailcall_fn_833FB560_833F3BA0(ts4_word a0)
{
    return fn_833FB560((ts4_word)a0);
}

/* Loader_DLL.xex 0x833F3BA8: if_tailcall fn_833FB8C8 */
ts4_word ts4_if_tailcall_fn_833FB8C8_833F3BA8(ts4_word a0)
{
    if ((ts4_word)(a0 & 0xffff) == 65535) {
        return a0;
    }
    return fn_833FB8C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x833F7C00: fn  */
ts4_word ts4_fn_833F7C00(ts4_word a0)
{
    return (a0 & 0x7f);
}

/* Loader_DLL.xex 0x833F8670: tailcall fn_833F8398 */
ts4_word ts4_tailcall_fn_833F8398_833F8670(void)
{
    return fn_833F8398((ts4_word)1);
}

/* Loader_DLL.xex 0x833F9780: if_tailcall fn_833E8528 */
ts4_word ts4_if_tailcall_fn_833E8528_833F9780(int a0)
{
    if ((int)a0 != 0) {
        return a0;
    }
    return fn_833E8528((ts4_word)a0);
}

/* Loader_DLL.xex 0x833F9A70: addr fn_833F9998, u32@lbl_83544688 */
void ts4_addr_fn_833F9998_833F9A70(void)
{
    *(ts4_word *)lbl_83544688 = (ts4_word)(ts4_word)fn_833F9998;
    return;
}

/* Loader_DLL.xex 0x833F9D60: fn  */
ts4_word ts4_fn_833F9D60(void)
{
    return 0;
}

/* Loader_DLL.xex 0x833FA070: tailcall fn_833F9FC8 */
ts4_word ts4_tailcall_fn_833F9FC8_833FA070(ts4_word a0)
{
    return fn_833F9FC8((ts4_word)a0);
}

/* Loader_DLL.xex 0x833FA1A0: tailcall fn_833FA078 */
ts4_word ts4_tailcall_fn_833FA078_833FA1A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_833FA078((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)a3);
}

/* Loader_DLL.xex 0x833FA1F0: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA1F0(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)259);
}

/* Loader_DLL.xex 0x833FA1F8: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA1F8(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)259);
}

/* Loader_DLL.xex 0x833FA200: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA200(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)1);
}

/* Loader_DLL.xex 0x833FA208: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA208(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)1);
}

/* Loader_DLL.xex 0x833FA210: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA210(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)2);
}

/* Loader_DLL.xex 0x833FA218: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA218(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)2);
}

/* Loader_DLL.xex 0x833FA220: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA220(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)4);
}

/* Loader_DLL.xex 0x833FA228: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA228(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)4);
}

/* Loader_DLL.xex 0x833FA230: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA230(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)128);
}

/* Loader_DLL.xex 0x833FA238: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA238(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)128);
}

/* Loader_DLL.xex 0x833FA240: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA240(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)8);
}

/* Loader_DLL.xex 0x833FA248: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA248(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)8);
}

/* Loader_DLL.xex 0x833FA250: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA250(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)16);
}

/* Loader_DLL.xex 0x833FA258: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA258(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)16);
}

/* Loader_DLL.xex 0x833FA260: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA260(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)263);
}

/* Loader_DLL.xex 0x833FA268: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA268(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)263);
}

/* Loader_DLL.xex 0x833FA270: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA270(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)343);
}

/* Loader_DLL.xex 0x833FA278: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA278(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)343);
}

/* Loader_DLL.xex 0x833FA280: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA280(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)279);
}

/* Loader_DLL.xex 0x833FA288: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA288(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)279);
}

/* Loader_DLL.xex 0x833FA290: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA290(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)32);
}

/* Loader_DLL.xex 0x833FA298: tailcall fn_833F5188 */
ts4_word ts4_tailcall_fn_833F5188_833FA298(ts4_word a0)
{
    return fn_833F5188((ts4_word)a0, (ts4_word)32);
}

/* Loader_DLL.xex 0x833FA468: set u32@lbl_8354B964 */
void ts4_set_u32_lbl_8354B964_833FA468(void)
{
    *(ts4_word *)lbl_8354B964 = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x833FA570: tailcall fn_833FA478 */
ts4_word ts4_tailcall_fn_833FA478_833FA570(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_833FA478((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Loader_DLL.xex 0x833FAE58: call_seq fn_833F13E0, fn_833FAC70 */
ts4_word ts4_call_seq_fn_833F13E0_833FAE58(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_833F13E0((ts4_word)0, (ts4_word)((4294443008) | 1792));
    t2 = fn_833FAC70((ts4_word)t1);
    return t2;
}

/* Loader_DLL.xex 0x833FAE88: call_seq fn_833F13E0, fn_833FAC70 */
ts4_word ts4_call_seq_fn_833F13E0_833FAE88(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_833F13E0((ts4_word)0, (ts4_word)((4294443008) | 1792));
    t2 = fn_833FAC70((ts4_word)t1);
    return t2;
}

/* Loader_DLL.xex 0x833FAEB8: fn  */
ts4_word ts4_fn_833FAEB8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x833FAEC0: tailcall fn_833F1420 */
ts4_word ts4_tailcall_fn_833F1420_833FAEC0(ts4_word a0)
{
    return fn_833F1420((ts4_word)a0);
}

/* Loader_DLL.xex 0x833FAEC8: tailcall fn_833FACF0 */
ts4_word ts4_tailcall_fn_833FACF0_833FAEC8(ts4_word a0, ts4_word a1)
{
    return fn_833FACF0((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x833FAED0: fn  */
ts4_word ts4_fn_833FAED0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x833FB030: tailcall fn_833FAF88 */
ts4_word ts4_tailcall_fn_833FAF88_833FB030(ts4_word a0, ts4_word a1)
{
    return fn_833FAF88((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Loader_DLL.xex 0x833FB0E0: tailcall fn_833FB038 */
ts4_word ts4_tailcall_fn_833FB038_833FB0E0(ts4_word a0, ts4_word a1)
{
    return fn_833FB038((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Loader_DLL.xex 0x833FB190: tailcall fn_833FB0E8 */
ts4_word ts4_tailcall_fn_833FB0E8_833FB190(ts4_word a0, ts4_word a1)
{
    return fn_833FB0E8((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Loader_DLL.xex 0x833FB1F0: get u32@lbl_8354468C */
ts4_word ts4_get_u32_lbl_8354468C_833FB1F0(void)
{
    return (*(ts4_word *)lbl_8354468C);
}

/* Loader_DLL.xex 0x833FB4E0: tailcall fn_833E89B0 */
ts4_word ts4_tailcall_fn_833E89B0_833FB4E0(void)
{
    return fn_833E89B0((ts4_word)2);
}

/* Loader_DLL.xex 0x833FB4E8: fn  */
ts4_word ts4_fn_833FB4E8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x833FB4F0: fn  */
ts4_word ts4_fn_833FB4F0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x833FB4F8: fn  */
ts4_word ts4_fn_833FB4F8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x833FB530: get u32@lbl_8352CD50 */
ts4_word ts4_get_u32_lbl_8352CD50_833FB530(void)
{
    return (*(ts4_word *)lbl_8352CD50);
}

/* Loader_DLL.xex 0x833FB540: get u32@lbl_8352CD4C */
ts4_word ts4_get_u32_lbl_8352CD4C_833FB540(void)
{
    return (*(ts4_word *)lbl_8352CD4C);
}

/* Loader_DLL.xex 0x833FB550: get u32@lbl_8352CDB0 */
ts4_word ts4_get_u32_lbl_8352CDB0_833FB550(void)
{
    return (*(ts4_word *)lbl_8352CDB0);
}

/* Loader_DLL.xex 0x833FB8C0: tailcall fn_833FB7E0 */
ts4_word ts4_tailcall_fn_833FB7E0_833FB8C0(ts4_word a0)
{
    return fn_833FB7E0((ts4_word)a0);
}

/* Loader_DLL.xex 0x833FBF50: tailcall fn_833FBC80 */
ts4_word ts4_tailcall_fn_833FBC80_833FBF50(ts4_word a0)
{
    return fn_833FBC80((ts4_word)a0);
}

/* Loader_DLL.xex 0x833FBF58: tailcall fn_833FBC80 */
ts4_word ts4_tailcall_fn_833FBC80_833FBF58(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833FBC80((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x833FC088: tailcall fn_833FBF60 */
ts4_word ts4_tailcall_fn_833FBF60_833FC088(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_833FBF60((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)0);
}

/* Loader_DLL.xex 0x833FC418: loop_get u32@0x0 */
void ts4_loop_get_u32_off0_833FC418(ts4_word a0, ts4_word a1)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p4;

    c1 = (ts4_word)3;
    lv2 = (ts4_word)a1;
    do {
        *(ts4_word *)((char *)(ts4_word)((a0 - a1)) + lv2) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 0));
        p4 = (ts4_word)(lv2 + 4);
        lv2 = p4;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x833FC440: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_833FC440(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x833FFE20: tailcall fn_833FFC28 */
ts4_word ts4_tailcall_fn_833FFC28_833FFE20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_833FFC28((ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a0, (ts4_word)1);
}

/* Loader_DLL.xex 0x833FFE40: set u32@0x0 */
void ts4_set_u32_off0_833FFE40(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x833FFE50: set u32@0x0, u32@0x4, u32@0x10, u32@0x8, u32@0xc */
void ts4_set_u32_off0_833FFE50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x834004E8: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_834004E8(void)
{
    return ((((*(ts4_word *)lbl_835446E8) & 0x60) + -96) != 0);
}

/* Loader_DLL.xex 0x83400550: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_83400550(void)
{
    return ((*(ts4_word *)lbl_835446E8) & 0x1000);
}

/* Loader_DLL.xex 0x83400560: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_83400560(void)
{
    return ((*(ts4_word *)lbl_835446E8) & 0x2000);
}

/* Loader_DLL.xex 0x83400570: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_83400570(void)
{
    return ((*(ts4_word *)lbl_835446E8) & 0x4000);
}

/* Loader_DLL.xex 0x83400598: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_83400598(void)
{
    return ((*(ts4_word *)lbl_835446E8) & 0x10000);
}

/* Loader_DLL.xex 0x834006E8: set u32@0x0, u8@0x4, u8@0x5 */
void ts4_set_u32_off0_834006E8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)0;
    return;
}

/* Loader_DLL.xex 0x83400748: get u8@0x4 */
ts4_word ts4_get_u8_off4_83400748(ts4_word a0)
{
    return ((signed char)(*(unsigned char *)((char *)(ts4_word)(a0) + 4)));
}

/* Loader_DLL.xex 0x83400768: get u32@0x4 */
ts4_word ts4_get_u32_off4_83400768(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) >> 23) & 0x1);
}

/* Loader_DLL.xex 0x834007F8: get u32@0x4 */
ts4_word ts4_get_u32_off4_834007F8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) >> 20) & 0x1);
}

/* Loader_DLL.xex 0x83400808: get u32@0x4 */
ts4_word ts4_get_u32_off4_83400808(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) >> 19) & 0x1);
}

/* Loader_DLL.xex 0x83400828: get u32@0x4 */
ts4_word ts4_get_u32_off4_83400828(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) >> 18) & 0x1);
}

/* Loader_DLL.xex 0x83400848: get u32@0x4 */
ts4_word ts4_get_u32_off4_83400848(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) >> 17) & 0x1);
}

/* Loader_DLL.xex 0x83400868: get u16@0x4 */
ts4_word ts4_get_u16_off4_83400868(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)(a0) + 4)) & 0x1);
}

/* Loader_DLL.xex 0x83400950: set u32@0x0 */
void ts4_set_u32_off0_83400950(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-1;
    return;
}

/* Loader_DLL.xex 0x83400988: fn  */
ts4_word ts4_fn_83400988(void)
{
    return 1;
}
