/* 0x883E1CE0: when the pending flag 0x200 (+0x24) is set, clears it and, if the timer (+0x34) is busy, re-arms the chain: recurses into +0x1C, reads its due stamp and adds a random interval before restarting the timer */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); errors 0x24 and 0xB from the busy query count as success; the interval is zero-extended, so it is cast to unsigned int. */
typedef union Stamp { struct { int a, b; } p; unsigned __int64 v; } Stamp;
typedef struct C2 { char pad[0xC]; void *rng; } C2;
typedef struct C1 { char pad[0xC]; C2 *c; } C1;
typedef struct T { char pad[0x14]; C1 *cfg; char p18[4]; struct T *next; char p20[4]; unsigned int flags; char p28[0x34 - 0x28]; void *timer; } T;
int ts4_if_call_seq_fn_88322CA8_88317788(void *timer, unsigned char *busy);
int fn_883E1A10(T *t, Stamp *s);
int ts4_random_interval_scaled_883E06A0(void *rng);
int ts4_if_call_seq_fn_88322CA8_88317138(void *timer, int a, int hi, int lo);
int ts4_timer_chain_rearm_883E1CE0(T *t)
{
    int r;
    unsigned char busy;
    Stamp s;
    if (t->flags & 0x200) {
        t->flags &= ~0x200;
        if (t->timer && t->next) {
            r = ts4_if_call_seq_fn_88322CA8_88317788(t->timer, &busy);
            if (r == 0x24 || r == 0xb) r = 0;
            if (r) return r;
            if (busy) {
                r = ts4_timer_chain_rearm_883E1CE0(t->next);
                if (r) return r;
                r = fn_883E1A10(t->next, &s);
                if (r) return r;
                s.v += (unsigned int)ts4_random_interval_scaled_883E06A0(t->cfg->c->rng);
                if (s.v) {
                    r = ts4_if_call_seq_fn_88322CA8_88317138(t->timer, 1, s.p.a, s.p.b);
                    if (r) return r;
                }
            }
        }
    }
    return 0;
}
