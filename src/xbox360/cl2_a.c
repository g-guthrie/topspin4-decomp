typedef unsigned char cl2_u8;
typedef unsigned int cl2_u32;
#ifdef _MSC_VER
#define CL2_INLINE static __inline
#else
#define CL2_INLINE static inline
#endif

struct Cl2PtrVec { cl2_u32 *begin; cl2_u32 *end; };
struct Cl2Hist {
    cl2_u8 pad_00[0x438];
    struct Cl2PtrVec vec;      /* +0x438 */
    cl2_u8 pad_440[0x488 - 0x440];
    int enabled;               /* +0x488 */
    cl2_u32 last;              /* +0x48C */
};

CL2_INLINE int cl2_vec_empty(const struct Cl2PtrVec *v) { return v->begin == v->end; }
CL2_INLINE cl2_u32 *cl2_vec_end(const struct Cl2PtrVec *v) { return v->end; }
CL2_INLINE cl2_u32 cl2_vec_back(const struct Cl2PtrVec *v) { return *(cl2_vec_end(v) - 1); }
CL2_INLINE void cl2_vec_pop_back(struct Cl2PtrVec *v) { --v->end; }

/* Swing_DLL.xex 0x8863A058 */
void ts4_hist_pop_8863A058(struct Cl2Hist *self, const cl2_u8 *flag)
{
    if (self->enabled == 0) return;
    if (*flag == 0) return;
    if (cl2_vec_empty(&self->vec)) return;
    self->last = cl2_vec_back(&self->vec);
    cl2_vec_pop_back(&self->vec);
}

struct Cl2HistOwner { cl2_u32 w0; struct Cl2Hist *hist; /* +4 */ };

/* Swing_DLL.xex 0x8863A0C8 */
void ts4_hist_owner_pop_8863A0C8(struct Cl2HistOwner *o, const cl2_u8 *flag)
{
    struct Cl2Hist *self = o->hist;
    if (self->enabled == 0) return;
    if (*flag == 0) return;
    if (cl2_vec_empty(&self->vec)) return;
    self->last = cl2_vec_back(&self->vec);
    cl2_vec_pop_back(&self->vec);
}

/*
 * CL2: functions whose original contains `clrrwi rD,rS,0`.
 * Swing_DLL.xex, Xbox 360, cl.exe 16.00.10224.00, plain route, no flags.
 *
 * 0x8863A058 / 0x8863A0C8: inline empty()/back()/pop_back() on a pointer vector
 *   (case 1: back() re-reads end through its own inline end() accessor).
 * strlen users: the inline `strlen` intrinsic expansion (lbz/addi/cmplwi/bne loop)
 *   is followed by a clrrwi copy of the length when the result is used as an int
 *   through an extern `unsigned strlen(const char *)` declaration.
 */
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
extern u32 strlen(const char *s);
#else
#include <string.h>
#endif
static __inline int slen_(const char *s) { if (s == 0) return 0; return (int)strlen(s); }
static __inline int mn(int a,int b){return (a<b)?a:b;}
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_widen_8819A020(u16 *dst, int n, const char *src)
{
    int i; int l = slen_(src);
    int m = mn(n,l);
    for (i = 0; i <= m; i++) dst[i] = (u16)(unsigned char)src[i];
    dst[m] = 0;
}

struct FStr;
void fn_8822A4A0(struct FStr *self);
struct FStr *ts4_fixed_string_append_8816CF48(struct FStr *self, const char *from, const char *to);

struct FStr *ts4_fstr_assign_cstr_8821FA18(struct FStr *self, int unused, const char *src)
{
    const char *end;
    (void)unused;
    fn_8822A4A0(self);
    end = src + (int)strlen(src);
    if (src != end)
        ts4_fixed_string_append_8816CF48(self, src, end);
    return self;
}

struct WStr { u16 *data; };
u16 *fn_8819C528(struct WStr *self, int n);
void ts4_widen_8819A020(u16 *dst, int n, const char *src);
void ts4_wstring_unshare_8819C2D8(struct WStr *self);

struct WStr *ts4_wstring_assign_cstr_8819ADD0(struct WStr *self, const char *src)
{
    int len;
    u16 *d;
    if (src != 0 && (len = (int)strlen(src)) > 0) {
        d = fn_8819C528(self, len);
        ts4_widen_8819A020(d, len, src);
        ((int *)self->data)[-3] = len;
        self->data[len] = 0;
        return self;
    }
    ts4_wstring_unshare_8819C2D8(self);
    return self;
}
