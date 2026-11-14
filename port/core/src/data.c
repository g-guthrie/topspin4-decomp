/*
 * ts4core data layer: blob parsing and validation, tunable registry, curves, analyser graph evaluator, roles.
 * Format: docs/port/data-format.md. Graph kernels: tools/ts4_analyser.py (bit-identical, see test_core.c).
 */
#include <string.h>

#include "ts4_internal.h"

/* ================================================================================================ */
/* names                                                                                             */
/* ================================================================================================ */
uint32_t ts4_crc32(const char *name)
{
    uint32_t crc = 0xFFFFFFFFu;
    for (; *name; ++name) {
        int bit;
        crc ^= (uint8_t)*name;
        for (bit = 0; bit < 8; ++bit) crc = (crc >> 1) ^ (0xEDB88320u & (0u - (crc & 1u)));
    }
    return ~crc;
}
uint32_t ts4_hash_name(const char *s) { return ts4_crc32(s); }

static const char *const tun_names[TS4_T_COUNT] = {
#define TS4_TUN(id, name, unit, origin, req, src) name,
#include "ts4_tunables.def"
#undef TS4_TUN
};
#define TS4_REQ_R 1
#define TS4_REQ_O 0
static const uint8_t tun_required[TS4_T_COUNT] = {
#define TS4_TUN(id, name, unit, origin, req, src) TS4_REQ_##req,
#include "ts4_tunables.def"
#undef TS4_TUN
};
static const char *const mod_names[TS4_MOD_COUNT] = {"data", "ball", "templates", "shot", "graphs", "rules",
                                                     "reach", "move", "swing", "ai"};

uint32_t ts4_api_version(void) { return TS4_API_VERSION; }
const char *ts4_build_info(void)
{
#if defined(__wasm__)
    return "ts4core 1 wasm32 soft-libm";
#else
    return "ts4core 1 host soft-libm";
#endif
}
uint32_t ts4_tunable_count(void) { return TS4_T_COUNT; }
const char *ts4_tunable_name(uint32_t id) { return id < TS4_T_COUNT ? tun_names[id] : (const char *)0; }
uint32_t ts4_tunable_key(uint32_t id) { return id < TS4_T_COUNT ? ts4_crc32(tun_names[id]) : 0u; }
const char *ts4_module_name(uint32_t m) { return m < TS4_MOD_COUNT ? mod_names[m] : (const char *)0; }

/* ================================================================================================ */
/* instance                                                                                          */
/* ================================================================================================ */
uint32_t ts4_core_size(void) { return (uint32_t)((sizeof(struct Ts4Core) + 15u) & ~15u); }

Ts4Core *ts4_core_init(void *mem, uint32_t mem_size)
{
    Ts4Core *c;
    if (!mem || ((uintptr_t)mem & 15u) || mem_size < ts4_core_size()) return (Ts4Core *)0;
    memset(mem, 0, ts4_core_size());
    c = (Ts4Core *)mem;
    c->magic = TS4_MAGIC;
    c->size = ts4_core_size();
    ts4_data_resolve(c);
    return c;
}

/* ================================================================================================ */
/* blob                                                                                              */
/* ================================================================================================ */
static int tag_is(const uint8_t *p, const char *t) { return p[0] == (uint8_t)t[0] && p[1] == (uint8_t)t[1] && p[2] == (uint8_t)t[2] && p[3] == (uint8_t)t[3]; }
static int in_bounds(uint32_t off, uint32_t len, uint32_t size) { return off <= size && len <= size - off; }

