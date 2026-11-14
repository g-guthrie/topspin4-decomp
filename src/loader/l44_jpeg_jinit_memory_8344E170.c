/* Loader_DLL.xex 0x8344E170-0x8344E298, executable version 0.0.0.3. */
/* Library routine: libjpeg jmemmgr.c jinit_memory_mgr. */
#include "l44_jpeg.h"

struct ts4l_my_memory_mgr {
    struct ts4l_jpeg_memory_mgr pub; /* 0x00 */
    void *small_list[2];            /* 0x34 */
    void *large_list[2];            /* 0x3c */
    void *virt_sarray_list;         /* 0x44 */
    void *virt_barray_list;         /* 0x48 */
    int total_space_allocated;      /* 0x4c */
    int pad50;
};

extern int ts4_fn_834564D8(struct ts4l_jpeg_decomp *cinfo);
extern void *fn_83456200(struct ts4l_jpeg_decomp *cinfo, unsigned int size);
extern void ts4_fn_834564E8(struct ts4l_jpeg_decomp *cinfo);
extern void *fn_8344D070(struct ts4l_jpeg_decomp *cinfo, int pool_id, unsigned int size);
extern void *ts4l_if_get_u32_off4_8344D248(struct ts4l_jpeg_decomp *cinfo, int pool_id, unsigned int size);
extern void *fn_8344D368(struct ts4l_jpeg_decomp *cinfo, int pool_id, unsigned int a, unsigned int b);
extern void *fn_8344D448(struct ts4l_jpeg_decomp *cinfo, int pool_id, unsigned int a, unsigned int b);
extern void *ts4l_if_get_u32_off4_8344D530(struct ts4l_jpeg_decomp *cinfo, int pool_id, int pre_zero,
                                           unsigned int a, unsigned int b, unsigned int c);
extern void *ts4l_if_get_u32_off4_8344D5C8(struct ts4l_jpeg_decomp *cinfo, int pool_id, int pre_zero,
                                           unsigned int a, unsigned int b, unsigned int c);
extern void fn_8344D660(struct ts4l_jpeg_decomp *cinfo);
extern void *fn_8344DA58(struct ts4l_jpeg_decomp *cinfo, void *ptr, unsigned int start, unsigned int n, int w);
extern void *fn_8344DC48(struct ts4l_jpeg_decomp *cinfo, void *ptr, unsigned int start, unsigned int n, int w);
extern void fn_8344DE40(struct ts4l_jpeg_decomp *cinfo, int pool_id);
extern void fn_8344DFC8(struct ts4l_jpeg_decomp *cinfo);

void ts4l_jpeg_jinit_memory_mgr_8344E170(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_my_memory_mgr *mem;
    int max_to_use;
    int pool;

    cinfo->mem = 0;
    max_to_use = ts4_fn_834564D8(cinfo);

    mem = (struct ts4l_my_memory_mgr *)fn_83456200(cinfo, 0x54);
    if (mem == 0) {
        ts4_fn_834564E8(cinfo);
        TS4L_ERREXIT1(cinfo, 54, 0);
    }

    mem->pub.alloc_small = fn_8344D070;
    mem->pub.alloc_large = ts4l_if_get_u32_off4_8344D248;
    mem->pub.alloc_sarray = (ts4l_jsamparray (*)(struct ts4l_jpeg_decomp *, int, ts4l_jdim, ts4l_jdim))fn_8344D368;
    mem->pub.alloc_barray = (ts4l_jblockarray (*)(struct ts4l_jpeg_decomp *, int, ts4l_jdim, ts4l_jdim))fn_8344D448;
    mem->pub.request_virt_sarray = (struct ts4l_jpeg_virt_sarray *(*)(struct ts4l_jpeg_decomp *, int, int, ts4l_jdim, ts4l_jdim, ts4l_jdim))ts4l_if_get_u32_off4_8344D530;
    mem->pub.request_virt_barray = (struct ts4l_jpeg_virt_barray *(*)(struct ts4l_jpeg_decomp *, int, int, ts4l_jdim, ts4l_jdim, ts4l_jdim))ts4l_if_get_u32_off4_8344D5C8;
    mem->pub.realize_virt_arrays = fn_8344D660;
    mem->pub.access_virt_sarray = (ts4l_jsamparray (*)(struct ts4l_jpeg_decomp *, struct ts4l_jpeg_virt_sarray *, ts4l_jdim, ts4l_jdim, int))fn_8344DA58;
    mem->pub.access_virt_barray = (ts4l_jblockarray (*)(struct ts4l_jpeg_decomp *, struct ts4l_jpeg_virt_barray *, ts4l_jdim, ts4l_jdim, int))fn_8344DC48;
    mem->pub.free_pool = fn_8344DE40;
    mem->pub.self_destruct = fn_8344DFC8;

    mem->pub.max_alloc_chunk = 1000000000;
    mem->pub.max_memory_to_use = max_to_use;

    for (pool = 1; pool >= 0; pool--) {
        mem->small_list[pool] = 0;
        mem->large_list[pool] = 0;
    }
    mem->virt_sarray_list = 0;
    mem->virt_barray_list = 0;

    mem->total_space_allocated = 0x54;

    cinfo->mem = &mem->pub;
}
