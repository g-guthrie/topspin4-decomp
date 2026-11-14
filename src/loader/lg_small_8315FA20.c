/* Loader_DLL.xex 0x8315FA20-0x831884F0, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char lbl_83531690[];
ts4_word fn_83161838();
ts4_word fn_831619A8();
ts4_word fn_831631A8();
ts4_word fn_83166790();
ts4_word fn_8316F128();
ts4_word fn_83170F60();
ts4_word fn_83173298();
ts4_word fn_83174FE0();
ts4_word fn_831754C0();
ts4_word fn_83175540();
ts4_word fn_831755F8();
ts4_word fn_831767A0();
ts4_word fn_83176830();
ts4_word fn_83176F40();
ts4_word fn_831791F0();
ts4_word fn_8317AB70();
ts4_word fn_8317B410();
ts4_word fn_8317D908();
ts4_word fn_8317DBA0();
ts4_word fn_8317E240();
ts4_word fn_8317E2A8();
ts4_word fn_8317EC40();
ts4_word fn_8317FF90();
ts4_word fn_831803D8();
ts4_word fn_83180660();
ts4_word fn_83180808();
ts4_word fn_831808E8();
ts4_word fn_83180AC0();
ts4_word fn_83181010();
ts4_word fn_831821A0();
ts4_word fn_83182410();
ts4_word fn_83182BA0();
ts4_word fn_83183080();
ts4_word fn_83183160();
ts4_word fn_83183360();
ts4_word fn_83183418();
ts4_word fn_83183EF8();
ts4_word fn_831841D8();
ts4_word fn_83184218();
ts4_word fn_83184570();
ts4_word fn_83184ED8();
ts4_word fn_83185BF0();
ts4_word fn_83185C28();
ts4_word fn_83186640();
ts4_word fn_83186A18();
ts4_word fn_83186C48();
ts4_word fn_83187018();
ts4_word fn_83187058();
ts4_word fn_83187B88();
ts4_word fn_83187D68();
ts4_word fn_83187EB8();
ts4_word fn_83187EF8();
ts4_word fn_83188320();
ts4_word fn_83189480();
ts4_word fn_83189588();
ts4_word fn_83189608();
ts4_word fn_83189690();
ts4_word fn_83189708();
ts4_word fn_83189770();
ts4_word fn_831897E0();
ts4_word fn_83189870();
ts4_word fn_831898F0();
ts4_word fn_8318A108();
ts4_word fn_8318A240();
ts4_word fn_8318A2A8();
ts4_word fn_8318A310();
ts4_word fn_8318A370();
ts4_word fn_8318A3F0();
ts4_word fn_8318A518();
ts4_word fn_8318ABC8();
ts4_word fn_8318AE90();
ts4_word fn_8318B860();
ts4_word fn_8319D618();
ts4_word fn_8319E048();
ts4_word fn_831A3268();
ts4_word fn_831A3308();
ts4_word fn_831A5178();
ts4_word fn_831B9FB8();

/* Loader_DLL.xex 0x8315FA20: tailcall fn_831619A8 */
ts4_word ts4_tailcall_fn_831619A8_8315FA20(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_831619A8((ts4_word)a1);
}

/* Loader_DLL.xex 0x83162DC8: fn  */
ts4_word ts4_fn_83162DC8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83163180: call_seq fn_83166790, fn_83161838 */
ts4_word ts4_call_seq_fn_83166790_83163180(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_83166790();
    t2 = fn_83161838((ts4_word)t1);
    return t2;
}

/* Loader_DLL.xex 0x83163260: tailcall fn_831631A8 */
ts4_word ts4_tailcall_fn_831631A8_83163260(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_831631A8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)-1);
}

/* Loader_DLL.xex 0x83163338: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_83163338(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a0;
    return;
}

/* Loader_DLL.xex 0x831732A0: tailcall fn_83173298 */
ts4_word ts4_tailcall_fn_83173298_831732A0(ts4_word a0)
{
    return fn_83173298((ts4_word)(a0 + -8));
}

/* Loader_DLL.xex 0x83175328: if_get u32@0x34, fn_83188320 */
ts4_word ts4_if_get_u32_off34_83175328(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0) {
        return fn_83188320((ts4_word)t1);
    }
    return 0;
}

/* Loader_DLL.xex 0x83175340: set u32@0x3c, u32@0x44, u32@0x40 */
void ts4_set_u32_off3c_83175340(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)a2;
    return;
}

/* Loader_DLL.xex 0x83175350: fn  */
ts4_word ts4_fn_83175350(ts4_word a0)
{
    return (a0 + 4);
}

/* Loader_DLL.xex 0x83175358: get u32@0x1c */
ts4_word ts4_get_u32_off1c_83175358(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return ((*(ts4_word *)((char *)(ts4_word)(a1) + 28)) != 0);
}

/* Loader_DLL.xex 0x831753F8: get u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_831753F8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83175408: if_tail fn_83174FE0, fn_83174FE0 */
ts4_word ts4_if_tail_fn_83174FE0_83175408(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_83174FE0((ts4_word)a2);
    }
    return fn_83174FE0((ts4_word)a2);
}

/* Loader_DLL.xex 0x83175420: fn  */
void ts4_fn_83175420(void)
{
    return;
}

/* Loader_DLL.xex 0x83175428: if_tail fn_83174FE0, fn_83174FE0 */
ts4_word ts4_if_tail_fn_83174FE0_83175428(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_83174FE0((ts4_word)a2);
    }
    return fn_83174FE0((ts4_word)a2);
}

/* Loader_DLL.xex 0x83175440: if_tail fn_83174FE0, fn_83174FE0 */
ts4_word ts4_if_tail_fn_83174FE0_83175440(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_83174FE0((ts4_word)a2);
    }
    return fn_83174FE0((ts4_word)a2);
}

/* Loader_DLL.xex 0x83175458: if_tail fn_83174FE0, fn_83174FE0 */
ts4_word ts4_if_tail_fn_83174FE0_83175458(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_83174FE0((ts4_word)a2);
    }
    return fn_83174FE0((ts4_word)a2);
}

/* Loader_DLL.xex 0x83175470: get u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_83175470(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83175480: get u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_83175480(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83175490: get u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_83175490(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831754A0: fn  */
void ts4_fn_831754A0(void)
{
    return;
}

/* Loader_DLL.xex 0x831754A8: fn  */
void ts4_fn_831754A8(void)
{
    return;
}

