/* Swing_DLL.xex 0x88474028: clears the slot holding value in the pointer list at +0xcc (16-bit count). When value is
 * absent the index stays -1 and the word before the array is cleared, as in the original. agO: lookalike of 88427878, plain and LTCG. */
typedef struct PtrList { void **items; unsigned short count; } PtrList;
typedef struct Obj { char pad[0xcc]; PtrList *list; } Obj;

static __inline int index_of(PtrList *l, void *value)
{
    int i;
    for (i = 0; i < l->count; i++) {
        if (l->items[i] == value)
            return i;
    }
    return -1;
}

void fn_88474028(Obj *o, void *value)
{
    PtrList *l = o->list;
    l->items[index_of(l, value)] = 0;
}
