/* Loader_DLL.xex 0x830A1D10-0x830A44F8, executable version 0.0.0.3. */
/* Algorithms over 20-byte elements (copy, fill, uninitialized copy/fill). */
typedef unsigned int u32;
typedef struct E20 { int a[5]; } E20;
#ifndef _MSC_VER
#define __forceinline inline
#endif

E20 *ts4l_ucopy_830A4130(E20 *first, E20 *last, E20 *dest)
{
    for (; first != last; first++, dest++) {
        if (dest)
            *dest = *first;
    }
    return dest;
}

void ts4l_fill_range_830A41C8(E20 *first, E20 *last, const E20 *val)
{
    for (; first != last; first++)
        *first = *val;
}

void ts4l_ufill_n_830A4200(E20 *dest, u32 n, const E20 *val)
{
    if (n == 0)
        return;
    do {
        if (dest)
            *dest = *val;
        dest++;
    } while (--n);
}

void ts4l_construct_830A4480(E20 *dest, const E20 *val)
{
    if (dest)
        *dest = *val;
}

void ts4l_ufill_n_830A44A8(E20 *dest, u32 n, const E20 *val)
{
    if (n == 0)
        return;
    do {
        if (dest)
            *dest = *val;
        dest++;
    } while (--n);
}

E20 *ts4l_copy_forward_830A4330(E20 *first, E20 *last, E20 *dest)
{
    int n = last - first;
    for (; n > 0; n--) {
        *dest = *first;
        dest++;
        first++;
    }
    return dest;
}

E20 *ts4l_copy_backward_830A44F8(E20 *first, E20 *last, E20 *dest_end)
{
    int n = last - first;
    for (; n > 0; n--) {
        --last;
        --dest_end;
        *dest_end = *last;
    }
    return dest_end;
}

typedef struct V20 { E20 *first; E20 *last; E20 *end; } V20;
static __forceinline E20 *copy_fwd(E20 *first, E20 *last, E20 *dest)
{
    int n = last - first;
    for (; n > 0; n--) {
        *dest = *first;
        first++;
        dest++;
    }
    return dest;
}
void ts4l_vec20_clear_830A1D10(V20 *v)
{
    v->last = copy_fwd(v->last, v->last, v->first);
}
E20 *ts4l_vec20_erase_830A2318(V20 *v, E20 *pos, E20 *next)
{
    v->last = copy_fwd(next, v->last, pos);
    return pos;
}
