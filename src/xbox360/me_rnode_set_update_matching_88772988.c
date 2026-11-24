/* 0x88772988: for each child whose key matches, apply the set's two parameters and refresh its cached value. */
typedef struct RNodeChild { char pad[8]; float value; unsigned param; char pad2[0x14]; unsigned key; } RNodeChild;
typedef struct RNodeSet { char pad[0x40]; RNodeChild **first; RNodeChild **last; char pad2[0xb4-0x48]; unsigned arg_b4; unsigned arg_b8; } RNodeSet;
typedef struct RNodeOwner { char pad[0x10]; RNodeSet *set; } RNodeOwner;
void fn_8876E150(RNodeChild *c, int level, unsigned a, unsigned b);
float fn_88771618(RNodeChild *c, unsigned param);
void rnode_set_update_matching_88772988(RNodeOwner *o, int level, unsigned key)
{
    RNodeSet *s = o->set;
    if (s) {
        int n = s->last - s->first;
        int i;
        for (i = 0; i < n; i++) {
            if (key == o->set->first[i]->key && level >= 0) {
                RNodeChild *c;
                fn_8876E150(o->set->first[i], level, o->set->arg_b4, o->set->arg_b8);
                c = o->set->first[i];
                c->value = fn_88771618(c, c->param);
            }
        }
    }
}
