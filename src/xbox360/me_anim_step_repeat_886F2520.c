
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Clip { u8 pad[0x50]; u32 id; float len; u8 pad58[0x18]; float t0; float t1; } Clip;
typedef struct Anim { u8 pad[0x30]; float f30; u8 pad34[0xc]; int n40; u32 id44; u8 pad48[8]; Clip *clip; } Anim;
struct Obj;
typedef struct ObjVt { void *m[0x21]; u8 (*step)(struct Obj *o, Anim *a); } ObjVt;
typedef struct Obj { ObjVt *vt; } Obj;
extern const float g_ts4_event_value;
extern const float g_ts4_script_constants[];
void anim_step_repeat(Obj *o, Anim *a){
  Clip *c = a->clip;
  int n, i; float zero = g_ts4_event_value;
  if (!(c->len > zero)) return;
  if (c->id != 0xC55579FD && a->id44 == 0x171D6FBB) {
    float d, ratio, inv; int r;
    if ((float)a->n40 >= c->len) return;
    d = c->t1 - c->t0;
    ratio = d / c->len;
    if (d == zero) inv = g_ts4_script_constants[0]; else inv = c->len / d;
    r = (int)ratio; if (r <= 1) r = 1;
    if ((int)a->f30 % r != 0) return;
    n = (int)inv; if (n <= 1) n = 1;
  } else {
    n = (int)c->len;
  }
  if (n > 0) { i = 0;
  do { if (!o->vt->step(o, a)) break; } while (++i < n); }
}
