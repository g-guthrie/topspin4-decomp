/*
 * ts4core: game-state images and graphs wired by field.
 *
 * The game binds every analyser-graph port to a member of a root object through the cell table (G1,
 * docs/gameplay/graphs-decoded.md s3). The blob section BIND carries that binding for every graph as
 * (region, byte offset); this file keeps byte images of the objects the graphs read and write
 * (PlayerState 0x1070, UserAIState 0x274, TeamState 0xC0, MatchState 0x340, BallState 0x540) and runs a graph by
 * gathering its inputs from the images and scattering its outputs back, so any graph runs exactly where the game
 * would run it, without a hand-written role table. SINI holds the State.bin default of every bound field.
 *
 * Also here: the AIDF (AI difficulty records) and SCLS (shot classes) lookups, and the new section loader.
 */
#include <string.h>

#include "ts4_internal.h"

#define F_RANDOM 1u

static int tag_eq(const uint8_t *t, const char *s) { return t[0] == (uint8_t)s[0] && t[1] == (uint8_t)s[1] && t[2] == (uint8_t)s[2] && t[3] == (uint8_t)s[3]; }
static int fits(uint32_t off, uint32_t len, uint32_t size) { return off <= size && len <= size - off; }

void ts4_ext_reset(Ts4Core *c)
{
    memset(&c->ext, 0, sizeof c->ext);
}

int32_t ts4_ext_section(Ts4Core *c, const uint8_t *tag, const uint8_t *p, uint32_t n)
{
    Ts4Ext *e = &c->ext;
    if (tag_eq(tag, "BIND")) { e->bind = p; e->bind_n = n; return 1; }
    if (tag_eq(tag, "SINI")) { e->sini = p; e->sini_n = n; return 1; }
    if (tag_eq(tag, "AIDF")) { e->aidf = p; e->aidf_n = n; return 1; }
    if (tag_eq(tag, "SKIL")) { e->skil = p; e->skil_n = n; return 1; }
    if (tag_eq(tag, "ANIM")) { e->anim = p; e->anim_n = n; return 1; }
    if (tag_eq(tag, "SCLS")) { e->scls = p; e->scls_n = n; return 1; }
    if (tag_eq(tag, "SCAT")) { e->scat = p; e->scat_n = n; return 1; }
    return 0;
}

static uint32_t region_size(uint32_t r)
{
    switch (r) {
    case TS4_RG_SELF: case TS4_RG_OPP: return TS4_PS_SIZE;
    case TS4_RG_BALL: return TS4_BALLIMG_SIZE;
    case TS4_RG_MATCH: return TS4_MATCH_SIZE;
    case TS4_RG_TEAM: return TS4_TEAM_SIZE;
    case TS4_RG_AI: return TS4_AI_SIZE;
    default: return 0xFFFFFFFFu;
    }
}

