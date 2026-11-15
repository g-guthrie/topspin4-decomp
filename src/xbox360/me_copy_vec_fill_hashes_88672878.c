/* 0x88672878 (hand match). */
#include "vx1_vector.h"
typedef unsigned int u32;
typedef struct Item { u32 a; u32 hash; } Item;
typedef struct Ent { int rel; int count; char pad[8]; } Ent;
typedef struct Hdr { int rel; } Hdr;
typedef struct D74 { char p[0x8e0]; __vector4 v8e0; char q[0x9a0-0x8f0]; __vector4 v9a0; char r[0x9fc-0x9b0]; u32 f9fc; } D74;
typedef struct C4c { char p[0x2c]; int f2c; } C4c;
typedef struct B8 { char p[0x4c]; C4c *f4c; char q[0x74-0x50]; D74 *f74; } B8;
typedef struct T28 { char p[0x98]; Hdr h; } T28;
typedef struct A1c { char p[8]; B8 *f8; char q[0x28-0xc]; T28 *f28; } A1c;
typedef struct Self { char p[0x1c]; A1c *f1c; } Self;
void ts4_copy_vec_fill_hashes_88672878(Self *s){ int op1_pad0 = 0, op1_pad1 = 0, op1_pad2 = 0, op1_pad3 = 0; /* dead locals: fix operand order (OP1) */ u32 n, i; int j; s->f1c->f8->f74->v9a0 = s->f1c->f8->f74->v8e0;
 s->f1c->f8->f74->f9fc = 0x8999a0bfu;
 n = (s->f1c->f8->f4c->f2c == 2) ? 2 : 1; for (i = 0; i != n; i++) { Hdr *h = &s->f1c->f28->h; Ent *e = (Ent *)((char *)h + (i * 16 + h->rel)); int c = e->count; for (j = 0; j < c; j++) { Item *it = (Item *)((char *)((Item *)e + j) + e->rel); it->hash = 0x968230b3u; } } }
