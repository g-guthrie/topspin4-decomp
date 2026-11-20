/* Loader_DLL.xex 0x83462898-0x83462B28, 0x83462B28-0x83462FE4, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcmaster.c): initial_setup and validate_script. */
#include "l44_jpeg.h"

struct ts4l_jscan_info {
    int comps_in_scan;       /* 0x00 */
    int component_index[4];  /* 0x04 */
    int Ss;                  /* 0x14 */
    int Se;                  /* 0x18 */
    int Ah;                  /* 0x1c */
    int Al;                  /* 0x20 */
};

extern long ts4l_jpeg_jdiv_round_up_8344EED8(long a, long b);

#define MAXI(a, b) ((a) > (b) ? (a) : (b))

void ts4l_jpeg_initial_setup_83462898(struct ts4l_jcomp *cinfo)
{
    int ci;
    struct ts4l_jpeg_component_info *compptr;
    long samplesperrow;
    unsigned int jd_samplesperrow;

    if (cinfo->image_height <= 0 || cinfo->image_width <= 0 || cinfo->num_components <= 0 ||
        cinfo->input_components <= 0)
        TS4L_CERREXIT(cinfo, 0x20);

    if ((long)cinfo->image_height > 65500L || (long)cinfo->image_width > 65500L)
        TS4L_CERREXIT1(cinfo, 0x29, 65500);

    samplesperrow = (long)cinfo->image_width * (long)cinfo->input_components;
    jd_samplesperrow = (unsigned int)samplesperrow;
    if ((long)jd_samplesperrow != samplesperrow)
        TS4L_CERREXIT(cinfo, 0x2b);

    if (cinfo->data_precision != 8)
        TS4L_CERREXIT1(cinfo, 0xf, cinfo->data_precision);

    if (cinfo->num_components > 10)
        TS4L_CERREXIT2(cinfo, 0x1a, cinfo->num_components, 10);

    cinfo->max_h_samp_factor = 1;
    cinfo->max_v_samp_factor = 1;
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        if (compptr->h_samp_factor <= 0 || compptr->h_samp_factor > 4 || compptr->v_samp_factor <= 0 ||
            compptr->v_samp_factor > 4)
            TS4L_CERREXIT(cinfo, 0x12);
        cinfo->max_h_samp_factor = MAXI(cinfo->max_h_samp_factor, compptr->h_samp_factor);
        cinfo->max_v_samp_factor = MAXI(cinfo->max_v_samp_factor, compptr->v_samp_factor);
    }

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        compptr->component_index = ci;
        compptr->DCT_scaled_size = 8;
        compptr->width_in_blocks = (unsigned int)ts4l_jpeg_jdiv_round_up_8344EED8((long)cinfo->image_width * (long)compptr->h_samp_factor,
                                                             (long)(cinfo->max_h_samp_factor * 8));
        compptr->height_in_blocks = (unsigned int)ts4l_jpeg_jdiv_round_up_8344EED8((long)cinfo->image_height * (long)compptr->v_samp_factor,
                                                              (long)(cinfo->max_v_samp_factor * 8));
        compptr->downsampled_width = (unsigned int)ts4l_jpeg_jdiv_round_up_8344EED8((long)cinfo->image_width * (long)compptr->h_samp_factor,
                                                               (long)cinfo->max_h_samp_factor);
        compptr->downsampled_height = (unsigned int)ts4l_jpeg_jdiv_round_up_8344EED8((long)cinfo->image_height * (long)compptr->v_samp_factor,
                                                                (long)cinfo->max_v_samp_factor);
        compptr->component_needed = 1;
    }

    cinfo->total_iMCU_rows = (unsigned int)ts4l_jpeg_jdiv_round_up_8344EED8((long)cinfo->image_height, (long)(cinfo->max_v_samp_factor * 8));
}

