/* 0x887EC1A8: resolve a 14-bit slot handle to the matching entry (by slot key) in the slot object's self-relative 0x28-byte table; returns a one-word ref by hidden pointer. Matched /Oc .cpp (agBJ). */
struct Ent { char p[0x24]; unsigned key; };
struct Arr { int rel; int n; };
struct Src { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
  virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
  virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
  virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
  virtual Arr *get(int); };
struct Inner { char p[8]; Src *src; };
struct Obj { char p[0xc]; Inner *in; };
struct Slot { unsigned handle; unsigned key; Obj *obj; int pad[2]; };
struct Vec { Slot *begin; Slot *end; };
struct T { char p[0x30]; Vec slots; };
struct Mgr { char p[0x20]; T *t; };
struct Ref { Ent *e; Ref(Ent *x) : e(x) {} };
extern "C" unsigned char fn_887E9D78(T *t, unsigned int h, unsigned char mode);
extern "C" Ref fn_887EC1A8(Mgr *m, unsigned h)
{
    T *t = m->t;
    if (fn_887E9D78(t, h, 1) == 1) {
        Slot *s = &t->slots.begin[h & 0x3fff];
        Inner *in = s->obj->in;
        if (in) {
            Arr *a = in->src->get(0);
            Ent *found = 0;
            int i;
            for (i = 0; i < a->n; i++) {
                Ent *e = (Ent *)((char *)a + a->rel) + i;
                if (e->key == s->key) { found = e; break; }
            }
            return Ref(found);
        }
    }
    return Ref(0);
}
