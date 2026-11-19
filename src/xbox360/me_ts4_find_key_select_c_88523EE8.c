/* 0x88523EE8: finds the entry with key in the table at +0xc of o and selects it */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { unsigned short key; char p[6]; } E;
typedef struct { char p[2]; unsigned char n; char q[3]; E e[1]; } Sub;
typedef struct { char p[0xc]; Sub sub; } O;
void fn_88532E50(Sub *s, int i);
void ts4_find_key_select_c_88523EE8(void *self, O *o, unsigned short key) { Sub *sub = &o->sub; int i; for (i = 0; i < sub->n; i++) if (sub->e[i].key == key) { fn_88532E50(sub, i); return; } }
