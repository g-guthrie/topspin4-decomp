/* 0x886B81E0 near miss (48 off, /Oc plain C). AI shot pick: stores distance to the rally's court spot (or k[15]),
 * builds entries (fn_88694030), zeroes and fills the four shot weights, snapshots them to +0x1D0, then rolls the rng for
 * the 'lucky' flag and a band flag. Residue from +0x108: target copies the weights through a dead addi s+0x1D0 with fmr
 * copies into f30/f29/f28 and recomputes a+b twice; we CSE a+b. Tried: W4 struct copy (worse), add2 inline, hi temp, b+a. */
typedef unsigned char u8;
extern const float lbl_8814B440;
extern const float g_ts4_script_constants[];
typedef struct Ts4Rng Ts4Rng;
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Spot { float x, y, z; char _c[0x24]; } Spot;
typedef struct Court { char _0[0x5A0]; Spot *spots; } Court;
typedef struct Match { char _0[0x88]; Court *court; } Match;
typedef struct Rally { int spot; Match *match; } Rally;
typedef struct Shot { char _0[0xCC]; float w[4]; char _dc[0xD8]; float dist; char _1b8[0x18]; float w_prev[4]; } Shot;
typedef struct Player { char _0[0x28]; Shot *shot; } Player;
typedef struct Brain { char _0[0xB4]; char rng[4]; } Brain;
typedef struct Rates { char _0[0x28]; void *table; } Rates;
typedef struct Flags { char _0[0x47E]; u8 lucky; char _47f[0x751]; u8 mid_band; } Flags;
typedef struct Ctx { char _0[0x44]; Brain *brain; Rates *rates; char _4c[4]; Player *player; char _54[0x20]; Flags *flags;
    char _78[0x50]; Rally *rally; } Ctx;
typedef struct Self { char _0[0x1C]; Ctx *ctx; char _20[0x570]; char entries[4]; } Self;
u8 fn_88660520(Rally *r);
Vec3 *ts4_if_get_u32_off4c_8865EC70(Vec3 *out, Ctx *ctx);
int fn_88694030(Ctx *ctx, Shot *shot, void *entries, Ts4Rng *rng);
void ts4_print_entry_rates_886B63B8(void *entries, void *table);
void fn_88693FA8(Shot *shot, int n, Ts4Rng *rng);
float ts4_rng_range_8861E598(Ts4Rng *r, float lo, float hi);
void ts4_shot_pick_weights_886B81E0(Self *self)
{
    Player *pl = self->ctx->player;
    Ts4Rng *rng = (Ts4Rng *)self->ctx->brain->rng;
    const float *k = g_ts4_script_constants;
    float zero, a, b, c, r;
    Shot *sh;
    int n;
    if (fn_88660520(self->ctx->rally)) {
        Rally *ra = self->ctx->rally;
        Spot *sp = &ra->match->court->spots[ra->spot];
        Vec3 tmp;
        Vec3 *p = ts4_if_get_u32_off4c_8865EC70(&tmp, self->ctx);
        float dz = p->z - sp->z;
        float dx = p->x - sp->x;
        sh = pl->shot;
        sh->dist = __fsqrts(dx * dx + dz * dz);
    } else {
        sh = pl->shot;
        sh->dist = k[15];
    }
    n = fn_88694030(self->ctx, sh, self->entries, (Ts4Rng *)self->ctx->brain->rng);
    ts4_print_entry_rates_886B63B8(self->entries, self->ctx->rates->table);
    zero = lbl_8814B440;
    pl->shot->w[0] = zero; pl->shot->w[1] = zero; pl->shot->w[2] = zero; pl->shot->w[3] = zero;
    fn_88693FA8(pl->shot, n, rng);
    {
        Shot *s = pl->shot;
        float *dst = s->w_prev;
        dst[0] = a = s->w[0];
        dst[1] = b = s->w[1];
        dst[2] = c = s->w[2];
        dst[3] = s->w[3];
    }
    self->ctx->flags->lucky = ts4_rng_range_8861E598(rng, zero, k[0]) < c;
    r = ts4_rng_range_8861E598(rng, zero, a + b);
    if (r > zero && r < a)
        self->ctx->flags->mid_band = 1;
    if (a < r && r < a + b)
        self->ctx->flags->mid_band = 0;
}
