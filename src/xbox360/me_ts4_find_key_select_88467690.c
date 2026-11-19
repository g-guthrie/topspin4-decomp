/* 0x88467690: finds the entry with key in the table at +0x30 and selects it */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { unsigned short key; char p[6]; } E;
typedef struct { char p[2]; unsigned char n; char q[3]; E e[1]; } Sub;
typedef struct { char p[0x30]; Sub sub; } S;
void fn_88532E50(Sub *s, int i);
void ts4_find_key_select_88467690(S *s, unsigned short key) { int i; for (i = 0; i < s->sub.n; i++) if (s->sub.e[i].key == key) { fn_88532E50(&s->sub, i); return; } }
