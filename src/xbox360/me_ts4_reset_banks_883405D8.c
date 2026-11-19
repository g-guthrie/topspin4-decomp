/* 0x883405D8: Resets each of the owner count 0x1403C-byte banks (ts4_call_seq_ts4_memset_883403E0) and points each bank sink at the owner sink area (+0x138). Returns 0. */
/* Matched on /Oc (agAH). Plain loop. */
typedef struct Owner Owner;
typedef struct Bank { char data[0x14034]; void *sink; int pad; } Bank;
struct Owner { char p0[0x138]; char sink[0xc148 - 0x138]; Bank *banks; int pad; int count; };
extern void ts4_call_seq_ts4_memset_883403E0(Bank *b);
int fn_883405D8(Owner *o)
{
    int i;
    if (o->banks != 0) {
        for (i = 0; i < o->count; i++) {
            ts4_call_seq_ts4_memset_883403E0(&o->banks[i]);
            o->banks[i].sink = o->sink;
        }
    }
    return 0;
}
