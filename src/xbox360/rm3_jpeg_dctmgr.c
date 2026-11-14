/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG inverse-DCT manager (IJG libjpeg jddctmgr.c style), Swing_DLL.xex
 * auto_03_882F5CEC. This build maps DCT methods 3/5 to ISLOW and 4/6 to IFAST. (RM3) */
#include "rm3_jpeg.h"

/* IJG aanscales (AA&N scale factors in 2.14 fixed point), shared with the
 * forward-DCT manager. */
extern const short lbl_88026AD8[64];
/* IJG aanscalefactor; the compiler folds the 1.0 entries. */
static const double lbl_88026B58[8] = {
    1.0, 1.387039845, 1.306562965, 1.175875602,
    1.0, 0.785694958, 0.541196100, 0.275899379
};

void ts4_get_u32_off50_883061E0(void); /* jpeg_idct_1x1 */
void fn_88305C08(void);                /* jpeg_idct_2x2 */
void fn_883058D0(void);                /* jpeg_idct_4x4 */
void fn_88305428(void);                /* jpeg_idct_islow */
void fn_88304F98(void);                /* jpeg_idct_ifast */
void fn_88304B48(void);                /* jpeg_idct_float */

enum {
    TS4_JERR_BAD_DCTSIZE = 0x07,
    TS4_JERR_NOT_COMPILED_IDCT = 0x30
};

/* Picks each component's IDCT routine and builds its dequantization multiplier
 * table for that method (Swing_DLL.xex 0x882F8A78). */
void ts4_jpeg_idct_start_pass_882F8A78(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_idct_controller *idct = cinfo->idct;
    int ci, i;
    struct ts4_jpeg_component_info *compptr;
    int method = 0;
    ts4_jpeg_idct_method method_ptr = 0;
    struct ts4_jpeg_quant_tbl *qtbl;

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        switch (compptr->DCT_scaled_size) {
        case 1:
            method_ptr = ts4_get_u32_off50_883061E0;
            method = 0;
            break;
        case 2:
            method_ptr = fn_88305C08;
            method = 0;
            break;
        case 4:
            method_ptr = fn_883058D0;
            method = 0;
            break;
        case 8:
            switch (cinfo->dct_method) {
            case 0:
            case 3:
            case 5:
                method_ptr = fn_88305428;
                method = 0;
                break;
            case 1:
            case 4:
            case 6:
                method_ptr = fn_88304F98;
                method = 1;
                break;
            case 2:
                method_ptr = fn_88304B48;
                method = 2;
                break;
            default:
                JPEG_ERREXIT(cinfo, TS4_JERR_NOT_COMPILED_IDCT);
                break;
            }
            break;
        default:
            JPEG_ERREXIT1(cinfo, TS4_JERR_BAD_DCTSIZE, compptr->DCT_scaled_size);
            break;
        }
        idct->inverse_DCT[ci] = method_ptr;
        if (!compptr->component_needed || idct->cur_method[ci] == method)
            continue;
        qtbl = compptr->quant_table;
        if (qtbl == 0)
            continue;
        idct->cur_method[ci] = method;
        switch (method) {
        case 0: {
            short *ismtbl = (short *)compptr->dct_table;
            for (i = 0; i < 64; i++) {
                ismtbl[i] = (short)qtbl->quantval[i];
            }
        } break;
        case 1: {
            short *ifmtbl = (short *)compptr->dct_table;
            for (i = 0; i < 64; i++) {
                ifmtbl[i] = (short)(((int)qtbl->quantval[i] * (int)lbl_88026AD8[i] + (1 << 11)) >> 12);
            }
        } break;
        case 2: {
            float *fmtbl = (float *)compptr->dct_table;
            int row, col;
            i = 0;
            for (row = 0; row < 8; row++) {
                for (col = 0; col < 8; col++) {
                    fmtbl[i] = (float)((double)qtbl->quantval[i] * lbl_88026B58[row] * lbl_88026B58[col]);
                    i++;
                }
            }
        } break;
        default:
            JPEG_ERREXIT(cinfo, TS4_JERR_NOT_COMPILED_IDCT);
            break;
        }
    }
}
