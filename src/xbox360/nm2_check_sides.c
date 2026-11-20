/* NM2: per-frame check between the two sides of a rally (Swing_DLL.xex 0x8868FBC0).
 *
 * Operand order of the first lwzx (list base, idx*4): the side list must be read at
 * the use (`self->sides->side[idx]`), not through a named local. With
 * `list = self->sides` as a local the order flips to (idx*4, list).
 */
struct W9Pawn { unsigned char pad_00[0x310]; unsigned int value_310; };
/* ---- per-frame check between the two sides ---- */
struct Ga3Slot { unsigned char pad_00[0xB8]; int index; };                       /* +0xB8 participant index */
struct Ga3Timer { unsigned char pad_00[0x750]; unsigned int base; };           /* +0x750 */
struct Ga3Record { unsigned char pad_00[0xFA4]; unsigned char flag; };          /* +0xFA4 */
struct Ga3Window { unsigned char pad_00[0x10]; unsigned int length; };          /* +0x10 */
struct Ga3Participant {
    unsigned char pad_00[0x2C];
    struct Ga3Timer *timer;         /* +0x2C */
    unsigned char pad_30[0x2C];
    unsigned char pad_5C[4];
    void *gate;                     /* +0x60 */
    unsigned char pad_64[0x10];
    struct Ga3Record *record;       /* +0x74 */
    unsigned char pad_78[0xC];
    struct Ga3Window *window;       /* +0x84 */
};
struct Ga3Side {
    unsigned char pad_00[0x10];
    struct Ga3Participant **members;   /* +0x10 */
    unsigned char pad_14[0x10];
    struct Ga3Slot *slot;              /* +0x24 */
};
struct Ga3SideList { struct Ga3Side *side[2]; };
struct Ga3Phase { int kind; };
struct Ga3Ctx44 { unsigned char pad_00[0x54]; int first; unsigned char pad_58[0x8D]; unsigned char latch_E5; };   /* +0x54 index of the first side, +0xE5 */
struct Ga3Checker {
    unsigned char pad_00[0x10];
    struct Ga3SideList *sides;         /* +0x10 the two sides, indexed by Ctx44.first / (1 - first) */
    unsigned char pad_14[0x1C];
    struct W9Pawn *pawn;              /* +0x30 */
    unsigned char pad_34[0x10];
    struct Ga3Ctx44 *ctx;              /* +0x44 */
    unsigned char pad_48[0x30];
    struct Ga3Phase *phase;            /* +0x78 */
    unsigned char pad_7C[0x2C];
    unsigned char done;                /* +0xA8 */
};
unsigned char ts4_anim_frames_to_event_886CD488(void *gate, void *out);

void ts4_check_sides_8868FBC0(struct Ga3Checker *self)
{
    if (self->phase->kind == 2) {
        int idx = self->ctx->first;
        struct Ga3Side *side_a = self->sides->side[idx];
        struct Ga3Side *side_b = self->sides->side[1 - idx];
        struct Ga3Participant *pa = side_a->members[side_a->slot->index];
        struct Ga3Participant *pb = side_b->members[side_b->slot->index];
        struct Ga3Record *rec = pb->record;
        if (!rec->flag) {
            if (self->pawn->value_310 >= pa->window->length - pb->timer->base)
                rec->flag = 1;
        }
        if (self->phase->kind == 2 && !self->done) {
            unsigned int tmp[2];
            if (ts4_anim_frames_to_event_886CD488(pa->gate, tmp)) {
                self->done = 1;
                self->ctx->latch_E5 = 1;
            }
        }
    }
}