static int validate_graph(const uint8_t *g, uint32_t size)
{
    uint32_t nregs, n_in, n_out, n_nodes, ports_off, nodes_off, i;
    if (size < 32) return 0;
    nregs = ts4_le32(g + 4); n_in = ts4_le32(g + 8); n_out = ts4_le32(g + 12); n_nodes = ts4_le32(g + 16);
    ports_off = ts4_le32(g + 20); nodes_off = ts4_le32(g + 24);
    if (nregs > TS4_MAX_REGS || n_in > 1024 || n_out > 1024 || n_nodes > 4096) return 0;
    if (!in_bounds(ports_off, (n_in + n_out) * 16u, size) || !in_bounds(nodes_off, n_nodes * 32u, size)) return 0;
    for (i = 0; i < n_in + n_out; i++)
        if (ts4_le32(g + ports_off + 16 * i + 8) >= nregs) return 0;
    for (i = 0; i < n_nodes; i++) {
        const uint8_t *n = g + nodes_off + 32 * i;
        uint32_t kind = ts4_le32(n), cnt = ts4_le32(n + 20), off = ts4_le32(n + 24), j;
        int32_t out = (int32_t)ts4_le32(n + 4);
        uint32_t a = ts4_le32(n + 8), b = ts4_le32(n + 12), t = ts4_le32(n + 16);
        if (kind == 0xFFFFFFFFu) continue;
        if (kind > 10) return 0;
        if (out >= (int32_t)nregs) return 0;
        if (out < 0 && kind != 5) return 0;
        switch (kind) {
        case 0: break;
        case 1: case 2: case 3: case 4: case 6:
            if (!in_bounds(off, cnt * 4u, size)) return 0;
            for (j = 0; j < cnt; j++) if (ts4_le32(g + off + 4 * j) >= nregs) return 0;
            break;
        case 5:
            if (a >= nregs || !in_bounds(off, cnt * 16u, size)) return 0;
            break;
        case 7: case 8:
            if (a >= nregs || b >= nregs) return 0;
            break;
        default:
            if (a >= nregs || b >= nregs || t >= nregs) return 0;
            break;
        }
    }
    return 1;
}

static int tree_depth_ok(const uint8_t *nodes, uint32_t n, int32_t node, uint32_t depth)
{
    const uint8_t *p;
    int32_t ch[2];
    int k;
    if (depth > TS4_TREE_DEPTH) return 0;
    if (node < 0 || (uint32_t)node >= n) return 0;
    p = nodes + 12u * (uint32_t)node;
    ch[0] = (int32_t)ts4_le32(p + 4);
    ch[1] = (int32_t)ts4_le32(p + 8);
    for (k = 0; k < 2; k++)
        if (ch[k] >= 0 && !tree_depth_ok(nodes, n, ch[k], depth + 1)) return 0;
    return 1;
}

static int prefix_is(const char *s, const char *p)
{
    while (*p) { if (*s++ != *p++) return 0; }
    return 1;
}

static uint32_t tun_module(uint32_t id)
{
    const char *n = tun_names[id];
    if (prefix_is(n, "ball.")) return TS4_MOD_BALL;
    if (prefix_is(n, "court.") || prefix_is(n, "shot.") || prefix_is(n, "aim.") || prefix_is(n, "serve.") ||
        prefix_is(n, "receive."))
        return TS4_MOD_SHOT;
    if (prefix_is(n, "reach.")) return TS4_MOD_REACH;
    if (prefix_is(n, "move.")) return TS4_MOD_MOVE;
    if (prefix_is(n, "swing.")) return TS4_MOD_SWING;
    return TS4_MOD_AI;
}

