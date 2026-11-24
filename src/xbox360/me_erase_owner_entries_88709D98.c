
typedef unsigned int u32;
typedef struct E { char pad[0x58]; u32 owner; char pad2[0xc]; } E;
typedef struct V { E *first; E *last; } V;
typedef struct Sub { char pad[0xc]; void *c; } Sub;
typedef struct G { char pad[0x27c]; u32 owner; } G;
typedef struct O { char pad[0x34]; Sub *sub; char pad2[0x48]; V v; } O;
extern G *lbl_88D45B1C;
extern E *fn_8823DF18(E *src, E *end, E *dst);
static void vclear(V *v)
{
    v->last = fn_8823DF18(v->last, v->last, v->first);
}
/* 0x88709D98: when the sub-object is live, erase every 0x68-byte entry owned by the current owner or by key (all entries if key is the current owner) */
void ts4_erase_owner_entries_88709D98(O *o, u32 key)
{
    G *g;
    E *it;
    if (!o->sub || !o->sub->c) return;
    g = lbl_88D45B1C;
    if (g->owner == key) {
        vclear(&o->v);
        return;
    }
    for (it = o->v.first; it != o->v.last; ) {
        if (g->owner == it->owner || it->owner == key) {
            V *v = &o->v;
            if (it + 1 != v->last) fn_8823DF18(it + 1, v->last, it);
            v->last--;
        } else {
            it++;
        }
    }
}
