/* nearmiss (q5s 2026-11-24): 2 off; addi r3,r1,0x50 must precede first zero store; tried C++ Rng member+LocalTime ctor, t.Fill(), =T(), ={0,...}, pads 0-8 */
/* NEAR MISS 0x886176F0 (2 instructions off on plain /Oc and LTCG, work/army/ME/v.py chk, matching-b129):
 * seed the random generator from the local clock. Zeroes an 8-int local time record, fills it through
 * ts4_call_seq_fn_88582018_88885388 (which widens a SYSTEMTIME-like set of u16 fields into ints:
 * year, month, day_of_week, day, hour, minute, second, ms), then sets rng->lcg = second * minute and
 * rng->x = ms (the Rng layout used by ts4_rng_range_inclusive_8860BAB8).
 * Residue: target computes `addi r3,r1,0x50` before the first zero store; every candidate puts the store first.
 * Tried: field stores, inline init (by pointer, returning pointer), C++ ctor, two quad inits, memset,
 * 0-8 operand-order pads, reordered stores (worse). */
typedef struct Ts4LocalTime { int year, month, day_of_week, day, hour, minute, second, ms; } Ts4LocalTime;
typedef struct Rng { int seed; int x; int lcg; } Rng;
void ts4_call_seq_fn_88582018_88885388(Ts4LocalTime *t);
void fn_886176F0(Rng *r)
{
    Ts4LocalTime t;
    t.year = 0; t.month = 0; t.day_of_week = 0; t.day = 0; t.hour = 0; t.minute = 0; t.second = 0; t.ms = 0;
    ts4_call_seq_fn_88582018_88885388(&t);
    r->lcg = t.minute * t.second;
    r->x = t.ms;
}
