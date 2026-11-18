/* 0x886B83B0: enters the controller mode (AI or human), binds the controller link to the two rig slots
 * (0xEEEC65F2, 0xCC20BAEA) and, for human players, runs fn_886B6448 on the selected variant. Matched in C++ with
 * Mode::enter as a real virtual (slot 4) on the LTCG route with /Ob1 and the real caller ga5_a.c / w10a_b.c in
 * context; the C function-pointer form left `li r6,1` after the link load (2 off). */
typedef struct Ga5SlotTable Ga5SlotTable;
typedef struct Ga5SlotLink Ga5SlotLink;
typedef struct Variant Variant;
typedef struct VarObj { char p[0x28]; void *owner; } VarObj;
struct Mode { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void enter(); };
typedef struct Rig { char p[0x5e4]; Ga5SlotTable *slots; } Rig;
typedef struct RigHolder { char p[0x28]; Rig *rig; } RigHolder;
typedef struct Player {
    char p[0x10]; unsigned char is_ai; char p11[0x50 - 0x11]; VarObj *variants; char p54[0x60 - 0x54]; RigHolder *rig;
} Player;
typedef struct Controller {
    char p[0x1c]; Player *player; char p20[0x44 - 0x20]; Mode *mode; Mode human; char p4c[0xf4 - 0x4c];
    Mode ai; char pf8[0x100 - 0xf8]; Ga5SlotLink *link; char p104[0x590 - 0x104]; char anim[4];
} Controller;
extern "C" void ts4_bind_slot_link_by_id_886C3FE0(Ga5SlotTable *self, unsigned id, Ga5SlotLink *link, unsigned char bind);
extern "C" Variant *ts4_selected_variant_886A0EC8(VarObj *o);
extern "C" void fn_886B6448(void *dst, void *anim, Player *player, void *owner);
extern "C" void ts4_controller_activate(Controller *self)
{
    Mode *m;
    Player *pl;
    int pad0 = 0;
    int pad1 = 0;
    int pad2 = 0;
    int pad3 = 0;
    int pad4 = 0;
    int pad5 = 0;
    m = self->player->is_ai ? &self->ai : &self->human;
    self->mode = m;
    m->enter();
    ts4_bind_slot_link_by_id_886C3FE0(self->player->rig->rig->slots, 0xEEEC65F2u, self->link, 1);
    ts4_bind_slot_link_by_id_886C3FE0(self->player->rig->rig->slots, 0xCC20BAEAu, self->link, 1);
    pl = self->player;
    if (!pl->is_ai) {
        void *owner = pl->variants->owner;
        fn_886B6448((char *)ts4_selected_variant_886A0EC8(pl->variants) + 0x30, self->anim, pl, owner);
    }
    (void)pad0;
    (void)pad1;
    (void)pad2;
    (void)pad3;
    (void)pad4;
    (void)pad5;
}
