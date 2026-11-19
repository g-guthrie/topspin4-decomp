/* Swing_DLL.xex 0x881AC7D0: find 8-byte record by key in the self-relative table at +0xc */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b135. */
typedef unsigned int u32;
typedef struct Rec8 { u32 key; u32 value; } Rec8;
typedef struct Table8 { int data_offset; int count; } Table8;
typedef struct Owner { char pad[0xc]; Table8 table; } Owner;

/* Linear search of the self-relative table at +0xc (8-byte records, key at +0x0) for *key. */
static __forceinline void *table8_find(Table8 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec8 *r = (Rec8 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

void *fn_881AC7D0(Owner *o, const u32 *key)
{
    return table8_find(&o->table, key);
}
