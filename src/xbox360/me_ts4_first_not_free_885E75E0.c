/* 0x885E75E0: returns the first index (0..n) whose word is not -1, or n + 1 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { int *a; int x; int n; } S;
int ts4_first_not_free_885E75E0(S *s) { int i; for (i = 0; i <= s->n; i++) if (s->a[i] != -1) return i; return i; }
