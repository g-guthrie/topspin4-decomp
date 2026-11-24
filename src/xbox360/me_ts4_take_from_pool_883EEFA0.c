/* 0x883EEFA0: bump-allocates n bytes from the pool (+8 base, +4 size, +0xc cursor); returns 0 when full or n is 0 */
/* Matched on /Os plain and LTCG (work/army/ME/v.py chk). */
typedef struct { int a; unsigned size; char *base; char *cur; } S;
char *ts4_take_from_pool_883EEFA0(S *s, int n) { char *r = 0; if (n) { char *end = s->base + s->size; char *cur = s->cur; if (cur < end) { char *nx = cur + n; if (nx <= end) { r = cur; s->cur = nx; } } } return r; }
