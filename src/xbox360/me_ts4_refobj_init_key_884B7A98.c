/* 0x884B7A98: Initialises a refcounted object: refs (+6) = 1, vtable lbl_880895C4, 8-byte key copied from *key to +8, +0x10 = 0; returns the object. */
/* Matched on /Oc (agAH). 8-byte key as a struct assignment. */
extern void *lbl_880895C4;
typedef struct Pair { int a, b; } Pair;
typedef struct RefObj { void *vtable; short unk4; short refs; Pair key; int x10; } RefObj;
RefObj *fn_884B7A98(RefObj *o, const Pair *key)
{
    o->refs = 1;
    o->vtable = &lbl_880895C4;
    o->key = *key;
    o->x10 = 0;
    return o;
}
