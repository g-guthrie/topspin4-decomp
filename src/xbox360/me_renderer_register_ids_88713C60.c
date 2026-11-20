
typedef struct { char pad[0xc]; char list[0x10]; unsigned int *first, *last; } Reg;
typedef struct { char pad[0x1c]; Reg *reg; } Ctx;
extern Ctx *lbl_88D45AD4;
typedef struct { char pad[8]; unsigned char active; } Fx;
typedef struct { char pad[8]; Fx *fx; char pad0c[0x24]; int id30, id34; } O;
extern void ts4_ptrvec_add_88223000(void *vec, unsigned int val);
static unsigned char is_new(Ctx *c, int id)
{
  unsigned int *e, *p;
  if (id < 0) return 0;
  e = c->reg->last;
  for (p = c->reg->first; e != p; p++)
    if ((unsigned int)id == *p) return 0;
  return 1;
}
void fn_88713C60(O *o)
{
  Ctx *c = lbl_88D45AD4;
  if (o->fx) o->fx->active = 0;
  if (is_new(c, o->id34)) ts4_ptrvec_add_88223000(c->reg->list, o->id34);
  if (is_new(c, o->id30)) ts4_ptrvec_add_88223000(c->reg->list, o->id30);
}
