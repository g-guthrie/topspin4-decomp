/* 0x886603C0: 1 when the cursor has no list, the list item vector (+0x7C, 8-byte items) is empty, or the index is outside [0, size) */
/* Matched on /Oc (agAL). Plain route. Return the || condition directly (li/clrlwi bool tail); the list handle is tested with cmpwi, so it is an int handle cast at the dereference. */
typedef unsigned char u8;
typedef struct Item8 { int a, b; } Item8;
typedef struct Vec8 { Item8 *first; Item8 *last; } Vec8;
typedef struct List { u8 pad[0x7c]; Vec8 items; } List;
typedef struct Cursor { int index; int list; } Cursor;

static int vsize(Vec8 *v) { return v->last - v->first; }

u8 ts4_cursor_out_of_range_886603C0(Cursor *c)
{
    return c->list == 0 || vsize(&((List *)c->list)->items) == 0 || c->index < 0 || c->index >= vsize(&((List *)c->list)->items);
}
