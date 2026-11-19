/* 0x8854F558: refcounted result-holder init: vtable lbl_8808E8B4, refs 1, result {code -0x2F, n 0, p 0} through an inline helper, then ts4_set_u32_off0_885E9618 on the result */
/* Matched on /Oc (agAH). The result is set up by a __forceinline helper; writing the fields inline changes the order. */
extern void *lbl_8808E8B4;
typedef struct Res { int code; short n; short pad; int p; } Res;
void ts4_set_u32_off0_885E9618(Res *r);
typedef struct RefR { void *vtable; short unk4; short refs; Res r; } RefR;
static __forceinline void Res_Init(Res *r) { r->code = -0x2f; r->n = 0; r->p = 0; }
RefR *fn_8854F558(RefR *o)
{
    o->vtable = &lbl_8808E8B4;
    o->refs = 1;
    Res_Init(&o->r);
    ts4_set_u32_off0_885E9618(&o->r);
    return o;
}
