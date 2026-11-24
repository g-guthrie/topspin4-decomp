/* Swing_DLL.xex 0x886F8058-0x886F80E8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;

#ifdef _MSC_VER
#define TS4_FI static __forceinline
#else
#define TS4_FI static inline
#endif

typedef struct Ts4RefTarget {
    void **vtbl;
} Ts4RefTarget;

typedef struct Ts4Ref {
    Ts4RefTarget *target;
    u32 node;
    u32 extra;
} Ts4Ref;

typedef void *(*Ts4RefInvokeFn)(Ts4RefTarget *, Ts4Ref *, u32, u32);

extern void fn_88150770(Ts4Ref *out, void *a, void *b);
extern char lbl_880C1320[];

TS4_FI u8 ts4_ref_invalid(Ts4Ref *r)
{
    return r->target == 0 || r->node == 0xfffff;
}

/* Resolve a reference from two handle words and invoke slot 0x14 on its target; falls back to a default object. */
void *ts4_ref_invoke_886F8058(void *a, void *b)
{
    Ts4Ref r;
    fn_88150770(&r, a, b);
    if (!ts4_ref_invalid(&r)) return ((Ts4RefInvokeFn)r.target->vtbl[0x50 / 4])(r.target, &r, r.node, 1);
    return lbl_880C1320;
}
