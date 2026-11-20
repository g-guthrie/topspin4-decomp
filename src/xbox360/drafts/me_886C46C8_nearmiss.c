/* NEAR MISS (~5 instructions): the game loads the last key before the self-compare guard and forms the
 * key base as offset + &keys; this source sinks the load into the guarded block. */
/* 0x886C46C8: looks a time up in a sorted key table. The last key and index are reported first (the
 * guard compares the time with itself, so it only skips NaN); then the first key whose bit pattern is
 * not below the time's bit pattern is reported and 1 returned. Returns 0 (index -1) for an empty table. */
typedef struct Keys { int offset; int count; } Keys;
typedef struct Track { char p[0x18]; Keys keys; } Track;
unsigned char f(float time, Track *t, float *out, int *index)
{
    int n;
    float *k;
    int i;
    Keys *ks;
    float last;
    unsigned char found = 0;
    *index = -1;
    n = t->keys.count;
    if (n > 0) {
    ks = &t->keys;
    k = (float *)((char *)ks + ks->offset);
    last = k[n - 1];
    if (time >= time) {
        *out = last;
        *index = n - 1;
    }
    for (i = 0; i < n; i++) {
        if (*(int *)&k[i] >= *(int *)&time) {
            *index = i;
            *out = k[i];
            found = 1;
            break;
        }
    }
    }
    return found;
}