/* Loader_DLL.xex 0x831754B0: fn  */
void ts4_fn_831754B0(void)
{
    return;
}

/* Loader_DLL.xex 0x831754B8: fn  */
void ts4_fn_831754B8(void)
{
    return;
}

/* Loader_DLL.xex 0x83175D78: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_83175D78(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a1, (ts4_word)(546766848), (ts4_word)8);
}

/* Loader_DLL.xex 0x83175FC0: if_tail fn_83174FE0, fn_83174FE0 */
ts4_word ts4_if_tail_fn_83174FE0_83175FC0(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_83174FE0((ts4_word)a2);
    }
    return fn_83174FE0((ts4_word)a2);
}

/* Loader_DLL.xex 0x83176268: fn  */
ts4_word ts4_fn_83176268(ts4_word a0)
{
    return (a0 + 584);
}

/* Loader_DLL.xex 0x83176688: if_tailcall fn_83174FE0 */
ts4_word ts4_if_tailcall_fn_83174FE0_83176688(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return fn_83174FE0((ts4_word)a1);
}

/* Loader_DLL.xex 0x83176BB8: call_seq u32@0x0, fn_83176830, fn_831767A0 */
ts4_word ts4_call_seq_u32_off0_83176BB8(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    fn_83176830((ts4_word)(a0 + 80));
    t2 = fn_831767A0((ts4_word)(a0 + 8));
    return t2;
}

