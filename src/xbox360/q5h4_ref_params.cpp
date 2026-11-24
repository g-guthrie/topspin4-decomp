// Q5h4: load parameters from a resolved reference and re-apply them (Top Spin 4, Xbox 360, Swing_DLL.xex).
// Clones of the 0x887FDE60 template (q5_gameplay_ref_params.cpp). The four sisters have the same code; only the
// relative call and branch displacements differ.
typedef unsigned int u32;
typedef unsigned char u8;

// Null 12-byte handle {0, 0xFFFFF, 0}, passed by value.
struct Q5h4Handle12 { u32 node, offset, extra; };
// Reference slot: target is `off` (absolute) or `(char *)this - off` (relative); valid flag at +8.
struct Q5h4Ref { u32 w0; int off; u8 valid; u8 relative; };
// Parameter block reached through the descriptor's self-relative offset.
struct Q5h4Params { u32 w00, w04, w08, w0c, w10, w14; };
struct Q5h4Desc { int rel; u32 value; };
// Resolves (binds) the reference for the handle.
extern "C" void fn_8892EE88(Q5h4Ref *ref, Q5h4Handle12 h, int flag);

#ifdef _MSC_VER
#define Q5H4_INLINE static __forceinline
#else
#define Q5H4_INLINE static inline
#endif
Q5H4_INLINE Q5h4Desc *q5h4_ref_get(Q5h4Ref *r)
{
    if (r->valid) return r->relative ? (Q5h4Desc *)((char *)r - r->off) : (Q5h4Desc *)(unsigned long)r->off;
    return 0;
}
Q5H4_INLINE Q5h4Params *q5h4_params(Q5h4Desc *d) { return (Q5h4Params *)((char *)d + d->rel); }

// A C++ class: the vtable slot load is invariant, which lets it be scheduled above the field stores.
struct Q5h4ParamUser {
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c(); virtual void s10(); virtual void s14();
    virtual void s18(); virtual void s1c(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s2c();
    virtual void s30();
    virtual void apply(); // +0x34
    u32 p04, p08;
    u32 value;            // +0x0c
    char p10[0x1c];
    u32 a, b, c;          // +0x2c, +0x30, +0x34
};

// 0x887FDE60 template shape: bind ref under the null handle, then copy the descriptor's value and parameters 1, 3
// and 5 into self and call its apply() (virtual slot +0x34).
#define Q5H4_PARAM_LOAD(NAME)                                   \
extern "C" void NAME(Q5h4ParamUser *self, Q5h4Ref *ref)        \
{                                                               \
    Q5h4Handle12 h;                                             \
    Q5h4Desc *d;                                                \
    h.node = 0;                                                 \
    h.offset = 0xFFFFF;                                         \
    h.extra = 0;                                                \
    fn_8892EE88(ref, h, 0);                                     \
    d = q5h4_ref_get(ref);                                      \
    self->value = d->value;                                     \
    self->a = q5h4_params(d)->w04;                              \
    self->b = q5h4_params(d)->w0c;                              \
    self->c = q5h4_params(d)->w14;                              \
    self->apply();                                              \
}

// 0x887FDF38, 0x887FE0A8, 0x887FE330, 0x887FE408: one body, four addresses.
Q5H4_PARAM_LOAD(ts4_param_user_load_ref_887FDF38)
Q5H4_PARAM_LOAD(ts4_param_user_load_ref_887FE0A8)
Q5H4_PARAM_LOAD(ts4_param_user_load_ref_887FE330)
Q5H4_PARAM_LOAD(ts4_param_user_load_ref_887FE408)
