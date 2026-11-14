/* Loader_DLL.xex 0x8345D608-0x8345D778, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jchuff.c): htest_one_block. */
struct ts4l_compress_struct;
typedef struct ts4l_error_mgr {
    void (*error_exit)(struct ts4l_compress_struct *cinfo);
    char pad4[0x10];
    int msg_code;
} ts4l_error_mgr;
typedef struct ts4l_compress_struct {
    ts4l_error_mgr *err;
} ts4l_compress_struct;

extern const int lbl_8307A868[64];

void ts4l_jpeg_htest_one_block_8345D608(ts4l_compress_struct *cinfo, short *block, int last_dc_val,
                                        long dc_counts[], long ac_counts[])
{
    int temp;
    int nbits;
    int k, r;

    temp = block[0] - last_dc_val;
    if (temp < 0)
        temp = -temp;
    nbits = 0;
    while (temp) {
        nbits++;
        temp >>= 1;
    }
    if (nbits > 11) {
        cinfo->err->msg_code = 6;
        (*cinfo->err->error_exit)(cinfo);
    }
    dc_counts[nbits]++;

    r = 0;
    for (k = 1; k < 64; k++) {
        if ((temp = block[lbl_8307A868[k]]) == 0) {
            r++;
        } else {
            while (r > 15) {
                ac_counts[0xF0]++;
                r -= 16;
            }
            if (temp < 0)
                temp = -temp;
            nbits = 1;
            while ((temp >>= 1))
                nbits++;
            if (nbits > 10) {
                cinfo->err->msg_code = 6;
                (*cinfo->err->error_exit)(cinfo);
            }
            ac_counts[(r << 4) + nbits]++;
            r = 0;
        }
    }
    if (r > 0)
        ac_counts[0]++;
}
