/* Loader_DLL.xex 0x83450500-0x83450610, executable version 0.0.0.3. */
/* libjpeg 6b jcmaster.c: jinit_compress_master. */
struct Ts4lJCinfo;
struct Ts4lJErr {
    void (*error_exit)(struct Ts4lJCinfo *);
    void (*emit_message)(struct Ts4lJCinfo *, int);
    char pad[0x14 - 8];
    int msg_code;
};
struct Ts4lJMem {
    void *alloc_small, *alloc_large, *alloc_sarray, *alloc_barray, *request_virt_sarray;
    void (*request_virt_barray)(void);
    void (*realize_virt_arrays)(struct Ts4lJCinfo *);
};
struct Ts4lJMarker {
    void (*write_file_header)(struct Ts4lJCinfo *);
};
typedef struct Ts4lJCinfo {
    struct Ts4lJErr *err;
    struct Ts4lJMem *mem;
    char pad0[0xa8 - 8];
    int num_scans;
    char pad1[0xb0 - 0xac];
    int raw_data_in;
    int arith_code;
    int optimize_coding;
    char pad2[0xec - 0xbc];
    int progressive_mode;
    char pad3[0x164 - 0xf0];
    struct Ts4lJMarker *marker;
} Ts4lJCinfo;

extern void fn_834636F0(Ts4lJCinfo *cinfo, int v);
extern void fn_834624B8(Ts4lJCinfo *cinfo);
extern void fn_83461BE8(Ts4lJCinfo *cinfo);
extern void fn_834610E0(Ts4lJCinfo *cinfo, int v);
extern void fn_83460918(Ts4lJCinfo *cinfo);
extern void fn_8345F560(Ts4lJCinfo *cinfo);
extern void fn_8345E310(Ts4lJCinfo *cinfo);
extern void fn_8345CA98(Ts4lJCinfo *cinfo, int v);
extern void fn_8345C140(Ts4lJCinfo *cinfo, int v);
extern void ts4l_get_u32_off4_83450460(Ts4lJCinfo *cinfo);

void ts4l_jpeg_jinit_compress_master_83450500(Ts4lJCinfo *cinfo)
{
    fn_834636F0(cinfo, 0);
    if (!cinfo->raw_data_in) {
        fn_834624B8(cinfo);
        fn_83461BE8(cinfo);
        fn_834610E0(cinfo, 0);
    }
    fn_83460918(cinfo);
    if (cinfo->arith_code) {
        cinfo->err->msg_code = 1;
        (*cinfo->err->error_exit)(cinfo);
    } else {
        if (cinfo->progressive_mode)
            fn_8345F560(cinfo);
        else
            fn_8345E310(cinfo);
    }
    fn_8345CA98(cinfo, (cinfo->num_scans > 1 || cinfo->optimize_coding) ? 1 : 0);
    fn_8345C140(cinfo, 0);
    ts4l_get_u32_off4_83450460(cinfo);
    (*cinfo->mem->realize_virt_arrays)(cinfo);
    (*cinfo->marker->write_file_header)(cinfo);
}
