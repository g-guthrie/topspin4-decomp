/* Swing_DLL.xex 0x883E1DD0: re-arms the root of t's parent chain (+0x54) and then each child timer in the root's list (+0x78, node
 * at timer+4) with ts4_timer_chain_rearm_883E1CE0, stopping at the first error. agAE: /O1. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Timer { void *vt; Link link; char padc[0x54 - 0xc]; struct Timer *parent; char pad58[0x78 - 0x58]; Link children; } Timer;
int ts4_timer_chain_rearm_883E1CE0(Timer *t);
#define LINK_TIMER(l) ((l) ? (Timer *)((char *)(l) - 4) : 0)
static __inline Timer *timer_root(Timer *t) { Timer *p = t->parent; if (!p) return t; while (p->parent) p = p->parent; return p; }
int fn_883E1DD0(Timer *t)
{
    Timer *root = timer_root(t);
    Link *l;
    int hr = ts4_timer_chain_rearm_883E1CE0(root);
    if (hr) return hr;
    for (l = root->children.next; l != &root->children; l = l->next) {
        hr = ts4_timer_chain_rearm_883E1CE0(LINK_TIMER(l));
        if (hr) return hr;
    }
    return 0;
}