int32_t ts4_ext_resolve(Ts4Core *c)
{
    Ts4Ext *e = &c->ext;
    uint32_t i, k;
    if (e->bind && c->grph) {
        uint32_t n;
        if (e->bind_n < 4) return TS4_ERR_BAD_BLOB;
        n = ts4_le32(e->bind);
        if (!fits(4, n * 16u, e->bind_n)) return TS4_ERR_BAD_BLOB;
        for (i = 0; i < n; i++) {
            const uint8_t *d = e->bind + 4 + 16 * i;
            uint32_t gh = ts4_le32(d), gi = ts4_le32(d + 4), np = ts4_le32(d + 8), off = ts4_le32(d + 12);
            if (!fits(off, np * 8u, e->bind_n)) return TS4_ERR_BAD_BLOB;
            if (gi >= c->grph_n || gi >= TS4_MAX_GRAPHS || ts4_graph_hash(c, gi) != gh) continue;   /* stale entry */
            if (np != ts4_graph_input_count(c, gi) + ts4_graph_output_count(c, gi)) continue;
            if (ts4_graph_input_count(c, gi) > 256 || ts4_graph_output_count(c, gi) > 64) continue;
            for (k = 0; k < np; k++) {
                const uint8_t *pp = e->bind + off + 8 * k;
                uint32_t rg = pp[0], fo = ts4_le32(pp + 4);
                if (rg > TS4_RG_PARTNER) return TS4_ERR_BAD_BLOB;
                if (region_size(rg) != 0xFFFFFFFFu && !fits(fo, 4, region_size(rg))) return TS4_ERR_BAD_BLOB;
            }
            e->graph_bind[gi] = off + 1;
            e->n_bound++;
        }
    }
    if (e->sini) {
        if (e->sini_n < 4 || !fits(4, ts4_le32(e->sini) * 12u, e->sini_n)) return TS4_ERR_BAD_BLOB;
        for (i = 0; i < ts4_le32(e->sini); i++) {
            const uint8_t *r = e->sini + 4 + 12 * i;
            if (r[0] > TS4_RG_PARTNER || region_size(r[0]) == 0xFFFFFFFFu || !fits(ts4_le32(r + 4), 4, region_size(r[0])))
                return TS4_ERR_BAD_BLOB;
        }
    }
    if (e->aidf) {
        uint32_t ns, nl, s, l, j;
        if (e->aidf_n < 8) return TS4_ERR_BAD_BLOB;
        ns = ts4_le32(e->aidf); nl = ts4_le32(e->aidf + 4);
        if (ns > 64 || nl > 64 || !fits(8 + 4 * ns, ns * nl * TS4_AI_REC_SIZE, e->aidf_n)) return TS4_ERR_BAD_BLOB;
        for (s = 0; s < ns; s++)
            for (l = 0; l < nl; l++) {
                const uint8_t *r = e->aidf + 8 + 4 * ns + (s * nl + l) * TS4_AI_REC_SIZE;
                for (j = 0; j < 5; j++)
                    if (!fits(ts4_le32(r + TS4_AI_LOFF + 4 * j), ts4_le32(r + TS4_AI_LCOUNT + 4 * j) * 20u, e->aidf_n))
                        return TS4_ERR_BAD_BLOB;
            }
        e->ai_styles = ns; e->ai_levels = nl;
    }
    if (e->skil && (e->skil_n < 4 || !fits(4, ts4_le32(e->skil) * 4u, e->skil_n))) return TS4_ERR_BAD_BLOB;
    if (e->scls) {
        uint32_t nc, nr;
        if (e->scls_n < 8) return TS4_ERR_BAD_BLOB;
        nc = ts4_le32(e->scls);
        if (nc > 256 || !fits(4, nc * 64u + 4, e->scls_n)) return TS4_ERR_BAD_BLOB;
        nr = ts4_le32(e->scls + 4 + nc * 64u);
        if (nr > 4096 || !fits(8 + nc * 64u, nr * 8u, e->scls_n)) return TS4_ERR_BAD_BLOB;
        for (i = 0; i < nc; i++)
            if (ts4_le32(e->scls + 4 + 64 * i + 12) > 12) return TS4_ERR_BAD_BLOB;
        e->n_classes = nc; e->n_class_rows = nr;
    }
    if (e->scat) {
        uint32_t nm, nc;
        if (e->scat_n < 8) return TS4_ERR_BAD_BLOB;
        nm = ts4_le32(e->scat); nc = ts4_le32(e->scat + 4);
        if (nm > 8 || nc > 16 || !fits(8, 8 * nm * nc, e->scat_n)) return TS4_ERR_BAD_BLOB;
        for (i = 0; i < nm * nc; i++)
            if (!fits(ts4_le32(e->scat + 12 + 8 * i), 20 * ts4_le32(e->scat + 8 + 8 * i), e->scat_n)) return TS4_ERR_BAD_BLOB;
    }
    if (e->anim) {
        const uint8_t *a = e->anim;
        uint32_t *h = &e->an_nq;
        if (e->anim_n < 68) return TS4_ERR_BAD_BLOB;
        for (i = 0; i < 17; i++) h[i] = ts4_le32(a + 4 * i);
        if (e->an_nq > 32 || e->an_stride != 20u + 4u * e->an_nq || !fits(e->an_q, 4 * e->an_nq, e->anim_n) ||
            !fits(e->an_qv, 12 * e->an_nqv, e->anim_n) || !fits(e->an_clips, e->an_nclips * e->an_stride, e->anim_n) ||
            !fits(e->an_groups, 16 * e->an_ngroups, e->anim_n) || !fits(e->an_subs, 12 * e->an_nsubs, e->anim_n) ||
            !fits(e->an_ms, 12 * e->an_nms, e->anim_n) || !fits(e->an_rules, 24 * e->an_nrules, e->anim_n) ||
            !fits(e->an_mat, 8 * e->an_msize, e->anim_n))
            return TS4_ERR_BAD_BLOB;
        for (i = 0; i < e->an_nms; i++) {
            const uint8_t *m = a + e->an_ms + 12 * i;
            if (!fits(ts4_le32(m + 8), 4 * ts4_le32(m + 4), e->anim_n)) return TS4_ERR_BAD_BLOB;
        }
        for (i = 0; i < e->an_msize; i++) {
            const uint8_t *m = a + e->an_mat + 8 * i;
            if (!fits(ts4_le32(m + 4), 4 * ts4_le32(m), e->anim_n)) return TS4_ERR_BAD_BLOB;
        }
        for (i = 0; i < e->an_nclips; i++) {
            const uint8_t *cl = a + e->an_clips + e->an_stride * i;
            int16_t g = (int16_t)(cl[8] | (cl[9] << 8)), sb = (int16_t)(cl[10] | (cl[11] << 8));
            if (g < -1 || g >= (int32_t)e->an_ngroups || sb < -1 || sb >= (int32_t)e->an_nsubs) return TS4_ERR_BAD_BLOB;
        }
    }
    return TS4_OK;
}

