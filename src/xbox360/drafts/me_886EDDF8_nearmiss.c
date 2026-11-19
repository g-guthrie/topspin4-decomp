/* 0x886EDDF8 near miss (agW, /Oc and /Os): 1 off, operand order of the second cmplw (target r8,r9 = it->b,*b; here r9,r8). */
/* Finds the first 0xbc-byte item in [first,last) whose +0xa4 equals *a and +0x84 equals *b. `*a == it->a` forms are 2 off. */
typedef struct { char pad[0x84]; unsigned int b; char pad2[0x1c]; unsigned int a; char pad3[0x14]; } It;
typedef struct { char pad[0x1c]; It *first; It *last; } O;
It *ts4_find_pair_886EDDF8(O *o, unsigned int *a, unsigned int *b)
{
    It *it;
    for (it = o->first; it != o->last; it++)
        if (it->a == *a && *b == it->b) return it;
    return 0;
}
