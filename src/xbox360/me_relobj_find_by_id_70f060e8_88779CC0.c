/* 0x88779CC0: hash the key and find the 0x70F060E8-typed entry of a self-relative table whose object id matches. */
typedef struct RelObj { char pad[0x18]; unsigned id; } RelObj;
typedef struct RelEnt { int rel; unsigned type; } RelEnt;
typedef struct RelEntArr { int rel; unsigned count; } RelEntArr;
typedef struct RelOwner { char pad[0x18]; RelEntArr arr; } RelOwner;
unsigned ts4_crc32_cstr_seed_88608590(int ctx, unsigned key);
RelObj *relobj_find_by_id_70f060e8_88779CC0(RelOwner *o, unsigned *key)
{
    unsigned id = ts4_crc32_cstr_seed_88608590(0, *key);
    RelEntArr *a = &o->arr;
    RelObj *r = 0;
    unsigned i;
    for (i = 0; a->count > i; i++) {
        RelEnt *e = (RelEnt *)((char *)a + (i * sizeof(RelEnt) + a->rel));
        if (e->type == 0x70F060E8) {
            r = (RelObj *)((char *)e + e->rel);
            if (id == r->id) break;
            r = 0;
        }
    }
    return r;
}
