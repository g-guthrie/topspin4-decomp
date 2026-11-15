/* 0x8866DF18: returns a hash object by value; default hash unless the owner's mode is 2. */
struct MeT88 { unsigned char p[0x84]; unsigned f84; };
struct MeT { unsigned char p[0x88]; MeT88 *p88; };
struct MeMode { int mode; };
struct MeB { unsigned char p[4]; MeT **tab; unsigned char q[0x78 - 8]; MeMode *m78; };
struct MeI24 { unsigned char p[0x48]; int idx; };
struct MeI4c { unsigned char p[0x24]; MeI24 *p24; };
struct MeA { unsigned char p[0x48]; MeB *b; MeI4c *c; };
struct MeHash {
    unsigned v;
    MeHash() : v(0xca68aaecu) {}
};
MeHash ts4_lookup_hash_8866DF18(MeA *a)
{
    MeB *b = a->b;
    MeHash h;
    if (b->m78->mode == 2)
        h.v = b->tab[a->c->p24->idx]->p88->f84;
    return h;
}
