/* 0x88879280: dispatch an event payload by kind. Kind 5 goes to vtable slot 0x20, kind 2 to slot
   0x24, kind 7 is ignored, every other kind up to 8 goes to slot 0x28; larger kinds are ignored. */
typedef unsigned int u32;
typedef struct EvPayload { u32 pad[3]; u32 kind; } EvPayload;
typedef struct EvMsg { u32 pad[6]; EvPayload *payload; } EvMsg;
struct EvHandler;
typedef struct EvHandlerVt { void *s[8];
    void (*on_kind5)(struct EvHandler *, EvPayload *);
    void (*on_kind2)(struct EvHandler *, EvPayload *);
    void (*on_other)(struct EvHandler *, EvPayload *); } EvHandlerVt;
typedef struct EvHandler { EvHandlerVt *vt; } EvHandler;
void ts4_ev_dispatch_kind_88879280(EvHandler *h, EvMsg *m)
{
    EvPayload *p = m->payload;
    if (!p)
        return;
    switch (p->kind) {
    case 5: h->vt->on_kind5(h, p); break;
    case 2: h->vt->on_kind2(h, p); break;
    case 7: break;
    case 0: case 1: case 3: case 4: case 6: case 8: h->vt->on_other(h, p); break;
    }
}
