/* agAO near-miss (1 off, /Oc): 0x8887B380 finds the first non-null entry whose key equals *key in the
 * o->begin/end pointer vector. If that entry has a world, it bumps the use count and tail-calls
 * fn_88471F10(world, cache).
 * Remaining diff: the operand order of the key `cmplw`. The target loads e->key into r8, then *key into r7,
 * and compares r7 with r8. `e->key == *key` gets the loads right but compares r8 with r7. `*key == e->key`
 * swaps the loads. Struct-key inlines, const, and a find() inline do not change this. */
typedef unsigned int u32;
void fn_88471F10(void *world, void *cache);
typedef struct { char p[0x10]; void *world; u32 key; char q[0x1c]; int uses; } Ent;
typedef struct { char p[0x40]; Ent **begin; Ent **end; } O;

void ts4_use_world_by_key_8887B380(O *o, void *cache, u32 *key)
{
    Ent **it;
    for (it = o->begin; it != o->end; ++it) {
        Ent *e = *it;
        if (e && e->key == *key) {
            if (e->world) {
                e->uses++;
                fn_88471F10(e->world, cache);
            }
            return;
        }
    }
}
