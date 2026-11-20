/* 0x883E5900: shifts a timed voice by (t - clock.now): while playing (88317910 == 0), repositions the handle (88317138 with the 64-bit position split into words) to start+delta when start is in the future, else to ticks(n/rate) + t - elapsed; adds delta to start/end (+0x18/+0x20) and re-forwards (88316FB0) when still playing. */
/* Near miss /O1 plain and LTCG (agX): 2 off, both 64-bit 'x += d' adds come out add rX,rX,d where the target has add rX,d,rX (operand order; += , d + x, pointer-local and helper forms tried). */
typedef unsigned long long u64;
typedef struct Clock Clock;
typedef struct ClockVt { void *f0[6]; u64 (*now)(Clock *c); void *f7[4]; u64 (*ticks)(Clock *c, float secs); } ClockVt;
struct Clock { ClockVt *vt; };
typedef struct S S;
typedef struct SVt { void *f0[10]; int (*rate)(S *s, float *out); } SVt;
struct S { SVt *vt; int p4; Clock *clk; int pc; void *h; int p14; u64 start; u64 end; };
typedef union Tmp { u64 v; float f; int w[2]; } Tmp;
int ts4_if_call_seq_fn_88322CA8_88317910(void *h, void *out);
int ts4_if_call_seq_fn_88322CA8_88317138(void *h, int a, int hi, int lo);
int ts4_if_call_seq_fn_88322CA8_88317370(void *h, unsigned int *out, int kind);
int ts4_lookup_then_forward_88316FB0(void *p, int x);

static unsigned char playing(void *h, Tmp *tmp)
{
    return !h ? 0 : ts4_if_call_seq_fn_88322CA8_88317910(h, tmp) == 0;
}

int fn_883E5900(S *s, u64 t)
{
    u64 d = t - s->clk->vt->now(s->clk);
    Tmp tmp;
    unsigned int n;
    int r;
    if (playing(s->h, &tmp)) {
        u64 start = s->start;
        if (start > s->clk->vt->now(s->clk)) {
            tmp.v = start + d;
            r = ts4_if_call_seq_fn_88322CA8_88317138(s->h, 1, tmp.w[0], tmp.w[1]);
            if (r)
                return r;
        } else {
            Tmp p;
            u64 el = s->clk->vt->now(s->clk) - s->start;
            r = s->vt->rate(s, &tmp.f);
            if (r)
                return r;
            r = ts4_if_call_seq_fn_88322CA8_88317370(s->h, &n, 2);
            if (r)
                return r;
            p.v = s->clk->vt->ticks(s->clk, (float)n / tmp.f) + (t - el);
            r = ts4_if_call_seq_fn_88322CA8_88317138(s->h, 1, p.w[0], p.w[1]);
            if (r)
                return r;
        }
    }
    s->end += d;
    s->start += d;
    if (playing(s->h, &tmp)) {
        r = ts4_lookup_then_forward_88316FB0(s->h, 0);
        if (r)
            return r;
    }
    return 0;
}
