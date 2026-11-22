/* Q5 equivalent tier: gameplay service lookups (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * These pass tools/fn_equiv.py; they are not byte matches (see the per-function notes). */
#include "ga3_types.h"
typedef unsigned int u32;

/* Null 12-byte handle {0, 0xFFFFF, 0} passed by value to the hash find. */
typedef struct Q5Handle12 { u32 node, offset, extra; } Q5Handle12;
typedef struct Q5Service Q5Service;
typedef struct Q5ServiceVt {
    void *s00[19];
    Q5Service *(*resolve)(Q5Service *self, u32 arg); /* +0x4c */
} Q5ServiceVt;
struct Q5Service { Q5ServiceVt *vt; };
/* Hash-table record: the lazily created service is at +0x0c. */
typedef struct Q5ServiceRec { u32 w00, w04, w08; Q5Service *service; /* +0x0c */ } Q5ServiceRec;
typedef struct Q5GameCtx { char p000[0x2bc]; void *factory; /* +0x2bc */ } Q5GameCtx;
extern void *lbl_88D458F0;
extern Q5GameCtx *lbl_88D45B1C;
extern Q5ServiceRec *ts4_hash_find_881AB900(void *table, struct Ga3Id hash, Q5Handle12 h);
/* Creates rec->service when it is still null (the callee re-checks +0x0c itself). */
extern void fn_8892F038(Q5ServiceRec *rec, u32 a, void *factory, u32 b, u32 c, u32 d);

/* 0x888EC548: find record 0x9B6E0EFE in the global table, create its service if needed, and return the
 * service's resolve(0) (virtual slot +0x4c), or 0 when there is still no service.
 * Near miss (32 off): the target keeps the zero of the handle in r30 and reuses it for `return 0`;
 * no C or C++ form found (shared zero local, result local, ternary, inline lookup, C++ handle ctor).
 * perm_auto: 1503 candidates, no gain. */
Q5Service *ts4_get_service_9b6e0efe_888EC548(void)
{
    struct Ga3Id id;
    Q5Handle12 h;
    Q5ServiceRec *rec;
    id.value = 0x9B6E0EFEu;
    h.node = 0;
    h.offset = 0xFFFFF;
    h.extra = 0;
    rec = ts4_hash_find_881AB900(lbl_88D458F0, id, h);
    if (!rec->service)
        fn_8892F038(rec, 0, lbl_88D45B1C->factory, 0, 0, 0);
    if (rec->service)
        return rec->service->vt->resolve(rec->service, 0);
    return 0;
}
