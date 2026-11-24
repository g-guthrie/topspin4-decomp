/* NEAR MISS, 8 instructions off: vtable and id-constant materialize in the other registers (target r9/r8, ours r8/r7), with the same stores. Draft, not matched.
 * Swing_DLL.xex 0x88912018: constructor; calls fn_88636DC8, vtable, id slot at +0x38, and cleared words at +0x2c..+0x34 and +0x50..+0x54. */
typedef unsigned int u32;
typedef struct Ts4IdSlot { int a; int id; int b; } Ts4IdSlot;
typedef struct Ts4RModD {
    const void **vt;            /* +0x00 */
    char pad04[0x28];
    u32 f2c;
    u32 f30;
    u32 f34;
    Ts4IdSlot s0;               /* +0x38 */
    char pad44[0xc];
    u32 f50;
    u32 f54;
} Ts4RModD;
extern const void *lbl_880D75C4[];
void fn_88636DC8(void *self);
static __inline void ts4_id_slot_init(Ts4IdSlot *s) { s->a = 0; s->b = 0; s->id = 0xFFFFF; }
Ts4RModD *ts4_rmod_d_ctor_88912018(Ts4RModD *m)
{
    fn_88636DC8(m);
    m->vt = lbl_880D75C4;
    m->f2c = 0;
    m->f30 = 0;
    m->f34 = 0;
    m->s0.a = 0;
    m->s0.b = 0;
    m->s0.id = 0xFFFFF;
    m->f50 = 0;
    m->f54 = 0;
    return m;
}
