/* 0x885E7660: returns the first index after k (up to n) whose word is not -1, or n + 1 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { int *a; int x; int n; } S;
int ts4_next_not_free_885E7660(S *s, int k) { int i; for (i = k + 1; i <= s->n; i++) if (s->a[i] != -1) return i; return i; }
