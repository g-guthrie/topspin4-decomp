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

extern char lbl_8803EF90[];
extern char lbl_8803EF9C[];
extern char lbl_8803EFA8[];
extern char lbl_8803EFD0[];
extern char lbl_8803EFE8[];
extern char lbl_8803F00C[];
extern char lbl_8803F030[];
extern char lbl_8803F048[];
extern char lbl_8803F084[];
extern char lbl_8803F094[];
extern char lbl_8803F0AC[];
extern char lbl_8803F0C8[];
extern char lbl_8803F5D4[];
extern char lbl_8803F5F4[];
extern char lbl_8803F64C[];
extern char lbl_8803F660[];
extern char lbl_8803F690[];
extern char lbl_8803F6B0[];
extern char lbl_8803F6CC[];
extern char lbl_8803F6D8[];
extern char lbl_8803F9D4[];
extern char lbl_8803F9E8[];
extern char lbl_8803FA04[];
extern char lbl_8803FA18[];
extern char lbl_8803FBE0[];
extern char lbl_8803FC48[];
extern char lbl_8803FC6C[];
extern char lbl_8803FC80[];
extern char lbl_8803FCA0[];
extern char lbl_880400A8[];
extern char lbl_880400BC[];
extern char lbl_880400D0[];
extern char lbl_880400E8[];
extern char lbl_88040100[];
extern char lbl_88040110[];
extern char lbl_8804011C[];
extern char lbl_880402A0[];
extern char lbl_880402B0[];
extern char lbl_880402BC[];
extern char lbl_880402CC[];
extern char lbl_880402E4[];
extern char lbl_88040300[];
extern char lbl_88040318[];
extern char lbl_8804032C[];
extern char lbl_88040344[];
extern char lbl_88040364[];
extern char lbl_88040380[];
extern char lbl_88040394[];
extern char lbl_880403AC[];
extern char lbl_880403C4[];
extern char lbl_880403DC[];
extern char lbl_88040658[];
extern char lbl_88040668[];
extern char lbl_88040DB0[];
extern char lbl_88040E04[];
extern char lbl_88040E18[];
extern char lbl_88040E68[];
extern char lbl_88041284[];
extern char lbl_88041AFC[];
extern char lbl_88041B0C[];
extern char lbl_88041B24[];
extern char lbl_88041DE0[];
extern char lbl_8804215C[];
extern char lbl_88042170[];
extern char lbl_88042184[];
extern char lbl_880421A0[];
extern char lbl_880421C4[];
extern char lbl_880421E0[];
extern char lbl_88042200[];
extern char lbl_8804221C[];
extern char lbl_8804223C[];
extern char lbl_88042260[];
extern char lbl_88042284[];
extern char lbl_8804229C[];
extern char lbl_880422B8[];
extern char lbl_880422DC[];
extern char lbl_880422F8[];
extern char lbl_88042318[];
extern char lbl_8804232C[];
extern char lbl_8804234C[];
extern char lbl_88042358[];
extern char lbl_88042370[];
extern char lbl_88042380[];
extern char lbl_88042390[];
extern char lbl_880423A4[];
extern char lbl_880423C0[];
extern char lbl_880423D4[];
extern char lbl_88042E20[];
extern char lbl_88043ED0[];
extern char lbl_88043EE0[];
extern char lbl_88044438[];
extern char lbl_88044524[];
extern char lbl_88044680[];
extern char lbl_88044700[];
extern char lbl_880448C8[];
extern char lbl_880448FC[];
extern char lbl_88044924[];
extern char lbl_8804494C[];
extern char lbl_88044A08[];
extern char lbl_88044A58[];
extern char lbl_88044A90[];
extern char lbl_88044ACC[];
extern char lbl_88044B0C[];
extern char lbl_88044B54[];
extern char lbl_88044B94[];
extern char lbl_88044BD4[];
extern char lbl_88044C08[];
extern char lbl_88044C48[];
extern char lbl_88044C84[];
extern char lbl_88044CD0[];
extern char lbl_88044CFC[];
extern char lbl_88044D60[];
extern char lbl_88044D8C[];
extern char lbl_88044DD0[];
extern char lbl_88044DF8[];
extern char lbl_88044E30[];
extern char lbl_88044E64[];
extern char lbl_88044EA8[];
extern char lbl_88044F10[];
extern char lbl_88044F38[];
extern char lbl_88044F90[];
extern char lbl_88045020[];
extern char lbl_88045070[];
extern char lbl_88045194[];
extern char lbl_88045224[];
extern char lbl_880453D8[];
extern char lbl_88045580[];
extern char lbl_880455E0[];
extern char lbl_880456EC[];
extern char lbl_88045734[];
extern char lbl_880457FC[];
extern char lbl_88045860[];
extern char lbl_8804589C[];
extern char lbl_88045914[];
extern char lbl_880459C0[];
extern char lbl_880459F8[];
extern char lbl_88045A30[];
extern char lbl_88045A70[];
extern char lbl_88045AA8[];
extern char lbl_88045AFC[];
extern char lbl_88045B24[];
extern char lbl_88045B44[];
extern char lbl_88045B88[];
extern char lbl_88045BCC[];
extern char lbl_88045C08[];
extern char lbl_88045C4C[];
extern char lbl_88045D00[];
extern char lbl_88045D4C[];
extern char lbl_88045D94[];
extern char lbl_88045DD8[];
extern char lbl_88045E10[];
extern char lbl_88045E48[];
extern char lbl_88045E90[];
extern char lbl_88045F18[];
extern char lbl_88045F4C[];
extern char lbl_88045F84[];
extern char lbl_88045FC0[];
extern char lbl_88045FF4[];
extern char lbl_88046098[];
extern char lbl_880460D0[];
extern char lbl_88046108[];
extern char lbl_88046144[];
extern char lbl_88046178[];
extern char lbl_880461A4[];
extern char lbl_88046220[];
extern char lbl_880462E8[];
extern char lbl_88046320[];
extern char lbl_880463D4[];
extern char lbl_88046498[];
extern char lbl_88046518[];
extern char lbl_88046574[];
extern char lbl_88046678[];
extern char lbl_880466D4[];
extern char lbl_8804671C[];
extern char lbl_8804675C[];
extern char lbl_880467DC[];
extern char lbl_88046868[];
extern char lbl_880468C8[];
extern char lbl_8804690C[];
extern char lbl_8804694C[];
extern char lbl_8804696C[];
extern char lbl_88046994[];
extern char lbl_88046A18[];
extern char lbl_88046A50[];
extern char lbl_88046A84[];
extern char lbl_88046AB4[];
extern char lbl_88046AE0[];
extern char lbl_88047050[];
extern char lbl_8804705C[];
extern char lbl_88047070[];
extern char lbl_8804707C[];
extern char lbl_88057B58[];
extern char lbl_88057C04[];
extern char lbl_88057D28[];
extern char lbl_88057D50[];
extern char lbl_88057D68[];
extern char lbl_88057DF0[];
extern char lbl_88057EA8[];
extern char lbl_88057F04[];
extern char lbl_88057F48[];
extern char lbl_88057F74[];
extern char lbl_88057FB0[];
extern char lbl_88057FD4[];
extern char lbl_88058008[];
extern char lbl_88058034[];
extern char lbl_88058048[];
extern char lbl_880580A4[];
extern char lbl_880580B8[];
extern char lbl_8805811C[];
extern char lbl_88058180[];
extern char lbl_88058194[];
extern char lbl_88058390[];
extern char lbl_880583BC[];
extern char lbl_880583E8[];
extern char lbl_88058414[];
extern char lbl_88058428[];
extern char lbl_88B792A8[];
extern char lbl_88B792D8[];
extern char lbl_88B792F0[];
extern char lbl_88B79308[];
extern char lbl_88B79320[];
extern char lbl_88B79380[];
extern char lbl_88B79398[];
extern char lbl_88B793C8[];
extern char lbl_88B793E0[];
extern char lbl_88B79410[];
extern char lbl_88B79428[];
extern char lbl_88B79440[];
extern char lbl_88B79458[];
extern char lbl_88B794A0[];
extern char lbl_88B794D0[];
extern char lbl_88B79500[];
extern char lbl_88B79548[];
extern char lbl_88B795C4[];
extern char lbl_88B79658[];
extern char lbl_88B79688[];
extern char lbl_88B796A0[];
extern char lbl_88B796BC[];
extern char lbl_88B796C0[];
extern char lbl_88B79738[];
extern char lbl_88B79750[];
extern char lbl_88B79780[];
extern char lbl_88B797B0[];
extern char lbl_88B797E0[];
extern char lbl_88B79828[];
extern char lbl_88B798D0[];
extern char lbl_88B79918[];
extern char lbl_88B79978[];
extern char lbl_88B79A08[];
extern char lbl_88B79A20[];
extern char lbl_88B79A50[];
extern char lbl_88B79A98[];
extern char lbl_88B79AE0[];
extern char lbl_88B79AF8[];
extern char lbl_88B79B2C[];
extern char lbl_88B79B5C[];
extern char lbl_88B79B74[];
extern char lbl_88B79B8C[];
extern char lbl_88B79BBC[];
extern char lbl_88B79BEC[];
extern char lbl_88B79C1C[];
extern char lbl_88B79C34[];
extern char lbl_88B79C4C[];
extern char lbl_88B79C50[];
extern char lbl_88B79C98[];
extern char lbl_88B79CE0[];
extern char lbl_88B79CF8[];
extern char lbl_88B79D28[];
extern char lbl_88B79DA0[];
extern char lbl_88B79E30[];
extern char lbl_88B79E90[];
extern char lbl_88B79F38[];
extern char lbl_88B79FB0[];
extern char lbl_88B79FF8[];
extern char lbl_88B7A088[];
extern char lbl_88B7A0E8[];
extern char lbl_88B7A130[];
extern char lbl_88B7A160[];
extern char lbl_88B7A190[];
extern char lbl_88B7A1A8[];
extern char lbl_88B7A208[];
extern char lbl_88B7A220[];
extern char lbl_88B7A250[];
extern char lbl_88B7A268[];
extern char lbl_88B7A26C[];
extern char lbl_88B7A288[];
extern char lbl_88B7A2D0[];
extern char lbl_88B7A2E8[];
extern char lbl_88B7A348[];
extern char lbl_88B7A354[];
extern char lbl_88B7A384[];
extern char lbl_88B7A3A0[];
extern char lbl_88B7A3E8[];
extern char lbl_88B7A404[];
extern char lbl_88B7A408[];
extern char lbl_88B7A498[];
extern char lbl_88B7A4B0[];
extern char lbl_88B7A528[];
extern char lbl_88B7A558[];
extern char lbl_88B7A578[];
extern char lbl_88B7A620[];
extern char lbl_88B7A638[];
extern char lbl_88B7A668[];
extern char lbl_88B7A680[];
extern char lbl_88B7A728[];
extern char lbl_88B7A770[];
extern char lbl_88B7A848[];
extern char lbl_88B7A878[];
extern char lbl_88B7A890[];
extern char lbl_88B7A8C0[];
extern char lbl_88B7A954[];
extern char lbl_88B7A958[];
extern char lbl_88B7A9A0[];
extern char lbl_88B7A9B8[];
extern char lbl_88B7AA48[];
extern char lbl_88B7AB20[];
extern char lbl_88B7AB68[];
extern char lbl_88B7ABE0[];
extern char lbl_88B7AC10[];
extern char lbl_88B7AC88[];
extern char lbl_88B7ACD0[];
extern char lbl_88B7AD00[];
extern char lbl_88B7AD60[];
extern char lbl_88B7AD90[];
extern char lbl_88B7ADD8[];
extern char lbl_88B7AE08[];
extern char lbl_88B7AE20[];
extern char lbl_88B7AFA4[];
extern char lbl_88B7AFD4[];
extern char lbl_88B7AFD8[];
extern char lbl_88B7B080[];
extern char lbl_88B7B0B0[];
extern char lbl_88B7B0E0[];
extern char lbl_88B7B0F8[];
extern char lbl_88B7B128[];
extern char lbl_88B7B140[];
extern char lbl_88B7B158[];
extern char lbl_88B7B204[];
extern char lbl_88B7B208[];
extern char lbl_88B7B20C[];
extern char lbl_88B7B218[];
extern char lbl_88B7B2A8[];
extern char lbl_88B7B2C0[];
extern char lbl_88B7B2D8[];
extern char lbl_88B7B2F0[];
extern char lbl_88B7B338[];
extern char lbl_88B7B350[];
extern char lbl_88B7B388[];
extern char lbl_88B7B430[];
extern char lbl_88B7B448[];
extern char lbl_88B7B4A8[];
extern char lbl_88B7B4C0[];
extern char lbl_88B7B508[];
extern char lbl_88B7B568[];
extern char lbl_88B7B5C8[];
extern char lbl_88B7B628[];
extern char lbl_88B7B6E8[];
extern char lbl_88B7B8B0[];
extern char lbl_88B7B8C8[];
extern char lbl_88B7B8E0[];
extern char lbl_88B7B910[];
extern char lbl_88B7B940[];
extern char lbl_88B7B958[];
extern char lbl_88B7B988[];
extern char lbl_88B7B9D0[];
extern char lbl_88B7BA18[];
extern char lbl_88B7BAA8[];
extern char lbl_88B7BAF0[];
extern char lbl_88B7BB20[];
extern char lbl_88B7BB50[];
extern char lbl_88B7BB80[];
extern char lbl_88B7BB98[];
extern char lbl_88B7BBB0[];
extern char lbl_88B7BBE0[];
extern char lbl_88B7BBF8[];
extern char lbl_88B7BCE8[];
extern char lbl_88B7BE98[];
extern char lbl_88B7C030[];
extern char lbl_88B7C288[];
extern char lbl_88B7C300[];
extern char lbl_88B7C348[];
extern char lbl_88B7C378[];
extern char lbl_88B7D290[];
extern char lbl_88B7D3C8[];
extern char lbl_88B7D3E0[];
extern char lbl_88B7D488[];
extern char lbl_88B7D4D0[];
extern char lbl_88B7D5A8[];
extern char lbl_88B7D620[];
extern char lbl_88B7D638[];
extern char lbl_88B7D6B0[];
extern char lbl_88CCF20C[];
extern char lbl_88CCFCBC[];
extern char lbl_88CCFD7C[];
extern char lbl_88CCFDAC[];
extern char lbl_88CCFDDC[];
extern char lbl_88CCFE0C[];
extern char lbl_88CCFE3C[];
extern char lbl_88CCFE6C[];
extern char lbl_88CCFE9C[];
extern char lbl_88CCFECC[];
extern char lbl_88CCFEFC[];
extern char lbl_88CCFF2C[];
extern char lbl_88CCFF5C[];
extern char lbl_88CCFF8C[];
extern char lbl_88CCFFBC[];
extern char lbl_88CCFFEC[];
extern char lbl_88CD001C[];
extern char lbl_88CD004C[];
extern char lbl_88CD007C[];
extern char lbl_88CD00AC[];
extern char lbl_88CD00DC[];
extern char lbl_88CD010C[];
extern char lbl_88CD013C[];
extern char lbl_88CD016C[];
extern char lbl_88CD01CC[];
extern char lbl_88CD01FC[];
extern char lbl_88CD022C[];
extern char lbl_88CD025C[];
extern char lbl_88CD028C[];
extern char lbl_88CD02BC[];
extern char lbl_88CD02EC[];
extern char lbl_88CD031C[];
extern char lbl_88CD034C[];
extern char lbl_88CD037C[];
extern char lbl_88CD03AC[];
extern char lbl_88CD03DC[];
extern char lbl_88CD040C[];
extern char lbl_88CD043C[];
extern char lbl_88CD046C[];
extern char lbl_88CD049C[];
extern char lbl_88CD04CC[];
extern char lbl_88CD04FC[];
extern char lbl_88CD052C[];
extern char lbl_88CD055C[];
extern char lbl_88CD058C[];
extern char lbl_88CD05BC[];
extern char lbl_88CD05EC[];
extern char lbl_88CD061C[];
extern char lbl_88CD064C[];
extern char lbl_88CD067C[];
extern char lbl_88CD06AC[];
extern char lbl_88CD06DC[];
extern char lbl_88CD070C[];
extern char lbl_88CD073C[];
extern char lbl_88CD076C[];
extern char lbl_88CD079C[];
extern char lbl_88CD07CC[];
extern char lbl_88CD07FC[];
extern char lbl_88CD082C[];
extern char lbl_88CD085C[];
extern char lbl_88CD088C[];
extern char lbl_88CD08BC[];
extern char lbl_88CD08EC[];
extern char lbl_88CD091C[];
extern char lbl_88CD094C[];
extern char lbl_88CD09AC[];
extern char lbl_88CD09DC[];
extern char lbl_88CD0A0C[];
extern char lbl_88CD0A3C[];
extern char lbl_88CD0A6C[];
extern char lbl_88CD0A9C[];
extern char lbl_88CD0ACC[];
extern char lbl_88CD0AFC[];
extern char lbl_88CD0B2C[];
extern char lbl_88CD0B5C[];
extern char lbl_88CD0B8C[];
extern char lbl_88CD0BBC[];
extern char lbl_88CD0BEC[];
extern char lbl_88CD0C1C[];
extern char lbl_88CD0C4C[];
extern char lbl_88CD0C7C[];
extern char lbl_88CD0CAC[];
extern char lbl_88CD0CDC[];
extern char lbl_88CD0D0C[];
extern char lbl_88CD0D3C[];
extern char lbl_88CD0D6C[];
extern char lbl_88CD0D9C[];
extern char lbl_88CD0DCC[];
extern char lbl_88CD0DFC[];
extern char lbl_88CD0E2C[];
extern char lbl_88CD0E5C[];
extern char lbl_88CD0E8C[];
extern char lbl_88CD0EBC[];
extern char lbl_88CD0EEC[];
extern char lbl_88CD0F1C[];
extern char lbl_88CD0F4C[];
extern char lbl_88CD0F7C[];
extern char lbl_88CD0FAC[];
extern char lbl_88CD0FDC[];
extern char lbl_88CD100C[];
extern char lbl_88CD103C[];
extern char lbl_88CD106C[];
extern char lbl_88CD109C[];
extern char lbl_88CD10CC[];
extern char lbl_88CD10FC[];
extern char lbl_88CD112C[];
extern char lbl_88CD115C[];
extern char lbl_88CD118C[];
extern char lbl_88CD11BC[];
extern char lbl_88CD11EC[];
extern char lbl_88CD121C[];
extern char lbl_88CD124C[];
extern char lbl_88CD127C[];
extern char lbl_88CD12AC[];
extern char lbl_88CD12DC[];
extern char lbl_88CD130C[];
extern char lbl_88CD133C[];
extern char lbl_88CD136C[];
extern char lbl_88CD139C[];
extern char lbl_88CD13CC[];
extern char lbl_88CD13FC[];
extern char lbl_88CD142C[];
extern char lbl_88CD145C[];
extern char lbl_88CD148C[];
extern char lbl_88CD14BC[];
extern char lbl_88CD14EC[];
extern char lbl_88CD151C[];
extern char lbl_88CD154C[];
extern char lbl_88CD157C[];
extern char lbl_88CD15AC[];
extern char lbl_88CD15DC[];
extern char lbl_88CD160C[];
extern char lbl_88CD163C[];
extern char lbl_88CD166C[];
extern char lbl_88CD169C[];
extern char lbl_88CD16CC[];
extern char lbl_88CD16FC[];
extern char lbl_88CD172C[];
extern char lbl_88CD175C[];
extern char lbl_88CD178C[];
extern char lbl_88CD17BC[];
extern char lbl_88CD17EC[];
extern char lbl_88CD181C[];
extern char lbl_88CD184C[];
extern char lbl_88CD187C[];
extern char lbl_88CD18AC[];
extern char lbl_88CD18DC[];
extern char lbl_88CD193C[];
extern char lbl_88CD196C[];
extern char lbl_88CD199C[];
extern char lbl_88CD19CC[];
extern char lbl_88CD19FC[];
extern char lbl_88CD1A2C[];
extern char lbl_88CD1A5C[];
extern char lbl_88CD1A8C[];
extern char lbl_88CD1ABC[];
extern char lbl_88CD1AEC[];
extern char lbl_88CD1B1C[];
extern char lbl_88CD1B4C[];
extern char lbl_88CD1B7C[];
extern char lbl_88CD1BAC[];
extern char lbl_88CD1BDC[];
extern char lbl_88CD1C0C[];
extern char lbl_88CD1C3C[];
extern char lbl_88CD1C6C[];
extern char lbl_88CD1C9C[];
extern char lbl_88CD1CCC[];
extern char lbl_88CD1CFC[];
extern char lbl_88CD1D2C[];
extern char lbl_88CD1D5C[];
extern char lbl_88CD1D8C[];
extern char lbl_88CD1DBC[];
extern char lbl_88CD1DEC[];
extern char lbl_88CD1E1C[];
extern char lbl_88CD1E4C[];
extern char lbl_88CD1E7C[];
extern char lbl_88CD1EAC[];
extern char lbl_88CD1EDC[];
extern char lbl_88CD1F0C[];
extern char lbl_88CD1F3C[];
extern char lbl_88CD1F6C[];
extern char lbl_88CD1F9C[];
extern char lbl_88CD1FCC[];
extern char lbl_88CD1FFC[];
extern char lbl_88CD202C[];
extern char lbl_88CD205C[];
extern char lbl_88CD208C[];
extern char lbl_88CD20BC[];
extern char lbl_88CD20EC[];
extern char lbl_88CD211C[];
extern char lbl_88CD214C[];
extern char lbl_88CD217C[];
extern char lbl_88CD21AC[];
ts4_word fn_8841F080();

