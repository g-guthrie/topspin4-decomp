/* Loader_DLL.xex 0x834502E0-0x8345045C, executable version 0.0.0.3. */
/* libjpeg 6b jcmarker.c: write_tables_only (SOI, DQT/DHT tables, EOI). */
struct Ts4lJCinfo;
struct Ts4lJErr {
    void (*error_exit)(struct Ts4lJCinfo *);
    void (*emit_message)(struct Ts4lJCinfo *, int);
    char pad[0x14 - 8];
    int msg_code;
};
struct Ts4lJDest {
    unsigned char *next_output_byte;
    unsigned free_in_buffer;
    void (*init_destination)(struct Ts4lJCinfo *);
    int (*empty_output_buffer)(struct Ts4lJCinfo *);
};
typedef struct Ts4lJCinfo {
    struct Ts4lJErr *err;
    char pad0[0x18 - 4];
    struct Ts4lJDest *dest;
    char pad1[0x48 - 0x1c];
    void *quant_tbl_ptrs[4];
    void *dc_huff_tbl_ptrs[4];
    void *ac_huff_tbl_ptrs[4];
    char pad2[0xb4 - 0x78];
    int arith_code;
} Ts4lJCinfo;

extern int ts4l_jpeg_emit_dqt_8344F0D0(Ts4lJCinfo *cinfo, int index);
extern void ts4l_jpeg_emit_dht_8344F478(Ts4lJCinfo *cinfo, int index, int is_ac);
extern void fn_8344EFB0(Ts4lJCinfo *cinfo, int val);

#ifdef _MSC_VER
#define TS4L_INLINE static __forceinline
#else
#define TS4L_INLINE static
#endif

TS4L_INLINE void ts4l_emit_byte(Ts4lJCinfo *cinfo, int val)
{
    struct Ts4lJDest *dest = cinfo->dest;
    *(dest->next_output_byte)++ = (unsigned char)val;
    if (--dest->free_in_buffer == 0) {
        if (!(*dest->empty_output_buffer)(cinfo)) {
            cinfo->err->msg_code = 24;
            (*cinfo->err->error_exit)(cinfo);
        }
    }
}

void ts4l_jpeg_write_tables_only_834502E0(Ts4lJCinfo *cinfo)
{
    int i;

    fn_8344EFB0(cinfo, 0xff);
    fn_8344EFB0(cinfo, 0xd8);
    for (i = 0; i < 4; i++) {
        if (cinfo->quant_tbl_ptrs[i] != 0)
            ts4l_jpeg_emit_dqt_8344F0D0(cinfo, i);
    }
    if (!cinfo->arith_code) {
        for (i = 0; i < 4; i++) {
            if (cinfo->dc_huff_tbl_ptrs[i] != 0)
                ts4l_jpeg_emit_dht_8344F478(cinfo, i, 0);
            if (cinfo->ac_huff_tbl_ptrs[i] != 0)
                ts4l_jpeg_emit_dht_8344F478(cinfo, i, 1);
        }
    }
    ts4l_emit_byte(cinfo, 0xff);
    ts4l_emit_byte(cinfo, 0xd9);
}
