/* Loader_DLL.xex 0x83463340-0x834635E4, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcmaster.c): prepare_for_pass. */
#include "l44_jpeg.h"

struct ts4l_cstage {
    void (*start_pass)(struct ts4l_jcomp *cinfo, int mode);
};

struct ts4l_cstage0 {
    void (*start_pass)(struct ts4l_jcomp *cinfo);
};

extern void ts4l_jpeg_select_scan_parameters_83462FE8(struct ts4l_jcomp *cinfo);
extern void fn_83463130(struct ts4l_jcomp *cinfo);

void ts4l_jpeg_prepare_for_pass_83463340(struct ts4l_jcomp *cinfo)
{
    struct ts4l_jcmaster *master = cinfo->master;

    switch (master->pass_type) {
    case 0:
        ts4l_jpeg_select_scan_parameters_83462FE8(cinfo);
        fn_83463130(cinfo);
        if (!cinfo->raw_data_in) {
            (*((struct ts4l_cstage0 *)cinfo->cconvert)->start_pass)(cinfo);
            (*((struct ts4l_cstage0 *)cinfo->downsample)->start_pass)(cinfo);
            (*((struct ts4l_cstage *)cinfo->prep)->start_pass)(cinfo, 0);
        }
        (*((struct ts4l_cstage0 *)cinfo->fdct)->start_pass)(cinfo);
        (*((struct ts4l_cstage *)cinfo->entropy)->start_pass)(cinfo, cinfo->optimize_coding);
        (*cinfo->coef->start_pass)(cinfo, (master->total_passes > 1 ? 3 : 0));
        (*((struct ts4l_cstage *)cinfo->main)->start_pass)(cinfo, 0);
        if (cinfo->optimize_coding)
            master->call_pass_startup = 0;
        else
            master->call_pass_startup = 1;
        break;
    case 1:
        ts4l_jpeg_select_scan_parameters_83462FE8(cinfo);
        fn_83463130(cinfo);
        if (cinfo->Ss != 0 || cinfo->Ah == 0 || cinfo->arith_code) {
            (*((struct ts4l_cstage *)cinfo->entropy)->start_pass)(cinfo, 1);
            (*cinfo->coef->start_pass)(cinfo, 2);
            master->call_pass_startup = 0;
            break;
        }
        master->pass_type = 2;
        master->pass_number++;
        /* fall through */
    case 2:
        if (!cinfo->optimize_coding) {
            ts4l_jpeg_select_scan_parameters_83462FE8(cinfo);
            fn_83463130(cinfo);
        }
        (*((struct ts4l_cstage *)cinfo->entropy)->start_pass)(cinfo, 0);
        (*cinfo->coef->start_pass)(cinfo, 2);
        if (master->scan_number == 0)
            (*cinfo->marker->write_frame_header)(cinfo);
        (*cinfo->marker->write_scan_header)(cinfo);
        master->call_pass_startup = 0;
        break;
    default:
        TS4L_CERREXIT(cinfo, 0x30);
    }

    master->is_last_pass = (master->pass_number == master->total_passes - 1);

    if (cinfo->progress != 0) {
        cinfo->progress->completed_passes = master->pass_number;
        cinfo->progress->total_passes = master->total_passes;
    }
}
