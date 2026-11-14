/* Swing_DLL.xex 0x88994F40-0x88995180, executable version 0.0.0.3. */
extern const char lbl_880D259C[];
extern const char lbl_880D25A4[];
extern const char lbl_880D25C0[];
extern const char lbl_880D25F4[];
extern const char lbl_880D261C[];
extern const char lbl_880D2640[];
extern const char lbl_880D26A0[];
extern const char lbl_880D26D4[];
extern const char lbl_880D2710[];
extern const char lbl_880D2734[];
extern const char lbl_880D2748[];
extern const char lbl_880D2798[];
extern const char lbl_880D27E8[];
extern const char lbl_880D2828[];
extern const char lbl_880D286C[];
extern const char lbl_880D28A0[];
extern const char lbl_880D28B0[];
extern const char lbl_880D28F0[];
extern const char lbl_880D2968[];
extern const char lbl_880D29C0[];
extern const char lbl_880D29F4[];

const char *ts4_hresult_text_88994F40(int code)
{
    int hr = (code <= 0) ? code : (int)((code & 0xFFFF) | 0x80070000);
    switch (hr) {
    case (int)0x80070057u:
        return lbl_880D25A4;
    case (int)0x80070000u:
        return lbl_880D259C;
    case (int)0x8007007Au:
        return lbl_880D25C0;
    case (int)0x800705B4u:
        return lbl_880D26D4;
    case (int)0x800703E5u:
        return lbl_880D25F4;
    case (int)0x8007065Bu:
        return lbl_880D2710;
    case (int)0x80072735u:
        return lbl_880D2640;
    case (int)0x80072726u:
        return lbl_880D261C;
    case (int)0x80072741u:
        return lbl_880D26A0;
    case (int)0x8015000Au:
        return lbl_880D2734;
    case (int)0x80155119u:
        return lbl_880D2828;
    case (int)0x80155202u:
        return lbl_880D2748;
    case (int)0x80155125u:
        return lbl_880D286C;
    case (int)0x80155206u:
        return lbl_880D2798;
    case (int)0x80155209u:
        return lbl_880D2968;
    case (int)0x8015520Cu:
        return lbl_880D27E8;
    case (int)0x80159003u:
        return lbl_880D28A0;
    case (int)0x8015520Du:
        return lbl_880D29C0;
    case (int)0x8015B10Du:
        return lbl_880D28B0;
    default:
        return lbl_880D29F4;
    case (int)0x0015B1F2u:
        return lbl_880D28F0;
    }
}
