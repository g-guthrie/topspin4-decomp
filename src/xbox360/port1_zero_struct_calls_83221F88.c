/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l3b_zero_struct_calls_83221F88.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
#ifdef _MSC_VER
void *memset(void *, int, unsigned);
#pragma intrinsic(memset)
typedef unsigned __int64 ts4_u64;
#else
#include <string.h>
typedef unsigned long long ts4_u64;
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

typedef struct {
    unsigned a, b;
    ts4_u64 c, d;
    unsigned e, f, g, h, i, j;
} Ts4lState48;



/* Swing_DLL.xex 0x885C89D0 */
void ts4_clear_state_885C89D0(Ts4lState48 *s)
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