/* Swing_DLL.xex 0x88A286C0: call_seq lbl_88CCF20C, lbl_88042318, lbl_88CCFD7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCF20C_88A286C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFD7C, (ts4_word)(ts4_word)lbl_88042318, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28728: call_seq lbl_88046A84, lbl_88CCFDAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A84_88A28728(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFDAC, (ts4_word)(ts4_word)lbl_88046A84, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28788: call_seq lbl_88B792A8, lbl_88CCFD7C, lbl_8804232C, lbl_88CCFDDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B792A8_88A28788(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFDDC, (ts4_word)(ts4_word)lbl_8804232C, (ts4_word)(ts4_word)lbl_88CCFD7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B792A8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28800: call_seq lbl_88B792D8, lbl_88CCFD7C, lbl_8804690C, lbl_88CCFE0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B792D8_88A28800(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFE0C, (ts4_word)(ts4_word)lbl_8804690C, (ts4_word)(ts4_word)lbl_88CCFD7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B792D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28878: call_seq lbl_88CCFD7C, lbl_8804671C, lbl_88CCFE3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCFD7C_88A28878(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFE3C, (ts4_word)(ts4_word)lbl_8804671C, (ts4_word)(ts4_word)lbl_88CCFD7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A288E0: call_seq lbl_88046A50, lbl_88CCFE6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046A50_88A288E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFE6C, (ts4_word)(ts4_word)lbl_88046A50, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28940: call_seq lbl_88B792F0, lbl_88CCF20C, lbl_88041284, lbl_88CCFE9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B792F0_88A28940(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFE9C, (ts4_word)(ts4_word)lbl_88041284, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B792F0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A289B8: call_seq lbl_88046994, lbl_88CCFECC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046994_88A289B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFECC, (ts4_word)(ts4_word)lbl_88046994, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28A18: call_seq lbl_88B79308, lbl_88CCFECC, lbl_88046678, lbl_88CCFEFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79308_88A28A18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFEFC, (ts4_word)(ts4_word)lbl_88046678, (ts4_word)(ts4_word)lbl_88CCFECC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79308, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28A90: call_seq lbl_88B79320, lbl_88046220, lbl_88CCFF2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79320_88A28A90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFF2C, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79320, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28B00: call_seq lbl_88B79380, lbl_88CD004C, lbl_8804694C, lbl_88CCFF5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79380_88A28B00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFF5C, (ts4_word)(ts4_word)lbl_8804694C, (ts4_word)(ts4_word)lbl_88CD004C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79380, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28B78: call_seq lbl_88B79398, lbl_88CCFE9C, lbl_88040110, lbl_88CCFF8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79398_88A28B78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFF8C, (ts4_word)(ts4_word)lbl_88040110, (ts4_word)(ts4_word)lbl_88CCFE9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79398, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28BF0: call_seq lbl_88B793C8, lbl_88CCFE9C, lbl_88040100, lbl_88CCFFBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B793C8_88A28BF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFFBC, (ts4_word)(ts4_word)lbl_88040100, (ts4_word)(ts4_word)lbl_88CCFE9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B793C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28C68: call_seq lbl_88B793E0, lbl_88CD004C, lbl_8804011C, lbl_88CCFFEC, lbl_88057B58, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B793E0_88A28C68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CCFFEC, (ts4_word)(ts4_word)lbl_8804011C, (ts4_word)(ts4_word)lbl_88CD004C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057B58, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B793E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28CE0: call_seq lbl_88B79410, lbl_88CCFE9C, lbl_880400A8, lbl_88CD001C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79410_88A28CE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD001C, (ts4_word)(ts4_word)lbl_880400A8, (ts4_word)(ts4_word)lbl_88CCFE9C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79410, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28D58: call_seq lbl_88B79428, lbl_88CD04FC, lbl_88042370, lbl_88CD004C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79428_88A28D58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD004C, (ts4_word)(ts4_word)lbl_88042370, (ts4_word)(ts4_word)lbl_88CD04FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79428, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28DD0: call_seq lbl_88B79440, lbl_88CD025C, lbl_88041B24, lbl_88CD007C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79440_88A28DD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD007C, (ts4_word)(ts4_word)lbl_88041B24, (ts4_word)(ts4_word)lbl_88CD025C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79440, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28E48: call_seq lbl_88B79458, lbl_88CD001C, lbl_880468C8, lbl_88CD00AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79458_88A28E48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD00AC, (ts4_word)(ts4_word)lbl_880468C8, (ts4_word)(ts4_word)lbl_88CD001C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79458, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28EC0: call_seq lbl_88B794A0, lbl_88CD004C, lbl_880400E8, lbl_88CD00DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B794A0_88A28EC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD00DC, (ts4_word)(ts4_word)lbl_880400E8, (ts4_word)(ts4_word)lbl_88CD004C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B794A0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28F38: call_seq lbl_88B794D0, lbl_88CD004C, lbl_880400D0, lbl_88CD010C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B794D0_88A28F38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD010C, (ts4_word)(ts4_word)lbl_880400D0, (ts4_word)(ts4_word)lbl_88CD004C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B794D0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A28FB0: call_seq lbl_88B79500, lbl_880463D4, lbl_88CD013C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79500_88A28FB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD013C, (ts4_word)(ts4_word)lbl_880463D4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79500, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29020: call_seq lbl_88B79548, lbl_88CD004C, lbl_88046868, lbl_88CD016C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79548_88A29020(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD016C, (ts4_word)(ts4_word)lbl_88046868, (ts4_word)(ts4_word)lbl_88CD004C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79548, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29110: call_seq lbl_88CD02EC, lbl_880467DC, lbl_88CD01CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD02EC_88A29110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD01CC, (ts4_word)(ts4_word)lbl_880467DC, (ts4_word)(ts4_word)lbl_88CD02EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29178: call_seq lbl_88CCFE9C, lbl_88046AE0, lbl_88CD01FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCFE9C_88A29178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD01FC, (ts4_word)(ts4_word)lbl_88046AE0, (ts4_word)(ts4_word)lbl_88CCFE9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A291E0: call_seq lbl_88B79658, lbl_88042358, lbl_88CD022C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79658_88A291E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD022C, (ts4_word)(ts4_word)lbl_88042358, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79658, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29250: call_seq lbl_88B79688, lbl_88CD001C, lbl_8804234C, lbl_88CD025C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79688_88A29250(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD025C, (ts4_word)(ts4_word)lbl_8804234C, (ts4_word)(ts4_word)lbl_88CD001C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79688, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A292C8: call_seq lbl_88B796A0, lbl_88046320, lbl_88CD028C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B796A0_88A292C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD028C, (ts4_word)(ts4_word)lbl_88046320, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B796A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29338: addr lbl_88B7D290, u32@lbl_88B795C4, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B7D290_88A29338(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B795C4;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D290) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D290) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A29358: call_seq lbl_88B7D290, lbl_8803EFE8, lbl_88CD02BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D290_88A29358(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD02BC, (ts4_word)(ts4_word)lbl_8803EFE8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7D290, (ts4_word)13, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A293C8: call_seq lbl_88B796C0, lbl_88CD001C, lbl_8803EF9C, lbl_88CD02EC, lbl_88057C04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B796C0_88A293C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD02EC, (ts4_word)(ts4_word)lbl_8803EF9C, (ts4_word)(ts4_word)lbl_88CD001C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057C04, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B796C0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29440: call_seq lbl_88B79738, lbl_88CCFFBC, lbl_880423C0, lbl_88CD031C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79738_88A29440(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD031C, (ts4_word)(ts4_word)lbl_880423C0, (ts4_word)(ts4_word)lbl_88CCFFBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79738, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A294B8: call_seq lbl_88B79750, lbl_880462E8, lbl_88CD034C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79750_88A294B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD034C, (ts4_word)(ts4_word)lbl_880462E8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79750, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29528: call_seq lbl_88B79780, lbl_88CCFE9C, lbl_8804675C, lbl_88CD037C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79780_88A29528(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD037C, (ts4_word)(ts4_word)lbl_8804675C, (ts4_word)(ts4_word)lbl_88CCFE9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79780, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A295A0: call_seq lbl_88B797B0, lbl_88CD04FC, lbl_8803F9D4, lbl_88CD03AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B797B0_88A295A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD03AC, (ts4_word)(ts4_word)lbl_8803F9D4, (ts4_word)(ts4_word)lbl_88CD04FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B797B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29618: call_seq lbl_88CCFE9C, lbl_88046AB4, lbl_88CD03DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCFE9C_88A29618(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD03DC, (ts4_word)(ts4_word)lbl_88046AB4, (ts4_word)(ts4_word)lbl_88CCFE9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29680: call_seq lbl_88B797E0, lbl_88CD01FC, lbl_880466D4, lbl_88CD040C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B797E0_88A29680(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD040C, (ts4_word)(ts4_word)lbl_880466D4, (ts4_word)(ts4_word)lbl_88CD01FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B797E0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A296F8: call_seq lbl_88B79828, lbl_88CD01FC, lbl_88046A18, lbl_88CD043C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79828_88A296F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD043C, (ts4_word)(ts4_word)lbl_88046A18, (ts4_word)(ts4_word)lbl_88CD01FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79828, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29770: call_seq lbl_88B798D0, lbl_880423A4, lbl_88CD046C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B798D0_88A29770(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD046C, (ts4_word)(ts4_word)lbl_880423A4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B798D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A297E0: call_seq lbl_88B79918, lbl_88CD001C, lbl_88042390, lbl_88CD049C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79918_88A297E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD049C, (ts4_word)(ts4_word)lbl_88042390, (ts4_word)(ts4_word)lbl_88CD001C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79918, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29858: call_seq lbl_88CD004C, lbl_88043ED0, lbl_88CD04CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD004C_88A29858(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD04CC, (ts4_word)(ts4_word)lbl_88043ED0, (ts4_word)(ts4_word)lbl_88CD004C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A298C0: call_seq lbl_88CCFE9C, lbl_8804696C, lbl_88CD04FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCFE9C_88A298C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD04FC, (ts4_word)(ts4_word)lbl_8804696C, (ts4_word)(ts4_word)lbl_88CCFE9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29928: call_seq lbl_88B79978, lbl_88CCF20C, lbl_8803F00C, lbl_88CD052C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79978_88A29928(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD052C, (ts4_word)(ts4_word)lbl_8803F00C, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79978, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A299A0: call_seq lbl_88B79A08, lbl_88CD02EC, lbl_88046574, lbl_88CD055C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79A08_88A299A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD055C, (ts4_word)(ts4_word)lbl_88046574, (ts4_word)(ts4_word)lbl_88CD02EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79A08, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29A18: call_seq lbl_88B79A20, lbl_88CD043C, lbl_88046518, lbl_88CD058C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79A20_88A29A18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD058C, (ts4_word)(ts4_word)lbl_88046518, (ts4_word)(ts4_word)lbl_88CD043C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79A20, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29A90: call_seq lbl_88B79A50, lbl_88CCFE9C, lbl_880400BC, lbl_88CD05BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79A50_88A29A90(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD05BC, (ts4_word)(ts4_word)lbl_880400BC, (ts4_word)(ts4_word)lbl_88CCFE9C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79A50, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29B08: call_seq lbl_88B79A98, lbl_88CD004C, lbl_88042380, lbl_88CD05EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79A98_88A29B08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD05EC, (ts4_word)(ts4_word)lbl_88042380, (ts4_word)(ts4_word)lbl_88CD004C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79A98, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29B80: call_seq lbl_88B79AE0, lbl_88CCFFBC, lbl_880423D4, lbl_88CD061C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79AE0_88A29B80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD061C, (ts4_word)(ts4_word)lbl_880423D4, (ts4_word)(ts4_word)lbl_88CCFFBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79AE0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29BF8: call_seq lbl_88B79AF8, lbl_88CD001C, lbl_88046498, lbl_88CD064C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79AF8_88A29BF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD064C, (ts4_word)(ts4_word)lbl_88046498, (ts4_word)(ts4_word)lbl_88CD001C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79AF8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29C70: addr lbl_88B7D3C8, u32@lbl_88B796BC, u32@0x8 */
void ts4_addr_lbl_88B7D3C8_88A29C70(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D3C8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B796BC);
    return;
}

