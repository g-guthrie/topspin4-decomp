/* nearmiss: 16 off (LTCG /Oc), register allocation only (target lo=r6 hi=r7 a=r5 key=r8 mid=r10 e=r11; ours
 * a=r6 lo=r7 hi=r8 key=r5); blocker: tools/perm_auto.py, 72 candidates, then a 386-candidate run (best 16), no improvement; the loop/hoist structure
 * variants tried change size (0x68 vs 0x74). Odds improve with a source-level register-order probe tool. */
#include "../include/ts4/ts4.h"

typedef struct Entry32 { char pad0[0x18]; unsigned int key; char pad1c[4]; } Entry32;

Entry32 *ts4_rel_bsearch32_881518D0(Ts4RelArray *a, const unsigned int *key)
{
    Entry32 *r = 0;
    int lo = 0;
    int hi = a->count - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        Entry32 *e = (Entry32 *)((char *)a + (mid * 32 + a->offset));
        if (e->key == *key) {
            r = e;
            break;
        }
        if (e->key < *key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return r;
}
