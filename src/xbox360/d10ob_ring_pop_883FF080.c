/* Swing_DLL.xex 0x883FF080-0x883FF0FC, executable version 0.0.0.3. */
typedef struct Q { char pad0[8]; unsigned int *buf; unsigned int cap; unsigned int count; unsigned int head; } Q;

void ts4_ring_pop_883FF080(Q *o, unsigned int *out)
{
    if (o->count == 0) {
        if (out != 0)
            *out = o->count;
        return;
    }
    if (out != 0)
        *out = o->buf[o->head];
    o->buf[o->head] = 0;
    o->head = (o->head + 1) % o->cap;
    o->count--;
}
