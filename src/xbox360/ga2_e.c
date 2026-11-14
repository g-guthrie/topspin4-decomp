/*
 * GA2: gameplay reset helpers, Swing_DLL.xex 0x886601F0..0x8867B608.
 */
#include "ga2_types.h"

#define GA2_NO_ID 0x968230B3u

/* ---- 0x886731B0 / 0x88673210: reset the swing-request block ---- */
struct Ga2ReqGroupA { ga2_u8 f_0; ga2_u8 f_1; ga2_u8 f_2; PAD(1); int v_4; };
struct Ga2ReqGroupB { ga2_u8 f_0; PAD(3); ga2_u32 id_4; };
struct Ga2ReqBlock {
    PAD(0xbc);
    ga2_u8 f_bc;
    ga2_u8 f_bd;
    PAD(2);
    ga2_u32 id_c0;
    PAD(4);
    struct Ga2ReqGroupA grp_c8;
    struct Ga2ReqGroupB grp_d0;
};
struct Ga2ReqFlag { PAD(0x2e); ga2_u8 f_2e; };
struct Ga2ReqSelf { PAD(0x28); struct Ga2ReqFlag *flag; PAD(0xc); struct Ga2ReqBlock *block; };

/* 0x886731B0: clear the request flags and set the id slots to "none". */
void ts4_ga2_reset_request_block_886731B0(struct Ga2ReqSelf *self)
{
    ga2_u32 none = GA2_NO_ID;
    struct Ga2ReqGroupA *ga;
    struct Ga2ReqGroupB *gb;
    self->block->f_bc = 0;
    self->block->f_bd = 0;
    self->block->id_c0 = none;
    ga = &self->block->grp_c8;
    ga->f_0 = 0;
    ga->f_1 = 0;
    ga->f_2 = 0;
    ga->v_4 = 0;
    gb = &self->block->grp_d0;
    gb->f_0 = 0;
    gb->id_4 = 0;
    self->block->grp_d0.id_4 = none;
    self->flag->f_2e = 0;
}

/* 0x88673210: identical body to 0x886731B0. */
void ts4_ga2_reset_request_block_88673210(struct Ga2ReqSelf *self)
{
    ga2_u32 none = GA2_NO_ID;
    struct Ga2ReqGroupA *ga;
    struct Ga2ReqGroupB *gb;
    self->block->f_bc = 0;
    self->block->f_bd = 0;
    self->block->id_c0 = none;
    ga = &self->block->grp_c8;
    ga->f_0 = 0;
    ga->f_1 = 0;
    ga->f_2 = 0;
    ga->v_4 = 0;
    gb = &self->block->grp_d0;
    gb->f_0 = 0;
    gb->id_4 = 0;
    self->block->grp_d0.id_4 = none;
    self->flag->f_2e = 0;
}

/* ---- "enter state" helpers: write the rally-state block, then run virtual slot 15 ---- */
struct Ga2StateBlock { ga2_u32 w0; ga2_u32 w4; ga2_u32 w8; ga2_u32 wc; };
struct Ga2StateHdr { int rel; PAD(8); ga2_u32 f_0c; ga2_u32 state_10; };
struct Ga2StateHolder { PAD(0x48); struct Ga2StateHdr hdr; };
struct Ga2StateOwner { PAD(0x37c); ga2_u8 flag_37c; };
struct Ga2StateTop { PAD(0x44); struct Ga2StateHolder *holder; PAD(4); struct Ga2StateOwner *owner; };
struct Ga2StateObj;
struct Ga2StateVtbl { void (*slot[32])(struct Ga2StateObj *); };
struct Ga2StateObj { struct Ga2StateVtbl *vtbl; struct Ga2StateTop *top; };

#define GA2_STATE_BLOCK(h) ((struct Ga2StateBlock *)((char *)(h) + (h)->rel))
#define GA2_WRITE_STATE_BLOCK(self)                                  \
    do {                                                             \
        struct Ga2StateHdr *h = &(self)->top->holder->hdr;           \
        h->f_0c = 0;                                                 \
        h->state_10 = 0x23BAED9Eu;                                   \
        GA2_STATE_BLOCK(h)->w0 = 0;                                  \
        GA2_STATE_BLOCK(h)->w8 = 0;                                  \
        GA2_STATE_BLOCK(h)->w4 = 0x317C51B7u;                        \
        GA2_STATE_BLOCK(h)->wc = 0xA2EDA1E7u;                        \
    } while (0)