void ts4l_jpeg_validate_script_83462B28(struct ts4l_jcomp *cinfo)
{
    const struct ts4l_jscan_info *scanptr;
    int scanno, ncomps, ci, coefi, thisi;
    int Ss, Se, Ah, Al;
    int component_sent[10];
    int *last_bitpos_ptr;
    int last_bitpos[10][64];

    if (cinfo->num_scans <= 0)
        TS4L_CERREXIT1(cinfo, 0x13, 0);

    scanptr = (const struct ts4l_jscan_info *)cinfo->scan_info;
    if (scanptr->Ss != 0 || scanptr->Se != 63) {
        cinfo->progressive_mode = 1;
        last_bitpos_ptr = &last_bitpos[0][0];
        for (ci = 0; ci < cinfo->num_components; ci++)
            for (coefi = 0; coefi < 64; coefi++)
                *last_bitpos_ptr++ = -1;
    } else {
        cinfo->progressive_mode = 0;
        for (ci = 0; ci < cinfo->num_components; ci++)
            component_sent[ci] = 0;
    }

    for (scanno = 1; scanno <= cinfo->num_scans; scanptr++, scanno++) {
        ncomps = scanptr->comps_in_scan;
        if (ncomps <= 0 || ncomps > 4)
            TS4L_CERREXIT2(cinfo, 0x1a, ncomps, 4);
        for (ci = 0; ci < ncomps; ci++) {
            thisi = scanptr->component_index[ci];
            if (thisi < 0 || thisi >= cinfo->num_components)
                TS4L_CERREXIT1(cinfo, 0x13, scanno);
            if (ci > 0 && thisi <= scanptr->component_index[ci - 1])
                TS4L_CERREXIT1(cinfo, 0x13, scanno);
        }
        Ss = scanptr->Ss;
        Se = scanptr->Se;
        Ah = scanptr->Ah;
        Al = scanptr->Al;
        if (cinfo->progressive_mode) {
            if (Ss < 0 || Ss >= 64 || Se < Ss || Se >= 64 || Ah < 0 || Ah > 10 || Al < 0 || Al > 10)
                TS4L_CERREXIT1(cinfo, 0x11, scanno);
            if (Ss == 0) {
                if (Se != 0)
                    TS4L_CERREXIT1(cinfo, 0x11, scanno);
            } else {
                if (ncomps != 1)
                    TS4L_CERREXIT1(cinfo, 0x11, scanno);
            }
            for (ci = 0; ci < ncomps; ci++) {
                last_bitpos_ptr = &last_bitpos[scanptr->component_index[ci]][0];
                if (Ss != 0 && last_bitpos_ptr[0] < 0)
                    TS4L_CERREXIT1(cinfo, 0x11, scanno);
                for (coefi = Ss; coefi <= Se; coefi++) {
                    if (last_bitpos_ptr[coefi] < 0) {
                        if (Ah != 0)
                            TS4L_CERREXIT1(cinfo, 0x11, scanno);
                    } else {
                        if (Ah != last_bitpos_ptr[coefi] || Al != Ah - 1)
                            TS4L_CERREXIT1(cinfo, 0x11, scanno);
                    }
                    last_bitpos_ptr[coefi] = Al;
                }
            }
        } else {
            if (Ss != 0 || Se != 63 || Ah != 0 || Al != 0)
                TS4L_CERREXIT1(cinfo, 0x11, scanno);
            for (ci = 0; ci < ncomps; ci++) {
                thisi = scanptr->component_index[ci];
                if (component_sent[thisi])
                    TS4L_CERREXIT1(cinfo, 0x13, scanno);
                component_sent[thisi] = 1;
            }
        }
    }

    if (cinfo->progressive_mode) {
        for (ci = 0; ci < cinfo->num_components; ci++) {
            if (last_bitpos[ci][0] < 0)
                TS4L_CERREXIT(cinfo, 0x2d);
        }
    } else {
        for (ci = 0; ci < cinfo->num_components; ci++) {
            if (!component_sent[ci])
                TS4L_CERREXIT(cinfo, 0x2d);
        }
    }
}
