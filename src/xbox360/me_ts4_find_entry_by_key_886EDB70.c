/* 0x886EDB70: returns the index of the first 12-byte entry (vector begin/end) whose key byte (+9) equals key, stopping at an entry with id 0xFF; -1 when not found. */
/* Matched on /Oc (agAB). Element pointer local e = &v->begin[i] gives the lhzx plus add. */
typedef struct E { unsigned short id; char p2[7]; unsigned char key; char pa[2]; } E;
typedef struct V { E *begin; E *end; } V;
int fn_886EDB70(V *v, unsigned int key)
{
    unsigned int i, n = v->end - v->begin;
    for (i = 0; i < n; i++) {
        E *e = &v->begin[i];
        if (e->id == 0xff)
            break;
        if (e->key == key)
            return i;
    }
    return -1;
}
