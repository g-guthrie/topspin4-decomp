/* NEAR MISS (13 instructions): game keeps constant[0] in f0 across the stores but loads it after d0;
 * a local 'one' hoists lis above the o->r load, a global read reloads it. Tried __restrict, const, helpers. */
/* 0x886C4540: refreshes a rate block's reciprocals: inverse of each of four durations (the second
 * scaled by script constant 14 instead of 1). */
typedef struct Rates { float inv0, inv1, inv2, inv3; char p[0x14 - 0x10]; float d0; float d2; float d1; float d3; } Rates;
typedef struct Owner { char p[0x18]; Rates *r; } Owner;
extern float g_ts4_script_constants[];
void f(Owner *o)
{
    Rates *r = o->r;
    r->inv0 = g_ts4_script_constants[0] / r->d0;
    r->inv1 = g_ts4_script_constants[14] / r->d1;
    r->inv2 = g_ts4_script_constants[0] / r->d2;
    r->inv3 = g_ts4_script_constants[0] / r->d3;
}
