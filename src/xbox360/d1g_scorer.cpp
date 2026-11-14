/*
 * D1G: AI hit-point scorer (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * The scorer class (vtable 0x880F4428) binds four analyser graphs; slot 3 binds a hashes[4] array,
 * slot 4 binds one hash into all four slots. docs/gameplay/graphs-decoded.md ("Graphs 1-4 run").
 */
#include "d1g_types.h"

/* Four graph hashes (graphs 1-4 of the hit-point scorer). */
struct Ts4ScorerGraphs {
    ts4_u32 hash[4];
    Ts4ScorerGraphs()
    {
        hash[0] = 0;
        hash[1] = 0;
        hash[2] = 0;
        hash[3] = 0;
    }
    void fill(ts4_u32 h)
    {
        for (int i = 0; i < 4; i++)
            hash[i] = h;
    }
};

struct Ts4HitPointScorer;

struct Ts4HitPointScorerVtbl {
    void *slot0;
    void *slot1;
    void *evaluate;                                               /* +0x08 fn_88692040 */
    void (*bind)(struct Ts4HitPointScorer *self, Ts4ScorerGraphs *graphs); /* +0x0C fn_886B6348 */
};

struct Ts4HitPointScorer {
    struct Ts4HitPointScorerVtbl *vtbl;
};

/* HitPointScorer slot 4: bind the same graph hash into all four slots. Swing_DLL.xex 0x8867C488 */
D1G_EXTERN_C void ts4_hit_point_scorer_bind_one_8867C488(struct Ts4HitPointScorer *self, ts4_u32 hash)
{
    Ts4ScorerGraphs graphs;
    graphs.fill(hash);
    self->vtbl->bind(self, &graphs);
}
