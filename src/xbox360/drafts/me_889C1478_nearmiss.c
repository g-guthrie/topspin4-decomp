/* agentA2 (2026-11-18 tips pass): not retried: residue is a dropped argument needing fn_889C0FE8 body as LTCG context, none of the three tips apply. Still 8 off. */
/* 0x889C1478 near miss (8 off, /Oc plain and LTCG alike). Ball stepper: convert to local frame (fn_889C1160) then
 * back to world (fn_889C0FE8). Target saves r4 in r30 but never sets r4 for the second call: the original likely passed
 * p to fn_889C0FE8 and LTCG dropped the unused argument, which needs fn_889C0FE8's real body in the context.
 * One-arg second call: 13 off (no r30 save). */
typedef struct Gp4Stepper Gp4Stepper;
typedef struct W8bStep W8bStep;
void fn_889C1160(Gp4Stepper *s, W8bStep *p);
void fn_889C0FE8(Gp4Stepper *s, W8bStep *p);
void ts4_stepper_roundtrip_local(Gp4Stepper *s, W8bStep *p)
{
    fn_889C1160(s, p);
    fn_889C0FE8(s, p);
}
