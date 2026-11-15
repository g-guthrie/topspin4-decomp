/* CW18 part d: guarded static hash lists (0x88850000-0x88871F08). The list and its init flag are globals here (lbl_*), as
   the original's relocations target them directly. Built with /Oc. */
typedef unsigned int u32;
typedef struct Cx18Reg { char pad[0x70]; void *f70; } Cx18Reg;
extern Cx18Reg *lbl_88D41FC4;
extern u32 lbl_88D4D8F0[32];
extern u32 lbl_88D4D970;
extern u32 lbl_88D4D978[16];
extern u32 lbl_88D4D9B8;
extern void fn_882107D0(void *owner, u32 *hash, int flag);
extern void ts4_register_hash_list32_8886BCE0(void);

/* 0x8886BCE0: register 32 hashes (list built on first use) with the owner at +0x70 of the global */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_register_hash_list32_8886BCE0(void)
{
    u32 *p;
    int n;
    if ((lbl_88D4D970 & 1) == 0) {
        lbl_88D4D970 |= 1;
        lbl_88D4D8F0[0] = 0x6FBFDE10;
        lbl_88D4D8F0[1] = 0x84886513;
        lbl_88D4D8F0[2] = 0x6B4A0E2D;
        lbl_88D4D8F0[3] = 0x89961554;
        lbl_88D4D8F0[4] = 0x5A526843;
        lbl_88D4D8F0[5] = 0xB165D340;
        lbl_88D4D8F0[6] = 0x5EA7B87E;
        lbl_88D4D8F0[7] = 0xBC7BA307;
        lbl_88D4D8F0[8] = 0xFFD9F84D;
        lbl_88D4D8F0[9] = 0x14EE434E;
        lbl_88D4D8F0[10] = 0xFB2C2870;
        lbl_88D4D8F0[11] = 0x19F03309;
        lbl_88D4D8F0[12] = 0x318904E5;
        lbl_88D4D8F0[13] = 0xDABEBFE6;
        lbl_88D4D8F0[14] = 0x357CD4D8;
        lbl_88D4D8F0[15] = 0xD7A0CFA1;
        lbl_88D4D8F0[16] = 0xE60CC797;
        lbl_88D4D8F0[17] = 0xDF81FB52;
        lbl_88D4D8F0[18] = 0xC8FAEF11;
        lbl_88D4D8F0[19] = 0xAC9B82D8;
        lbl_88D4D8F0[20] = 0xBE126EBF;
        lbl_88D4D8F0[21] = 0x879F527A;
        lbl_88D4D8F0[22] = 0x90E44639;
        lbl_88D4D8F0[23] = 0xF4852BF0;
        lbl_88D4D8F0[24] = 0x3F370B98;
        lbl_88D4D8F0[25] = 0x06BA375D;
        lbl_88D4D8F0[26] = 0x11C1231E;
        lbl_88D4D8F0[27] = 0x75A04ED7;
        lbl_88D4D8F0[28] = 0x0E2F3CEF;
        lbl_88D4D8F0[29] = 0x37A2002A;
        lbl_88D4D8F0[30] = 0x20D91469;
        lbl_88D4D8F0[31] = 0x44B879A0;
    }
    p = lbl_88D4D8F0;
    for (n = 32; n != 0; n--, p++) fn_882107D0(lbl_88D41FC4->f70, p, 0);
}

/* 0x8886BEC8: register 16 hashes (list built on first use), then the 32-hash list */
void ts4_register_hash_list16_8886BEC8(void)
{
    u32 *p;
    int n;
    if ((lbl_88D4D9B8 & 1) == 0) {
        lbl_88D4D9B8 |= 1;
        lbl_88D4D978[0] = 0xFAB3E2FF;
        lbl_88D4D978[1] = 0x63BAB345;
        lbl_88D4D978[2] = 0x14BD83D3;
        lbl_88D4D978[3] = 0x8AD91670;
        lbl_88D4D978[4] = 0x5B2A5BB2;
        lbl_88D4D978[5] = 0xC2230A08;
        lbl_88D4D978[6] = 0xB5243A9E;
        lbl_88D4D978[7] = 0x2B40AF3D;
        lbl_88D4D978[8] = 0x315BD78E;
        lbl_88D4D978[9] = 0xA8528634;
        lbl_88D4D978[10] = 0xDF55B6A2;
        lbl_88D4D978[11] = 0x41312301;
        lbl_88D4D978[12] = 0x7971E42F;
        lbl_88D4D978[13] = 0xE078B595;
        lbl_88D4D978[14] = 0x977F8503;
        lbl_88D4D978[15] = 0x091B10A0;
    }
    p = lbl_88D4D978;
    for (n = 16; n != 0; n--, p++) fn_882107D0(lbl_88D41FC4->f70, p, 0);
    ts4_register_hash_list32_8886BCE0();
}
