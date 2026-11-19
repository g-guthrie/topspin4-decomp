/* 0x884D4BD8: inserts each {key, value} of a null-key-terminated table into the map at +0x2C and value->key into +0x3C */
/* Matched on /Oc (agAH). Plain indexed for loop; the pointer-walk do-while is larger. */
typedef struct Map { char p[0x10]; } Map;
typedef struct Pair { const char *key; const char *value; } Pair;
typedef struct T { char p[0x2c]; Map fwd; Map rev; } T;
extern void fn_885E76C0(Map *m, const char *k, const char *v);
void fn_884D4BD8(T *t, const Pair *pairs)
{
    int i;
    if (!pairs)
        return;
    for (i = 0; pairs[i].key; i++) {
        fn_885E76C0(&t->fwd, pairs[i].key, pairs[i].value);
        fn_885E76C0(&t->rev, pairs[i].value, pairs[i].key);
    }
}
