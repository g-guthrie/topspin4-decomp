/* CW9 part a: game core 0x881EEBB0-0x8820F390 (containers, loaders). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern void *fn_88562DC0(void *, void *, u32);
extern void fn_881992A8(u32, void *);
extern void *ts4_if_call_seq_u32_off0_8818C588(void *self, u32 bytes);

/* Hash-table style storage with an inline buffer: when the heap block is too small, copy the
   contents (via fn_88562DC0) back into the inline area and grow the recorded capacity. */
typedef struct Cw9Buf400 { u32 pad[0x400]; u32 *data; u32 size; u32 cap; } Cw9Buf400;
/* 0x881EF098: inline capacity 0x400, 4-byte entries */
void ts4_buf400_localize_881EF098(Cw9Buf400 *b)
{
    if (b->cap < 0x400) {
        if (b->data == 0) {
            b->cap = 0x400;
        } else {
            u32 n = b->size >> 3;
            u32 nc, sum;
            if (n < 4) n = 4; else if (n > 0x400) n = 0x400;
            sum = b->cap + n;
            nc = (sum > 0x400) ? sum : 0x400;
            fn_88562DC0(b, b->data, b->size << 2);
            b->cap = nc;
        }
        b->data = (u32 *)b;
    }
}

typedef struct Cw9Buf4 { u32 pad; u32 *data; u32 size; u32 cap; } Cw9Buf4;
/* 0x881EF3D0: inline capacity 4 */
void ts4_buf4_localize_881EF3D0(Cw9Buf4 *b)
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
            fn_88562DC0(b, b->data, b->size);
            b->cap = nc;
        }
        b->data = (u32 *)b;
    }
}

typedef struct Cw9Buf5 { u32 pad[0xf]; u32 *data; u32 size; u32 cap; } Cw9Buf5;
/* 0x881EF468: inline capacity 5, 12-byte entries */
void ts4_buf5x12_localize_881EF468(Cw9Buf5 *b)
{
    if (b->cap < 5) {
        if (b->data == 0) {
            b->cap = 5;
        } else {
            u32 n = b->size >> 3;
            u32 nc;
            if (n < 4) n = 4; else if (n > 0x400) n = 0x400;
            nc = b->cap + n;
            if (nc <= 5) nc = 5;
            fn_88562DC0(b, b->data, b->size * 12);
            b->cap = nc;
        }
        b->data = (u32 *)b;
    }
}

typedef struct Cw9Arr24 { u32 pad0; char *data; u32 size; u32 cap; } Cw9Arr24;
/* 0x881EF510: reserve capacity for n 24-byte entries (grows by max(cap + clamp(size/8), n)) */
void ts4_arr24_reserve_881EF510(Cw9Arr24 *a, u32 n)
{
    if (n > a->cap) {
        if (a->data == 0) {
            a->data = ts4_if_call_seq_u32_off0_8818C588(a, n * 24);
            if (a->data == 0) return;
            a->cap = n;
        } else {
            u32 g = a->size >> 3;
            u32 nc, sum;
            char *nd;
            if (g < 4) g = 4; else if (g > 0x400) g = 0x400;
            sum = a->cap + g;
            nc = (n < sum) ? sum : n;
            nd = ts4_if_call_seq_u32_off0_8818C588(a, nc * 24);
            if (nd == 0) return;
            fn_88562DC0(nd, a->data, a->size * 24);
            if (a->data != 0) fn_881992A8(0, a->data);
            a->data = nd;
            a->cap = nc;
        }
    }
}

typedef struct Cw9Node Cw9Node;
struct Cw9Node { u32 pad0[4]; Cw9Node *parent; Cw9Node *first; Cw9Node *next; };

/* 0x881F4CC8: detach a node from its parent's singly linked child list */
void ts4_node_unlink_881F4CC8(Cw9Node *n)
{
    Cw9Node *p = n->parent;
    if (p != 0) {
        Cw9Node **slot = &p->first;
        while (*slot != 0) {
            Cw9Node *cur = *slot;
            if (cur == n) {
                *slot = n->next;
                break;
            }
            slot = &cur->next;
        }
        n->parent = 0;
    }
    n->next = 0;
}
