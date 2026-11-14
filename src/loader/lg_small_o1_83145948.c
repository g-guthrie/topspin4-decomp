/* Loader_DLL.xex 0x83145948-0x834473D8, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char lbl_830009F8[];
extern char lbl_83002270[];
extern char lbl_830028D8[];
extern char lbl_83002904[];
extern char lbl_83002920[];
extern char lbl_8300293C[];
extern char lbl_83003F10[];
extern char lbl_83003F24[];
extern char lbl_83003F44[];
extern char lbl_83003F5C[];
extern char lbl_83003F80[];
extern char lbl_830041D8[];
extern char lbl_83004214[];
extern char lbl_8300422C[];
extern char lbl_83005668[];
extern char lbl_83006B54[];
extern char lbl_83007E90[];
extern char lbl_830080C4[];
extern char lbl_830080DC[];
extern char lbl_830081A0[];
extern char lbl_830081E0[];
extern char lbl_830088A4[];
extern char lbl_830088B4[];
extern char lbl_83008970[];
extern char lbl_8300CA98[];
extern char lbl_8300CB70[];
extern char lbl_8300CBFC[];
extern char lbl_8300CC28[];
extern char lbl_8300CC54[];
extern char lbl_8300CC90[];
extern char lbl_8303ADF0[];
extern char lbl_8303AE10[];
extern char lbl_8306F7CC[];
extern char lbl_8306F7D0[];
extern char lbl_8306F7EC[];
extern char lbl_8306F7F4[];
extern char lbl_8306FAB0[];
extern char lbl_8306FAB8[];
extern char lbl_83071A88[];
extern char lbl_83071C50[];
extern char lbl_83071C5C[];
extern char lbl_83071C80[];
extern char lbl_83073B3C[];
extern char lbl_83073B4C[];
extern char lbl_83073B5C[];
extern char lbl_83073B6C[];
extern char lbl_83073B7C[];
extern char lbl_83073B8C[];
extern char lbl_83073B9C[];
extern char lbl_83073BAC[];
extern char lbl_83073BC8[];
extern char lbl_83073BE4[];
extern char lbl_83086960[];
extern char lbl_8352BFD0[];
extern char lbl_8352C070[];
extern char lbl_8352C3C8[];
extern char lbl_8352C3CC[];
extern char lbl_8352C928[];
extern char lbl_8352CA04[];
extern char lbl_8352D368[];
extern char lbl_835311B0[];
extern char lbl_835312B4[];
extern char lbl_835312FC[];
extern char lbl_83531678[];
extern char lbl_83531710[];
extern char lbl_8353AF34[];
extern char lbl_83543A10[];
extern char lbl_83543A28[];
extern char lbl_835446E8[];
extern char lbl_83546320[];
extern char lbl_8354BA80[];
ts4_word MmGetPhysicalAddress();
ts4_word NtClearEvent();
ts4_word NtFlushBuffersFile();
ts4_word NtPulseEvent();
ts4_word NtReleaseMutant();
ts4_word NtReleaseSemaphore();
ts4_word NtResumeThread();
ts4_word NtSetEvent();
ts4_word NtSuspendThread();
ts4_word RtlInitializeCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word XamEnumerate();
ts4_word XamReadTileToTexture();
ts4_word XexGetModuleHandle();
ts4_word XexGetModuleSection();
ts4_word XexUnloadImage();
ts4_word fn_830FF250();
ts4_word fn_83120540();
ts4_word fn_831461B0();
ts4_word fn_83148048();
ts4_word fn_8314D5C8();
ts4_word fn_83159748();
ts4_word fn_83163318();
ts4_word fn_8316E7C0();
ts4_word fn_83173B38();
ts4_word fn_831A1518();
ts4_word fn_831A1698();
ts4_word fn_831A2B48();
ts4_word fn_831A3268();
ts4_word fn_833E08D8();
ts4_word fn_833E1758();
ts4_word fn_833E3A30();
ts4_word fn_833E74C0();
ts4_word fn_833E8350();
ts4_word fn_833E89B0();
ts4_word fn_833E8E50();
ts4_word fn_833F8670();
ts4_word fn_833F8EC8();
ts4_word fn_833F91C8();
ts4_word fn_833FAB08();
ts4_word fn_833FAED8();
ts4_word fn_8340D088();
ts4_word fn_8340D830();
ts4_word fn_8340D860();
ts4_word fn_8340F068();
ts4_word fn_8340F088();
ts4_word fn_83410140();
ts4_word fn_83414000();
ts4_word fn_834141B8();
ts4_word fn_83415CD0();
ts4_word fn_8343B6B8();
ts4_word fn_8343C098();
ts4_word fn_83455050();

/* Loader_DLL.xex 0x83145948: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_83145948(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x83146330: if_call_seq fn_83120540 */
ts4_word ts4_if_call_seq_fn_83120540_83146330(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83146448: if_call_seq fn_831461B0, u32@0x8 */
ts4_word ts4_if_call_seq_fn_831461B0_83146448(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_831461B0((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
    }
    return t1;
}

/* Loader_DLL.xex 0x83146A38: addr lbl_83002270, u32@0x0 */
void ts4_addr_lbl_83002270_83146A38(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83002270;
    return;
}

/* Loader_DLL.xex 0x83146A58: addr lbl_830028D8, u32@0x0 */
void ts4_addr_lbl_830028D8_83146A58(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830028D8;
    return;
}

/* Loader_DLL.xex 0x83146CA8: addr lbl_830028D8, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_830028D8_83146CA8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830028D8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x83147418: if_addr lbl_835311B0 */
void ts4_if_addr_lbl_835311B0_83147418(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 >= 64) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)((a0 << 2)) + (ts4_word)lbl_835311B0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83147438: if_addr lbl_835311B0 */
void ts4_if_addr_lbl_835311B0_83147438(ts4_word a0)
{
    if ((ts4_word)a0 >= 64) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)((a0 << 2)) + (ts4_word)lbl_835311B0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83147468: addr lbl_83002904, u32@0x4, u32@0x0 */
void ts4_addr_lbl_83002904_83147468(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83002904;
    return;
}

/* Loader_DLL.xex 0x83147488: addr lbl_83002904, u32@0x0 */
void ts4_addr_lbl_83002904_83147488(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83002904;
    return;
}

/* Loader_DLL.xex 0x831478C0: addr lbl_83002920, u32@0x4, u32@0x0 */
void ts4_addr_lbl_83002920_831478C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83002920;
    return;
}

/* Loader_DLL.xex 0x831478E0: addr lbl_83002920, u32@0x0 */
void ts4_addr_lbl_83002920_831478E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83002920;
    return;
}

/* Loader_DLL.xex 0x83147A70: set u32@0x14, u32@0x4, lbl_8300293C, u32@0x8, u32@0x10, u32@0x0 */
void ts4_set_u32_off14_83147A70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8300293C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83147AA8: addr lbl_8300293C, u32@0x0 */
void ts4_addr_lbl_8300293C_83147AA8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8300293C;
    return;
}

/* Loader_DLL.xex 0x831482A8: call_seq fn_83148048 */
ts4_word ts4_call_seq_fn_83148048_831482A8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;

    *(unsigned char *)((char *)loc50 + 0) = (unsigned char)(a1 != 0);
    t1 = fn_83148048((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
    return t1;
}

/* Loader_DLL.xex 0x83148AD0: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_83148AD0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831493F8: get  */
void ts4_get_831493F8(ts4_word a0, ts4_word a1, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = ((*(float *)((char *)(ts4_word)(a1) + 0)) * f1);
    *(float *)((char *)(ts4_word)(a0) + 4) = ((*(float *)((char *)(ts4_word)(a1) + 4)) * f1);
    return;
}

/* Loader_DLL.xex 0x831494C0: addr lbl_83003F24, u32@0x8, u32@0x0, u32@0x4 */
void ts4_addr_lbl_83003F24_831494C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F24;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83149528: get u32@0x0, u32@0xc0 */
ts4_word ts4_get_u32_off0_83149528(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 192))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83149858: fn  */
ts4_word ts4_fn_83149858(ts4_word a0, ts4_word a1)
{
    return (((a0 & 0xff) == 0) ^ ((a1 & 0xff) == 0));
}

/* Loader_DLL.xex 0x83149DF8: addr lbl_83003F44, u32@0x0 */
void ts4_addr_lbl_83003F44_83149DF8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F44;
    return;
}

/* Loader_DLL.xex 0x8314A8B0: addr lbl_83003F80, u32@0x0 */
void ts4_addr_lbl_83003F80_8314A8B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F80;
    return;
}

/* Loader_DLL.xex 0x8314B310: get u32@0xbc, u32@0xc0, u32@0xc4, u32@0xbc, u32@0xc0, u32@0xc4 */
void ts4_get_u32_offbc_8314B310(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 188);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 192);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 196);
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)(a1 + t1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)(a2 + t2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 196) = (ts4_word)(t3 + 1);
    return;
}

/* Loader_DLL.xex 0x8314C300: get u32@0x14c, u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_off14c_8314C300(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 36))))((ts4_word)t1, (ts4_word)9, (ts4_word)a1, (ts4_word)1);
}

/* Loader_DLL.xex 0x8314C320: get u32@0x14c, u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_off14c_8314C320(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 36))))((ts4_word)t1, (ts4_word)10, (ts4_word)a1, (ts4_word)2);
}

/* Loader_DLL.xex 0x8314C340: get u32@0x14c, u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_off14c_8314C340(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 36))))((ts4_word)t1, (ts4_word)9, (ts4_word)a1, (ts4_word)1);
}

/* Loader_DLL.xex 0x8314C5A8: addr lbl_83003F10 */
ts4_word ts4_addr_lbl_83003F10_8314C5A8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((a0 & 0xc)) + (ts4_word)lbl_83003F10));
}

