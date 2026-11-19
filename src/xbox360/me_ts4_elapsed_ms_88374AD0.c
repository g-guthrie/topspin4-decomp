/* 0x88374AD0: reads a tick count and stores rate * ticks / 1000 into *out; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x4a4]; unsigned rate; } Cfg;
typedef struct { char p[0x30]; Cfg *cfg; } O;
void ts4_call_seq_fn_8857B830_8831A8B8(unsigned *t);
int ts4_elapsed_ms_88374AD0(Base *b, unsigned *out) { unsigned t; unsigned rate; O *o = b ? (O *)((char *)b - 0x1c) : 0; t = 0; rate = o->cfg->rate; ts4_call_seq_fn_8857B830_8831A8B8(&t); *out = rate * t / 1000; return 0; }
