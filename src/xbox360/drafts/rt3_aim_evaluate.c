/* EQUIVALENT, not byte-matched (6 register-number diffs; LTCG with callee context did not fix it).
 * Evidence: work/equiv/rt3_88695C48.json (196 valid trials, 100% blocks). Compile flags /Oc /fp:precise. */
/* RT3: aiming (Top Spin 4, Xbox 360, Swing_DLL.xex). */
extern float g_ts4_script_constants[];
extern float g_ts4_event_value;

struct Rt3AimState {            /* hitter+0x74 == shot context +4 */
    char pad0[0x5d8];
    unsigned char is_serving;
    char pad5d9[0xd88 - 0x5d9];
    float efficiency;           /* 0xd88 */
    char padd8c[0xd90 - 0xd8c];
    float quad_efficiency;      /* 0xd90 */
    char padd94[0xda4 - 0xd94];
    float random;               /* 0xda4 */
    float final_efficiency;     /* 0xda8 */
};
struct Rt3Rng { char pad0[0xb4]; char rng[1]; };
struct Rt3Pad1C { char pad0[0x1c]; struct Rt3Rng *rng; };
struct Rt3Hitter {
    char pad0[0x10];
    unsigned char is_human;
    char pad11[0x48 - 0x11];
    struct Rt3Pad1C *pad48;
    char pad4c[0x50 - 0x4c];
    char *pad50;
    char pad54[0x74 - 0x54];
    struct Rt3AimState *aim;
    char pad78[0x1dc - 0x78];
    char graph_human[4];
};
struct Rt3Entry { char pad0[0x18]; char graph[1]; };
struct Rt3ShotContext {
    struct Rt3Hitter *hitter;
    struct Rt3AimState *aim;
    char pad8[0x100 - 8];
    struct Rt3Entry *entry;
};

void ts4_loop_call_seq_u32_off2c_8890E988(void *graph);
float fn_8861E598(void *rng, float a, float b);

/* Swing_DLL.xex 0x88695C48: run the shot class aiming graph, then QuadEfficiency = FinalEfficiency */
void ts4_aiming_evaluate_88695C48(struct Rt3ShotContext *self)
{
    struct Rt3Entry *entry = self->entry;
    if (entry != 0) {
        float fin;
        if (self->hitter->is_human != 0 || self->hitter->aim->is_serving == 0)
            ts4_loop_call_seq_u32_off2c_8890E988(entry->graph);
        if (self->hitter->aim->is_serving == 0) {
            self->hitter->aim->random =
                fn_8861E598(self->hitter->pad48->rng->rng, g_ts4_event_value, g_ts4_script_constants[0]);
            if (self->hitter->is_human != 0) {
                ts4_loop_call_seq_u32_off2c_8890E988(self->hitter->graph_human);
            } else {
                ts4_loop_call_seq_u32_off2c_8890E988(self->hitter->pad50 + 0x1e0);
            }
            fin = self->hitter->aim->final_efficiency;
        } else {
            fin = self->aim->efficiency;
            self->aim->final_efficiency = fin;
        }
        self->aim->quad_efficiency = fin;
    }
}