/* Swing_DLL.xex 0x88A29C88: call_seq lbl_88B7D3C8, lbl_8804215C, lbl_88CD067C, lbl_88057D28, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D3C8_88A29C88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)(ts4_word)lbl_8804215C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057D28, (ts4_word)2, (ts4_word)(ts4_word)lbl_88B7D3C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29CF8: call_seq lbl_88B79B2C, lbl_88CD067C, lbl_88041B0C, lbl_88CD06AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79B2C_88A29CF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD06AC, (ts4_word)(ts4_word)lbl_88041B0C, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79B2C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29D70: call_seq lbl_88B79B5C, lbl_88041AFC, lbl_88CD06DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79B5C_88A29D70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD06DC, (ts4_word)(ts4_word)lbl_88041AFC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79B5C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29DE0: call_seq lbl_88CD067C, lbl_88046098, lbl_88CD070C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD067C_88A29DE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD070C, (ts4_word)(ts4_word)lbl_88046098, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29E48: call_seq lbl_88B79B74, lbl_88CD067C, lbl_88045C08, lbl_88CD073C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79B74_88A29E48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD073C, (ts4_word)(ts4_word)lbl_88045C08, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79B74, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29EC0: call_seq lbl_88B79B8C, lbl_88CD067C, lbl_88045D4C, lbl_88CD076C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79B8C_88A29EC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD076C, (ts4_word)(ts4_word)lbl_88045D4C, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79B8C, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29F38: call_seq lbl_88B79BBC, lbl_88CD067C, lbl_88045D00, lbl_88CD079C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79BBC_88A29F38(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD079C, (ts4_word)(ts4_word)lbl_88045D00, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79BBC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A29FB0: call_seq lbl_88B79BEC, lbl_88CD067C, lbl_88045D94, lbl_88CD07CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79BEC_88A29FB0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD07CC, (ts4_word)(ts4_word)lbl_88045D94, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79BEC, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A028: call_seq lbl_88B79C1C, lbl_88CD067C, lbl_88045E48, lbl_88CD07FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79C1C_88A2A028(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD07FC, (ts4_word)(ts4_word)lbl_88045E48, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79C1C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A0A0: call_seq lbl_88B79C34, lbl_88CD067C, lbl_88045FF4, lbl_88CD082C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79C34_88A2A0A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD082C, (ts4_word)(ts4_word)lbl_88045FF4, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79C34, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A118: call_seq lbl_88B79C50, lbl_88CD067C, lbl_88045F18, lbl_88CD085C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79C50_88A2A118(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD085C, (ts4_word)(ts4_word)lbl_88045F18, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79C50, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A190: call_seq lbl_88B79C98, lbl_88CD067C, lbl_88045F84, lbl_88CD088C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79C98_88A2A190(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD088C, (ts4_word)(ts4_word)lbl_88045F84, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79C98, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A208: call_seq lbl_88B79CE0, lbl_88CD067C, lbl_880461A4, lbl_88CD08BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79CE0_88A2A208(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD08BC, (ts4_word)(ts4_word)lbl_880461A4, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79CE0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A280: call_seq lbl_88B79CF8, lbl_88CD067C, lbl_88046178, lbl_88CD08EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79CF8_88A2A280(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD08EC, (ts4_word)(ts4_word)lbl_88046178, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79CF8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A2F8: call_seq lbl_88057D50, lbl_88B79D28, lbl_88CD067C, lbl_88046108, lbl_88CD091C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88057D50_88A2A2F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD091C, (ts4_word)(ts4_word)lbl_88046108, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79D28, (ts4_word)5, (ts4_word)(ts4_word)lbl_88057D50, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A370: call_seq lbl_88057D68, lbl_88B79DA0, lbl_88CD067C, lbl_88045BCC, lbl_88CD094C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88057D68_88A2A370(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD094C, (ts4_word)(ts4_word)lbl_88045BCC, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79DA0, (ts4_word)6, (ts4_word)(ts4_word)lbl_88057D68, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A3E8: addr lbl_88B7D3E0, u32@lbl_88B79C4C, u32@0x50 */
void ts4_addr_lbl_88B7D3E0_88A2A3E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D3E0) + 80) = (ts4_word)(*(ts4_word *)lbl_88B79C4C);
    return;
}

