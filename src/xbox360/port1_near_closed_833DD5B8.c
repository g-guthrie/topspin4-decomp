/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l25_near_closed_833DD5B8.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Small helpers: neighbour smoothing of an int array, a LocalAlloc-style heap allocation, 96-bit add with carry, bounded buffer read. */
typedef unsigned long ts4_u32;

/* Replace each interior element by the average of its neighbours, then copy element n-2 into the last slot. */

/* LocalAlloc-style: bit 0x40 of the flags requests zeroed memory (HEAP_ZERO_MEMORY). */

typedef struct { ts4_u32 hi, mid, lo; } Ts4lNum96;

/* a += b for a 96-bit number stored as three 32-bit words (most significant first). */

typedef struct { ts4_u32 pad0, pad1, pad2, buf, end, pos; } Ts4lReadBuf;

/* Copy up to want bytes from the read buffer to dst, advance the position and report the count. */

extern ts4_u32 ts4_get_u32_lbl_88D4E11C_88581A90(void);
extern void *fn_885805C0(ts4_u32 heap, ts4_u32 flags, ts4_u32 size);

/* Swing_DLL.xex 0x8858B138 */
void *ts4_local_alloc_8858B138(ts4_u32 flags, ts4_u32 size)
{
    return fn_885805C0(ts4_get_u32_lbl_88D4E11C_88581A90(), (flags & 0x40) ? 8 : 0, size);
}

