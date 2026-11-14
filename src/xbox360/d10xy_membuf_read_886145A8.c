/* Swing_DLL.xex 0x886145A8-0x88614644, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct {
    u32 pad[5];
    int pos;
    int size;
    char *data;
} ts4_membuf;

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned long);
#else
#include <string.h>
#endif

int ts4_membuf_read_886145A8(ts4_membuf *self, void *dst, int n)
{
    int r = 0;
    int pos = self->pos;
    int end;
    char *src;

    if (pos >= 0) {
        end = pos + n;
        if (end >= self->size)
            end = self->size;
        r = end - pos;
        if (r != 0) {
            src = 0;
            if (pos < self->size)
                src = self->data + pos;
            memcpy(dst, src, r);
            self->pos = r + self->pos;
        }
    }
    return r;
}
