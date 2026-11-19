/* 0x883E51E0: frees the value table at +8 and, for a non-null source, reallocates it to the source object's slot-7 count and copies the words (0x2C on allocation failure); a null source clears it */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039750[];
typedef struct Src Src;
typedef struct SrcVt { void *f[7]; unsigned int (*count)(Src *s); } SrcVt;
struct Src { SrcVt *vt; };
typedef struct T { Src *src; int p4; unsigned int *vals; } T;
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
void fn_88315F10(void *heap, void *buf, const char *file, int line);

int fn_883E51E0(T *t, const unsigned int *v)
{
    unsigned int i;
    if (t->vals)
        fn_88315F10(lbl_88B3302C->heap, t->vals, lbl_88039750, 0xb5);
    if (v) {
        t->vals = (unsigned int *)fn_88315C60(lbl_88B3302C->heap, t->src->vt->count(t->src) * 4, lbl_88039750, 0xbb, 0, 0);
        if (!t->vals)
            return 0x2c;
        for (i = 0; i < t->src->vt->count(t->src); i++)
            t->vals[i] = v[i];
    } else {
        t->vals = 0;
    }
    return 0;
}
