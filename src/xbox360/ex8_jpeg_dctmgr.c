/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libjpeg 6b forward-DCT manager (jcdctmgr.c). */
#include "ex8_jpeg.h"


void fn_882FE210(ex8_jcomp *cinfo); /* start_pass_fdctmgr */
enum { EX8_JERR_NOT_COMPILED = 0x30 };

void ex8_jpeg_fdct_islow_88307368(short *data); /* jpeg_fdct_islow */
void ex8_jpeg_fdct_ifast_88307068(short *data); /* jpeg_fdct_ifast */
void ts4_jpeg_fdct_float_88306220(float *data); /* jpeg_fdct_float */
void fn_882FEB48(ex8_jcomp *cinfo, ex8_jcinfo *compptr, ex8_jsamparray sample_data,
                                    ex8_jblockrow coef_blocks, unsigned int start_row, unsigned int start_col,
                                    unsigned int num_blocks);

typedef struct ex8_fdct_priv {
    ex8_jcfdct pub;               /* 0x00 */
    void (*do_dct)(short *data);  /* 0x08 */
    short *divisors[4];           /* 0x0c */
    void (*do_float_dct)(float *data); /* 0x1c */
    float *float_divisors[4];     /* 0x20 */
} ex8_fdct_priv;

/* Integer forward DCT and quantization of a row of blocks. */
void ex8_forward_DCT_882FE638(ex8_jcomp *cinfo, ex8_jcinfo *compptr, ex8_jsamparray sample_data,
                              ex8_jblockrow coef_blocks, unsigned int start_row, unsigned int start_col,
                              unsigned int num_blocks)
{
    ex8_fdct_priv *fdct = (ex8_fdct_priv *)cinfo->fdct;
    void (*do_dct)(short *data) = fdct->do_dct;
    short *divisors = fdct->divisors[compptr->quant_tbl_no];
    short workspace[64];
    unsigned int bi;

    sample_data += start_row;
    for (bi = 0; bi < num_blocks; bi++, start_col += 8) {
        {
            short *workspaceptr;
            ex8_jsamprow elemptr;
            int elemr;

            workspaceptr = workspace;
            for (elemr = 0; elemr < 8; elemr++) {
                elemptr = sample_data[elemr] + start_col;
                *workspaceptr++ = (short)(*elemptr++ - 128);
                *workspaceptr++ = (short)(*elemptr++ - 128);
                *workspaceptr++ = (short)(*elemptr++ - 128);
                *workspaceptr++ = (short)(*elemptr++ - 128);
                *workspaceptr++ = (short)(*elemptr++ - 128);
                *workspaceptr++ = (short)(*elemptr++ - 128);
                *workspaceptr++ = (short)(*elemptr++ - 128);
                *workspaceptr++ = (short)(*elemptr++ - 128);
            }
        }

        (*do_dct)(workspace);

        {
            short temp, qval;
            int i;
            short *output_ptr = coef_blocks[bi];

            for (i = 0; i < 64; i++) {
                qval = divisors[i];
                temp = workspace[i];
                if (temp < 0) {
                    temp = -temp;
                    temp += qval >> 1;
                    if (temp >= qval)
                        temp /= qval;
                    else
                        temp = 0;
                    temp = -temp;
                } else {
                    temp += qval >> 1;
                    if (temp >= qval)
                        temp /= qval;
                    else
                        temp = 0;
                }
                output_ptr[i] = temp;
            }
        }
    }
}

/* Allocates the forward-DCT manager and selects the DCT routines. */
void ex8_jinit_forward_dct_882FF558(ex8_jcomp *cinfo)
{
    ex8_fdct_priv *fdct;
    int i;

    fdct = (ex8_fdct_priv *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(ex8_fdct_priv));
    cinfo->fdct = &fdct->pub;
    fdct->pub.start_pass = fn_882FE210;

    switch (cinfo->dct_method) {
    case 0:
    case 3:
    case 5:
        fdct->pub.forward_DCT = ex8_forward_DCT_882FE638;
        fdct->do_dct = ex8_jpeg_fdct_islow_88307368;
        break;
    case 1:
    case 4:
    case 6:
        fdct->pub.forward_DCT = ex8_forward_DCT_882FE638;
        fdct->do_dct = ex8_jpeg_fdct_ifast_88307068;
        break;
    case 2:
        fdct->pub.forward_DCT = fn_882FEB48;
        fdct->do_float_dct = ts4_jpeg_fdct_float_88306220;
        break;
    default:
        EX8_ERREXIT(cinfo, EX8_JERR_NOT_COMPILED);
        break;
    }

    for (i = 0; i < 4; i++) {
        fdct->divisors[i] = 0;
        fdct->float_divisors[i] = 0;
    }
}
