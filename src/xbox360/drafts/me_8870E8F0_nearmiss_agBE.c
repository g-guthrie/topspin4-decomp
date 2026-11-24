/* 0x8870E8F0 near miss (agBE, b197, /Oc): weighted random pick from a self-relative entry array.
 * 1 instruction short: the target reloads ents.rel (lwz r9,0(r11)) for the end pointer after computing begin;
 * here the compiler CSEs it with the begin load. Everything else matches. */

typedef struct { int data[4]; float weight; } Ent;
typedef struct { int rel; unsigned int count; } RelArr;
typedef struct { char pad[0x60]; RelArr ents; } Set;
typedef struct { char pad[0x14]; Set *set; } O;
typedef struct { char pad[0x228]; char rng[4]; } G;
extern G *lbl_88D45B1C;
extern const float lbl_8814B440;
extern float ts4_rng_range_8861E598(void *rng, float lo, float hi);
static Ent *ra_begin(RelArr *a) { Ent *b = 0; if (a->rel != -1) b = (Ent *)((char *)a + a->rel); return b; }
static Ent *ra_end(RelArr *a) { Ent *e = 0; if (a->rel != -1) e = (Ent *)((char *)a + a->rel) + a->count; return e; }
Ent *fn_8870E8F0(O *o)
{
  Set *s = o->set;
  Ent *b, *e, *p;
  float sum, r, acc, z;
  if (!s || !s->ents.count) return 0;
  if (s->ents.count == 1) return ra_begin(&s->ents);
  b = ra_begin(&s->ents);
  e = ra_end(&s->ents);
  z = lbl_8814B440;
  sum = z;
  for (p = b; p != e; p++) sum += p->weight;
  r = ts4_rng_range_8861E598(lbl_88D45B1C->rng, z, sum);
  acc = z;
  for (p = b; p != e; p++) {
    acc += p->weight;
    if (r <= acc) return p;
  }
  return 0;
}
