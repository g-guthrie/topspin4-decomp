/* Loader_DLL.xex 0x83443A80-0x83443D80, executable version 0.0.0.3. */
/* Library routines: libjpeg jcapimin.c (jpeg_write_marker, jpeg_start_compress). */
#include "l44_jpeg.h"

extern void ts4l_loop_get_u32_off48_83443860(struct ts4l_jcomp *cinfo, int suppress);
extern void ts4l_jpeg_jinit_compress_master_83450500(struct ts4l_jcomp *cinfo);

void ts4l_jpeg_write_marker_83443A80(struct ts4l_jcomp *cinfo, int marker, const unsigned char *dataptr,
                                     unsigned int datalen)
{
    void (*write_marker_byte)(struct ts4l_jcomp *info, int val);

    if (cinfo->next_scanline != 0 ||
        (cinfo->global_state != 101 && cinfo->global_state != 102 && cinfo->global_state != 103))
        TS4L_CERREXIT1(cinfo, 20, cinfo->global_state);

    (*cinfo->marker->write_marker_header)(cinfo, marker, datalen);
    write_marker_byte = cinfo->marker->write_marker_byte;

    while (datalen--) {
        (*write_marker_byte)(cinfo, *dataptr);
        dataptr++;
    }
}

void ts4l_jpeg_start_compress_83443CA0(struct ts4l_jcomp *cinfo, int write_all_tables)
{
    if (cinfo->global_state != 100)
        TS4L_CERREXIT1(cinfo, 20, cinfo->global_state);

    if (write_all_tables)
        ts4l_loop_get_u32_off48_83443860(cinfo, 0);

    (*cinfo->err->reset_error_mgr)(cinfo);
    (*cinfo->dest->init_destination)(cinfo);
    ts4l_jpeg_jinit_compress_master_83450500(cinfo);
    (*cinfo->master->prepare_for_pass)(cinfo);
    cinfo->next_scanline = 0;
    cinfo->global_state = (cinfo->raw_data_in ? 102 : 101);
}
