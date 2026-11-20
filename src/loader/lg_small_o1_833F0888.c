/* Loader_DLL.xex 0x833F0888-0x83516538, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char fn_83516540[];
extern char fn_835167E0[];
extern char fn_835168E0[];
extern char fn_835168F0[];
extern char fn_83516900[];
extern char fn_83516920[];
extern char fn_83516928[];
extern char fn_83516958[];
extern char lbl_8307BE9C[];
extern char lbl_8307D158[];
extern char lbl_8307EE20[];
extern char lbl_8307EE30[];
extern char lbl_8307EE40[];
extern char lbl_8307EE50[];
extern char lbl_8307EE60[];
extern char lbl_8307EE70[];
extern char lbl_8307EE80[];
extern char lbl_8307EE90[];
extern char lbl_8307EEA0[];
extern char lbl_8352BF70[];
extern char lbl_8352CA04[];
extern char lbl_8352CA10[];
extern char lbl_8352DB50[];
extern char lbl_8352FB1C[];
extern char lbl_8352FB20[];
extern char lbl_83531108[];
extern char lbl_83531134[];
extern char lbl_83531160[];
extern char lbl_835312D0[];
extern char lbl_8353130C[];
ts4_word RtlInitializeCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_830FEDE8();
ts4_word fn_831602C8();
ts4_word fn_833E3A30();
ts4_word fn_833E4920();
ts4_word fn_833E9D50();
ts4_word fn_833E9F90();
ts4_word fn_834829F0();
ts4_word fn_834833D8();

/* Loader_DLL.xex 0x833F0888: if_call_seq u32@0x10, fn_833E9F90, u32@0x0, fn_833E9D50 */
ts4_word ts4_if_call_seq_u32_off10_833F0888(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 == 0) {
        t2 = fn_833E9F90();
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)22;
        fn_833E9D50((ts4_word)t2);
        p4 = (ts4_word)-1;
    } else {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
    }
    return p4;
}

/* Loader_DLL.xex 0x833F8EC8: addr lbl_8352CA10, RtlLeaveCriticalSection */
ts4_word ts4_addr_lbl_8352CA10_833F8EC8(ts4_word a0)
{
    return RtlLeaveCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)((a0 << 3)) + (ts4_word)lbl_8352CA10)));
}

/* Loader_DLL.xex 0x833FAED8: if_get u32@lbl_8352CA04, u32@0xc8 */
ts4_word ts4_if_get_u32_lbl_8352CA04_833FAED8(int a0, ts4_word a1)
{
    if ((int)a0 >= -1 && (int)a0 <= 255) {
        return ((*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_8352CA04)) + 200))) + (a0 << 1))) & a1);
    }
    return 0;
}

/* Loader_DLL.xex 0x834475C8: get u32@0x560, u32@0x560 */
void ts4_get_u32_off560_834475C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1376)) | 1);
    return;
}

/* Loader_DLL.xex 0x834475D8: if_get u8@0x617, u32@0x560, u32@0x560 */
void ts4_if_get_u8_off617_834475D8(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1559);
    if ((ts4_word)t1 != 16) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1376)) | 16);
    return;
}

/* Loader_DLL.xex 0x834475F8: if_get u8@0x617, u32@0x560, u8@0x618, u32@0x560 */
void ts4_if_get_u8_off617_834475F8(ts4_word a0)
{
    unsigned char t1;
    ts4_word t2;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1559);
    if ((ts4_word)t1 >= 8) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 1376);
    *(unsigned char *)((char *)(ts4_word)(a0) + 1560) = (unsigned char)8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)(t2 | 4);
    return;
}

/* Loader_DLL.xex 0x83447650: if_get u8@0x613, u32@0x560, u32@0x560 */
ts4_word ts4_if_get_u8_off613_83447650(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1555);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1376)) | 2);
        return 7;
    }
    return 1;
}

/* Loader_DLL.xex 0x834478F8: get u32@0x560, u32@0x560 */
void ts4_get_u32_off560_834478F8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1376)) | 1024);
    return;
}

/* Loader_DLL.xex 0x834480B0: get u32@0x560, u32@0x560 */
void ts4_get_u32_off560_834480B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1376)) | 4096);
    return;
}

/* Loader_DLL.xex 0x834480C0: get u32@0x560, u32@0x560 */
void ts4_get_u32_off560_834480C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1376)) | 4096);
    return;
}

