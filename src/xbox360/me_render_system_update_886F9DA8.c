/* 0x886F9DA8: per-frame update of a render system. Items at +0x94 are updated through vt slot 0x74 and removed
 * (cleanup + erase) when the update returns 0 and the item is not flagged done; 0x90-byte entries at +0x80 are ticked
 * through vt slot 0x78 while active, otherwise their resource refcount is dropped and the entry erased. */
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Item { char pad[0x3c]; u8 done; } Item;
typedef struct Res { char pad[0x40]; int refs; char pad2[0xc]; u32 h50; } Res;
typedef struct Ent { char pad[0x78]; u8 active; char p79[3]; Res *res; char pad2[0x10]; } Ent;
typedef struct { Item **first; Item **last; } PVec;
typedef struct { Ent *first; Ent *last; } EVec;
struct Sys;
typedef struct SysVt { void *s[29]; int (*update)(struct Sys *, Item *, float); void (*tick)(struct Sys *, Ent *, u32, float); } SysVt;
typedef struct Sys { SysVt *vt; char pad[0x7c]; EVec ents; char pad2[0xc]; PVec items; } Sys;
void ts4_tsu_cleanup_end(void *object);
void *fn_88562DC0(void *d, const void *s, u32 n);
Ent *fn_8823E898(Ent *first, Ent *last, Ent *dest);
static void perase(PVec *v, Item **p, Item **n) { if (n != v->last) fn_88562DC0(p, n, (char *)v->last - (char *)n); v->last--; }
static void eerase(EVec *v, Ent *p, Ent *n) { if (n != v->last) fn_8823E898(n, v->last, p); v->last--; }
void fn_886F9DA8(Sys *o, float dt)
{
  {Item **it = o->items.first; Item **n;
  if (it != o->items.last) {
    n = it + 1;
    do {
      Item *p = *it; u8 rem = 0;
      if (o->vt->update(o, p, dt) == 0 && p->done == 0) {
        rem = 1; ts4_tsu_cleanup_end(p); perase(&o->items, it, n);
      }
      if (!rem) { n++; it++; }
    } while (it != o->items.last);
  }
  }
  {Ent *e = o->ents.first, *en;
  if (e != o->ents.last) {
    en = e + 1;
    do {
      Res *r = en[-1].res;
      if (en[-1].active) { o->vt->tick(o, e, r->h50, dt); e++; en++; }
      else { r->refs--; eerase(&o->ents, e, en); }
    } while (e != o->ents.last);
  }}
}
