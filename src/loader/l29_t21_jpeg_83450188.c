/* Loader_DLL.xex 0x83450188-0x8345029C, executable version 0.0.0.3. */
/* libjpeg 6b jcmarker.c: write_scan_header (DHT tables, DRI, SOS). */
typedef struct Ts4lJComp {
    int component_id, component_index, h_samp_factor, v_samp_factor;
    int quant_tbl_no, dc_tbl_no, ac_tbl_no;
} Ts4lJComp;
typedef struct Ts4lJMarker {
    char pad[0x1c];
    unsigned last_restart_interval;
} Ts4lJMarker;
typedef struct Ts4lJCinfo {
    char pad0[0xb4];
    int arith_code;
    char pad1[0xc8 - 0xb8];
    unsigned restart_interval;
    char pad2[0xec - 0xcc];
    int progressive_mode;
    char pad3[0xfc - 0xf0];
    int comps_in_scan;
    Ts4lJComp *cur_comp_info[4];
    char pad4[0x144 - 0x110];
    int Ss;
    int Se;
    int Ah;
    char pad5[0x164 - 0x150];
    Ts4lJMarker *marker;
} Ts4lJCinfo;

extern void ts4l_jpeg_emit_dht_8344F478(Ts4lJCinfo *cinfo, int index, int is_ac);
extern void fn_8344EFB0(Ts4lJCinfo *cinfo, int val);
extern void ts4l_jpeg_emit_sos_8344FA58(Ts4lJCinfo *cinfo);

void ts4l_jpeg_write_scan_header_83450188(Ts4lJCinfo *cinfo)
{
    Ts4lJMarker *marker = cinfo->marker;
    int i, value;
    Ts4lJComp *compptr;

    if (!cinfo->arith_code) {
        for (i = 0; i < cinfo->comps_in_scan; i++) {
            compptr = cinfo->cur_comp_info[i];
            if (cinfo->progressive_mode) {
                if (cinfo->Ss == 0) {
                    if (cinfo->Ah == 0)
                        ts4l_jpeg_emit_dht_8344F478(cinfo, compptr->dc_tbl_no, 0);
                } else {
                    ts4l_jpeg_emit_dht_8344F478(cinfo, compptr->ac_tbl_no, 1);
                }
            } else {
                ts4l_jpeg_emit_dht_8344F478(cinfo, compptr->dc_tbl_no, 0);
                ts4l_jpeg_emit_dht_8344F478(cinfo, compptr->ac_tbl_no, 1);
            }
        }
    }
    if (cinfo->restart_interval != marker->last_restart_interval) {
        fn_8344EFB0(cinfo, 0xff);
        fn_8344EFB0(cinfo, 0xdd);
        fn_8344EFB0(cinfo, 0);
        fn_8344EFB0(cinfo, 4);
        value = (int)cinfo->restart_interval;
        fn_8344EFB0(cinfo, (value >> 8) & 0xFF);
        fn_8344EFB0(cinfo, value & 0xFF);
        marker->last_restart_interval = cinfo->restart_interval;
    }
    ts4l_jpeg_emit_sos_8344FA58(cinfo);
}
