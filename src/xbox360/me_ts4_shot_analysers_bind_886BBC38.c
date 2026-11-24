/* Swing_DLL.xex 0x886BBC38 (ts4_shot_analysers_bind), size 0xE4: binds the shot analysers. Looks up graph 0xDAF1C0D6 and graph
 * 0x9C8607A7 in self->graphs and, for each one found, binds the first/second analyser to it with the graph set's
 * input (+0x8C) and output (+0xD4) tables. Sets the body weight to the event default value for shot kind
 * 0x4DD88F5A, else to script constant 0, and points graph_data at graphs+0xB4.
 * Matching note: the weight stores go through a block-local pointer, so the graphs reload is scheduled after
 * the stfs (agP 2026-11-19; was a 2-off draft). Matches on LTCG; plain /Oc only differs by the stale
 * lbl_8814B440 name for g_ts4_event_value in the reference build. */
#include "d1g_types.h"
struct Ts4GraphSlot;
struct Ts4GraphSet {
    ts4_u8 pad_00[0x8c];
    ts4_u8 inputs_8c[0x48];         /* +0x8C analyser input table */
    ts4_u8 outputs_d4[4];           /* +0xD4 analyser output table */
};
struct Ts4Analyser { ts4_u8 data[0x44]; };
struct Ts4BodyState { ts4_u8 pad_000[0x580]; float weight; };
struct Ts4ShotCtx {
    ts4_u8 pad_00[0x20];
    ts4_u32 kind;                   /* +0x20 */
    ts4_u8 pad_24[0x50];
    struct Ts4BodyState *body;      /* +0x74 */
};
struct Ts4ShotAnalysers {
    ts4_u32 unk_00;
    struct Ts4GraphSet *graphs;     /* +0x04 */
    struct Ts4ShotCtx *ctx;         /* +0x08 */
    ts4_u32 unk_0c;
    void *inputs;                   /* +0x10 */
    struct Ts4Analyser first;       /* +0x14 */
    ts4_u8 *graph_data;             /* +0x58 */
    struct Ts4Analyser second;      /* +0x5C */
};
extern const float g_ts4_event_value;
extern const float g_ts4_script_constants[];
struct Ts4GraphSlot *ts4_graph_set_find_8866F028(struct Ts4GraphSet *set, const ts4_u32 *name);
void fn_88911668(struct Ts4Analyser *analyser, void *inputs, struct Ts4GraphSlot *graph, void *graph_inputs,
                 void *graph_outputs);
void ts4_shot_analysers_bind(struct Ts4ShotAnalysers *self)
{
    struct Ts4GraphSet *graphs = self->graphs;
    struct Ts4GraphSlot *g;
    ts4_u32 name;
    name = 0xDAF1C0D6u;
    g = ts4_graph_set_find_8866F028(graphs, &name);
    if (g) fn_88911668(&self->first, self->inputs, g, graphs->inputs_8c, graphs->outputs_d4);
    name = 0x9C8607A7u;
    g = ts4_graph_set_find_8866F028(graphs, &name);
    if (g) fn_88911668(&self->second, self->inputs, g, graphs->inputs_8c, graphs->outputs_d4);
    {
        if (self->ctx->kind == 0x4DD88F5Au) { float *pw = &self->ctx->body->weight; *pw = g_ts4_event_value; }
        else { float *pw = &self->ctx->body->weight; *pw = g_ts4_script_constants[0]; }
    }
    self->graph_data = (ts4_u8 *)self->graphs + 0xb4;
}
