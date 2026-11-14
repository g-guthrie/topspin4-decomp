/* Loader_DLL.xex 0x8311B4D8-0x83152F10, executable version 0.0.0.3. */
/* Buffer descriptors: remember the buffer and size, and zero the buffer (memset). */
typedef unsigned int u32;
#ifdef _MSC_VER
extern void *memset(void *d, int c, u32 n);
#else
#include <string.h>
#endif

void ts4l_set_buf_8311B4D8(char *self, void *a, u32 n)
{
    *(void **)(self + 0x10) = a;
    memset(a, 0, n);
    *(u32 *)(self + 0xc) = n;
}

void ts4l_set_buf_8311DC58(char *self, void *a, u32 n)
{
    *(void **)(self + 0x10) = a;
    memset(a, 0, n);
    *(u32 *)(self + 0xc) = n;
}

void ts4l_set_buf_83123118(char *self, void *a, u32 n)
{
    *(void **)(self + 0x10) = a;
    memset(a, 0, n);
    *(u32 *)(self + 0xc) = n;
}

void ts4l_set_buf_8313F370(char *self, void *a, u32 n)
{
    *(void **)(self + 0x10) = a;
    memset(a, 0, n);
    *(u32 *)(self + 0xc) = n;
}

void ts4l_set_buf_83141F60(char *self, void *a, u32 n)
{
    *(void **)(self + 0x10) = a;
    memset(a, 0, n);
    *(u32 *)(self + 0xc) = n;
}

void ts4l_set_buf_83123628(char *self, void *a, u32 n)
{
    *(void **)(self + 0xc) = a;
    memset(a, 0, n);
    *(u32 *)(self + 8) = n;
}

typedef struct Ts4lInitA { int a[3]; char m[0x1c]; int b[10]; } Ts4lInitA;
Ts4lInitA *ts4l_init_83151090(Ts4lInitA *s)
{
    s->a[0] = 0;
    s->a[1] = 0;
    s->a[2] = 0;
    memset(s->m, 0, 0x1c);
    s->b[0] = 0; s->b[1] = 0; s->b[2] = 0; s->b[3] = 0; s->b[4] = 0;
    s->b[5] = 0; s->b[6] = 0; s->b[7] = 0; s->b[8] = 0;
    return s;
}

void *ts4l_init_83152F10(char *s)
{
    *(int *)(s + 0x190) = 0;
    memset(s, 0, 0x64);
    *(int *)(s + 0x324) = 0;
    memset(s + 0x194, 0, 0x64);
    return s;
}
