/* 0x883CF430: copies a parameter record: duplicates the name (883299F0), copies four floats and fields, and deep-copies the int array (alloc + 8857ACB8 as memcpy); a null source resets everything; 0x2C on allocation failure */
/* Matched on /O1 plain only (agV, v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_880390E4[];
typedef struct P {
    char pad0[8];
    int c8;
    char *name;
    float a, b, c, d;
    int *vals;
    int nvals;
    int x28, x2c;
} P;
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
char *fn_883299F0(const char *s);
void fn_8857ACB8(void *dst, const void *src, unsigned int n);

int fn_883CF430(P *t, const P *s)
{
    t->c8 = 0;
    if (s) {
        if (s->name) {
            t->name = fn_883299F0(s->name);
            if (!t->name)
                return 0x2c;
        } else {
            t->name = 0;
        }
        t->a = s->a;
        t->d = s->d;
        t->b = s->b;
        t->c = s->c;
        t->x28 = s->x28;
        t->x2c = s->x2c;
        t->vals = s->vals;
        t->nvals = s->nvals;
        if (t->nvals) {
            t->vals = (int *)fn_88315C60(lbl_88B3302C->heap, t->nvals * 4, lbl_880390E4, 0x59d, 0, 0);
            if (!t->vals)
                return 0x2c;
            fn_8857ACB8(t->vals, s->vals, t->nvals * 4);
            return 0;
        }
    } else {
        t->name = 0;
        t->x28 = 0;
        t->x2c = 0;
        t->nvals = 0;
        t->a = 0.0f;
        t->d = 0.0f;
        t->b = 0.0f;
        t->c = 0.0f;
    }
    t->vals = 0;
    return 0;
}
