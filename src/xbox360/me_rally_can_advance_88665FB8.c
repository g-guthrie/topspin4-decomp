/* 0x88665FB8 (hand match): whether the rally may advance: only while enabled, with exactly two
 * participants, when the two sides' score entries add up to more than the next step and the
 * rally is not locked. */
typedef unsigned char u8;
typedef struct Rel { int offset; } Rel;
typedef struct Score { Rel value; char p[0x18 - 4]; } Score;
typedef struct Rally { char p[0xb4]; Rel scores; char p2[0xc4 - 0xb8]; u8 locked; } Rally;
typedef struct Info { char p[0x28]; int side; } Info;
typedef struct Player { char p[0x4c]; Info *info; } Player;
typedef struct Group { char p[0x10]; Player **first; Player **last; } Group;
typedef struct Obj { char p[4]; u8 enabled; char p1[3]; int step; char p2[0x14 - 0xc]; Rally *rally; char p3[0x1c - 0x18];
    Group *group; Player *a; Player *b; } Obj;
static __inline Score *at(Rel *t, int i) { return (Score *)((char *)t + t->offset) + i; }
static __inline int val(Score *s) { return *(int *)((char *)s + s->value.offset); }
static __inline int sidev(Obj *o, Player *p) { return val(at(&o->rally->scores, p->info->side)); }
static __inline int total(Obj *o) { return sidev(o, o->a) + sidev(o, o->b); }
static __inline int total2(Rel *t, int a, int b) { return val(at(t, a)) + val(at(t, b)); }
u8 ts4_rally_can_advance_88665FB8(Obj *o)
{
    u8 r = 0;
    if (o->enabled && o->group->last - o->group->first == 2
        && total(o) > o->step + 1
        && !o->rally->locked)
        r = 1;
    return r;
}
