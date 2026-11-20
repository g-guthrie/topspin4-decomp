/* Loader_DLL.xex 0x83106B30-0x8321C780, executable version 0.0.0.3. */
extern unsigned lbl_8352FE70;
extern char lbl_8352FE5C[];
extern float lbl_83001104;
extern char ts4_addr_lbl_8352FE5C_83516568[];
extern void ts4_set_u32_off0_831403F8(void *p, float v);
extern void fn_833E4920(void *p);
extern unsigned lbl_8352FED0;
extern char lbl_8352FEBC[];
extern float lbl_830009F8;
extern char ts4_addr_lbl_8352FEBC_83516598[];
extern unsigned lbl_83530F88;
extern char lbl_83530F74[];
extern char ts4_addr_lbl_83530F74_835167F0[];
extern unsigned lbl_83530FA0;
extern char lbl_83530F8C[];
extern float lbl_830009E0;
extern char ts4_addr_lbl_83530F8C_83516800[];
extern unsigned lbl_835310CC;
extern char lbl_835310B8[];
extern float lbl_83002208;
extern char ts4_addr_lbl_835310B8_835168A0[];
extern unsigned lbl_835310E4;
extern char lbl_835310D0[];
extern float lbl_83002678;
extern char ts4_addr_lbl_835310D0_835168B0[];
extern unsigned lbl_8353AE70;
extern char lbl_8353AE5C[];
extern float lbl_830012A8;
extern char ts4_addr_lbl_8353AE5C_83516948[];

void *ts4l_static_singleton_o1_83106B30(void)
{
    if (((lbl_8352FE70) & 1) == 0) {
        lbl_8352FE70 |= 1;
        ts4_set_u32_off0_831403F8(lbl_8352FE5C, lbl_83001104);
        fn_833E4920(ts4_addr_lbl_8352FE5C_83516568);
    }
    return lbl_8352FE5C;
}

void *ts4l_static_singleton_o1_83106E88(void)
{
    if (((lbl_8352FED0) & 1) == 0) {
        lbl_8352FED0 |= 1;
        ts4_set_u32_off0_831403F8(lbl_8352FEBC, lbl_830009F8);
        fn_833E4920(ts4_addr_lbl_8352FEBC_83516598);
    }
    return lbl_8352FEBC;
}

void *ts4l_static_singleton_o1_83117F78(void)
{
    if (((lbl_83530F88) & 1) == 0) {
        lbl_83530F88 |= 1;
        ts4_set_u32_off0_831403F8(lbl_83530F74, lbl_830009F8);
        fn_833E4920(ts4_addr_lbl_83530F74_835167F0);
    }
    return lbl_83530F74;
}

void *ts4l_static_singleton_o1_83117FE0(void)
{
    if (((lbl_83530FA0) & 1) == 0) {
        lbl_83530FA0 |= 1;
        ts4_set_u32_off0_831403F8(lbl_83530F8C, lbl_830009E0);
        fn_833E4920(ts4_addr_lbl_83530F8C_83516800);
    }
    return lbl_83530F8C;
}

void *ts4l_static_singleton_o1_8312E010(void)
{
    if (((lbl_835310CC) & 1) == 0) {
        lbl_835310CC |= 1;
        ts4_set_u32_off0_831403F8(lbl_835310B8, lbl_83002208);
        fn_833E4920(ts4_addr_lbl_835310B8_835168A0);
    }
    return lbl_835310B8;
}

void *ts4l_static_singleton_o1_8312E078(void)
{
    if (((lbl_835310E4) & 1) == 0) {
        lbl_835310E4 |= 1;
        ts4_set_u32_off0_831403F8(lbl_835310D0, lbl_83002678);
        fn_833E4920(ts4_addr_lbl_835310D0_835168B0);
    }
    return lbl_835310D0;
}

void *ts4l_static_singleton_o1_8321C780(void)
{
    if (((lbl_8353AE70) & 1) == 0) {
        lbl_8353AE70 |= 1;
        ts4_set_u32_off0_831403F8(lbl_8353AE5C, lbl_830012A8);
        fn_833E4920(ts4_addr_lbl_8353AE5C_83516948);
    }
    return lbl_8353AE5C;
}
