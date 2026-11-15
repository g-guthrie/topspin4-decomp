/*
 * CL2: strlen-intrinsic users whose original has `clrrwi rD,rS,0` after the length loop.
 * Swing_DLL.xex, Xbox 360, cl.exe 16.00.10224.00, plain route, no flags.
 */
typedef unsigned int u32;
#ifdef _MSC_VER
#define CL2_UPTR u32
extern u32 strlen(const char *s);
#else
#include <string.h>
#define CL2_UPTR unsigned long
#endif
struct VT { void *s0,*s1,*s2,*s3; void (*write)(void *self, const char *s, int n); };
struct Sink { struct VT *vt; };
struct Owner { u32 pad[11]; int sink; };
struct W { u32 pad[7]; const char *name; u32 base; };
int ts4_cstr_size_88603C00(const char *s)
{
    return s ? (int)strlen(s) + 2 : 2;
}
void ts4_sink_write_8827F748(struct Owner *o, const char *s)
{
    int k = o->sink;
    if (k) (*(struct VT **)(CL2_UPTR)k)->write((void *)(CL2_UPTR)k, s, (int)strlen(s));
}
int ts4_name_size_885F5448(struct W *w)
{
    const char *n = w->name;
    int len = n ? (int)strlen(n) + 2 : 2;
    return w->base + len + 0x16;
}

struct Str1 { int v; };
void *fn_881DA660(void);
int fn_881DAFA8(void *a, const char *s, int n);
struct Str1 *ts4_str1_init_881DB1A8(struct Str1 *self, const char *s)
{
    int n = (int)strlen(s);
    self->v = fn_881DAFA8(fn_881DA660(), s, n);
    return self;
}