/* Swing_DLL.xex 0x88A2A478: call_seq lbl_88B79E30, lbl_88CD067C, lbl_88046144, lbl_88CD09AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79E30_88A2A478(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD09AC, (ts4_word)(ts4_word)lbl_88046144, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79E30, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A4F0: call_seq lbl_88B79E90, lbl_88CD067C, lbl_880460D0, lbl_88CD09DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79E90_88A2A4F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD09DC, (ts4_word)(ts4_word)lbl_880460D0, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79E90, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A568: call_seq lbl_88B79F38, lbl_88CD067C, lbl_88045DD8, lbl_88CD0A0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79F38_88A2A568(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0A0C, (ts4_word)(ts4_word)lbl_88045DD8, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79F38, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A5E0: call_seq lbl_88B79FB0, lbl_88CD067C, lbl_88045FC0, lbl_88CD0A3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79FB0_88A2A5E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0A3C, (ts4_word)(ts4_word)lbl_88045FC0, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79FB0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A658: call_seq lbl_88B79FF8, lbl_88CD067C, lbl_88045F4C, lbl_88CD0A6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B79FF8_88A2A658(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0A6C, (ts4_word)(ts4_word)lbl_88045F4C, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B79FF8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A6D0: call_seq lbl_88B7A088, lbl_88CD067C, lbl_88045E10, lbl_88CD0A9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A088_88A2A6D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0A9C, (ts4_word)(ts4_word)lbl_88045E10, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A088, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A748: call_seq lbl_88B7A0E8, lbl_88CD067C, lbl_880422DC, lbl_88CD0ACC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A0E8_88A2A748(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0ACC, (ts4_word)(ts4_word)lbl_880422DC, (ts4_word)(ts4_word)lbl_88CD067C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A0E8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A7C0: call_seq lbl_88B7A130, lbl_88CD0ACC, lbl_88045C4C, lbl_88CD0AFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A130_88A2A7C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0AFC, (ts4_word)(ts4_word)lbl_88045C4C, (ts4_word)(ts4_word)lbl_88CD0ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A130, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A838: call_seq lbl_88B7A160, lbl_88CD0ACC, lbl_88043EE0, lbl_88CD0B2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A160_88A2A838(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0B2C, (ts4_word)(ts4_word)lbl_88043EE0, (ts4_word)(ts4_word)lbl_88CD0ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A160, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A8B0: call_seq lbl_88CD0ACC, lbl_88045B88, lbl_88CD0B5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD0ACC_88A2A8B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0B5C, (ts4_word)(ts4_word)lbl_88045B88, (ts4_word)(ts4_word)lbl_88CD0ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A918: call_seq lbl_88B7A190, lbl_88CD0ACC, lbl_88045E90, lbl_88CD0B8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A190_88A2A918(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0B8C, (ts4_word)(ts4_word)lbl_88045E90, (ts4_word)(ts4_word)lbl_88CD0ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A190, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2A990: call_seq lbl_88B7A1A8, lbl_88CCF20C, lbl_88047050, lbl_88CD0BBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A1A8_88A2A990(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0BBC, (ts4_word)(ts4_word)lbl_88047050, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A1A8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2AA08: call_seq lbl_88B7A208, lbl_88CD0BBC, lbl_88045B44, lbl_88CD0BEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A208_88A2AA08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0BEC, (ts4_word)(ts4_word)lbl_88045B44, (ts4_word)(ts4_word)lbl_88CD0BBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A208, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2AA80: call_seq lbl_88B7A220, lbl_88CD0BBC, lbl_88045B24, lbl_88CD0C1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A220_88A2AA80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0C1C, (ts4_word)(ts4_word)lbl_88045B24, (ts4_word)(ts4_word)lbl_88CD0BBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A220, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2AAF8: call_seq lbl_88B7A250, lbl_88CD0BBC, lbl_880459C0, lbl_88CD0C4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A250_88A2AAF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0C4C, (ts4_word)(ts4_word)lbl_880459C0, (ts4_word)(ts4_word)lbl_88CD0BBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A250, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2AB70: addr lbl_88B7D488, u32@lbl_88B7A268, u32@0x8 */
void ts4_addr_lbl_88B7D488_88A2AB70(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D488) + 8) = (ts4_word)(*(ts4_word *)lbl_88B7A268);
    return;
}

