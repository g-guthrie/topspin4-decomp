/* Loader_DLL.xex 0x8311B0B8-0x83150E80, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char fn_83141BA8[];
extern char fn_831421C8[];
extern char lbl_830009EC[];
extern char lbl_830009F8[];
extern char lbl_83000C6C[];
extern char lbl_83002860[];
extern char lbl_83002898[];
extern char lbl_83003F40[];
extern char lbl_83527DF8[];
extern char lbl_83527DFC[];
extern char lbl_83527E00[];
extern char lbl_83527E04[];
extern char lbl_83531104[];
extern char lbl_835312B4[];
extern char lbl_835312B8[];
extern char lbl_835312D0[];
ts4_word RtlInitializeCriticalSection();
ts4_word fn_830AD8F8();
ts4_word fn_830FF018();
ts4_word fn_830FF0B0();
ts4_word fn_830FFBE8();
ts4_word fn_8310D380();
ts4_word fn_8311AFF0();
ts4_word fn_8311B5B8();
ts4_word fn_8311BA20();
ts4_word fn_8311BB08();
ts4_word fn_8311CAE0();
ts4_word fn_8311CC18();
ts4_word fn_83120540();
ts4_word fn_83122BC8();
ts4_word fn_83125528();
ts4_word fn_831263D8();
ts4_word fn_831266E8();
ts4_word fn_8312E850();
ts4_word fn_83131660();
ts4_word fn_831334E0();
ts4_word fn_8313E8B0();
ts4_word fn_8313F080();
ts4_word fn_8313FCF0();
ts4_word fn_83140430();
ts4_word fn_83140CF0();
ts4_word fn_831416B8();
ts4_word fn_83142118();
ts4_word fn_83142AA8();
ts4_word fn_83143150();
ts4_word fn_83143330();
ts4_word fn_83143B40();
ts4_word fn_83143E08();
ts4_word fn_831441C0();
ts4_word fn_83144558();
ts4_word fn_831457D0();
ts4_word fn_831458C0();
ts4_word fn_83147FE8();
ts4_word fn_83148000();
ts4_word fn_83148168();
ts4_word fn_831481E8();
ts4_word fn_831482A8();
ts4_word fn_83148348();
ts4_word fn_831483F8();
ts4_word fn_831484F0();
ts4_word fn_83148560();
ts4_word fn_831487C0();
ts4_word fn_831488C0();
ts4_word fn_83148B70();
ts4_word fn_831495D8();
ts4_word fn_83149750();
ts4_word fn_83149FD8();
ts4_word fn_8314C7E8();
ts4_word fn_8315DED8();
ts4_word fn_8315EF40();
ts4_word fn_833E2CA0();
ts4_word fn_833E3A30();
ts4_word fn_833E4108();
ts4_word fn_8340D710();

/* Loader_DLL.xex 0x8311B0B8: get u32@0x34 */
ts4_word ts4_get_u32_off34_8311B0B8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 52));
}