/* Loader_DLL.xex 0x834480D0: get u32@0x560, u32@0x560 */
void ts4_get_u32_off560_834480D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1376)) | 4096);
    return;
}

/* Loader_DLL.xex 0x834480E0: get u32@0x560, u32@0x560 */
void ts4_get_u32_off560_834480E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1376)) | 4096);
    return;
}

/* Loader_DLL.xex 0x8344A288: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_8344A288(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((t1 << 16) | (t1 >> 16));
    return;
}

/* Loader_DLL.xex 0x834546D8: get u8@0x0, u8@0x1 */
ts4_word ts4_get_u8_off0_834546D8(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    return ((((t1 << 8) | (t1 >> 24)) + (*(unsigned char *)((char *)(ts4_word)(a0) + 1))) & 0xffff);
}

/* Loader_DLL.xex 0x83465A90: addr lbl_8307BE9C, u32@0x0 */
ts4_word ts4_addr_lbl_8307BE9C_83465A90(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((((ts4_word)lbl_8307BE9C + 8) - (a0 << 2))) + 0));
}

/* Loader_DLL.xex 0x834665F0: get u32@0x0 */
ts4_word ts4_get_u32_off0_834665F0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + -1) == 0);
}

/* Loader_DLL.xex 0x83469ED8: addr lbl_8307D158, u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_addr_lbl_8307D158_83469ED8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)9;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)5;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((ts4_word)lbl_8307D158 + -4096);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(ts4_word)lbl_8307D158;
    return 0;
}

/* Loader_DLL.xex 0x8346BDC0: addr lbl_8352DB50, u32@0x4, u32@0xc, u32@0x8 */
void ts4_addr_lbl_8352DB50_8346BDC0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352DB50) + 4) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352DB50) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352DB50) + 8) = (ts4_word)a2;
    return;
}

