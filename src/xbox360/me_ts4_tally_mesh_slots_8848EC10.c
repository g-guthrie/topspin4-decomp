/* 0x8848EC10: For each mesh in the list, marks its mapped slot as used and adds max(instances, 1) to that slot count. */
/* Matched on /Oc (agAH). A ternary on a separate n local; the if-default form misses. */
typedef struct Mesh { char p0[0x9c]; unsigned short instances; } Mesh;
typedef struct MeshList { Mesh **items; int count; } MeshList;
typedef struct IdArr { int *ids; } IdArr;
typedef struct Mapping { IdArr *slots; } Mapping;
typedef struct IntArr { int *v; } IntArr;
void fn_8848EC10(const Mapping *map, const MeshList *list, IntArr *used, IntArr *counts)
{
    int i;
    for (i = 0; i < list->count; i++) {
        Mesh *m = list->items[i];
        int slot = map->slots->ids[i];
        int n;
        used->v[slot] = 1;
        n = m->instances;
        counts->v[slot] += n < 1 ? 1 : n;
    }
}
