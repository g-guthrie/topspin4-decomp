/* Loader_DLL.xex 0x8345F9F8-0x8345FF08, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcdctmgr.c): forward_DCT. */
#include "l44_jpeg.h"

struct ts4l_fdct_ctl {
    void *start_pass;                  /* 0x00 */
    void *forward_DCT;                 /* 0x04 */
    void (*do_dct)(short *data);       /* 0x08 */
    short *divisors[4];                /* 0x0c */
    void *do_float_dct;                /* 0x1c */
    float *float_divisors[4];          /* 0x20 */
};

#define DIVIDE_BY(a, b) if (a >= b) a /= b; else a = 0

void ts4l_jpeg_forward_DCT_8345F9F8(struct ts4l_jcomp *cinfo, struct ts4l_jpeg_component_info *compptr,
                                   unsigned char **sample_data, short *coef_blocks, unsigned int start_row,
                                   unsigned int start_col, unsigned int num_blocks)
{
    struct ts4l_fdct_ctl *fdct = (struct ts4l_fdct_ctl *)cinfo->fdct;
    void (*do_dct)(short *data) = fdct->do_dct;
    short *divisors = fdct->divisors[compptr->quant_tbl_no];
    short workspace[64];
    unsigned int bi;

    sample_data += start_row;

    for (bi = 0; bi < num_blocks; bi++, start_col += 8) {
        {
            short *workspaceptr;
            unsigned char *elemptr;
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
            short *output_ptr = coef_blocks + bi * 64;

            for (i = 0; i < 64; i++) {
                qval = divisors[i];
                temp = workspace[i];
                if (temp < 0) {
                    temp = -temp;
                    temp += qval >> 1;
                    DIVIDE_BY(temp, qval);
                    temp = -temp;
                } else {
                    temp += qval >> 1;
                    DIVIDE_BY(temp, qval);
                }
                output_ptr[i] = temp;
            }
        }
    }
}