int32_t ts4_data_resolve(Ts4Core *c)
{
    uint32_t i;
    c->n_missing = 0;
    for (i = 0; i < TS4_MOD_COUNT; i++) c->mod_status[i] = TS4_STATUS_READY;
    for (i = 0; i < TS4_T_COUNT; i++) {
        if (tun_required[i] && !c->tun_have[i]) {
            c->missing[c->n_missing++] = (uint8_t)i;
            c->mod_status[tun_module(i)] = TS4_STATUS_MISSING_DATA;
        }
    }
    if (!c->blob) c->mod_status[TS4_MOD_DATA] = TS4_STATUS_MISSING_DATA;
    if (!c->have_tpls || !c->have_tree) {
        c->mod_status[TS4_MOD_TEMPLATES] = TS4_STATUS_MISSING_DATA;
        c->mod_status[TS4_MOD_BALL] = TS4_STATUS_MISSING_DATA;
        c->mod_status[TS4_MOD_SHOT] = TS4_STATUS_MISSING_DATA;
    }
    if (!c->grph_n) c->mod_status[TS4_MOD_GRAPHS] = TS4_STATUS_DEGRADED;
    if (c->mod_status[TS4_MOD_REACH] == TS4_STATUS_READY &&
        (!c->roles[TS4_R_SELECTION_GROUND].present || !c->roles[TS4_R_SELECTION_VOLLEY].present ||
         !c->roles[TS4_R_SHOT_DIFFICULTY].present))
        c->mod_status[TS4_MOD_REACH] = TS4_STATUS_DEGRADED;
    if (c->mod_status[TS4_MOD_MOVE] == TS4_STATUS_READY) {
        uint32_t ty, n;
        if (!ts4_curve_find(c, ts4_crc32("move.table.rush"), &ty, &n) ||
            !ts4_curve_find(c, ts4_crc32("move.table.jogjog"), &ty, &n) ||
            !ts4_curve_find(c, ts4_crc32("move.table.jog"), &ty, &n))
            c->mod_status[TS4_MOD_MOVE] = TS4_STATUS_DEGRADED;
    }
    if (c->mod_status[TS4_MOD_SHOT] == TS4_STATUS_READY &&
        (!c->roles[TS4_R_SHOT_ERROR].present || !c->roles[TS4_R_LET_PROBABILITY].present))
        c->mod_status[TS4_MOD_SHOT] = TS4_STATUS_DEGRADED;
    if (c->mod_status[TS4_MOD_SWING] == TS4_STATUS_READY &&
        (!c->roles[TS4_R_DEFAULT_ATTRIBUTES].present))
        c->mod_status[TS4_MOD_SWING] = TS4_STATUS_DEGRADED;
    return TS4_OK;
}

