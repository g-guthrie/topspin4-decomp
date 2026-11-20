/* Loader_DLL.xex 0x8345E978-0x8345EB54, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcphuff.c): encode_mcu_DC_first. */
struct ts4l_compress_struct;
typedef struct ts4l_error_mgr {
    void (*error_exit)(struct ts4l_compress_struct *cinfo);
    char pad4[0x10];
    int msg_code;
} ts4l_error_mgr;
typedef struct ts4l_destination_mgr {
    unsigned char *next_output_byte;
    unsigned long free_in_buffer;
} ts4l_destination_mgr;
typedef struct ts4l_derived_tbl {
    unsigned int ehufco[256];
    char ehufsi[256];
} ts4l_derived_tbl;
typedef struct ts4l_component_info {
    char pad0[0x14];
    int dc_tbl_no;
    int ac_tbl_no;
    char pad1c[0x54 - 0x1c];
} ts4l_component_info;
typedef struct ts4l_phuff_entropy {
    void *start_pass;
    void *encode_mcu;
    void *finish_pass;
    int gather_statistics;
    unsigned char *next_output_byte;
    unsigned long free_in_buffer;
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
    ts4l_derived_tbl *derived_tbls[4];
    long *count_ptrs[4];
} ts4l_phuff_entropy;
typedef struct ts4l_compress_struct {
    ts4l_error_mgr *err;
    char pad4[0x18 - 0x04];
    ts4l_destination_mgr *dest;
    char pad1c[0xc8 - 0x1c];
    unsigned int restart_interval;
    char padcc[0xfc - 0xcc];
    int comps_in_scan;
    ts4l_component_info *cur_comp_info[4];
    char pad110[0x118 - 0x110];
    int blocks_in_MCU;
    int MCU_membership[10];
    char pad144[0x150 - 0x144];
    int Al;
    char pad154[0x174 - 0x154];
    ts4l_phuff_entropy *entropy;
} ts4l_compress_struct;

extern void fn_8345E880(ts4l_phuff_entropy *entropy, int restart_num);
extern void fn_8345E408(ts4l_phuff_entropy *entropy, unsigned int code, int size);

#ifdef _MSC_VER
static __forceinline
#else
static
#endif
void emit_symbol(ts4l_phuff_entropy *entropy, int tbl_no, int symbol)
{
    if (entropy->gather_statistics) {
        entropy->count_ptrs[tbl_no][symbol]++;
    } else {
        ts4l_derived_tbl *tbl = entropy->derived_tbls[tbl_no];
        fn_8345E408(entropy, tbl->ehufco[symbol], tbl->ehufsi[symbol]);
    }
}

int ts4l_jpeg_encode_mcu_DC_first_8345E978(ts4l_compress_struct *cinfo, short **MCU_data)
{
    ts4l_phuff_entropy *entropy = cinfo->entropy;
    int temp, temp2;
    int nbits;
    int blkn, ci;
    int Al = cinfo->Al;
    short *block;
    ts4l_component_info *compptr;

    entropy->next_output_byte = cinfo->dest->next_output_byte;
    entropy->free_in_buffer = cinfo->dest->free_in_buffer;

    if (cinfo->restart_interval)
        if (entropy->restarts_to_go == 0)
            fn_8345E880(entropy, entropy->next_restart_num);

    for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
        block = MCU_data[blkn];
        ci = cinfo->MCU_membership[blkn];
        compptr = cinfo->cur_comp_info[ci];

        temp2 = (int)block[0] >> Al;

        temp = temp2 - entropy->last_dc_val[ci];
        entropy->last_dc_val[ci] = temp2;

        temp2 = temp;
        if (temp < 0) {
            temp = -temp;
            temp2--;
        }

        nbits = 0;
        while (temp) {
            nbits++;
            temp >>= 1;
        }
        if (nbits > 11) {
            cinfo->err->msg_code = 6;
            (*cinfo->err->error_exit)(cinfo);
        }

        emit_symbol(entropy, compptr->dc_tbl_no, nbits);

        if (nbits)
            fn_8345E408(entropy, (unsigned int)temp2, nbits);
    }

    cinfo->dest->next_output_byte = entropy->next_output_byte;
    cinfo->dest->free_in_buffer = entropy->free_in_buffer;

    if (cinfo->restart_interval) {
        if (entropy->restarts_to_go == 0) {
            entropy->restarts_to_go = cinfo->restart_interval;
            entropy->next_restart_num++;
            entropy->next_restart_num &= 7;
        }
        entropy->restarts_to_go--;
    }
    return 1;
}
