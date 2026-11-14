/* Loader_DLL.xex 0x83107690-0x831089F0, executable version 0.0.0.3.
   Function-local static singletons: guard bit, construct, register destructor. */
extern unsigned lbl_83530090;
extern char lbl_8353007C[];
extern float lbl_830009F8;
extern char ts4_addr_lbl_8353007C_835165D8[];
extern void ts4_set_u32_off0_831403F8(void *p, float v);
extern void fn_833E4920(void *p);
extern unsigned lbl_835300B0;
extern char lbl_8353009C[];
extern float lbl_83000A00;
extern char ts4_addr_lbl_8353009C_83516618[];
extern unsigned lbl_835300E0;
extern char lbl_835300CC[];
extern float lbl_830012A8;
extern char ts4_addr_lbl_835300CC_83516628[];
extern unsigned lbl_83530110;
extern char lbl_835300FC[];
extern float lbl_830012AC;
extern char ts4_addr_lbl_835300FC_83516668[];
extern unsigned lbl_83530128;
extern char lbl_83530114[];
extern float lbl_830012B0;
extern char ts4_addr_lbl_83530114_83516658[];
extern unsigned lbl_83530140;
extern char lbl_8353012C[];
extern float lbl_830009E8;
extern char ts4_addr_lbl_8353012C_83516648[];
extern unsigned lbl_83530340;
extern char lbl_8353032C[];
extern char ts4_addr_lbl_8353032C_83516718[];

void *ts4l_static_singleton_83107690(void)
{
    if (((lbl_83530090) & 1) == 0) {
        lbl_83530090 |= 1;
        ts4_set_u32_off0_831403F8(lbl_8353007C, lbl_830009F8);
        fn_833E4920(ts4_addr_lbl_8353007C_835165D8);
    }
    return lbl_8353007C;
}

void *ts4l_static_singleton_83107CE8(void)
{
    if (((lbl_835300B0) & 1) == 0) {
        lbl_835300B0 |= 1;
        ts4_set_u32_off0_831403F8(lbl_8353009C, lbl_83000A00);
        fn_833E4920(ts4_addr_lbl_8353009C_83516618);
    }
    return lbl_8353009C;
}

void *ts4l_static_singleton_83107EA0(void)
{
    if (((lbl_835300E0) & 1) == 0) {
        lbl_835300E0 |= 1;
        ts4_set_u32_off0_831403F8(lbl_835300CC, lbl_830012A8);
        fn_833E4920(ts4_addr_lbl_835300CC_83516628);
    }
    return lbl_835300CC;
}

void *ts4l_static_singleton_83107FC0(void)
{
    if (((lbl_83530110) & 1) == 0) {
        lbl_83530110 |= 1;
        ts4_set_u32_off0_831403F8(lbl_835300FC, lbl_830012AC);
        fn_833E4920(ts4_addr_lbl_835300FC_83516668);
    }
    return lbl_835300FC;
}

void *ts4l_static_singleton_83108028(void)
{
    if (((lbl_83530128) & 1) == 0) {
        lbl_83530128 |= 1;
        ts4_set_u32_off0_831403F8(lbl_83530114, lbl_830012B0);
        fn_833E4920(ts4_addr_lbl_83530114_83516658);
    }
    return lbl_83530114;
}

void *ts4l_static_singleton_83108090(void)
{
    if (((lbl_83530140) & 1) == 0) {
        lbl_83530140 |= 1;
        ts4_set_u32_off0_831403F8(lbl_8353012C, lbl_830009E8);
        fn_833E4920(ts4_addr_lbl_8353012C_83516648);
    }
    return lbl_8353012C;
}

void *ts4l_static_singleton_831089F0(void)
{
    if (((lbl_83530340) & 1) == 0) {
        lbl_83530340 |= 1;
        ts4_set_u32_off0_831403F8(lbl_8353032C, lbl_830009F8);
        fn_833E4920(ts4_addr_lbl_8353032C_83516718);
    }
    return lbl_8353032C;
}
