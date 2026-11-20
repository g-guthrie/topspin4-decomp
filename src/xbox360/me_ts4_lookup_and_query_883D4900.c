/* 0x883D4900: 0x25 for null key/out, 0x1F without the map at +0x8044, 0x5B when fn_883E4F58 finds nothing; then queries via fn_883D38C8 (flag 4) or fn_883DA438(obj->owner, ...) */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Obj { char pad[0x28]; void *owner; } Obj;
typedef struct T { char pad[0x8044]; void *map; } T;
Obj *fn_883E4F58(void *map, void *key);
int fn_883D38C8(T *t, Obj *o, void *out, unsigned int flags, int a);
int fn_883DA438(void *owner, Obj *o, void *out, unsigned int flags);
int ts4_lookup_and_query_883D4900(T *t, void *key, unsigned int flags, void *out)
{
    Obj *o;
    int r;
    if (!key || !out)
        return 0x25;
    if (!t->map)
        return 0x1f;
    o = fn_883E4F58(t->map, key);
    if (!o)
        return 0x5b;
    if (flags & 4) {
        r = fn_883D38C8(t, o, out, flags, 0);
        if (r)
            return r;
    } else {
        r = fn_883DA438(o->owner, o, out, flags);
        if (r)
            return r;
    }
    return 0;
}
