extern const float g_ts4_script_constants[];
extern const float g_ts4_event_value;

struct W7bW { float acc; int n; };

/* Swing_DLL.xex 0x889C0C28: wrap accumulator by period, count whole periods */
void ts4_wrap_count_889C0C28(struct W7bW *w)
{
    float v = w->acc;
    int n = 0;
    float p = g_ts4_script_constants[56];
    float sum = g_ts4_event_value;
    while (v >= p) { v -= p; n++; sum += p; }
    w->n = n;
    w->acc = sum;
}

struct W7bS {
    char pad[0x10];
    unsigned w10;
    char pad2[0x28 - 0x14];
    float arr[4];
    char pad3[0x48 - 0x38];
    unsigned w48, w4c, w50, w54, w58, w5c;
    unsigned char b60;
};

/* Swing_DLL.xex 0x886C6508: clear state, fill the four-float array with the event value */
void ts4_reset_state_886C6508(struct W7bS *s)
{
    float *p;
    s->w48 = 0; s->w4c = 0; s->w54 = 0; s->w50 = 0; s->b60 = 0; s->w58 = 0; s->w5c = 0;
    for (p = &s->arr[0]; p != &s->arr[4]; p++) *p = g_ts4_event_value;
    s->w10 = 0;
}
