/* 0x888F4E70: reset. Erases every element of the vector at +0x0, empties the string buffer at +0xc
   (terminator at begin, end = begin), clears the vector at +0x18, and resets the flag at +0x38 and
   the two indices at +0x30/+0x34 to -1. */
typedef unsigned int u32;
typedef struct E10 E10;
typedef struct V10 { E10 *first, *end; } V10;
typedef struct StrBuf { char *begin, *end; } StrBuf;
typedef struct Vec12 { u32 w[3]; } Vec12;
typedef struct ResetObj { V10 items; u32 f8; StrBuf text; u32 f14; Vec12 v18; u32 pad[3]; int i30, i34; unsigned char b38; } ResetObj;
extern E10 *ts4_copy_down_8817EEB8(V10 *v, E10 *dst, E10 *src);
extern void ts4_vec12_move_tail_88161620(Vec12 *v);
static __inline void str_clear(StrBuf *s)
{
    if (s->begin != s->end) {
        *s->begin = 0;
        s->end = s->begin;
    }
}
void ts4_reset_obj_888F4E70(ResetObj *o)
{
    ts4_copy_down_8817EEB8(&o->items, o->items.first, o->items.end);
    str_clear(&o->text);
    ts4_vec12_move_tail_88161620(&o->v18);
    o->b38 = 0;
    o->i30 = -1;
    o->i34 = -1;
}