/* Loader_DLL.xex 0x8314C7C0: get u32@0x14c, u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off14c_8314C7C0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x8314CB80: get u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_8314CB80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(a0 + 24));
}

/* Loader_DLL.xex 0x8314D0E0: get u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_8314D0E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(a0 + 24));
}

/* Loader_DLL.xex 0x8314D428: get u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_8314D428(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(a0 + 24));
}

/* Loader_DLL.xex 0x8314D618: if_get u32@0x0, u32@0x68 */
ts4_word ts4_if_get_u32_off0_8314D618(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 104))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314DA00: if_get u32@0x0, u32@0x58 */
ts4_word ts4_if_get_u32_off0_8314DA00(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 88))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314DA28: if_get u32@0x0, u32@0x34 */
ts4_word ts4_if_get_u32_off0_8314DA28(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 52))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314DA80: if_tailcall fn_83159748 */
ts4_word ts4_if_tailcall_fn_83159748_8314DA80(ts4_word a0)
{
    if ((int)(a0 & 0x1) == 0) {
        return a0;
    }
    return fn_83159748((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314DB48: if_get u32@0x0, u32@0x44 */
ts4_word ts4_if_get_u32_off0_8314DB48(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 68))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Loader_DLL.xex 0x8314DB70: if_get u32@0x0, u32@0x44 */
ts4_word ts4_if_get_u32_off0_8314DB70(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 68))))((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Loader_DLL.xex 0x8314DB98: if_get u32@0x0, u32@0x48 */
ts4_word ts4_if_get_u32_off0_8314DB98(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314DBC0: if_set u32@0x0, u32@0x0, u32@0x0, u32@0xe0 */
ts4_word ts4_if_set_u32_off0_8314DBC0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a1 != 0 && (ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
        if ((ts4_word)a0 != 0) {
            return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 224))))((ts4_word)a0);
        }
        return ((2147942400) | 87);
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x8314DC00: if_get u32@0x0, u32@0x50 */
ts4_word ts4_if_get_u32_off0_8314DC00(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 80))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314DF10: if_get u32@0x0, u32@0x54 */
ts4_word ts4_if_get_u32_off0_8314DF10(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 84))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314DF38: if_get u32@0x0, u32@0x5c */
ts4_word ts4_if_get_u32_off0_8314DF38(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 92))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314DF60: if_get u32@0x0, u32@0x60 */
ts4_word ts4_if_get_u32_off0_8314DF60(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 96))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314DF88: if_get u32@0x0, u32@0x20 */
ts4_word ts4_if_get_u32_off0_8314DF88(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314DFB0: if_get u32@0x0, u32@0x38 */
ts4_word ts4_if_get_u32_off0_8314DFB0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314DFD8: if_get u32@0x0, u32@0x28 */
ts4_word ts4_if_get_u32_off0_8314DFD8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314E000: if_get u32@0x0, u32@0x2c */
ts4_word ts4_if_get_u32_off0_8314E000(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314E100: if_get u32@0x0, u32@0x18 */
ts4_word ts4_if_get_u32_off0_8314E100(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314E270: if_get u32@0x0, u32@0x6c */
ts4_word ts4_if_get_u32_off0_8314E270(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 108))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314E298: if_get u32@0x0, u32@0x70 */
ts4_word ts4_if_get_u32_off0_8314E298(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 112))))((ts4_word)a0);
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x8314E2C8: if_get u32@0x0, u32@0x7c */
ts4_word ts4_if_get_u32_off0_8314E2C8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 124))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314E2F0: if_get u32@0x0, u32@0x80 */
ts4_word ts4_if_get_u32_off0_8314E2F0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 128))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314E318: if_get u32@0x0, u32@0x84 */
ts4_word ts4_if_get_u32_off0_8314E318(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 132))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314E658: if_get u32@lbl_835312B4, u32@lbl_835312B4 */
void ts4_if_get_u32_lbl_835312B4_8314E658(int a0)
{
    ts4_word p2;
    ts4_word t1;

    t1 = *(ts4_word *)lbl_835312B4;
    if ((int)a0 != 0) {
        p2 = (ts4_word)(t1 | 2);
    } else {
        p2 = (ts4_word)(t1 & 0xfffffffd);
    }
    *(ts4_word *)lbl_835312B4 = (ts4_word)p2;
    return;
}

/* Loader_DLL.xex 0x8314E6A0: if_get u32@0x0, u32@0x94 */
ts4_word ts4_if_get_u32_off0_8314E6A0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 148))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314E880: get u32@0x0, u32@0xe4 */
ts4_word ts4_get_u32_off0_8314E880(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 228))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314E890: get u32@0x0, u32@0xbc */
ts4_word ts4_get_u32_off0_8314E890(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 188))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314E8D8: if_get u32@0x8 */
ts4_word ts4_if_get_u32_off8_8314E8D8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return a0;
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x8314E968: if_get u32@0x0, u32@0x88 */
ts4_word ts4_if_get_u32_off0_8314E968(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 136))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314E990: if_get u32@0x0, u32@0x8c */
ts4_word ts4_if_get_u32_off0_8314E990(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 140))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314EA10: addr lbl_830041D8, u32@0x0 */
void ts4_addr_lbl_830041D8_8314EA10(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830041D8;
    return;
}

/* Loader_DLL.xex 0x8314EA20: addr lbl_83004214, u32@0x8, u32@0x0, u32@0x4 */
void ts4_addr_lbl_83004214_8314EA20(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83004214;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8314EC78: addr lbl_83003F24, u32@0x0 */
void ts4_addr_lbl_83003F24_8314EC78(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F24;
    return;
}

/* Loader_DLL.xex 0x8314ECD0: addr lbl_8300422C, u32@0x8, u32@0x0, u32@0x4 */
void ts4_addr_lbl_8300422C_8314ECD0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8300422C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8314ECF0: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_8314ECF0(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314ED18: addr lbl_83003F24, u32@0x0 */
void ts4_addr_lbl_83003F24_8314ED18(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F24;
    return;
}

/* Loader_DLL.xex 0x8314EE58: get u32@0x58, u32@0x0, u32@0x5c, u32@0x0 */
void ts4_get_u32_off58_8314EE58(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88));
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 92));
    return;
}

/* Loader_DLL.xex 0x8314F5F8: addr lbl_83003F5C, u32@0x8, u32@0x4, u32@0x0, u32@0xc, u32@0x10 */
void ts4_addr_lbl_83003F5C_8314F5F8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F5C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83150680: if_get u32@0x0, u32@0x48 */
ts4_word ts4_if_get_u32_off0_83150680(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831506A8: if_get u32@0x0, u32@0x20 */
ts4_word ts4_if_get_u32_off0_831506A8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Loader_DLL.xex 0x83152E50: if_call_seq fn_8314D5C8, u32@lbl_835312FC, u32@0x58 */
ts4_word ts4_if_call_seq_fn_8314D5C8_83152E50(ts4_word a0)
{
    ts4_word p3;
    ts4_word t1;

    t1 = fn_8314D5C8();
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        p3 = (ts4_word)(*(ts4_word *)lbl_835312FC);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)p3;
    return p3;
}

/* Loader_DLL.xex 0x83153418: get u32@0x3c, u32@0x0, u32@0xe8 */
ts4_word ts4_get_u32_off3c_83153418(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 232))))((ts4_word)t1, (ts4_word)(a1 & 0xffff), (ts4_word)(a2 & 0xffff));
}

/* Loader_DLL.xex 0x83153DD8: if_set u32@0x0, u32@0x10, u32@0x4, u32@0x14, u32@0x4, u32@0x14 */
void ts4_if_set_u32_off0_83153DD8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 4));
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)a1;
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    if ((ts4_word)t2 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83158D18: get u32@0x40 */
ts4_word ts4_get_u32_off40_83158D18(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a1)) + 64))))((ts4_word)a0, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83158D30: get u32@0x1d4 */
ts4_word ts4_get_u32_off1d4_83158D30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a2)) + 468))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x8315E470: get u32@0x40 */
ts4_word ts4_get_u32_off40_8315E470(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a1)) + 64))))((ts4_word)a0, (ts4_word)a2);
}

/* Loader_DLL.xex 0x8315E488: get u32@0x1d4 */
ts4_word ts4_get_u32_off1d4_8315E488(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a2)) + 468))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x8315EA08: get u32@0xc, u32@0x40, vcall */
ts4_word ts4_get_u32_offc_8315EA08(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((t1 + a1)) + 64))))((ts4_word)t1, (ts4_word)a2);
    return 0;
}

/* Loader_DLL.xex 0x8315F8E8: addr lbl_83005668, u32@0x0 */
void ts4_addr_lbl_83005668_8315F8E8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83005668;
    return;
}

/* Loader_DLL.xex 0x8315F958: if_set u32@0x0 */
ts4_word ts4_if_set_u32_off0_8315F958(ts4_word a0, ts4_word a1)
{
    (void)a0;
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)2;
    }
    return 0;
}

/* Loader_DLL.xex 0x831602C8: addr lbl_83005668, u8@0x4, u32@0x0, u32@0x14, u32@0x18, u32@0x1c */
void ts4_addr_lbl_83005668_831602C8(ts4_word a0)
{
    float t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    t1 = *(float *)lbl_830009F8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83005668;
    *(float *)((char *)(ts4_word)(a0) + 8) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83161800: call_seq lbl_83531678, fn_83163318, lbl_83546320, fn_83163318 */
ts4_word ts4_call_seq_lbl_83531678_83161800(void)
{
    ts4_word t2;

    fn_83163318((ts4_word)(ts4_word)lbl_83531678);
    t2 = fn_83163318((ts4_word)(ts4_word)lbl_83546320);
    return t2;
}

/* Loader_DLL.xex 0x83161AD0: get u32@0x4, u32@0x4 */
ts4_word ts4_get_u32_off4_83161AD0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 1);
    return 0;
}

