/* 0x883CF1A0: resets the pose: with config flag 0x100 (+0x80AC) copies the source position and zeroes the two angles, otherwise copies position and angles from the database lookup (virtual slot 21 of the owner's +0x138) for the source; then zeroes +0x1C and clears flag bit 0 */
/* Matched on /O1 plain only (work/army/ME/v.py chk); the zero constant is held in f31 as a local. */
typedef struct Cfg { char pad[0x80AC]; unsigned int flags; } Cfg;
extern Cfg *lbl_88CAC988;
typedef struct Src { char pad[0x14]; float x, y; } Src;
typedef struct Pose { char pad[0x18]; float a; char p1c[4]; float b; char p24[8]; float x, y; } Pose;
typedef struct Db Db;
typedef struct DbVt { void *f[21]; int (*lookup)(Db *db, Src *s, Pose **out); } DbVt;
struct Db { DbVt *vt; };
typedef struct Sys { char pad[0x138]; Db *db; } Sys;
typedef struct Own { Sys *sys; } Own;
typedef struct Node { char pad[0xAC]; Own *own; } Node;
typedef struct T { char pad[0x14]; Src *src; float a, c, b; char p24[4]; unsigned int flags; float x, y; char p34[4]; Node *node; int p3c; } T;
int ts4_pose_reset_883CF1A0(T *t)
{
    float z = 0.0f;
    Pose *p;
    Sys *s;
    int r;
    t->p3c = 0;
    if (lbl_88CAC988->flags & 0x100) {
        t->x = t->src->x;
        t->y = t->src->y;
        t->a = z;
        t->b = z;
    } else {
        s = t->node->own ? t->node->own->sys : 0;
        r = s->db->vt->lookup(s->db, t->src, &p);
        if (r) return r;
        t->x = p->x;
        t->y = p->y;
        t->a = p->a;
        t->b = p->b;
    }
    t->c = z;
    t->flags &= ~1;
    return 0;
}
