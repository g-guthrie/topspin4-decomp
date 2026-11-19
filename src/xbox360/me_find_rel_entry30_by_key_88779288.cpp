/* 0x88779288: sibling of fn_88779330: find the 0x30-byte entry in the second self-relative array (+0xC) whose key at +0x24 equals *key; null if none. */
typedef unsigned int u32;
typedef struct { char p0[0x30]; u32 key; char p34[0x14]; } RelEntry;
typedef struct { char p0[0x24]; u32 key; char p28[8]; } RelEntry30;
typedef struct { u32 rel; u32 count; } RelArray;
typedef struct { u32 rel; u32 count; u32 pad8; RelArray second; } Table;
struct Src { virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual Table *table(int index); };
struct Obj { char p0[0x300]; Src *src; };
extern "C" RelEntry30 *fn_88779288(Obj *o, const u32 *key)
{
    Table *t = o->src->table(0);
    RelEntry30 *r = 0;
    u32 i;
    for (i = 0; t->second.count > i; i++) {
        RelArray *a = &t->second;
        RelEntry30 *e = (RelEntry30 *)((char *)a + (i * sizeof(RelEntry30) + a->rel));
        if (*key == e->key) { r = e; break; }
    }
    return r;
}