int32_t ts4_bound(const Ts4Core *c) { return c->ext.n_bound != 0; }

int32_t ts4_gfind(const Ts4Core *c, uint32_t hash)
{
    uint32_t i;
    for (i = 0; i < c->grph_n; i++)
        if (ts4_graph_hash(c, i) == hash) return (int32_t)i;
    return -1;
}

static uint8_t *image(Ts4Core *c, uint32_t region, int player)
{
    switch (region) {
    case TS4_RG_SELF: return c->pl[player].ps;
    case TS4_RG_OPP: return c->pl[player ^ 1].ps;
    case TS4_RG_BALL: return c->ball_img;
    case TS4_RG_MATCH: return c->match_img;
    case TS4_RG_TEAM: return c->pl[player].team;
    case TS4_RG_AI: return c->pl[player].ai;
    default: return 0;
    }
}

int32_t ts4_bgraph(Ts4Core *c, int32_t gi, int player)
{
    static float in[256], out[64];   /* not reentrant; the core is single threaded */
    const uint8_t *ports;
    uint32_t n_in, n_out, k;
    if (gi < 0 || (uint32_t)gi >= c->grph_n || (uint32_t)gi >= TS4_MAX_GRAPHS || !c->ext.graph_bind[gi]) return 0;
    ports = c->ext.bind + c->ext.graph_bind[gi] - 1;
    n_in = ts4_graph_input_count(c, (uint32_t)gi);
    n_out = ts4_graph_output_count(c, (uint32_t)gi);
    for (k = 0; k < n_in; k++) {
        const uint8_t *pp = ports + 8 * k;
        uint32_t rg = pp[0], fl = pp[1], aux = (uint32_t)(pp[2] | (pp[3] << 8)), off = ts4_le32(pp + 4);
        uint8_t *img = image(c, rg, player);
        float v = 0.0f;
        if (img) {
            if (fl & F_RANDOM) ts4_fset(img, off, ts4_rng_range(&c->rng, 0.0f, 1.0f));
            v = ts4_fget(img, off);
        } else if (rg == TS4_RG_SKILL) {
            v = (off < 32 && ((c->extra[player].skill_mask >> off) & 1u)) ? 1.0f : 0.0f;
        } else if (rg == TS4_RG_QUAL) {
            v = ts4_anim_qual(c, player, aux, off);
        }
        in[k] = v;
    }
    ts4_graph_run(c, (uint32_t)gi, in, out, c->regs);
    for (k = 0; k < n_out; k++) {
        const uint8_t *pp = ports + 8 * (n_in + k);
        uint32_t rg = pp[0], off = ts4_le32(pp + 4);
        uint8_t *img = image(c, rg, player);
        if (!img) continue;
        if (rg == TS4_RG_BALL && (off < 0x480u || off >= 0x4C0u)) continue;   /* only the let block is writable */
        ts4_fset(img, off, out[k]);
    }
    return 1;
}

int32_t ts4_bgraph_h(Ts4Core *c, uint32_t hash, int player)
{
    return ts4_bgraph(c, ts4_gfind(c, hash), player);
}

