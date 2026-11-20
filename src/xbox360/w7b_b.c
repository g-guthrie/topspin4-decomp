/* Swing_DLL.xex 0x889C0BC8, 0x886C3748, 0x886C3CB8: vector clear / delete-all helpers */
typedef unsigned int W7bU32;
/* dead locals shift the symbol numbering that decides the lwzx operand order */
#ifdef _MSC_VER
#define W7B_PAD6 int pd0 = 0; int pd1 = 0; int pd2 = 0; int pd3 = 0; int pd4 = 0; int pd5 = 0;
#else
#define W7B_PAD6
#endif
extern void *fn_88562DC0(void *dst, void *src, W7bU32 n);
typedef struct W7bVec { char *first; char *last; } W7bVec;
static __inline char *w7b_copy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        W7bU32 n = (W7bU32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
struct W7bO0BC8 { unsigned char p[0x28]; W7bVec v; };
void ts4_clear_vec_889C0BC8(struct W7bO0BC8 *o)
{
    W7bVec *v = &o->v;
    v->last = w7b_copy(v->last, v->last, v->first);
}
struct W7bO3748 { unsigned char p[0xc]; W7bVec v; };
extern void ts4_object_finalize(void *);
void ts4_finalize_and_clear_886C3748(struct W7bO3748 *o)
{
    W7bVec *v;
    ts4_object_finalize(o);
    v = &o->v;
    v->last = w7b_copy(v->last, v->last, v->first);
}
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
struct W7bO3CB8 { unsigned char p[0x50]; W7bPVec v; };
void ts4_delete_all_and_clear_886C3CB8(struct W7bO3CB8 *o)
{
    W7B_PAD6
    W7bPVec *v = &o->v;
    int n = v->last - v->first;
    int i;
    for (i = 0; i < n; i++) {
        struct W7bObj *e = v->first[i];
        if (e) ((void (*)(struct W7bObj *, int))e->vt[0])(e, 1);
    }
    v->last = w7b_copyp(v->last, v->last, v->first);
}