/* Loader_DLL.xex 0x83162D10: get u32@0x10, u32@0x10 */
ts4_word ts4_get_u32_off10_83162D10(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 1);
    return 0;
}

/* Loader_DLL.xex 0x83162D90: if_get u32@0xc, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0xc */
ts4_word ts4_if_get_u32_offc_83162D90(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
        *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
        *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x83163348: get u32@0x0, u32@0x4, u32@0x0, u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_83163348(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)a0;
    return;
}

/* Loader_DLL.xex 0x83163368: get u32@0x4, u32@0x0, u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
void ts4_get_u32_off4_83163368(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    return;
}

/* Loader_DLL.xex 0x83163AC8: get u8@0x0, u8@0x1 */
ts4_word ts4_get_u8_off0_83163AC8(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    return ((((t1 << 8) | (t1 >> 24)) | (*(unsigned char *)((char *)(ts4_word)(a0) + 1))) & 0xffff);
}

/* Loader_DLL.xex 0x83166490: set u32@0xc, u16@0x8, u32@0x10, u16@0xa, u16@0x0, u32@0x18 */
void ts4_set_u32_offc_83166490(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    unsigned short t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 8) = (unsigned short)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(a2 + -4);
    *(unsigned short *)((char *)(ts4_word)(a0) + 10) = (unsigned short)1;
    t1 = *(unsigned short *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)((((t1 << 16) | (t1 >> 16)) + 65536) + -32768);
    return;
}

/* Loader_DLL.xex 0x831664C8: get u32@0x0, u32@0x4, u32@0x0, u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_831664C8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)a0;
    return;
}

/* Loader_DLL.xex 0x831664E8: get u32@0x4, u32@0x0, u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
void ts4_get_u32_off4_831664E8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    return;
}

/* Loader_DLL.xex 0x83166A18: get u32@0x0, u32@0x4, u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
ts4_word ts4_get_u32_off0_83166A18(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4))) + 0) = (ts4_word)t1;
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 164));
    *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)a1;
    return t1;
}

/* Loader_DLL.xex 0x8316C0B8: addr lbl_83006B54, u32@0x0 */
ts4_word ts4_addr_lbl_83006B54_8316C0B8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((((ts4_word)lbl_83006B54 + 8) - (a0 << 2))) + 0));
}

/* Loader_DLL.xex 0x8316CC88: get u32@0x0 */
ts4_word ts4_get_u32_off0_8316CC88(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + -1) == 0);
}

/* Loader_DLL.xex 0x8316DAC8: addr lbl_83007E90, u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_addr_lbl_83007E90_8316DAC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)9;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)5;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((ts4_word)lbl_83007E90 + -4096);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(ts4_word)lbl_83007E90;
    return 0;
}

/* Loader_DLL.xex 0x8316E1A8: get u32@0xd4 */
ts4_word ts4_get_u32_offd4_8316E1A8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 212)) == 0);
}

/* Loader_DLL.xex 0x8316E1D8: get u32@0x20 */
ts4_word ts4_get_u32_off20_8316E1D8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) == 0);
}

/* Loader_DLL.xex 0x8316E210: get u32@0x20 */
ts4_word ts4_get_u32_off20_8316E210(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) == 0);
}

/* Loader_DLL.xex 0x8316E240: get u32@0x20 */
ts4_word ts4_get_u32_off20_8316E240(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) == 0);
}

/* Loader_DLL.xex 0x8316E258: get u32@0x20 */
ts4_word ts4_get_u32_off20_8316E258(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) == 0);
}

/* Loader_DLL.xex 0x8316EF90: get u32@-0x8, u32@0x0, u32@-0x4, u32@0x0 */
void ts4_get_u32_0x8_8316EF90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + -8));
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + -4));
    return;
}

/* Loader_DLL.xex 0x8316F420: addr lbl_830080DC, u32@0x4, u32@0x0 */
void ts4_addr_lbl_830080DC_8316F420(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830080DC;
    return;
}

/* Loader_DLL.xex 0x8316F438: addr lbl_830080DC, u32@0x0 */
void ts4_addr_lbl_830080DC_8316F438(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830080DC;
    return;
}

/* Loader_DLL.xex 0x8316F608: get u32@0x0 */
ts4_word ts4_get_u32_off0_8316F608(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) == 0);
}

/* Loader_DLL.xex 0x8316F630: call_seq fn_8340D860, u32@0xac */
ts4_word ts4_call_seq_fn_8340D860_8316F630(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8340D860();
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 172)) - t1) == 0);
}

/* Loader_DLL.xex 0x8316FC58: if_get u32@0x1b0, u32@0x0 */
ts4_word ts4_if_get_u32_off1b0_8316FC58(ts4_word a0)
{
    ts4_word p3;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 432);
    if ((ts4_word)t1 != 0) {
        p3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    } else {
        p3 = (ts4_word)0;
    }
    if ((ts4_word)p3 != 0) {
        return (p3 + 4);
    }
    return 0;
}

/* Loader_DLL.xex 0x8316FFD0: get u32@0x10, u32@0x18, u32@0x18c, u32@0x1c, u32@0x14, u32@0x20 */
void ts4_get_u32_off10_8316FFD0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
    *(ts4_word *)((char *)(ts4_word)(a1) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 396));
    *(ts4_word *)((char *)(ts4_word)(a1) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    *(ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    *(ts4_word *)((char *)(ts4_word)(a1) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
    *(ts4_word *)((char *)(ts4_word)(a1) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
    *(ts4_word *)((char *)(ts4_word)(a1) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36));
    return;
}

/* Loader_DLL.xex 0x83170580: if_tailcall fn_8316E7C0 */
ts4_word ts4_if_tailcall_fn_8316E7C0_83170580(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 > (ts4_word)((2147418112) | 65535)) {
        return ((2147942400) | 87);
    }
    return fn_8316E7C0((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x83170F48: addr lbl_830080C4, u32@0x20, u32@0x0 */
void ts4_addr_lbl_830080C4_83170F48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830080C4;
    return;
}

/* Loader_DLL.xex 0x831741C8: if_call_seq fn_83173B38 */
ts4_word ts4_if_call_seq_fn_83173B38_831741C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)(a1 & 0x1) != 0) {
        fn_83173B38();
    }
    return a0;
}

/* Loader_DLL.xex 0x83174D68: get u32@0x20 */
ts4_word ts4_get_u32_off20_83174D68(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) == 0);
}

/* Loader_DLL.xex 0x83174E08: get u32@0xd4 */
ts4_word ts4_get_u32_offd4_83174E08(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 212)) == 0);
}

/* Loader_DLL.xex 0x83174F50: get u32@0x0, lbl_830081E0, u32@0x0 */
ts4_word ts4_get_u32_off0_83174F50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a2;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)(ts4_word)lbl_830081E0, (ts4_word)a1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x83175130: get u32@0x8, u32@0x4 */
ts4_word ts4_get_u32_off8_83175130(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return (((int)t1 * (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 4))) << 2);
}

/* Loader_DLL.xex 0x83175148: get u32@0x8, u32@0x4 */
ts4_word ts4_get_u32_off8_83175148(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((((int)t1 * (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 3) << 2);
}

/* Loader_DLL.xex 0x83175160: get u32@0x4, u32@0x14 */
ts4_word ts4_get_u32_off4_83175160(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return (((((int)t1 * (int)a2) + a1) << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
}

/* Loader_DLL.xex 0x83175180: get u32@0x4, u32@0x18 */
ts4_word ts4_get_u32_off4_83175180(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((((((int)t1 * (int)a2) + a1) + 3) << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
}

/* Loader_DLL.xex 0x83175308: get u32@0x8, u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off8_83175308(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 4))))((ts4_word)t2, (ts4_word)0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x83175368: if_get u32@0x3c, u32@0x34 */
float ts4_if_get_u32_off3c_83175368(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    float t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((int)(t1 & 0x10) != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        t4 = *(float *)((char *)(ts4_word)(a0) + 76);
        return ((*(float *)((char *)(ts4_word)(t3) + 528)) * t4);
    }
    return (*(float *)((char *)(ts4_word)(a0) + 76));
}

/* Loader_DLL.xex 0x83176270: if_get u32@0x0, u32@0x4, u32@0x4, u32@0x44, u32@0x40 */
ts4_word ts4_if_get_u32_off0_83176270(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 == 0) {
        return (*(ts4_word *)((char *)(ts4_word)(a0) + 64));
    }
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4))) + 4))) + 68));
}

/* Loader_DLL.xex 0x83177938: call_seq MmGetPhysicalAddress, u32@lbl_83531710 */
ts4_word ts4_call_seq_MmGetPhysicalAddress_83177938(void)
{
    ts4_word t1;

    t1 = MmGetPhysicalAddress();
    return (((int)(t1 - (*(ts4_word *)lbl_83531710)) >> 6) & 0xffff);
}

