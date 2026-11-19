/* 0x8834C9B0: passes (p, 0, 0x4000, +0xd8 of the outer object) to the callee; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0xd8]; int v; } O;
void fn_8832EDB0(void *p, int a, int b, int c);
int ts4_post_d8_8834C9B0(Base *b, void *p) { O *o = b ? (O *)((char *)b - 0x1c) : 0; fn_8832EDB0(p, 0, 0x4000, o->v); return 0; }
