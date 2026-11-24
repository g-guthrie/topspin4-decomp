/* 0x883E6B40: in states 2/3 runs ts4_release_key_ref_883E68B0, in state 3 also starts the object at +8 (slot 1) with +0x10->+4 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); then finishes the child at +0xC and frees itself to the lbl_88B3302C heap (file lbl_88039750, line 0x2AF); returns the first error. */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039750[];
typedef struct S S;
typedef struct SVt { void *s0; int (*start)(S *s, void *arg); } SVt;
struct S { SVt *vt; };
typedef struct P { int f0; void *arg; } P;
typedef struct T { int f0, f4; S *s; void *child; P *p; char pad[0x30 - 0x14]; int state; } T;
int ts4_release_key_ref_883E68B0(T *t);
int ts4_if_get_u32_off0_883E54C8(void *child);
void fn_88315F10(void *heap, void *p, const char *file, int line);
int ts4_finish_and_free_883E6B40(T *t)
{
    int r;
    if (t->state == 3 || t->state == 2) {
        r = ts4_release_key_ref_883E68B0(t);
        if (r)
            return r;
    }
    if (t->state == 3) {
        r = t->s->vt->start(t->s, t->p ? t->p->arg : 0);
        if (r)
            return r;
    }
    r = ts4_if_get_u32_off0_883E54C8(t->child);
    if (r)
        return r;
    fn_88315F10(lbl_88B3302C->heap, t, lbl_88039750, 0x2af);
    return 0;
}
