/* Loader_DLL.xex 0x83443198-0x83443428, executable version 0.0.0.3. */
/* Library routines: libjpeg jdmarker.c (jinit_marker_reader, jpeg_save_markers variants). */
#include "l44_jpeg.h"

extern void ts4_get_u32_off1bc_83443170(struct ts4l_jpeg_decomp *cinfo);
extern int ts4l_jpeg_read_markers_83442C20(struct ts4l_jpeg_decomp *cinfo);
extern int fn_83442F30(struct ts4l_jpeg_decomp *cinfo);
extern int fn_834428C0(struct ts4l_jpeg_decomp *cinfo);
extern int fn_83442488(struct ts4l_jpeg_decomp *cinfo);
extern int ts4l_jpeg_save_marker_83442630(struct ts4l_jpeg_decomp *cinfo);

void ts4l_jpeg_jinit_marker_reader_83443198(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_my_marker_reader *marker;
    int i;

    marker = (struct ts4l_my_marker_reader *)(*cinfo->mem->alloc_small)(cinfo, 0, 0xac);
    cinfo->marker = &marker->pub;
    marker->pub.reset_marker_reader = ts4_get_u32_off1bc_83443170;
    marker->pub.read_markers = ts4l_jpeg_read_markers_83442C20;
    marker->pub.read_restart_marker = fn_83442F30;
    marker->pub.process_COM = fn_834428C0;
    marker->length_limit_COM = 0;
    for (i = 0; i < 16; i++) {
        marker->pub.process_APPn[i] = fn_834428C0;
        marker->length_limit_APPn[i] = 0;
    }
    marker->pub.process_APPn[0] = fn_83442488;
    marker->pub.process_APPn[14] = fn_83442488;

    cinfo->comp_info = 0;
    cinfo->input_scan_number = 0;
    cinfo->unread_marker = 0;
    marker = (struct ts4l_my_marker_reader *)cinfo->marker;
    marker->pub.saw_SOI = 0;
    marker->pub.saw_SOF = 0;
    marker->pub.discarded_bytes = 0;
    marker->cur_marker = 0;
}

void ts4l_jpeg_save_markers_83443270(struct ts4l_jpeg_decomp *cinfo, int marker_code,
                                     unsigned int length_limit)
{
    struct ts4l_my_marker_reader *marker = (struct ts4l_my_marker_reader *)cinfo->marker;
    int maxlength;
    ts4l_marker_parser processor;

    maxlength = cinfo->mem->max_alloc_chunk - 20;
    if ((int)length_limit > maxlength)
        length_limit = (unsigned int)maxlength;

    if (length_limit) {
        processor = ts4l_jpeg_save_marker_83442630;
        if (marker_code == 0xE0 && length_limit < 14)
            length_limit = 14;
        else if (marker_code == 0xEE && length_limit < 12)
            length_limit = 12;
    } else {
        processor = fn_834428C0;
        if (marker_code == 0xE0 || marker_code == 0xEE)
            processor = fn_83442488;
    }
    if (marker_code == 0xFE) {
        marker->pub.process_COM = processor;
        marker->length_limit_COM = length_limit;
    } else if (marker_code >= 0xE0 && marker_code <= 0xEF) {
        marker->pub.process_APPn[marker_code - 0xE0] = processor;
        marker->length_limit_APPn[marker_code - 0xE0] = length_limit;
    } else
        TS4L_ERREXIT1(cinfo, 68, marker_code);
}

void ts4l_jpeg_save_markers_83443350(struct ts4l_jpeg_decomp *cinfo, int marker_code,
                                     unsigned int length_limit, ts4l_marker_parser processor)
{
    struct ts4l_my_marker_reader *marker = (struct ts4l_my_marker_reader *)cinfo->marker;
    int maxlength;

    maxlength = cinfo->mem->max_alloc_chunk - 20;
    if ((int)length_limit > maxlength)
        length_limit = (unsigned int)maxlength;

    if (length_limit) {
        if (marker_code == 0xE0 && length_limit < 14)
            length_limit = 14;
        else if (marker_code == 0xEE && length_limit < 12)
            length_limit = 12;
    } else {
        processor = fn_834428C0;
        if (marker_code == 0xE0 || marker_code == 0xEE)
            processor = fn_83442488;
    }
    if (marker_code == 0xFE) {
        marker->pub.process_COM = processor;
        marker->length_limit_COM = length_limit;
    } else if (marker_code >= 0xE0 && marker_code <= 0xEF) {
        marker->pub.process_APPn[marker_code - 0xE0] = processor;
        marker->length_limit_APPn[marker_code - 0xE0] = length_limit;
    } else
        TS4L_ERREXIT1(cinfo, 68, marker_code);
}
