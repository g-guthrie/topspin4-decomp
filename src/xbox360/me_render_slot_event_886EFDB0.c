
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Ev { u32 pad0; u32 type; u32 id; int idx; u32 pad10[2]; float f18; u32 pad1c[3]; int v28; } Ev;
typedef struct Flag { u32 pad; float f4; u8 on; u8 match; } Flag;
typedef struct Item { u32 pad0; u32 id; u8 pad8[0x8d]; u8 b95; u8 b96; u8 pad97[5]; int v9c; int va0; } Item;
typedef struct Slot { u8 pad[0x18]; Item **begin; Item **end; } Slot;
typedef struct Obj { u8 pad[0x38]; Slot **slots; u8 pad3c[0x18]; Flag *flag; u8 pad58[8]; u8 b60; u8 b61; } Obj;
void render_slot_event(Obj *o, Ev *e){
  if (e->type == 0xA877942E && !o->b61) {
    o->flag->f4 = e->f18;
    o->flag->on = 1;
    o->flag->match = e->id == 0x10CE168B;
  }
  if (e->type == 0x3013A51E) o->b60 = 1;
  if (e->type == 0xCA8D6E99) {
    if (o->b60) {
      Slot *s = o->slots[e->idx]; Item **it = s->begin, **end = s->end;
      for (; it != end; it++) {
        Item *i = *it; i->b95 = 1; i->v9c = e->v28; i->va0 = e->v28;
      }
    }
  } else if (e->type == 0x9C9C0A0B) {
    Slot *s = o->slots[e->idx]; Item **it = s->begin, **end = s->end;
    for (; it != end; it++) {
      Item *i = *it;
      if (e->id == 0x5BE8962F || e->id == i->id) i->b96 = 1;
    }
  }
}
