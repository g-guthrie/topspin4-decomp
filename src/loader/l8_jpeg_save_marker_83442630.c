/* Loader_DLL.xex 0x83442630-0x834428C0, executable version 0.0.0.3. */
/* Library routine: libjpeg save_marker (jdmarker.c). */

#include "l8_jpeg.h"

extern void fn_83442378(ts4l_jcinfo *cinfo, ts4l_joctet *data, unsigned int datalen, int remaining);
extern void fn_83442068(ts4l_jcinfo *cinfo, ts4l_joctet *data, unsigned int datalen, int remaining);

int ts4l_jpeg_save_marker_83442630(ts4l_jcinfo *cinfo)
{
    ts4l_jmarker *marker = cinfo->marker;
    ts4l_jsaved *cur_marker = marker->cur_marker;
    unsigned int bytes_read, data_length;
    ts4l_joctet *data;
    int length = 0;
    TS4L_INPUT_VARS(cinfo);

    if (cur_marker == 0) {
        TS4L_INPUT_2BYTES(cinfo, length, return 0);
        length -= 2;
        if (length >= 0) {
            unsigned int limit;
            if (cinfo->unread_marker == 0xFE)
                limit = marker->length_limit_COM;
            else
                limit = marker->length_limit_APPn[cinfo->unread_marker - 0xE0];
            if ((unsigned int)length < limit)
                limit = (unsigned int)length;
            cur_marker = (ts4l_jsaved *)(*cinfo->mem->alloc_large)(cinfo, 1,
                                                                    sizeof(ts4l_jsaved) + limit);
            cur_marker->next = 0;
            cur_marker->marker = (ts4l_u8)cinfo->unread_marker;
            cur_marker->original_length = (unsigned int)length;
            cur_marker->data_length = limit;
            data = cur_marker->data = (ts4l_joctet *)(cur_marker + 1);
            marker->cur_marker = cur_marker;
            marker->bytes_read = 0;
            bytes_read = 0;
            data_length = limit;
        } else {
            bytes_read = data_length = 0;
            data = 0;
        }
    } else {
        bytes_read = marker->bytes_read;
        data_length = cur_marker->data_length;
        data = cur_marker->data + bytes_read;
    }

    while (bytes_read < data_length) {
        TS4L_INPUT_SYNC(cinfo);
        marker->bytes_read = bytes_read;
        TS4L_MAKE_BYTE_AVAIL(cinfo, return 0);
        while (bytes_read < data_length && bytes_in_buffer > 0) {
            *data++ = *next_input_byte++;
            bytes_in_buffer--;
            bytes_read++;
        }
    }

    if (cur_marker != 0) {
        if (cinfo->marker_list == 0) {
            cinfo->marker_list = cur_marker;
        } else {
            ts4l_jsaved *prev = cinfo->marker_list;
            while (prev->next != 0)
                prev = prev->next;
            prev->next = cur_marker;
        }
        data = cur_marker->data;
        length = cur_marker->original_length - data_length;
    }
    marker->cur_marker = 0;

    switch (cinfo->unread_marker) {
    case 0xE0:
        fn_83442068(cinfo, data, data_length, length);
        break;
    case 0xEE:
        fn_83442378(cinfo, data, data_length, length);
        break;
    default:
        TS4L_TRACEMS2(cinfo, 1, 91, cinfo->unread_marker, (int)(data_length + length));
        break;
    }

    TS4L_INPUT_SYNC(cinfo);
    if (length > 0)
        (*cinfo->src->skip_input_data)(cinfo, (long)length);
    return 1;
}