int32_t ts4_data_load(Ts4Core *c, const uint8_t *blob, uint32_t size)
{
    uint32_t nsec, i, id;
    const uint8_t *tune = 0, *tpls = 0, *tree = 0, *grph = 0, *role = 0, *curv = 0;
    uint32_t tune_n = 0, tpls_n = 0, tree_n = 0, grph_n = 0, role_n = 0, curv_n = 0;
    if (!c || c->magic != TS4_MAGIC || !blob) return TS4_ERR_ARG;
    if (c->started) return TS4_ERR_ARG;
    if (size < 16 || !tag_is(blob, "TS4D") || ts4_le32(blob + 4) != 1u) return TS4_ERR_BAD_BLOB;
    nsec = ts4_le32(blob + 8);
    if (nsec > 64 || !in_bounds(16, nsec * 16u, size)) return TS4_ERR_BAD_BLOB;
    for (i = 0; i < nsec; i++) {
        const uint8_t *d = blob + 16 + 16 * i;
        uint32_t off = ts4_le32(d + 4), len = ts4_le32(d + 8);
        if ((off & 3u) || !in_bounds(off, len, size)) return TS4_ERR_BAD_BLOB;
        if (tag_is(d, "TUNE")) { tune = blob + off; tune_n = len; }
        else if (tag_is(d, "TPLS")) { tpls = blob + off; tpls_n = len; }
        else if (tag_is(d, "TREE")) { tree = blob + off; tree_n = len; }
        else if (tag_is(d, "GRPH")) { grph = blob + off; grph_n = len; }
        else if (tag_is(d, "ROLE")) { role = blob + off; role_n = len; }
        else if (tag_is(d, "CURV")) { curv = blob + off; curv_n = len; }
    }
    /* reset everything derived from a previous blob (runtime overrides stay) */
    c->blob = blob; c->blob_size = size;
    c->have_tune = c->have_tpls = c->have_tree = 0;
    c->grph = 0; c->grph_n = 0; c->curv = 0; c->curv_n = 0;
    for (id = 0; id < TS4_R_COUNT; id++) c->roles[id].present = 0;
    for (id = 0; id < TS4_T_COUNT; id++) if (c->tun_have[id] == 1) { c->tun_have[id] = 0; c->tun_prov[id] = 0; }

    if (tune) {
        uint32_t n, k, prev = 0;
        if (tune_n < 4) return TS4_ERR_BAD_BLOB;
        n = ts4_le32(tune);
        if (!in_bounds(4, n * 12u, tune_n)) return TS4_ERR_BAD_BLOB;
        for (k = 0; k < n; k++) {
            uint32_t key = ts4_le32(tune + 4 + 12 * k);
            if (k && key <= prev) return TS4_ERR_BAD_BLOB;
            prev = key;
        }
        for (id = 0; id < TS4_T_COUNT; id++) {
            uint32_t key = ts4_crc32(tun_names[id]), lo = 0, hi = n;
            if (c->tun_have[id] == 2) continue;
            while (lo < hi) {
                uint32_t mid = (lo + hi) / 2, mk = ts4_le32(tune + 4 + 12 * mid);
                if (mk < key) lo = mid + 1; else hi = mid;
            }
            if (lo < n && ts4_le32(tune + 4 + 12 * lo) == key) {
                c->tun[id] = ts4_lef32(tune + 8 + 12 * lo);
                c->tun_have[id] = 1;
                c->tun_prov[id] = (uint8_t)(ts4_le32(tune + 12 + 12 * lo) & 1u);
            }
        }
        c->have_tune = 1;
    }
    if (tpls) {
        uint32_t rows, stride, roff, psz;
        if (tpls_n < 16) return TS4_ERR_BAD_BLOB;
        rows = ts4_le32(tpls); stride = ts4_le32(tpls + 4); roff = ts4_le32(tpls + 8); psz = ts4_le32(tpls + 12);
        if (stride < 0x8C || rows == 0 || rows > 4096 || !in_bounds(16, psz, tpls_n) || !in_bounds(roff, rows * stride, psz))
            return TS4_ERR_BAD_BLOB;
        c->tpl_payload = tpls + 16; c->tpl_rows = rows; c->tpl_stride = stride; c->tpl_rows_off = roff;
        c->tpl_payload_size = psz;
        c->have_tpls = 1;
    }
    if (tree) {
        uint32_t n, root;
        if (tree_n < 8) return TS4_ERR_BAD_BLOB;
        n = ts4_le32(tree); root = ts4_le32(tree + 4);
        if (n == 0 || !in_bounds(8, n * 12u, tree_n) || root >= n) return TS4_ERR_BAD_BLOB;
        for (i = 0; i < n; i++) {
            int k;
            for (k = 0; k < 2; k++) {
                int32_t ch = (int32_t)ts4_le32(tree + 8 + 12 * i + 4 + 4 * k);
                if (ch >= 0 && (uint32_t)ch >= n) return TS4_ERR_BAD_BLOB;
                if (ch < 0 && c->have_tpls && (uint32_t)(~ch) >= c->tpl_rows) return TS4_ERR_BAD_BLOB;
            }
        }
        if (!tree_depth_ok(tree + 8, n, (int32_t)root, 0)) return TS4_ERR_BAD_BLOB;
        c->tree = tree + 8; c->tree_n = n; c->tree_root = root;
        c->have_tree = 1;
    }
    if (grph) {
        uint32_t n;
        if (grph_n < 4) return TS4_ERR_BAD_BLOB;
        n = ts4_le32(grph);
        if (!in_bounds(4, n * 12u, grph_n)) return TS4_ERR_BAD_BLOB;
        for (i = 0; i < n; i++) {
            const uint8_t *d = grph + 4 + 12 * i;
            uint32_t off = ts4_le32(d + 4), len = ts4_le32(d + 8);
            if ((off & 3u) || !in_bounds(off, len, grph_n) || !validate_graph(grph + off, len)) return TS4_ERR_BAD_BLOB;
            if (ts4_le32(grph + off) != ts4_le32(d)) return TS4_ERR_BAD_BLOB;
        }
        c->grph = grph; c->grph_n = n; c->grph_size = grph_n;
    }
    if (curv) {
        uint32_t n;
        if (curv_n < 4) return TS4_ERR_BAD_BLOB;
        n = ts4_le32(curv);
        if (!in_bounds(4, n * 16u, curv_n)) return TS4_ERR_BAD_BLOB;
        for (i = 0; i < n; i++) {
            const uint8_t *d = curv + 4 + 16 * i;
            uint32_t ty = ts4_le32(d + 4), cnt = ts4_le32(d + 8), off = ts4_le32(d + 12);
            if (ty > 2) return TS4_ERR_BAD_BLOB;
            if (ty < 2 && !in_bounds(off, cnt * 16u, curv_n)) return TS4_ERR_BAD_BLOB;
            if (ty == 2) {
                uint32_t r, pos = off;
                if (cnt > 64) return TS4_ERR_BAD_BLOB;
                for (r = 0; r < cnt; r++) {
                    uint32_t nk;
                    if (!in_bounds(pos, 8, curv_n)) return TS4_ERR_BAD_BLOB;
                    nk = ts4_le32(curv + pos + 4);
                    if (!in_bounds(pos + 8, nk * 16u, curv_n)) return TS4_ERR_BAD_BLOB;
                    pos += 8 + nk * 16u;
                }
            }
        }
        c->curv = curv; c->curv_n = n; c->curv_size = curv_n;
    }
    if (role) {
        uint32_t n, pos = 4, k;
        if (role_n < 4) return TS4_ERR_BAD_BLOB;
        n = ts4_le32(role);
        for (k = 0; k < n; k++) {
            uint32_t rid, gh, ni, no, j;
            int32_t gi = -1;
            if (!in_bounds(pos, 16, role_n)) return TS4_ERR_BAD_BLOB;
            rid = ts4_le32(role + pos); gh = ts4_le32(role + pos + 4);
            ni = ts4_le32(role + pos + 8); no = ts4_le32(role + pos + 12);
            if (ni > TS4_ROLE_PORTS || no > TS4_ROLE_PORTS || !in_bounds(pos + 16, (ni + no) * 4u, role_n)) return TS4_ERR_BAD_BLOB;
            for (j = 0; j < ni + no; j++)
                if (ts4_le32(role + pos + 16 + 4 * j) >= TS4_V_COUNT) return TS4_ERR_BAD_BLOB;
            if (rid < TS4_R_COUNT) {
                for (j = 0; j < c->grph_n; j++)
                    if (ts4_le32(c->grph + 4 + 12 * j) == gh) { gi = (int32_t)j; break; }
                if (gi >= 0) {
                    const uint8_t *g = c->grph + ts4_le32(c->grph + 4 + 12 * (uint32_t)gi + 4);
                    if (ts4_le32(g + 8) == ni && ts4_le32(g + 12) == no) {
                        Ts4RoleBinding *b = &c->roles[rid];
                        b->present = 1; b->graph_index = (uint32_t)gi; b->n_in = ni; b->n_out = no;
                        for (j = 0; j < ni; j++) b->in_var[j] = (uint8_t)ts4_le32(role + pos + 16 + 4 * j);
                        for (j = 0; j < no; j++) b->out_var[j] = (uint8_t)ts4_le32(role + pos + 16 + 4 * (ni + j));
                    }
                }
            }
            pos += 16 + (ni + no) * 4u;
        }
    }
    ts4_data_resolve(c);
    return TS4_OK;
}