/* Loader_DLL.xex 0x8346C858: get u32@0x0, u32@0x8, u32@0xc, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_8346C858(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(t1 + a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t2 + a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t3 + a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t4 + a2);
    return 1;
}

/* Loader_DLL.xex 0x8346C898: get u32@0x0, u32@0x8, u32@0x4, u32@0xc, u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_8346C898(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(t1 - a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t2 + a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t3 - a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t4 + a2);
    return 1;
}

/* Loader_DLL.xex 0x8346C910: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
ts4_word ts4_get_u32_off0_8346C910(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    return 1;
}

/* Loader_DLL.xex 0x83485360: call_seq fn_834833D8, lbl_8307EE20, u32@0x0 */
ts4_word ts4_call_seq_fn_834833D8_83485360(ts4_word a0, ts4_word a1)
{
    fn_834833D8((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8307EE20;
    return a0;
}

/* Loader_DLL.xex 0x834853F8: call_seq fn_834833D8, lbl_8307EE30, u32@0x0 */
ts4_word ts4_call_seq_fn_834833D8_834853F8(ts4_word a0, ts4_word a1)
{
    fn_834833D8((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8307EE30;
    return a0;
}

/* Loader_DLL.xex 0x83485490: call_seq fn_834833D8, lbl_8307EE40, u32@0x0 */
ts4_word ts4_call_seq_fn_834833D8_83485490(ts4_word a0, ts4_word a1)
{
    fn_834833D8((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8307EE40;
    return a0;
}

/* Loader_DLL.xex 0x83485528: call_seq fn_834833D8, lbl_8307EE50, u32@0x0 */
ts4_word ts4_call_seq_fn_834833D8_83485528(ts4_word a0, ts4_word a1)
{
    fn_834833D8((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8307EE50;
    return a0;
}

/* Loader_DLL.xex 0x834855C0: call_seq fn_834833D8, lbl_8307EE60, u32@0x0 */
ts4_word ts4_call_seq_fn_834833D8_834855C0(ts4_word a0, ts4_word a1)
{
    fn_834833D8((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8307EE60;
    return a0;
}

/* Loader_DLL.xex 0x834856A8: call_seq fn_834829F0, lbl_8307EE70, u32@0x0 */
ts4_word ts4_call_seq_fn_834829F0_834856A8(ts4_word a0)
{
    fn_834829F0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8307EE70;
    return a0;
}

/* Loader_DLL.xex 0x834856F0: call_seq fn_834829F0, lbl_8307EE80, u32@0x0 */
ts4_word ts4_call_seq_fn_834829F0_834856F0(ts4_word a0)
{
    fn_834829F0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8307EE80;
    return a0;
}

/* Loader_DLL.xex 0x83485738: call_seq fn_834829F0, lbl_8307EE90, u32@0x0 */
ts4_word ts4_call_seq_fn_834829F0_83485738(ts4_word a0)
{
    fn_834829F0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8307EE90;
    return a0;
}

/* Loader_DLL.xex 0x83485780: call_seq fn_834829F0, lbl_8307EEA0, u32@0x0 */
ts4_word ts4_call_seq_fn_834829F0_83485780(ts4_word a0)
{
    fn_834829F0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8307EEA0;
    return a0;
}

/* Loader_DLL.xex 0x83486688: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_83486688(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((t1 << 16) | (t1 >> 16));
    return;
}

/* Loader_DLL.xex 0x83515DE8: call_seq lbl_8352FB20, fn_833E3A30, fn_835167E0, fn_833E4920 */
ts4_word ts4_call_seq_lbl_8352FB20_83515DE8(void)
{
    ts4_word t2;

    fn_833E3A30((ts4_word)(ts4_word)lbl_8352FB20, (ts4_word)0, (ts4_word)108);
    t2 = fn_833E4920((ts4_word)(ts4_word)fn_835167E0);
    return t2;
}

/* Loader_DLL.xex 0x83515E28: call_seq lbl_8352FB1C, fn_830FEDE8, fn_83516540, fn_833E4920 */
ts4_word ts4_call_seq_lbl_8352FB1C_83515E28(void)
{
    ts4_word t2;

    fn_830FEDE8((ts4_word)(ts4_word)lbl_8352FB1C);
    t2 = fn_833E4920((ts4_word)(ts4_word)fn_83516540);
    return t2;
}

/* Loader_DLL.xex 0x83515EC0: call_seq lbl_83531108, RtlInitializeCriticalSection, fn_835168E0, fn_833E4920 */
ts4_word ts4_call_seq_lbl_83531108_83515EC0(void)
{
    ts4_word t2;

    RtlInitializeCriticalSection((ts4_word)((ts4_word)lbl_83531108 + 16));
    t2 = fn_833E4920((ts4_word)(ts4_word)fn_835168E0);
    return t2;
}

/* Loader_DLL.xex 0x83515EF8: call_seq lbl_83531134, RtlInitializeCriticalSection, fn_835168F0, fn_833E4920 */
ts4_word ts4_call_seq_lbl_83531134_83515EF8(void)
{
    ts4_word t2;

    RtlInitializeCriticalSection((ts4_word)((ts4_word)lbl_83531134 + 16));
    t2 = fn_833E4920((ts4_word)(ts4_word)fn_835168F0);
    return t2;
}

/* Loader_DLL.xex 0x83515F30: call_seq lbl_83531160, RtlInitializeCriticalSection, fn_83516900, fn_833E4920 */
ts4_word ts4_call_seq_lbl_83531160_83515F30(void)
{
    ts4_word t2;

    RtlInitializeCriticalSection((ts4_word)((ts4_word)lbl_83531160 + 16));
    t2 = fn_833E4920((ts4_word)(ts4_word)fn_83516900);
    return t2;
}

/* Loader_DLL.xex 0x83515F78: call_seq lbl_835312D0, RtlInitializeCriticalSection, fn_83516920, fn_833E4920 */
ts4_word ts4_call_seq_lbl_835312D0_83515F78(void)
{
    ts4_word t2;

    RtlInitializeCriticalSection((ts4_word)(ts4_word)lbl_835312D0);
    t2 = fn_833E4920((ts4_word)(ts4_word)fn_83516920);
    return t2;
}

/* Loader_DLL.xex 0x83515FB0: call_seq lbl_8353130C, fn_831602C8, fn_83516928, fn_833E4920 */
ts4_word ts4_call_seq_lbl_8353130C_83515FB0(void)
{
    ts4_word t2;

    fn_831602C8((ts4_word)(ts4_word)lbl_8353130C);
    t2 = fn_833E4920((ts4_word)(ts4_word)fn_83516928);
    return t2;
}

/* Loader_DLL.xex 0x835164F8: call_seq lbl_8352BF70, RtlInitializeCriticalSection, fn_83516958, fn_833E4920 */
ts4_word ts4_call_seq_lbl_8352BF70_835164F8(void)
{
    ts4_word t2;

    RtlInitializeCriticalSection((ts4_word)((ts4_word)lbl_8352BF70 + 4));
    t2 = fn_833E4920((ts4_word)(ts4_word)fn_83516958);
    return t2;
}