/* Loader_DLL.xex 0x8311BCE8: tailcall fn_8311B5B8 */
ts4_word ts4_tailcall_fn_8311B5B8_8311BCE8(ts4_word a0)
{
    return fn_8311B5B8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8311BCF0: tailcall fn_8311BA20 */
ts4_word ts4_tailcall_fn_8311BA20_8311BCF0(ts4_word a0)
{
    return fn_8311BA20((ts4_word)a0);
}

/* Loader_DLL.xex 0x8311CBE0: call_seq fn_8311CAE0, u32@0x20, u32@0x1c, fn_8311BB08 */
ts4_word ts4_call_seq_fn_8311CAE0_8311CBE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    fn_8311CAE0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a2;
    t2 = fn_8311BB08((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x8311CCA0: tailcall fn_8311CC18 */
ts4_word ts4_tailcall_fn_8311CC18_8311CCA0(ts4_word a0)
{
    return fn_8311CC18((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120518: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83120518(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(613285888));
}

/* Loader_DLL.xex 0x831241C0: tailcall fn_8311AFF0 */
ts4_word ts4_tailcall_fn_8311AFF0_831241C0(ts4_word a0)
{
    return fn_8311AFF0((ts4_word)a0);
}

/* Loader_DLL.xex 0x8312D5B8: if_get u32@0x0, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off0_8312D5B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)((a1 << 2) + t1) == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(((a1 << 2) + t1)) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Loader_DLL.xex 0x8312D5D8: if_get u32@0x0, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off0_8312D5D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)((a1 << 2) + t1) == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(((a1 << 2) + t1)) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Loader_DLL.xex 0x8312D5F8: if_get u32@0x0, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off0_8312D5F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)((a1 << 2) + t1) == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(((a1 << 2) + t1)) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Loader_DLL.xex 0x8312D668: tailcall fn_83125528 */
ts4_word ts4_tailcall_fn_83125528_8312D668(ts4_word a0)
{
    return fn_83125528((ts4_word)a0);
}

/* Loader_DLL.xex 0x8312D670: set u32@0x18 */
void ts4_set_u32_off18_8312D670(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8312E110: tailcall fn_83122BC8 */
ts4_word ts4_tailcall_fn_83122BC8_8312E110(ts4_word a0)
{
    return fn_83122BC8((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x8312E118: call_seq fn_831263D8 */
ts4_word ts4_call_seq_fn_831263D8_8312E118(ts4_word a0, float f1, float f2)
{
    ts4_word loc50[2];
    ts4_word t1;

    *(float *)((char *)loc50 + 0) = f1;
    *(float *)((char *)loc50 + 4) = f2;
    t1 = fn_831263D8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Loader_DLL.xex 0x8312E148: tailcall fn_831266E8 */
ts4_word ts4_tailcall_fn_831266E8_8312E148(ts4_word a0)
{
    return fn_831266E8((ts4_word)a0);
}

/* Loader_DLL.xex 0x831317D0: set u32@0x10, u32@0x18, u32@0x14, fn_83131660 */
ts4_word ts4_set_u32_off10_831317D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a2;
    return fn_83131660((ts4_word)a0, (ts4_word)t1);
}

/* Loader_DLL.xex 0x83134FA8: get u32@0x0, fn_8312E850 */
ts4_word ts4_get_u32_off0_83134FA8(ts4_word a0, ts4_word a1)
{
    return fn_8312E850((ts4_word)(a0 + 4), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x83134FC0: get u32@0x0, fn_8312E850 */
ts4_word ts4_get_u32_off0_83134FC0(ts4_word a0, ts4_word a1)
{
    return fn_8312E850((ts4_word)(a0 + 4), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x83136B80: call_seq u32@0x4, fn_83120540, fn_831334E0 */
ts4_word ts4_call_seq_u32_off4_83136B80(ts4_word a0)
{
    ts4_word t3;

    fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t3 = fn_831334E0((ts4_word)a0);
    return t3;
}

/* Loader_DLL.xex 0x8313CC38: get u32@0x0 */
ts4_word ts4_get_u32_off0_8313CC38(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x8313CC40: get u32@0x4 */
ts4_word ts4_get_u32_off4_8313CC40(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x8313CC48: get u32@0x8 */
ts4_word ts4_get_u32_off8_8313CC48(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x8313CC50: get u32@0xc */
ts4_word ts4_get_u32_offc_8313CC50(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x8313CC58: get u32@0x10 */
ts4_word ts4_get_u32_off10_8313CC58(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Loader_DLL.xex 0x8313CC60: get u32@0x14 */
ts4_word ts4_get_u32_off14_8313CC60(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Loader_DLL.xex 0x8313CC68: get u32@0x18 */
ts4_word ts4_get_u32_off18_8313CC68(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Loader_DLL.xex 0x8313CC70: get u32@0x1c */
ts4_word ts4_get_u32_off1c_8313CC70(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 28));
}

/* Loader_DLL.xex 0x8313CC78: get u32@0x20 */
ts4_word ts4_get_u32_off20_8313CC78(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Loader_DLL.xex 0x8313CC80: get u32@0x24 */
ts4_word ts4_get_u32_off24_8313CC80(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 36));
}

/* Loader_DLL.xex 0x8313CC88: get u32@0x0 */
ts4_word ts4_get_u32_off0_8313CC88(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x8313CC90: get u32@0x4 */
ts4_word ts4_get_u32_off4_8313CC90(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x8313CC98: get u32@0x8 */
ts4_word ts4_get_u32_off8_8313CC98(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x8313CCA0: get u16@0xc */
ts4_word ts4_get_u16_offc_8313CCA0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x8313CCA8: get u32@0xe */
ts4_word ts4_get_u32_offe_8313CCA8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 14));
}

/* Loader_DLL.xex 0x8313CCB0: get u16@0x12 */
ts4_word ts4_get_u16_off12_8313CCB0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 18));
}

/* Loader_DLL.xex 0x8313CCB8: get u32@0x0 */
ts4_word ts4_get_u32_off0_8313CCB8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x8313CCC0: get u32@0x4 */
ts4_word ts4_get_u32_off4_8313CCC0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x8313CCC8: get u32@0x8 */
ts4_word ts4_get_u32_off8_8313CCC8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x8313CCD0: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_8313CCD0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8313CED0: set u32@0x4, u32@0x0, u32@0x8 */
void ts4_set_u32_off4_8313CED0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8313CEE8: get u32@0x0, fn_83120540 */
ts4_word ts4_get_u32_off0_8313CEE8(ts4_word a0)
{
    return fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x8313CFE8: set u32@0x0 */
void ts4_set_u32_off0_8313CFE8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8313CFF8: get u32@0x0, fn_83120540 */
ts4_word ts4_get_u32_off0_8313CFF8(ts4_word a0)
{
    return fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x8313D050: get u32@0x0 */
ts4_word ts4_get_u32_off0_8313D050(ts4_word a0, ts4_word a1)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a1);
}

/* Loader_DLL.xex 0x8313D068: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_8313D068(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x8313D0B0: get u32@0x28, u32@0x28 */
void ts4_get_u32_off28_8313D0B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40)) + 1);
    return;
}

/* Loader_DLL.xex 0x8313D1C8: get u8@0x0 */
ts4_word ts4_get_u8_off0_8313D1C8(ts4_word a0)
{
    return (((*(unsigned char *)((char *)(ts4_word)(a0) + 0)) & 0x7) + 1);
}

/* Loader_DLL.xex 0x8313D3A0: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_8313D3A0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8313D3B8: get u32@0x0, fn_83120540 */
ts4_word ts4_get_u32_off0_8313D3B8(ts4_word a0)
{
    return fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x8313D420: get u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_8313D420(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return t1;
}

/* Loader_DLL.xex 0x8313D880: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_8313D880(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8313D898: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_8313D898(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x8313D8A0: tailcall fn_83144558 */
ts4_word ts4_tailcall_fn_83144558_8313D8A0(ts4_word a0)
{
    return fn_83144558((ts4_word)a0);
}

/* Loader_DLL.xex 0x8313E920: tailcall fn_8313E8B0 */
ts4_word ts4_tailcall_fn_8313E8B0_8313E920(ts4_word a0)
{
    return fn_8313E8B0((ts4_word)a0);
}

/* Loader_DLL.xex 0x8313E928: set u32@0x0, u32@0x4, u32@0x8, u8@0xc */
void ts4_set_u32_off0_8313E928(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
    return;
}

/* Loader_DLL.xex 0x8313E940: tailcall fn_8313E8B0 */
ts4_word ts4_tailcall_fn_8313E8B0_8313E940(ts4_word a0)
{
    return fn_8313E8B0((ts4_word)a0);
}

/* Loader_DLL.xex 0x8313F078: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_8313F078(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x8313F190: set u32@lbl_83531104 */
ts4_word ts4_set_u32_lbl_83531104_8313F190(ts4_word a0)
{
    *(ts4_word *)lbl_83531104 = (ts4_word)a0;
    return 0;
}

/* Loader_DLL.xex 0x8313F2E0: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_8313F2E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8313F2F8: get u32@0x8 */
ts4_word ts4_get_u32_off8_8313F2F8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x8313F320: fn  */
void ts4_fn_8313F320(void)
{
    return;
}

/* Loader_DLL.xex 0x8313F328: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_8313F328(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Loader_DLL.xex 0x8313F338: fn  */
ts4_word ts4_fn_8313F338(ts4_word a0, ts4_word a1)
{
    return a1;

    (void)a0;}

/* Loader_DLL.xex 0x8313F340: fn  */
ts4_word ts4_fn_8313F340(ts4_word a0, ts4_word a1)
{
    return a1;

    (void)a0;}

/* Loader_DLL.xex 0x8313F348: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x0 */
void ts4_set_u32_off0_8313F348(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)20;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8313F588: tailcall fn_8313F080 */
ts4_word ts4_tailcall_fn_8313F080_8313F588(ts4_word a0)
{
    return fn_8313F080((ts4_word)a0);
}

/* Loader_DLL.xex 0x8313FFC8: tailcall fn_8313FCF0 */
ts4_word ts4_tailcall_fn_8313FCF0_8313FFC8(ts4_word a0)
{
    return fn_8313FCF0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83140018: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_83140018(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83140030: tailcall fn_8313FCF0 */
ts4_word ts4_tailcall_fn_8313FCF0_83140030(ts4_word a0)
{
    return fn_8313FCF0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83140038: tailcall fn_8313FCF0 */
ts4_word ts4_tailcall_fn_8313FCF0_83140038(ts4_word a0)
{
    return fn_8313FCF0((ts4_word)a0);
}

/* Loader_DLL.xex 0x831403C8: set u32@0x0, u32@0x8 */
void ts4_set_u32_off0_831403C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831403D8: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_831403D8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)2;
    return;
}

/* Loader_DLL.xex 0x831403E8: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_831403E8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)3;
    return;
}

/* Loader_DLL.xex 0x831403F8: set u32@0x0 */
void ts4_set_u32_off0_831403F8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4) = f1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)4;
    return;
}

/* Loader_DLL.xex 0x83140838: call_seq fn_83140430, u32@0x8, u32@0x4, u32@0x0 */
ts4_word ts4_call_seq_fn_83140430_83140838(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_83140430((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)10;
    return t1;
}

/* Loader_DLL.xex 0x83140BF8: call_seq fn_83147FE8 */
ts4_word ts4_call_seq_fn_83147FE8_83140BF8(ts4_word a0)
{
    fn_83147FE8((ts4_word)a0);
    return a0;
}

/* Loader_DLL.xex 0x83140C28: tailcall fn_83148000 */
ts4_word ts4_tailcall_fn_83148000_83140C28(ts4_word a0)
{
    return fn_83148000((ts4_word)a0);
}

/* Loader_DLL.xex 0x83140C30: tailcall fn_831481E8 */
ts4_word ts4_tailcall_fn_831481E8_83140C30(ts4_word a0, ts4_word a1)
{
    return fn_831481E8((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x83140C38: tailcall fn_831482A8 */
ts4_word ts4_tailcall_fn_831482A8_83140C38(ts4_word a0, ts4_word a1)
{
    return fn_831482A8((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x83140C40: tailcall fn_83148348 */
ts4_word ts4_tailcall_fn_83148348_83140C40(ts4_word a0)
{
    return fn_83148348((ts4_word)a0);
}

/* Loader_DLL.xex 0x83140C48: tailcall fn_831483F8 */
ts4_word ts4_tailcall_fn_831483F8_83140C48(ts4_word a0, ts4_word a1)
{
    return fn_831483F8((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x83140C50: tailcall fn_83148168 */
ts4_word ts4_tailcall_fn_83148168_83140C50(ts4_word a0)
{
    return fn_83148168((ts4_word)a0);
}

/* Loader_DLL.xex 0x83140C58: tailcall fn_83140430 */
ts4_word ts4_tailcall_fn_83140430_83140C58(ts4_word a0)
{
    return fn_83140430((ts4_word)a0);
}

/* Loader_DLL.xex 0x83141178: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_83141178(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831411D8: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_831411D8(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x831411E0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_831411E0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x831411E8: tailcall fn_831488C0 */
ts4_word ts4_tailcall_fn_831488C0_831411E8(ts4_word a0)
{
    return fn_831488C0((ts4_word)a0);
}

/* Loader_DLL.xex 0x831411F0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_831411F0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x831411F8: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_831411F8(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83141200: tailcall fn_83148B70 */
ts4_word ts4_tailcall_fn_83148B70_83141200(ts4_word a0)
{
    return fn_83148B70((ts4_word)a0);
}

/* Loader_DLL.xex 0x83141688: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_83141688(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83141708: tailcall fn_831416B8 */
ts4_word ts4_tailcall_fn_831416B8_83141708(ts4_word a0)
{
    return fn_831416B8((ts4_word)a0);
}

/* Loader_DLL.xex 0x831417B0: fn  */
ts4_word ts4_fn_831417B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return ((((a2 << 16) | (a2 >> 16)) & 0xffff0000) | (a1 & 0xffff));
}

/* Loader_DLL.xex 0x83141B80: get u32@0x0 */
ts4_word ts4_get_u32_off0_83141B80(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x83141B88: get u8@0x4 */
ts4_word ts4_get_u8_off4_83141B88(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x83141B90: get u8@0x5 */
ts4_word ts4_get_u8_off5_83141B90(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 5));
}

/* Loader_DLL.xex 0x83141B98: get u32@0x6 */
ts4_word ts4_get_u32_off6_83141B98(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 6));
}

/* Loader_DLL.xex 0x83141BA0: get u16@0xa */
ts4_word ts4_get_u16_offa_83141BA0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 10));
}

/* Loader_DLL.xex 0x83141BA8: get u32@0x0, u32@0x0, u32@0x0, u32@0x0, fn_833E4108 */
ts4_word ts4_get_u32_off0_83141BA8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    return fn_833E4108((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)));
}

/* Loader_DLL.xex 0x83141BC0: set u32@0x4, u32@0x0, u32@0x8, u32@0xc */
void ts4_set_u32_off4_83141BC0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83141DE0: fn  */
void ts4_fn_83141DE0(void)
{
    return;
}

/* Loader_DLL.xex 0x83141DE8: fn  */
void ts4_fn_83141DE8(void)
{
    return;
}

/* Loader_DLL.xex 0x83141DF0: get u32@0x0, u32@0x8, fn_83141BA8, fn_833E2CA0 */
ts4_word ts4_get_u32_off0_83141DF0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return fn_833E2CA0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)t1, (ts4_word)4, (ts4_word)(ts4_word)fn_83141BA8);
}

/* Loader_DLL.xex 0x83141E98: get u32@0x0 */
ts4_word ts4_get_u32_off0_83141E98(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x83141F38: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x0 */
void ts4_set_u32_off0_83141F38(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)20;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83141FB8: tailcall fn_83140CF0 */
ts4_word ts4_tailcall_fn_83140CF0_83141FB8(ts4_word a0)
{
    return fn_83140CF0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83142008: if_get u32@0x8, u32@0x8, u32@0x0, u32@0x8 */
void ts4_if_get_u32_off8_83142008(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 < 0) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)a1 >= (int)t2) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)((a1 << 1)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83142090: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_83142090(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83142180: set u32@0x0, u32@0x8, u32@0x4 */
void ts4_set_u32_off0_83142180(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x83142190: if_get u32@0x4, u32@0x0, u32@0x8, u32@0x8, u32@0x0, u32@0x8 */
void ts4_if_get_u32_off4_83142190(ts4_word a0)
{
    int t1;
    ts4_word t2;
    int t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 < 0) {
        return;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
    if ((int)t1 >= (int)t4) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)((t1 << 1)) + (*(ts4_word *)((char *)(ts4_word)(t2) + 0))) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)t1;
    return;
}

/* Loader_DLL.xex 0x83142508: tailcall fn_83142118 */
ts4_word ts4_tailcall_fn_83142118_83142508(ts4_word a0)
{
    return fn_83142118((ts4_word)a0);
}

/* Loader_DLL.xex 0x83142AF8: addr fn_831421C8, fn_83142AA8 */
ts4_word ts4_addr_fn_831421C8_83142AF8(ts4_word a0, ts4_word a1)
{
    return fn_83142AA8((ts4_word)a0, (ts4_word)a1, (ts4_word)0, (ts4_word)(ts4_word)fn_831421C8);
}

/* Loader_DLL.xex 0x83142E58: get u32@0x10 */
ts4_word ts4_get_u32_off10_83142E58(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Loader_DLL.xex 0x83142EB8: get u32@0x44 */
ts4_word ts4_get_u32_off44_83142EB8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 68));
}

/* Loader_DLL.xex 0x83142EC0: get u32@0x38 */
ts4_word ts4_get_u32_off38_83142EC0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 56));
}

/* Loader_DLL.xex 0x83142EC8: get u32@0x3c */
ts4_word ts4_get_u32_off3c_83142EC8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 60));
}

