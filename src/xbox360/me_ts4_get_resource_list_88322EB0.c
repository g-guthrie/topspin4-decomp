/* Swing_DLL.xex 0x88322EB0: copies the resource list into out and its length into *outCount: the group's list (+0x7C/+0x80)
 * when slot 0 reports isGroup (vtable slot 2), otherwise the set's own (+0x48/+0x4C). agAE: /Oc. */
typedef struct Res Res;
typedef struct ResVt { void *slots[2]; unsigned char (*isGroup)(Res *r); } ResVt;
struct Res { ResVt *vt; char pad4[0x7c - 4]; int count; Res *items[1]; };
typedef struct Set { char pad[0x48]; int count; Res *items[1]; } Set;
int fn_88322EB0(Set *s, Res **out, int *outCount)
{
    int i;
    if (s->items[0]->vt->isGroup(s->items[0])) {
        Res *g = s->items[0];
        if (out)
            for (i = 0; i < g->count; i++) out[i] = g->items[i];
        if (!outCount) return 0;
        *outCount = g->count;
        return 0;
    }
    if (out)
        for (i = 0; i < s->count; i++) out[i] = s->items[i];
    if (!outCount) return 0;
    *outCount = s->count;
    return 0;
}
