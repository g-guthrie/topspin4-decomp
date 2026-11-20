/* NM2: append a key/value pair to two parallel arrays (Swing_DLL.xex 0x886C5C80).
 *
 * The first stwx is (keys base, i*4) in the target. That order needs the keys base
 * read at the use (`s->k[i]`), not through a named local; `__restrict` on the count
 * pointer lets the compiler keep the s->k load ahead of the count store, as in the
 * target. A local `unsigned *k = s->k` gives (i*4, base).
 */
struct Nm2PairArrays {
    unsigned char pad_00[4];
    unsigned *keys;                 /* +0x04 */
    unsigned char pad_08[4];
    unsigned *vals;                 /* +0x0C */
};

void ts4_push_pair_886C5C80(struct Nm2PairArrays *s, int *__restrict count, unsigned val, unsigned key)
{
    int i = *count;
    *count = i + 1;
    s->keys[i] = key;
    s->vals[i] = val;
}
