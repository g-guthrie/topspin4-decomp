/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char lbl_88000A3C[];
extern char lbl_88028B5C[];
extern char lbl_88028D18[];
extern char lbl_8803A308[];
extern char lbl_88040228[];
extern char lbl_8804116C[];
extern char lbl_880411C8[];
extern char lbl_880411DC[];
extern char lbl_880411F0[];
extern char lbl_880415D4[];
extern char lbl_880415F8[];
extern char lbl_88041618[];
extern char lbl_88042074[];
extern char lbl_88042098[];
extern char lbl_88042140[];
extern char lbl_88048610[];
extern char lbl_88053F68[];
extern char lbl_8805704C[];
extern char lbl_8805C14C[];
extern char lbl_8805C1EC[];
extern char lbl_8805C258[];
extern char lbl_8805C27C[];
extern char lbl_8805C2C4[];
extern char lbl_880C1320[];
extern char lbl_880D19F0[];
extern char lbl_880F799C[];
extern char lbl_88B30F80[];
extern char lbl_88B8D2E0[];
extern char lbl_88B8D340[];
extern char lbl_88B8D418[];
extern char lbl_88B8D520[];
extern char lbl_88B8D550[];
extern char lbl_88B8D554[];
extern char lbl_88B8D584[];
extern char lbl_88B8D588[];
extern char lbl_88B8D618[];
extern char lbl_88B8D648[];
extern char lbl_88B8D6D8[];
extern char lbl_88B8D828[];
extern char lbl_88B8D8E8[];
extern char lbl_88B8D900[];
extern char lbl_88B8D990[];
extern char lbl_88B8D9AC[];
extern char lbl_88B92C50[];
extern char lbl_88B92DE8[];
extern char lbl_88C2289C[];
extern char lbl_88C24200[];
extern char lbl_88C6C278[];
extern char lbl_88C6C28C[];
extern char lbl_88C6C2A0[];
extern char lbl_88C6C2C4[];
extern char lbl_88C6C300[];
extern char lbl_88C6C3E8[];
extern char lbl_88C6C6AC[];
extern char lbl_88C6CD9C[];
extern char lbl_88C6E268[];
extern char lbl_88C74928[];
extern char lbl_88CACF08[];
extern char lbl_88CAD338[];
extern char lbl_88CB006C[];
extern char lbl_88CB2C04[];
extern char lbl_88CB5BBC[];
extern char lbl_88CB8F04[];
extern char lbl_88CBC27C[];
extern char lbl_88CBF624[];
extern char lbl_88CC29CC[];
extern char lbl_88CC6554[];
extern char lbl_88CCA55C[];
extern char lbl_88CCE534[];
extern char lbl_88CD262C[];
extern char lbl_88CD6724[];
extern char lbl_88CDA96C[];
extern char lbl_88CDAFE4[];
extern char lbl_88CDB104[];
extern char lbl_88CDB134[];
extern char lbl_88CDB164[];
extern char lbl_88CDB194[];
extern char lbl_88CDB1F4[];
extern char lbl_88CDB224[];
extern char lbl_88CDB284[];
extern char lbl_88CDB2B4[];
extern char lbl_88CDB2E4[];
extern char lbl_88CDB314[];
extern char lbl_88CDB344[];
extern char lbl_88CDB374[];
extern char lbl_88CDB3A4[];
extern char lbl_88CDB3D4[];
extern char lbl_88CDB644[];
extern char lbl_88CDEBB4[];
extern char lbl_88CE375C[];
extern char lbl_88CE8304[];
extern char lbl_88CED47C[];
extern char lbl_88CF2564[];
extern char lbl_88CF785C[];
extern char lbl_88CFCB54[];
extern char lbl_88D01E4C[];
extern char lbl_88D07144[];
extern char lbl_88D0CA0C[];
extern char lbl_88D122D4[];
extern char lbl_88D17C2C[];
extern char lbl_88D1D704[];
extern char lbl_88D2320C[];
extern char lbl_88D26F88[];
extern char lbl_88D26FB0[];
extern char lbl_88D2E270[];
extern char lbl_88D3CB08[];
extern char lbl_88D3CB10[];
extern char lbl_88D48854[];
extern char lbl_88D493C8[];
extern char lbl_88D49884[];
extern char lbl_88D498BC[];
extern char lbl_88D498C4[];
extern char lbl_88D498CC[];
extern char lbl_88D498D4[];
extern char lbl_88D4BD54[];
ts4_word KeTlsFree();
ts4_word fn_8817C008();
ts4_word fn_8818A360();
ts4_word fn_8818A530();
ts4_word fn_88198F20();
ts4_word fn_88199E90();
ts4_word fn_88224B38();
ts4_word fn_88316460();
ts4_word ts4_addr_lbl_880292C8_8832E758();
ts4_word fn_8841F080();
ts4_word fn_88472748();
ts4_word ts4_if_call_seq_u32_off18_885018B0();
ts4_word fn_88617D28();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_forward_883165A0();

