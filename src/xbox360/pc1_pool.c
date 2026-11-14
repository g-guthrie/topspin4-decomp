/* PC1: functions (default /O2 /Oi) that read the script float-constant pool g_ts4_script_constants.
 *
 * The pool is declared per translation unit as a static const array: this is the only form that
 * reproduces the original `addi rX, REFLO pool; lfs fN, disp(rX)` access pattern (an extern
 * declaration does not).  The relocation still resolves to g_ts4_script_constants.
 * Source: Swing_DLL.xex.
 */
static const float g_ts4_script_constants[668] = {1.0f};

/* Float constant 0.0f (lbl_8814B440 in the original image). */
extern float lbl_8814B440;
/* Seconds-per-tick style scale factor (lbl_88D459B0). */
extern float lbl_88D459B0;

/* ---- pure math ---- */

/* Swing_DLL.xex 0x881A4518: integer power by squaring, x^n (n may be negative; 1.0f is pool[0]). */
float ts4_powi_881A4518(void *unused, int n, float x)
{
    unsigned m;
    float r;
    float one = g_ts4_script_constants[0];
    (void)unused;
    if (n >= 0)
        m = n;
    else
        m = -n;
    r = one;
    for (;;) {
        if (m & 1)
            r *= x;
        m >>= 1;
        if (!m)
            break;
        x *= x;
    }
    if (n < 0)
        r = one / r;
    return r;
}

/* ---- virtual-call helpers ---- */

typedef struct Ts4VCall Ts4VCall;
typedef struct Ts4VCallVT {
    void *pad[24];
    float (*get_a)(Ts4VCall *self, float t);
    float (*get_b)(Ts4VCall *self, float t);
} Ts4VCallVT;
struct Ts4VCall {
    Ts4VCallVT *vt;
    char pad[0x44];
    float t;
};

/* Swing_DLL.xex 0x8820DBB0: difference of two virtual curve queries at the same t; negative results are scaled by pool[14]. */
float ts4_curve_delta_scaled_8820DBB0(Ts4VCall *self)
{
    float a = self->vt->get_a(self, self->t);
    float b = self->vt->get_b(self, self->t);
    if (b - a < lbl_8814B440)
        return (b - a) * g_ts4_script_constants[14];
    return b - a;
}

/* ---- predicates using a global manager object (virtual slot 0x5c) ---- */

typedef struct Ts4Mgr Ts4Mgr;
typedef struct Ts4MgrVT {
    void *pad[23];
    unsigned char (*query)(Ts4Mgr *self, int handle);
} Ts4MgrVT;
struct Ts4Mgr {
    Ts4MgrVT *vt;
};
extern Ts4Mgr *lbl_88D41F80;
typedef struct Ts4Handle { char pad[0x10]; int id; } Ts4Handle;

typedef struct Ts4UnitA {
    char pad0[0x1c];
    float scale;
    char pad1[0x34 - 0x20];
    int handle;
} Ts4UnitA;
typedef struct Ts4UnitB {
    char pad0[0x1c];
    float scale;
    char pad1[0x44 - 0x20];
    int handle;
} Ts4UnitB;

/* Swing_DLL.xex 0x8820FAA8: true if the manager flags the +0x34 handle, else if scale != pool[0] (1.0f). */
unsigned char ts4_unit_a_flagged_or_scaled_8820FAA8(Ts4UnitA *self)
{
    return (self->handle && lbl_88D41F80->vt->query(lbl_88D41F80, ((Ts4Handle *)(unsigned long)self->handle)->id)) || self->scale != g_ts4_script_constants[0];
}

/* Swing_DLL.xex 0x88210128: same as above for the handle at +0x44. */
unsigned char ts4_unit_b_flagged_or_scaled_88210128(Ts4UnitB *self)
{
    return (self->handle && lbl_88D41F80->vt->query(lbl_88D41F80, ((Ts4Handle *)(unsigned long)self->handle)->id)) || self->scale != g_ts4_script_constants[0];
}

/* ---- timer ---- */

typedef struct Ts4Stopwatch {
    long long start;
    long long accumulated;
    int running;
} Ts4Stopwatch;
extern double fn_8856B2C0(long long ticks);
extern void fn_8857AFF0(long long *out_now);

/* Swing_DLL.xex 0x88193B60: elapsed time of a stopwatch (accumulated + now - start while running) in scaled units. */
float ts4_stopwatch_elapsed_scaled_88193B60(Ts4Stopwatch *self)
{
    long long t = self->accumulated;
    if (self->running != 0) {
        long long now;
        fn_8857AFF0(&now);
        t += now - self->start;
    }
    return g_ts4_script_constants[15] * ((float)fn_8856B2C0(t) * lbl_88D459B0);
}

/* ---- accumulator ---- */

extern struct Ts4FrameClock {
    char pad[0x80];
    float delta;
} *lbl_88D41FC4;

typedef struct Ts4Ramp {
    char pad0[0x7c];
    int decreasing;
    float rate;
    float value;
    char pad1[0x8d - 0x88];
    unsigned char active;
    char pad2[0x98 - 0x8e];
    unsigned char clamped;
    char pad3[0x9c - 0x99];
    float lower;
    float upper;
} Ts4Ramp;

/* Swing_DLL.xex 0x88205448: while active, ramp value up/down by frame delta * rate * pool[87]; optionally clamp to [lower, upper]. */
void ts4_ramp_update_88205448(Ts4Ramp *self)
{
    float step;
    if (self->active != 1)
        return;
    step = lbl_88D41FC4->delta * self->rate * g_ts4_script_constants[87];
    if (self->decreasing == 0) {
        float v = self->value + step;
        self->value = v;
        if (self->clamped && v > self->upper)
            self->value = self->upper;
    } else {
        float v = self->value - step;
        self->value = v;
        if (self->clamped && v < self->lower)
            self->value = self->lower;
    }
}

/* ---- indexed weight sum ---- */

typedef struct Ts4WeightTable {
    char pad[0x14];
    float *values;
} Ts4WeightTable;

typedef struct Ts4WeightRecord {
    int index_offset;
    int count;
    int unused;
    int dest;
} Ts4WeightRecord;

/* Swing_DLL.xex 0x881794E0: sum values[idx[i]] over a record's index list; if any value is negative
 * the result becomes pool[14], then the result is stored at values[record->dest]. */
void ts4_sum_indexed_weights_881794E0(Ts4WeightTable *self, int *record_ref)
{
    Ts4WeightRecord *rec = (Ts4WeightRecord *)((char *)record_ref + *record_ref);
    float zero = lbl_8814B440;
    float sum = zero;
    unsigned char bad = 0;
    int i = 0;
    int n = rec->count;
    int dst = rec->dest;
    for (; i < n; i++) {
        float v = self->values[((int *)((char *)rec + rec->index_offset))[i]];
        if (v < zero) {
            bad = 1;
            break;
        }
        if (i == 0)
            sum = v;
        else
            sum = v + sum;
    }
    if (bad)
        sum = g_ts4_script_constants[14];
    self->values[dst] = sum;
}
