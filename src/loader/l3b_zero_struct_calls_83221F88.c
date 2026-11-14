/* Loader_DLL.xex 0x831C75F8-0x83262118, executable version 0.0.0.3.
 * Zero-initialised structures: a constructor and a virtual call that is
 * given a zeroed 28-byte request block. */

#ifdef _MSC_VER
void *memset(void *, int, unsigned);
#pragma intrinsic(memset)
typedef unsigned __int64 ts4l_u64;
#else
#include <string.h>
typedef unsigned long long ts4l_u64;
#endif

typedef struct Ts4lObj Ts4lObj;
typedef struct {
    char pad[0x2c];
    int (*submit)(Ts4lObj *, void *);
} Ts4lObjVt;
struct Ts4lObj {
    Ts4lObjVt *vt;
};
typedef struct {
    unsigned a, b, c, d, e, f, g;
} Ts4lRequest28;

int ts4l_submit_empty_request_83221F88(Ts4lObj *o)
{
    Ts4lRequest28 z;
    memset(&z, 0, sizeof(z));
    return o->vt->submit(o, &z);
}

int ts4l_submit_empty_request_83223370(Ts4lObj *o)
{
    Ts4lRequest28 z;
    memset(&z, 0, sizeof(z));
    return o->vt->submit(o, &z);
}

typedef struct {
    unsigned a, b;
    ts4l_u64 c, d;
    unsigned e, f, g, h, i, j;
} Ts4lState48;

void ts4l_clear_state_831C75F8(Ts4lState48 *s)
{
    memset(s, 0, 48);
    s->b = 0;
    s->a = 0;
    s->c = 0;
    s->d = 0;
    s->e = 0;
    s->f = 0;
    s->g = 0;
    s->h = 0;
    s->i = 0;
    s->j = 0;
}

void ts4l_clear_state_83262118(Ts4lState48 *s)
{
    memset(s, 0, 48);
    s->b = 0;
    s->a = 0;
    s->c = 0;
    s->d = 0;
    s->e = 0;
    s->f = 0;
    s->g = 0;
    s->h = 0;
    s->i = 0;
    s->j = 0;
}
