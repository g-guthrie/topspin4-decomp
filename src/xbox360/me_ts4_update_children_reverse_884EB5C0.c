/* 0x884EB5C0: calls slot 6 (dt) on the children back to front, then fn_884EBE70 on the state at +0x18 when the owner at +0x8 is set (4-byte result discarded) */
/* Matched on /Oc (agAH). The discarded hidden-pointer result is a 4-byte local; the frame size gives its size. */
typedef struct C C;
typedef struct CVt { void *f[6]; void (*update)(C *c, float dt); } CVt;
struct C { CVt *vt; };
typedef struct Tmp { char p[4]; } Tmp;
typedef struct T { char p[8]; void *owner; char p2[0xc]; char state[0x14]; C **kids; int count; } T;
extern void fn_884EBE70(Tmp *out, void *state, void *owner);
void fn_884EB5C0(T *t, float dt)
{
    int i;
    for (i = t->count - 1; i >= 0; i--)
        t->kids[i]->vt->update(t->kids[i], dt);
    if (t->owner) {
        Tmp tmp;
        fn_884EBE70(&tmp, t->state, t->owner);
    }
}
