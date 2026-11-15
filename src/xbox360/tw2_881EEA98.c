/* Twin of 0x881EF098 (ts4_buf400_localize_881EF098 in src/xbox360/cw9_core_a.c), inline capacity 4. */
typedef unsigned int u32;
extern void *fn_88562DC0(void *, void *, u32);

typedef struct Cw9Buf4x { u32 pad[0x20]; u32 *data; u32 size; u32 cap; } Cw9Buf4x;
void ts4_buf400_localize_881EEA98(Cw9Buf4x *b)
{
    if (b->cap < 4) {
        if (b->data == 0) {
            b->cap = 4;
        } else {
            u32 n = b->size >> 3;
            u32 nc, sum;
            if (n < 4) n = 4; else if (n > 0x400) n = 0x400;
            sum = b->cap + n;
            nc = (sum > 4) ? sum : 4;
            fn_88562DC0(b, b->data, b->size << 5);
            b->cap = nc;
        }
        b->data = (u32 *)b;
    }
}
