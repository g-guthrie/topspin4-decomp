/* Look up an entry by id (resolving id 0 through the sorted lookup), then forward the argument to its handler. */

typedef unsigned char u8; typedef unsigned int u32;
typedef struct { u32 id; u32 w4; void *p8; } Ent;
typedef struct { char p[0x44]; Ent **first; Ent **last; } Obj;
typedef struct { u32 w0; u32 w4; } Arg;
u8 ts4_sorted_lookup_88657BF0(Obj *o, u32 v, u32 *out);
u8 fn_88655C90(void *p, Arg *a);
static Ent *entry_find(Obj *o, u32 id)
{
  Ent **end = o->last;
  Ent **it;
  for (it = o->first; it != end; it++)
    if ((*it)->id == id) return *it;
  return 0;
}
u8 ts4_keyed_entry_dispatch_88657C70(Obj *o, Arg *a, u32 id)
{
  Ent *e;
  u32 k = id;
  if (k == 0 && !ts4_sorted_lookup_88657BF0(o, a->w4, &k)) return 0;
  e = entry_find(o, k);
  if (!e) return 0;
  return fn_88655C90(e->p8, a);
}
