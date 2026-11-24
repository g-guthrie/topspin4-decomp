/*
 * D1G: analyser-graph binding (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * See docs/gameplay/analyser-graphs.md and gp8.md (fatigue analysers).
 */
#include "d1g_types.h"

/* A loaded graph: +0x28 name hash. */
struct Ts4Graph {
    ts4_u8 pad_00[0x28];
    ts4_u32 name;
};
struct Ts4GraphSlot {           /* 8 bytes */
    ts4_u32 unk_00;
    struct Ts4Graph *graph;     /* +0x04 */
};
struct Ts4GraphCount {
    ts4_u32 unk_00;
    int count;                  /* +0x04 */
};
/* The player's graph set (PC+0x44). */
struct Ts4GraphSet {
    ts4_u8 pad_00[0x70];
    struct Ts4GraphCount *header;   /* +0x70 */
    ts4_u8 pad_74[0x18];
    ts4_u8 inputs_8c[0x10];         /* +0x8C analyser input table (passed by address) */
    struct Ts4GraphSlot *slots;     /* +0x9C */
    ts4_u8 pad_a0[0x34];
    ts4_u8 outputs_d4[4];           /* +0xD4 analyser output table (passed by address) */
};

/* Find the graph slot whose graph name hash is *name; null when absent. Swing_DLL.xex 0x8866F028 */
D1G_NOINLINE struct Ts4GraphSlot *ts4_graph_set_find_8866F028(struct Ts4GraphSet *set, const ts4_u32 *name)
{
    int i = 0;
    int n = set->header->count;
    if (n > 0) {
        for (; i < n; i++) {
            if (set->slots[i].graph->name == *name)
                break;
        }
    }
    if (i == n)
        return 0;
    return &set->slots[i];
}

/* Graph-name hashes of the fatigue analysers (gp8.md). */
#define TS4_GRAPH_FATIGUE_INGAME 0xCBE44A9Bu
#define TS4_GRAPH_FATIGUE_CONST  0x6BD1FBABu

/* One bound analyser (0x44 bytes). */
struct Ts4Analyser {
    ts4_u8 data[0x44];
};

struct Ts4AnalyserTuning {
    ts4_u8 pad_000[0x61C];
    int fatigue_slots;          /* +0x61C */
};

/* The player object that owns the analysers. */
struct Ts4AnalyserOwner {
    ts4_u8 pad_000[0x2C];
    struct Ts4AnalyserTuning *tuning;  /* +0x2C */
    ts4_u8 pad_030[0x14];
    struct Ts4GraphSet *graphs;        /* +0x44 */
    ts4_u8 pad_048[0x2E8];
    ts4_u8 inputs_330[4];              /* +0x330 per-player analyser inputs (passed by address) */
};

/* Fatigue analysers: five graphs and a per-slot byte array sized from the tuning. */
struct Ts4FatigueAnalysers {
    struct Ts4AnalyserOwner *owner;    /* +0x000 */
    struct Ts4Analyser ingame;         /* +0x004 FatigueIngame */
    struct Ts4Analyser graph_8add300f; /* +0x048 */
    struct Ts4Analyser graph_80ce1a10; /* +0x08C */
    struct Ts4Analyser fatigue_const;  /* +0x0D0 FatigueConst */
    struct Ts4Analyser graph_9d734117; /* +0x114 */
    ts4_u8 pad_158[0x70];
    ts4_u8 *slots;                     /* +0x1C8 */
    int slot_count;                    /* +0x1CC */
};

extern void *lbl_88D45B38;
void *ts4_node_dispatch_with_target_88613268(void *heap, int size, int align, int flags, int tag);
void ts4_registry_dispatch_888860A0(void *p);
void fn_88911668(struct Ts4Analyser *analyser, void *inputs, struct Ts4GraphSlot *graph, void *graph_inputs,
                 void *graph_outputs);

/* Bind one analyser to the named graph of the owner's graph set when the graph exists. */
static void ts4_fatigue_bind(struct Ts4FatigueAnalysers *self, struct Ts4AnalyserOwner *owner,
                             struct Ts4GraphSet *graphs, struct Ts4Analyser *analyser, ts4_u32 name)
{
    struct Ts4GraphSlot *graph = ts4_graph_set_find_8866F028(graphs, &name);
    (void)self;
    if (graph)
        fn_88911668(analyser, owner->inputs_330, graph, graphs->inputs_8c, graphs->outputs_d4);
}

/* Initialise the fatigue analysers: bind the five graphs (FatigueIngame, 0x80CE1A10, 0x8ADD300F,
   0x9D734117, FatigueConst) and resize the slot byte array to tuning+0x61C, cleared to zero.
   Swing_DLL.xex 0x886BC1E0 */
void ts4_fatigue_analysers_init_886BC1E0(struct Ts4FatigueAnalysers *self, struct Ts4AnalyserOwner *owner)
{
    struct Ts4GraphSet *graphs;
    int n;
    int i;
    self->owner = owner;
    graphs = owner->graphs;
    ts4_fatigue_bind(self, owner, graphs, &self->ingame, TS4_GRAPH_FATIGUE_INGAME);
    ts4_fatigue_bind(self, owner, graphs, &self->graph_80ce1a10, 0x80CE1A10u);
    ts4_fatigue_bind(self, owner, graphs, &self->graph_8add300f, 0x8ADD300Fu);
    ts4_fatigue_bind(self, owner, graphs, &self->graph_9d734117, 0x9D734117u);
    ts4_fatigue_bind(self, owner, graphs, &self->fatigue_const, TS4_GRAPH_FATIGUE_CONST);
    n = self->owner->tuning->fatigue_slots;
    if (n == 0) {
        if ((int)(long)self->slots != 0) {
            ts4_registry_dispatch_888860A0(self->slots);
            self->slots = 0;
            self->slot_count = 0;
        }
        self->slots = 0;
        self->slot_count = 0;
    } else {
        self->slots = (ts4_u8 *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, n, 1, 0, 2);
        self->slot_count = n;
    }
    for (i = 0; (unsigned)i < (unsigned)n; i++)
        self->slots[i] = 0;
}
