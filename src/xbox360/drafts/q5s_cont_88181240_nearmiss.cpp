/* nearmiss: 4 off (scheduling at +0x44: mr r10,r3 / lfs f0 issued after the stores); blocker: tool limit, the kept dead store needs a volatile cast, which pins store order. Caller fk5_001.c (C) needs extern "C". */
#include "include/ts4/ts4.h"
#ifdef _MSC_VER
inline void *operator new(unsigned int, void *p) { return p; }
#else
#include <new>
#endif
extern "C" const float lbl_8814B440;
struct EvPayload {
    unsigned int name_hash; int target; int arg_a; int arg_b; int arg_c; float value;
    EvPayload() { *(volatile int *)&target = 0; name_hash = 0; target = 0; arg_a = 0; arg_b = 0; arg_c = 0; value = lbl_8814B440; }
};
struct EvRef { unsigned int size; EvPayload *payload; };
struct EvPair { int first; int second; };
struct Event {
    unsigned int name_hash; /* +0x00 */
    EvRef data;             /* +0x04 */
    EvPair extra;           /* +0x0C */
    int f14;                /* +0x14 */
    unsigned char f18;      /* +0x18 */
    Event(unsigned int h, EvRef d, EvPair e) : name_hash(h), data(d), extra(e), f14(0), f18(0) {}
};
struct EvQueue { char pad[0x2c]; void *heap; };
extern "C" void *ts4_node_dispatch_8860DCF8(void *heap, unsigned int size, unsigned int align, unsigned int flags);
extern "C" Event *ts4_event_alloc_88181240(EvQueue *q, unsigned int name_hash, EvPair extra)
{
    char *mem = (char *)ts4_node_dispatch_8860DCF8(q->heap, sizeof(EvPayload) + sizeof(Event), 4, 2);
    EvPayload *p = new (mem) EvPayload;
    EvRef r;
    r.size = sizeof(EvPayload);
    r.payload = p;
    return new (mem + sizeof(EvPayload)) Event(name_hash, r, extra);
}
