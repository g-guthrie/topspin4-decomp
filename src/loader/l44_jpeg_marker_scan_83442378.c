/* Loader_DLL.xex 0x83442378-0x83442C20, 0x83443018-0x8344316C, executable version 0.0.0.3. */
/* Library routines: libjpeg jdmarker.c (examine_app14, get_interesting_appn,
   skip_variable, next_marker, first_marker, jpeg_resync_to_restart). */
#include "l21_jp1_jpeg_8344E498.h"

extern int ts4l_jpeg_examine_app0_83442068(struct ts4l_jpeg_decomp *cinfo, unsigned char *data, unsigned int datalen,
                       int remaining);

#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4l_jpeg_examine_app14_83442378(struct ts4l_jpeg_decomp *cinfo, unsigned char *data,
                                      unsigned int datalen, int remaining)
{
    unsigned int version, flags0, flags1, transform;

    if (datalen >= 12 && data[0] == 0x41 && data[1] == 0x64 && data[2] == 0x6F && data[3] == 0x62 &&
        data[4] == 0x65) {
        version = (data[5] << 8) + data[6];
        flags0 = (data[7] << 8) + data[8];
        flags1 = (data[9] << 8) + data[10];
        transform = data[11];
        TS4L_TRACEMS4(cinfo, 1, 76, version, flags0, flags1, transform);
        cinfo->saw_Adobe_marker = 1;
        cinfo->Adobe_transform = (unsigned char)transform;
    } else {
        TS4L_TRACEMS1(cinfo, 1, 78, (int)(datalen + remaining));
    }
}

#ifdef _MSC_VER
__declspec(noinline)
#endif
int ts4l_jpeg_get_interesting_appn_83442488(struct ts4l_jpeg_decomp *cinfo)
{
    int length;
    unsigned int i;
    unsigned int numtoread;
    unsigned char b[14];
    TS4L_INPUT_VARS(cinfo);

    TS4L_INPUT_2BYTES(cinfo, length, return 0);
    length -= 2;

    if (length >= 14)
        numtoread = 14;
    else if (length > 0)
        numtoread = length;
    else
        numtoread = 0;
    for (i = 0; i < numtoread; i++)
        TS4L_INPUT_BYTE(cinfo, b[i], return 0);
    length -= numtoread;

    switch (cinfo->unread_marker) {
    case 0xE0:
        ts4l_jpeg_examine_app0_83442068(cinfo, b, numtoread, length);
        break;
    case 0xEE:
        ts4l_jpeg_examine_app14_83442378(cinfo, b, numtoread, length);
        break;
    default:
        TS4L_ERREXIT1(cinfo, 68, cinfo->unread_marker);
        break;
    }

    TS4L_INPUT_SYNC(cinfo);
    if (length > 0)
        (*cinfo->src->skip_input_data)(cinfo, length);
    return 1;
}

int ts4l_jpeg_skip_variable_834428C0(struct ts4l_jpeg_decomp *cinfo)
{
    int length;
    TS4L_INPUT_VARS(cinfo);

    TS4L_INPUT_2BYTES(cinfo, length, return 0);
    length -= 2;

    TS4L_TRACEMS2(cinfo, 1, 91, cinfo->unread_marker, length);

    TS4L_INPUT_SYNC(cinfo);
    if (length > 0)
        (*cinfo->src->skip_input_data)(cinfo, length);
    return 1;
}

int ts4l_jpeg_next_marker_834429C0(struct ts4l_jpeg_decomp *cinfo)
{
    int c;
    TS4L_INPUT_VARS(cinfo);

    for (;;) {
        TS4L_INPUT_BYTE(cinfo, c, return 0);
        while (c != 0xFF) {
            cinfo->marker->discarded_bytes++;
            TS4L_INPUT_SYNC(cinfo);
            TS4L_INPUT_BYTE(cinfo, c, return 0);
        }
        do {
            TS4L_INPUT_BYTE(cinfo, c, return 0);
        } while (c == 0xFF);
        if (c != 0)
            break;
        cinfo->marker->discarded_bytes += 2;
        TS4L_INPUT_SYNC(cinfo);
    }

    if (cinfo->marker->discarded_bytes != 0) {
        TS4L_WARNMS2(cinfo, 116, cinfo->marker->discarded_bytes, c);
        cinfo->marker->discarded_bytes = 0;
    }

    cinfo->unread_marker = c;
    TS4L_INPUT_SYNC(cinfo);
    return 1;
}

int ts4l_jpeg_first_marker_83442B40(struct ts4l_jpeg_decomp *cinfo)
{
    int c, c2;
    TS4L_INPUT_VARS(cinfo);

    TS4L_INPUT_BYTE(cinfo, c, return 0);
    TS4L_INPUT_BYTE(cinfo, c2, return 0);
    if (c != 0xFF || c2 != 0xD8)
        TS4L_ERREXIT2(cinfo, 53, c, c2);

    cinfo->unread_marker = c2;
    TS4L_INPUT_SYNC(cinfo);
    return 1;
}

int ts4l_jpeg_resync_to_restart_83443018(struct ts4l_jpeg_decomp *cinfo, int desired)
{
    int marker = cinfo->unread_marker;
    int action = 1;

    TS4L_WARNMS2(cinfo, 121, marker, desired);

    for (;;) {
        if (marker < 0xC0)
            action = 2;
        else if (marker < 0xD0 || marker > 0xD7)
            action = 3;
        else {
            if (marker == (0xD0 + ((desired + 1) & 7)))
                action = 3;
            else if (marker == (0xD0 + ((desired + 2) & 7)))
                action = 3;
            else if (marker == (0xD0 + ((desired - 1) & 7)) || marker == (0xD0 + ((desired - 2) & 7)))
                action = 2;
            else
                action = 1;
        }
        TS4L_TRACEMS2(cinfo, 4, 97, marker, action);
        switch (action) {
        case 1:
            cinfo->unread_marker = 0;
            return 1;
        case 2:
            if (!ts4l_jpeg_next_marker_834429C0(cinfo))
                return 0;
            marker = cinfo->unread_marker;
            break;
        case 3:
            return 1;
        }
    }
}