/* Swing_DLL.xex 0x88A2AB88: call_seq lbl_88B7D488, lbl_88045224, lbl_88CD0C7C, lbl_88057DF0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D488_88A2AB88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0C7C, (ts4_word)(ts4_word)lbl_88045224, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057DF0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7D488, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2ABF8: call_seq lbl_88B7A26C, lbl_88045194, lbl_88CD0CAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A26C_88A2ABF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0CAC, (ts4_word)(ts4_word)lbl_88045194, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A26C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2AC68: call_seq lbl_88B7A288, lbl_8803EF90, lbl_88CD0CDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A288_88A2AC68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0CDC, (ts4_word)(ts4_word)lbl_8803EF90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A288, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2ACD8: call_seq lbl_88B7A2D0, lbl_88CCF20C, lbl_8803FA04, lbl_88CD0D0C, lbl_88057EA8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A2D0_88A2ACD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)(ts4_word)lbl_8803FA04, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057EA8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7A2D0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2AD48: call_seq lbl_88B7A2E8, lbl_88042170, lbl_88CD0D3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A2E8_88A2AD48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0D3C, (ts4_word)(ts4_word)lbl_88042170, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A2E8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2ADB8: addr lbl_88B7D4D0, u32@lbl_88B7A348, u32@0x68 */
void ts4_addr_lbl_88B7D4D0_88A2ADB8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D4D0) + 104) = (ts4_word)(*(ts4_word *)lbl_88B7A348);
    return;
}

/* Swing_DLL.xex 0x88A2ADD0: call_seq lbl_88B7D4D0, lbl_88CCF20C, lbl_8803F0C8, lbl_88CD0D6C, lbl_88057F04, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D4D0_88A2ADD0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0D6C, (ts4_word)(ts4_word)lbl_8803F0C8, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057F04, (ts4_word)3, (ts4_word)(ts4_word)lbl_88B7D4D0, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2AE48: call_seq lbl_88B7A354, lbl_880422B8, lbl_88CD0D9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A354_88A2AE48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0D9C, (ts4_word)(ts4_word)lbl_880422B8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A354, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2AEB8: call_seq lbl_88B7A384, lbl_88CD0D0C, lbl_880403DC, lbl_88CD0DCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A384_88A2AEB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0DCC, (ts4_word)(ts4_word)lbl_880403DC, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A384, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2AF30: call_seq lbl_88B7A3A0, lbl_8804229C, lbl_88CD0DFC, lbl_88057F48, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A3A0_88A2AF30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0DFC, (ts4_word)(ts4_word)lbl_8804229C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057F48, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7A3A0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2AFA0: call_seq lbl_88B7A3E8, lbl_88CD0D0C, lbl_88040394, lbl_88CD0E2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A3E8_88A2AFA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0E2C, (ts4_word)(ts4_word)lbl_88040394, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A3E8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B018: call_seq lbl_88B7A408, lbl_88042260, lbl_88CD0E5C, lbl_88057F74, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A408_88A2B018(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0E5C, (ts4_word)(ts4_word)lbl_88042260, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057F74, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7A408, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B088: call_seq lbl_88B7A498, lbl_88CD0D0C, lbl_8803F690, lbl_88CD0E8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A498_88A2B088(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0E8C, (ts4_word)(ts4_word)lbl_8803F690, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A498, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B100: call_seq lbl_88B7A4B0, lbl_88CD0EEC, lbl_88045734, lbl_88CD0EBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A4B0_88A2B100(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0EBC, (ts4_word)(ts4_word)lbl_88045734, (ts4_word)(ts4_word)lbl_88CD0EEC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A4B0, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B178: call_seq lbl_88CCF20C, lbl_88045A30, lbl_88CD0EEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCF20C_88A2B178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0EEC, (ts4_word)(ts4_word)lbl_88045A30, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B1E0: addr lbl_88B7D5A8, u32@lbl_88B7A404, u32@0x50 */
void ts4_addr_lbl_88B7D5A8_88A2B1E0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D5A8) + 80) = (ts4_word)(*(ts4_word *)lbl_88B7A404);
    return;
}

