/* Swing_DLL.xex fixed-capacity byte string append (FAM3).
   MSVC 16.00.10224.00 /O2.

   The string keeps {first, last} pointers, an inline buffer of N bytes and
   a capacity-end pointer. Growing reuses the inline buffer, so the
   allocator never touches the heap. Instances differ only in N. */
typedef unsigned int u32;

#define TS4_FIXED_STRING(N) \
    struct Ts4FixedString##N { \
        char *first; \
        char *last; \
        char buffer[N]; \
        char *capacity; \
    }

#ifndef _MSC_VER
#define __forceinline inline
#endif

extern char lbl_880D19E0[];                               /* length-error message */
void *fn_88562DC0(void *dst, const void *src, u32 size);  /* memmove */
void *fn_88562EF8(const char *msg);                       /* build length_error */
void fn_88562E80(void *error);                            /* throw */

static __forceinline const u32 *ts4_u32_max_ref(const u32 *a, const u32 *b)
{
    return (*a < *b) ? b : a;
}

static __forceinline char *ts4_char_copy_range(const char *from, const char *to, char *dst)
{
    if (to == from)
        return dst;
    {
        u32 n = (u32)(to - from);
        return (char *)fn_88562DC0(dst, from, n) + n;
    }
}

#define FIXED_STRING_APPEND(A, N) \
TS4_FIXED_STRING(N); \
struct Ts4FixedString##N *ts4_fixed_string_append_##A(struct Ts4FixedString##N *self, const char *from, const char *to) \
{ \
    u32 size = (u32)(self->last - self->first); \
    u32 n = (u32)(to - from); \
    if (n > (u32)-2 || size > (u32)-2 - n) \
        fn_88562E80(fn_88562EF8(lbl_880D19E0)); \
    if (n + size > (u32)(self->capacity - self->first) - 1) { \
        u32 grow = n; \
        u32 cap; \
        char *nb; \
        char *ne; \
        { \
            const u32 *larger = ts4_u32_max_ref(&size, &grow); \
            cap = *larger + size + 1; \
        } \
        nb = self->buffer; \
        ne = ts4_char_copy_range(self->first, self->last, nb); \
        ne = ts4_char_copy_range(from, to, ne); \
        *ne = 0; \
        self->first = nb; \
        self->last = ne; \
        self->capacity = nb + cap; \
    } else { \
        const char *rest = from + 1; \
        if (to != rest) \
            fn_88562DC0(self->last + 1, rest, (u32)(to - rest)); \
        self->last[n] = 0; \
        *self->last = *from; \
        self->last += n; \
    } \
    return self; \
}

/* Swing_DLL.xex addresses */
FIXED_STRING_APPEND(8816BBD8, 0x40)
FIXED_STRING_APPEND(8816CF48, 0x100)
FIXED_STRING_APPEND(88186AB8, 0x200)
FIXED_STRING_APPEND(88186C00, 0x34)
FIXED_STRING_APPEND(88259F20, 0x80)
