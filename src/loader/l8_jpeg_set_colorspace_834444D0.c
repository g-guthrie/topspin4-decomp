/* Loader_DLL.xex 0x834444D0-0x83444850, executable version 0.0.0.3. */
/* Library routine: libjpeg jpeg_set_colorspace (jcparam.c). */

#include "l8_jpeg.h"

typedef struct ts4l_jccinfo {
    ts4l_jerr *err;
    char pad0[0x10];
    int global_state;
    char pad1[0x24 - 0x18];
    int input_components;
    char pad2[0x3c - 0x28];
    int num_components;
    int jpeg_color_space;
    ts4l_jcomp *comp_info;
    char pad3[0xd0 - 0x48];
    int write_JFIF_header;
    char pad4[0xdc - 0xd4];
    int write_Adobe_marker;
    int x_e0;
    int x_e4;
} ts4l_jccinfo;

#define TS4L_SET_COMP(index, id, hsamp, vsamp, quant, dctbl, actbl)                            \
    (compptr = &cinfo->comp_info[index], compptr->component_id = (id),                         \
     compptr->h_samp_factor = (hsamp), compptr->v_samp_factor = (vsamp),                       \
     compptr->quant_tbl_no = (quant), compptr->dc_tbl_no = (dctbl), compptr->ac_tbl_no = (actbl))

#define TS4L_CERREXIT(cinfo, code) ((cinfo)->err->msg_code = (code), (*(cinfo)->err->error_exit)((ts4l_jcinfo *)(cinfo)))
#define TS4L_CERREXIT1(cinfo, code, p1)                                                        \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm[0] = (p1),                        \
     (*(cinfo)->err->error_exit)((ts4l_jcinfo *)(cinfo)))
#define TS4L_CERREXIT2(cinfo, code, p1, p2)                                                    \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm[0] = (p1),                        \
     (cinfo)->err->msg_parm[1] = (p2), (*(cinfo)->err->error_exit)((ts4l_jcinfo *)(cinfo)))

void ts4l_jpeg_set_colorspace_834444D0(ts4l_jccinfo *cinfo, int colorspace)
{
    ts4l_jcomp *compptr;
    int ci;

    if (cinfo->global_state != 100)
        TS4L_CERREXIT1(cinfo, 20, cinfo->global_state);

    cinfo->jpeg_color_space = colorspace;
    cinfo->write_JFIF_header = 0;
    cinfo->write_Adobe_marker = 0;
    cinfo->x_e0 = 1;
    cinfo->x_e4 = 1;

    switch (colorspace) {
    case 1:
        cinfo->write_JFIF_header = 1;
        cinfo->num_components = 1;
        TS4L_SET_COMP(0, 1, 1, 1, 0, 0, 0);
        break;
    case 2:
        cinfo->write_Adobe_marker = 1;
        cinfo->num_components = 3;
        TS4L_SET_COMP(0, 0x52, 1, 1, 0, 0, 0);
        TS4L_SET_COMP(1, 0x47, 1, 1, 0, 0, 0);
        TS4L_SET_COMP(2, 0x42, 1, 1, 0, 0, 0);
        break;
    case 3:
        cinfo->write_JFIF_header = 1;
        cinfo->num_components = 3;
        TS4L_SET_COMP(0, 1, 2, 2, 0, 0, 0);
        TS4L_SET_COMP(1, 2, 1, 1, 1, 1, 1);
        TS4L_SET_COMP(2, 3, 1, 1, 1, 1, 1);
        break;
    case 4:
        cinfo->write_Adobe_marker = 1;
        cinfo->num_components = 4;
        TS4L_SET_COMP(0, 0x43, 1, 1, 0, 0, 0);
        TS4L_SET_COMP(1, 0x4D, 1, 1, 0, 0, 0);
        TS4L_SET_COMP(2, 0x59, 1, 1, 0, 0, 0);
        TS4L_SET_COMP(3, 0x4B, 1, 1, 0, 0, 0);
        break;
    case 5:
        cinfo->write_Adobe_marker = 1;
        cinfo->num_components = 4;
        TS4L_SET_COMP(0, 1, 2, 2, 0, 0, 0);
        TS4L_SET_COMP(1, 2, 1, 1, 1, 1, 1);
        TS4L_SET_COMP(2, 3, 1, 1, 1, 1, 1);
        TS4L_SET_COMP(3, 4, 2, 2, 0, 0, 0);
        break;
    case 0:
        cinfo->num_components = cinfo->input_components;
        if (cinfo->num_components < 1 || cinfo->num_components > 10)
            TS4L_CERREXIT2(cinfo, 26, cinfo->num_components, 10);
        for (ci = 0; ci < cinfo->num_components; ci++) {
            TS4L_SET_COMP(ci, ci, 1, 1, 0, 0, 0);
        }
        break;
    default:
        TS4L_CERREXIT(cinfo, 10);
    }
}
