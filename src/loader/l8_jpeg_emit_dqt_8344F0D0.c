/* Loader_DLL.xex 0x8344F0D0-0x8344F474, executable version 0.0.0.3. */
/* Library routine: libjpeg emit_dqt (jcmarker.c) with emit_byte,
   emit_marker and emit_2bytes inlined. */

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

typedef struct ts4l_cquant {
    unsigned short quantval[64];
    int sent_table;
} ts4l_cquant;

struct ts4l_cinfo {
    ts4l_cerr *err;
    char pad0[0x14];
    ts4l_cdest *dest;
    char pad1[0x48 - 0x1c];
    ts4l_cquant *quant_tbl_ptrs[4];
};

extern int lbl_8307A868[];

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
    ts4l_emit_byte(cinfo, 0xFF);
    ts4l_emit_byte(cinfo, mark);
}

static void ts4l_emit_2bytes(ts4l_cinfo *cinfo, int value)
{
    ts4l_emit_byte(cinfo, (value >> 8) & 0xFF);
    ts4l_emit_byte(cinfo, value & 0xFF);
}

int ts4l_jpeg_emit_dqt_8344F0D0(ts4l_cinfo *cinfo, int index)
{
    ts4l_cquant *qtbl = cinfo->quant_tbl_ptrs[index];
    int prec;
    int i;

    if (qtbl == 0) {
        cinfo->err->msg_code = 52;
        cinfo->err->msg_parm[0] = index;
        (*cinfo->err->error_exit)(cinfo);
    }

    prec = 0;
    for (i = 0; i < 64; i++) {
        if (qtbl->quantval[i] > 255)
            prec = 1;
    }

    if (!qtbl->sent_table) {
        ts4l_emit_marker(cinfo, 0xDB);

        ts4l_emit_2bytes(cinfo, prec ? 64 * 2 + 1 + 2 : 64 + 1 + 2);

        ts4l_emit_byte(cinfo, index + (prec << 4));

        for (i = 0; i < 64; i++) {
            unsigned int qval = qtbl->quantval[lbl_8307A868[i]];
            if (prec)
                ts4l_emit_byte(cinfo, (int)(qval >> 8));
            ts4l_emit_byte(cinfo, (int)(qval & 0xFF));
        }

        qtbl->sent_table = 1;
    }

    return prec;
}