/* Loader_DLL.xex 0x83177D28: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_83177D28(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) & ~a1);
    return;
}

/* Loader_DLL.xex 0x83178630: if_get u32@0x4, u32@0x8, u32@0x40, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_off4_83178630(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)(t1 & 0x20000) != 0) {
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((int)a1 * 96)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 8))));
    } else {
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((((int)a1 * 96) + (*(ts4_word *)((char *)(ts4_word)(a0) + 8)))) + 64))) + 0));
    }
    return ((p8 >> 12) & 0xff);
}

/* Loader_DLL.xex 0x831790C0: get u32@0x20 */
ts4_word ts4_get_u32_off20_831790C0(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) == 0);
}

/* Loader_DLL.xex 0x83179288: addr lbl_830081A0, u32@lbl_830081A0, u32@0x4, u32@0x8, u32@0xc, u32@0x0 */
void ts4_addr_lbl_830081A0_83179288(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(volatile ts4_word *)lbl_830081A0;
    t2 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_830081A0) + 4);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_830081A0) + 8);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_830081A0) + 12);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(a1 & 0xffff);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t4;
    return;
}

/* Loader_DLL.xex 0x83179558: if_get u32@0x290, u32@0x28c, u32@0x1d0, u32@0x28c, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off290_83179558(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 656);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 652);
        if ((ts4_word)t3 != 0) {
            p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
        } else {
            p5 = (ts4_word)0;
        }
        *(ts4_word *)((char *)(ts4_word)(p5) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(p5) + 0)) | 64);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 464) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8317B5C0: get u32@0x20 */
ts4_word ts4_get_u32_off20_8317B5C0(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) == 0);
}

/* Loader_DLL.xex 0x8317B8C8: if_get u32@0x214, u32@0x210, u32@0x210, u32@0x0, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off214_8317B8C8(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 532);
    if ((ts4_word)t1 == 0) {
        return;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 528);
    if ((ts4_word)t3 != 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
    } else {
        p5 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(p5) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(p5) + 0)) | 64);
    return;
}

/* Loader_DLL.xex 0x8317F5B0: get u32@0xa8 */
ts4_word ts4_get_u32_offa8_8317F5B0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 168)) + -2) == 0);
}

/* Loader_DLL.xex 0x8317F5C8: if_get u32@0x84, u32@0x0, u32@0x68 */
ts4_word ts4_if_get_u32_off84_8317F5C8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t1 != 0) {
        return t1;
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 104))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8317F5F0: if_get u32@0x34, u32@0x84, u32@0x84, u32@0x0, u32@0x68, u32@0xc */
ts4_word ts4_if_get_u32_off34_8317F5F0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 12));
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t3 != 0) {
        return t3;
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 104))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8317F6C0: if_get u32@0x34, u32@0x0, u32@0x6c, u32@0x4 */
ts4_word ts4_if_get_u32_off34_8317F6C0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 4));
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 108))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83180750: get u32@0x20 */
ts4_word ts4_get_u32_off20_83180750(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) == 0);
}

/* Loader_DLL.xex 0x83180978: get u32@0x80 */
ts4_word ts4_get_u32_off80_83180978(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 128)) + -2) == 0);
}

/* Loader_DLL.xex 0x83180CD8: get u32@0x48, u32@0x40, u32@0x8 */
ts4_word ts4_get_u32_off48_83180CD8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 64))) + 8))))((ts4_word)(t1 + 64));
}

/* Loader_DLL.xex 0x83180CF0: get u32@0x48, u32@0x40, u32@0x14 */
ts4_word ts4_get_u32_off48_83180CF0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 64))) + 20))))((ts4_word)(t1 + 64));
}

/* Loader_DLL.xex 0x83182C90: get u32@0x48, u32@0x30, fn_833E3A30 */
ts4_word ts4_get_u32_off48_83182C90(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    return fn_833E3A30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)0, (ts4_word)((int)t1 * 12));
}

/* Loader_DLL.xex 0x83183AD0: addr lbl_83008970, u32@0x0, fn_831A3268 */
ts4_word ts4_addr_lbl_83008970_83183AD0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83008970;
    return fn_831A3268((ts4_word)a0);
}

/* Loader_DLL.xex 0x83188F08: get u32@0x20 */
ts4_word ts4_get_u32_off20_83188F08(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) == 0);
}

/* Loader_DLL.xex 0x83189240: get u32@0x8, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off8_83189240(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 0);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 0))))((ts4_word)t2);
}

/* Loader_DLL.xex 0x8319CC58: get u32@0x20 */
ts4_word ts4_get_u32_off20_8319CC58(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) == 0);
}

/* Loader_DLL.xex 0x8319CD80: get u32@0x30 */
ts4_word ts4_get_u32_off30_8319CD80(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 48);
    return (t1 - ((int)((int)t1 / (int)13) * 13));
}

/* Loader_DLL.xex 0x8319D618: if_get u32@0x23c, u32@0x23c, u32@0x23c, u32@0x23c */
void ts4_if_get_u32_off23c_8319D618(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 572) = (ts4_word)2;
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 572);
    if ((int)t2 != 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 572) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8319DB68: addr lbl_8300CA98, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_8300CA98_8319DB68(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8300CA98;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8319DD70: get u32@0x84, u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off84_8319DD70(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x8319DD88: get u32@0x84, u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off84_8319DD88(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x8319FDA8: call_seq fn_8340D860, u32@0x14 */
ts4_word ts4_call_seq_fn_8340D860_8319FDA8(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8340D860();
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) - t1) == 0);
}

/* Loader_DLL.xex 0x831A08E0: get u32@0x4, u32@0x0, u32@0x1c, vcall */
ts4_word ts4_get_u32_off4_831A08E0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1);
    return 0;
}

/* Loader_DLL.xex 0x831A0918: get u32@0x4, u32@0x0, u32@0x28 */
ts4_word ts4_get_u32_off4_831A0918(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x831A0A08: get u32@0x4, u32@0x10, u32@0x0, u32@0x20 */
ts4_word ts4_get_u32_off4_831A0A08(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 32))))((ts4_word)t1, (ts4_word)t2);
}

/* Loader_DLL.xex 0x831A0A20: get u32@0x4, u32@0x10, u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_off4_831A0A20(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 36))))((ts4_word)t1, (ts4_word)t2);
}

/* Loader_DLL.xex 0x831A0AF0: set u32@0x4, u32@0x8, lbl_8300CB70, u32@0xc, u32@0x10, u32@0x0 */
void ts4_set_u32_off4_831A0AF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8300CB70;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831A1818: if_call_seq fn_831A1518, fn_831A1698 */
ts4_word ts4_if_call_seq_fn_831A1518_831A1818(ts4_word a0)
{
    ts4_word p3;
    int t1;
    ts4_word t2;

    t1 = fn_831A1518();
    p3 = (ts4_word)t1;
    if ((int)t1 >= 0) {
        t2 = fn_831A1698((ts4_word)a0);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x831A1AD0: get u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off0_831A1AD0(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831A2238: addr lbl_8300CBFC, u32@0x4, u32@0x0 */
void ts4_addr_lbl_8300CBFC_831A2238(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8300CBFC;
    return;
}

/* Loader_DLL.xex 0x831A2250: addr lbl_8300CBFC, u32@0x0 */
void ts4_addr_lbl_8300CBFC_831A2250(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8300CBFC;
    return;
}

/* Loader_DLL.xex 0x831A22B0: addr lbl_8300CC54, lbl_8300CC28, lbl_8300CBFC, u32@0x0, u32@0x4, u32@0x4 */
void ts4_addr_lbl_8300CC54_831A22B0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8300CC54;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_8300CC28;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_8300CBFC;
    return;
}

/* Loader_DLL.xex 0x831A26C0: get u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_off0_831A26C0(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 36))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831A2BA0: addr lbl_8300CC90, u32@lbl_8300CC90, u32@0x4, u32@0x8, u32@0xc, u32@0x0 */
void ts4_addr_lbl_8300CC90_831A2BA0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(volatile ts4_word *)lbl_8300CC90;
    t2 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8300CC90) + 4);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8300CC90) + 8);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8300CC90) + 12);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(a1 & 0xffff);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t4;
    return;
}

/* Loader_DLL.xex 0x831A3708: if_tailcall fn_831A2B48 */
ts4_word ts4_if_tailcall_fn_831A2B48_831A3708(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 <= (ts4_word)((2147418112) | 65535)) {
        return fn_831A2B48((ts4_word)a0, (ts4_word)a1);
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x831F2EC8: get u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_831F2EC8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831F2ED8: get u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off0_831F2ED8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831F2FB0: addr lbl_830080C4, u32@0x20, u32@0x0, u32@0x24, u32@0x28, u32@0x2c */
void ts4_addr_lbl_830080C4_831F2FB0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830080C4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831F3518: get u32@0x84, u32@0x80, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off84_831F3518(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)t2, (ts4_word)a2);
}

/* Loader_DLL.xex 0x831F3640: get u32@0x84, u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off84_831F3640(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x831F36B8: get u32@0x74 */
ts4_word ts4_get_u32_off74_831F36B8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 116)) == 0);
}

/* Loader_DLL.xex 0x831F4470: get u32@0x2c */
ts4_word ts4_get_u32_off2c_831F4470(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 44)) == 0);
}

/* Loader_DLL.xex 0x831F4570: get u32@0x0, lbl_830088A4, u32@0x0 */
ts4_word ts4_get_u32_off0_831F4570(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a2;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)(ts4_word)lbl_830088A4, (ts4_word)a1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x831F4590: get u32@0x0, lbl_830088B4, u32@0x0 */
ts4_word ts4_get_u32_off0_831F4590(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a2;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)(ts4_word)lbl_830088B4, (ts4_word)a1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x8320BFD0: get u32@0x8, u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off8_8320BFD0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x8321C388: if_call_seq fn_830FF250, u32@0xc */
ts4_word ts4_if_call_seq_fn_830FF250_8321C388(ts4_word a0)
{
    ts4_word p5;
    ts4_word loc50[2];
    ts4_word t2;

    fn_830FF250((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc50[0];
    if ((ts4_word)t2 == 0) {
        p5 = (ts4_word)0;
    } else {
        p5 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 12)) & 0x1);
    }
    return p5;
}

