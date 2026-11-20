/* 0x883E5F30: when a is in state 1 or 4 and b (non-null) is in state 2, 3 or 4, rebases a 64-bit [start, end) range so that start = b->end - a->base, keeping its length. */
/* Matched on /O1 (agAF). Length local first, start stored, then end = start + len. */
typedef struct T { char p[0x18]; __int64 start; __int64 end; __int64 base; int state; } T;
void fn_883E5F30(T *a, T *b)
{
    if (b && (a->state == 1 || a->state == 4) && (b->state == 2 || b->state == 3 || b->state == 4)) {
        __int64 len = a->end - a->start;
        a->start = b->end - a->base;
        a->end = a->start + len;
    }
}
