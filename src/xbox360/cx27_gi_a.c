/* CX27 gi a: small-buffer grow functions, /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
extern void *fn_88562DC0(void *dst, const void *src, u32 n);

typedef struct GiSb38 { u8 buf[0x380]; void *data; u32 count; u32 cap; } GiSb38;

/* 0x881C6998: grow the capacity to at least n, by count/8 (4..1024) when growing from a live block */
void ts4_sb38_grow_881C6998(GiSb38 *s, u32 n)
{
    u32 cap = s->cap;
    if (n > cap) {
        if (s->data != 0) {
            u32 count = s->count;
            u32 g = count >> 3;
            if (g < 4) g = 4;
            else if (g > 0x400) g = 0x400;
            g = s->cap + g;
            if (n < g) n = g;
            fn_88562DC0(s, s->data, count * 0x38);
        }
        s->cap = n;
        s->data = s;
    }
}

typedef struct GiSb18 { u8 buf[0x2d0]; void *data; u32 count; u32 cap; } GiSb18;

/* 0x881C2660 */
void ts4_sb18_grow_881C2660(GiSb18 *s, u32 n)
{
    u32 cap = s->cap;
    if (n > cap) {
        if (s->data != 0) {
            u32 count = s->count;
            u32 g = count >> 3;
            if (g < 4) g = 4;
            else if (g > 0x400) g = 0x400;
            g = s->cap + g;
            if (n < g) n = g;
            fn_88562DC0(s, s->data, count * 0x18);
        }
        s->cap = n;
        s->data = s;
    }
}
