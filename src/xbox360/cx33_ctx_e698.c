/* CX33: LTCG context only (not a matched function): stand-in body for fn_8890E698 so the caller sees its register use. Swing_DLL.xex 0x8890E698. */
typedef unsigned int u32;
typedef struct Cx33Pair { u32 val; u32 key; } Cx33Pair;
typedef struct Cx33PairVec { u32 w0; Cx33Pair *first; Cx33Pair *last; } Cx33PairVec;

/* 0x8890E698: value of the first pair whose key equals *key, or 0 (unrolled random-access find) */
u32 fn_8890E698(Cx33PairVec *v, const u32 *key)
{
    Cx33Pair *last = v->last;
    Cx33Pair *p = v->first;
    u32 k = *key;
    int n;
    for (n = (last - p) >> 2; n > 0; n--) {
        if (p->key == k) goto found;
        p++;
        if (p->key == k) goto found;
        p++;
        if (p->key == k) goto found;
        p++;
        if (p->key == k) goto found;
        p++;
    }
    switch (last - p) {
    case 3:
        if (p->key == k) goto found;
        p++;
    case 2:
        if (p->key == k) goto found;
        p++;
    case 1:
        if (p->key == k) goto found;
    default:
        p = last;
    }
found:
    if (p != last)
        return p->val;
    return 0;
}
