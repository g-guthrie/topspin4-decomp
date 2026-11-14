/* Loader_DLL.xex 0x8344F800-0x8344FA54, executable version 0.0.0.3. */
/* libjpeg 6b jcmarker.c: emit_sof (SOFn marker with component table). */
struct Ts4lJCinfo;
struct Ts4lJErr {
    void (*error_exit)(struct Ts4lJCinfo *);
    void (*emit_message)(struct Ts4lJCinfo *, int);
    char pad[0x14 - 8];
    int msg_code;
    int msg_parm0;
};
struct Ts4lJDest {
    unsigned char *next_output_byte;
    unsigned free_in_buffer;
    void (*init_destination)(struct Ts4lJCinfo *);
    int (*empty_output_buffer)(struct Ts4lJCinfo *);
};
typedef struct Ts4lJComp {
    int component_id, component_index, h_samp_factor, v_samp_factor;
    int quant_tbl_no;
    char pad[0x54 - 0x14];
} Ts4lJComp;
typedef struct Ts4lJCinfo {
    struct Ts4lJErr *err;
    char pad0[0x18 - 4];
    struct Ts4lJDest *dest;
    int image_width;
    int image_height;
    char pad1[0x38 - 0x24];
    int data_precision;
    int num_components;
    char pad2[0x44 - 0x40];
    Ts4lJComp *comp_info;
} Ts4lJCinfo;

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

static void ts4l_emit_2bytes(Ts4lJCinfo *cinfo, int value)
{
    fn_8344EFB0(cinfo, (value >> 8) & 0xFF);
    fn_8344EFB0(cinfo, value & 0xFF);
}

void ts4l_jpeg_emit_sof_8344F800(Ts4lJCinfo *cinfo, int code)
{
    int ci;
    Ts4lJComp *compptr;

    fn_8344EFB0(cinfo, 0xFF);
    fn_8344EFB0(cinfo, code);
    ts4l_emit_2bytes(cinfo, 3 * cinfo->num_components + 2 + 5 + 1);
    if (cinfo->image_height > 65535L || cinfo->image_width > 65535L) {
        cinfo->err->msg_code = 41;
        cinfo->err->msg_parm0 = 65535;
        (*cinfo->err->error_exit)(cinfo);
    }
    fn_8344EFB0(cinfo, cinfo->data_precision);
    ts4l_emit_2bytes(cinfo, cinfo->image_height);
    ts4l_emit_2bytes(cinfo, cinfo->image_width);
    fn_8344EFB0(cinfo, cinfo->num_components);
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        ts4l_emit_byte(cinfo, compptr->component_id);
        ts4l_emit_byte(cinfo, (compptr->h_samp_factor << 4) + compptr->v_samp_factor);
        ts4l_emit_byte(cinfo, compptr->quant_tbl_no);
    }
}
