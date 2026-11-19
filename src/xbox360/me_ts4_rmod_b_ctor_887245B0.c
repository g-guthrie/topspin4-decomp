/* Swing_DLL.xex 0x887245B0: construct a render module (base init, vtable, type hash, two cleared id slots). */
typedef struct Ts4IdSlot { int a; int id; int b; } Ts4IdSlot;
typedef struct Ts4RModB {
    const void **vt;            /* +0x00 */
    char pad04[4];
    unsigned int type_hash;     /* +0x08 */
    char pad0c[0x30];
    Ts4IdSlot s0;               /* +0x3c */
    Ts4IdSlot s1;               /* +0x48 */
} Ts4RModB;
extern const void *lbl_880F2348[];
void fn_88721F10(void *self);
static __inline void ts4_id_slot_init(Ts4IdSlot *s) { s->a = 0; s->b = 0; s->id = 0xFFFFF; }
Ts4RModB *ts4_rmod_b_ctor_887245B0(Ts4RModB *m)
{
    fn_88721F10(m);
    m->vt = lbl_880F2348;
    ts4_id_slot_init(&m->s0);
    ts4_id_slot_init(&m->s1);
    m->type_hash = 0xF66AF447;
    return m;
}
