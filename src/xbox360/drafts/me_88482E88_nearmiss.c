/* NEAR MISS (agO, 2026-11-19): 5 off on plain and LTCG (/Oc), registers only in the push tail: the target keeps n+1 in r11
 * (addi r11,r11,1) with base in r9. Model 88477DC8; tried ++, n+1, pointer, shift and order variants. */
/* Swing_DLL.xex 0x88482E88: if *item is non-zero and fn_88478548 does not already account for it, append the item pointer
 * to the list at +0x150 (grows through fn_8841C678 when size == capacity). */
typedef struct IntVec { int *base; int size; int cap; } IntVec;
typedef struct Obj { char pad[0x150]; IntVec list; } Obj;
void fn_8841C678(IntVec *v, int elem_size);
int fn_88478548(Obj *o, int value);

void fn_88482E88(Obj *o, int *item)
{
    IntVec *v;
    if (*item == 0)
        return;
    if (fn_88478548(o, (int)item) != 0)
        return;
    v = &o->list;
    if (v->size == (v->cap & 0x3fffffff))
        fn_8841C678(v, 4);
    { int n = v->size; v->size = n + 1; v->base[n] = (int)item; }
}
