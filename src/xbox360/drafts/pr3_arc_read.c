/* PR3 DRAFT: CFileSystemPackArchive member read under the archive lock (not compiled into the build).
 *
 * 0x88613EB8 (0x150) ts4_arc_read_member_88613EB8 - 19 instructions differ: entry/pos and result/position swap
 *   saved registers and one add has its operands reversed. Tried: declaration orders, a local for the in-memory
 *   flag, both operand orders for the address sums, permute.py (48 candidates, exhaustive). fn_equiv: UNCHECKED (no
 *   mismatch in 2345 valid trials, coverage 62%: the in-memory branches need +0x64 set and a growing image).
 *
 * What it does: called by the member stream Read (0x8827ED60) as (archive, entry, pos, buf, n).
 *   EnterCriticalSection(archive+0x48); abs = entry->offset + archive->data_start (+0x34) + pos.
 *   Normal archive (+0x64 == 0): optionally remember abs in +0x40 (+0x25 set), then
 *     n = base->ReadAt(buf, n, abs, 2 = SET) on the archive file stream (+0x2C, vtable slot 2).
 *   In-memory archive (+0x64 != 0, loaded with the async path of 0x886217C0): when +0x70 == 0, clamp n to
 *     entry->size - pos, then copy from image (+0x7C: {data, size}); if the bytes are not there yet
 *     (abs + n > image->size, the image is still streaming in) spin with Sleep(1) (ts4_tailcall_fn_88584548_8857AFE8)
 *     until they are. Returns the byte count. LeaveCriticalSection on every path.
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifndef _MSC_VER
#define __forceinline inline
#define __inline inline
#endif
#ifdef _MSC_VER
void *memcpy(void *, const void *, unsigned int);
#pragma function(memcpy)
#else
#include <string.h>
#endif
void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);
void ts4_tailcall_fn_88584548_8857AFE8(u32 ms);

typedef struct Stream Stream;
typedef struct StreamVt { void *dtor; void *read; int (*read_at)(Stream *, void *, u32, int, int); } StreamVt;
struct Stream { StreamVt *vt; };
typedef struct ArcFatEntry { u32 hash; int offset; u32 size; } ArcFatEntry;
typedef struct MemImage { u8 *data; int size; } MemImage;
typedef struct ArcCs { u32 w[7]; } ArcCs;
typedef struct PackArchive {
    char pad00[0x25];
    u8 track_pos;        /* 0x25 */
    char pad26[0x6];
    Stream *base;        /* 0x2c */
    char pad30[4];
    int data_start;      /* 0x34 */
    char pad38[8];
    int last_pos;        /* 0x40 */
    char pad44[4];
    ArcCs cs;            /* 0x48 */
    u8 in_memory;        /* 0x64 */
    char pad65[0xb];
    int f70;             /* 0x70 */
    char pad74[8];
    MemImage *image;     /* 0x7c */
} PackArchive;


int ts4_arc_read_member_88613EB8(PackArchive *a, ArcFatEntry *e, int pos, void *buf, u32 n)
{
    int r;
    int abs;
    int p2 = pos;
    ArcFatEntry *e2 = e;
    RtlEnterCriticalSection(&a->cs);
    r = 0;
    abs = e2->offset + a->data_start;
    if (!a->in_memory) {
        abs += p2;
        if (a->track_pos) a->last_pos = abs;
        r = a->base->vt->read_at(a->base, buf, n, abs, 2);
        RtlLeaveCriticalSection(&a->cs);
        return r;
    }
    abs += p2;
    if (a->f70 == 0) {
        MemImage *m = a->image;
        u32 left = e2->size - p2;
        int end;
        if (left < n) n = left;
        end = abs + n;
        if (end > m->size) {
            u8 done = 0;
            do {
                if (end <= m->size) { memcpy(buf, m->data + abs, n); r = n; done = 1; }
                else ts4_tailcall_fn_88584548_8857AFE8(1);
            } while (!done);
            RtlLeaveCriticalSection(&a->cs);
            return r;
        }
        memcpy(buf, m->data + abs, n);
        r = n;
    }
    RtlLeaveCriticalSection(&a->cs);
    return r;
}
