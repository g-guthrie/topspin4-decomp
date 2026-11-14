/* Loader_DLL.xex 0x83444250-0x834444D0, 0x83444878-0x834448B8, executable version 0.0.0.3. */
/* Library routines: libjpeg jcparam.c (jpeg_quality_scaling, jpeg_set_quality, add_huff_table,
   std_huff_tables, fill_scans). */
#include "l44_jpeg.h"

struct ts4l_jc_scan_info {
    int comps_in_scan;
    int component_index[4];
    int Ss, Se, Ah, Al;
};

extern void fn_83443FF8(struct ts4l_jcomp *cinfo, int which_tbl, const unsigned int *basic_table,
                        int scale_factor, int force_baseline);
extern void *ts4_get_u32_off4_8344E390(struct ts4l_jcomp *cinfo);
extern void fn_833E3AD0(void *dst, const void *src, unsigned int n);
extern void fn_83444340(struct ts4l_jcomp *cinfo, void **htblptr, const unsigned char *bits,
                        const unsigned char *val);
extern const unsigned int lbl_830752E0[];
extern const unsigned int lbl_830751E0[];
extern const unsigned char lbl_83075574[];
extern const unsigned char lbl_83075588[];
extern const unsigned char lbl_830754BC[];
extern const unsigned char lbl_830754D0[];
extern const unsigned char lbl_8307549C[];
extern const unsigned char lbl_830754B0[];
extern const unsigned char lbl_830753E0[];
extern const unsigned char lbl_830753F8[];

int ts4l_jpeg_quality_scaling_83444250(int quality)
{
    if (quality <= 0)
        quality = 1;
    if (quality > 100)
        quality = 100;

    if (quality < 50)
        quality = 5000 / quality;
    else
        quality = 200 - quality * 2;

    return quality;
}

#ifdef _MSC_VER
static __forceinline
#else
static
#endif
int ts4l_quality_scaling_inl(int quality)
{
    if (quality <= 0)
        quality = 1;
    if (quality > 100)
        quality = 100;

    if (quality < 50)
        quality = 5000 / quality;
    else
        quality = 200 - quality * 2;

    return quality;
}

void ts4l_jpeg_set_quality_834442A0(struct ts4l_jcomp *cinfo, int quality, int force_baseline)
{
    quality = ts4l_quality_scaling_inl(quality);

    fn_83443FF8(cinfo, 0, lbl_830752E0, quality, force_baseline);
    fn_83443FF8(cinfo, 1, lbl_830751E0, quality, force_baseline);
}

void ts4l_jpeg_add_huff_table_83444340(struct ts4l_jcomp *cinfo, void **htblptr,
                                       const unsigned char *bits, const unsigned char *val)
{
    int nsymbols, len;

    if (*htblptr == 0)
        *htblptr = ts4_get_u32_off4_8344E390(cinfo);

    fn_833E3AD0(*htblptr, bits, 17);

    nsymbols = 0;
    for (len = 1; len <= 16; len++)
        nsymbols += bits[len];
    if (nsymbols < 1 || nsymbols > 256)
        TS4L_CERREXIT(cinfo, 8);

    fn_833E3AD0((unsigned char *)*htblptr + 17, val, nsymbols);

    ((struct ts4l_jpeg_huff_tbl *)*htblptr)->sent_table = 0;
}

void ts4l_jpeg_std_huff_tables_83444438(struct ts4l_jcomp *cinfo)
{
    fn_83444340(cinfo, &cinfo->dc_huff_tbl_ptrs[0], lbl_83075574, lbl_83075588);
    fn_83444340(cinfo, &cinfo->ac_huff_tbl_ptrs[0], lbl_830754BC, lbl_830754D0);
    fn_83444340(cinfo, &cinfo->dc_huff_tbl_ptrs[1], lbl_8307549C, lbl_830754B0);
    fn_83444340(cinfo, &cinfo->ac_huff_tbl_ptrs[1], lbl_830753E0, lbl_830753F8);
}

struct ts4l_jc_scan_info *ts4l_jpeg_fill_scans_83444878(struct ts4l_jc_scan_info *scanptr, int ncomps,
                                                         int Ss, int Se, int Ah, int Al)
{
    int ci;

    for (ci = 0; ci < ncomps; ci++) {
        scanptr->comps_in_scan = 1;
        scanptr->component_index[0] = ci;
        scanptr->Ss = Ss;
        scanptr->Se = Se;
        scanptr->Ah = Ah;
        scanptr->Al = Al;
        scanptr++;
    }
    return scanptr;
}
