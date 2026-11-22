/* Q5h3 equivalent tier: gameplay service lookups (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * This function passes tools/fn_equiv.py; it is not a byte match (see the notes on the function). */
#include "ga3_types.h"
typedef unsigned int u32;

/* Null 12-byte handle {0, 0xFFFFF, 0} passed by value to the hash find. */
typedef struct Q5h3Handle12 { u32 node, offset, extra; } Q5h3Handle12;
typedef struct Q5h3Service Q5h3Service;
typedef struct Q5h3ServiceVt {
    void *s00[19];
    Q5h3Service *(*resolve)(Q5h3Service *self, u32 arg); /* +0x4c */
} Q5h3ServiceVt;
struct Q5h3Service { Q5h3ServiceVt *vt; };
/* Hash-table record: the lazily created service is at +0x0c. */
typedef struct Q5h3ServiceRec { u32 w00, w04, w08; Q5h3Service *service; /* +0x0c */ } Q5h3ServiceRec;
typedef struct Q5h3GameCtx { char p000[0x2bc]; void *factory; /* +0x2bc */ } Q5h3GameCtx;
extern void *lbl_88D458F0;
extern Q5h3GameCtx *lbl_88D45B1C;
extern Q5h3ServiceRec *ts4_hash_find_881AB900(void *table, struct Ga3Id hash, Q5h3Handle12 h);
/* Creates rec->service when it is still null (the callee re-checks +0x0c itself). */
extern void fn_8892F038(Q5h3ServiceRec *rec, u32 a, void *factory, u32 b, u32 c, u32 d);

/* 0x888EC5F8: find record 0xAD0C7318 in the global table, create its service if needed, and return the
 * service's resolve(0) (virtual slot +0x4c), or 0 when there is still no service.
 * Same body as 0x888EC548 (the record hash is the only difference in the target code). */
/* byte-gap: 39 off; same body as 0x888EC548 (the record hash is the only difference in the target code) */
Q5h3Service *ts4_get_service_ad0c7318_888EC5F8(void)
{
    struct Ga3Id id;
    Q5h3Handle12 h;
    Q5h3ServiceRec *rec;
    id.value = 0xAD0C7318u;
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
