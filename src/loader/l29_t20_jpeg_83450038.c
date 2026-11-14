/* Loader_DLL.xex 0x83450038-0x83450184, executable version 0.0.0.3. */
/* libjpeg 6b jcmarker.c: write_frame_header (DQT tables, baseline test, SOFn marker). */
struct Ts4lJCinfo;
struct Ts4lJErr {
    void (*error_exit)(struct Ts4lJCinfo *);
    void (*emit_message)(struct Ts4lJCinfo *, int);
    void (*output_message)(struct Ts4lJCinfo *);
    void (*format_message)(struct Ts4lJCinfo *, char *);
    void (*reset_error_mgr)(struct Ts4lJCinfo *);
    int msg_code;
};
typedef struct Ts4lJComp {
    int component_id, component_index, h_samp_factor, v_samp_factor;
    int quant_tbl_no, dc_tbl_no, ac_tbl_no;
    char pad[0x54 - 0x1c];
} Ts4lJComp;
struct Ts4lJCinfo {
    struct Ts4lJErr *err;
    char pad0[0x38 - 4];
    int data_precision;
    int num_components;
    char pad1[0x44 - 0x40];
    Ts4lJComp *comp_info;
    char pad2[0xb4 - 0x48];
    int arith_code;
    char pad3[0xec - 0xb8];
    int progressive_mode;
};

extern int ts4l_jpeg_emit_dqt_8344F0D0(struct Ts4lJCinfo *cinfo, int index);
extern void fn_8344F800(struct Ts4lJCinfo *cinfo, int marker);

void ts4l_jpeg_write_frame_header_83450038(struct Ts4lJCinfo *cinfo)
{
    int ci, prec;
    int is_baseline;
    Ts4lJComp *compptr;

    prec = 0;
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        prec += ts4l_jpeg_emit_dqt_8344F0D0(cinfo, compptr->quant_tbl_no);
    }
    if (cinfo->arith_code || cinfo->progressive_mode || cinfo->data_precision != 8) {
        is_baseline = 0;
    } else {
        is_baseline = 1;
        for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
            if (compptr->dc_tbl_no > 1 || compptr->ac_tbl_no > 1) is_baseline = 0;
        }
        if (prec && is_baseline) {
            is_baseline = 0;
            cinfo->err->msg_code = 75;
            (*cinfo->err->emit_message)(cinfo, 0);
        }
    }
    if (cinfo->arith_code) fn_8344F800(cinfo, 0xc9);
    else if (cinfo->progressive_mode) fn_8344F800(cinfo, 0xc2);
    else if (is_baseline) fn_8344F800(cinfo, 0xc0);
    else fn_8344F800(cinfo, 0xc1);
}