/* Swing_DLL.xex 0x88A43B20: call_seq lbl_8805C14C, lbl_88B8D2E0, lbl_88CDAFE4, lbl_880411F0, lbl_88CDB104, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805C14C_88A43B20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB104, (ts4_word)(ts4_word)lbl_880411F0, (ts4_word)(ts4_word)lbl_88CDAFE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D2E0, (ts4_word)4, (ts4_word)(ts4_word)lbl_8805C14C, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43B98: call_seq lbl_88B8D340, lbl_88CDAFE4, lbl_880411C8, lbl_88CDB134, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D340_88A43B98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB134, (ts4_word)(ts4_word)lbl_880411C8, (ts4_word)(ts4_word)lbl_88CDAFE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D340, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43C10: call_seq lbl_88B8D418, lbl_88CDAFE4, lbl_88048610, lbl_88CDB164, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D418_88A43C10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB164, (ts4_word)(ts4_word)lbl_88048610, (ts4_word)(ts4_word)lbl_88CDAFE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D418, (ts4_word)11, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43C88: call_seq lbl_88B8D520, lbl_88CDAFE4, lbl_88042140, lbl_88CDB194, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D520_88A43C88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB194, (ts4_word)(ts4_word)lbl_88042140, (ts4_word)(ts4_word)lbl_88CDAFE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D520, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43D00: addr lbl_88B92C50, u32@lbl_88B8D550, u32@0x68 */
void ts4_addr_lbl_88B92C50_88A43D00(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B92C50) + 104) = (ts4_word)(*(ts4_word *)lbl_88B8D550);
    return;
}

/* Swing_DLL.xex 0x88A43D90: call_seq lbl_8805C1EC, lbl_88B8D554, lbl_88CDB644, lbl_88053F68, lbl_88CDB1F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805C1EC_88A43D90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB1F4, (ts4_word)(ts4_word)lbl_88053F68, (ts4_word)(ts4_word)lbl_88CDB644, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D554, (ts4_word)2, (ts4_word)(ts4_word)lbl_8805C1EC, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43E08: call_seq lbl_88B8D588, lbl_88042098, lbl_88CDB224, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D588_88A43E08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB224, (ts4_word)(ts4_word)lbl_88042098, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D588, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43E78: addr lbl_88B92DE8, u32@lbl_88B8D584, u32@0x50 */
void ts4_addr_lbl_88B92DE8_88A43E78(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B92DE8) + 80) = (ts4_word)(*(ts4_word *)lbl_88B8D584);
    return;
}

