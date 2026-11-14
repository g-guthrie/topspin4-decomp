/* Swing_DLL.xex 0x881AA5D0-0x881B3C84, executable version 0.0.0.3. */
typedef unsigned int u32;
#ifdef _MSC_VER
void *memcpy(void *, const void *, unsigned int);
#pragma intrinsic(memcpy)
#else
#include <string.h>
#endif
struct rel_array { int data_off; u32 count; u32 capacity; };
struct rel_src { int data_off; u32 count; };


/* Copies another relative-offset array's elements when they fit the capacity. */
void ts4_rel_array_assign_881AA5D0(struct rel_array *dst, struct rel_src *src)
{
    u32 n = src->count;
    if ((int)n > 0 && dst->data_off != -1 && src->data_off != -1 && dst->capacity >= n) {
        memcpy((char *)dst + dst->data_off, (char *)src + src->data_off, n << 3);
        dst->count = dst->count < n ? n : dst->count;
    }
}


/* Copies another relative-offset array's elements when they fit the capacity. */
void ts4_rel_array_assign_881ACC00(struct rel_array *dst, struct rel_src *src)
{
    u32 n = src->count;
    if ((int)n > 0 && dst->data_off != -1 && src->data_off != -1 && dst->capacity >= n) {
        memcpy((char *)dst + dst->data_off, (char *)src + src->data_off, n << 5);
        dst->count = dst->count < n ? n : dst->count;
    }
}


/* Copies another relative-offset array's elements when they fit the capacity. */
void ts4_rel_array_assign_881B3B78(struct rel_array *dst, struct rel_src *src)
{
    u32 n = src->count;
    if ((int)n > 0 && dst->data_off != -1 && src->data_off != -1 && dst->capacity >= n) {
        memcpy((char *)dst + dst->data_off, (char *)src + src->data_off, n << 6);
        dst->count = dst->count < n ? n : dst->count;
    }
}


/* Copies another relative-offset array's elements when they fit the capacity. */
void ts4_rel_array_assign_881B3C00(struct rel_array *dst, struct rel_src *src)
{
    u32 n = src->count;
    if ((int)n > 0 && dst->data_off != -1 && src->data_off != -1 && dst->capacity >= n) {
        memcpy((char *)dst + dst->data_off, (char *)src + src->data_off, n << 4);
        dst->count = dst->count < n ? n : dst->count;
    }
}
