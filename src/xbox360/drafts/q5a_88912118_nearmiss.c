/* Draft (Opus A, Q5 batch J): 0x88912118, 1 instruction off (operand order of the key cmplw). Not proven: fn_equiv UNCHECKED. */
typedef unsigned int u32;
typedef struct Q5Binding Q5Binding;
typedef struct Q5BindingVt { void (*destroy)(Q5Binding *self, int flags); } Q5BindingVt;
typedef struct Q5Key { u32 h; } Q5Key;
struct Q5Binding { Q5BindingVt *vt; u32 owner; Q5Key key; u32 slot; };
static int q5_key_eq(const Q5Key *a, const Q5Key *b) { return a->h == b->h; }
typedef struct Q5BindingVec { Q5Binding **first; Q5Binding **last; } Q5BindingVec;
typedef struct Q5BindingSet { char pad[0x14]; Q5BindingVec items; } Q5BindingSet;
extern Q5Binding **ts4_vec_erase_one_881AAE10(Q5BindingVec *v, Q5Binding **it);

/* Swing_DLL.xex 0x88912118 */
unsigned char ts4_binding_remove_88912118(Q5BindingSet *self, u32 owner, const Q5Key *key, u32 slot)
{
    Q5Binding **end = self->items.last;
    Q5BindingVec *v = &self->items;
    Q5Binding **it;
    unsigned char r = 0;
    for (it = v->first; it != end; it++) {
        Q5Binding *b = *it;
        if (b->owner == owner && q5_key_eq(key, &b->key) && b->slot == slot) {
            b->vt->destroy(b, 1);
            ts4_vec_erase_one_881AAE10(v, it);
            r = 1;
            break;
        }
    }
    return r;
}
