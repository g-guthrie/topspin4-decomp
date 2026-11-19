/* 0x883345E8: clears the flag byte of the 8-byte entry whose key matches; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { unsigned char on; char p[3]; unsigned key; } E;
typedef struct { char p[0x130]; int n; } Cfg;
typedef struct { int a, b; E *e; Cfg *cfg; } S;
int ts4_clear_entry_flag_883345E8(S *s, unsigned key) { E *e = s->e; int i; if (e) { for (i = 0; i < s->cfg->n; i++) { if (e[i].key == key) { e[i].on = 0; return 0; } } } return 0; }
