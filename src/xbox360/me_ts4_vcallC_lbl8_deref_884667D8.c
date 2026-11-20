/* 0x884667D8: calls t->vt[3](t, lbl_8808324C, 8, *b); arguments a and c are unused */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct T T;
typedef struct { void *s[3]; int (*fc)(T *, const char *, int, int); } TVt;
struct T { TVt *vt; };
extern const char lbl_8808324C[];
int ts4_vcallC_lbl8_deref_884667D8(void *a, int *b, int c, T *t)
{
    return t->vt->fc(t, lbl_8808324C, 8, *b);
}
