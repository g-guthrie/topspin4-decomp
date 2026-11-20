/* 0x888ED7E0 near miss (agBF, 1 missing instruction): if every item in the vector at +0x54 is ready, fetch service
 * 0x9C70EAF3, refresh (fn_88866F10, fn_888EBB08), set its +0x15c flag, and switch the global lbl_88D45910 into
 * mode 2 by clearing four 3-byte pairs and +0xe7. Returns 1 when not all ready.
 * Remaining diff: the target stores the pair "on" bytes from `clrlwi r9,r31,24` (a truncated copy of the zero it keeps in
 * r31) and the "val" bytes from r31 directly; every form tried here stores r31 for both. */

typedef unsigned int u32; typedef unsigned char u8;
typedef struct { char pad[4]; u8 ready; } Item;
typedef struct { char pad[0x54]; Item **first, **last; } O;
typedef struct { char pad[0x15c]; u8 b15c; } Svc;
typedef struct { u8 on, val, pad; } P3;
static void p3_set(P3 *p, u8 on) { p->on = on; p->val = 0; }
typedef struct { char pad[0xb4]; P3 a, b, c, d; char p[0xdc-0xc0]; u8 bdc; char p2[0xe7-0xdd]; u8 be7; } G;
extern G *lbl_88D45910;
extern Svc *ts4_find_service(u32 id);
extern void fn_88866F10(void);
extern void fn_888EBB08(Svc *s);
static u8 all_ready(O *o) {
    u8 r = 1;
    Item **e = o->last, **it;
    for (it = o->first; it != e; it++) if (!(*it)->ready) { r = 0; break; }
    return r;
}
u8 ts4_items_ready_enter_mode2_888ED7E0(O *o) {
    u8 ok = all_ready(o);
    if (ok == 1) {
        Svc *s = ts4_find_service(0x9C70EAF3);
        G *g;
        fn_88866F10();
        fn_888EBB08(s);
        s->b15c = 1;
        g = lbl_88D45910;
        if (g->bdc != 2) {
            g->bdc = 2;
            p3_set(&g->a, 0); p3_set(&g->b, 0); p3_set(&g->c, 0); p3_set(&g->d, 0); g->be7 = 0;
        }
    }
    return ok == 0;
}
