/* 0x88179AF0: build a 3-word reference {handle, offset, owner}. The handle comes from the owner's service (owner+0x34, vtable slot 15) looked up by the hashed id 0x25FCD125; offset = p - owner->base (owner+0x24).
 * Matched on plain /Oc and LTCG routes (work/army/ME/v.py chk, matching-b129). */
struct Hash { unsigned v; Hash(unsigned x) : v(x) {} };
struct Svc { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual int lookup(const Hash &); };
struct Owner { char pad[0x24]; int base; char pad2[0xc]; Svc *svc; };
struct Ref { int h; int off; Owner *o; };
extern "C" Ref *fn_88179AF0(Ref *r, Owner *o, int p)
{
    int off = p - o->base;
    r->h = o->svc->lookup(Hash(0x25FCD125));
    r->off = off;
    r->o = o;
    return r;
}
