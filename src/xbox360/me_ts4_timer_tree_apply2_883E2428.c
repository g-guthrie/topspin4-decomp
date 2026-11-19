/* Swing_DLL.xex 0x883E2428: applies (a, b) to the clock (+0x34) of t and then of each child timer (+0x78 list) via
 * ts4_fetch_then_use_two_floats_88317550; results 0, 0xB and 0x24 are not errors. agAE: /Oc. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Clock Clock;
typedef struct Timer { void *vt; Link link; char padc[0x34 - 0xc]; Clock *clock; char pad38[0x78 - 0x38]; Link children; } Timer;
int ts4_fetch_then_use_two_floats_88317550(Clock *c, float a, float b);
#define LINK_TIMER(l) ((l) ? (Timer *)((char *)(l) - 4) : 0)
int fn_883E2428(Timer *t, float a, float b)
{
    Timer *c = t;
    Timer *n = LINK_TIMER(t->children.next);
    int hr;
    do {
        if (c->clock) {
            hr = ts4_fetch_then_use_two_floats_88317550(c->clock, a, b);
            if (hr != 0x24 && hr != 0xb && hr != 0) return hr;
        }
        c = n;
        n = LINK_TIMER(n->link.next);
    } while (c != LINK_TIMER(&t->children));
    return 0;
}
