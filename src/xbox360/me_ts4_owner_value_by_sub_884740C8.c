/* Swing_DLL.xex 0x884740C8: finds the pair (array at +0x5c, count +0x60) whose second pointer is the sub-object at x+0x10
 * and returns the word at +8 of its first pointer, or 0. agO: lookalike of 884AD868, plain and LTCG. */
typedef struct Owner { char pad[8]; int value; } Owner;
typedef struct Pair { Owner *owner; char *sub; } Pair;
typedef struct Obj { char pad[0x5c]; Pair *pairs; int count; } Obj;

int fn_884740C8(Obj *o, char *x)
{
    int i;
    for (i = 0; i < o->count; i++) {
        if (o->pairs[i].sub == x + 0x10)
            return o->pairs[i].owner->value;
    }
    return 0;
}
