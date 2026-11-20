/* Swing_DLL.xex 0x8849A7F0: append opcode 0 to the inner op list */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b135. */
typedef struct IntVec { int *base; int size; int cap; } IntVec;
typedef struct Inner { char pad[0x1c]; IntVec ops; } Inner;
typedef struct Obj { void *vtbl; Inner *inner; int depth; } Obj;
void fn_8841C678(IntVec *v, int elem_size);

/* Appends opcode 0 to the inner op list. */
void fn_8849A7F0(Obj *o)
{
    IntVec *v;
    v = &o->inner->ops;
    if (v->size == (v->cap & 0x3fffffff))
        fn_8841C678(v, 4);
    v->base[v->size] = 0;
    v->size++;
}
