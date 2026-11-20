/* Swing_DLL.xex 0x8849A688: decrement depth, append opcode 0x17 to the inner op list */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b135. */
typedef struct IntVec { int *base; int size; int cap; } IntVec;
typedef struct Inner { char pad[0x1c]; IntVec ops; } Inner;
typedef struct Obj { void *vtbl; Inner *inner; int depth; } Obj;
void fn_8841C678(IntVec *v, int elem_size);

/* Decrements the nesting depth and appends opcode 0x17 to the inner op list. */
void fn_8849A688(Obj *o)
{
    IntVec *v;
    o->depth--;
    v = &o->inner->ops;
    if (v->size == (v->cap & 0x3fffffff))
        fn_8841C678(v, 4);
    v->base[v->size] = 0x17;
    v->size++;
}
