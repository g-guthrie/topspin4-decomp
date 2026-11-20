/* Swing_DLL.xex 0x88499548: append opcode 11 to the inner op list, set flag +0x17 */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b135. */
typedef struct IntVec { int *base; int size; int cap; } IntVec;
typedef struct Inner { char pad[0x1c]; IntVec ops; } Inner;
typedef struct Obj { void *vtbl; Inner *inner; char pad[0x17 - 8]; unsigned char flag; } Obj;
void fn_8841C678(IntVec *v, int elem_size);

/* Appends opcode 11 to the inner op list and sets the byte flag at 0x17. */
void fn_88499548(Obj *o)
{
    IntVec *v = &o->inner->ops;
    if (v->size == (v->cap & 0x3fffffff))
        fn_8841C678(v, 4);
    v->base[v->size] = 11;
    v->size++;
    o->flag = 1;
}
