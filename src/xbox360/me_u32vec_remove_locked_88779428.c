/* 0x88779428: under the global lock at lbl_88D45A60+0x204, remove the first occurrence of id from the u32 vector at +0x308 (memmove-style erase). */
typedef unsigned int u32;
typedef struct Lock Lock;
typedef struct { void *f0; void (*lock)(Lock *); void (*unlock)(Lock *); } LockVt;
struct Lock { LockVt *vt; };
typedef struct { char p0[0x204]; Lock lock; } Sys;
typedef struct { u32 *first; u32 *last; } U32Vec;
typedef struct { char p0[0x308]; U32Vec list; } Obj;
extern Sys *lbl_88D45A60;
char *fn_88562DC0(char *dst, const char *src, unsigned int n);
static __inline void u32vec_erase(U32Vec *v, u32 *p)
{
    u32 *n = p + 1;
    if (n != v->last) fn_88562DC0((char *)p, (const char *)n, (char *)v->last - (char *)n);
    v->last--;
}
void fn_88779428(Obj *o, u32 id)
{
    Lock *l = &lbl_88D45A60->lock;
    u32 *p;
    l->vt->lock(l);
    {
    u32 *e = o->list.last;
    for (p = o->list.first; e != p; p++) {
        if (*p == id) { u32vec_erase(&o->list, p); break; }
    }
    }
    l->vt->unlock(l);
}
