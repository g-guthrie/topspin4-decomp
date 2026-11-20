/* 888C72E8 near miss (1 off, plain and LTCG): loads 0x24 then 0x18 match, but cmplw operands come out r11,r10 (target r10,r11). */
typedef unsigned char u8; typedef struct { char p[0x18]; void *a; void *b; void *c; void *d; } S;
static int eq(void*a,void*d){return a==d;} u8 fn_888C72E8(S *s){ return s->b!=0 || eq(s->a,s->d); }
