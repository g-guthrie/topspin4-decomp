/* Loader_DLL.xex 0x83442C20-0x83442F2C, executable version 0.0.0.3. */
/* Library routine: libjpeg read_markers (jdmarker.c). */

#include "l8_jpeg.h"

extern int fn_83442B40(ts4l_jcinfo *cinfo);
extern int fn_834429C0(ts4l_jcinfo *cinfo);
extern int fn_83440F60(ts4l_jcinfo *cinfo);
extern int fn_83441048(ts4l_jcinfo *cinfo, int is_prog, int is_arith);
extern int fn_83441498(ts4l_jcinfo *cinfo);
extern int fn_83441850(ts4l_jcinfo *cinfo);
extern int fn_83441BF0(ts4l_jcinfo *cinfo);
extern int fn_83441F00(ts4l_jcinfo *cinfo);
extern int fn_834428C0(ts4l_jcinfo *cinfo);

int ts4l_jpeg_read_markers_83442C20(ts4l_jcinfo *cinfo)
{
    for (;;) {
        if (cinfo->unread_marker == 0) {
            if (!cinfo->marker->saw_SOI) {
                if (!fn_83442B40(cinfo))
                    return 0;
            } else {
                if (!fn_834429C0(cinfo))
                    return 0;
            }
        }

        switch (cinfo->unread_marker) {
        case 0xD8:
            if (!fn_83440F60(cinfo))
                return 0;
            break;
        case 0xC0:
        case 0xC1:
            if (!fn_83441048(cinfo, 0, 0))
                return 0;
            break;
        case 0xC2:
            if (!fn_83441048(cinfo, 1, 0))
                return 0;
            break;
        case 0xC9:
            if (!fn_83441048(cinfo, 0, 1))
                return 0;
            break;
        case 0xCA:
            if (!fn_83441048(cinfo, 1, 1))
                return 0;
            break;
        case 0xC3:
        case 0xC5:
        case 0xC6:
        case 0xC7:
        case 0xC8:
        case 0xCB:
        case 0xCD:
        case 0xCE:
        case 0xCF:
            TS4L_ERREXIT1(cinfo, 60, cinfo->unread_marker);
            break;
        case 0xDA:
            if (!fn_83441498(cinfo))
                return 0;
            cinfo->unread_marker = 0;
            return 1;
        case 0xD9:
            TS4L_TRACEMS(cinfo, 1, 85);
            cinfo->unread_marker = 0;
            return 2;
        case 0xCC:
            if (!fn_834428C0(cinfo))
                return 0;
            break;
        case 0xC4:
            if (!fn_83441850(cinfo))
                return 0;
            break;
        case 0xDB:
            if (!fn_83441BF0(cinfo))
                return 0;
            break;
        case 0xDD:
            if (!fn_83441F00(cinfo))
                return 0;
            break;
        case 0xE0:
        case 0xE1:
        case 0xE2:
        case 0xE3:
        case 0xE4:
        case 0xE5:
        case 0xE6:
        case 0xE7:
        case 0xE8:
        case 0xE9:
        case 0xEA:
        case 0xEB:
        case 0xEC:
        case 0xED:
        case 0xEE:
        case 0xEF:
            if (!(*cinfo->marker->process_APPn[cinfo->unread_marker - 0xE0])(cinfo))
                return 0;
            break;
        case 0xFE:
            if (!(*cinfo->marker->process_COM)(cinfo))
                return 0;
            break;
        case 0xD0:
        case 0xD1:
        case 0xD2:
        case 0xD3:
        case 0xD4:
        case 0xD5:
        case 0xD6:
        case 0xD7:
        case 0x01:
            TS4L_TRACEMS1(cinfo, 1, 92, cinfo->unread_marker);
            break;
        case 0xDC:
            if (!fn_834428C0(cinfo))
                return 0;
            break;
        default:
            TS4L_ERREXIT1(cinfo, 68, cinfo->unread_marker);
            break;
        }
        cinfo->unread_marker = 0;
    }
}