/* ================================================================================================ */
/* tunables, status                                                                                  */
/* ================================================================================================ */
int32_t ts4_set_tunable(Ts4Core *c, uint32_t id, float value)
{
    if (!c || c->magic != TS4_MAGIC || id >= TS4_T_COUNT) return TS4_ERR_ARG;
    c->tun[id] = value;
    c->tun_have[id] = 2;
    c->tun_prov[id] = 0;
    ts4_data_resolve(c);
    return TS4_OK;
}
int32_t ts4_get_tunable(const Ts4Core *c, uint32_t id, float *value)
{
    if (!c || c->magic != TS4_MAGIC || id >= TS4_T_COUNT || !value) return TS4_ERR_ARG;
    if (!c->tun_have[id]) return TS4_ERR_MISSING_DATA;
    *value = c->tun[id];
    return TS4_OK;
}
uint32_t ts4_missing_tunable_count(const Ts4Core *c) { return c ? c->n_missing : 0; }
uint32_t ts4_missing_tunable_id(const Ts4Core *c, uint32_t i) { return (c && i < c->n_missing) ? c->missing[i] : 0xFFFFFFFFu; }
uint32_t ts4_module_status(const Ts4Core *c, uint32_t m) { return (c && m < TS4_MOD_COUNT) ? c->mod_status[m] : TS4_STATUS_MISSING_DATA; }

