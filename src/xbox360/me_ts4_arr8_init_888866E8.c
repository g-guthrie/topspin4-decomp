/* 0x888866E8: initialize an array of n 8-byte elements: store the count, allocate n*8 bytes
   (0xFFFFFFFF on overflow) from the game heap lbl_88D45B38 when present, else the CRT heap,
   and clear the three trailing words. */
typedef unsigned int u32;
typedef struct Elem8 { u32 a, b; } Elem8;
typedef struct Arr8 { u32 count; Elem8 *data; u32 a, b, c; } Arr8;
extern void *lbl_88D45B38;
extern void *ts4_node_dispatch_default_88613350(void *heap, u32 size);
extern void *ts4_crt_nh_malloc_88565258(u32 size);
static __inline void *game_alloc(u32 size)
{
    if (!lbl_88D45B38)
        return ts4_crt_nh_malloc_88565258(size);
    return ts4_node_dispatch_default_88613350(lbl_88D45B38, size);
}
void ts4_arr8_init_888866E8(Arr8 *o, u32 n)
{
    o->count = n;
    o->data = (Elem8 *)game_alloc(n <= 0x1FFFFFFF ? n * 8 : 0xFFFFFFFF);
    o->a = 0; o->b = 0; o->c = 0;
}
