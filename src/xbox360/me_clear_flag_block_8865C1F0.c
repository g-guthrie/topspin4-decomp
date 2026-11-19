/* 8865C1F0: clears eleven u8 flags in the flag block at +0x96 of owner->ctx->f44. Plain /Oc. The stores must go through an
 * inline that takes &f->block (a sub-struct address); with the plain pointer the base gets r9/r10 instead of r11. */
typedef unsigned char u8;
typedef struct { u8 a96,a97; char p1[0xcc-0x98]; u8 acc,acd,ace; char p2[0xe5-0xcf]; u8 ae5; char p3[0x160-0xe6]; u8 b160,b161,b162,b163,b164; char p4[0x19a-0x165]; u8 b19a; } Q;
typedef struct { char p0[0x96]; Q q; } F;
typedef struct { char p[0x44]; F *f; } G;
typedef struct { int x; G *g; } S;
static void clrf(Q*f){ f->acc=0; f->acd=0; f->ace=0; f->ae5=0; f->a96=0; f->a97=0; f->b19a=0; f->b160=0; f->b161=0; f->b162=0; f->b164=0; }
void fn_8865C1F0(S *s){ clrf(&s->g->f->q); }
