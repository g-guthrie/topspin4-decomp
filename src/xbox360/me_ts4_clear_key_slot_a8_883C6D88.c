/* 0x883C6D88: clears the slot holding key in the table at +0xa8; returns 0x25 when absent */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { int n; int a; } T;
typedef struct { char p[0xa8]; T *t; } S;
int ts4_clear_key_slot_a8_883C6D88(S *s, unsigned key) { T *t = s->t; unsigned *a = (unsigned *)t->a; int i; if (t->a) { for (i = 0; i < t->n; i++) { if (a[i] == key) { a[i] = 0; return 0; } } } return 0x25; }
