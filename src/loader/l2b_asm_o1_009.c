/* Loader_DLL.xex 0x83183958-0x8318B1E8, executable version 0.0.0.3. */
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

ts4_word fn_831767A0();
ts4_word fn_83176830();
ts4_word fn_83183080();
ts4_word fn_83183900();
ts4_word fn_83183E60();
ts4_word fn_831842E8();
ts4_word fn_83184ED8();
ts4_word fn_83185DA8();
ts4_word fn_83186590();
ts4_word fn_83186A58();
ts4_word fn_83186BB0();
ts4_word fn_83187128();
ts4_word fn_83187B88();
ts4_word fn_83187FC0();
ts4_word fn_831888B0();
ts4_word fn_83188928();
ts4_word fn_83188980();
ts4_word fn_83188B68();
ts4_word fn_83188F68();
ts4_word fn_83189000();
ts4_word fn_83189130();
ts4_word fn_83189500();
ts4_word fn_83189CF8();
ts4_word fn_83189D80();
ts4_word fn_8318A010();
ts4_word fn_831BB1B8();

/* Loader_DLL.xex 0x83183958: if_call_seq fn_83183900, fn_83183080 */
ts4_word ts4l_if_call_seq_fn_83183900_83183958(ts4_word a0, ts4_word a1)
{

    fn_83183900((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83183080((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831844F8: if_call_seq fn_831842E8, fn_83183E60 */
ts4_word ts4l_if_call_seq_fn_831842E8_831844F8(ts4_word a0, ts4_word a1)
{

    fn_831842E8((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83183E60((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831864A0: if_call_seq fn_83185DA8, fn_83184ED8 */
ts4_word ts4l_if_call_seq_fn_83185DA8_831864A0(ts4_word a0, ts4_word a1)
{

    fn_83185DA8((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83184ED8((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83186AC0: if_call_seq fn_83186A58, fn_83186590 */
ts4_word ts4l_if_call_seq_fn_83186A58_83186AC0(ts4_word a0, ts4_word a1)
{

    fn_83186A58((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83186590((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831873F8: if_call_seq fn_83187128, fn_83186BB0 */
ts4_word ts4l_if_call_seq_fn_83187128_831873F8(ts4_word a0, ts4_word a1)
{

    fn_83187128((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83186BB0((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831882D0: if_call_seq fn_83187FC0, fn_83187B88 */
ts4_word ts4l_if_call_seq_fn_83187FC0_831882D0(ts4_word a0, ts4_word a1)
{

    fn_83187FC0((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83187B88((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83189708: get u32@0x30, u32@0x2c, u32@0x8, vcall, fn_83189500, u32@0x8 */
ts4_word ts4l_get_u32_off30_83189708(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = fn_83189500((ts4_word)a0, (ts4_word)a1);
    fn_83189130((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 8)), (ts4_word)a2);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 44))) + 20))))((ts4_word)(t8 + 44));
    return t11;
}

/* Loader_DLL.xex 0x8318A310: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x34, fn_831888B0 */
ts4_word ts4l_get_u32_off30_8318A310(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t7;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    fn_831888B0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)a1, (ts4_word)a2);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 44))) + 20))))((ts4_word)(t7 + 44));
    return t10;
}

/* Loader_DLL.xex 0x8318A370: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x34, fn_83188928 */
ts4_word ts4l_get_u32_off30_8318A370(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t6;
    ts4_word t8;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t6 = fn_83188928((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    loc50[0] = (ts4_word)t6;
    fn_83189000((ts4_word)(ts4_word)&loc50[0]);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 44))) + 20))))((ts4_word)(t8 + 44));
    t12 = loc50[0];
    return t12;
}

/* Loader_DLL.xex 0x8318A3F0: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x34, fn_83188980 */
ts4_word ts4l_get_u32_off30_8318A3F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t6;
    ts4_word t8;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t6 = fn_83188980((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    loc50[0] = (ts4_word)t6;
    fn_83189000((ts4_word)(ts4_word)&loc50[0]);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 44))) + 20))))((ts4_word)(t8 + 44));
    t12 = loc50[0];
    return t12;
}

/* Loader_DLL.xex 0x8318A920: if_call_seq fn_83189D80, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4l_if_call_seq_fn_83189D80_8318A920(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_83189D80((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x8318A9A0: if_call_seq fn_83189CF8, fn_83188B68, fn_83188F68 */
ts4_word ts4l_if_call_seq_fn_83189CF8_8318A9A0(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;
    ts4_word t1;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a1 == 0) {
        p5 = (ts4_word)a0;
        if ((ts4_word)a2 != 0) {
            fn_83188B68((ts4_word)a2);
            t4 = fn_83188F68((ts4_word)a2);
            p5 = (ts4_word)t4;
        }
        p6 = (ts4_word)p5;
    } else {
        p2 = (ts4_word)a0;
        if ((ts4_word)a2 != 0) {
            t1 = fn_83189CF8((ts4_word)a2, (ts4_word)3);
            p2 = (ts4_word)t1;
        }
        p6 = (ts4_word)p2;
    }
    return p6;
}

/* Loader_DLL.xex 0x8318AA00: if_call_seq u32@0x8, fn_831BB1B8, fn_83188F68, u32@0x8 */
ts4_word ts4l_if_call_seq_u32_off8_8318AA00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        fn_831BB1B8((ts4_word)t1);
        t3 = fn_83188F68((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x8318AA80: if_call_seq fn_8318A010, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4l_if_call_seq_fn_8318A010_8318AA80(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_8318A010((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x8318B188: if_call_seq u32@0x0, fn_83176830, fn_831767A0, fn_83188F68 */
ts4_word ts4l_if_call_seq_u32_off0_8318B188(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    fn_83176830((ts4_word)(a0 + 80));
    fn_831767A0((ts4_word)(a0 + 8));
    if ((int)(a1 & 0x1) != 0) {
        fn_83188F68((ts4_word)a0);
    }
    return a0;
}
