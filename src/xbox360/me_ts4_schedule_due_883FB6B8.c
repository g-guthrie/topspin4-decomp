/* 0x883FB6B8: reads the current 64-bit stamp (as an int pair) and the rate from the service at +8, returning their errors */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); stores due (+0x88) = now + (s64)(delay * lbl_88028BDC * rate + lbl_88001978). */
extern const float lbl_88028BDC;
extern const float lbl_88001978;
typedef union Stamp { struct { int a, b; } p; __int64 v; } Stamp;
typedef struct T { int f0, f4; void *svc; char pad[0x88 - 0xc]; __int64 due; } T;
int ts4_if_call_seq_fn_88309DB8_883095F8(void *svc, int *a, int *b);
int ts4_if_call_seq_fn_88309DB8_88308B60(void *svc, int *rate, int a, int b, int c, int d, int e);
int ts4_schedule_due_883FB6B8(T *t, unsigned __int64 delay)
{
    Stamp now;
    int rate;
    float d;
    int r = ts4_if_call_seq_fn_88309DB8_883095F8(t->svc, &now.p.a, &now.p.b);
    if (r)
        return r;
    r = ts4_if_call_seq_fn_88309DB8_88308B60(t->svc, &rate, 0, 0, 0, 0, 0);
    if (r)
        return r;
    d = (float)delay * lbl_88028BDC;
    t->due = now.v + (__int64)(d * (float)rate + lbl_88001978);
    return 0;
}
