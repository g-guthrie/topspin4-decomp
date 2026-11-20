/* 0x883F75E8: collects status flags for an object (or, unless its flags +0x24 have 2 or 0x10, for each child in the list at +0x78): voice activity via 88317788 (0x24/0xB read as inactive), resource state via 88316BB0 (0x40 for the extra byte, 2 for a state other than 0/6); 0x10 and stop at the first active voice. The probe is a macro with direct returns; an inline helper (even forced) adds a merged result test */
/* Matched on /O1 plain and LTCG (agX, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Obj {
    char pad0[0x24];
    unsigned int flags;
    void *res;
    char pad1[0x34 - 0x2c];
    void *voice;
    char pad2[0x78 - 0x38];
    Link kids;
} Obj;
typedef struct T { char pad[0x10]; Obj *obj; } T;
int ts4_if_call_seq_fn_88322CA8_88317788(void *v, unsigned char *active);
int ts4_if_get_fn_8832BFC0_88316BB0(void *res, int *state, int a, unsigned char *x);

/* Probe one object's voice and resource; returns from the caller on error. */
#define PROBE(o)                                                        \
    r = ts4_if_call_seq_fn_88322CA8_88317788((o)->voice, &active);     \
    if (r == 0x24 || r == 0xb)                                          \
        active = 0;                                                     \
    else if (r)                                                         \
        return r;                                                       \
    if ((o)->res) {                                                     \
        r = ts4_if_get_fn_8832BFC0_88316BB0((o)->res, &state, 0, &x);   \
        if (r)                                                          \
            return r;                                                   \
        if (x)                                                          \
            *flags |= 0x40;                                             \
        if (state != 0 && state != 6)                                   \
            *flags |= 2;                                                \
    }

int fn_883F75E8(T *t, unsigned int *flags)
{
    Obj *o = t->obj;
    Link *l, *h;
    unsigned char active, x;
    int state, r;
    if (!(o->flags & 2) && !(o->flags & 0x10)) {
        h = &o->kids;
        for (l = h->next; l != h; l = l->next) {
            o = l ? (Obj *)((char *)l - 4) : 0;
            PROBE(o)
            if (active) {
                *flags |= 0x10;
                return 0;
            }
        }
        return 0;
    }
    PROBE(o)
    if (active)
        *flags |= 0x10;
    return 0;
}
