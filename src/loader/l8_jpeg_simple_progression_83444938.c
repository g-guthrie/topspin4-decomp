/* Loader_DLL.xex 0x83444938-0x83444C5C, executable version 0.0.0.3. */
/* Library routine: libjpeg jpeg_simple_progression (jcparam.c). */

typedef struct ts4l_jscan {
    int comps_in_scan;
    int component_index[4];
    int Ss, Se, Ah, Al;
} ts4l_jscan;

typedef struct ts4l_jcinfo ts4l_jcinfo;

typedef struct ts4l_jerr {
    void (*error_exit)(ts4l_jcinfo *cinfo);
    void (*emit_message)(ts4l_jcinfo *cinfo, int level);
    char pad0[0xc];
    int msg_code;
    int msg_parm[8];
} ts4l_jerr;

typedef struct ts4l_jmem {
    void *(*alloc_small)(ts4l_jcinfo *cinfo, int pool, unsigned int size);
} ts4l_jmem;

struct ts4l_jcinfo {
    ts4l_jerr *err;
    ts4l_jmem *mem;
    char pad0[0xc];
    int global_state;
    char pad1[0x3c - 0x18];
    int num_components;
    int jpeg_color_space;
    char pad2[0xa8 - 0x44];
    int num_scans;
    ts4l_jscan *scan_info;
    char pad3[0x178 - 0xb0];
    ts4l_jscan *script_space;
    int script_space_size;
};


static ts4l_jscan *ts4l_fill_a_scan(ts4l_jscan *scanptr, int ci, int Ss, int Se, int Ah, int Al)
{
    scanptr->comps_in_scan = 1;
    scanptr->component_index[0] = ci;
    scanptr->Ss = Ss;
    scanptr->Se = Se;
    scanptr->Ah = Ah;
    scanptr->Al = Al;
    scanptr++;
    return scanptr;
}

static ts4l_jscan *ts4l_fill_scans(ts4l_jscan *scanptr, int ncomps, int Ss, int Se, int Ah, int Al)
{
    int ci;

    for (ci = 0; ci < ncomps; ci++) {
        scanptr->comps_in_scan = 1;
        scanptr->component_index[0] = ci;
        scanptr->Ss = Ss;
        scanptr->Se = Se;
        scanptr->Ah = Ah;
        scanptr->Al = Al;
        scanptr++;
    }
    return scanptr;
}

#ifdef _MSC_VER
__declspec(noinline)
#endif
ts4l_jscan *ts4l_jpeg_fill_dc_scans_834448B8(ts4l_jscan *scanptr, int ncomps, int Ah, int Al)
{
    int ci;

    if (ncomps <= 4) {
        scanptr->comps_in_scan = ncomps;
        for (ci = 0; ci < ncomps; ci++)
            scanptr->component_index[ci] = ci;
        scanptr->Ss = scanptr->Se = 0;
        scanptr->Ah = Ah;
        scanptr->Al = Al;
        scanptr++;
    } else {
        scanptr = ts4l_fill_scans(scanptr, ncomps, 0, 0, Ah, Al);
    }
    return scanptr;
}

void ts4l_jpeg_simple_progression_83444938(ts4l_jcinfo *cinfo)
{
    int ncomps = cinfo->num_components;
    int nscans;
    ts4l_jscan *scanptr;

    if (cinfo->global_state != 100) {
        cinfo->err->msg_code = 20;
        cinfo->err->msg_parm[0] = cinfo->global_state;
        (*cinfo->err->error_exit)(cinfo);
    }

    if (ncomps == 3 && cinfo->jpeg_color_space == 3) {
        nscans = 10;
    } else {
        if (ncomps > 4)
            nscans = 6 * ncomps;
        else
            nscans = 2 + 4 * ncomps;
    }

    if (cinfo->script_space == 0 || cinfo->script_space_size < nscans) {
        cinfo->script_space_size = nscans > 10 ? nscans : 10;
        cinfo->script_space = (ts4l_jscan *)(*cinfo->mem->alloc_small)(
            cinfo, 0, cinfo->script_space_size * sizeof(ts4l_jscan));
    }
    scanptr = cinfo->script_space;
    cinfo->scan_info = scanptr;
    cinfo->num_scans = nscans;

    if (ncomps == 3 && cinfo->jpeg_color_space == 3) {
        scanptr = ts4l_jpeg_fill_dc_scans_834448B8(scanptr, ncomps, 0, 1);
        scanptr = ts4l_fill_a_scan(scanptr, 0, 1, 5, 0, 2);
        scanptr = ts4l_fill_a_scan(scanptr, 2, 1, 63, 0, 1);
        scanptr = ts4l_fill_a_scan(scanptr, 1, 1, 63, 0, 1);
        scanptr = ts4l_fill_a_scan(scanptr, 0, 6, 63, 0, 2);
        scanptr = ts4l_fill_a_scan(scanptr, 0, 1, 63, 2, 1);
        scanptr = ts4l_jpeg_fill_dc_scans_834448B8(scanptr, ncomps, 1, 0);
        scanptr = ts4l_fill_a_scan(scanptr, 2, 1, 63, 1, 0);
        scanptr = ts4l_fill_a_scan(scanptr, 1, 1, 63, 1, 0);
        scanptr = ts4l_fill_a_scan(scanptr, 0, 1, 63, 1, 0);
    } else {
        scanptr = ts4l_jpeg_fill_dc_scans_834448B8(scanptr, ncomps, 0, 1);
        scanptr = ts4l_fill_scans(scanptr, ncomps, 1, 5, 0, 2);
        scanptr = ts4l_fill_scans(scanptr, ncomps, 6, 63, 0, 2);
        scanptr = ts4l_fill_scans(scanptr, ncomps, 1, 63, 2, 1);
        scanptr = ts4l_jpeg_fill_dc_scans_834448B8(scanptr, ncomps, 1, 0);
        scanptr = ts4l_fill_scans(scanptr, ncomps, 1, 63, 1, 0);
    }
}
