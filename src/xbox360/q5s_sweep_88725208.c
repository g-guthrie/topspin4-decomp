/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x88725208: construct the render module singleton (base init, vtable lbl_880F25A8, three bound resource slots,
 * global self pointer lbl_88D45AAC, type hash 0x36CBBE4B).
 * Source: drafts/me_88725208_nearmiss.c (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_88725208.json for route and flags. */
typedef struct Ts4IdSlot { int a; int id; int b; } Ts4IdSlot;
typedef struct Ts4ResBinding { char handle[0xc]; Ts4IdSlot id; } Ts4ResBinding;
typedef struct Ts4RModC {
    const void **vt;            /* +0x00 */
    char pad04[4];
    unsigned int type_hash;     /* +0x08 */
    char pad0c[0x30];
    Ts4ResBinding r0;           /* +0x3c */
    Ts4ResBinding r1;           /* +0x54 */
    Ts4ResBinding r2;           /* +0x6c */
} Ts4RModC;
extern const void *lbl_880F25A8[];
extern Ts4RModC *lbl_88D45AAC;
void fn_88721F10(void *self);
void fn_8816D1A8(void *handle);
static __inline void ts4_id_slot_init(Ts4IdSlot *s) { s->a = 0; s->b = 0; s->id = 0xFFFFF; }
static __inline void ts4_res_binding_init(Ts4ResBinding *b) { fn_8816D1A8(b->handle); ts4_id_slot_init(&b->id); }
Ts4RModC *ts4_rmod_c_ctor_88725208(Ts4RModC *m)
{
    fn_88721F10(m);
    m->vt = lbl_880F25A8;
    ts4_res_binding_init(&m->r0);
    ts4_res_binding_init(&m->r1);
    ts4_res_binding_init(&m->r2);
    lbl_88D45AAC = m;
    m->type_hash = 0x36CBBE4B;
    return m;
}
