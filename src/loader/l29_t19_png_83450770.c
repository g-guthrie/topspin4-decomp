/* Loader_DLL.xex 0x83450770-0x83450848, executable version 0.0.0.3. */
/* libpng: png_write_PLTE. */
typedef unsigned long ts4l_u32;
typedef unsigned char ts4l_u8;
typedef struct Ts4lPng {
    char pad0[0x558]; ts4l_u32 mode;
    char pad1[0x608 - 0x55c]; unsigned short num_palette;
    char pad2[0x616 - 0x60a]; ts4l_u8 color_type;
    char pad3[0x698 - 0x617]; ts4l_u8 mng;
} Ts4lPng;
extern void fn_8343FD80(Ts4lPng *png, const char *msg);
extern void ts4_if_get_u32_off544_8343FDB8(Ts4lPng *png, const char *msg);
extern void fn_83450640(Ts4lPng *png, const char *name, ts4l_u32 len);
extern void fn_83440030(Ts4lPng *png, const void *buf, ts4l_u32 n);
extern void ts4_if_get_u32_off54c_83445FC0(Ts4lPng *png, const void *buf, ts4l_u32 n);
extern void ts4l_call_seq_u32_off600_83450710(Ts4lPng *png);
extern char lbl_8307AA40[];
extern char lbl_8307AA38[];

void ts4l_png_write_plte_83450770(Ts4lPng *png, const ts4l_u8 *pal, ts4l_u32 num)
{
    ts4l_u8 buf[3];
    ts4l_u32 i;
    const ts4l_u8 *pp;
    if ((png->mng == 0 && num == 0) || num > 256) {
        if (png->color_type == 3) {
            fn_8343FD80(png, lbl_8307AA40);
        } else {
            ts4_if_get_u32_off544_8343FDB8(png, lbl_8307AA40);
            return;
        }
    }
    png->num_palette = (unsigned short)num;
    fn_83450640(png, lbl_8307AA38, num * 3);
    for (i = 0, pp = pal; i < num; i++, pp += 3) {
        buf[0] = pp[0];
        buf[1] = pp[1];
        buf[2] = pp[2];
        fn_83440030(png, buf, 3);
        ts4_if_get_u32_off54c_83445FC0(png, buf, 3);
    }
    ts4l_call_seq_u32_off600_83450710(png);
    png->mode |= 2;
}
