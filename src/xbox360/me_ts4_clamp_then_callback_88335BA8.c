/* 0x88335BA8: clamps x to [lbl_880038E0, lbl_88028DFC] and passes it to the callback at s+0xbc (with s+0x1c); 0x19 when there is none */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
extern const float lbl_880038E0, lbl_88028DFC;
typedef struct { char pad[0xbc]; int (*cb)(void *, float); } S;
typedef struct { char pad[0x44]; S *s; } O;
int ts4_clamp_then_callback_88335BA8(O *o, float x)
{
    S *s;
    if (x < lbl_880038E0) x = lbl_880038E0;
    else if (x > lbl_88028DFC) x = lbl_88028DFC;
    s = o->s;
    if (s) { int (*cb)(void *, float) = s->cb; if (cb) return cb((char *)s + 0x1c, x); }
    return 0x19;
}
