/* Swing_DLL.xex 0x88593848: allocate a 16-pointer chunk array (near miss, 2 off under /O1).
 * Remaining diff: in the success arm the target sets r3 = 0 before r11 = 0x10; ours the other way, in either source order. */
typedef unsigned int u32;
typedef struct ChunkArray { void **items; u32 capacity; u32 count; } ChunkArray;

void *fn_88888668(u32 size, u32 tag);

/* Allocate room for 16 pointers (tag 0x24970000); E_OUTOFMEMORY on failure. */
long fn_88593848(ChunkArray *a)
{
    long hr;
    a->items = fn_88888668(0x80, 0x24970000);
    if (a->items != 0) {
        hr = 0;
        a->capacity = 0x10;
    } else {
        hr = 0x8007000E;
        a->capacity = 0;
    }
    a->count = 0;
    return hr;
}