/* Swing_DLL.xex 0x88A43F08: call_seq lbl_88B8D618, lbl_88CDAFE4, lbl_88042074, lbl_88CDB284, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D618_88A43F08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB284, (ts4_word)(ts4_word)lbl_88042074, (ts4_word)(ts4_word)lbl_88CDAFE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D618, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43F80: call_seq lbl_8805C258, lbl_88B8D648, lbl_88CDAFE4, lbl_88041618, lbl_88CDB2B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805C258_88A43F80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB2B4, (ts4_word)(ts4_word)lbl_88041618, (ts4_word)(ts4_word)lbl_88CDAFE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D648, (ts4_word)6, (ts4_word)(ts4_word)lbl_8805C258, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A43FF8: call_seq lbl_88B8D6D8, lbl_880415F8, lbl_88CDB2E4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D6D8_88A43FF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB2E4, (ts4_word)(ts4_word)lbl_880415F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D6D8, (ts4_word)14, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A44068: call_seq lbl_8805C27C, lbl_88B8D828, lbl_88CDAFE4, lbl_88040228, lbl_88CDB314, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805C27C_88A44068(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB314, (ts4_word)(ts4_word)lbl_88040228, (ts4_word)(ts4_word)lbl_88CDAFE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D828, (ts4_word)8, (ts4_word)(ts4_word)lbl_8805C27C, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A440E0: call_seq lbl_88B8D8E8, lbl_88CDAFE4, lbl_880415D4, lbl_88CDB344, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D8E8_88A440E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB344, (ts4_word)(ts4_word)lbl_880415D4, (ts4_word)(ts4_word)lbl_88CDAFE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D8E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A44158: call_seq lbl_88B8D900, lbl_88CDB134, lbl_880411DC, lbl_88CDB374, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D900_88A44158(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB374, (ts4_word)(ts4_word)lbl_880411DC, (ts4_word)(ts4_word)lbl_88CDB134, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D900, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A441D0: call_seq lbl_88B8D990, lbl_88CDAFE4, lbl_8805704C, lbl_88CDB3A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D990_88A441D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB3A4, (ts4_word)(ts4_word)lbl_8805704C, (ts4_word)(ts4_word)lbl_88CDAFE4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8D990, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A44248: call_seq lbl_88B8D9AC, lbl_88CDB644, lbl_8804116C, lbl_88CDB3D4, lbl_8805C2C4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8D9AC_88A44248(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDB3D4, (ts4_word)(ts4_word)lbl_8804116C, (ts4_word)(ts4_word)lbl_88CDB644, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805C2C4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B8D9AC, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88AFF008: tailcall fn_8817C008 */
ts4_word ts4_tailcall_fn_8817C008_88AFF008(ts4_word a0)
{
    return fn_8817C008((ts4_word)a0);
}

/* Swing_DLL.xex 0x88AFF040: get u32@lbl_88D4BD54, fn_88198F20 */
ts4_word ts4_get_u32_lbl_88D4BD54_88AFF040(void)
{
    return fn_88198F20((ts4_word)(*(ts4_word *)lbl_88D4BD54));
}

/* Swing_DLL.xex 0x88AFF050: addr lbl_88D49884, fn_8818A360 */
ts4_word ts4_addr_lbl_88D49884_88AFF050(void)
{
    return fn_8818A360((ts4_word)(ts4_word)lbl_88D49884);
}

/* Swing_DLL.xex 0x88AFF0B0: get u32@lbl_88D493C8, fn_88199E90 */
ts4_word ts4_get_u32_lbl_88D493C8_88AFF0B0(void)
{
    return fn_88199E90((ts4_word)(*(ts4_word *)lbl_88D493C8));
}

/* Swing_DLL.xex 0x88AFF0C8: get u32@lbl_88D48854, ts4_destroy_owned_object */
ts4_word ts4_get_u32_lbl_88D48854_88AFF0C8(void)
{
    return ts4_destroy_owned_object((ts4_word)(*(ts4_word *)lbl_88D48854));
}

/* Swing_DLL.xex 0x88AFF0D8: call_seq lbl_88C6C278, u32@0x4, fn_8818A530, u32@0x4, u32@lbl_88C6C278 */
ts4_word ts4_call_seq_lbl_88C6C278_88AFF0D8(void)
{
    ts4_word t2;

    t2 = fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C278) + 4)));
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C278) + 4) = (ts4_word)0;
    *(ts4_word *)lbl_88C6C278 = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x88AFF128: call_seq lbl_88C6C28C, u32@0x4, fn_8818A530, u32@0x4, u32@lbl_88C6C28C */
ts4_word ts4_call_seq_lbl_88C6C28C_88AFF128(void)
{
    ts4_word t2;

    t2 = fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C28C) + 4)));
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C28C) + 4) = (ts4_word)0;
    *(ts4_word *)lbl_88C6C28C = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x88AFF178: call_seq lbl_88C6C2A0, u32@0x4, fn_8818A530, u32@0x4, u32@lbl_88C6C2A0 */
