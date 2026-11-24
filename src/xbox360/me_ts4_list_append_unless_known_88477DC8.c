/* Swing_DLL.xex 0x88477DC8: append value to the list at +0xc0 unless already accounted for */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b135. */
typedef struct IntVec { int *base; int size; int cap; } IntVec;
typedef struct Obj { char pad[0xc0]; IntVec list; } Obj;
void fn_8841C678(IntVec *v, int elem_size);
int fn_88478548(Obj *o, int value);

/* Appends value to the list at +0xc0 unless fn_88478548 already accounts for it. */
void fn_88477DC8(Obj *o, int value)
{
    IntVec *v;
    if (fn_88478548(o, value) != 0)
        return;
    v = &o->list;
    if (v->size == (v->cap & 0x3fffffff))
        fn_8841C678(v, 4);
    v->base[v->size] = value;
    v->size++;
}