uint32_t ts4_template_count(const Ts4Core *c) { return (c && c->have_tpls) ? c->tpl_rows : 0; }
const uint8_t *ts4_template_row(const Ts4Core *c, uint32_t row)
{
    if (!c || !c->have_tpls || row >= c->tpl_rows) return (const uint8_t *)0;
    return c->tpl_payload + c->tpl_rows_off + row * c->tpl_stride;
}
uint32_t ts4_template_id(const Ts4Core *c, uint32_t row)
{
    const uint8_t *r = ts4_template_row(c, row);
    if (!r) return 0;
    return ((uint32_t)r[0x88] << 24) | ((uint32_t)r[0x89] << 16) | ((uint32_t)r[0x8A] << 8) | r[0x8B];
}

/* ================================================================================================ */
/* curves                                                                                            */
/* ================================================================================================ */
float ts4_curve16_le(const uint8_t *keys, uint32_t n, float x)
{
    const uint8_t *sel = keys;
    uint32_t i;
    float x0, x1, y0, y1, dx, span, dy, lo, t;
    if (!n) return 0.0f;
    for (i = 0; i < n; i++) {
        if (ts4_lef32(keys + 16 * i) > x) break;
        sel = keys + 16 * i;
    }
    x0 = ts4_lef32(sel); x1 = ts4_lef32(sel + 4); y0 = ts4_lef32(sel + 8); y1 = ts4_lef32(sel + 12);
    dx = x - x0; span = x1 - x0; dy = y1 - y0;
    lo = (dx >= 0.0f) ? dx : 0.0f;
    t = ((lo - span) >= 0.0f) ? span : lo;
    return ts4_fmaf(t / span, dy, y0);
}

float ts4_curve20_le(const uint8_t *keys, uint32_t n, float x)
{
    const uint8_t *sel = keys;
    uint32_t i;
    float x0, x1, y0, slope, d, span, ds, t;
    if (!n) return 0.0f;
    for (i = 0; i < n; i++) {
        if (ts4_lef32(keys + 16 * i) > x) break;   /* a NaN compare does not stop the scan (as the original) */
        sel = keys + 16 * i;
    }
    x0 = ts4_lef32(sel); x1 = ts4_lef32(sel + 4); y0 = ts4_lef32(sel + 8); slope = ts4_lef32(sel + 12);
    d = x - x0; span = x1 - x0; ds = d - span;
    t = (ds != ds || ds < 0.0f) ? d : span;       /* fsel(d - span): d when negative or unordered */
    if (t != t || t < 0.0f) t = 0.0f;
    return ts4_fmaf(t, slope, y0);
}