/* ---- 0x88670D10 / 0x88672828: reset the +0x44 record of the object at +0x28 ---- */
extern float g_ts4_script_constants[];

struct Ga2RecBlock { PAD(0x18); ga2_u32 id_18; PAD(0x10); float value_2c; };
struct Ga2RecHdr { int rel; int count; };
struct Ga2RecOwner { PAD(0x44); struct Ga2RecHdr hdr; };
struct Ga2RecSelf { PAD(0x28); struct Ga2RecOwner *owner; };


/* ---- 0x8866F028: find the loaded analyser graph slot by definition hash ---- */
struct Ga2GraphDef { PAD(0x28); ga2_u32 hash_28; };
struct Ga2GraphSlot { ga2_u32 w0; struct Ga2GraphDef *def; };
struct Ga2GraphCount { PAD(4); int count_4; };
struct Ga2GraphSelf { PAD(0x70); struct Ga2GraphCount *graphs; PAD(0x9c - 0x74); struct Ga2GraphSlot *slots; };

/* ---- 0x88661638: acquire a registered object by id (first acquire runs virtual slot 13) ---- */
struct Ga2ObjVtbl { void (*slot[32])(void *); };
struct Ga2Obj { struct Ga2ObjVtbl *vtbl; };
struct Ga2RegEntry { PAD(4); int refs_4; ga2_u32 id_8; struct Ga2Obj *obj_c; };      /* 16 bytes */
struct Ga2Registry { PAD(0xc); struct Ga2RegEntry *begin; struct Ga2RegEntry *end; };

/* 0x88661638 */
void ts4_ga2_acquire_registered_88661638(struct Ga2Registry *self, ga2_u32 *id)
{
    struct Ga2RegEntry *end = self->end;
    struct Ga2RegEntry *e = self->begin;
    ga2_u32 want = *id;
    for (; e != end; e++) {
        if (e->id_8 == want) {
            if (e->obj_c == 0) return;
            if (e->refs_4 == 0) e->obj_c->vtbl->slot[13](e->obj_c);
            e->refs_4++;
            return;
        }
    }
}


/* ---- 0x88660F08 / 0x886614F8: look up a 0x70-byte record by id in a self-relative array ---- */
struct Ga2RelHdr { int rel; };
struct Ga2LookupKey { PAD(4); ga2_u32 id_4; };
struct Ga2LookupResult { PAD(8); void *found_8; };
struct Ga2Rec70A { PAD(0x54); ga2_u32 id_54; PAD(0x70 - 0x58); };
struct Ga2Rec70B { PAD(0x60); ga2_u32 id_60; PAD(0x70 - 0x64); };
struct Ga2TableA { PAD(0x114); struct Ga2RelHdr hdr; int count; };
struct Ga2TableB { PAD(0xfc); struct Ga2RelHdr hdr; int count; };


/* ---- 0x88664F60: first object in the list whose flag byte matches `want` (else the first object) ---- */
struct Ga2FlagObj { PAD(0x10); ga2_u8 flag_10; };
struct Ga2ObjList { PAD(4); struct Ga2FlagObj **begin; struct Ga2FlagObj **end; };
struct Ga2ObjListOwner { PAD(0x1c); struct Ga2ObjList *list; };

/* 0x88664F60 */
struct Ga2FlagObj *ts4_ga2_find_by_flag_88664F60(struct Ga2ObjListOwner *self, ga2_u8 want)
{
    struct Ga2FlagObj **it = self->list->begin;
    struct Ga2FlagObj **end = self->list->end;
    for (; it != end; it++) {
        struct Ga2FlagObj *o = *it;
        if (o != 0) {
            if (want) {
                if (o->flag_10 != 0) return o;
            } else {
                if (o->flag_10 == 0) return o;
            }
        }
    }
    return *self->list->begin;
}

/* ---- 0x886626D8: clear the flag byte of every 8-byte slot in the player's self-relative slot array ---- */
struct Ga2Slot8 { ga2_u32 w0; ga2_u8 flag_4; PAD(3); };
struct Ga2Slot8Array { int rel; int count; };
struct Ga2SlotSub { PAD(0xc); struct Ga2Slot8Array slots; };
struct Ga2SlotPlayer { PAD(0x40c); struct Ga2SlotSub sub; };
struct Ga2SlotCtx { PAD(0x74); struct Ga2SlotPlayer *player; };
struct Ga2SlotTop { PAD(4); struct Ga2SlotCtx *ctx; };

