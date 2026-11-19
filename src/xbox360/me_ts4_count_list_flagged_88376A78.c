/* 0x88376A78: counts the entries of a circular list and those with the +0x24 flag set; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct N { struct N *next; char p[0x20]; unsigned char on; } N;
int ts4_count_list_flagged_88376A78(N *head, int *total, int *flagged) { int n = 0, m = 0; N *e; for (e = head->next; e != head; e = e->next) { n++; if (e->on) m++; } if (total) *total = n; if (flagged) *flagged = m; return 0; }
