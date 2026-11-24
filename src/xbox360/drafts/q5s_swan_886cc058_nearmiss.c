/* STATE (2026-11-23): still 6 off with the recovered class (include/ts4/classes.h: Ts4Tracker, ctor
 * `Ts4Tracker::Ts4Tracker() { f_30 = 0; Reset(); }` with member ctors for a/b and Reset defined in the same TU;
 * decorated ??0Ts4Tracker@@QAA@XZ). Same three swapped scheduling pairs as below. Also tried with the class:
 * Acc ctor body orders, Reset out of line (cl still inlines it under /O2), fn_check_ltcg /Oc. */
/* nearmiss: 6 off (three swapped pairs); concrete blocker: list-scheduling order only. Target issues
 * lis(script_constants) before `li r11,0`, the dead `addi r10,r3,0x44` before `stw a.n`, and the 1.0f load
 * before the f04 store; here each pair is the other way round. All stores, registers and the dead addi
 * (from acc_init(&t->a), DA1) otherwise match. Was 38-48 off (drafts/me_886CC058_nearmiss.c); the inline
 * sub-object helpers for a and b fixed store order. Tried: scale before/after f04, a local for 1.0f (20),
 * literal 1.0f (15), block-local/restrict pointers, base-init helper, vtable order, const/non-const externs,
 * __forceinline, nested clear helper, C++ member ctors (23); perm_auto 320 candidates, nothing below 6.
 * 0x886CC058: tracker constructor: two vtables (+0, +8), clears the accumulators (+0x44, +0x58) and fields,
 * scale (+0x3C) = 1.0f, then the inlined reset clears the +0x44 accumulator again. */
extern const char ts4_vtbl_Q5sTrackerItem880F3798[];
extern const char ts4_vtbl_Ts4TrackerShell880D6B70[];
extern float g_ts4_event_value;
extern const float g_ts4_script_constants[];
typedef struct Accum4 { float v[4]; int n; } Accum4;
typedef struct Tracker {
    const void *vtbl; int f04; const void *vtbl2;
    float f0c[9];
    int f30, f34;
    float f38, scale, f40;
    Accum4 a, b;
    int f6c; float f70; int f74, f78, f7c; unsigned char f80;
} Tracker;
static __inline void acc_init(Accum4 *a) { a->v[0] = g_ts4_event_value; a->n = 0; a->v[1] = g_ts4_event_value; a->v[2] = g_ts4_event_value; a->v[3] = g_ts4_event_value; }
static __inline void acc_init2(Accum4 *a) { a->n = 0; a->v[0] = g_ts4_event_value; a->v[1] = g_ts4_event_value; a->v[2] = g_ts4_event_value; a->v[3] = g_ts4_event_value; }
void ts4_tracker_ctor_886CC058(Tracker *t)
{
    t->vtbl = ts4_vtbl_Q5sTrackerItem880F3798;
    t->vtbl2 = ts4_vtbl_Ts4TrackerShell880D6B70;
    acc_init(&t->a);
    acc_init2(&t->b);
    t->f30 = 0; t->f34 = 0; t->f04 = 0;
    t->scale = g_ts4_script_constants[0];
    t->f38 = g_ts4_event_value; t->f40 = g_ts4_event_value;
    t->f0c[0] = g_ts4_event_value; t->f0c[1] = g_ts4_event_value; t->f0c[2] = g_ts4_event_value; t->f0c[3] = g_ts4_event_value;
    acc_init2(&t->a);
    t->f6c = 0; t->f0c[4] = g_ts4_event_value; t->f74 = 0; t->f0c[5] = g_ts4_event_value; t->f78 = 0; t->f0c[6] = g_ts4_event_value; t->f7c = 0;
    t->f0c[7] = g_ts4_event_value; t->f80 = 0; t->f0c[8] = g_ts4_event_value; t->f70 = g_ts4_event_value;
}
