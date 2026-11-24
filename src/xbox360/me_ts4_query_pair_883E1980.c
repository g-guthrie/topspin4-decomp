/* 0x883E1980: queries the handle at +0x34 (88317788 flag probe, codes 0x24/0xB treated as success) and, when flagged, reads two words via 88317180(h, 1, &a, &b); stores the 8-byte pair (zero by default) */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif
typedef union Pair { struct { unsigned int a, b; } s; u64 q; } Pair;
typedef struct T { char pad[0x34]; void *h; } T;
int ts4_if_call_seq_fn_88322CA8_88317788(void *h, unsigned char *flag);
int ts4_if_call_seq_fn_88322CA8_88317180(void *h, int which, unsigned int *a, unsigned int *b);
int ts4_query_pair_883E1980(T *t, Pair *out)
{
    Pair p;
    unsigned char flag;
    int r;
    p.q = 0;
    if (t->h) {
        flag = 0;
        r = ts4_if_call_seq_fn_88322CA8_88317788(t->h, &flag);
        if (r == 0x24 || r == 0xb)
            r = 0;
        if (r)
            return r;
        if (flag) {
            r = ts4_if_call_seq_fn_88322CA8_88317180(t->h, 1, &p.s.a, &p.s.b);
            if (r)
                return r;
        }
    }
    *out = p;
    return 0;
}