/* Loader_DLL.xex 0x83242F60: loop_get u8@0x0, u8@0x0 */
void ts4_loop_get_u8_off0_83242F60(ts4_word a0, ts4_word a1)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p5;
    unsigned char t3;

    c1 = (ts4_word)16;
    lv2 = (ts4_word)a0;
    do {
        t3 = *(unsigned char *)((char *)(ts4_word)((a1 - a0)) + lv2);
        *(unsigned char *)((char *)(ts4_word)(lv2) + 0) = (unsigned char)(t3 ^ (*(unsigned char *)((char *)(ts4_word)(lv2) + 0)));
        p5 = (ts4_word)(lv2 + 1);
        lv2 = p5;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x83243028: loop_get u8@0x0, u8@0x0 */
void ts4_loop_get_u8_off0_83243028(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p5;
    unsigned char t3;

    if ((ts4_word)a2 == 0) {
        return;
    }
    c1 = (ts4_word)a2;
    lv2 = (ts4_word)a0;
    do {
        t3 = *(unsigned char *)((char *)(ts4_word)((a1 - a0)) + lv2);
        *(unsigned char *)((char *)(ts4_word)(lv2) + 0) = (unsigned char)(t3 ^ (*(unsigned char *)((char *)(ts4_word)(lv2) + 0)));
        p5 = (ts4_word)(lv2 + 1);
        lv2 = p5;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x83243058: if_fn  */
ts4_word ts4_if_fn_83243058(ts4_word a0)
{
    if ((int)(a0 & 0xf) == 0) {
        return a0;
    }
    return ((a0 - (a0 & 0xf)) + 16);
}

/* Loader_DLL.xex 0x83268E50: if_fn  */
ts4_word ts4_if_fn_83268E50(ts4_word a0)
{
    ts4_word p1;

    p1 = (ts4_word)0;
    if ((ts4_word)a0 != 0) {
        p1 = (ts4_word)16;
    }
    return p1;
}

/* Loader_DLL.xex 0x83268E68: get u32@lbl_8353AF34, u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_lbl_8353AF34_83268E68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_8353AF34;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1, (ts4_word)a0, (ts4_word)a2, (ts4_word)a1, (ts4_word)16, (ts4_word)((a3 + -1) == 0));
}

/* Loader_DLL.xex 0x8327F3B0: addr lbl_8303ADF0, u32@0x0 */
void ts4_addr_lbl_8303ADF0_8327F3B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8303ADF0;
    return;
}

/* Loader_DLL.xex 0x8327F3C0: addr lbl_8303AE10, u32@0x0 */
void ts4_addr_lbl_8303AE10_8327F3C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8303AE10;
    return;
}

/* Loader_DLL.xex 0x8327F578: loop_set u8@0x0, fn_833E1758 */
ts4_word ts4_loop_set_u8_off0_8327F578(ts4_word a0, ts4_word a1)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;

    if ((ts4_word)a1 == 0) {
        return a0;
    }
    c1 = (ts4_word)352;
    lv2 = (ts4_word)(a1 + -1);
    do {
        *(volatile unsigned char *)((char *)(ts4_word)((lv2 + 1)) + 0) = (unsigned char)0;
        p3 = (ts4_word)(lv2 + 1);
        lv2 = p3;
    } while (--c1 != 0);
    return fn_833E1758((ts4_word)a1);
}

/* Loader_DLL.xex 0x8327F758: addr lbl_8303AE10, u32@0x0 */
void ts4_addr_lbl_8303AE10_8327F758(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8303AE10;
    return;
}

/* Loader_DLL.xex 0x833DF550: call_seq lbl_8306F7CC, u32@0x0, RtlInitializeCriticalSection */
ts4_word ts4_call_seq_lbl_8306F7CC_833DF550(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8306F7CC;
    RtlInitializeCriticalSection((ts4_word)(a0 + 4));
    return a0;
}

/* Loader_DLL.xex 0x833DF590: addr lbl_8306F7CC, u32@0x0 */
void ts4_addr_lbl_8306F7CC_833DF590(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8306F7CC;
    return;
}

/* Loader_DLL.xex 0x833E0760: addr lbl_8306F7D0, u32@0x0, u32@0x0, u32@0x4, u8@0x8 */
void ts4_addr_lbl_8306F7D0_833E0760(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8306F7D0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return;
}

/* Loader_DLL.xex 0x833E0930: addr lbl_8306F7F4, lbl_8306F7EC, u32@0x4, u32@0x0, u8@0x8 */
void ts4_addr_lbl_8306F7F4_833E0930(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_8306F7F4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8306F7EC;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return;
}

/* Loader_DLL.xex 0x833E0958: addr lbl_8306F7EC, u32@0x0, fn_833E08D8 */
ts4_word ts4_addr_lbl_8306F7EC_833E0958(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8306F7EC;
    return fn_833E08D8((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E1C00: loop_get u16@0x0 */
ts4_word ts4_loop_get_u16_off0_833E1C00(ts4_word a0)
{
    ts4_word lv1;
    ts4_word p3;
    unsigned short t2;

    lv1 = (ts4_word)a0;
    do {
        t2 = *(unsigned short *)((char *)(ts4_word)(lv1) + 0);
        p3 = (ts4_word)(lv1 + 2);
        lv1 = p3;
    } while ((ts4_word)t2 != 0);
    return (((int)(lv1 - a0) >> 1) + -1);
}

/* Loader_DLL.xex 0x833E27F8: get u32@lbl_8352BFD0, u32@lbl_8352BFD0 */
ts4_word ts4_get_u32_lbl_8352BFD0_833E27F8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_8352BFD0;
    *(ts4_word *)lbl_8352BFD0 = (ts4_word)((t1 & ~a1) | (a0 & a1));
    return t1;
}

/* Loader_DLL.xex 0x833E7190: get u32@lbl_8352C070, u32@lbl_83543A10 */
ts4_word ts4_get_u32_lbl_8352C070_833E7190(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_8352C070;
    return (((t1 | 1) - (*(ts4_word *)lbl_83543A10)) == 0);
}

/* Loader_DLL.xex 0x833E8178: addr lbl_8306FAB0, u32@0x0, fn_833F91C8 */
ts4_word ts4_addr_lbl_8306FAB0_833E8178(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8306FAB0;
    return fn_833F91C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E82A8: addr lbl_8306FAB0, u32@0x0 */
void ts4_addr_lbl_8306FAB0_833E82A8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8306FAB0;
    return;
}

/* Loader_DLL.xex 0x833E8330: addr lbl_8306FAB8, u32@0x8, u32@0x5c, u32@0x14 */
void ts4_addr_lbl_8306FAB8_833E8330(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)(ts4_word)lbl_8306FAB8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x833E8428: if_call_seq fn_833E8350, fn_833E89B0 */
ts4_word ts4_if_call_seq_fn_833E8350_833E8428(void)
{
    ts4_word t1;

    t1 = fn_833E8350();
    if ((int)t1 == 0) {
        fn_833E89B0((ts4_word)16);
    }
    return t1;
}

/* Loader_DLL.xex 0x833E8E98: if_call_seq fn_833E8E50, fn_83414000 */
ts4_word ts4_if_call_seq_fn_833E8E50_833E8E98(ts4_word a0)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_833E8E50((ts4_word)a0);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_83414000((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x833E9F90: if_call_seq fn_833E8350, lbl_8352C3C8 */
ts4_word ts4_if_call_seq_fn_833E8350_833E9F90(void)
{
    ts4_word p2;
    ts4_word t1;

    t1 = fn_833E8350();
    if ((ts4_word)t1 == 0) {
        p2 = (ts4_word)(ts4_word)lbl_8352C3C8;
    } else {
        p2 = (ts4_word)(t1 + 8);
    }
    return p2;
}

/* Loader_DLL.xex 0x833E9FC8: if_call_seq fn_833E8350, lbl_8352C3CC */
ts4_word ts4_if_call_seq_fn_833E8350_833E9FC8(void)
{
    ts4_word p2;
    ts4_word t1;

    t1 = fn_833E8350();
    if ((ts4_word)t1 == 0) {
        p2 = (ts4_word)(ts4_word)lbl_8352C3CC;
    } else {
        p2 = (ts4_word)(t1 + 12);
    }
    return p2;
}

/* Loader_DLL.xex 0x833F05C0: if_call_seq fn_833F8670, u8@lbl_83543A28, fn_833FAB08, u32@lbl_8354BA80, fn_833E74C0 */
ts4_word ts4_if_call_seq_fn_833F8670_833F05C0(void)
{
    ts4_word t1;
    unsigned char t2;
    ts4_word t6;

    t1 = fn_833F8670();
    t2 = *(unsigned char *)lbl_83543A28;
    if ((ts4_word)t2 != 0) {
        fn_833FAB08((ts4_word)t1);
    }
    t6 = fn_833E74C0((ts4_word)(*(ts4_word *)lbl_8354BA80));
    return t6;
}

/* Loader_DLL.xex 0x833F0700: if_tail RtlLeaveCriticalSection, u32@0xc, u32@0xc, fn_833F8EC8 */
ts4_word ts4_if_tail_RtlLeaveCriticalSection_833F0700(int a0, ts4_word a1)
{
    if ((int)a0 < 20) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 12)) & 0xffff7fff);
        return fn_833F8EC8((ts4_word)(a0 + 16));
    }
    return RtlLeaveCriticalSection((ts4_word)(a1 + 32));
}

