/* 0x883FB970: true when the embedded object at +0xC is not busy (slot 0xC) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); and the handle at +4 reports ready. */
typedef struct Sub Sub;
typedef struct SubVt { void *s[3]; unsigned (*busy)(Sub *s); } SubVt;
struct Sub { SubVt *vt; };
typedef struct T { int f0; void *h; int f8; Sub sub; } T;
unsigned char fn_88400558(void *h);
unsigned char ts4_idle_and_ready_883FB970(T *t)
{
    return !t->sub.vt->busy(&t->sub) && fn_88400558(t->h);
}
