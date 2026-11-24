/* Swing_DLL.xex small byte-string template instances (FAM3).
   MSVC 16.00.10224.00 /O2 /Oi.

   The string is {first, last, ...} with a terminating NUL kept after last.
   Each instantiation differs only in the out-of-line append routine it
   uses when the source is longer than the current contents. */
typedef unsigned int u32;

typedef struct Ts4ByteString {
    char *first;
    char *last;
} Ts4ByteString;

#ifdef _MSC_VER
extern unsigned int strlen(const char *);
void *memcpy(void *dst, const void *src, unsigned int size);
#else
#include <string.h>
#define __forceinline inline
#endif
void *fn_88562DC0(void *dst, const void *src, u32 size); /* memmove */

void fn_8815D9D8(Ts4ByteString *self, const char *from, const char *to);
void ts4_fixed_string_append_8816BBD8(Ts4ByteString *self, const char *from, const char *to);
void ts4_fixed_string_append_8816CF48(Ts4ByteString *self, const char *from, const char *to);
void ts4_fixed_string_append_88186AB8(Ts4ByteString *self, const char *from, const char *to);
void ts4_fixed_string_append_88186C00(Ts4ByteString *self, const char *from, const char *to);
void ts4_fixed_string_append_88259F20(Ts4ByteString *self, const char *from, const char *to);

/* Erases [where, end) where end is the current last, moving the NUL down. */
static __forceinline void ts4_byte_string_erase_tail(Ts4ByteString *self, char *where, char *end)
{
    if (where != end) {
        u32 n = (u32)(self->last - end) + 1;
        if (n)
            fn_88562DC0(where, end, n);
        self->last = where + (self->last - end);
    }
}

/* Assigns another string: overwrite in place, then erase the excess or
   append the rest of the source. */
#define BYTE_STRING_ASSIGN(A, APPEND) \
Ts4ByteString *ts4_byte_string_assign_##A(Ts4ByteString *self, const Ts4ByteString *src) \
{ \
    if (src != self) { \
        const char *to = src->last; \
        const char *from = src->first; \
        char *dst = self->first; \
        for (; from != to && dst != self->last; ++dst, ++from) \
            *dst = *from; \
        if (from == to) \
            ts4_byte_string_erase_tail(self, dst, self->last); \
        else \
            APPEND(self, from, to); \
    } \
    return self; \
}

/* Assigns a C string. */
#define BYTE_STRING_ASSIGN_CSTR(A, APPEND) \
Ts4ByteString *ts4_byte_string_assign_cstr_##A(Ts4ByteString *self, const char *s) \
{ \
    const char *e = s + strlen(s); \
    u32 size = (u32)(self->last - self->first); \
    u32 n = (u32)(e - s); \
    if (n <= size) { \
        if (n) \
            memcpy(self->first, s, n); \
        ts4_byte_string_erase_tail(self, self->first + n, self->last); \
    } else { \
        const char *mid; \
        if (size) \
            memcpy(self->first, s, size); \
        mid = s + (self->last - self->first); \
        if (mid != e) \
            APPEND(self, mid, e); \
    } \
    return self; \
}

/* Swing_DLL.xex addresses */
BYTE_STRING_ASSIGN(88158908, fn_8815D9D8)
BYTE_STRING_ASSIGN(8815F510, ts4_fixed_string_append_8816BBD8)
BYTE_STRING_ASSIGN(8816D090, ts4_fixed_string_append_8816CF48)
BYTE_STRING_ASSIGN(8817D8B8, ts4_fixed_string_append_88186C00)
BYTE_STRING_ASSIGN(881A52D8, ts4_fixed_string_append_88186AB8)
BYTE_STRING_ASSIGN_CSTR(88166D08, ts4_fixed_string_append_8816BBD8)
BYTE_STRING_ASSIGN_CSTR(88181EF8, ts4_fixed_string_append_88186AB8)
BYTE_STRING_ASSIGN_CSTR(88182330, ts4_fixed_string_append_8816CF48)
BYTE_STRING_ASSIGN_CSTR(88182828, ts4_fixed_string_append_88186C00)
BYTE_STRING_ASSIGN_CSTR(88235298, ts4_fixed_string_append_88259F20)
