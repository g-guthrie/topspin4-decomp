/* Loader_DLL.xex 0x8345F368-0x8345F560, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcphuff.c): start_pass_phuff. */
struct ts4l_compress_struct;
typedef struct ts4l_error_mgr {
    void (*error_exit)(struct ts4l_compress_struct *cinfo);
    char pad4[0x10];
    int msg_code;
    int msg_parm[2];
} ts4l_error_mgr;
typedef struct ts4l_memory_mgr {
    void *(*alloc_small)(struct ts4l_compress_struct *cinfo, int pool_id, unsigned long sizeofobject);
} ts4l_memory_mgr;
typedef struct ts4l_component_info {
    char pad0[0x14];
    int dc_tbl_no;
    int ac_tbl_no;
    char pad1c[0x54 - 0x1c];
} ts4l_component_info;
typedef struct ts4l_phuff_entropy {
    void *start_pass;
    void (*encode_mcu)(void);
    void (*finish_pass)(void);
    int gather_statistics;
    char pad10[0x18 - 0x10];
    long put_buffer;
    int put_bits;
    struct ts4l_compress_struct *cinfo;
    int last_dc_val[4];
    int ac_tbl_no;
    unsigned int EOBRUN;
    unsigned int BE;
    char *bit_buffer;
    unsigned int restarts_to_go;
    int next_restart_num;
    void *derived_tbls[4];
    long *count_ptrs[4];
} ts4l_phuff_entropy;
typedef struct ts4l_compress_struct {
    ts4l_error_mgr *err;
    ts4l_memory_mgr *mem;
    char pad8[0xc8 - 0x08];
    unsigned int restart_interval;
    char padcc[0xfc - 0xcc];
    int comps_in_scan;
    ts4l_component_info *cur_comp_info[4];
    char pad110[0x144 - 0x110];
    int Ss, Se, Ah, Al;
    char pad154[0x174 - 0x154];
    ts4l_phuff_entropy *entropy;
} ts4l_compress_struct;

extern void fn_8345E978(void);
extern void fn_8345EB58(void);
extern void fn_8345EDF0(void);
extern void ts4l_jpeg_encode_mcu_AC_refine_8345EEF0(void);
extern void fn_8345F278(void);
extern void ts4l_call_seq_u32_off18_8345F1F0(void);
extern void *fn_833E3A30(void *dst, int c, unsigned long n);
extern void fn_8345CBE0(ts4l_compress_struct *cinfo, int isDC, int tblno, void *pdtbl);

void ts4l_jpeg_start_pass_phuff_8345F368(ts4l_compress_struct *cinfo, int gather_statistics)
{
    ts4l_phuff_entropy *entropy = cinfo->entropy;
    int is_DC_band;
    int ci, tbl;
    ts4l_component_info *compptr;

    entropy->cinfo = cinfo;
    entropy->gather_statistics = gather_statistics;

    is_DC_band = (cinfo->Ss == 0);

    if (cinfo->Ah == 0) {
        if (is_DC_band)
            entropy->encode_mcu = fn_8345E978;
        else
            entropy->encode_mcu = fn_8345EB58;
    } else {
        if (is_DC_band) {
            entropy->encode_mcu = fn_8345EDF0;
        } else {
            entropy->encode_mcu = ts4l_jpeg_encode_mcu_AC_refine_8345EEF0;
            if (entropy->bit_buffer == 0)
                entropy->bit_buffer = (char *)(*cinfo->mem->alloc_small)(cinfo, 1, 1000);
        }
    }
    if (gather_statistics)
        entropy->finish_pass = fn_8345F278;
    else
        entropy->finish_pass = ts4l_call_seq_u32_off18_8345F1F0;

    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
        compptr = cinfo->cur_comp_info[ci];
        entropy->last_dc_val[ci] = 0;
        if (is_DC_band) {
            if (cinfo->Ah != 0)
                continue;
            tbl = compptr->dc_tbl_no;
        } else {
            entropy->ac_tbl_no = tbl = compptr->ac_tbl_no;
        }
        if (gather_statistics) {
            if (tbl < 0 || tbl >= 4) {
                cinfo->err->msg_code = 50;
                cinfo->err->msg_parm[0] = tbl;
                (*cinfo->err->error_exit)(cinfo);
            }
            if (entropy->count_ptrs[tbl] == 0)
                entropy->count_ptrs[tbl] = (long *)(*cinfo->mem->alloc_small)(cinfo, 1, 257 * sizeof(long));
            fn_833E3A30(entropy->count_ptrs[tbl], 0, 257 * sizeof(long));
        } else {
            fn_8345CBE0(cinfo, is_DC_band, tbl, &entropy->derived_tbls[tbl]);
        }
    }

    entropy->EOBRUN = 0;
    entropy->BE = 0;
    entropy->put_buffer = 0;
    entropy->put_bits = 0;
    entropy->restarts_to_go = cinfo->restart_interval;
    entropy->next_restart_num = 0;
}
