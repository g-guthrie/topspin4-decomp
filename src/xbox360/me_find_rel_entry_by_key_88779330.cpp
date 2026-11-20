/* 0x88779330: find the 0x48-byte self-relative table entry (table fetched through vtable slot 0x4C, index 0) whose key at +0x30 equals *key; null if none. */
typedef unsigned int u32;
typedef struct { char p0[0x30]; u32 key; char p34[0x14]; } RelEntry;
typedef struct { u32 rel; u32 count; } Table;
struct Src { virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual Table *table(int index); };
struct Obj { char p0[0x300]; Src *src; };
extern "C" RelEntry *fn_88779330(Obj *o, const u32 *key)
{
    Table *t = o->src->table(0);
    RelEntry *r = 0;
    u32 i;
    for (i = 0; t->count > i; i++) {
        RelEntry *e = (RelEntry *)((char *)t + (i * sizeof(RelEntry) + t->rel));
        if (*key == e->key) { r = e; break; }
    }
    return r;
}
