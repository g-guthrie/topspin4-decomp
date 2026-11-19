/* 0x886F76A0: finds the entry tagged with the hash for kind 0/1/2 in a self-relative (hash, value) table; returns fn_886ED860(value) or 0. */
typedef unsigned int u32;
typedef struct E { u32 hash; u32 value; } E;
typedef struct T { u32 offset; int count; } T;
extern int fn_886ED860(u32 v);
int ts4_table_lookup_886F76A0(T *t, u32 kind)
{
    u32 h = 0;
    int i;
    E *f;
    int r;
    switch (kind) {
    case 0: h = 0x97E67864; break;
    case 1: h = 0x0EEF29DE; break;
    case 2: h = 0x79E81948; break;
    }
    f = 0;
    for (i = 0; i < t->count; i++) {
        E *e = (E *)((char *)t + t->offset + i * 8);
        if (e->hash == h) {
            f = e;
            break;
        }
    }
    r = 0;
    if (f) {
        r = fn_886ED860(f->value);
    }
    return r;
}
