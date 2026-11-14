/* Loader_DLL.xex 0x8344FD18-0x8344FF38, executable version 0.0.0.3. */
/* libjpeg 6b jcmarker.c: emit_jfif_app0 and emit_adobe_app14. */
struct Ts4lJCinfo;
typedef struct Ts4lJCinfo {
    char pad0[0x40];
    int jpeg_color_space;
    char pad1[0xd4 - 0x44];
    unsigned char JFIF_major_version;
    unsigned char JFIF_minor_version;
    unsigned char density_unit;
    char pad2;
    unsigned short X_density;
    unsigned short Y_density;
} Ts4lJCinfo;

extern void fn_8344EFB0(Ts4lJCinfo *cinfo, int val);

static void ts4l_emit_2bytes(Ts4lJCinfo *cinfo, int value)
{
    fn_8344EFB0(cinfo, (value >> 8) & 0xFF);
    fn_8344EFB0(cinfo, value & 0xFF);
}

void ts4l_jpeg_emit_jfif_app0_8344FD18(Ts4lJCinfo *cinfo)
{
    fn_8344EFB0(cinfo, 0xFF);
    fn_8344EFB0(cinfo, 0xE0);
    ts4l_emit_2bytes(cinfo, 2 + 4 + 1 + 2 + 1 + 2 + 2 + 1 + 1);
    fn_8344EFB0(cinfo, 0x4A);
    fn_8344EFB0(cinfo, 0x46);
    fn_8344EFB0(cinfo, 0x49);
    fn_8344EFB0(cinfo, 0x46);
    fn_8344EFB0(cinfo, 0);
    fn_8344EFB0(cinfo, cinfo->JFIF_major_version);
    fn_8344EFB0(cinfo, cinfo->JFIF_minor_version);
    fn_8344EFB0(cinfo, cinfo->density_unit);
    ts4l_emit_2bytes(cinfo, cinfo->X_density);
    ts4l_emit_2bytes(cinfo, cinfo->Y_density);
    fn_8344EFB0(cinfo, 0);
    fn_8344EFB0(cinfo, 0);
}

void ts4l_jpeg_emit_adobe_app14_8344FE30(Ts4lJCinfo *cinfo)
{
    fn_8344EFB0(cinfo, 0xFF);
    fn_8344EFB0(cinfo, 0xEE);
    ts4l_emit_2bytes(cinfo, 2 + 5 + 2 + 2 + 2 + 1);
    fn_8344EFB0(cinfo, 0x41);
    fn_8344EFB0(cinfo, 0x64);
    fn_8344EFB0(cinfo, 0x6F);
    fn_8344EFB0(cinfo, 0x62);
    fn_8344EFB0(cinfo, 0x65);
    ts4l_emit_2bytes(cinfo, 100);
    ts4l_emit_2bytes(cinfo, 0);
    ts4l_emit_2bytes(cinfo, 0);
    switch (cinfo->jpeg_color_space) {
    case 3:
        fn_8344EFB0(cinfo, 1);
        break;
    case 5:
        fn_8344EFB0(cinfo, 2);
        break;
    default:
        fn_8344EFB0(cinfo, 0);
        break;
    }
}