/* Loader_DLL.xex 0x83176CE8: tailcall fn_8318B860 */
ts4_word ts4_tailcall_fn_8318B860_83176CE8(ts4_word a0)
{
    return fn_8318B860((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176CF0: tailcall fn_8318ABC8 */
ts4_word ts4_tailcall_fn_8318ABC8_83176CF0(ts4_word a0)
{
    return fn_8318ABC8((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176CF8: tailcall fn_8318A240 */
ts4_word ts4_tailcall_fn_8318A240_83176CF8(ts4_word a0)
{
    return fn_8318A240((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176D00: tailcall fn_8318A2A8 */
ts4_word ts4_tailcall_fn_8318A2A8_83176D00(ts4_word a0)
{
    return fn_8318A2A8((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176D08: tailcall fn_8318A310 */
ts4_word ts4_tailcall_fn_8318A310_83176D08(ts4_word a0)
{
    return fn_8318A310((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176D10: tailcall fn_8318A370 */
ts4_word ts4_tailcall_fn_8318A370_83176D10(ts4_word a0)
{
    return fn_8318A370((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176D18: tailcall fn_8318A3F0 */
ts4_word ts4_tailcall_fn_8318A3F0_83176D18(ts4_word a0)
{
    return fn_8318A3F0((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176D20: tailcall fn_83189588 */
ts4_word ts4_tailcall_fn_83189588_83176D20(ts4_word a0)
{
    return fn_83189588((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176D28: tailcall fn_83189608 */
ts4_word ts4_tailcall_fn_83189608_83176D28(ts4_word a0, ts4_word a1)
{
    return fn_83189608((ts4_word)(a0 + 4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x83176D30: tailcall fn_83189690 */
ts4_word ts4_tailcall_fn_83189690_83176D30(ts4_word a0)
{
    return fn_83189690((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176D38: tailcall fn_83189708 */
ts4_word ts4_tailcall_fn_83189708_83176D38(ts4_word a0)
{
    return fn_83189708((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176D40: tailcall fn_83189770 */
ts4_word ts4_tailcall_fn_83189770_83176D40(ts4_word a0, ts4_word a1)
{
    return fn_83189770((ts4_word)(a0 + 4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x83176D48: tailcall fn_83189870 */
ts4_word ts4_tailcall_fn_83189870_83176D48(ts4_word a0)
{
    return fn_83189870((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176D50: tailcall fn_8318A518 */
ts4_word ts4_tailcall_fn_8318A518_83176D50(ts4_word a0)
{
    return fn_8318A518((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176D58: tailcall fn_831898F0 */
ts4_word ts4_tailcall_fn_831898F0_83176D58(ts4_word a0)
{
    return fn_831898F0((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176D60: tailcall fn_8318A108 */
ts4_word ts4_tailcall_fn_8318A108_83176D60(ts4_word a0)
{
    return fn_8318A108((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83176D68: fn  */
void ts4_fn_83176D68(void)
{
    return;
}

/* Loader_DLL.xex 0x83176D70: fn  */
void ts4_fn_83176D70(void)
{
    return;
}

/* Loader_DLL.xex 0x83176D78: fn  */
void ts4_fn_83176D78(void)
{
    return;
}

/* Loader_DLL.xex 0x83176D80: fn  */
void ts4_fn_83176D80(void)
{
    return;
}

/* Loader_DLL.xex 0x83176D88: fn  */
ts4_word ts4_fn_83176D88(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83176D90: fn  */
ts4_word ts4_fn_83176D90(void)
{
    return ((2147483648) | 16389);
}

/* Loader_DLL.xex 0x83176DA0: fn  */
ts4_word ts4_fn_83176DA0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83176DA8: set u32@0x4 */
void ts4_set_u32_off4_83176DA8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83176DB0: get u32@0x8c */
ts4_word ts4_get_u32_off8c_83176DB0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 140));
}

/* Loader_DLL.xex 0x83176DB8: get u32@0xcc */
ts4_word ts4_get_u32_offcc_83176DB8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 204));
}

/* Loader_DLL.xex 0x83176E78: tailcall fn_83176F40 */
ts4_word ts4_tailcall_fn_83176F40_83176E78(ts4_word a0, ts4_word a1)
{
    return fn_83176F40((ts4_word)(a0 + -4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x83176EC0: tailcall fn_831754C0 */
ts4_word ts4_tailcall_fn_831754C0_83176EC0(ts4_word a0, ts4_word a1)
{
    return fn_831754C0((ts4_word)(a0 + -4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x83176EC8: tailcall fn_831755F8 */
ts4_word ts4_tailcall_fn_831755F8_83176EC8(ts4_word a0)
{
    return fn_831755F8((ts4_word)(a0 + -4));
}

/* Loader_DLL.xex 0x83176ED0: tailcall fn_83175540 */
ts4_word ts4_tailcall_fn_83175540_83176ED0(ts4_word a0)
{
    return fn_83175540((ts4_word)(a0 + -4));
}

/* Loader_DLL.xex 0x83177D20: get u32@0x4 */
ts4_word ts4_get_u32_off4_83177D20(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x831787A8: fn  */
void ts4_fn_831787A8(void)
{
    return;
}

/* Loader_DLL.xex 0x83178FF0: set u32@0x1c4, u32@0x1c8, u32@0x1d0 */
void ts4_set_u32_off1c4_83178FF0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 452) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 456) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 464) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83179008: fn  */
void ts4_fn_83179008(void)
{
    return;
}

/* Loader_DLL.xex 0x83179010: fn  */
void ts4_fn_83179010(void)
{
    return;
}

/* Loader_DLL.xex 0x83179018: set u32@0x1d0 */
void ts4_set_u32_off1d0_83179018(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 464) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83179028: fn  */
void ts4_fn_83179028(void)
{
    return;
}

/* Loader_DLL.xex 0x831790D0: if_get u32@0x18, u32@0x0 */
ts4_word ts4_if_get_u32_off18_831790D0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x831790F0: if_get u32@0x1c, u32@0x0 */
ts4_word ts4_if_get_u32_off1c_831790F0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x83179110: get u32@0x18 */
ts4_word ts4_get_u32_off18_83179110(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Loader_DLL.xex 0x83179118: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_83179118(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4));
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x831791D0: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_831791D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x831792C0: get u32@0x44 */
ts4_word ts4_get_u32_off44_831792C0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 68));
}

/* Loader_DLL.xex 0x831792C8: get u32@0x40 */
ts4_word ts4_get_u32_off40_831792C8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 64)) << 1);
}

/* Loader_DLL.xex 0x83179340: if_tail fn_831791F0, fn_831791F0 */
ts4_word ts4_if_tail_fn_831791F0_83179340(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_831791F0((ts4_word)a2);
    }
    return fn_831791F0((ts4_word)a2);
}

/* Loader_DLL.xex 0x83179358: if_tail fn_831791F0, fn_831791F0 */
ts4_word ts4_if_tail_fn_831791F0_83179358(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_831791F0((ts4_word)a2);
    }
    return fn_831791F0((ts4_word)a2);
}

/* Loader_DLL.xex 0x83179370: get u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_83179370(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83179380: get u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_83179380(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83179390: fn  */
void ts4_fn_83179390(void)
{
    return;
}

/* Loader_DLL.xex 0x83179398: fn  */
void ts4_fn_83179398(void)
{
    return;
}

/* Loader_DLL.xex 0x83179598: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_83179598(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a1, (ts4_word)(546766848), (ts4_word)8);
}

/* Loader_DLL.xex 0x83179760: if_tail fn_831791F0, fn_831791F0 */
ts4_word ts4_if_tail_fn_831791F0_83179760(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_831791F0((ts4_word)a2);
    }
    return fn_831791F0((ts4_word)a2);
}

/* Loader_DLL.xex 0x83179778: if_tail fn_831791F0, fn_831791F0 */
ts4_word ts4_if_tail_fn_831791F0_83179778(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_831791F0((ts4_word)a2);
    }
    return fn_831791F0((ts4_word)a2);
}

/* Loader_DLL.xex 0x83179790: if_tail fn_831791F0, fn_831791F0 */
ts4_word ts4_if_tail_fn_831791F0_83179790(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_831791F0((ts4_word)a2);
    }
    return fn_831791F0((ts4_word)a2);
}

/* Loader_DLL.xex 0x83179C98: if_tailcall fn_831791F0 */
ts4_word ts4_if_tailcall_fn_831791F0_83179C98(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return fn_831791F0((ts4_word)a1);
}

/* Loader_DLL.xex 0x8317AAE8: fn  */
ts4_word ts4_fn_8317AAE8(void)
{
    return 2;
}

/* Loader_DLL.xex 0x8317AAF0: tailcall fn_8317AB70 */
ts4_word ts4_tailcall_fn_8317AB70_8317AAF0(ts4_word a0, ts4_word a1)
{
    return fn_8317AB70((ts4_word)(a0 + -4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x8317AED8: fn  */
ts4_word ts4_fn_8317AED8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8317AEE0: fn  */
void ts4_fn_8317AEE0(void)
{
    return;
}

/* Loader_DLL.xex 0x8317AF58: fn  */
void ts4_fn_8317AF58(void)
{
    return;
}

/* Loader_DLL.xex 0x8317AF60: get u8@0x0 */
ts4_word ts4_get_u8_off0_8317AF60(ts4_word a0)
{
    return (((*(unsigned char *)((char *)(ts4_word)(a0) + 0))) >> 2);
}

/* Loader_DLL.xex 0x8317AF98: get u8@0x3 */
ts4_word ts4_get_u8_off3_8317AF98(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 3));
}

/* Loader_DLL.xex 0x8317B208: fn  */
void ts4_fn_8317B208(void)
{
    return;
}

/* Loader_DLL.xex 0x8317B210: fn  */
void ts4_fn_8317B210(void)
{
    return;
}

/* Loader_DLL.xex 0x8317B270: fn  */
void ts4_fn_8317B270(void)
{
    return;
}

/* Loader_DLL.xex 0x8317B300: get u32@0x20 */
ts4_word ts4_get_u32_off20_8317B300(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Loader_DLL.xex 0x8317B308: if_get u32@0x1c, u32@0x0 */
ts4_word ts4_if_get_u32_off1c_8317B308(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x8317B328: get u32@0x18 */
ts4_word ts4_get_u32_off18_8317B328(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Loader_DLL.xex 0x8317B330: get u32@0x18 */
ts4_word ts4_get_u32_off18_8317B330(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Loader_DLL.xex 0x8317B370: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_8317B370(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4));
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x8317B398: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_8317B398(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4));
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x8317B3C0: fn  */
ts4_word ts4_fn_8317B3C0(ts4_word a0)
{
    return (a0 & 0xff);
}

/* Loader_DLL.xex 0x8317B3C8: fn  */
ts4_word ts4_fn_8317B3C8(ts4_word a0)
{
    return (a0 & 0xff);
}

/* Loader_DLL.xex 0x8317B3D0: if_fn  */
ts4_word ts4_if_fn_8317B3D0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 > (ts4_word)a1) {
        return a0;
    }
    return a1;
}

/* Loader_DLL.xex 0x8317B3E0: if_fn  */
ts4_word ts4_if_fn_8317B3E0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 < (ts4_word)a1) {
        return a0;
    }
    return a1;
}

/* Loader_DLL.xex 0x8317B3F0: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_8317B3F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x8317B4A8: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_8317B4A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    return;
}

/* Loader_DLL.xex 0x8317B4B8: get u32@0x0 */
ts4_word ts4_get_u32_off0_8317B4B8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x8317B4C0: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_8317B4C0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return (t1 + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x8317B4D0: get u32@0x4 */
ts4_word ts4_get_u32_off4_8317B4D0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x8317B4D8: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_8317B4D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    return;
}

/* Loader_DLL.xex 0x8317B510: get  */
float ts4_get_8317B510(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 200));
}

/* Loader_DLL.xex 0x8317B518: get u32@0xd4 */
ts4_word ts4_get_u32_offd4_8317B518(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 212));
}

/* Loader_DLL.xex 0x8317B520: get u32@0x40 */
ts4_word ts4_get_u32_off40_8317B520(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 64)) << 1);
}

/* Loader_DLL.xex 0x8317B530: if_get u32@0x0 */
ts4_word ts4_if_get_u32_off0_8317B530(ts4_word a0, ts4_word a1)
{
    (void)a0;
    if ((ts4_word)a1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x8317B548: get u32@0x6c */
ts4_word ts4_get_u32_off6c_8317B548(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 108));
}

/* Loader_DLL.xex 0x8317B550: get u32@0xcc */
ts4_word ts4_get_u32_offcc_8317B550(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 204));
}

/* Loader_DLL.xex 0x8317B5D0: if_get u32@0x18, u32@0x0 */
ts4_word ts4_if_get_u32_off18_8317B5D0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x8317B5F0: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_8317B5F0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4));
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x8317B618: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_8317B618(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4));
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x8317B640: if_tail fn_8317B410, fn_8317B410 */
ts4_word ts4_if_tail_fn_8317B410_8317B640(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_8317B410((ts4_word)a2);
    }
    return fn_8317B410((ts4_word)a2);
}

/* Loader_DLL.xex 0x8317B658: if_tail fn_8317B410, fn_8317B410 */
ts4_word ts4_if_tail_fn_8317B410_8317B658(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_8317B410((ts4_word)a2);
    }
    return fn_8317B410((ts4_word)a2);
}

/* Loader_DLL.xex 0x8317B670: get u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_8317B670(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8317B680: get u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_8317B680(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8317B690: fn  */
void ts4_fn_8317B690(void)
{
    return;
}

/* Loader_DLL.xex 0x8317B698: fn  */
void ts4_fn_8317B698(void)
{
    return;
}

/* Loader_DLL.xex 0x8317BAB8: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_8317BAB8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a1, (ts4_word)(546766848), (ts4_word)8);
}

/* Loader_DLL.xex 0x8317BCF0: if_tail fn_8317B410, fn_8317B410 */
ts4_word ts4_if_tail_fn_8317B410_8317BCF0(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_8317B410((ts4_word)a2);
    }
    return fn_8317B410((ts4_word)a2);
}

/* Loader_DLL.xex 0x8317BD08: if_tail fn_8317B410, fn_8317B410 */
ts4_word ts4_if_tail_fn_8317B410_8317BD08(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_8317B410((ts4_word)a2);
    }
    return fn_8317B410((ts4_word)a2);
}

/* Loader_DLL.xex 0x8317BD20: if_tail fn_8317B410, fn_8317B410 */
ts4_word ts4_if_tail_fn_8317B410_8317BD20(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_8317B410((ts4_word)a2);
    }
    return fn_8317B410((ts4_word)a2);
}

/* Loader_DLL.xex 0x8317BF20: if_get u32@0x20c, u32@0x0 */
ts4_word ts4_if_get_u32_off20c_8317BF20(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 524);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x8317C920: if_tailcall fn_8317B410 */
ts4_word ts4_if_tailcall_fn_8317B410_8317C920(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return fn_8317B410((ts4_word)a1);
}

/* Loader_DLL.xex 0x8317D810: fn  */
ts4_word ts4_fn_8317D810(void)
{
    return 1;
}

/* Loader_DLL.xex 0x8317D898: tailcall fn_8317D908 */
ts4_word ts4_tailcall_fn_8317D908_8317D898(ts4_word a0, ts4_word a1)
{
    return fn_8317D908((ts4_word)(a0 + -4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x8317DCC0: tailcall fn_8317DBA0 */
ts4_word ts4_tailcall_fn_8317DBA0_8317DCC0(ts4_word a0)
{
    return fn_8317DBA0((ts4_word)(a0 + 16040));
}

/* Loader_DLL.xex 0x8317E6F0: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_8317E6F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x8317F4F8: tailcall fn_8317EC40 */
ts4_word ts4_tailcall_fn_8317EC40_8317F4F8(ts4_word a0)
{
    return fn_8317EC40((ts4_word)a0);
}

/* Loader_DLL.xex 0x8317F500: tailcall fn_8317E240 */
ts4_word ts4_tailcall_fn_8317E240_8317F500(ts4_word a0)
{
    return fn_8317E240((ts4_word)a0);
}

/* Loader_DLL.xex 0x8317F598: get u32@0x4 */
ts4_word ts4_get_u32_off4_8317F598(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x8317F5A0: get u32@0x8 */
ts4_word ts4_get_u32_off8_8317F5A0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x8317F5A8: get u32@0xc */
ts4_word ts4_get_u32_offc_8317F5A8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x8317F670: if_get u32@0x34, u32@0x78, u32@0x8 */
ts4_word ts4_if_get_u32_off34_8317F670(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 8));
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 120));
}

/* Loader_DLL.xex 0x8317F6E8: fn  */
void ts4_fn_8317F6E8(void)
{
    return;
}

/* Loader_DLL.xex 0x8317FDD8: get u32@0xb8 */
ts4_word ts4_get_u32_offb8_8317FDD8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 184));
}

/* Loader_DLL.xex 0x8317FDE0: set u32@0x4 */
void ts4_set_u32_off4_8317FDE0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8317FDE8: get u32@0x3c, fn_8317E2A8 */
ts4_word ts4_get_u32_off3c_8317FDE8(ts4_word a0)
{
    return fn_8317E2A8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)));
}

/* Loader_DLL.xex 0x8317FDF0: tailcall fn_83189480 */
ts4_word ts4_tailcall_fn_83189480_8317FDF0(ts4_word a0, ts4_word a1)
{
    return fn_83189480((ts4_word)(a0 + 4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x8317FDF8: tailcall fn_8318B860 */
ts4_word ts4_tailcall_fn_8318B860_8317FDF8(ts4_word a0)
{
    return fn_8318B860((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE00: tailcall fn_8318ABC8 */
ts4_word ts4_tailcall_fn_8318ABC8_8317FE00(ts4_word a0)
{
    return fn_8318ABC8((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE08: tailcall fn_8318A240 */
ts4_word ts4_tailcall_fn_8318A240_8317FE08(ts4_word a0)
{
    return fn_8318A240((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE10: tailcall fn_8318A2A8 */
ts4_word ts4_tailcall_fn_8318A2A8_8317FE10(ts4_word a0)
{
    return fn_8318A2A8((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE18: tailcall fn_8318A310 */
ts4_word ts4_tailcall_fn_8318A310_8317FE18(ts4_word a0)
{
    return fn_8318A310((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE20: tailcall fn_8318A370 */
ts4_word ts4_tailcall_fn_8318A370_8317FE20(ts4_word a0)
{
    return fn_8318A370((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE28: tailcall fn_8318A3F0 */
ts4_word ts4_tailcall_fn_8318A3F0_8317FE28(ts4_word a0)
{
    return fn_8318A3F0((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE30: tailcall fn_83189588 */
ts4_word ts4_tailcall_fn_83189588_8317FE30(ts4_word a0)
{
    return fn_83189588((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE38: tailcall fn_83189608 */
ts4_word ts4_tailcall_fn_83189608_8317FE38(ts4_word a0, ts4_word a1)
{
    return fn_83189608((ts4_word)(a0 + 4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x8317FE40: tailcall fn_83189690 */
ts4_word ts4_tailcall_fn_83189690_8317FE40(ts4_word a0)
{
    return fn_83189690((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE48: tailcall fn_83189708 */
ts4_word ts4_tailcall_fn_83189708_8317FE48(ts4_word a0)
{
    return fn_83189708((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE50: tailcall fn_8318AE90 */
ts4_word ts4_tailcall_fn_8318AE90_8317FE50(ts4_word a0)
{
    return fn_8318AE90((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE58: tailcall fn_83189770 */
ts4_word ts4_tailcall_fn_83189770_8317FE58(ts4_word a0, ts4_word a1)
{
    return fn_83189770((ts4_word)(a0 + 4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x8317FE60: tailcall fn_831897E0 */
ts4_word ts4_tailcall_fn_831897E0_8317FE60(ts4_word a0)
{
    return fn_831897E0((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE68: tailcall fn_83189870 */
ts4_word ts4_tailcall_fn_83189870_8317FE68(ts4_word a0)
{
    return fn_83189870((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE70: tailcall fn_8318A518 */
ts4_word ts4_tailcall_fn_8318A518_8317FE70(ts4_word a0)
{
    return fn_8318A518((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE78: tailcall fn_831898F0 */
ts4_word ts4_tailcall_fn_831898F0_8317FE78(ts4_word a0)
{
    return fn_831898F0((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE80: tailcall fn_8318A108 */
ts4_word ts4_tailcall_fn_8318A108_8317FE80(ts4_word a0)
{
    return fn_8318A108((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8317FE88: fn  */
ts4_word ts4_fn_8317FE88(void)
{
    return 4;
}

/* Loader_DLL.xex 0x8317FE90: get u32@0x30, u32@0xb8 */
ts4_word ts4_get_u32_off30_8317FE90(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 184));
}

/* Loader_DLL.xex 0x8317FED8: tailcall fn_8317FF90 */
ts4_word ts4_tailcall_fn_8317FF90_8317FED8(ts4_word a0, ts4_word a1)
{
    return fn_8317FF90((ts4_word)(a0 + -4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x83180078: get u32@0x80 */
ts4_word ts4_get_u32_off80_83180078(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 128)) != 0);
}

/* Loader_DLL.xex 0x83180088: fn  */
void ts4_fn_83180088(void)
{
    return;
}

/* Loader_DLL.xex 0x83180238: tailcall fn_83189480 */
ts4_word ts4_tailcall_fn_83189480_83180238(ts4_word a0, ts4_word a1)
{
    return fn_83189480((ts4_word)(a0 + 4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x83180240: tailcall fn_8318B860 */
ts4_word ts4_tailcall_fn_8318B860_83180240(ts4_word a0)
{
    return fn_8318B860((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83180248: tailcall fn_8318ABC8 */
ts4_word ts4_tailcall_fn_8318ABC8_83180248(ts4_word a0)
{
    return fn_8318ABC8((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83180250: tailcall fn_8318A240 */
ts4_word ts4_tailcall_fn_8318A240_83180250(ts4_word a0)
{
    return fn_8318A240((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83180258: tailcall fn_8318A2A8 */
ts4_word ts4_tailcall_fn_8318A2A8_83180258(ts4_word a0)
{
    return fn_8318A2A8((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83180260: tailcall fn_8318A310 */
ts4_word ts4_tailcall_fn_8318A310_83180260(ts4_word a0)
{
    return fn_8318A310((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83180268: tailcall fn_8318A370 */
ts4_word ts4_tailcall_fn_8318A370_83180268(ts4_word a0)
{
    return fn_8318A370((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83180270: tailcall fn_8318A3F0 */
ts4_word ts4_tailcall_fn_8318A3F0_83180270(ts4_word a0)
{
    return fn_8318A3F0((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83180278: tailcall fn_83189588 */
ts4_word ts4_tailcall_fn_83189588_83180278(ts4_word a0)
{
    return fn_83189588((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83180280: tailcall fn_83189608 */
ts4_word ts4_tailcall_fn_83189608_83180280(ts4_word a0, ts4_word a1)
{
    return fn_83189608((ts4_word)(a0 + 4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x83180288: tailcall fn_83189690 */
ts4_word ts4_tailcall_fn_83189690_83180288(ts4_word a0)
{
    return fn_83189690((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83180290: tailcall fn_83189708 */
ts4_word ts4_tailcall_fn_83189708_83180290(ts4_word a0)
{
    return fn_83189708((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x83180298: tailcall fn_8318AE90 */
ts4_word ts4_tailcall_fn_8318AE90_83180298(ts4_word a0)
{
    return fn_8318AE90((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x831802A0: tailcall fn_83189770 */
ts4_word ts4_tailcall_fn_83189770_831802A0(ts4_word a0, ts4_word a1)
{
    return fn_83189770((ts4_word)(a0 + 4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x831802A8: tailcall fn_831897E0 */
ts4_word ts4_tailcall_fn_831897E0_831802A8(ts4_word a0)
{
    return fn_831897E0((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x831802B0: tailcall fn_83189870 */
ts4_word ts4_tailcall_fn_83189870_831802B0(ts4_word a0)
{
    return fn_83189870((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x831802B8: tailcall fn_8318A518 */
ts4_word ts4_tailcall_fn_8318A518_831802B8(ts4_word a0)
{
    return fn_8318A518((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x831802C0: tailcall fn_831898F0 */
ts4_word ts4_tailcall_fn_831898F0_831802C0(ts4_word a0)
{
    return fn_831898F0((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x831802C8: tailcall fn_8318A108 */
ts4_word ts4_tailcall_fn_8318A108_831802C8(ts4_word a0)
{
    return fn_8318A108((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x831802D0: fn  */
ts4_word ts4_fn_831802D0(void)
{
    return 3;
}

/* Loader_DLL.xex 0x831802D8: get u32@0x8c */
ts4_word ts4_get_u32_off8c_831802D8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 140));
}

/* Loader_DLL.xex 0x831802E0: get u32@0x88 */
ts4_word ts4_get_u32_off88_831802E0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 136));
}

/* Loader_DLL.xex 0x83180300: tailcall fn_831803D8 */
ts4_word ts4_tailcall_fn_831803D8_83180300(ts4_word a0, ts4_word a1)
{
    return fn_831803D8((ts4_word)(a0 + -4), (ts4_word)a1);
}

/* Loader_DLL.xex 0x83180428: fn  */
void ts4_fn_83180428(void)
{
    return;
}

/* Loader_DLL.xex 0x83180430: fn  */
void ts4_fn_83180430(void)
{
    return;
}

/* Loader_DLL.xex 0x83180630: call_seq u32@0x48, fn_8319E048 */
ts4_word ts4_call_seq_u32_off48_83180630(ts4_word a0, ts4_word a1)
{
    fn_8319E048((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 72)), (ts4_word)a1);
    return 0;
}

/* Loader_DLL.xex 0x83180658: get u32@0x44, fn_8319D618 */
ts4_word ts4_get_u32_off44_83180658(ts4_word a0, ts4_word a1)
{
    return fn_8319D618((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x831806C8: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_831806C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83180740: get u32@0xd4 */
ts4_word ts4_get_u32_offd4_83180740(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 212));
}

/* Loader_DLL.xex 0x83180748: get u32@0xcc */
ts4_word ts4_get_u32_offcc_83180748(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 204));
}

/* Loader_DLL.xex 0x83180760: get u32@0x18 */
ts4_word ts4_get_u32_off18_83180760(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Loader_DLL.xex 0x83180768: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_83180768(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4));
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x83180790: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_83180790(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4));
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x831807B8: get u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_831807B8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831807C8: get u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_831807C8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831807D8: fn  */
void ts4_fn_831807D8(void)
{
    return;
}

/* Loader_DLL.xex 0x831807E0: fn  */
void ts4_fn_831807E0(void)
{
    return;
}

/* Loader_DLL.xex 0x831807E8: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_831807E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x831808A0: fn  */
void ts4_fn_831808A0(void)
{
    return;
}

/* Loader_DLL.xex 0x831808D8: fn  */
ts4_word ts4_fn_831808D8(ts4_word a0)
{
    return (a0 + 32);
}

/* Loader_DLL.xex 0x831808E0: get u32@0x10 */
ts4_word ts4_get_u32_off10_831808E0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Loader_DLL.xex 0x83180940: get u32@0x4 */
ts4_word ts4_get_u32_off4_83180940(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x83180948: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_83180948(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83180960: tailcall fn_831808E8 */
ts4_word ts4_tailcall_fn_831808E8_83180960(ts4_word a0)
{
    return fn_831808E8((ts4_word)a0);
}

/* Loader_DLL.xex 0x83180968: get u32@0x80 */
ts4_word ts4_get_u32_off80_83180968(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 128)) != 0);
}

/* Loader_DLL.xex 0x83180990: get u32@0x10 */
ts4_word ts4_get_u32_off10_83180990(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Loader_DLL.xex 0x83180998: fn  */
ts4_word ts4_fn_83180998(ts4_word a0)
{
    return (a0 + 64);
}

/* Loader_DLL.xex 0x831809A0: fn  */
ts4_word ts4_fn_831809A0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (a1 + 4);
}

/* Loader_DLL.xex 0x831809A8: get u32@0x1c */
ts4_word ts4_get_u32_off1c_831809A8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 28));
}

/* Loader_DLL.xex 0x831809B0: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_831809B0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a1, (ts4_word)((546766848) | 6), (ts4_word)8);
}

/* Loader_DLL.xex 0x83180A50: get u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_83180A50(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83180A98: fn  */
void ts4_fn_83180A98(void)
{
    return;
}

/* Loader_DLL.xex 0x83180AB0: fn  */
ts4_word ts4_fn_83180AB0(void)
{
    return -1;
}

/* Loader_DLL.xex 0x83180AB8: fn  */
void ts4_fn_83180AB8(void)
{
    return;
}

/* Loader_DLL.xex 0x83180D08: get u32@0x14, u32@0x10, fn_83180660 */
ts4_word ts4_get_u32_off14_83180D08(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    return fn_83180660((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16)), (ts4_word)t1);
}

/* Loader_DLL.xex 0x83181140: if_tail fn_83180808, fn_83180808 */
ts4_word ts4_if_tail_fn_83180808_83181140(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_83180808((ts4_word)a2);
    }
    return fn_83180808((ts4_word)a2);
}

/* Loader_DLL.xex 0x83181438: if_tail fn_83180808, fn_83180808 */
ts4_word ts4_if_tail_fn_83180808_83181438(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_83180808((ts4_word)a2);
    }
    return fn_83180808((ts4_word)a2);
}

/* Loader_DLL.xex 0x83181488: if_tail fn_83180808, fn_83180808 */
ts4_word ts4_if_tail_fn_83180808_83181488(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_83180808((ts4_word)a2);
    }
    return fn_83180808((ts4_word)a2);
}

/* Loader_DLL.xex 0x831814D8: if_tail fn_83180808, fn_83180808 */
ts4_word ts4_if_tail_fn_83180808_831814D8(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_83180808((ts4_word)a2);
    }
    return fn_83180808((ts4_word)a2);
}

/* Loader_DLL.xex 0x831814F0: if_tailcall fn_83180808 */
ts4_word ts4_if_tailcall_fn_83180808_831814F0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return fn_83180808((ts4_word)a1);
}

/* Loader_DLL.xex 0x83181B60: get u32@0x14, u32@0x10, fn_83180660 */
ts4_word ts4_get_u32_off14_83181B60(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    return fn_83180660((ts4_word)(a0 + -8), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16)), (ts4_word)t1);
}

/* Loader_DLL.xex 0x83182408: tailcall fn_83182BA0 */
ts4_word ts4_tailcall_fn_83182BA0_83182408(ts4_word a0, ts4_word a1)
{
    return fn_83182BA0((ts4_word)(a0 + -16), (ts4_word)a1);
}

/* Loader_DLL.xex 0x83182438: tailcall fn_83182410 */
ts4_word ts4_tailcall_fn_83182410_83182438(ts4_word a0)
{
    return fn_83182410((ts4_word)(a0 + -16));
}

/* Loader_DLL.xex 0x83182440: tailcall fn_83180AC0 */
ts4_word ts4_tailcall_fn_83180AC0_83182440(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_83180AC0((ts4_word)(a0 + -16), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83182448: tailcall fn_83170F60 */
ts4_word ts4_tailcall_fn_83170F60_83182448(ts4_word a0)
{
    return fn_83170F60((ts4_word)(a0 + 16));
}

/* Loader_DLL.xex 0x83182510: call_seq u32@0x0, u32@0x4, fn_83181010 */
ts4_word ts4_call_seq_u32_off0_83182510(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    fn_83181010((ts4_word)(a0 + 8));
    return a0;
}

/* Loader_DLL.xex 0x831826C0: tailcall fn_831821A0 */
ts4_word ts4_tailcall_fn_831821A0_831826C0(ts4_word a0)
{
    return fn_831821A0((ts4_word)a0, (ts4_word)4);
}

/* Loader_DLL.xex 0x83182CC8: get  */
void ts4_get_83182CC8(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 68));
    return;
}

/* Loader_DLL.xex 0x83182CD8: get u32@0x4 */
ts4_word ts4_get_u32_off4_83182CD8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x83182CE0: get u32@0x18 */
ts4_word ts4_get_u32_off18_83182CE0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Loader_DLL.xex 0x83183050: fn  */
ts4_word ts4_fn_83183050(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83183058: fn  */
ts4_word ts4_fn_83183058(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83183060: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_83183060(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83183118: call_seq fn_831A5178 */
ts4_word ts4_call_seq_fn_831A5178_83183118(ts4_word a0, ts4_word a1)
{
    fn_831A5178((ts4_word)a0, (ts4_word)a1);
    return a0;
}

/* Loader_DLL.xex 0x83183148: tailcall fn_831A3268 */
ts4_word ts4_tailcall_fn_831A3268_83183148(ts4_word a0)
{
    return fn_831A3268((ts4_word)a0);
}

/* Loader_DLL.xex 0x83183150: fn  */
void ts4_fn_83183150(void)
{
    return;
}

/* Loader_DLL.xex 0x83183158: fn  */
void ts4_fn_83183158(void)
{
    return;
}

/* Loader_DLL.xex 0x83183270: if_tail fn_83183080, fn_83183080 */
ts4_word ts4_if_tail_fn_83183080_83183270(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_83183080((ts4_word)a2);
    }
    return fn_83183080((ts4_word)a2);
}

/* Loader_DLL.xex 0x831833F8: tailcall fn_83183360 */
ts4_word ts4_tailcall_fn_83183360_831833F8(ts4_word a0)
{
    return fn_83183360((ts4_word)(a0 + -32));
}

/* Loader_DLL.xex 0x83183400: tailcall fn_83183360 */
ts4_word ts4_tailcall_fn_83183360_83183400(ts4_word a0)
{
    return fn_83183360((ts4_word)(a0 + -36));
}

/* Loader_DLL.xex 0x83183408: tailcall fn_83183160 */
ts4_word ts4_tailcall_fn_83183160_83183408(ts4_word a0, ts4_word a1)
{
    return fn_83183160((ts4_word)(a0 + -32), (ts4_word)a1);
}

/* Loader_DLL.xex 0x83183410: tailcall fn_83183160 */
ts4_word ts4_tailcall_fn_83183160_83183410(ts4_word a0, ts4_word a1)
{
    return fn_83183160((ts4_word)(a0 + -36), (ts4_word)a1);
}

/* Loader_DLL.xex 0x831834A0: tailcall fn_83183418 */
ts4_word ts4_tailcall_fn_83183418_831834A0(ts4_word a0)
{
    return fn_83183418((ts4_word)a0);
}

/* Loader_DLL.xex 0x831839A8: fn  */
ts4_word ts4_fn_831839A8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831839B0: fn  */
ts4_word ts4_fn_831839B0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83183A18: fn  */
ts4_word ts4_fn_83183A18(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83183A20: fn  */
void ts4_fn_83183A20(void)
{
    return;
}

/* Loader_DLL.xex 0x83183A28: fn  */
ts4_word ts4_fn_83183A28(ts4_word a0, ts4_word a1)
{
    return a1;

    (void)a0;}

/* Loader_DLL.xex 0x83183A30: fn  */
ts4_word ts4_fn_83183A30(ts4_word a0, ts4_word a1)
{
    return a1;

    (void)a0;}

/* Loader_DLL.xex 0x83183E40: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_83183E40(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83184200: tailcall fn_83183EF8 */
ts4_word ts4_tailcall_fn_83183EF8_83184200(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_83183EF8((ts4_word)(a0 + -32), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83184208: tailcall fn_831841D8 */
ts4_word ts4_tailcall_fn_831841D8_83184208(ts4_word a0)
{
    return fn_831841D8((ts4_word)(a0 + -32));
}

/* Loader_DLL.xex 0x83184210: tailcall fn_83183418 */
ts4_word ts4_tailcall_fn_83183418_83184210(ts4_word a0)
{
    return fn_83183418((ts4_word)a0);
}

/* Loader_DLL.xex 0x831842A8: call_seq fn_83184218, fn_831A3308 */
ts4_word ts4_call_seq_fn_83184218_831842A8(ts4_word a0)
{
    ts4_word t2;

    fn_83184218((ts4_word)a0);
    t2 = fn_831A3308((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x83184E78: fn  */
ts4_word ts4_fn_83184E78(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83184E80: fn  */
ts4_word ts4_fn_83184E80(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83184E88: get  */
void ts4_get_83184E88(ts4_word a0, ts4_word a1)
{
    float t1;

    t1 = *(float *)((char *)(ts4_word)(a0) + 0);
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a1) + 0) = t1;
    return;
}

/* Loader_DLL.xex 0x83184EA0: get u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
void ts4_get_u32_off0_83184EA0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
    return;
}

/* Loader_DLL.xex 0x83184EB8: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_83184EB8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83185030: if_tail fn_83184ED8, fn_83184ED8 */
ts4_word ts4_if_tail_fn_83184ED8_83185030(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_83184ED8((ts4_word)a2);
    }
    return fn_83184ED8((ts4_word)a2);
}

/* Loader_DLL.xex 0x83185BE8: tailcall fn_83184570 */
ts4_word ts4_tailcall_fn_83184570_83185BE8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_83184570((ts4_word)(a0 + -32), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83185C18: tailcall fn_83185BF0 */
ts4_word ts4_tailcall_fn_83185BF0_83185C18(ts4_word a0)
{
    return fn_83185BF0((ts4_word)(a0 + -32));
}

/* Loader_DLL.xex 0x83185C20: tailcall fn_83183418 */
ts4_word ts4_tailcall_fn_83183418_83185C20(ts4_word a0)
{
    return fn_83183418((ts4_word)a0);
}

/* Loader_DLL.xex 0x83185D68: call_seq fn_83185C28, fn_831A3308 */
ts4_word ts4_call_seq_fn_83185C28_83185D68(ts4_word a0)
{
    ts4_word t2;

    fn_83185C28((ts4_word)a0);
    t2 = fn_831A3308((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x831864F0: set u32@0x34 */
void ts4_set_u32_off34_831864F0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83186500: fn  */
ts4_word ts4_fn_83186500(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83186508: fn  */
ts4_word ts4_fn_83186508(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83186570: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_83186570(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83186A40: tailcall fn_83186A18 */
ts4_word ts4_tailcall_fn_83186A18_83186A40(ts4_word a0)
{
    return fn_83186A18((ts4_word)(a0 + -32));
}

/* Loader_DLL.xex 0x83186A48: tailcall fn_83186640 */
ts4_word ts4_tailcall_fn_83186640_83186A48(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_83186640((ts4_word)(a0 + -32), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83186A50: tailcall fn_83183418 */
ts4_word ts4_tailcall_fn_83183418_83186A50(ts4_word a0)
{
    return fn_83183418((ts4_word)a0);
}

/* Loader_DLL.xex 0x83187040: tailcall fn_83186C48 */
ts4_word ts4_tailcall_fn_83186C48_83187040(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_83186C48((ts4_word)(a0 + -32), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83187048: tailcall fn_83187018 */
ts4_word ts4_tailcall_fn_83187018_83187048(ts4_word a0)
{
    return fn_83187018((ts4_word)(a0 + -32));
}

/* Loader_DLL.xex 0x83187050: tailcall fn_83183418 */
ts4_word ts4_tailcall_fn_83183418_83187050(ts4_word a0)
{
    return fn_83183418((ts4_word)a0);
}

/* Loader_DLL.xex 0x831870E8: call_seq fn_83187058, fn_831A3308 */
ts4_word ts4_call_seq_fn_83187058_831870E8(ts4_word a0)
{
    ts4_word t2;

    fn_83187058();
    t2 = fn_831A3308((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x83187590: fn  */
ts4_word ts4_fn_83187590(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83187760: get u32@0xd8, u32@0xd4, u32@0x24, fn_831B9FB8 */
ts4_word ts4_get_u32_offd8_83187760(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 216);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 212);
    return fn_831B9FB8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)), (ts4_word)t2, (ts4_word)t1);
}

/* Loader_DLL.xex 0x83187B68: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_83187B68(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83187E00: if_tail fn_83187B88, fn_83187B88 */
ts4_word ts4_if_tail_fn_83187B88_83187E00(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_83187B88((ts4_word)a2);
    }
    return fn_83187B88((ts4_word)a2);
}

/* Loader_DLL.xex 0x83187EE0: tailcall fn_83187EB8 */
ts4_word ts4_tailcall_fn_83187EB8_83187EE0(ts4_word a0)
{
    return fn_83187EB8((ts4_word)(a0 + -32));
}

/* Loader_DLL.xex 0x83187EE8: tailcall fn_83187D68 */
ts4_word ts4_tailcall_fn_83187D68_83187EE8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_83187D68((ts4_word)(a0 + -32), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83187EF0: tailcall fn_83183418 */
ts4_word ts4_tailcall_fn_83183418_83187EF0(ts4_word a0)
{
    return fn_83183418((ts4_word)a0);
}

/* Loader_DLL.xex 0x83187F80: call_seq fn_83187EF8, fn_831A3308 */
ts4_word ts4_call_seq_fn_83187EF8_83187F80(ts4_word a0)
{
    ts4_word t2;

    fn_83187EF8((ts4_word)a0);
    t2 = fn_831A3308((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x83188330: get u32@0x18 */
ts4_word ts4_get_u32_off18_83188330(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Loader_DLL.xex 0x83188338: if_get u32@0x0 */
ts4_word ts4_if_get_u32_off0_83188338(ts4_word a0, ts4_word a1)
{
    (void)a0;
    if ((ts4_word)a1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x83188350: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_83188350(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4));
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x83188378: loop_get u32@0x20, u32@0x18, u32@0x18, u32@0x4 */
ts4_word ts4_loop_get_u32_off20_83188378(ts4_word a0, ts4_word a1)
{
    ts4_word c4;
    ts4_word lv5;
    ts4_word p7;
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)a1 >= (ts4_word)t1) {
        return 0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)a1 == 0) {
        return t3;
    }
    c4 = (ts4_word)a1;
    lv5 = (ts4_word)t3;
    do {
        p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv5) + 4));
        lv5 = p7;
    } while (--c4 != 0);
    return lv5;
}

/* Loader_DLL.xex 0x831883A8: get u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_831883A8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831883B8: fn  */
void ts4_fn_831883B8(void)
{
    return;
}

/* Loader_DLL.xex 0x831883C0: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_831883C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83188478: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_83188478(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    return;
}

/* Loader_DLL.xex 0x831884B0: get u32@0x10, u32@0x30 */
ts4_word ts4_get_u32_off10_831884B0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 48));
}