/* Loader_DLL.xex 0x833F7820: if_addr lbl_8352CA04, u32@lbl_8352CA04, u32@0xac, u32@0xc8, fn_833FAED8 */
ts4_word ts4_if_addr_lbl_8352CA04_833F7820(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)lbl_8352CA04;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 172);
    if ((int)t2 > 1) {
        return fn_833FAED8((ts4_word)a0, (ts4_word)259, (ts4_word)(ts4_word)lbl_8352CA04);
    }
    return ((*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 200))) + (a0 << 1))) & 259);
}

/* Loader_DLL.xex 0x833F7858: addr lbl_8352C928, u32@0xc8 */
ts4_word ts4_addr_lbl_8352C928_833F7858(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352C928) + 200)))) & 259);
}

/* Loader_DLL.xex 0x833F7878: if_addr lbl_8352CA04, u32@lbl_8352CA04, u32@0xac, u32@0xc8, fn_833FAED8 */
ts4_word ts4_if_addr_lbl_8352CA04_833F7878(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)lbl_8352CA04;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 172);
    if ((int)t2 > 1) {
        return fn_833FAED8((ts4_word)a0, (ts4_word)1, (ts4_word)(ts4_word)lbl_8352CA04);
    }
    return ((*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 200))) + (a0 << 1))) & 0x1);
}

/* Loader_DLL.xex 0x833F78B0: addr lbl_8352C928, u32@0xc8 */
ts4_word ts4_addr_lbl_8352C928_833F78B0(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352C928) + 200)))) & 0x1);
}

/* Loader_DLL.xex 0x833F78D0: if_addr lbl_8352CA04, u32@lbl_8352CA04, u32@0xac, u32@0xc8, fn_833FAED8 */
ts4_word ts4_if_addr_lbl_8352CA04_833F78D0(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)lbl_8352CA04;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 172);
    if ((int)t2 > 1) {
        return fn_833FAED8((ts4_word)a0, (ts4_word)2, (ts4_word)(ts4_word)lbl_8352CA04);
    }
    return ((*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 200))) + (a0 << 1))) & 0x2);
}

/* Loader_DLL.xex 0x833F7908: addr lbl_8352C928, u32@0xc8 */
ts4_word ts4_addr_lbl_8352C928_833F7908(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352C928) + 200)))) & 0x2);
}

/* Loader_DLL.xex 0x833F7928: if_addr lbl_8352CA04, u32@lbl_8352CA04, u32@0xac, u32@0xc8, fn_833FAED8 */
ts4_word ts4_if_addr_lbl_8352CA04_833F7928(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)lbl_8352CA04;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 172);
    if ((int)t2 > 1) {
        return fn_833FAED8((ts4_word)a0, (ts4_word)4, (ts4_word)(ts4_word)lbl_8352CA04);
    }
    return ((*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 200))) + (a0 << 1))) & 0x4);
}

/* Loader_DLL.xex 0x833F7960: addr lbl_8352C928, u32@0xc8 */
ts4_word ts4_addr_lbl_8352C928_833F7960(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352C928) + 200)))) & 0x4);
}

/* Loader_DLL.xex 0x833F7980: if_addr lbl_8352CA04, u32@lbl_8352CA04, u32@0xac, u32@0xc8, fn_833FAED8 */
ts4_word ts4_if_addr_lbl_8352CA04_833F7980(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)lbl_8352CA04;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 172);
    if ((int)t2 > 1) {
        return fn_833FAED8((ts4_word)a0, (ts4_word)128, (ts4_word)(ts4_word)lbl_8352CA04);
    }
    return ((*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 200))) + (a0 << 1))) & 0x80);
}

/* Loader_DLL.xex 0x833F79B8: addr lbl_8352C928, u32@0xc8 */
ts4_word ts4_addr_lbl_8352C928_833F79B8(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352C928) + 200)))) & 0x80);
}

/* Loader_DLL.xex 0x833F79D8: if_addr lbl_8352CA04, u32@lbl_8352CA04, u32@0xac, u32@0xc8, fn_833FAED8 */
ts4_word ts4_if_addr_lbl_8352CA04_833F79D8(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)lbl_8352CA04;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 172);
    if ((int)t2 > 1) {
        return fn_833FAED8((ts4_word)a0, (ts4_word)8, (ts4_word)(ts4_word)lbl_8352CA04);
    }
    return ((*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 200))) + (a0 << 1))) & 0x8);
}

/* Loader_DLL.xex 0x833F7A10: addr lbl_8352C928, u32@0xc8 */
ts4_word ts4_addr_lbl_8352C928_833F7A10(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352C928) + 200)))) & 0x8);
}

/* Loader_DLL.xex 0x833F7A30: if_addr lbl_8352CA04, u32@lbl_8352CA04, u32@0xac, u32@0xc8, fn_833FAED8 */
ts4_word ts4_if_addr_lbl_8352CA04_833F7A30(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)lbl_8352CA04;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 172);
    if ((int)t2 > 1) {
        return fn_833FAED8((ts4_word)a0, (ts4_word)16, (ts4_word)(ts4_word)lbl_8352CA04);
    }
    return ((*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 200))) + (a0 << 1))) & 0x10);
}

/* Loader_DLL.xex 0x833F7A68: addr lbl_8352C928, u32@0xc8 */
ts4_word ts4_addr_lbl_8352C928_833F7A68(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352C928) + 200)))) & 0x10);
}

/* Loader_DLL.xex 0x833F7A88: if_addr lbl_8352CA04, u32@lbl_8352CA04, u32@0xac, u32@0xc8, fn_833FAED8 */
ts4_word ts4_if_addr_lbl_8352CA04_833F7A88(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)lbl_8352CA04;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 172);
    if ((int)t2 > 1) {
        return fn_833FAED8((ts4_word)a0, (ts4_word)263, (ts4_word)(ts4_word)lbl_8352CA04);
    }
    return ((*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 200))) + (a0 << 1))) & 263);
}

/* Loader_DLL.xex 0x833F7AC0: addr lbl_8352C928, u32@0xc8 */
ts4_word ts4_addr_lbl_8352C928_833F7AC0(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352C928) + 200)))) & 263);
}

/* Loader_DLL.xex 0x833F7AE0: if_addr lbl_8352CA04, u32@lbl_8352CA04, u32@0xac, u32@0xc8, fn_833FAED8 */
ts4_word ts4_if_addr_lbl_8352CA04_833F7AE0(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)lbl_8352CA04;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 172);
    if ((int)t2 > 1) {
        return fn_833FAED8((ts4_word)a0, (ts4_word)343, (ts4_word)(ts4_word)lbl_8352CA04);
    }
    return ((*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 200))) + (a0 << 1))) & 343);
}

/* Loader_DLL.xex 0x833F7B18: addr lbl_8352C928, u32@0xc8 */
ts4_word ts4_addr_lbl_8352C928_833F7B18(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352C928) + 200)))) & 343);
}

/* Loader_DLL.xex 0x833F7B38: if_addr lbl_8352CA04, u32@lbl_8352CA04, u32@0xac, u32@0xc8, fn_833FAED8 */
ts4_word ts4_if_addr_lbl_8352CA04_833F7B38(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)lbl_8352CA04;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 172);
    if ((int)t2 > 1) {
        return fn_833FAED8((ts4_word)a0, (ts4_word)279, (ts4_word)(ts4_word)lbl_8352CA04);
    }
    return ((*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 200))) + (a0 << 1))) & 279);
}

/* Loader_DLL.xex 0x833F7B70: addr lbl_8352C928, u32@0xc8 */
ts4_word ts4_addr_lbl_8352C928_833F7B70(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352C928) + 200)))) & 279);
}

/* Loader_DLL.xex 0x833F7B90: if_addr lbl_8352CA04, u32@lbl_8352CA04, u32@0xac, u32@0xc8, fn_833FAED8 */
ts4_word ts4_if_addr_lbl_8352CA04_833F7B90(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)lbl_8352CA04;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 172);
    if ((int)t2 > 1) {
        return fn_833FAED8((ts4_word)a0, (ts4_word)32, (ts4_word)(ts4_word)lbl_8352CA04);
    }
    return ((*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 200))) + (a0 << 1))) & 0x20);
}

/* Loader_DLL.xex 0x833F7BC8: addr lbl_8352C928, u32@0xc8 */
ts4_word ts4_addr_lbl_8352C928_833F7BC8(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352C928) + 200)))) & 0x20);
}

/* Loader_DLL.xex 0x833FAF10: addr lbl_8352C928, u32@0xc8 */
ts4_word ts4_addr_lbl_8352C928_833FAF10(ts4_word a0, ts4_word a1)
{
    return ((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8352C928) + 200)))) & a1);
}

