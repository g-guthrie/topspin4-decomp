/* Loader_DLL.xex 0x8345F278-0x8345F368, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcphuff.c): finish_pass_gather_phuff. */
#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
#else
#include <string.h>
#endif
typedef struct ts4l_huff_tbl ts4l_huff_tbl;
typedef struct ts4l_component_info {
    char pad0[0x14];
    int dc_tbl_no;
    int ac_tbl_no;
    char pad1c[0x54 - 0x1c];
} ts4l_component_info;
typedef struct ts4l_phuff_entropy {
    char pad0[0x5c];
    long *count_ptrs[4];
} ts4l_phuff_entropy;
typedef struct ts4l_compress_struct {
    char pad0[0x58];
    ts4l_huff_tbl *dc_huff_tbl_ptrs[4];
    ts4l_huff_tbl *ac_huff_tbl_ptrs[4];
    char pad78[0xfc - 0x78];
    int comps_in_scan;
    ts4l_component_info *cur_comp_info[4];
    char pad110[0x144 - 0x110];
    int Ss, Se, Ah, Al;
    char pad154[0x174 - 0x154];
    ts4l_phuff_entropy *entropy;
} ts4l_compress_struct;

extern void fn_8345E788(ts4l_phuff_entropy *entropy);
extern ts4l_huff_tbl *ts4_get_u32_off4_8344E390(ts4l_compress_struct *cinfo);
extern void ts4l_jpeg_gen_optimal_table_8345D9B8(ts4l_compress_struct *cinfo, ts4l_huff_tbl *htbl, long *freq);

void ts4l_jpeg_finish_pass_gather_phuff_8345F278(ts4l_compress_struct *cinfo)
{
    ts4l_phuff_entropy *entropy = cinfo->entropy;
    int is_DC_band;
    int ci, tbl;
    ts4l_component_info *compptr;
    ts4l_huff_tbl **htblptr;
    int did[4];

    fn_8345E788(entropy);

    is_DC_band = (cinfo->Ss == 0);

    memset(did, 0, sizeof(did));

    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
        compptr = cinfo->cur_comp_info[ci];
        if (is_DC_band) {
            if (cinfo->Ah != 0)
                continue;
            tbl = compptr->dc_tbl_no;
        } else {
            tbl = compptr->ac_tbl_no;
        }
        if (!did[tbl]) {
            if (is_DC_band)
                htblptr = &cinfo->dc_huff_tbl_ptrs[tbl];
            else
                htblptr = &cinfo->ac_huff_tbl_ptrs[tbl];
            if (*htblptr == 0)
                *htblptr = ts4_get_u32_off4_8344E390(cinfo);
            ts4l_jpeg_gen_optimal_table_8345D9B8(cinfo, *htblptr, entropy->count_ptrs[tbl]);
            did[tbl] = 1;
        }
    }
}
