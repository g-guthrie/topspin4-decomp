/* 0x8834DDE0: sets (on) or clears the byte flag at +0x110 of the outer object; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x110]; unsigned char flag; } O;
int ts4_set_flag_110_8834DDE0(Base *b, unsigned on) { O *o = b ? (O *)((char *)b - 0x1c) : 0; if (on) { if (!o->flag) o->flag = 1; } else o->flag = 0; return 0; }
