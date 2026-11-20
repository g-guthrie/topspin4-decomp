/* Loader_DLL.xex 0x8313CEF0-0x83121448, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Pool { u32 *data; u32 elemSize; u32 count; };
struct Handle { u32 pad0; u32 flags; u32 pad8; u32 flagsC; u32 slot; u32 pad14; };

extern void *ts4_tailcall_fn_8340D710_83120518(u32 n);
extern void fn_833E3AD0(void *dst, const void *src, u32 n);

long ts4l_pool_init_8313CEF0(struct Pool *p, const void *src, u32 size)
{
    u32 unit = p->elemSize * 4;
    if (size % unit != 0) return 0x8000ffff;
    p->data = (u32 *)ts4_tailcall_fn_8340D710_83120518(size);
    if (p->data == 0) return 0x8007000e;
    fn_833E3AD0(p->data, src, size);
    p->count = size / (p->elemSize * 4);
    return 0;
}
