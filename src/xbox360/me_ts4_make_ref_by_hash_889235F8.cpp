/* 0x889235F8: build a 3-word reference {handle, offset, owner} for a caller-supplied hashed id. The handle comes from
 * the owner's service (owner+0x34, vtable slot 15) looked up by that id; offset = p - owner->base (owner+0x24). */
struct Hash { unsigned v; Hash(unsigned x) : v(x) {} };
struct Svc { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual int lookup(const Hash &); };
struct Owner { char pad[0x24]; int base; char pad2[0xc]; Svc *svc; };
struct Ref { int h; int off; Owner *o; };
extern "C" Ref *fn_889235F8(Ref *r, Owner *o, int p, unsigned id)
{
    int off = p - o->base;
    r->h = o->svc->lookup(Hash(id));
    r->off = off;
    r->o = o;
    return r;
}
