/* Swing_DLL.xex 0x8867C418, 0x88662E58, 0x8864EBB0: container teardown with vector clear */
typedef unsigned int W7bU32;
#ifdef _MSC_VER
#define W7B_PAD6 int pd0 = 0; int pd1 = 0; int pd2 = 0; int pd3 = 0; int pd4 = 0; int pd5 = 0;
#else
#define W7B_PAD6
#endif
extern void *fn_88562DC0(void *dst, void *src, W7bU32 n);
extern void ts4_destroy_owned_object(void *);
typedef struct W7bVec { char *first; char *last; } W7bVec;
static __inline char *w7b_copy(char *first, char *last, char *dest)
{
    char *r = dest;
    if (first != last) {
        W7bU32 n = (W7bU32)(last - first);
        r = (char *)fn_88562DC0(dest, first, n);
        r = r + n;
    }
    return r;
}
struct W7bO7C418 { unsigned char p[0x4c]; int f4c; int f50; unsigned char q[0x5a0 - 0x54]; W7bVec v; unsigned char r[0x5dc - 0x5a8]; int f5dc; };
void ts4_reset_and_free_8867C418(struct W7bO7C418 *o)
{
    W7bVec *v = &o->v;
    v->last = w7b_copy(v->last, v->last, v->first);
    o->f4c = 0;
    o->f50 = 0x7fffffff;
    o->f5dc = 0;
    if (v->first) ts4_destroy_owned_object(v->first);
}
extern void fn_8890DDA8(void *);
struct W7bObj { void **vt; };
typedef struct W7bPVec { struct W7bObj **first; struct W7bObj **last; } W7bPVec;
static __inline struct W7bObj **w7b_copyp(struct W7bObj **first, struct W7bObj **last, struct W7bObj **dest)
{
    if (first == last) {
        return dest;
    } else {
        W7bU32 n = (W7bU32)((char *)last - (char *)first);
        dest = (struct W7bObj **)fn_88562DC0(dest, first, n);
        return (struct W7bObj **)((char *)dest + n);
    }
}
struct W7bO2E58 { unsigned char p0[4]; W7bPVec v; unsigned char p1[0x18 - 0xc]; unsigned char a18[0x44]; unsigned char a5c[4]; };
void ts4_destroy_container_88662E58(struct W7bO2E58 *o)
{
    W7bPVec *v;
    struct W7bObj **p;
    struct W7bObj **end;
    fn_8890DDA8(o->a5c);
    fn_8890DDA8(o->a18);
    v = &o->v;
    end = v->last;
    for (p = v->first; p != end; p++) {
        ((void (*)(struct W7bObj *))(*p)->vt[2])(*p);
        if (*p) ((void (*)(struct W7bObj *, int))(*p)->vt[0])(*p, 1);
    }
    v->last = w7b_copyp(v->last, v->last, v->first);
}
struct W7bO4EBB0 { unsigned char p0[8]; unsigned f8; unsigned char p1[4]; W7bPVec v; };
void ts4_destroy_items_8864EBB0(struct W7bO4EBB0 *o)
{
    W7B_PAD6
    W7bPVec *v = &o->v;
    unsigned n = v->last - v->first;
    unsigned i;
    for (i = 0; i != n; i++) {
        struct W7bObj *e = v->first[i];
        struct W7bObj *d;
        ((void (*)(struct W7bObj *))e->vt[3])(e);
        d = v->first[i];
        if (d) ((void (*)(struct W7bObj *, int))d->vt[0])(d, 1);
    }
    v->last = w7b_copyp(v->last, v->last, v->first);
    o->f8 = 0;
}
