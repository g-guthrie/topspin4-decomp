
typedef struct V V;
typedef struct { void (*f0)(V *); void (*f1)(V *); void (*f2)(V *); } VT;
struct V { const VT *vt; char pad[0x18]; unsigned char b1c; };
typedef struct { char pad[0x278]; int mode; } G;
extern V *lbl_88D45A70, *lbl_88D45A78, *lbl_88D45AE0;
extern G *lbl_88D45B1C;
typedef struct { char pad[0x14]; int a, b, c; } Ring;
typedef struct { char pad[0x150]; Ring ring; } Sub;
typedef struct { char pad[0x1c]; int sub; } O;  /* stored as a signed word; holds a Sub * */
extern void fn_88722EA8(O *o);
extern void fn_88755718(V *v);
extern void ts4_if_call_seq_fn_88734098_8876CE68(Sub *s);
void fn_8876CF38(O *o)
{
  V *p; Ring *r; int v;
  fn_88722EA8(o);
  p = lbl_88D45A70;
  if (p) {
    int m = lbl_88D45B1C->mode;
    if (m == 2 || m == 4) p->vt->f2(p);
    else if (p->b1c) fn_88755718(p);
  }
  r = &((Sub *)o->sub)->ring;
  v = r->a;
  if (v == r->c) v = r->b;
  r->c = v;
  p = lbl_88D45A78;
  if (p) p->vt->f2(p);
  if (o->sub) {
    ((unsigned char *)o->sub)[0x15820] = 0;
    ts4_if_call_seq_fn_88734098_8876CE68((Sub *)o->sub);
  }
  p = lbl_88D45AE0;
  if (p) p->vt->f2(p);
}
