/* GA3: gameplay code that calls through MSVC virtual-call thunks (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * The game calls these virtual slots by pointer-to-member constants, which MSVC lowers to a direct
 * call to the per-slot thunk (??_9TS4VcallClass88271E68@@$B...). Only the thunk-carrying class
 * layout is needed here; see d1_vcall_thunks_88271E68.cpp for the thunks themselves. */

class TS4VcallClass88271E68 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot_008();
    virtual void slot_009();
    virtual void slot_00a();
    virtual void slot_00b();
    virtual void slot_00c();
    virtual void slot_00d();
    virtual void slot_00e();
    virtual void slot_00f();
};

/* Controller with five embedded parts and a list of 16-byte entries whose last word is a handle. */
/* Plain signed address (32-bit on the target): the game's list code compares the bounds as signed words. */
typedef long Ga3Addr;
struct Ga3HandleList { Ga3Addr begin; Ga3Addr end; };
struct Ga3Releasable { void **vtbl; };
struct Ga3Controller {
    unsigned char pad_00[0x08];
    int state;                         /* +0x08 */
    struct Ga3HandleList handles;      /* +0x0C begin, +0x10 end */
    unsigned char pad_14[0x2C];
    unsigned char part_40[4];          /* +0x40 */
    unsigned char pad_44[0x90];
    struct Ga3Releasable *listener;    /* +0xD4 */
    unsigned char pad_D8[0x80];
    unsigned char part_158[0x44];
    unsigned char part_19C[0x44];
    unsigned char part_1E0[0x44];
    unsigned char part_224[0x44];
    unsigned char part_268[0x44];
};

extern "C" {
void fn_8890DDA8(void *part);
void fn_8867C5A8(void *part);

/* Resets the five embedded parts, notifies the listener (vtbl[5]), releases every handle with slot 0xE then slot 0xC of the handle class, clears part +0x40 and the state. */
void ga3_controller_reset_8867DBC0(struct Ga3Controller *self)
{
    struct Ga3HandleList *list;
    Ga3Addr first;
    Ga3Addr it;
    fn_8890DDA8(self->part_268);
    fn_8890DDA8(self->part_224);
    fn_8890DDA8(self->part_1E0);
    fn_8890DDA8(self->part_19C);
    fn_8890DDA8(self->part_158);
    ((void (*)(struct Ga3Releasable *))self->listener->vtbl[5])(self->listener);
    list = &self->handles;
    first = list->begin;
    for (it = list->end; it != first; it -= 0x10) {
        TS4VcallClass88271E68 *h = *(TS4VcallClass88271E68 **)(it - 4);
        if (h) (h->*(&TS4VcallClass88271E68::slot_00e))();
    }
    first = list->begin;
    for (it = list->end; it != first; it -= 0x10) {
        TS4VcallClass88271E68 *h = *(TS4VcallClass88271E68 **)(it - 4);
        if (h) (h->*(&TS4VcallClass88271E68::slot_00c))();
    }
    fn_8867C5A8(self->part_40);
    self->state = 0;
}
}