void ts4_images_init(Ts4Core *c)
{
    uint32_t i, n;
    int p;
    memset(c->match_img, 0, sizeof c->match_img);
    memset(c->ball_img, 0, sizeof c->ball_img);
    for (p = 0; p < 2; p++) {
        memset(c->pl[p].ps, 0, TS4_PS_SIZE);
        memset(c->pl[p].ai, 0, TS4_AI_SIZE);
        memset(c->pl[p].team, 0, TS4_TEAM_SIZE);
    }
    if (!c->ext.sini) return;
    n = ts4_le32(c->ext.sini);
    for (i = 0; i < n; i++) {
        const uint8_t *r = c->ext.sini + 4 + 12 * i;
        uint32_t off = ts4_le32(r + 4);
        float v = ts4_lef32(r + 8);
        switch (r[0]) {
        case TS4_RG_SELF: ts4_fset(c->pl[0].ps, off, v); ts4_fset(c->pl[1].ps, off, v); break;
        case TS4_RG_AI: ts4_fset(c->pl[0].ai, off, v); ts4_fset(c->pl[1].ai, off, v); break;
        case TS4_RG_TEAM: ts4_fset(c->pl[0].team, off, v); ts4_fset(c->pl[1].team, off, v); break;
        case TS4_RG_MATCH: ts4_fset(c->match_img, off, v); break;
        default: break;
        }
    }
}

void ts4_ball_img_sync(Ts4Core *c)
{
    memcpy(c->ball_img, &c->ball.b, 0x480);
    memcpy(c->ball_img + 0x4C0, (const uint8_t *)&c->ball.b + 0x4C0, TS4_BALLIMG_SIZE - 0x4C0);
}

const uint8_t *ts4_ai_record(const Ts4Core *c, uint32_t style, uint32_t level)
{
    const Ts4Ext *e = &c->ext;
    if (!e->aidf || !e->ai_styles || !e->ai_levels) return 0;
    if (style >= e->ai_styles) style = e->ai_styles - 1;
    if (level >= e->ai_levels) level = e->ai_levels - 1;
    return e->aidf + 8 + 4 * e->ai_styles + (style * e->ai_levels + level) * TS4_AI_REC_SIZE;
}

/* SCLS: u32 n; n x {u32 id_hash, i32 aiming, i32 power, u32 n_el, i32 el[12]}; u32 n_rows; n_rows x {i32 cls, i32 ret} */
int32_t ts4_shot_class(const Ts4Core *c, uint32_t row, int is_return)
{
    const Ts4Ext *e = &c->ext;
    const uint8_t *r;
    int32_t v;
    if (!e->scls || row >= e->n_class_rows) return -1;
    r = e->scls + 8 + 64 * e->n_classes + 8 * row;
    v = (int32_t)ts4_le32(r + (is_return ? 4 : 0));
    if (is_return && v < 0) v = (int32_t)ts4_le32(r);
    return (v >= 0 && (uint32_t)v < e->n_classes) ? v : -1;
}

int32_t ts4_class_run(Ts4Core *c, int32_t cls, int player)
{
    const uint8_t *r;
    uint32_t n, i;
    if (cls < 0 || (uint32_t)cls >= c->ext.n_classes) return 0;
    r = c->ext.scls + 4 + 64 * (uint32_t)cls;
    n = ts4_le32(r + 12);
    for (i = 0; i < n; i++) ts4_bgraph(c, (int32_t)ts4_le32(r + 16 + 4 * i), player);   /* Element list, in order */
    ts4_bgraph(c, (int32_t)ts4_le32(r + 4), player);                                    /* aiming graph */
    ts4_bgraph(c, (int32_t)ts4_le32(r + 8), player);                                    /* power post-graph */
    return 1;
}

/* ---- public ---------------------------------------------------------------------------------------------- */
int32_t ts4_set_player_extra(Ts4Core *c, uint32_t player, const Ts4PlayerExtra *x)
{
    if (!c || c->magic != TS4_MAGIC || player > 1 || !x || x->struct_size < sizeof(Ts4PlayerExtra)) return TS4_ERR_ARG;
    c->extra[player] = *x;
    c->extra[player].struct_size = sizeof(Ts4PlayerExtra);
    return TS4_OK;
}

int32_t ts4_player_field(const Ts4Core *c, uint32_t player, uint32_t offset, float *value)
{
    if (!c || c->magic != TS4_MAGIC || player > 1 || !value || !fits(offset, 4, TS4_PS_SIZE)) return TS4_ERR_ARG;
    *value = ts4_fget(c->pl[player].ps, offset);
    return TS4_OK;
}
