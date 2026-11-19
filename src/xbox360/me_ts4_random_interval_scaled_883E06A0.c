/* 0x883E06A0: picks a value in the [lo, hi) halfword range at +0x34/+0x36 (lo when equal, 0 when both are zero) and scales it by the clock reading / 1000 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns 0 when the clock call fails. */
typedef struct Svc { char pad[0x14]; void *clock; } Svc;
extern Svc *lbl_88CAC988;
typedef struct T { char pad[0x34]; unsigned short lo, hi; } T;
int ts4_crt_rand_88564110(void);
int ts4_if_call_seq_fn_88309DB8_88308B60(void *clock, int *out, int a, int b, int c, int d, int e);
int ts4_random_interval_scaled_883E06A0(T *t)
{
    int v, ms;
    if (!t->lo && !t->hi) return 0;
    if (t->lo == t->hi)
        v = t->lo;
    else
        v = ts4_crt_rand_88564110() % (t->hi - t->lo) + t->lo;
    if (ts4_if_call_seq_fn_88309DB8_88308B60(lbl_88CAC988->clock, &ms, 0, 0, 0, 0, 0)) return 0;
    return ms / 1000 * v;
}
