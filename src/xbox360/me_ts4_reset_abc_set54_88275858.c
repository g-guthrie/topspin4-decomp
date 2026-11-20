/* 0x88275858: clears +0x44, sets +0x54 to 1 and sets the floats at +0x40/+0x3c/+0x38 to g_ts4_event_value */
/* Matched on /Oc LTCG route only (+ pp1_pool_primer.c; plain reloads the global for each store). */
extern float g_ts4_event_value;
typedef struct { char p[0x38]; float a, b, c; int n; char q[0xc]; int m; } S;
void ts4_reset_abc_set54_88275858(S *s) { float z; s->n = 0; s->m = 1; z = g_ts4_event_value; s->c = z; s->b = z; s->a = z; }
