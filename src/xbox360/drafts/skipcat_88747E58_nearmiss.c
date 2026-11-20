/* Near miss, 4 instructions: store order. The target stores 3c, 40, 114, 11c, then
 * `std` 0 to +0x118 (an 8-byte zero overlapping the word at +0x11c). The best of
 * all 120 statement orders still puts one store early, so the layout is probably a
 * C++ member init list or sub-object rather than this union.
 * Check: python3 tools/fn_check.py <this> ts4_init_88747E58=0x88747E58 --flags /Oc */
extern void fn_88222D28(void *);
extern void fn_88744C70(void *);
typedef struct TS4Obj88747E58 {
    char p0[0x3c]; int a; int b;
    char p1[0x114 - 0x44]; int c;
    union { __int64 q; struct { int hi; int lo; } w; } u;
    char tail[1];
} TS4Obj88747E58;
TS4Obj88747E58 *ts4_init_88747E58(TS4Obj88747E58 *o)
{
    fn_88222D28(o);
    o->b = -1; o->c = 0; o->a = -1; o->u.w.lo = 0; o->u.q = 0;
    fn_88744C70(o->tail);
    return o;
}
