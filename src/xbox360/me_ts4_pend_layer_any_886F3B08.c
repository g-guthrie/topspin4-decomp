/* Swing_DLL.xex 0x886F3B08: true when the layer has anything pending, by mode. */
typedef struct Ts4PendA { char pad[0xc]; unsigned char busy; } Ts4PendA;
typedef struct Ts4PendB { char pad[0x3a]; unsigned char busy; } Ts4PendB;
typedef struct Ts4PendC { char pad[0x3c]; unsigned char queued; char p3d[7]; unsigned char f0, f1, f2; } Ts4PendC;
typedef struct Ts4PendLayer { char pad[0x54]; int mode; char p58[8]; Ts4PendA *a; Ts4PendB *b; Ts4PendC *c; } Ts4PendLayer;
static __inline unsigned char ts4_pend_c_any(Ts4PendC *c) { return c->f0 || c->f1 || c->f2 || c->queued; }
unsigned char ts4_pend_layer_any_886F3B08(Ts4PendLayer *l)
{
    if (l->mode == 1)
        return l->b->busy || ts4_pend_c_any(l->c);
    return l->b->busy || l->a->busy;
}