float ts4_table2d_le(const uint8_t *rows, uint32_t n_rows, float a, float b)
{
    const uint8_t *rp[64];
    uint32_t nk[64], i, lo, hi;
    const uint8_t *p = rows;
    float d, span, vlo, vhi;
    if (!n_rows || n_rows > 64) return 0.0f;
    for (i = 0; i < n_rows; i++) {
        rp[i] = p;
        nk[i] = ts4_le32(p + 4);
        p += 8 + 16u * nk[i];
    }
    lo = hi = 0;
    for (;;) {
        d = a - ts4_lef32(rp[hi]);
        if (d < 0.0f || (d == 0.0f && 1.0f / d < 0.0f)) break;   /* sign bit set */
        lo = hi;
        hi++;
        if (hi == n_rows) break;
    }
    if (lo == hi || hi == n_rows) return ts4_curve16_le(rp[lo] + 8, nk[lo], b);
    vlo = ts4_curve16_le(rp[lo] + 8, nk[lo], b);
    vhi = ts4_curve16_le(rp[hi] + 8, nk[hi], b);
    d = a - ts4_lef32(rp[lo]);
    span = ts4_lef32(rp[hi]) - ts4_lef32(rp[lo]);
    if (d > 0.0f) {
        if (d >= span) return vhi;
        return ts4_fmaf(d / span, vhi - vlo, vlo);
    }
    return vlo;
}

const uint8_t *ts4_curve_find(const Ts4Core *c, uint32_t name_hash, uint32_t *type, uint32_t *n)
{
    uint32_t i;
    if (!c->curv) return (const uint8_t *)0;
    for (i = 0; i < c->curv_n; i++) {
        const uint8_t *d = c->curv + 4 + 16 * i;
        if (ts4_le32(d) == name_hash) {
            *type = ts4_le32(d + 4);
            *n = ts4_le32(d + 8);
            return c->curv + ts4_le32(d + 12);
        }
    }
    return (const uint8_t *)0;
}

/* ================================================================================================ */
/* analyser graphs                                                                                   */
/* ================================================================================================ */
uint32_t ts4_graph_count(const Ts4Core *c) { return c ? c->grph_n : 0; }
static const uint8_t *graph_at(const Ts4Core *c, uint32_t i)
{
    return c->grph + ts4_le32(c->grph + 4 + 12 * i + 4);
}
uint32_t ts4_graph_hash(const Ts4Core *c, uint32_t i) { return (c && i < c->grph_n) ? ts4_le32(c->grph + 4 + 12 * i) : 0; }
int32_t ts4_graph_find(const Ts4Core *c, uint32_t hash)
{
    uint32_t i;
    if (!c) return TS4_ERR_ARG;
    for (i = 0; i < c->grph_n; i++)
        if (ts4_le32(c->grph + 4 + 12 * i) == hash) return (int32_t)i;
    return TS4_ERR_ARG;
}
uint32_t ts4_graph_input_count(const Ts4Core *c, uint32_t i) { return (c && i < c->grph_n) ? ts4_le32(graph_at(c, i) + 8) : 0; }
uint32_t ts4_graph_output_count(const Ts4Core *c, uint32_t i) { return (c && i < c->grph_n) ? ts4_le32(graph_at(c, i) + 12) : 0; }

static float clamp01(float v)
{
    if (v != v || v < 0.0f) v = 0.0f;
    return (v - 1.0f >= 0.0f) ? 1.0f : v;
}

