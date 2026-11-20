/* Swing_DLL.xex 0x8866EFA0: is the frame counter inside [stamp - before, stamp + after] (-1 = open side). */
typedef struct MeFrameSrc { char pad[0x310]; int now; } MeFrameSrc;
typedef struct MeMatch { char pad[0x30]; MeFrameSrc *t; } MeMatch;
typedef struct MeStamp { int v; } MeStamp;
typedef struct MeWindow { MeStamp *pv; MeMatch *m; } MeWindow;
static __inline unsigned char me_stamp_invalid(int v) { return v == 0x7fffffff || v < 0; }
unsigned char ts4_stamp_in_window_8866EFA0(MeWindow *s, int before, int after)
{
    int v = s->pv->v;
    int now;
    int r;
    if (me_stamp_invalid(v))
        return 0;
    now = s->m->t->now;
    if ((before != -1 && now < v - before) || (after != -1 && now > v + after))
        r = 0;
    else
        r = 1;
    return (unsigned char)r;
}