/* Loader_DLL.xex 0x833FC158: if_set u32@0x0 */
ts4_word ts4_if_set_u32_off0_833FC158(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p1;

    p1 = (ts4_word)0;
    if ((ts4_word)(a0 + a1) < (ts4_word)a0 || (ts4_word)(a0 + a1) < (ts4_word)a1) {
        p1 = (ts4_word)1;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(a0 + a1);
    return p1;
}

/* Loader_DLL.xex 0x83400458: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_83400458(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_835446E8;
    return ((~(t1 | t1)) & 0x1);
}

/* Loader_DLL.xex 0x83400470: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_83400470(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_835446E8;
    return (((~(t1 | t1)) >> 1) & 0x1);
}

/* Loader_DLL.xex 0x83400488: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_83400488(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_835446E8;
    return (((~(t1 | t1)) >> 17) & 0x1);
}

/* Loader_DLL.xex 0x834004A0: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_834004A0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_835446E8;
    return (((~(t1 | t1)) >> 2) & 0x1);
}

/* Loader_DLL.xex 0x834004B8: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_834004B8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_835446E8;
    return (((~(t1 | t1)) >> 3) & 0x1);
}

/* Loader_DLL.xex 0x834004D0: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_834004D0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_835446E8;
    return (((~(t1 | t1)) >> 4) & 0x1);
}

/* Loader_DLL.xex 0x83400508: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_83400508(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_835446E8;
    return (((~(t1 | t1)) >> 7) & 0x1);
}

/* Loader_DLL.xex 0x83400520: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_83400520(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_835446E8;
    return (((~(t1 | t1)) >> 8) & 0x1);
}

/* Loader_DLL.xex 0x83400538: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_83400538(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_835446E8;
    return (((~(t1 | t1)) >> 9) & 0x1);
}

/* Loader_DLL.xex 0x83400580: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_83400580(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_835446E8;
    return (((~(t1 | t1)) >> 15) & 0x1);
}

/* Loader_DLL.xex 0x834005A8: get u32@lbl_835446E8 */
ts4_word ts4_get_u32_lbl_835446E8_834005A8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_835446E8;
    return (((~(t1 | t1)) >> 18) & 0x1);
}

/* Loader_DLL.xex 0x834005C0: if_get u32@lbl_835446E8, lbl_83071A88 */
ts4_word ts4_if_get_u32_lbl_835446E8_834005C0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_835446E8;
    if ((int)((~(t1 | t1)) & 0x1) != 0) {
        return (*(ts4_word *)((char *)(ts4_word)((a0 << 2)) + (ts4_word)lbl_83071A88));
    }
    return ((*(ts4_word *)((char *)(ts4_word)((a0 << 2)) + (ts4_word)lbl_83071A88)) + 2);
}

/* Loader_DLL.xex 0x83400700: get u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
void ts4_get_u32_off0_83400700(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    return;
}

/* Loader_DLL.xex 0x83400738: get u32@0x0 */
ts4_word ts4_get_u32_off0_83400738(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) == 0);
}

/* Loader_DLL.xex 0x83400758: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_83400758(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) | 8388608);
    return;
}

/* Loader_DLL.xex 0x834007A0: if_get u32@0x0, u32@0x4, u32@0x4 */
void ts4_if_get_u32_off0_834007A0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) | 4194304);
    return;
}

/* Loader_DLL.xex 0x834007E8: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_834007E8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) | 1048576);
    return;
}

/* Loader_DLL.xex 0x83400818: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_83400818(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) | 524288);
    return;
}

/* Loader_DLL.xex 0x83400838: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_83400838(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) | 262144);
    return;
}

/* Loader_DLL.xex 0x83400858: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_83400858(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) | 131072);
    return;
}

/* Loader_DLL.xex 0x83400878: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_83400878(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) | 65536);
    return;
}

/* Loader_DLL.xex 0x83400888: if_get u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_83400888(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        return t1;
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x834008A8: if_get u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off0_834008A8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        return t1;
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x834008C8: if_get u32@0x0, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_off0_834008C8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        return a1;
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x83400920: get u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
void ts4_get_u32_off0_83400920(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    return;
}

/* Loader_DLL.xex 0x83400938: get u32@0x0 */
ts4_word ts4_get_u32_off0_83400938(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + -9) == 0);
}

/* Loader_DLL.xex 0x83400960: addr lbl_83071C50, u32@0x0 */
void ts4_addr_lbl_83071C50_83400960(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83071C50;
    return;
}

/* Loader_DLL.xex 0x83400970: set u8@0x4, lbl_83071C5C, u32@0x0 */
void ts4_set_u8_off4_83400970(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83071C5C;
    return;
}

/* Loader_DLL.xex 0x83400B80: set u32@0x4, u32@0x8, lbl_83071C80, u32@0xc, u32@0x0 */
void ts4_set_u32_off4_83400B80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83071C80;
    return;
}

