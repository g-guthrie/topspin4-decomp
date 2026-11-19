/* 0x8836F980: returns 0x2d when any of the pointers at +0x164/+0x16c/+0x174 is set, else 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x164]; void *a; int q; void *b; int r; void *c; } O;
int ts4_busy_code_2d_8836F980(Base *b) { O *o = b ? (O *)((char *)b - 0x1c) : 0; if (o->a) return 0x2d; if (o->b) return 0x2d; return o->c ? 0x2d : 0; }