int32_t ts4_graph_run(const Ts4Core *c, uint32_t index, const float *in, float *out, float *regs)
{
    const uint8_t *g = graph_at(c, index);
    uint32_t nregs = ts4_le32(g + 4), n_in = ts4_le32(g + 8), n_out = ts4_le32(g + 12), n_nodes = ts4_le32(g + 16);
    const uint8_t *ports = g + ts4_le32(g + 20), *nodes = g + ts4_le32(g + 24);
    uint32_t i, j;
    for (i = 0; i < nregs; i++) regs[i] = 0.0f;
    for (i = 0; i < n_in; i++) regs[ts4_le32(ports + 16 * i + 8)] = in[i];
    for (i = 0; i < n_nodes; i++) {
        const uint8_t *nd = nodes + 32 * i;
        uint32_t kind = ts4_le32(nd), cnt = ts4_le32(nd + 20), off = ts4_le32(nd + 24);
        int32_t out_r = (int32_t)ts4_le32(nd + 4);
        uint32_t a = ts4_le32(nd + 8), b = ts4_le32(nd + 12), t = ts4_le32(nd + 16);
        float acc, x, d;
        switch (kind) {
        case 0: regs[out_r] = ts4_lef32(nd + 28); break;
        case 1: case 2: case 3: case 4:
            acc = cnt ? regs[ts4_le32(g + off)] : 0.0f;
            for (j = 1; j < cnt; j++) {
                x = regs[ts4_le32(g + off + 4 * j)];
                if (kind == 1) acc = x + acc;
                else if (kind == 2) acc = x * acc;
                else if (kind == 3) { d = acc - x; if (d >= 0.0f) acc = x; }
                else { d = acc - x; if (!(d >= 0.0f)) acc = x; }
            }
            regs[out_r] = acc;
            break;
        case 5:
            if (out_r >= 0) regs[out_r] = ts4_curve20_le(g + off, cnt, regs[a]);
            break;
        case 6: {
            int bad = 0;
            acc = 0.0f;
            for (j = 0; j < cnt; j++) {
                x = regs[ts4_le32(g + off + 4 * j)];
                if (x < 0.0f) { bad = 1; break; }
                acc = (j == 0) ? x : x + acc;
            }
            regs[out_r] = bad ? -1.0f : acc;
            break;
        }
        case 7: regs[out_r] = regs[a] - regs[b]; break;
        case 8: regs[out_r] = regs[a] / regs[b]; break;
        case 9: regs[out_r] = ts4_fmaf(clamp01(regs[t]), regs[b] - regs[a], regs[a]); break;
        case 10: regs[out_r] = clamp01((regs[t] - regs[a]) / (regs[b] - regs[a])); break;
        default: break;   /* unknown node type: no kernel, skipped */
        }
    }
    for (j = 0; j < n_out; j++) out[j] = regs[ts4_le32(ports + 16 * (n_in + j) + 8)];
    return TS4_OK;
}

int32_t ts4_graph_eval(const Ts4Core *c, uint32_t index, const float *in, uint32_t n_in, float *out, uint32_t n_out)
{
    float regs[TS4_MAX_REGS];
    if (!c || c->magic != TS4_MAGIC || index >= c->grph_n || !in || !out) return TS4_ERR_ARG;
    if (n_in != ts4_graph_input_count(c, index) || n_out != ts4_graph_output_count(c, index)) return TS4_ERR_ARG;
    return ts4_graph_run(c, index, in, out, regs);
}

int32_t ts4_role_run(Ts4Core *c, uint32_t role, float *vars)
{
    const Ts4RoleBinding *b;
    float in[TS4_ROLE_PORTS], out[TS4_ROLE_PORTS];
    uint32_t i;
    if (role >= TS4_R_COUNT) return 0;
    b = &c->roles[role];
    if (!b->present) return 0;
    vars[TS4_V_ZERO] = 0.0f;
    for (i = 0; i < b->n_in; i++) in[i] = vars[b->in_var[i]];
    ts4_graph_run(c, b->graph_index, in, out, c->regs);
    for (i = 0; i < b->n_out; i++)
        if (b->out_var[i] != TS4_V_ZERO) vars[b->out_var[i]] = out[i];
    return 1;
}
