/* 0x883D4890: 0x1F without the map at +0x809C, 0x25 for null out or index past count; then queries items[index] via fn_883D38C8 (flag 4) or fn_883DA438(owner, ...) */
/* Matched on /O1 (agAH). Index sibling of 883D4900. An inline owner accessor loads the item straight into r4. */
typedef struct Obj { char pad[0x28]; void *owner; } Obj;
typedef struct T { char p0[0x3c]; unsigned int count; char p40[4]; Obj *items[0x2000]; char pad[0x58]; void *map; } T;
int fn_883D38C8(T *t, Obj *o, void *out, unsigned int flags, int a);
int fn_883DA438(void *owner, Obj *o, void *out, unsigned int flags);
static __inline void *owner_of(Obj *o) { return o->owner; }
int fn_883D4890(T *t, unsigned int index, unsigned int flags, void *out)
{
    if (!t->map)
        return 0x1f;
    if (!out)
        return 0x25;
    if (index >= t->count)
        return 0x25;
    if (flags & 4)
        return fn_883D38C8(t, t->items[index], out, flags, 0);
    return fn_883DA438(owner_of(t->items[index]), t->items[index], out, flags);
}
