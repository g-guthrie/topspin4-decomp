/* Loader_DLL.xex 0x83460918-0x83460A30, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcdctmgr.c): jinit_forward_dct. */
struct ts4l_compress_struct;
typedef struct ts4l_error_mgr {
    void (*error_exit)(struct ts4l_compress_struct *cinfo);
    char pad4[0x10];
    int msg_code;
} ts4l_error_mgr;
typedef struct ts4l_memory_mgr {
    void *(*alloc_small)(struct ts4l_compress_struct *cinfo, int pool_id, unsigned long sizeofobject);
} ts4l_memory_mgr;
typedef struct ts4l_fdct_controller {
    void (*start_pass)(void);
    void (*forward_DCT)(void);
    void (*do_dct)(void);
    void *divisors[4];
    void (*do_float_dct)(void);
    void *float_divisors[4];
} ts4l_fdct_controller;
typedef struct ts4l_compress_struct {
    ts4l_error_mgr *err;
    ts4l_memory_mgr *mem;
    char pad8[0xc4 - 0x08];
    int dct_method;
    char padc8[0x170 - 0xc8];
    ts4l_fdct_controller *fdct;
} ts4l_compress_struct;

extern void fn_8345F5D0(void);
extern void fn_8345F9F8(void);
extern void fn_83468E28(void);
extern void fn_83468B28(void);
extern void fn_8345FF08(void);
extern void fn_83467CE0(void);

void ts4l_jpeg_init_forward_dct_83460918(ts4l_compress_struct *cinfo)
{
    ts4l_fdct_controller *fdct;
    int i;

    fdct = (ts4l_fdct_controller *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(ts4l_fdct_controller));
    cinfo->fdct = fdct;
    fdct->start_pass = fn_8345F5D0;

    switch (cinfo->dct_method) {
    case 0:
    case 3:
    case 5:
        fdct->forward_DCT = fn_8345F9F8;
        fdct->do_dct = fn_83468E28;
        break;
    case 1:
    case 4:
    case 6:
        fdct->forward_DCT = fn_8345F9F8;
        fdct->do_dct = fn_83468B28;
        break;
    case 2:
        fdct->forward_DCT = fn_8345FF08;
        fdct->do_float_dct = fn_83467CE0;
        break;
    default:
        cinfo->err->msg_code = 48;
        (*cinfo->err->error_exit)(cinfo);
        break;
    }
    for (i = 0; i < 4; i++) {
        fdct->divisors[i] = 0;
        fdct->float_divisors[i] = 0;
    }
}
