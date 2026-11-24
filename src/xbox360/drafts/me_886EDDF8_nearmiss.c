/* 0x886EDDF8: find the 0xBC-byte entry in [+0x1C,+0x20) whose +0xA4 == *a and +0x84 == *b; 0 if none. */
/* Near-miss on /Oc (agAB): 1 instruction off at +0x2C. The target loads *b before it->b but still compares cmplw it->b,*b; this form gets the load order right and swaps the cmplw operands. */
typedef struct E { char p[0x84]; unsigned int b; char p88[0xa4 - 0x88]; unsigned int a; char pa8[0xbc - 0xa8]; } E;
typedef struct T { char p[0x1c]; E *begin; E *end; } T;
E *fn_886EDDF8(T *t, const unsigned int *a, const unsigned int *b)
{
    E *it = t->begin, *end = t->end;
    for (; it != end; it++)
        if (it->a == *a && *b == it->b)
            return it;
    return 0;
}
