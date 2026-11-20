/* 0x8858E820: Fills the 1024-entry code table at +0x454: entries 0-3 map to themselves, then each pair of codes from 4 upward covers a run that doubles in length, as in an LZ distance-code table. */
/* Matched on /O1 (agAH). Indexing c->dist_code directly matches; a tab pointer local and /Oc unroll differently. */
typedef struct Coder { char p0[0x454]; unsigned char dist_code[0x400]; } Coder;
void fn_8858E820(Coder *c)
{
    unsigned char code;
    int n, i, k;
    c->dist_code[0] = 0;
    c->dist_code[1] = 1;
    c->dist_code[2] = 2;
    c->dist_code[3] = 3;
    code = 4;
    k = 4;
    n = 2;
    do {
        for (i = 0; i < n; i++)
            c->dist_code[k++] = code;
        code++;
        for (i = 0; i < n; i++)
            c->dist_code[k++] = code;
        code++;
        n <<= 1;
    } while (k < 0x400);
}
