/* 0x886EDBC8: returns the index of the first 12-byte entry (vector begin/end) whose bytes +9 and +0xA equal a and b, stopping at an id (+0) of 0xFF; -1 if none. */
/* Matched on /Oc (agAF). Plain loop with the count re-derived from begin/end in the condition and every access through v->begin[i]. */
typedef struct E { unsigned short id; char p2[7]; unsigned char a; unsigned char b; char pb; } E;
typedef struct V { E *begin; E *end; } V;
int fn_886EDBC8(V *v, unsigned int a, int b)
{
    unsigned int i;
    for (i = 0; i < (unsigned int)(v->end - v->begin); i++) {
        if (v->begin[i].id == 0xff)
            break;
        if (v->begin[i].a == a && v->begin[i].b == b)
            return i;
    }
    return -1;
}
