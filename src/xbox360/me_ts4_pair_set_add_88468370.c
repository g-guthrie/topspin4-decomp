/* 0x88468370: Appends pair p to the 8-entry set and returns its index. Returns -1 if the count is over 8, the pair is already present (fn_884683F0) or the set is full. */
/* Matched on /Oc (agAH). The callee returns its found flag through a hidden result pointer, written here as an explicit out param. The three failure tests go in one || so they share the -1 block. */
typedef struct Pair { unsigned char a; unsigned char b; unsigned short value; } Pair;
typedef struct PairSet { Pair items[8]; unsigned char p20; unsigned char count; } PairSet;
typedef struct Found { unsigned char found; } Found;
extern Found *fn_884683F0(Found *out, PairSet *s, const Pair *p);
int fn_88468370(PairSet *s, int unused1, int unused2, const Pair *p)
{
    int n = s->count;
    Found f;
    if (s->count > 8 || fn_884683F0(&f, s, p)->found || n >= 8)
        return -1;
    s->items[n] = *p;
    s->count++;
    return n;
}
