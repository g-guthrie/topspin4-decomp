/* agD 2026-11-19: C rewrite in me_8869FAD8_nearmiss.c (88695568 model: Quad-cast arr_init, five explicit sub_init calls, 1.0 is g_ts4_script_constants[0]) is 58 off plain (vs 129 here). */
/* agentA2 (2026-11-18 tips pass): StatHist via Quad-cast inline (88695568 style) becomes a loop (0xf8), via inline hist_init stays 129/130 off; dead addi not reproduced. */
/* near-miss 0x8869FAD8 (C++, LTCG with primer, check as ??0ShotStats@@QAA@XZ): 129 off, mostly a shift. The target keeps nine dead addi (this+4/+0x48/... and +0x14 = each group and its history), 0x24 bytes we do not emit; likely the group/history ctors were separate functions inlined at LTCG. Vtable is lbl_880D7600 (a real virtual class names it ??_7StatGroup@@6B@). */
/* 0x8869FAD8: constructs a shot-statistics block: five counter groups (vtable 0x880D7600, four totals and a
 * twelve-entry history each), four reset words, 24 float averages (zero, the 18th starting at 1.0) and two words. */
extern "C" const void *lbl_880D7600[];
extern "C" float g_ts4_event_value;
struct StatHist { int v[12]; StatHist() { v[0] = 0; v[1] = 0; v[2] = 0; v[3] = 0; v[4] = 0; v[5] = 0; v[6] = 0; v[7] = 0; v[8] = 0; v[9] = 0; v[10] = 0; v[11] = 0; } };
struct StatGroup {
    int total[4]; StatHist hist;
    StatGroup() { total[0] = 0; total[1] = 0; total[2] = 0; total[3] = 0; }
    virtual void reset() {}
};
struct ShotStats {
    int pad; StatGroup g[5]; int w[4]; float avg[24]; int tail[2];
    ShotStats()
    {
        float z = g_ts4_event_value;
        avg[0] = z; avg[1] = z; avg[2] = z; avg[3] = z; avg[4] = z; avg[5] = z; avg[6] = z; avg[7] = z;
        avg[8] = z; avg[9] = z; avg[10] = z; avg[11] = z; avg[12] = z; avg[13] = z; avg[14] = z; avg[15] = z;
        avg[16] = z; avg[17] = 1.0f; avg[18] = z; avg[19] = z; avg[20] = z; avg[21] = z; avg[22] = z; avg[23] = z;
        w[0] = 0; w[1] = 0; w[2] = 0; w[3] = 0;
        tail[0] = 0; tail[1] = 0;
    }
};
ShotStats *make_stats(void *p); ShotStats g_force_ctor_use;
