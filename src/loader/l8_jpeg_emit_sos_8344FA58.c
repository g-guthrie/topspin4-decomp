/* Loader_DLL.xex 0x8344FA58-0x8344FD18, executable version 0.0.0.3. */
/* Library routine: libjpeg emit_sos (jcmarker.c); the header bytes go through the
   out-of-line emit_byte, the per-component bytes are inlined. */

typedef unsigned char ts4l_u8;

typedef struct ts4l_cinfo ts4l_cinfo;

typedef struct ts4l_cerr {
    void (*error_exit)(ts4l_cinfo *cinfo);
    void (*emit_message)(ts4l_cinfo *cinfo, int level);
    char pad0[0xc];
    int msg_code;
    int msg_parm[8];
} ts4l_cerr;

typedef struct ts4l_cdest {
    ts4l_u8 *next_output_byte;
    unsigned int free_in_buffer;
    void (*init_destination)(ts4l_cinfo *cinfo);
    int (*empty_output_buffer)(ts4l_cinfo *cinfo);
} ts4l_cdest;

typedef struct ts4l_ccomp {
    int component_id;
    int component_index;
    int h_samp_factor;
    int v_samp_factor;
    int quant_tbl_no;
    int dc_tbl_no;
    int ac_tbl_no;
} ts4l_ccomp;

struct ts4l_cinfo {
    ts4l_cerr *err;
    char pad0[0x14];
    ts4l_cdest *dest;
    char pad1[0xb4 - 0x1c];
    int arith_code;
    char pad2[0xec - 0xb8];
    int progressive_mode;
    char pad3[0xfc - 0xf0];
    int comps_in_scan;
    ts4l_ccomp *cur_comp_info[4];
    char pad4[0x144 - 0x110];
    int Ss;
    int Se;
    int Ah;
    int Al;
};

extern void fn_8344EFB0(ts4l_cinfo *cinfo, int val);

static void ts4l_emit_byte(ts4l_cinfo *cinfo, int val)
{
    ts4l_cdest *dest = cinfo->dest;

    *(dest->next_output_byte)++ = (ts4l_u8)val;
    if (--dest->free_in_buffer == 0) {
        if (!(*dest->empty_output_buffer)(cinfo)) {
            cinfo->err->msg_code = 24;
            (*cinfo->err->error_exit)(cinfo);
        }
    }
}

static void ts4l_emit_marker(ts4l_cinfo *cinfo, int mark)
{
    fn_8344EFB0(cinfo, 0xFF);
    fn_8344EFB0(cinfo, mark);
}

static void ts4l_emit_2bytes(ts4l_cinfo *cinfo, int value)
{
    fn_8344EFB0(cinfo, (value >> 8) & 0xFF);
    fn_8344EFB0(cinfo, value & 0xFF);
}

void ts4l_jpeg_emit_sos_8344FA58(ts4l_cinfo *cinfo)
{
    int i, td, ta;
    ts4l_ccomp *compptr;

    ts4l_emit_marker(cinfo, 0xDA);

    ts4l_emit_2bytes(cinfo, 2 * cinfo->comps_in_scan + 2 + 1 + 3);

    fn_8344EFB0(cinfo, cinfo->comps_in_scan);

    for (i = 0; i < cinfo->comps_in_scan; i++) {
        compptr = cinfo->cur_comp_info[i];
        ts4l_emit_byte(cinfo, compptr->component_id);
        td = compptr->dc_tbl_no;
        ta = compptr->ac_tbl_no;
        if (cinfo->progressive_mode) {
            if (cinfo->Ss == 0) {
                ta = 0;
                if (cinfo->Ah != 0 && !cinfo->arith_code)
                    td = 0;
            } else {
                td = 0;
            }
        }
        ts4l_emit_byte(cinfo, (td << 4) + ta);
    }

    ts4l_emit_byte(cinfo, cinfo->Ss);
    ts4l_emit_byte(cinfo, cinfo->Se);
    ts4l_emit_byte(cinfo, (cinfo->Ah << 4) + cinfo->Al);
}