/* Loader_DLL.xex 0x8340AED8: if_call_seq NtSetEvent, fn_8340F088 */
ts4_word ts4_if_call_seq_NtSetEvent_8340AED8(ts4_word a0)
{
    ts4_word p3;
    int t1;

    t1 = NtSetEvent((ts4_word)a0, (ts4_word)0);
    if ((int)t1 >= 0) {
        p3 = (ts4_word)1;
    } else {
        fn_8340F088((ts4_word)t1);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Loader_DLL.xex 0x8340AF18: if_call_seq XexUnloadImage, fn_834141B8 */
ts4_word ts4_if_call_seq_XexUnloadImage_8340AF18(void)
{
    ts4_word p3;
    int t1;

    t1 = XexUnloadImage();
    if ((int)t1 < 0) {
        fn_834141B8((ts4_word)t1);
        p3 = (ts4_word)0;
    } else {
        p3 = (ts4_word)1;
    }
    return p3;
}

/* Loader_DLL.xex 0x8340B058: if_call_seq XexGetModuleSection, fn_834141B8 */
ts4_word ts4_if_call_seq_XexGetModuleSection_8340B058(void)
{
    ts4_word p3;
    int t1;

    t1 = XexGetModuleSection();
    if ((int)t1 < 0) {
        fn_834141B8((ts4_word)t1);
        p3 = (ts4_word)0;
    } else {
        p3 = (ts4_word)1;
    }
    return p3;
}

/* Loader_DLL.xex 0x8340B090: if_call_seq XexGetModuleHandle, fn_8340F088 */
ts4_word ts4_if_call_seq_XexGetModuleHandle_8340B090(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[2];
    int t1;
    ts4_word t2;

    t1 = XexGetModuleHandle((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 < 0) {
        fn_8340F088((ts4_word)t1);
        p4 = (ts4_word)0;
    } else {
        t2 = loc50[0];
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x8340B840: tailcall XamReadTileToTexture */
ts4_word ts4_tailcall_XamReadTileToTexture_8340B840(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return XamReadTileToTexture((ts4_word)(((a1 == 0) ^ 1) + 2), (ts4_word)0, (ts4_word)0, (ts4_word)a0, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Loader_DLL.xex 0x8340CA48: if_call_seq NtSuspendThread, fn_834141B8 */
ts4_word ts4_if_call_seq_NtSuspendThread_8340CA48(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[2];
    int t1;
    ts4_word t2;

    t1 = NtSuspendThread((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 < 0) {
        fn_834141B8((ts4_word)t1);
        p4 = (ts4_word)-1;
    } else {
        t2 = loc50[0];
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x8340CE10: if_call_seq NtResumeThread, fn_8340F088 */
ts4_word ts4_if_call_seq_NtResumeThread_8340CE10(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[2];
    int t1;
    ts4_word t2;

    t1 = NtResumeThread((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 < 0) {
        fn_8340F088((ts4_word)t1);
        p4 = (ts4_word)-1;
    } else {
        t2 = loc50[0];
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x8340D0D8: if_call_seq NtReleaseMutant, fn_8340F088 */
ts4_word ts4_if_call_seq_NtReleaseMutant_8340D0D8(ts4_word a0)
{
    ts4_word p3;
    int t1;

    t1 = NtReleaseMutant((ts4_word)a0, (ts4_word)0);
    if ((int)t1 >= 0) {
        p3 = (ts4_word)1;
    } else {
        fn_8340F088((ts4_word)t1);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Loader_DLL.xex 0x8340D2A8: if_tailcall XamEnumerate */
ts4_word ts4_if_tailcall_XamEnumerate_8340D2A8(ts4_word a0, ts4_word a1)
{
    if ((int)(a1 & 0xffffffdf) == 0) {
        return XamEnumerate((ts4_word)a0);
    }
    return 87;
}

/* Loader_DLL.xex 0x8340D340: if_call_seq NtPulseEvent, fn_834141B8 */
ts4_word ts4_if_call_seq_NtPulseEvent_8340D340(ts4_word a0)
{
    ts4_word p3;
    int t1;

    t1 = NtPulseEvent((ts4_word)a0, (ts4_word)0);
    if ((int)t1 >= 0) {
        p3 = (ts4_word)1;
    } else {
        fn_834141B8((ts4_word)t1);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Loader_DLL.xex 0x8340D498: if_call_seq NtReleaseSemaphore, fn_834141B8 */
ts4_word ts4_if_call_seq_NtReleaseSemaphore_8340D498(void)
{
    ts4_word p3;
    int t1;

    t1 = NtReleaseSemaphore();
    if ((int)t1 >= 0) {
        p3 = (ts4_word)1;
    } else {
        fn_834141B8((ts4_word)t1);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Loader_DLL.xex 0x8340D850: if_tail fn_83415CD0, fn_8340D088 */
ts4_word ts4_if_tail_fn_83415CD0_8340D850(ts4_word a0, ts4_word a1)
{
    if ((int)(a1 & 0x80000000) != 0) {
        return fn_8340D088((ts4_word)a0);
    }
    return fn_83415CD0((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340F0E0: if_call_seq NtClearEvent, fn_8340F088 */
ts4_word ts4_if_call_seq_NtClearEvent_8340F0E0(void)
{
    ts4_word p3;
    int t1;

    t1 = NtClearEvent();
    if ((int)t1 >= 0) {
        p3 = (ts4_word)1;
    } else {
        fn_8340F088((ts4_word)t1);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Loader_DLL.xex 0x8340F2E0: get u32@0x0, u32@0x4, u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_8340F2E0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)t2;
    return ((t1 - t2) == 0);
}

/* Loader_DLL.xex 0x8340F6E0: get u32@0x18, u32@0x4c, u32@0x0, u32@0x18, u32@0x4c, u32@0x4 */
void ts4_get_u32_off18_8340F6E0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 76));
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 76) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83410050: if_get u8@0x5, u16@0x0 */
ts4_word ts4_if_get_u8_off5_83410050(ts4_word a0)
{
    unsigned char t1;
    unsigned short t2;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 5);
    if ((int)(t1 & 0x8) != 0) {
        return (a0 + -24);
    }
    t2 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    return ((((t2 << 4) | (t2 >> 28)) + a0) + -16);
}

/* Loader_DLL.xex 0x83410120: get u32@0x10 */
ts4_word ts4_get_u32_off10_83410120(ts4_word a0)
{
    return ((((4009689088) | 61183) - (*(ts4_word *)((char *)(ts4_word)(a0) + 16))) == 0);
}

/* Loader_DLL.xex 0x83413F70: get u32@0x0, u32@0x4, u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_83413F70(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)t2;
    return ((t1 - t2) == 0);
}

/* Loader_DLL.xex 0x834140A0: if_call_seq NtFlushBuffersFile, fn_8340F088 */
ts4_word ts4_if_call_seq_NtFlushBuffersFile_834140A0(ts4_word a0)
{
    ts4_word p3;
    ts4_word loc50[2];
    int t1;

    t1 = NtFlushBuffersFile((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 >= 0) {
        p3 = (ts4_word)1;
    } else {
        fn_8340F088((ts4_word)t1);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Loader_DLL.xex 0x83415C90: if_call_seq fn_83410140, fn_8340F068 */
ts4_word ts4_if_call_seq_fn_83410140_83415C90(void)
{
    ts4_word p3;
    ts4_word t1;

    t1 = fn_83410140();
    if ((ts4_word)t1 == 0) {
        p3 = (ts4_word)1;
    } else {
        fn_8340F068((ts4_word)6);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Loader_DLL.xex 0x83416468: addr lbl_83086960 */
ts4_word ts4_addr_lbl_83086960_83416468(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_83086960) + a0));
}

/* Loader_DLL.xex 0x83416478: addr lbl_83086960 */
ts4_word ts4_addr_lbl_83086960_83416478(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((a0 & 0x3f)) + (ts4_word)lbl_83086960));
}

/* Loader_DLL.xex 0x83417788: fn  */
ts4_word ts4_fn_83417788(ts4_word a0)
{
    return (((a0 + -1) & a0) == 0);
}

/* Loader_DLL.xex 0x834177B0: fn  */
ts4_word ts4_fn_834177B0(ts4_word a0, ts4_word a1)
{
    return (((a0 + a1) + -1) & ~(a1 + -1));
}

/* Loader_DLL.xex 0x8341B4D0: get u32@lbl_8352D368 */
ts4_word ts4_get_u32_lbl_8352D368_8341B4D0(void)
{
    return ((*(ts4_word *)lbl_8352D368) == 0);
}

/* Loader_DLL.xex 0x834234E8: get u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off0_834234E8(ts4_word a0)
{
    ts4_word loc50[50];
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Loader_DLL.xex 0x83423540: get u32@0x18, u32@0x0, u32@0x4, u32@0x0, u32@0x4 */
void ts4_get_u32_off18_83423540(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(t2 + a1);
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(t3 - a1);
    return;
}

/* Loader_DLL.xex 0x8342C008: get  */
void ts4_get_8342C008(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 12));
    return;
}

/* Loader_DLL.xex 0x8343D6D8: call_seq fn_8343C098, lbl_83073B3C, u32@0x0 */
ts4_word ts4_call_seq_fn_8343C098_8343D6D8(ts4_word a0, ts4_word a1)
{
    fn_8343C098((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073B3C;
    return a0;
}

/* Loader_DLL.xex 0x8343D720: call_seq fn_8343C098, lbl_83073B4C, u32@0x0 */
ts4_word ts4_call_seq_fn_8343C098_8343D720(ts4_word a0, ts4_word a1)
{
    fn_8343C098((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073B4C;
    return a0;
}

/* Loader_DLL.xex 0x8343D768: call_seq fn_8343C098, lbl_83073B5C, u32@0x0 */
ts4_word ts4_call_seq_fn_8343C098_8343D768(ts4_word a0, ts4_word a1)
{
    fn_8343C098((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073B5C;
    return a0;
}

/* Loader_DLL.xex 0x8343E2F8: call_seq fn_8343B6B8, lbl_83073B6C, u32@0x0 */
ts4_word ts4_call_seq_fn_8343B6B8_8343E2F8(ts4_word a0)
{
    fn_8343B6B8();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073B6C;
    return a0;
}

/* Loader_DLL.xex 0x8343E340: call_seq fn_8343B6B8, lbl_83073B7C, u32@0x0 */
ts4_word ts4_call_seq_fn_8343B6B8_8343E340(ts4_word a0)
{
    fn_8343B6B8();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073B7C;
    return a0;
}

/* Loader_DLL.xex 0x8343E388: call_seq fn_8343B6B8, lbl_83073B8C, u32@0x0 */
ts4_word ts4_call_seq_fn_8343B6B8_8343E388(ts4_word a0)
{
    fn_8343B6B8();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073B8C;
    return a0;
}

/* Loader_DLL.xex 0x8343E3D0: call_seq fn_8343B6B8, lbl_83073B9C, u32@0x0 */
ts4_word ts4_call_seq_fn_8343B6B8_8343E3D0(ts4_word a0)
{
    fn_8343B6B8();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073B9C;
    return a0;
}

/* Loader_DLL.xex 0x8343F130: get u32@0x0 */
ts4_word ts4_get_u32_off0_8343F130(ts4_word a0)
{
    return ((((271187968) | 4352) - ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) & 0xffffff00)) == 0);
}

/* Loader_DLL.xex 0x8343F348: if_get u32@0x0 */
ts4_word ts4_if_get_u32_off0_8343F348(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return a0;
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x8343F590: if_get u32@0xc, lbl_83073BC8, u32@0x0, u8@-0x1, u32@0xc, u32@0xc */
ts4_word ts4_if_get_u32_offc_8343F590(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073BC8;
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t1 - (*(unsigned char *)((char *)(ts4_word)(t1) + -1)));
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073BAC;
    return fn_8340D830((ts4_word)t5, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8343F868: addr lbl_83073BAC, u32@0xc, u32@0x0, u32@0x8, u32@0x4 */
void ts4_addr_lbl_83073BAC_8343F868(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073BAC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8343F9C8: addr lbl_83073BC8, u32@0xc, u32@0x0, u32@0x8, u32@0x4 */
void ts4_addr_lbl_83073BC8_8343F9C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073BC8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8343F9F0: addr lbl_83073BE4, u32@0xc, u32@0x0, u32@0x8, u32@0x4, u32@0x10 */
void ts4_addr_lbl_83073BE4_8343F9F0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073BE4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83445560: set u32@0x624 */
void ts4_set_u32_off624_83445560(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1572) = (ts4_word)((((a1) >> 31) + -1) & a1);
    return;
}

/* Loader_DLL.xex 0x83445C00: get u32@0x55c, u32@0x5a4, u32@0x55c */
void ts4_get_u32_off55c_83445C00(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1372);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1444) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1372) = (ts4_word)(t1 | 2);
    return;
}

/* Loader_DLL.xex 0x83445C18: get u32@0x55c, u32@0x5b0, u32@0x55c */
void ts4_get_u32_off55c_83445C18(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1372);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1456) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1372) = (ts4_word)(t1 | 4);
    return;
}

/* Loader_DLL.xex 0x83445C30: get u32@0x55c, u32@0x5b4, u32@0x55c */
void ts4_get_u32_off55c_83445C30(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1372);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1460) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1372) = (ts4_word)(t1 | 1);
    return;
}

/* Loader_DLL.xex 0x834461A8: if_get u32@0x8, u32@0x10, u16@0x14, u32@0x8 */
void ts4_if_get_u32_off8_834461A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    if ((ts4_word)a0 == 0) {
        return;
    }
    if ((ts4_word)a1 == 0) {
        return;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)a2;
    *(unsigned short *)((char *)(ts4_word)(a1) + 20) = (unsigned short)a3;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t1 | 8);
    return;
}

/* Loader_DLL.xex 0x834461D0: if_get u32@0x8, u8@0x2c, u32@0x8 */
void ts4_if_get_u32_off8_834461D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    if ((ts4_word)a0 == 0) {
        return;
    }
    if ((ts4_word)a1 == 0) {
        return;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(unsigned char *)((char *)(ts4_word)(a1) + 44) = (unsigned char)a2;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t1 | 2048);
    return;
}

/* Loader_DLL.xex 0x83446878: if_get u32@0x55c, fn_83455050 */
ts4_word ts4_if_get_u32_off55c_83446878(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1372);
    if ((int)(t1 & 0x40) != 0) {
        return a0;
    }
    return fn_83455050((ts4_word)a0);
}

/* Loader_DLL.xex 0x83447358: if_get u32@0x8 */
ts4_word ts4_if_get_u32_off8_83447358(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        if ((int)(t1 & 0x1) != 0 && (ts4_word)a2 != 0) {
            *(double *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a1) + 40));
            return 1;
        }
        return 0;
    }
    return 0;
}

/* Loader_DLL.xex 0x83447398: if_get u32@0x8, u8@0x2c, u32@0x0 */
ts4_word ts4_if_get_u32_off8_83447398(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        if ((int)(t1 & 0x800) != 0 && (ts4_word)a2 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a1) + 44));
            return 2048;
        }
        return 0;
    }
    return 0;
}
