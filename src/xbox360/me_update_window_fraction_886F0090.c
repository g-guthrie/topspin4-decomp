
typedef unsigned int u32;
typedef struct Clock { char pad[0xd04]; int now; } Clock;
typedef struct Slot { Clock *clock; u32 a; u32 b; } Slot;
typedef struct O {
    char p0[0x54]; int mode; char p58[0x14]; int *sel; char p70[0x10];
    Slot slots[1]; char p8c[0x10]; int end; int span; char pa4[4]; int window; float frac;
} O;
/* 0x886F0090: time left until o->end on the active clock; if inside the window, store span/(span-left) as the blend fraction */
unsigned char ts4_update_window_fraction_886F0090(O *o)
{
    int t;
    int d;
    unsigned char ok;
    if (o->mode == 1) t = o->slots[*o->sel].clock->now;
    else t = o->slots[0].clock->now;
    d = o->end - t;
    if (d >= 0 && d < o->window) ok = 1; else ok = 0;
    if (ok) o->frac = (float)o->span / (float)(o->span - d);
    return ok;
}
