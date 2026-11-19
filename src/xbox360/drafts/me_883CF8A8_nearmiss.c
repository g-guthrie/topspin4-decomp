typedef struct Track { char pad[0x10]; float rate; char pad2[0xc]; float *times; int count; } Track;
typedef struct T {
    char pad[0x14]; Track *track; float cur; char pad1[4]; float prev; char pad2[4]; unsigned int flags;
} T;
extern const float lbl_88001A20;
extern const float lbl_88001A68;
int fn_883CF7F0(T *t, float lo, float hi, unsigned char *found);
int fn_883CF8A8(T *t, unsigned char *out)
{
    unsigned char found;
    int r;
    float prev = t->prev;
    if (t->flags & 4) {
        float zero = lbl_88001A20;
        float lo;
        if (t->track->rate >= zero) {
            r = fn_883CF7F0(t, prev, lbl_88001A68, &found);
            if (r)
                return r;
            if (found)
                goto wrapped;
            lo = zero;
        } else {
            r = fn_883CF7F0(t, prev, zero, &found);
            if (r)
                return r;
            if (found)
                goto wrapped;
            lo = lbl_88001A68;
        }
        r = fn_883CF7F0(t, lo, t->cur, &found);
        if (r)
            return r;
        goto store;
    wrapped:
        t->flags &= ~4u;
    store:
        if (out)
            *out = found;
        return 0;
    }
    if (t->cur == prev) {
        if (out)
            *out = 0;
        return 0;
    }
    r = fn_883CF7F0(t, prev, t->cur, out);
    if (r)
        return r;
    return 0;
}
