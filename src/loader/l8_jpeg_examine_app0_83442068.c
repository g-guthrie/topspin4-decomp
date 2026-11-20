/* Loader_DLL.xex 0x83442068-0x83442378, executable version 0.0.0.3. */
/* Library routine: libjpeg examine_app0 (jdmarker.c, JFIF / JFXX APP0). */

#include "l8_jpeg.h"

void ts4l_jpeg_examine_app0_83442068(ts4l_jcinfo *cinfo, ts4l_joctet *data, unsigned int datalen,
                                     int remaining)
{
    int totallen = (int)datalen + remaining;

    if (datalen >= 14 && data[0] == 0x4A && data[1] == 0x46 && data[2] == 0x49 &&
        data[3] == 0x46 && data[4] == 0) {
        cinfo->saw_JFIF_marker = 1;
        cinfo->JFIF_major_version = data[5];
        cinfo->JFIF_minor_version = data[6];
        cinfo->density_unit = data[7];
        cinfo->X_density = (data[8] << 8) + data[9];
        cinfo->Y_density = (data[10] << 8) + data[11];

        if (cinfo->JFIF_major_version != 1)
            TS4L_WARNMS2(cinfo, 119, cinfo->JFIF_major_version, cinfo->JFIF_minor_version);

        TS4L_TRACEMS5(cinfo, 1, 87, cinfo->JFIF_major_version, cinfo->JFIF_minor_version,
                      cinfo->X_density, cinfo->Y_density, cinfo->density_unit);

        if (data[12] | data[13])
            TS4L_TRACEMS2(cinfo, 1, 90, data[12], data[13]);

        totallen -= 14;
        if (totallen != ((int)data[12] * (int)data[13] * (int)3))
            TS4L_TRACEMS1(cinfo, 1, 88, (int)totallen);
    } else if (datalen >= 6 && data[0] == 0x4A && data[1] == 0x46 && data[2] == 0x58 &&
               data[3] == 0x58 && data[4] == 0) {
        switch (data[5]) {
        case 0x10:
            TS4L_TRACEMS1(cinfo, 1, 108, (int)totallen);
            break;
        case 0x11:
            TS4L_TRACEMS1(cinfo, 1, 109, (int)totallen);
            break;
        case 0x13:
            TS4L_TRACEMS1(cinfo, 1, 110, (int)totallen);
            break;
        default:
            TS4L_TRACEMS2(cinfo, 1, 89, data[5], (int)totallen);
            break;
        }
    } else {
        TS4L_TRACEMS1(cinfo, 1, 77, (int)totallen);
    }
}
