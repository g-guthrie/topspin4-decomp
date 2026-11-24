/* Swing_DLL.xex 0x88A40230-0x88A45990, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern char lbl_88B89868[];
extern char lbl_88B8C068[];
extern char lbl_88B8C488[];
extern char lbl_88B8C4EC[];
extern char lbl_88B8CE44[];
extern char lbl_88B8D550[];
extern char lbl_88B8D584[];
extern char lbl_88B8DCCC[];
extern char lbl_88B8DEB8[];
extern char lbl_88B8DF24[];
extern char lbl_88B8DFDC[];
extern char lbl_88B8E4F0[];
extern char lbl_88B8E5E8[];
extern char lbl_88B8E634[];
extern char lbl_88B92A28[];
extern char lbl_88B92A70[];
extern char lbl_88B92AE8[];
extern char lbl_88B92C50[];
extern char lbl_88B92DE8[];
extern char lbl_88B92EF0[];
extern char lbl_88B93010[];
extern char lbl_88B930D0[];
extern char lbl_88B93160[];
extern char lbl_88B93190[];
extern char lbl_88B931C0[];
extern char lbl_88B931F0[];
extern char lbl_88B93268[];
extern char lbl_88B932B0[];

void ts4_copy_global_u32_88A445D0(void)
{
    unsigned int value = *(unsigned int *)lbl_88B8DCCC;
    *(unsigned int *)(lbl_88B92EF0 + 0x50) = value;
}

void ts4_copy_global_u32_88A449E0(void)
{
    unsigned int value = *(unsigned int *)lbl_88B8DEB8;
    *(unsigned int *)(lbl_88B93010 + 0x50) = value;
    *(unsigned int *)(lbl_88B93010 + 0x68) = value;
}

void ts4_copy_global_u32_88A44BC0(void)
{
    unsigned int value = *(unsigned int *)lbl_88B8DF24;
    *(unsigned int *)(lbl_88B930D0 + 0x50) = value;
}

void ts4_copy_global_u32_88A44F58(void)
{
    unsigned int value = *(unsigned int *)lbl_88B8DFDC;
    *(unsigned int *)(lbl_88B93160 + 0x20) = value;
}

void ts4_copy_global_u32_88A44FE0(void)
{
    unsigned int value = *(unsigned int *)lbl_88B8DFDC;
    *(unsigned int *)(lbl_88B93190 + 0x20) = value;
}

void ts4_copy_global_u32_88A450D8(void)
{
    unsigned int value = *(unsigned int *)lbl_88B8DFDC;
    *(unsigned int *)(lbl_88B931C0 + 0x20) = value;
}

void ts4_copy_global_u32_88A456A8(void)
{
    unsigned int value = *(unsigned int *)lbl_88B8E4F0;
    *(unsigned int *)(lbl_88B931F0 + 0x8) = value;
}

void ts4_copy_global_u32_88A45810(void)
{
    unsigned int value = *(unsigned int *)lbl_88B8E5E8;
    *(unsigned int *)(lbl_88B93268 + 0x20) = value;
}

void ts4_copy_global_u32_88A45978(void)
{
    unsigned int value = *(unsigned int *)lbl_88B8E634;
    *(unsigned int *)(lbl_88B932B0 + 0x8) = value;
}