/* Swing_DLL.xex 0x88A2B1F8: call_seq lbl_88B7D5A8, lbl_88CD0D0C, lbl_88040364, lbl_88CD0F1C, lbl_88057FB0, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D5A8_88A2B1F8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0F1C, (ts4_word)(ts4_word)lbl_88040364, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057FB0, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7D5A8, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B270: call_seq lbl_88B7A528, lbl_8804223C, lbl_88CD0F4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A528_88A2B270(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0F4C, (ts4_word)(ts4_word)lbl_8804223C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A528, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B2E0: call_seq lbl_88B7A558, lbl_88CD0D0C, lbl_88040344, lbl_88CD0F7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A558_88A2B2E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0F7C, (ts4_word)(ts4_word)lbl_88040344, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A558, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B358: call_seq lbl_88B7A578, lbl_8804221C, lbl_88CD0FAC, lbl_88057FD4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A578_88A2B358(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0FAC, (ts4_word)(ts4_word)lbl_8804221C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88057FD4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7A578, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B3C8: call_seq lbl_88B7A620, lbl_88CD0D0C, lbl_8803F048, lbl_88CD0FDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A620_88A2B3C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD0FDC, (ts4_word)(ts4_word)lbl_8803F048, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A620, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B440: call_seq lbl_88B7A638, lbl_880421A0, lbl_88CD100C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A638_88A2B440(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD100C, (ts4_word)(ts4_word)lbl_880421A0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A638, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B4B0: call_seq lbl_88B7A668, lbl_88CD0D0C, lbl_880402E4, lbl_88CD103C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A668_88A2B4B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD103C, (ts4_word)(ts4_word)lbl_880402E4, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A668, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B528: call_seq lbl_88B7A680, lbl_88042184, lbl_88CD106C, lbl_88058008, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A680_88A2B528(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD106C, (ts4_word)(ts4_word)lbl_88042184, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88058008, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7A680, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B598: call_seq lbl_88B7A728, lbl_88CD0D0C, lbl_880402CC, lbl_88CD109C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A728_88A2B598(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD109C, (ts4_word)(ts4_word)lbl_880402CC, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A728, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B610: call_seq lbl_88B7A770, lbl_88CD0D0C, lbl_8803F6B0, lbl_88CD10CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A770_88A2B610(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD10CC, (ts4_word)(ts4_word)lbl_8803F6B0, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A770, (ts4_word)9, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B688: call_seq lbl_88CD0D0C, lbl_88045AFC, lbl_88CD10FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD0D0C_88A2B688(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD10FC, (ts4_word)(ts4_word)lbl_88045AFC, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B6F0: call_seq lbl_88B7A848, lbl_88CD0D6C, lbl_8804589C, lbl_88CD112C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A848_88A2B6F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD112C, (ts4_word)(ts4_word)lbl_8804589C, (ts4_word)(ts4_word)lbl_88CD0D6C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A848, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B768: call_seq lbl_88B7A878, lbl_88CD0BBC, lbl_88045860, lbl_88CD115C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A878_88A2B768(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD115C, (ts4_word)(ts4_word)lbl_88045860, (ts4_word)(ts4_word)lbl_88CD0BBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A878, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B7E0: call_seq lbl_88B7A890, lbl_880453D8, lbl_88CD118C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A890_88A2B7E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD118C, (ts4_word)(ts4_word)lbl_880453D8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A890, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B850: call_seq lbl_88B7A8C0, lbl_88CD10FC, lbl_880403C4, lbl_88CD11BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A8C0_88A2B850(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD11BC, (ts4_word)(ts4_word)lbl_880403C4, (ts4_word)(ts4_word)lbl_88CD10FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A8C0, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B8C8: call_seq lbl_88B7A958, lbl_88042284, lbl_88CD11EC, lbl_88058034, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A958_88A2B8C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD11EC, (ts4_word)(ts4_word)lbl_88042284, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88058034, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7A958, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B938: call_seq lbl_88B7A9A0, lbl_88CD0D0C, lbl_88040380, lbl_88CD121C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A9A0_88A2B938(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD121C, (ts4_word)(ts4_word)lbl_88040380, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A9A0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2B9B0: call_seq lbl_88B7A9B8, lbl_8803FC48, lbl_88CD124C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7A9B8_88A2B9B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD124C, (ts4_word)(ts4_word)lbl_8803FC48, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7A9B8, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2BA20: call_seq lbl_88058048, lbl_88B7AA48, lbl_88CD10FC, lbl_8803FC6C, lbl_88CD127C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88058048_88A2BA20(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD127C, (ts4_word)(ts4_word)lbl_8803FC6C, (ts4_word)(ts4_word)lbl_88CD10FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7AA48, (ts4_word)9, (ts4_word)(ts4_word)lbl_88058048, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2BA98: call_seq lbl_88B7AB20, lbl_88045020, lbl_88CD12AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7AB20_88A2BA98(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD12AC, (ts4_word)(ts4_word)lbl_88045020, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7AB20, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2BB08: call_seq lbl_88B7AB68, lbl_88CD10FC, lbl_88040300, lbl_88CD12DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7AB68_88A2BB08(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD12DC, (ts4_word)(ts4_word)lbl_88040300, (ts4_word)(ts4_word)lbl_88CD10FC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7AB68, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2BB80: call_seq lbl_88B7ABE0, lbl_88CD0D0C, lbl_880403AC, lbl_88CD130C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7ABE0_88A2BB80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD130C, (ts4_word)(ts4_word)lbl_880403AC, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7ABE0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2BBF8: call_seq lbl_88B7AC10, lbl_880422F8, lbl_88CD133C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7AC10_88A2BBF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD133C, (ts4_word)(ts4_word)lbl_880422F8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7AC10, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2BC68: call_seq lbl_88B7AC88, lbl_88CD0D0C, lbl_8803FA18, lbl_88CD136C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7AC88_88A2BC68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD136C, (ts4_word)(ts4_word)lbl_8803FA18, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7AC88, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2BCE0: addr lbl_88B7D620, u32@lbl_88B7A954, u32@0x8 */
void ts4_addr_lbl_88B7D620_88A2BCE0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D620) + 8) = (ts4_word)(*(ts4_word *)lbl_88B7A954);
    return;
}

/* Swing_DLL.xex 0x88A2BCF8: call_seq lbl_88B7D620, lbl_88CCF20C, lbl_8803FBE0, lbl_88CD139C, lbl_880580A4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D620_88A2BCF8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD139C, (ts4_word)(ts4_word)lbl_8803FBE0, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880580A4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7D620, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2BD68: call_seq lbl_88B7ACD0, lbl_88CD139C, lbl_88045A70, lbl_88CD13CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7ACD0_88A2BD68(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD13CC, (ts4_word)(ts4_word)lbl_88045A70, (ts4_word)(ts4_word)lbl_88CD139C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7ACD0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2BDE0: call_seq lbl_88B7AD00, lbl_88CD13CC, lbl_8803FCA0, lbl_88CD13FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7AD00_88A2BDE0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD13FC, (ts4_word)(ts4_word)lbl_8803FCA0, (ts4_word)(ts4_word)lbl_88CD13CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7AD00, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2BE58: call_seq lbl_88B7AD60, lbl_88CD13CC, lbl_8803FC80, lbl_88CD142C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7AD60_88A2BE58(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD142C, (ts4_word)(ts4_word)lbl_8803FC80, (ts4_word)(ts4_word)lbl_88CD13CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7AD60, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2BED0: call_seq lbl_88B7AD90, lbl_88CD13CC, lbl_8803F9E8, lbl_88CD145C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7AD90_88A2BED0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD145C, (ts4_word)(ts4_word)lbl_8803F9E8, (ts4_word)(ts4_word)lbl_88CD13CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7AD90, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2BF48: call_seq lbl_88B7ADD8, lbl_88042200, lbl_88CD148C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7ADD8_88A2BF48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD148C, (ts4_word)(ts4_word)lbl_88042200, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7ADD8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2BFB8: call_seq lbl_88B7AE08, lbl_88CD0D0C, lbl_8804032C, lbl_88CD14BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7AE08_88A2BFB8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD14BC, (ts4_word)(ts4_word)lbl_8804032C, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7AE08, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C030: call_seq lbl_880580B8, lbl_88B7AE20, lbl_88CD193C, lbl_8803F6CC, lbl_88CD14EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_880580B8_88A2C030(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD14EC, (ts4_word)(ts4_word)lbl_8803F6CC, (ts4_word)(ts4_word)lbl_88CD193C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7AE20, (ts4_word)16, (ts4_word)(ts4_word)lbl_880580B8, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C0A8: call_seq lbl_88CCF20C, lbl_88045AA8, lbl_88CD151C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCF20C_88A2C0A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD151C, (ts4_word)(ts4_word)lbl_88045AA8, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C110: call_seq lbl_88CD15AC, lbl_880457FC, lbl_88CD154C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD15AC_88A2C110(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD154C, (ts4_word)(ts4_word)lbl_880457FC, (ts4_word)(ts4_word)lbl_88CD15AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C178: call_seq lbl_88CD14EC, lbl_880455E0, lbl_88CD157C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD14EC_88A2C178(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD157C, (ts4_word)(ts4_word)lbl_880455E0, (ts4_word)(ts4_word)lbl_88CD14EC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C1E0: call_seq lbl_8805811C, lbl_88CD151C, lbl_880459F8, lbl_88CD15AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805811C_88A2C1E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD15AC, (ts4_word)(ts4_word)lbl_880459F8, (ts4_word)(ts4_word)lbl_88CD151C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805811C, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C248: call_seq lbl_88B7AFA4, lbl_88045070, lbl_88CD15DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7AFA4_88A2C248(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD15DC, (ts4_word)(ts4_word)lbl_88045070, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7AFA4, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C2B8: call_seq lbl_88B7AFD8, lbl_88CD15AC, lbl_88041DE0, lbl_88CD160C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7AFD8_88A2C2B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD160C, (ts4_word)(ts4_word)lbl_88041DE0, (ts4_word)(ts4_word)lbl_88CD15AC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7AFD8, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C330: addr lbl_88B7D638, u32@lbl_88B7AFD4, u32@0x8 */
void ts4_addr_lbl_88B7D638_88A2C330(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D638) + 8) = (ts4_word)(*(ts4_word *)lbl_88B7AFD4);
    return;
}

