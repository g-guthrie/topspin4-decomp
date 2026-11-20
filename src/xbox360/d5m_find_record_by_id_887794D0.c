/* Swing_DLL.xex 0x887794D0-0x88779558, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
struct Slot98 { u8 pad[0x74]; u32 id; u8 pad2[0x20]; };
struct Owner {
    u8 pad0[0xa4];
    struct Slot98 *slots;
    u32 count;
};
struct Table {
    u8 p0[0x1c]; int defaultIdx; u8 p1[0x10]; int *map; int mapCount; u8 p2[4]; u8 *recs;
};
struct Root { u8 p[0x234]; struct Table *tbl; };
extern struct Root *lbl_88D45B1C;
u8 *ts4_find_record_887794D0(struct Owner *o, u8 id)
{
    u32 i;
    struct Table *t;
    int idx;
    for (i = 0; i < o->count; i++) {
        if (id == o->slots[i].id) {
            t = lbl_88D45B1C->tbl;
            idx = (int)i;
            if (idx >= t->mapCount || (idx = t->map[idx]) == -1) idx = t->defaultIdx;
            return t->recs + idx * 0xc4;
        }
    }
    return 0;
}
