/* 0x88926600: looks *key up in the table at +8 and passes entry+0x10 to vtable slot 0x54 as (s, a, entry+0x10, 0, d) */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct S S;
typedef struct { char pad[0x54]; int (*f54)(S *, int, void *, int, int); } SVt;
struct S { SVt *vt; int x4; void *tab; };
char *ts4_find_entry24_88924430(void *tab, unsigned int key);
int ts4_find_then_vcall54_88926600(S *s, int a, unsigned int *key, int d)
{
    SVt *vt = s->vt;
    return vt->f54(s, a, ts4_find_entry24_88924430(s->tab, *key) + 0x10, 0, d);
}
