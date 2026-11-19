/* 0x88483540: Snaps current (+0x20) to target (+0x18) when it is set (not lbl_88001A6C) and within snap (+0x24) of it; returns target if current is unset, else the smaller of current and target. */
/* Matched on /Oc (agAH). Unset sentinel read into a local once; fabs via the intrinsic on double with a float cast. */
extern const float lbl_88001A6C;
double fabs(double);
#pragma intrinsic(fabs)
typedef struct Approach { char pad[0x18]; float target; char pad1c[4]; float current; float snap; } Approach;
float fn_88483540(Approach *a)
{
    float unset = lbl_88001A6C;
    if (a->current != unset && (float)fabs(a->current - a->target) < a->snap)
        a->current = a->target;
    if (a->current == unset)
        return a->target;
    return a->target - a->current >= 0.0f ? a->current : a->target;
}
