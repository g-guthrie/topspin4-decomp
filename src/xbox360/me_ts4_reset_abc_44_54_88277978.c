/* 0x88277978: clears +0x54 and +0x44 and sets the floats at +0x40/+0x3c/+0x38 to g_ts4_event_value */
/* Matched on /Oc LTCG route only (+ pp1_pool_primer.c; plain reloads the global for each store). */
extern float g_ts4_event_value;
typedef struct { char p[0x38]; float a, b, c; int n; char q[0xc]; int m; } S;
void ts4_reset_abc_44_54_88277978(S *s) { float z; s->m = 0; s->n = 0; z = g_ts4_event_value; s->c = z; s->b = z; s->a = z; }
