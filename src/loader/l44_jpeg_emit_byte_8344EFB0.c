/* Loader_DLL.xex 0x8344EFB0-0x8344F038, executable version 0.0.0.3. */
/* Library routine: libjpeg jcmarker.c emit_byte. */
#include "l44_jpeg.h"

void ts4l_jpeg_emit_byte_8344EFB0(struct ts4l_jcomp *cinfo, int val)
{
    struct ts4l_jcdest *dest = cinfo->dest;

    *(dest->next_output_byte)++ = (unsigned char)val;
    if (--dest->free_in_buffer == 0) {
        if (!(*dest->empty_output_buffer)(cinfo))
            TS4L_CERREXIT(cinfo, 24);
    }
}