ts4_word ts4_call_seq_lbl_88C6C2A0_88AFF178(void)
{
    ts4_word t2;

    t2 = fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C2A0) + 4)));
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C2A0) + 4) = (ts4_word)0;
    *(ts4_word *)lbl_88C6C2A0 = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x88AFF1C8: call_seq lbl_88C6C2C4, u32@0x4, fn_8818A530, u32@0x4, u32@lbl_88C6C2C4 */
ts4_word ts4_call_seq_lbl_88C6C2C4_88AFF1C8(void)
{
    ts4_word t2;

    t2 = fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C2C4) + 4)));
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C2C4) + 4) = (ts4_word)0;
    *(ts4_word *)lbl_88C6C2C4 = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x88AFF218: call_seq lbl_88C6C300, u32@0x4, fn_8818A530, u32@0x4, u32@lbl_88C6C300 */
ts4_word ts4_call_seq_lbl_88C6C300_88AFF218(void)
{
    ts4_word t2;

    t2 = fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C300) + 4)));
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C300) + 4) = (ts4_word)0;
    *(ts4_word *)lbl_88C6C300 = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x88AFF2B8: addr lbl_88C6C3E8, fn_88617D28 */
ts4_word ts4_addr_lbl_88C6C3E8_88AFF2B8(void)
{
    return fn_88617D28((ts4_word)(ts4_word)lbl_88C6C3E8);
}

/* Swing_DLL.xex 0x88AFF2D0: addr lbl_88C6C6AC, lbl_880F799C, u32@0x8 */
void ts4_addr_lbl_88C6C6AC_88AFF2D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C6AC) + 8) = (ts4_word)(ts4_word)lbl_880F799C;
    return;
}

