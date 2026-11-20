/* 0x883D1CF0: compares a GUID with the one at t->+0xA8->+0x14 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); fields first, then the 8 tail bytes through fn_88329958. */
typedef struct Guid { unsigned a; unsigned short b, c; unsigned char d[8]; } Guid;
typedef struct S { char pad[0x14]; Guid *id; } S;
typedef struct T { char pad[0xa8]; S *s; } T;
int fn_88329958(const void *a, const void *b, unsigned n);
unsigned char ts4_guid_equals_owner_883D1CF0(const Guid *g, T *t)
{
    const Guid *o = t->s->id;
    return g->a == o->a && g->b == o->b && g->c == o->c && fn_88329958(g->d, o->d, 8) == 0;
}
