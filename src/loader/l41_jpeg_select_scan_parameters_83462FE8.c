/* Loader_DLL.xex 0x83462FE8-0x83463130, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcmaster.c): select_scan_parameters. */
struct ts4l_compress_struct;
typedef struct ts4l_error_mgr {
    void (*error_exit)(struct ts4l_compress_struct *cinfo);
    char pad4[0x10];
    int msg_code;
    int msg_parm[2];
} ts4l_error_mgr;
typedef struct ts4l_component_info {
    char pad[0x54];
} ts4l_component_info;
typedef struct ts4l_scan_info {
    int comps_in_scan;
    int component_index[4];
    int Ss, Se;
    int Ah, Al;
} ts4l_scan_info;
typedef struct ts4l_master {
    char pad[0x20];
    int scan_number;
} ts4l_master;
typedef struct ts4l_compress_struct {
    ts4l_error_mgr *err;
    char pad4[0x3c - 0x04];
    int num_components;
    char pad40[4];
    ts4l_component_info *comp_info;
    char pad48[0xac - 0x48];
    const ts4l_scan_info *scan_info;
    char padb0[0xfc - 0xb0];
    int comps_in_scan;
    ts4l_component_info *cur_comp_info[4];
    char pad110[0x144 - 0x110];
    int Ss, Se, Ah, Al;
    ts4l_master *master;
} ts4l_compress_struct;

void ts4l_jpeg_select_scan_parameters_83462FE8(ts4l_compress_struct *cinfo)
{
    int ci;

    if (cinfo->scan_info != 0) {
        ts4l_master *master = cinfo->master;
        const ts4l_scan_info *scanptr = cinfo->scan_info + master->scan_number;

        cinfo->comps_in_scan = scanptr->comps_in_scan;
        for (ci = 0; ci < scanptr->comps_in_scan; ci++) {
            cinfo->cur_comp_info[ci] = &cinfo->comp_info[scanptr->component_index[ci]];
        }
        cinfo->Ss = scanptr->Ss;
        cinfo->Se = scanptr->Se;
        cinfo->Ah = scanptr->Ah;
        cinfo->Al = scanptr->Al;
    } else {
        if (cinfo->num_components > 4) {
            cinfo->err->msg_code = 26;
            cinfo->err->msg_parm[0] = cinfo->num_components;
            cinfo->err->msg_parm[1] = 4;
            (*cinfo->err->error_exit)(cinfo);
        }
        cinfo->comps_in_scan = cinfo->num_components;
        for (ci = 0; ci < cinfo->num_components; ci++) {
            cinfo->cur_comp_info[ci] = &cinfo->comp_info[ci];
        }
        cinfo->Ss = 0;
        cinfo->Se = 63;
        cinfo->Ah = 0;
        cinfo->Al = 0;
    }
}