/* Swing_DLL.xex 0x88A2C348: call_seq lbl_88B7D638, lbl_88CCF20C, lbl_8803F5D4, lbl_88CD163C, lbl_88058180, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7D638_88A2C348(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD163C, (ts4_word)(ts4_word)lbl_8803F5D4, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88058180, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7D638, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C3C0: call_seq lbl_88CD163C, lbl_880402B0, lbl_88CD166C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD163C_88A2C3C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD166C, (ts4_word)(ts4_word)lbl_880402B0, (ts4_word)(ts4_word)lbl_88CD163C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C428: call_seq lbl_88CD16CC, lbl_88040E04, lbl_88CD169C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD16CC_88A2C428(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD169C, (ts4_word)(ts4_word)lbl_88040E04, (ts4_word)(ts4_word)lbl_88CD16CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C490: call_seq lbl_88B7B080, lbl_88CD163C, lbl_8803EFA8, lbl_88CD16CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B080_88A2C490(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD16CC, (ts4_word)(ts4_word)lbl_8803EFA8, (ts4_word)(ts4_word)lbl_88CD163C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B080, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C508: call_seq lbl_88CD16CC, lbl_880456EC, lbl_88CD16FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD16CC_88A2C508(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD16FC, (ts4_word)(ts4_word)lbl_880456EC, (ts4_word)(ts4_word)lbl_88CD16CC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C570: call_seq lbl_88CD163C, lbl_880402A0, lbl_88CD172C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD163C_88A2C570(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD172C, (ts4_word)(ts4_word)lbl_880402A0, (ts4_word)(ts4_word)lbl_88CD163C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C5D8: call_seq lbl_88CD166C, lbl_88040E18, lbl_88CD175C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD166C_88A2C5D8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD175C, (ts4_word)(ts4_word)lbl_88040E18, (ts4_word)(ts4_word)lbl_88CD166C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C640: call_seq lbl_88CD172C, lbl_88040E68, lbl_88CD178C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD172C_88A2C640(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD178C, (ts4_word)(ts4_word)lbl_88040E68, (ts4_word)(ts4_word)lbl_88CD172C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C6A8: call_seq lbl_88CD166C, lbl_88040DB0, lbl_88CD17BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CD166C_88A2C6A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD17BC, (ts4_word)(ts4_word)lbl_88040DB0, (ts4_word)(ts4_word)lbl_88CD166C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C710: call_seq lbl_88B7B0B0, lbl_88CD184C, lbl_8803F6D8, lbl_88CD17EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B0B0_88A2C710(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD17EC, (ts4_word)(ts4_word)lbl_8803F6D8, (ts4_word)(ts4_word)lbl_88CD184C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B0B0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C788: call_seq lbl_88B7B0E0, lbl_88CD187C, lbl_88045914, lbl_88CD181C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B0E0_88A2C788(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD181C, (ts4_word)(ts4_word)lbl_88045914, (ts4_word)(ts4_word)lbl_88CD187C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B0E0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C800: call_seq lbl_88B7B0F8, lbl_88CD193C, lbl_88047070, lbl_88CD184C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B0F8_88A2C800(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD184C, (ts4_word)(ts4_word)lbl_88047070, (ts4_word)(ts4_word)lbl_88CD193C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B0F8, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C878: call_seq lbl_88B7B128, lbl_88CD184C, lbl_880402BC, lbl_88CD187C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B128_88A2C878(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD187C, (ts4_word)(ts4_word)lbl_880402BC, (ts4_word)(ts4_word)lbl_88CD184C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B128, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C8F0: call_seq lbl_88B7B140, lbl_88CD187C, lbl_88045580, lbl_88CD18AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B140_88A2C8F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD18AC, (ts4_word)(ts4_word)lbl_88045580, (ts4_word)(ts4_word)lbl_88CD187C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B140, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C968: call_seq lbl_88058194, lbl_88B7B158, lbl_88CCF20C, lbl_8803F660, lbl_88CD18DC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88058194_88A2C968(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD18DC, (ts4_word)(ts4_word)lbl_8803F660, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B158, (ts4_word)7, (ts4_word)(ts4_word)lbl_88058194, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2C9E0: get u32@lbl_88B7B20C, lbl_88B7D6B0, u32@lbl_88B7B208, u32@lbl_88B7B204, u32@0x50, u32@0x110 */
void ts4_get_u32_lbl_88B7B20C_88A2C9E0(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B7B20C;
    t2 = *(ts4_word *)lbl_88B7B208;
    t3 = *(ts4_word *)lbl_88B7B204;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D6B0) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D6B0) + 272) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B7D6B0) + 560) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x88A2CA88: call_seq lbl_88B7B218, lbl_88CCF20C, lbl_8803F084, lbl_88CD193C, lbl_88058390, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B218_88A2CA88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD193C, (ts4_word)(ts4_word)lbl_8803F084, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88058390, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7B218, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2CB00: call_seq lbl_88B7B2A8, lbl_88CCF20C, lbl_8804707C, lbl_88CD196C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B2A8_88A2CB00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD196C, (ts4_word)(ts4_word)lbl_8804707C, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B2A8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2CB78: call_seq lbl_88B7B2C0, lbl_88CCFCBC, lbl_88044F38, lbl_88CD199C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B2C0_88A2CB78(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD199C, (ts4_word)(ts4_word)lbl_88044F38, (ts4_word)(ts4_word)lbl_88CCFCBC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B2C0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2CBF0: call_seq lbl_88B7B2D8, lbl_88042E20, lbl_88CD19CC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B2D8_88A2CBF0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD19CC, (ts4_word)(ts4_word)lbl_88042E20, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B2D8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2CC60: call_seq lbl_88B7B2F0, lbl_88CCF20C, lbl_8803EFD0, lbl_88CD19FC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B2F0_88A2CC60(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD19FC, (ts4_word)(ts4_word)lbl_8803EFD0, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B2F0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2CCD8: call_seq lbl_88B7B338, lbl_88044F10, lbl_88CD1A2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B338_88A2CCD8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1A2C, (ts4_word)(ts4_word)lbl_88044F10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B338, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2CD48: call_seq lbl_88B7B350, lbl_88CCF20C, lbl_88044F90, lbl_88CD1A5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B350_88A2CD48(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1A5C, (ts4_word)(ts4_word)lbl_88044F90, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B350, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2CDC0: call_seq lbl_88B7B388, lbl_880421E0, lbl_88CD1A8C, lbl_880583E8, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B388_88A2CDC0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1A8C, (ts4_word)(ts4_word)lbl_880421E0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880583E8, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7B388, (ts4_word)7, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2CE30: call_seq lbl_88B7B430, lbl_88CD0D0C, lbl_8803F030, lbl_88CD1ABC, lbl_880583BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B430_88A2CE30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1ABC, (ts4_word)(ts4_word)lbl_8803F030, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_880583BC, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7B430, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2CEA0: call_seq lbl_88B7B448, lbl_880421C4, lbl_88CD1AEC, lbl_88058414, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B448_88A2CEA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1AEC, (ts4_word)(ts4_word)lbl_880421C4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88058414, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B7B448, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2CF10: call_seq lbl_88B7B4A8, lbl_88CD0D0C, lbl_88040318, lbl_88CD1B1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B4A8_88A2CF10(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1B1C, (ts4_word)(ts4_word)lbl_88040318, (ts4_word)(ts4_word)lbl_88CD0D0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B4A8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2CF88: call_seq lbl_88B7B4C0, lbl_88CD0C1C, lbl_88044EA8, lbl_88CD1B4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B4C0_88A2CF88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1B4C, (ts4_word)(ts4_word)lbl_88044EA8, (ts4_word)(ts4_word)lbl_88CD0C1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B4C0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D000: call_seq lbl_88B7B508, lbl_88CD0C1C, lbl_88044E64, lbl_88CD1B7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B508_88A2D000(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1B7C, (ts4_word)(ts4_word)lbl_88044E64, (ts4_word)(ts4_word)lbl_88CD0C1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B508, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D078: call_seq lbl_88B7B568, lbl_88CD0C4C, lbl_88044DD0, lbl_88CD1BAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B568_88A2D078(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1BAC, (ts4_word)(ts4_word)lbl_88044DD0, (ts4_word)(ts4_word)lbl_88CD0C4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B568, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D0F0: call_seq lbl_88B7B5C8, lbl_88CD0C4C, lbl_88044CD0, lbl_88CD1BDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B5C8_88A2D0F0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1BDC, (ts4_word)(ts4_word)lbl_88044CD0, (ts4_word)(ts4_word)lbl_88CD0C4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B5C8, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D168: call_seq lbl_88B7B628, lbl_88CD0C1C, lbl_88044BD4, lbl_88CD1C0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B628_88A2D168(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1C0C, (ts4_word)(ts4_word)lbl_88044BD4, (ts4_word)(ts4_word)lbl_88CD0C1C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B628, (ts4_word)8, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D1E0: call_seq lbl_88B7B6E8, lbl_88058428, lbl_8803F094, lbl_88CD1C3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B6E8_88A2D1E0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1C3C, (ts4_word)(ts4_word)lbl_8803F094, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B6E8, (ts4_word)19, (ts4_word)(ts4_word)lbl_88058428, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D258: call_seq lbl_88B7B8B0, lbl_88CCFD7C, lbl_8803F0AC, lbl_88CD1C6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B8B0_88A2D258(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1C6C, (ts4_word)(ts4_word)lbl_8803F0AC, (ts4_word)(ts4_word)lbl_88CCFD7C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B8B0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D2D0: call_seq lbl_88B7B8C8, lbl_88CCFD7C, lbl_88044E30, lbl_88CD1C9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B8C8_88A2D2D0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1C9C, (ts4_word)(ts4_word)lbl_88044E30, (ts4_word)(ts4_word)lbl_88CCFD7C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B8C8, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D348: call_seq lbl_88B7B8E0, lbl_88CCFD7C, lbl_88044DF8, lbl_88CD1CCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B8E0_88A2D348(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1CCC, (ts4_word)(ts4_word)lbl_88044DF8, (ts4_word)(ts4_word)lbl_88CCFD7C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B8E0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D3C0: call_seq lbl_88B7B910, lbl_88044B54, lbl_88CD1CFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B910_88A2D3C0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1CFC, (ts4_word)(ts4_word)lbl_88044B54, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B910, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D430: call_seq lbl_88B7B940, lbl_88CCFD7C, lbl_88044D8C, lbl_88CD1D2C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B940_88A2D430(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1D2C, (ts4_word)(ts4_word)lbl_88044D8C, (ts4_word)(ts4_word)lbl_88CCFD7C, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B940, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D4A8: call_seq lbl_88B7B958, lbl_88044A90, lbl_88CD1D5C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B958_88A2D4A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1D5C, (ts4_word)(ts4_word)lbl_88044A90, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B958, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D518: call_seq lbl_88B7B988, lbl_88044ACC, lbl_88CD1D8C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B988_88A2D518(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1D8C, (ts4_word)(ts4_word)lbl_88044ACC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B988, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D588: call_seq lbl_88B7B9D0, lbl_88CCF20C, lbl_88044CFC, lbl_88CD1DBC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7B9D0_88A2D588(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1DBC, (ts4_word)(ts4_word)lbl_88044CFC, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7B9D0, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D600: call_seq lbl_88B7BA18, lbl_88CD0C4C, lbl_8804705C, lbl_88CD1DEC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7BA18_88A2D600(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1DEC, (ts4_word)(ts4_word)lbl_8804705C, (ts4_word)(ts4_word)lbl_88CD0C4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7BA18, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D678: call_seq lbl_88B7BAA8, lbl_88044A58, lbl_88CD1E1C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7BAA8_88A2D678(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1E1C, (ts4_word)(ts4_word)lbl_88044A58, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7BAA8, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D6E8: call_seq lbl_88B7BAF0, lbl_88044B0C, lbl_88CD1E4C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7BAF0_88A2D6E8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1E4C, (ts4_word)(ts4_word)lbl_88044B0C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7BAF0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D758: call_seq lbl_88B7BB20, lbl_88044B94, lbl_88CD1E7C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7BB20_88A2D758(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1E7C, (ts4_word)(ts4_word)lbl_88044B94, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7BB20, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D7C8: call_seq lbl_88B7BB50, lbl_88CCF20C, lbl_88044D60, lbl_88CD1EAC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7BB50_88A2D7C8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1EAC, (ts4_word)(ts4_word)lbl_88044D60, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7BB50, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D840: call_seq lbl_88B7BB80, lbl_88CCF20C, lbl_88044C84, lbl_88CD1EDC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7BB80_88A2D840(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1EDC, (ts4_word)(ts4_word)lbl_88044C84, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7BB80, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D8B8: call_seq lbl_88B7BB98, lbl_88CCF20C, lbl_88044C48, lbl_88CD1F0C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7BB98_88A2D8B8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1F0C, (ts4_word)(ts4_word)lbl_88044C48, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7BB98, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D930: call_seq lbl_88B7BBB0, lbl_88044A08, lbl_88CD1F3C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7BBB0_88A2D930(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1F3C, (ts4_word)(ts4_word)lbl_88044A08, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7BBB0, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2D9A0: call_seq lbl_88B7BBE0, lbl_88CCF20C, lbl_88044C08, lbl_88CD1F6C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7BBE0_88A2D9A0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1F6C, (ts4_word)(ts4_word)lbl_88044C08, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7BBE0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2DA18: call_seq lbl_88B7BBF8, lbl_88040668, lbl_88CD1F9C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7BBF8_88A2DA18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1F9C, (ts4_word)(ts4_word)lbl_88040668, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7BBF8, (ts4_word)10, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2DA88: call_seq lbl_88B7BCE8, lbl_88CCF20C, lbl_88040658, lbl_88CD1FCC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7BCE8_88A2DA88(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1FCC, (ts4_word)(ts4_word)lbl_88040658, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7BCE8, (ts4_word)18, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2DB00: call_seq lbl_88B7BE98, lbl_8803F5F4, lbl_88CD1FFC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7BE98_88A2DB00(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD1FFC, (ts4_word)(ts4_word)lbl_8803F5F4, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7BE98, (ts4_word)17, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2DB70: call_seq lbl_88B7C030, lbl_88CD0C4C, lbl_8803F64C, lbl_88CD202C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C030_88A2DB70(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD202C, (ts4_word)(ts4_word)lbl_8803F64C, (ts4_word)(ts4_word)lbl_88CD0C4C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C030, (ts4_word)25, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2DBE8: call_seq lbl_88CCF20C, lbl_8804494C, lbl_88CD205C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCF20C_88A2DBE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD205C, (ts4_word)(ts4_word)lbl_8804494C, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2DC50: call_seq lbl_88B7C288, lbl_88CD205C, lbl_88044700, lbl_88CD208C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C288_88A2DC50(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD208C, (ts4_word)(ts4_word)lbl_88044700, (ts4_word)(ts4_word)lbl_88CD205C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C288, (ts4_word)5, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2DCC8: call_seq lbl_88CCF20C, lbl_88044924, lbl_88CD20BC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCF20C_88A2DCC8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD20BC, (ts4_word)(ts4_word)lbl_88044924, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2DD30: call_seq lbl_88B7C300, lbl_88044438, lbl_88CD20EC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C300_88A2DD30(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD20EC, (ts4_word)(ts4_word)lbl_88044438, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C300, (ts4_word)3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2DDA0: call_seq lbl_88B7C348, lbl_88CD20BC, lbl_88044680, lbl_88CD211C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C348_88A2DDA0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD211C, (ts4_word)(ts4_word)lbl_88044680, (ts4_word)(ts4_word)lbl_88CD20BC, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C348, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2DE18: call_seq lbl_88CCF20C, lbl_880448C8, lbl_88CD214C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCF20C_88A2DE18(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD214C, (ts4_word)(ts4_word)lbl_880448C8, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2DE80: call_seq lbl_88CCF20C, lbl_880448FC, lbl_88CD217C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88CCF20C_88A2DE80(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD217C, (ts4_word)(ts4_word)lbl_880448FC, (ts4_word)(ts4_word)lbl_88CCF20C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A2DEE8: call_seq lbl_88B7C378, lbl_88CD214C, lbl_88044524, lbl_88CD21AC, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B7C378_88A2DEE8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CD21AC, (ts4_word)(ts4_word)lbl_88044524, (ts4_word)(ts4_word)lbl_88CD214C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B7C378, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}
