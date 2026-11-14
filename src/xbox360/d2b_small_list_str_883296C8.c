#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
/* Swing_DLL.xex 0x883296C8-0x8842566C, executable version 0.0.0.3. */
typedef unsigned char u8;

struct ts4_list_link {
    int unused0;
    struct ts4_list_link *next;
};

/* Appends a NUL-terminated string to the end of a buffer. */
void ts4_string_append_883296C8(char *dst, const char *src)
{
    char *end = dst;
    u8 c;
    while (*end) {
        end++;
    }
    do {
        c = (u8)*src++;
        *end++ = (char)c;
    } while (c);
}

/* Writes whether a node is reachable from the key by following next links. */
static void ts4_loop_get_u32_off4_8841EB08(u8 *out, struct ts4_list_link *start, struct ts4_list_link *key)
{
    struct ts4_list_link *p = key;
    while (p) {
        if (p == start) {
            *out = 1;
            return;
        }
        p = p->next;
    }
    *out = 0;
}

#ifdef _MSC_VER
#define TS4_FORCEINLINE __forceinline
#else
#define TS4_FORCEINLINE inline __attribute__((unused))
#endif

static TS4_FORCEINLINE void ts4_swap_float(float *a, float *b)
{
    float t = *a;
    *a = *b;
    *b = t;
}
