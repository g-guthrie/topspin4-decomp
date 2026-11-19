
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Pair { u32 key; int idx; } Pair;
typedef struct BoneVec { struct Bone *begin; struct Bone *end; } BoneVec;
typedef struct Bone { u8 pad[0x1c]; u8 has_children; u8 pad1d[0x1f]; BoneVec children; u8 pad44[0x48]; } Bone;
typedef struct PairVec { Pair *begin; Pair *end; } PairVec;
typedef struct Skel { PairVec map; u8 pad8[0x18]; Bone *bones; } Skel;
typedef struct Mgr { u8 pad[0x18]; Skel *skel; } Mgr;
typedef struct IntVec { int *begin; int *end; u32 pad; int *cap; } IntVec;
typedef struct Node { const char *name; } Node;
extern Mgr *lbl_88D45AD4;
u32 fn_88608590(int seed, const char *s);
int *cw3_find_int_881655A0(int *first, int *last, const int *val);
void ts4_vector_grow_append_scalar4_8816DD48(IntVec *v, int *where, const int *val);
void fn_88733D98(Bone *b, void *ctx);
static int bone_index(Skel *sk, u32 h) {
  PairVec *mp = &sk->map; Pair *p;
  for (p = mp->begin; p != mp->end; p++) if (p->key == h) break;
  if (p != mp->end) return p->idx;
  return -1;
}
void skel_collect_bone(Node *n, IntVec *out, void *ctx){
  Mgr *m = lbl_88D45AD4;
  int v = bone_index(m->skel, fn_88608590(0, n->name));
  int id = v;
  Bone *b; int *e;
  if (v == -1) return;
  e = out->end;
  if (cw3_find_int_881655A0(out->begin, e, &id) != e) return;
  if (e != out->cap) { if (e) *e = v; out->end++; }
  else ts4_vector_grow_append_scalar4_8816DD48(out, e, &id);
  b = &m->skel->bones[v];
  if (b->has_children) {
    BoneVec *c = &b->children; u32 i;
    for (i = 0; i < (u32)(c->end - c->begin); i++) fn_88733D98(&c->begin[i], ctx);
  } else fn_88733D98(b, ctx);
}
