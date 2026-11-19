/* 0x88660470: 1 when the two cursors are at different indices and at least one of them is in range.
 * LTCG: the target keeps b in r4 across the first call (the callee does not touch r4). The callee context is
 * compiled with /Ob1 so that it is not inlined. */
typedef unsigned char u8;
typedef struct Cursor { int index; int list; } Cursor;
u8 ts4_cursor_out_of_range_886603C0(Cursor *c);
u8 ts4_cursors_differ_either_in_range_88660470(Cursor *a, Cursor *b)
{
    if (a->index != b->index && (!ts4_cursor_out_of_range_886603C0(a) || !ts4_cursor_out_of_range_886603C0(b)))
        return 1;
    return 0;
}
