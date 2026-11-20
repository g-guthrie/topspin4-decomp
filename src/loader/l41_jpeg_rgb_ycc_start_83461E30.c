/* Loader_DLL.xex 0x83461E30-0x83461F00, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jccolor.c): rgb_ycc_start. */
struct ts4l_compress_struct;
typedef struct ts4l_memory_mgr {
    void *(*alloc_small)(struct ts4l_compress_struct *cinfo, int pool_id, unsigned long sizeofobject);
} ts4l_memory_mgr;
typedef struct ts4l_cconverter {
    void *start_pass;
    void *color_convert;
    long *rgb_ycc_tab;
} ts4l_cconverter;
typedef struct ts4l_compress_struct {
    void *err;
    ts4l_memory_mgr *mem;
    char pad8[0x168 - 0x08];
    ts4l_cconverter *cconvert;
} ts4l_compress_struct;

#define SCALEBITS 16
#define CBCR_OFFSET ((long)128 << SCALEBITS)
#define ONE_HALF ((long)1 << (SCALEBITS - 1))
#define FIX(x) ((long)((x) * (1L << SCALEBITS) + 0.5))
#define R_Y_OFF 0
#define G_Y_OFF (1 * 256)
#define B_Y_OFF (2 * 256)
#define R_CB_OFF (3 * 256)
#define G_CB_OFF (4 * 256)
#define B_CB_OFF (5 * 256)
#define R_CR_OFF B_CB_OFF
#define G_CR_OFF (6 * 256)
#define B_CR_OFF (7 * 256)
#define TABLE_SIZE (8 * 256)

void ts4l_jpeg_rgb_ycc_start_83461E30(ts4l_compress_struct *cinfo)
{
    ts4l_cconverter *cconvert = cinfo->cconvert;
    long *rgb_ycc_tab;
    long i;

    rgb_ycc_tab = (long *)(*cinfo->mem->alloc_small)(cinfo, 1, TABLE_SIZE * sizeof(long));
    cconvert->rgb_ycc_tab = rgb_ycc_tab;

    for (i = 0; i <= 255; i++) {
        rgb_ycc_tab[i + R_Y_OFF] = FIX(0.29900) * i;
        rgb_ycc_tab[i + G_Y_OFF] = FIX(0.58700) * i;
        rgb_ycc_tab[i + B_Y_OFF] = FIX(0.11400) * i + ONE_HALF;
        rgb_ycc_tab[i + R_CB_OFF] = (-FIX(0.16874)) * i;
        rgb_ycc_tab[i + G_CB_OFF] = (-FIX(0.33126)) * i;
        rgb_ycc_tab[i + B_CB_OFF] = FIX(0.50000) * i + CBCR_OFFSET + ONE_HALF - 1;
        rgb_ycc_tab[i + G_CR_OFF] = (-FIX(0.41869)) * i;
        rgb_ycc_tab[i + B_CR_OFF] = (-FIX(0.08131)) * i;
    }
}
