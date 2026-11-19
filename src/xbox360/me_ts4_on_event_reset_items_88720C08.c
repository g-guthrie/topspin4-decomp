/* 0x88720C08: event handler: unless the event is one of three focus events, clear the active flag (+0x60) and
 * reset every item of every group (+0x95, +0x9c, +0xa0); two of the focus events set the flag again; event
 * 0x04C901D9 also runs the refresh. */
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Item { u8 r[0x95]; u8 sel; u8 r96[6]; u32 a; u32 b; } Item;
typedef struct Group { u8 r[0x18]; Item **first; Item **last; } Group;
typedef struct Sub { u8 r[0xc]; void *ready; } Sub;
typedef struct Obj { u8 r[0x34]; Sub *sub; Group **first; Group **last; u8 r40[0x20]; u8 active; } Obj;
extern void fn_8871B870(Obj *o);
void ts4_on_event_reset_items_88720C08(Obj *o, u32 *ev)
{
    if (o->sub && o->sub->ready) {
        if (*ev != 0x1dca7285 && *ev != 0xde9bf1c4 && *ev != 0x9ff0bd90) {
            Group **g = o->first, **ge = o->last;
            o->active = 0;
            for (; g != ge; g++) {
                Item **e = (*g)->first, **ee = (*g)->last;
                for (; e != ee; e++) {
                    Item *it = *e;
                    it->sel = 0; it->a = 0; it->b = 0;
                }
            }
        }
        if (*ev == 0xde9bf1c4 || *ev == 0x9ff0bd90) o->active = 1;
        if (*ev == 0x04c901d9) fn_8871B870(o);
    }
}
