/* NEAR MISS 0x883EEFA0 (fn_883EEFA0), /Oc: 2 off, the target moves the result (mr r3,r11) before the cursor store; ours after. Statement order and a next-pointer local tried (agU 2026-11-19, work/army/ME/v.py chk, matching-b154). */
typedef struct { int a; unsigned size; char *base; char *cur; } S;
char *ts4_take_from_pool_883EEFA0(S *s, int n) { char *r = 0; if (n) { char *end = s->base + s->size; char *cur = s->cur; if (cur < end) { char *nx = cur + n; if (nx <= end) { r = cur; s->cur = nx; } } } return r; }
