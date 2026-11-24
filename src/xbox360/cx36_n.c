/* CX36: feed every ready child of every sub-vector to its parent (Swing_DLL.xex 0x889326E8, 0x88932798; differ in vtable slot). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Cx36Child { void **vt; } Cx36Child;
typedef struct Cx36CVec { u8 pad[4]; Cx36Child **first; Cx36Child **last; } Cx36CVec;
typedef struct Cx36Mid { u8 pad[0x14]; Cx36CVec *kids; } Cx36Mid;
typedef struct Cx36Par { void **vt; Cx36Mid *mid; } Cx36Par;
typedef struct Cx36PVec { u8 pad[4]; Cx36Par **first; Cx36Par **last; } Cx36PVec;
typedef u8 (*Cx36ReadyFn)(Cx36Child *c);
typedef void (*Cx36FeedFn)(Cx36Par *p, Cx36Child *c);
#define CX36_FEED(ADDR, SLOT) \
void ts4_feed_children_##ADDR(Cx36PVec *v) \
{ \
    Cx36Par **p; \
    Cx36Par **pend = v->last; \
    for (p = v->first; p != pend; p++) { \
        Cx36Par *par = *p; \
        if (par->mid && par->mid->kids) { \
            Cx36Child **c; \
            Cx36Child **cend = par->mid->kids->last; \
            for (c = par->mid->kids->first; c != cend; c++) { \
                Cx36Child *ch = *c; \
                if (((Cx36ReadyFn)ch->vt[6])(ch)) \
                    ((Cx36FeedFn)par->vt[SLOT])(par, ch); \
            } \
        } \
    } \
}
CX36_FEED(889326E8, 11)
CX36_FEED(88932798, 10)
