/* Loader_DLL.xex 0x83441850-0x83441BEC, executable version 0.0.0.3. */
/* Library routine: libjpeg get_dht (jdmarker.c). */

#include "l8_jpeg.h"

extern void *fn_8344E390(ts4l_jcinfo *cinfo);
#ifdef _MSC_VER
void *memcpy(void *, const void *, unsigned int);
#pragma intrinsic(memcpy)
#else
#include <string.h>
#endif

int ts4l_jpeg_get_dht_83441850(ts4l_jcinfo *cinfo)
{
    ts4l_u8 bits[17];
    ts4l_u8 huffval[256];
    int length;
    int i;
    int index;
    int count;
    void **htblptr;
    ts4l_jsrc *datasrc = cinfo->src;
    const ts4l_joctet *next_input_byte = datasrc->next_input_byte;
    unsigned int bytes_in_buffer = datasrc->bytes_in_buffer;

    TS4L_INPUT_2BYTES(cinfo, length, return 0);
    length -= 2;

    while (length > 16) {
        TS4L_INPUT_BYTE(cinfo, index, return 0);

        TS4L_TRACEMS1(cinfo, 1, 80, index);

        bits[0] = 0;
        count = 0;
        for (i = 1; i <= 16; i++) {
            TS4L_INPUT_BYTE(cinfo, bits[i], return 0);
            count += bits[i];
        }

        length -= 1 + 16;

        TS4L_TRACEMS8(cinfo, 2, 86, bits[1], bits[2], bits[3], bits[4], bits[5], bits[6],
                      bits[7], bits[8]);
        TS4L_TRACEMS8(cinfo, 2, 86, bits[9], bits[10], bits[11], bits[12], bits[13], bits[14],
                      bits[15], bits[16]);

        if (count > 256 || ((int)count) > length)
            TS4L_ERREXIT(cinfo, 8);

        for (i = 0; i < count; i++)
            TS4L_INPUT_BYTE(cinfo, huffval[i], return 0);

        length -= count;

        if (index & 0x10) {
            index -= 0x10;
            htblptr = &cinfo->ac_huff_tbl_ptrs[index];
        } else {
            htblptr = &cinfo->dc_huff_tbl_ptrs[index];
        }

        if (index < 0 || index >= 4)
            TS4L_ERREXIT1(cinfo, 30, index);

        if (*htblptr == 0)
            *htblptr = fn_8344E390(cinfo);

        memcpy(*htblptr, bits, 17);
        memcpy((ts4l_u8 *)*htblptr + 17, huffval, 256);
    }

    if (length != 0)
        TS4L_ERREXIT(cinfo, 11);

    TS4L_INPUT_SYNC(cinfo);
    return 1;
}
