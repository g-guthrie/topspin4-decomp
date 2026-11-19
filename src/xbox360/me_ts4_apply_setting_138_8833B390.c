/* 0x8833B390: applies the config value (+0x4bc) to the sub-object at +0x138; returns 0x2c on failure */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x4bc]; int v; } Cfg;
typedef struct { int s[1]; } Sub;
typedef struct { char p[0x14]; Cfg *cfg; char q[0x138 - 0x18]; Sub sub; } O;
int fn_88396320(Sub *s, int v);
void fn_88397970(Sub *s);
int ts4_apply_setting_138_8833B390(Base *b) { Sub *s; O *o = b ? (O *)((char *)b - 0x1c) : 0; s = &o->sub; if (fn_88396320(s, o->cfg->v)) return 0x2c; fn_88397970(s); return 0; }
