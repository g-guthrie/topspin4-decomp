typedef unsigned int u32;
struct vec { u32 *first; u32 *last; };
typedef struct { char pad[0xc]; u32 idx; char pad2[0x14-0x10]; } MapEnt;
typedef struct { int off; int count; } MapTab;
typedef struct { int pad0; struct vec out; int pad1[1]; MapTab *tab; } MapObj;
extern void ts4_vec_resize_881609C8(struct vec *v, u32 n);
static __inline MapEnt *map_ent(MapTab *t, int i) { return (MapEnt *)((char *)t + t->off) + i; }
void fn_8876E380(MapObj *o, MapTab *t, struct vec *src)
{
    o->tab = t;
    if (t) {
        int n = t->count, i;
        ts4_vec_resize_881609C8(&o->out, n);
        for (i = 0; i < n; i++)
        {
            u32 *s = src->first;
            u32 *d = o->out.first;
            d[i] = s[map_ent(o->tab, i)->idx];
        }
    }
}
