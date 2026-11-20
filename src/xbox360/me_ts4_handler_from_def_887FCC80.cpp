/* 0x887FCC80: create a handler from a definition record (name hash dispatch), init it with the owner entry matching the def key, then add every self-relative 8-byte pair value. Matched /Oc .cpp (agBJ). */
struct Ent { char p[0x24]; unsigned key; };
struct Tab { int rel; int n; };
struct Desc { char p[0xc]; Tab tab; };
struct Owner { char p[0x2c]; Desc *desc; };
struct Pair { int a; void *v; };
struct Def { int rel; int n; int x8; unsigned key; unsigned name; char args[1]; };
struct H { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
  virtual void init(void *args, unsigned key, int idx, Owner *o, void *x, Ent *e); virtual void add(void *v); };
extern "C" unsigned int ts4_dispatch_by_name_hash_887FC940(unsigned int hash);
static Ent *find(Tab *t, unsigned key)
{
    Ent *r = 0;
    int i;
    for (i = 0; i < t->n; i++) {
        Ent *e = (Ent *)((char *)t + t->rel) + i;
        if (e->key == key) { r = e; break; }
    }
    return r;
}
extern "C" H *fn_887FCC80(Owner *o, Def *d)
{
    unsigned name = d->name;
    unsigned key = d->key;
    void *args = d->args;
    H *h = (H *)ts4_dispatch_by_name_hash_887FC940(name);
    int i, n;
    Ent *e = find(&o->desc->tab, key);
    h->init(args, key, -1, o, 0, e);
    n = d->n;
    for (i = 0; i < n; i++)
        h->add(((Pair *)((char *)d + d->rel))[i].v);
    return h;
}
