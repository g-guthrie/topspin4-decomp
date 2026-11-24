/* 0x886F75E0: finds the entry tagged with the hash for kind 0/1/2 in a self-relative (hash, value) table and maps its value through fn_886ED8E0; 1 if absent. LTCG with the callee. */
typedef unsigned int u32;
typedef struct E { u32 hash; u32 value; } E;
typedef struct T { u32 offset; int count; } T;
int fn_886ED8E0(unsigned int hash, unsigned int kind);
int ts4_table_kind_for_886F75E0(T *t, u32 kind)
{
    u32 h = 0;
    int i;
    int r;
    switch (kind) {
    case 0: h = 0xDE2ECB76; break;
    case 1: h = 0x98539510; break;
    case 2: h = 0xE9CF2CE5; break;
    }
    r = 1;
    for (i = 0; i < t->count; i++) {
        E *e = (E *)((char *)t + t->offset + i * 8);
        if (e->hash == h) {
            r = fn_886ED8E0(e->value, kind);
            break;
        }
    }
    return r;
}
