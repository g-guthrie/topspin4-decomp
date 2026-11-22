/* Q5F: keyed use-count calls on a set of world entries (Top Spin 4, Xbox 360, Swing_DLL.xex), plain route, no flags.
 * The set holds a begin/end vector of entry pointers at +0x40. Both functions find the first non-null entry
 * whose key equals *key. If that entry has a world, they adjust its use count and tail-call the world's
 * acquire/release routine. The second argument is passed through untouched to that routine, which reads it
 * as a pointer.
 * Matching note: the key is a one-word struct copied into a struct local (`k = e->key`), then compared as
 * `key->id == k.id`. That gives the target's load of e->key before *key with `cmplw *key, e->key`. A scalar
 * key gives the loads and the compare in the same order whichever way it is written. */
typedef unsigned int u32;

typedef struct Q5WorldKey { u32 id; } Q5WorldKey;

typedef struct Q5WorldEntry {
    char pad00[0x10];
    void *world;            /* +0x10: null while the entry has no world */
    Q5WorldKey key;         /* +0x14 */
    char pad18[0x1c];
    int uses;               /* +0x34: use count of `world` */
} Q5WorldEntry;

typedef struct Q5WorldSet {
    char pad00[0x40];
    Q5WorldEntry **begin;   /* +0x40 */
    Q5WorldEntry **end;     /* +0x44 */
} Q5WorldSet;

void fn_88472130(void *world, void *ctx);   /* release */
void fn_88471F10(void *world, void *ctx);   /* acquire */

/* 0x8887B328: drop one use of the world of the entry with this key */
void ts4_world_set_release_by_key_8887B328(Q5WorldSet *set, void *ctx, Q5WorldKey *key)
{
    Q5WorldEntry **it;
    for (it = set->begin; it != set->end; ++it) {
        Q5WorldEntry *e = *it;
        Q5WorldKey k;
        if (!e) continue;
        k = e->key;
        if (key->id == k.id) {
            if (e->world) {
                e->uses--;
                fn_88472130(e->world, ctx);
            }
            return;
        }
    }
}

/* 0x8887B380: add one use of the world of the entry with this key */
void ts4_world_set_acquire_by_key_8887B380(Q5WorldSet *set, void *ctx, Q5WorldKey *key)
{
    Q5WorldEntry **it;
    for (it = set->begin; it != set->end; ++it) {
        Q5WorldEntry *e = *it;
        Q5WorldKey k;
        if (!e) continue;
        k = e->key;
        if (key->id == k.id) {
            if (e->world) {
                e->uses++;
                fn_88471F10(e->world, ctx);
            }
            return;
        }
    }
}
