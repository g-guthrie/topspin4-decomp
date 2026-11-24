/* Swing_DLL.xex 0x8883EC28: set target->current = key when the self-relative table at +0x6c lists key */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b139. */
typedef unsigned int u32;
typedef struct Rec12 { u32 key; u32 w[2]; } Rec12;
typedef struct Table12 { int data_offset; int count; } Table12;
typedef struct Target { int pad; u32 current; } Target;
typedef struct Obj { char pad[0x24]; Target *target; char pad2[0x44]; Table12 *table; } Obj;

static __forceinline Rec12 *table12_find(Table12 *self, u32 key)
{
    Rec12 *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec12 *r = (Rec12 *)((char *)self + self->data_offset) + i;
        if (r->key == key) {
            result = r;
            break;
        }
    }
    return result;
}

/* Selects key on the target when the table at +0x6c contains it. */
void fn_8883EC28(Obj *o, u32 key)
{
    if (table12_find(o->table, key) != 0)
        o->target->current = key;
}
