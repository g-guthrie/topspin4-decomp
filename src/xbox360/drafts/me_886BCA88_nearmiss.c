/* 0x886BCA88 near miss (33 off, /Oc plain C). Flow reset + next-state pick: clears items, resets sim, then picks a
 * state hash (scripted forced state, tutorial tiebreak paths, 0x96FE1E55, own-serve 0x0633F155, else 0x7A0291CB /
 * 0x1CEEFD8B / 0x19FB4C09) and calls ts4_call_seq_u32_offc_886A7678. Keys: end-first loop, srv->side == t->side,
 * mine = same && ..., mine held as int and cast to u8 at tests (fixed size + relocs). Residue: busy store placed before
 * the item loads in target; mine allocated r8 instead of r29. */
typedef unsigned int u32; typedef unsigned char u8;
extern const float lbl_8814B440;
typedef struct Item { char _0[8]; u32 state; } Item;
typedef struct Pl { char _0[0x14]; int id; } Pl;
typedef struct Srv { char _0[0x54]; int side; } Srv;
typedef struct Mode { char _0[0x48]; u8 scripted; char _49[0x51]; u8 forced; char _9b[0xEB5]; u32 forced_state; } Mode;
typedef struct Rules { char _0[0x328]; u8 tiebreak, deciding; } Rules;
typedef struct Match { char _0[0x28]; Mode *mode; char _2c[4]; Rules *rules; char _34[0x10]; Srv *srv; } Match;
typedef struct Sched { char _0[0xB8]; int slot; } Sched;
typedef struct Turn { char _0[0x10]; Pl **players; char _14[0x10]; Sched *sched; int side; } Turn;
typedef struct Sim { char _0[0x28]; void *phys; } Sim;
typedef struct Stats { char _0[0x5BC]; float timer; } Stats;
typedef struct Flags { char _0[0x14D]; u8 serve_pending; } Flags;
typedef struct Ctx { char _0[0x14]; int local_id; char _18[0x30]; Match *match; Turn *turn; char _50[0x10]; Sim *sim;
    char _64[0x10]; Stats *stats; Flags *flags; } Ctx;
typedef struct Opts { char _0[0x3A]; u8 online; } Opts;
typedef struct Cfg { char _0[0x30]; Rules *rules; char _34[0xC]; struct { char _0[0x8E]; u8 on; } *tut; Opts *opts; } Cfg;
typedef struct Flow { char _0[4]; u8 busy, b5, b6; char _7; u32 f8, fc; char _10[4]; u8 b14, b15; char _16[2];
    Ctx *ctx; Cfg *cfg; char _20[8]; Item **items_begin, **items_end; } Flow;
void fn_886D9070(void *phys);
void ga6_reset_sim_flags_886E2BF8(Sim *sim);
void ts4_call_seq_u32_offc_886A7678(Flow *f, u32 hash);
u8 ts4_query_slot_matches_target_8865EB60(Ctx *ctx);
void ts4_flow_pick_next_state_886BCA88(Flow *f)
{
    Item **it, **end;
    Ctx *ctx;
    Match *m;
    Turn *t;
    Mode *mode;
    Cfg *cfg;
    u8 same;
    int mine;
    u32 h;
    f->busy = 0;
    end = f->items_end;
    for (it = f->items_begin; it != end; it++)
        (*it)->state = 0;
    fn_886D9070(f->ctx->sim->phys);
    ga6_reset_sim_flags_886E2BF8(f->ctx->sim);
    ctx = f->ctx;
    f->f8 = 0; f->fc = 0; f->b5 = 0; f->b6 = 0;
    m = ctx->match; t = ctx->turn;
    same = m->srv->side == t->side;
    mine = same && t->players[t->sched->slot]->id == ctx->local_id;
    mode = m->mode;
    if (mode->scripted && mode->forced) {
        h = mode->forced_state;
        goto apply;
    }
    cfg = f->cfg;
    if (cfg->tut->on) {
        Rules *r = cfg->rules;
        if ((r->tiebreak || r->deciding) && !cfg->opts->online) {
            if (r->deciding && (u8)mine) {
                ctx->flags->serve_pending = 1;
                h = 0xB68E9520u;
            } else
                h = 0xAAA9D638u;
            goto apply;
        }
    }
    if (m->rules->tiebreak) {
        h = 0x96FE1E55u;
        goto apply;
    }
    if (same) {
        if ((u8)mine) {
            ts4_call_seq_u32_offc_886A7678(f, 0x0633F155u);
            f->ctx->flags->serve_pending = (u8)mine;
            goto done;
        }
        h = 0x7A0291CBu;
    } else if (ts4_query_slot_matches_target_8865EB60(ctx))
        h = 0x1CEEFD8Bu;
    else
        h = 0x19FB4C09u;
apply:
    ts4_call_seq_u32_offc_886A7678(f, h);
done:
    f->ctx->stats->timer = lbl_8814B440;
    f->b15 = 0;
    f->b14 = 0;
}
