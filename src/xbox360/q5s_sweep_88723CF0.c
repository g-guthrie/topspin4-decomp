/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x88723CF0: constructor: base init (0x88721F10), vtable lbl_880F26E0, a zeroed word at +0x38, one id slot at
 * +0x44, type hash 0xB270EBED, and the global self pointer lbl_88D45AC8.
 * Source: drafts/me_88723CF0_nearmiss_hk.c (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_88723CF0.json for route and flags. */
typedef unsigned int u32;
typedef struct Ts4IdSlot { int a; int id; int b; } Ts4IdSlot;
typedef struct Ts4RModC {
    const void **vt;            /* +0x00 */
    char pad04[4];
    u32 type_hash;              /* +0x08 */
    char pad0c[0x2c];
    u32 f38;                    /* +0x38 */
    char pad3c[8];
    Ts4IdSlot s1;               /* +0x44 */
} Ts4RModC;
extern const void *lbl_880F26E0[];
extern u32 lbl_88D45AC8;
void fn_88721F10(void *self);
static __inline void ts4_id_slot_init(Ts4IdSlot *s) { s->a = 0; s->b = 0; s->id = 0xFFFFF; }
Ts4RModC *ts4_rmod_c_ctor_88723CF0(Ts4RModC *m)
{
    fn_88721F10(m);
    m->f38 = 0;
    m->vt = lbl_880F26E0;
    ts4_id_slot_init(&m->s1);
    m->type_hash = 0xB270EBED;
    lbl_88D45AC8 = (u32)m;
    return m;
}
