/* Loader_DLL.xex 0x8344F478-0x8344F778, executable version 0.0.0.3. */
/* Library routine: libjpeg emit_dht (jcmarker.c); the marker bytes go through
   the out-of-line emit_byte, the rest is inlined. */

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

typedef struct ts4l_chuff {
    ts4l_u8 bits[17];
    ts4l_u8 huffval[256];
    int sent_table;
} ts4l_chuff;

struct ts4l_cinfo {
    ts4l_cerr *err;
    char pad0[0x14];
    ts4l_cdest *dest;
    char pad1[0x58 - 0x1c];
    ts4l_chuff *dc_huff_tbl_ptrs[4];
    ts4l_chuff *ac_huff_tbl_ptrs[4];
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

void ts4l_jpeg_emit_dht_8344F478(ts4l_cinfo *cinfo, int index, int is_ac)
{
    ts4l_chuff *htbl;
    int length, i;

    if (is_ac) {
        htbl = cinfo->ac_huff_tbl_ptrs[index];
        index += 0x10;
    } else {
        htbl = cinfo->dc_huff_tbl_ptrs[index];
    }

    if (htbl == 0) {
        cinfo->err->msg_code = 50;
        cinfo->err->msg_parm[0] = index;
        (*cinfo->err->error_exit)(cinfo);
    }

    if (!htbl->sent_table) {
        fn_8344EFB0(cinfo, 0xFF);
        fn_8344EFB0(cinfo, 0xC4);

        length = 0;
        for (i = 1; i <= 16; i++)
            length += htbl->bits[i];

        ts4l_emit_byte(cinfo, ((length + 2 + 1 + 16) >> 8) & 0xFF);
        ts4l_emit_byte(cinfo, (length + 2 + 1 + 16) & 0xFF);

        ts4l_emit_byte(cinfo, index);

        for (i = 1; i <= 16; i++)
            ts4l_emit_byte(cinfo, htbl->bits[i]);

        for (i = 0; i < length; i++)
            ts4l_emit_byte(cinfo, htbl->huffval[i]);

        htbl->sent_table = 1;
    }
}