/* Loader_DLL.xex 0x83142ED8: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_83142ED8(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83142F38: addr lbl_83002860 */
ts4_word ts4_addr_lbl_83002860_83142F38(void)
{
    return (ts4_word)lbl_83002860;
}

/* Loader_DLL.xex 0x83142F48: addr lbl_83000C6C */
ts4_word ts4_addr_lbl_83000C6C_83142F48(void)
{
    return (ts4_word)lbl_83000C6C;
}

/* Loader_DLL.xex 0x83143130: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_83143130(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83143148: get u32@0x8 */
ts4_word ts4_get_u32_off8_83143148(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x831431D8: get u32@0x0 */
ts4_word ts4_get_u32_off0_831431D8(ts4_word a0, ts4_word a1)
{
    return ((a1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x831431F8: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_831431F8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83143210: get u32@0x4 */
ts4_word ts4_get_u32_off4_83143210(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x83143218: get u32@0x0 */
ts4_word ts4_get_u32_off0_83143218(ts4_word a0, ts4_word a1)
{
    return ((a1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x83143228: fn  */
void ts4_fn_83143228(void)
{
    return;
}

/* Loader_DLL.xex 0x83143230: addr lbl_83002860, fn_8310D380 */
ts4_word ts4_addr_lbl_83002860_83143230(void)
{
    return fn_8310D380((ts4_word)(ts4_word)lbl_83002860);
}

/* Loader_DLL.xex 0x831433A0: fn  */
ts4_word ts4_fn_831433A0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831433A8: fn  */
ts4_word ts4_fn_831433A8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831433B0: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_831433B0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Loader_DLL.xex 0x831433C0: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_831433C0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Loader_DLL.xex 0x831433D0: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_831433D0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Loader_DLL.xex 0x831433F8: fn  */
ts4_word ts4_fn_831433F8(ts4_word a0, ts4_word a1)
{
    return a1;

    (void)a0;}

/* Loader_DLL.xex 0x83143400: fn  */
ts4_word ts4_fn_83143400(ts4_word a0, ts4_word a1)
{
    return a1;

    (void)a0;}

/* Loader_DLL.xex 0x83143408: fn  */
ts4_word ts4_fn_83143408(ts4_word a0, ts4_word a1)
{
    return a1;

    (void)a0;}

/* Loader_DLL.xex 0x83143410: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x0 */
void ts4_set_u32_off0_83143410(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)20;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831434F8: set u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_set_u32_off4_831434F8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83143718: tailcall fn_83143150 */
ts4_word ts4_tailcall_fn_83143150_83143718(ts4_word a0)
{
    return fn_83143150((ts4_word)a0);
}

/* Loader_DLL.xex 0x83143720: tailcall fn_83143330 */
ts4_word ts4_tailcall_fn_83143330_83143720(ts4_word a0)
{
    return fn_83143330((ts4_word)a0);
}

/* Loader_DLL.xex 0x83143758: if_get u32@0x0, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off0_83143758(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)((a1 << 2) + t1) == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(((a1 << 2) + t1)) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Loader_DLL.xex 0x83144050: tailcall fn_83143E08 */
ts4_word ts4_tailcall_fn_83143E08_83144050(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    return fn_83143E08((ts4_word)a2);
}

/* Loader_DLL.xex 0x83144058: call_seq u32@0x4, fn_83120540, fn_83143B40 */
ts4_word ts4_call_seq_u32_off4_83144058(ts4_word a0)
{
    ts4_word t3;

    fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t3 = fn_83143B40((ts4_word)a0);
    return t3;
}

/* Loader_DLL.xex 0x83144268: tailcall fn_831441C0 */
ts4_word ts4_tailcall_fn_831441C0_83144268(ts4_word a0)
{
    return fn_831441C0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83144270: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_83144270(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83144288: get u32@0x0, fn_83120540 */
ts4_word ts4_get_u32_off0_83144288(ts4_word a0)
{
    return fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x83144290: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_83144290(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x831442B0: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_831442B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x831442D0: set u16@0x0, u32@0x4, u16@0x2, u32@0x8, u32@0xc */
void ts4_set_u16_off0_831442D0(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 0) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 2) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831442F0: set u16@0x0, u32@0x4, u16@0x2, u32@0x8, u32@0xc */
void ts4_set_u16_off0_831442F0(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 0) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 2) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83144468: fn  */
void ts4_fn_83144468(void)
{
    return;
}

/* Loader_DLL.xex 0x83144858: fn  */
void ts4_fn_83144858(void)
{
    return;
}

/* Loader_DLL.xex 0x83144860: set u32@0x18 */
void ts4_set_u32_off18_83144860(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83144A30: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_83144A30(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83144A38: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_83144A38(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83144A48: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_83144A48(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83144A98: get u32@0x0 */
ts4_word ts4_get_u32_off0_83144A98(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x83144AA0: get u32@0x4 */
ts4_word ts4_get_u32_off4_83144AA0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x83144AA8: get u32@0x8 */
ts4_word ts4_get_u32_off8_83144AA8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x83144AB0: get u32@0xc */
ts4_word ts4_get_u32_offc_83144AB0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x83144AB8: get u32@0x10 */
ts4_word ts4_get_u32_off10_83144AB8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Loader_DLL.xex 0x83144AC0: get u16@0x14 */
ts4_word ts4_get_u16_off14_83144AC0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Loader_DLL.xex 0x83144AC8: get u32@0x0 */
ts4_word ts4_get_u32_off0_83144AC8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x83144AD0: get u32@0x4 */
ts4_word ts4_get_u32_off4_83144AD0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x83144AD8: get u8@0x8 */
ts4_word ts4_get_u8_off8_83144AD8(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x83144AE0: get u32@lbl_83527DF8 */
ts4_word ts4_get_u32_lbl_83527DF8_83144AE0(void)
{
    return (*(ts4_word *)lbl_83527DF8);
}

/* Loader_DLL.xex 0x83144AF0: fn  */
ts4_word ts4_fn_83144AF0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83144CA0: tailcall fn_830FFBE8 */
ts4_word ts4_tailcall_fn_830FFBE8_83144CA0(ts4_word a0)
{
    return fn_830FFBE8((ts4_word)(a0 + 8));
}

/* Loader_DLL.xex 0x83144F08: get u32@0xc */
ts4_word ts4_get_u32_offc_83144F08(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x83144F10: get u32@0x10 */
ts4_word ts4_get_u32_off10_83144F10(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Loader_DLL.xex 0x83145220: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_83145220(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83145228: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_83145228(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83145240: get u32@0x8 */
ts4_word ts4_get_u32_off8_83145240(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x83145300: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_83145300(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Loader_DLL.xex 0x83145310: fn  */
ts4_word ts4_fn_83145310(ts4_word a0, ts4_word a1)
{
    return a1;

    (void)a0;}

/* Loader_DLL.xex 0x83145318: fn  */
ts4_word ts4_fn_83145318(ts4_word a0, ts4_word a1)
{
    return a1;

    (void)a0;}

/* Loader_DLL.xex 0x83145320: if_get u32@0xc, u32@0x8 */
ts4_word ts4_if_get_u32_offc_83145320(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 == 0) {
        return 0;
    }
    return (*(ts4_word *)((char *)(ts4_word)(t1) + 8));
}

/* Loader_DLL.xex 0x831458B8: tailcall fn_831457D0 */
ts4_word ts4_tailcall_fn_831457D0_831458B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_831457D0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x83145968: tailcall fn_831458C0 */
ts4_word ts4_tailcall_fn_831458C0_83145968(ts4_word a0)
{
    return fn_831458C0((ts4_word)a0);
}

/* Loader_DLL.xex 0x831459B8: tailcall fn_831458C0 */
ts4_word ts4_tailcall_fn_831458C0_831459B8(ts4_word a0)
{
    return fn_831458C0((ts4_word)a0);
}

/* Loader_DLL.xex 0x831459C0: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_831459C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831460C0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_831460C0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x831460C8: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_831460C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83146140: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_83146140(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83146148: call_seq fn_833E3A30 */
ts4_word ts4_call_seq_fn_833E3A30_83146148(ts4_word a0)
{
    fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)128);
    return a0;
}

/* Loader_DLL.xex 0x83146180: fn  */
void ts4_fn_83146180(void)
{
    return;
}

/* Loader_DLL.xex 0x83146A30: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_83146A30(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83146A50: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_83146A50(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83146A68: get u32@lbl_83527DFC */
ts4_word ts4_get_u32_lbl_83527DFC_83146A68(void)
{
    return (*(ts4_word *)lbl_83527DFC);
}

/* Loader_DLL.xex 0x83146A78: fn  */
ts4_word ts4_fn_83146A78(void)
{
    return 1;
}

/* Loader_DLL.xex 0x83146C78: get u32@0xc */
ts4_word ts4_get_u32_offc_83146C78(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x83146C80: get u32@0x10 */
ts4_word ts4_get_u32_off10_83146C80(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Loader_DLL.xex 0x83146C88: fn  */
ts4_word ts4_fn_83146C88(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83146C98: fn  */
ts4_word ts4_fn_83146C98(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83147480: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_83147480(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x831474C0: get u32@lbl_83527E00 */
ts4_word ts4_get_u32_lbl_83527E00_831474C0(void)
{
    return (*(ts4_word *)lbl_83527E00);
}

/* Loader_DLL.xex 0x831474D0: fn  */
ts4_word ts4_fn_831474D0(void)
{
    return 1;
}

/* Loader_DLL.xex 0x831474D8: fn  */
ts4_word ts4_fn_831474D8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831474E0: fn  */
ts4_word ts4_fn_831474E0(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x831478D8: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_831478D8(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83147918: get u32@lbl_83527E04 */
ts4_word ts4_get_u32_lbl_83527E04_83147918(void)
{
    return (*(ts4_word *)lbl_83527E04);
}

/* Loader_DLL.xex 0x83147928: fn  */
ts4_word ts4_fn_83147928(void)
{
    return 1;
}

/* Loader_DLL.xex 0x83147930: fn  */
ts4_word ts4_fn_83147930(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83147938: fn  */
ts4_word ts4_fn_83147938(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83147AA0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_83147AA0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83147BA8: get u32@0x8 */
ts4_word ts4_get_u32_off8_83147BA8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x83147BB0: get u32@0x8, u32@0xc */
ts4_word ts4_get_u32_off8_83147BB0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return (t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
}

/* Loader_DLL.xex 0x83147BC0: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_83147BC0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    return 0;
}

/* Loader_DLL.xex 0x83147BD0: fn  */
ts4_word ts4_fn_83147BD0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83148130: get u32@0x0 */
void ts4_get_u32_off0_83148130(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + a1) = (unsigned char)a2;
    return;
}

/* Loader_DLL.xex 0x83148140: get u32@0x0 */
void ts4_get_u32_off0_83148140(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + a1) = (unsigned short)a2;
    return;
}

/* Loader_DLL.xex 0x83148150: get u32@0x0 */
void ts4_get_u32_off0_83148150(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + a1) = (ts4_word)a2;
    return;
}

/* Loader_DLL.xex 0x83148160: get u32@0x0 */
ts4_word ts4_get_u32_off0_83148160(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x83148408: set u32@0x0, u8@0x4, u8@0x5, u8@0x6, u8@0x7, u32@0x8 */
void ts4_set_u32_off0_83148408(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 6) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 7) = (unsigned char)50;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83148490: set u32@0x0, u8@0x4, u8@0x5, u8@0x6, u8@0x7, u32@0x8 */
void ts4_set_u32_off0_83148490(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 6) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 7) = (unsigned char)50;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831484B8: get u8@0x4 */
ts4_word ts4_get_u8_off4_831484B8(ts4_word a0)
{
    return (((*(unsigned char *)((char *)(ts4_word)(a0) + 4)) >> 1) & 0x3);
}

/* Loader_DLL.xex 0x831484C8: set u32@0x0, u8@0x4, u8@0x5, u8@0x6, u8@0x7, u32@0x8 */
void ts4_set_u32_off0_831484C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 6) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 7) = (unsigned char)50;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831486A8: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_831486A8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831486D0: tailcall fn_830FFBE8 */
ts4_word ts4_tailcall_fn_830FFBE8_831486D0(ts4_word a0)
{
    return fn_830FFBE8((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x831486E0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_831486E0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x831486E8: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_831486E8(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83148720: tailcall fn_831484F0 */
ts4_word ts4_tailcall_fn_831484F0_83148720(ts4_word a0)
{
    return fn_831484F0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83148728: tailcall fn_83148560 */
ts4_word ts4_tailcall_fn_83148560_83148728(ts4_word a0)
{
    return fn_83148560((ts4_word)a0);
}

/* Loader_DLL.xex 0x83148730: tailcall fn_830FFBE8 */
ts4_word ts4_tailcall_fn_830FFBE8_83148730(ts4_word a0)
{
    return fn_830FFBE8((ts4_word)(a0 + 4));
}

/* Loader_DLL.xex 0x831488B8: tailcall fn_831487C0 */
ts4_word ts4_tailcall_fn_831487C0_831488B8(ts4_word a0)
{
    return fn_831487C0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83148AB8: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_83148AB8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83148B58: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_83148B58(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83148D28: get u32@0x44 */
ts4_word ts4_get_u32_off44_83148D28(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 68));
}

/* Loader_DLL.xex 0x83148D30: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_set_u32_off0_83148D30(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83148D50: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_83148D50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    return;
}

/* Loader_DLL.xex 0x83149388: call_seq fn_830AD8F8 */
ts4_word ts4_call_seq_fn_830AD8F8_83149388(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_830AD8F8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return 0;
}

/* Loader_DLL.xex 0x831493B0: if_get  */
ts4_word ts4_if_get_831493B0(ts4_word a0, ts4_word a1)
{
    float t1;
    float t2;
    float t3;
    float t4;

    t1 = *(float *)((char *)(ts4_word)(a0) + 0);
    t2 = *(float *)((char *)(ts4_word)(a1) + 0);
    if (t1 == t2) {
        t3 = *(float *)((char *)(ts4_word)(a0) + 4);
        t4 = *(float *)((char *)(ts4_word)(a1) + 4);
        if (t3 == t4) {
            return 0;
        }
        return 1;
    }
    return 1;
}

/* Loader_DLL.xex 0x831493E0: set  */
void ts4_set_831493E0(ts4_word a0, float f1, float f2, float f3, float f4)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    *(float *)((char *)(ts4_word)(a0) + 4) = f2;
    *(float *)((char *)(ts4_word)(a0) + 8) = f3;
    *(float *)((char *)(ts4_word)(a0) + 12) = f4;
    return;
}

/* Loader_DLL.xex 0x831494A0: fn  */
void ts4_fn_831494A0(void)
{
    return;
}

/* Loader_DLL.xex 0x831494B0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_831494B0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x831494B8: fn  */
void ts4_fn_831494B8(void)
{
    return;
}

/* Loader_DLL.xex 0x831494E0: fn  */
void ts4_fn_831494E0(void)
{
    return;
}

/* Loader_DLL.xex 0x831494E8: fn  */
void ts4_fn_831494E8(void)
{
    return;
}

/* Loader_DLL.xex 0x831494F0: set u32@0x0, u32@0x0 */
void ts4_set_u32_off0_831494F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x83149508: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_83149508(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83149518: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_83149518(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x83149540: fn  */
void ts4_fn_83149540(void)
{
    return;
}

/* Loader_DLL.xex 0x83149578: set u8@0xc, u32@0x10, u32@0x14 */
void ts4_set_u8_offc_83149578(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83149590: tailcall fn_830FF018 */
ts4_word ts4_tailcall_fn_830FF018_83149590(ts4_word a0)
{
    return fn_830FF018((ts4_word)a0);
}

/* Loader_DLL.xex 0x83149598: tailcall fn_830FF0B0 */
ts4_word ts4_tailcall_fn_830FF0B0_83149598(ts4_word a0)
{
    return fn_830FF0B0((ts4_word)a0);
}

/* Loader_DLL.xex 0x831495A0: get u32@0x10, u32@0x14, u32@0x18 */
void ts4_get_u32_off10_831495A0(ts4_word a0)
{
    float t1;
    float t2;

    t1 = *(float *)lbl_83002898;
    t2 = *(float *)lbl_83003F40;
    *(volatile float *)((char *)(ts4_word)(a0) + 0) = t1;
    *(volatile float *)((char *)(ts4_word)(a0) + 4) = t1;
    *(volatile float *)((char *)(ts4_word)(a0) + 8) = t2;
    *(volatile float *)((char *)(ts4_word)(a0) + 12) = t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83149878: call_seq fn_83149750 */
ts4_word ts4_call_seq_fn_83149750_83149878(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = fn_83149750((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return (t1 == 0);
}

/* Loader_DLL.xex 0x83149DB0: call_seq lbl_835312D0, RtlInitializeCriticalSection */
ts4_word ts4_call_seq_lbl_835312D0_83149DB0(ts4_word a0)
{
    RtlInitializeCriticalSection((ts4_word)(ts4_word)lbl_835312D0);
    return a0;
}

/* Loader_DLL.xex 0x83149DE8: fn  */
void ts4_fn_83149DE8(void)
{
    return;
}

/* Loader_DLL.xex 0x83149DF0: fn  */
void ts4_fn_83149DF0(void)
{
    return;
}

/* Loader_DLL.xex 0x83149EE0: fn  */
ts4_word ts4_fn_83149EE0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83149EE8: fn  */
ts4_word ts4_fn_83149EE8(void)
{
    return 1;
}

/* Loader_DLL.xex 0x83149EF0: if_get u32@0x8, u32@0x1c, u32@0x1c, fn_8315EF40 */
ts4_word ts4_if_get_u32_off8_83149EF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    int t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((int)t3 == 0) {
        return a0;
    }
    return fn_8315EF40((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83149F18: set u32@0x18 */
ts4_word ts4_set_u32_off18_83149F18(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x83149F88: set u32@0xc */
void ts4_set_u32_offc_83149F88(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83149F90: get u32@0xc */
ts4_word ts4_get_u32_offc_83149F90(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x83149F98: get u32@0x10 */
ts4_word ts4_get_u32_off10_83149F98(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Loader_DLL.xex 0x83149FA0: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_83149FA0(ts4_word a0)
{
    float t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    t1 = *(float *)lbl_830009F8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 32) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8314A3B8: get u32@0xc */
ts4_word ts4_get_u32_offc_8314A3B8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x8314A3C0: get u32@0x4 */
ts4_word ts4_get_u32_off4_8314A3C0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x8314A810: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_8314A810(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314B338: set u32@0xa8 */
ts4_word ts4_set_u32_offa8_8314B338(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x8314B348: if_get u32@0xa8, u32@0x0 */
ts4_word ts4_if_get_u32_offa8_8314B348(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return ((2147942400) | 87);
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 168));
    return 0;
}

/* Loader_DLL.xex 0x8314B460: if_get u32@0xb8, u32@0xb8, u32@0x90 */
void ts4_if_get_u32_offb8_8314B460(ts4_word a0, int a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
    if ((int)t1 == (int)a1) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)-1;
    return;
}

/* Loader_DLL.xex 0x8314B480: get u32@0xb8 */
ts4_word ts4_get_u32_offb8_8314B480(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 184));
}

/* Loader_DLL.xex 0x8314B488: fn  */
ts4_word ts4_fn_8314B488(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8314B800: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_8314B800(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314C5C0: fn  */
ts4_word ts4_fn_8314C5C0(ts4_word a0)
{
    return (((~(a0 | a0)) >> 4) & 0x1);
}

/* Loader_DLL.xex 0x8314C5D0: fn  */
ts4_word ts4_fn_8314C5D0(ts4_word a0)
{
    return (((~(a0 | a0)) >> 5) & 0x1);
}

/* Loader_DLL.xex 0x8314C6E0: get u32@0x170 */
ts4_word ts4_get_u32_off170_8314C6E0(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 368)) != 0);
}

/* Loader_DLL.xex 0x8314C7D8: get u32@0x14c */
ts4_word ts4_get_u32_off14c_8314C7D8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 332));
}

/* Loader_DLL.xex 0x8314C7E0: fn  */
ts4_word ts4_fn_8314C7E0(void)
{
    return 1;
}

/* Loader_DLL.xex 0x8314C898: tailcall fn_8314C7E8 */
ts4_word ts4_tailcall_fn_8314C7E8_8314C898(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    return fn_8314C7E8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)8, (ts4_word)a5, (ts4_word)a6);
}

/* Loader_DLL.xex 0x8314C8A8: tailcall fn_8314C7E8 */
ts4_word ts4_tailcall_fn_8314C7E8_8314C8A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    return fn_8314C7E8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)16, (ts4_word)a5, (ts4_word)a6);
}

/* Loader_DLL.xex 0x8314C950: get  */
float ts4_get_8314C950(void)
{
    return (*(float *)lbl_830009EC);
}

/* Loader_DLL.xex 0x8314C9C8: fn  */
void ts4_fn_8314C9C8(void)
{
    return;
}

/* Loader_DLL.xex 0x8314CEB8: tailcall fn_8315DED8 */
ts4_word ts4_tailcall_fn_8315DED8_8314CEB8(ts4_word a0, ts4_word a1)
{
    return fn_8315DED8((ts4_word)(a0 + 24), (ts4_word)a1);
}

/* Loader_DLL.xex 0x8314D0D8: tailcall fn_8315DED8 */
ts4_word ts4_tailcall_fn_8315DED8_8314D0D8(ts4_word a0, ts4_word a1)
{
    return fn_8315DED8((ts4_word)(a0 + 24), (ts4_word)a1);
}

/* Loader_DLL.xex 0x8314D420: tailcall fn_8315DED8 */
ts4_word ts4_tailcall_fn_8315DED8_8314D420(ts4_word a0, ts4_word a1)
{
    return fn_8315DED8((ts4_word)(a0 + 24), (ts4_word)a1);
}

/* Loader_DLL.xex 0x8314D5C8: get u32@lbl_835312B8 */
ts4_word ts4_get_u32_lbl_835312B8_8314D5C8(void)
{
    return (*(ts4_word *)lbl_835312B8);
}

/* Loader_DLL.xex 0x8314D5D8: get u32@lbl_835312B4 */
ts4_word ts4_get_u32_lbl_835312B4_8314D5D8(void)
{
    return ((*(ts4_word *)lbl_835312B4) & 0x1);
}

/* Loader_DLL.xex 0x8314D5E8: fn  */
void ts4_fn_8314D5E8(void)
{
    return;
}

/* Loader_DLL.xex 0x8314D5F0: fn  */
void ts4_fn_8314D5F0(void)
{
    return;
}

/* Loader_DLL.xex 0x8314D5F8: fn  */
void ts4_fn_8314D5F8(void)
{
    return;
}

/* Loader_DLL.xex 0x8314D600: fn  */
void ts4_fn_8314D600(void)
{
    return;
}

/* Loader_DLL.xex 0x8314D608: fn  */
void ts4_fn_8314D608(void)
{
    return;
}

/* Loader_DLL.xex 0x8314D610: fn  */
void ts4_fn_8314D610(void)
{
    return;
}

/* Loader_DLL.xex 0x8314E5E8: get u32@lbl_835312B4, u32@lbl_835312B4 */
void ts4_get_u32_lbl_835312B4_8314E5E8(void)
{
    *(ts4_word *)lbl_835312B4 = (ts4_word)((*(ts4_word *)lbl_835312B4) | 1);
    return;
}

/* Loader_DLL.xex 0x8314E8A0: if_get u32@0xac, u32@0x0, u32@0xa4, u32@0x0, u32@0xb0, u32@0x0 */
void ts4_if_get_u32_offac_8314E8A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 172));
    }
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 164));
    }
    if ((ts4_word)a3 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 176));
    return;
}

/* Loader_DLL.xex 0x8314E908: get u32@lbl_835312B4 */
ts4_word ts4_get_u32_lbl_835312B4_8314E908(void)
{
    return ((*(ts4_word *)lbl_835312B4) & 0x2);
}

/* Loader_DLL.xex 0x8314EA40: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_8314EA40(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314EAC0: get u32@0x8 */
ts4_word ts4_get_u32_off8_8314EAC0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x8314EAC8: fn  */
ts4_word ts4_fn_8314EAC8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8314EAD0: fn  */
ts4_word ts4_fn_8314EAD0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8314ED00: set u32@0x0 */
ts4_word ts4_set_u32_off0_8314ED00(ts4_word a0, ts4_word a1)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8314F048: set u32@0x0, u32@0x0 */
void ts4_set_u32_off0_8314F048(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)128;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8314F238: set u32@0x0, u32@0x0 */
void ts4_set_u32_off0_8314F238(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)128;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8314F300: tailcall fn_831495D8 */
ts4_word ts4_tailcall_fn_831495D8_8314F300(ts4_word a0)
{
    return fn_831495D8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8314F9B8: tailcall fn_83149FD8 */
ts4_word ts4_tailcall_fn_83149FD8_8314F9B8(ts4_word a0)
{
    return fn_83149FD8((ts4_word)a0);
}

/* Loader_DLL.xex 0x83150E38: get u32@0x50 */
ts4_word ts4_get_u32_off50_83150E38(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 80));
}

/* Loader_DLL.xex 0x83150E40: get u32@0x50, u32@0x50 */
ts4_word ts4_get_u32_off50_83150E40(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)a1;
    return t1;
}