/* Swing_DLL.xex 0x88AFF390: addr lbl_880D19F0, u32@lbl_88C6CD9C */
void ts4_addr_lbl_880D19F0_88AFF390(void)
{
    *(ts4_word *)lbl_88C6CD9C = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88AFF3D0: tailcall fn_88224B38 */
ts4_word ts4_tailcall_fn_88224B38_88AFF3D0(ts4_word a0)
{
    return fn_88224B38((ts4_word)a0);
}

/* Swing_DLL.xex 0x88AFF3E0: addr lbl_880D19F0, u32@lbl_88D498D4 */
void ts4_addr_lbl_880D19F0_88AFF3E0(void)
{
    *(ts4_word *)lbl_88D498D4 = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88AFF3F8: addr lbl_880D19F0, u32@lbl_88D498CC */
void ts4_addr_lbl_880D19F0_88AFF3F8(void)
{
    *(ts4_word *)lbl_88D498CC = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88AFF410: addr lbl_880D19F0, u32@lbl_88D498C4 */
void ts4_addr_lbl_880D19F0_88AFF410(void)
{
    *(ts4_word *)lbl_88D498C4 = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88AFF428: addr lbl_880D19F0, u32@lbl_88D498BC */
void ts4_addr_lbl_880D19F0_88AFF428(void)
{
    *(ts4_word *)lbl_88D498BC = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88AFF440: addr lbl_88000A3C, u32@lbl_88B30F80 */
void ts4_addr_lbl_88000A3C_88AFF440(void)
{
    *(ts4_word *)lbl_88B30F80 = (ts4_word)(ts4_word)lbl_88000A3C;
    return;
}

/* Swing_DLL.xex 0x88AFF458: call_seq lbl_88C6E268, lbl_88028D18, u32@lbl_88C6E268, ts4_addr_lbl_880292C8_8832E758, lbl_88028B5C, lbl_880C1320 */
ts4_word ts4_call_seq_lbl_88C6E268_88AFF458(void)
{
    ts4_word t2;

    *(ts4_word *)lbl_88C6E268 = (ts4_word)(ts4_word)lbl_88028D18;
    ts4_addr_lbl_880292C8_8832E758((ts4_word)((ts4_word)lbl_88C6E268 + 24572));
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6E268) + 23080) = (ts4_word)(ts4_word)lbl_88028B5C;
    t2 = fn_88316460((ts4_word)((ts4_word)lbl_88C6E268 + 21952), (ts4_word)(ts4_word)lbl_880C1320, (ts4_word)0);
    return t2;
}

/* Swing_DLL.xex 0x88AFF4B8: addr lbl_88C74928, ts4_forward_883165A0 */
ts4_word ts4_addr_lbl_88C74928_88AFF4B8(void)
{
    return ts4_forward_883165A0((ts4_word)(ts4_word)lbl_88C74928);
}

/* Swing_DLL.xex 0x88AFF4C8: get u32@lbl_88CACF08, KeTlsFree */
ts4_word ts4_get_u32_lbl_88CACF08_88AFF4C8(void)
{
    return KeTlsFree((ts4_word)(*(ts4_word *)lbl_88CACF08));
}

/* Swing_DLL.xex 0x88AFF4D8: get u32@lbl_88CAD338, KeTlsFree */
ts4_word ts4_get_u32_lbl_88CAD338_88AFF4D8(void)
{
    return KeTlsFree((ts4_word)(*(ts4_word *)lbl_88CAD338));
}

/* Swing_DLL.xex 0x88AFF4E8: addr lbl_8803A308, u32@lbl_88CB006C */
void ts4_addr_lbl_8803A308_88AFF4E8(void)
{
    *(ts4_word *)lbl_88CB006C = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF500: addr lbl_8803A308, u32@lbl_88CB2C04 */
void ts4_addr_lbl_8803A308_88AFF500(void)
{
    *(ts4_word *)lbl_88CB2C04 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF518: addr lbl_8803A308, u32@lbl_88CB5BBC */
void ts4_addr_lbl_8803A308_88AFF518(void)
{
    *(ts4_word *)lbl_88CB5BBC = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF530: addr lbl_8803A308, u32@lbl_88CB8F04 */
void ts4_addr_lbl_8803A308_88AFF530(void)
{
    *(ts4_word *)lbl_88CB8F04 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF548: addr lbl_8803A308, u32@lbl_88CBC27C */
void ts4_addr_lbl_8803A308_88AFF548(void)
{
    *(ts4_word *)lbl_88CBC27C = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF560: addr lbl_8803A308, u32@lbl_88CBF624 */
void ts4_addr_lbl_8803A308_88AFF560(void)
{
    *(ts4_word *)lbl_88CBF624 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF578: addr lbl_8803A308, u32@lbl_88CC29CC */
void ts4_addr_lbl_8803A308_88AFF578(void)
{
    *(ts4_word *)lbl_88CC29CC = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF590: addr lbl_8803A308, u32@lbl_88CC6554 */
void ts4_addr_lbl_8803A308_88AFF590(void)
{
    *(ts4_word *)lbl_88CC6554 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF5A8: addr lbl_8803A308, u32@lbl_88CCA55C */
void ts4_addr_lbl_8803A308_88AFF5A8(void)
{
    *(ts4_word *)lbl_88CCA55C = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF5C0: addr lbl_8803A308, u32@lbl_88CCE534 */
void ts4_addr_lbl_8803A308_88AFF5C0(void)
{
    *(ts4_word *)lbl_88CCE534 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF5D8: addr lbl_8803A308, u32@lbl_88CD262C */
void ts4_addr_lbl_8803A308_88AFF5D8(void)
{
    *(ts4_word *)lbl_88CD262C = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF5F0: addr lbl_8803A308, u32@lbl_88CD6724 */
void ts4_addr_lbl_8803A308_88AFF5F0(void)
{
    *(ts4_word *)lbl_88CD6724 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF608: addr lbl_8803A308, u32@lbl_88CDA96C */
void ts4_addr_lbl_8803A308_88AFF608(void)
{
    *(ts4_word *)lbl_88CDA96C = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF620: addr lbl_8803A308, u32@lbl_88CDEBB4 */
void ts4_addr_lbl_8803A308_88AFF620(void)
{
    *(ts4_word *)lbl_88CDEBB4 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF638: addr lbl_8803A308, u32@lbl_88CE375C */
void ts4_addr_lbl_8803A308_88AFF638(void)
{
    *(ts4_word *)lbl_88CE375C = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF650: addr lbl_8803A308, u32@lbl_88CE8304 */
void ts4_addr_lbl_8803A308_88AFF650(void)
{
    *(ts4_word *)lbl_88CE8304 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF668: addr lbl_8803A308, u32@lbl_88CED47C */
void ts4_addr_lbl_8803A308_88AFF668(void)
{
    *(ts4_word *)lbl_88CED47C = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF680: addr lbl_8803A308, u32@lbl_88CF2564 */
void ts4_addr_lbl_8803A308_88AFF680(void)
{
    *(ts4_word *)lbl_88CF2564 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF698: addr lbl_8803A308, u32@lbl_88CF785C */
void ts4_addr_lbl_8803A308_88AFF698(void)
{
    *(ts4_word *)lbl_88CF785C = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF6B0: addr lbl_8803A308, u32@lbl_88CFCB54 */
void ts4_addr_lbl_8803A308_88AFF6B0(void)
{
    *(ts4_word *)lbl_88CFCB54 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF6C8: addr lbl_8803A308, u32@lbl_88D01E4C */
void ts4_addr_lbl_8803A308_88AFF6C8(void)
{
    *(ts4_word *)lbl_88D01E4C = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF6E0: addr lbl_8803A308, u32@lbl_88D07144 */
void ts4_addr_lbl_8803A308_88AFF6E0(void)
{
    *(ts4_word *)lbl_88D07144 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF6F8: addr lbl_8803A308, u32@lbl_88D0CA0C */
void ts4_addr_lbl_8803A308_88AFF6F8(void)
{
    *(ts4_word *)lbl_88D0CA0C = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF710: addr lbl_8803A308, u32@lbl_88D122D4 */
void ts4_addr_lbl_8803A308_88AFF710(void)
{
    *(ts4_word *)lbl_88D122D4 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF728: addr lbl_8803A308, u32@lbl_88D17C2C */
void ts4_addr_lbl_8803A308_88AFF728(void)
{
    *(ts4_word *)lbl_88D17C2C = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF740: addr lbl_8803A308, u32@lbl_88D1D704 */
void ts4_addr_lbl_8803A308_88AFF740(void)
{
    *(ts4_word *)lbl_88D1D704 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF758: addr lbl_8803A308, u32@lbl_88D2320C */
void ts4_addr_lbl_8803A308_88AFF758(void)
{
    *(ts4_word *)lbl_88D2320C = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF770: addr lbl_8803A308, u32@lbl_88C2289C */
void ts4_addr_lbl_8803A308_88AFF770(void)
{
    *(ts4_word *)lbl_88C2289C = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF788: addr lbl_8803A308, u32@lbl_88C24200 */
void ts4_addr_lbl_8803A308_88AFF788(void)
{
    *(ts4_word *)lbl_88C24200 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF7A0: addr lbl_8803A308, u32@lbl_88D26F88 */
void ts4_addr_lbl_8803A308_88AFF7A0(void)
{
    *(ts4_word *)lbl_88D26F88 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF7B8: addr lbl_8803A308, u32@lbl_88D26FB0 */
void ts4_addr_lbl_8803A308_88AFF7B8(void)
{
    *(ts4_word *)lbl_88D26FB0 = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88AFF7D0: addr lbl_88D2E270, ts4_if_call_seq_u32_off18_885018B0 */
ts4_word ts4_addr_lbl_88D2E270_88AFF7D0(void)
{
    return ts4_if_call_seq_u32_off18_885018B0((ts4_word)(ts4_word)lbl_88D2E270);
}

/* Swing_DLL.xex 0x88AFF7E0: get u32@lbl_88D3CB08, KeTlsFree */
ts4_word ts4_get_u32_lbl_88D3CB08_88AFF7E0(void)
{
    return KeTlsFree((ts4_word)(*(ts4_word *)lbl_88D3CB08));
}

/* Swing_DLL.xex 0x88AFF7F0: addr lbl_88D3CB10, fn_88472748 */
ts4_word ts4_addr_lbl_88D3CB10_88AFF7F0(void)
{
    return fn_88472748((ts4_word)((ts4_word)lbl_88D3CB10 + 40));
}
