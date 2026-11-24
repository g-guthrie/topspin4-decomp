/* 0x88731158: GPU buffer resize: allocate stride*count, block on the old buffer's fence on the active device, store count, release the old ref and install the new buffer. */
typedef unsigned int u32;
typedef struct GpuRes { char p0[8]; u32 fence; } GpuRes;
typedef struct { GpuRes *res; char p4[8]; u32 stride; u32 count; } Obj;
extern char **__imp_VdGlobalDevice;
extern char **__imp_VdGlobalXamDevice;
extern int KeGetCurrentProcessType(void);
extern GpuRes *ts4_create_gpu_buffer_882886B8(u32 size, u32 align, u32 flags);
extern void fn_88292698(void *dev, u32 fence, u32 a, u32 b);
extern u32 ts4_if_atomic_interlocked_dec_88288530(void *res);
static __inline char *gpu_device(void)
{
    return KeGetCurrentProcessType() == 2 ? *__imp_VdGlobalXamDevice : *__imp_VdGlobalDevice;
}
static __inline void gpu_block_on_fence(void *dev, u32 fence)
{
    if (fence) fn_88292698(dev, fence, 5, 0);
}
void fn_88731158(Obj *o, u32 count)
{
    GpuRes *nb = ts4_create_gpu_buffer_882886B8(o->stride * count, 8, 0);
    GpuRes *old = o->res;
    gpu_block_on_fence(gpu_device(), old->fence);
    o->count = count;
    if (o->res && !ts4_if_atomic_interlocked_dec_88288530(o->res)) o->res = 0;
    o->res = nb;
}
