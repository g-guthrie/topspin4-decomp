/* 0x886CDED0: binds three xdata views of the court handle: type 0x7300948E -> +0x5FC (size 1), 0xF73023FB ->
   +0x5F8 (size 4), 0xFC6B3509 -> +0x600 via fn_88923458 (size 0x10). Matched in C++: the getter is a real virtual
   (slot 10) called through a member of the ref, which keeps each result store ahead of the next ref load
   (the C function-pointer form hoisted the loads; 9 off). */
typedef unsigned int u32;
struct Ts4Handle16 { u32 a, b, c, d; };
struct TS4TripleArg { u32 first, second, third; };
struct Ts4XdataRef;
struct Ts4XdataNode {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void *get(Ts4XdataRef *r, u32 off, int size);
};
struct Ts4XdataRef { Ts4XdataNode *node; u32 offset; u32 extra; void *at(int n) { return node->get(this, offset, n); } };
struct Ts4CourtRes { char p[0x5f8]; void *f5f8; void *f5fc; void *f600; };
extern "C" Ts4XdataRef *ts4_handle_forward_88150770(Ts4XdataRef *out, Ts4Handle16 *handle, u32 *type_hash);
extern "C" TS4TripleArg *ts4_handle_forward_88610A48(TS4TripleArg *out, Ts4Handle16 *handle, u32 *type_hash);
extern "C" void *fn_88923458(void *owner, TS4TripleArg value, unsigned int size);
extern "C" void ts4_court_res_bind(Ts4CourtRes *self, Ts4Handle16 h)
{
    u32 h1, h2, h3;
    Ts4XdataRef r1, r2;
    TS4TripleArg t, *pt, v;
    h1 = 0x7300948Eu;
    ts4_handle_forward_88150770(&r1, &h, &h1);
    h2 = 0xF73023FBu;
    ts4_handle_forward_88150770(&r2, &h, &h2);
    self->f5fc = r1.at(1);
    self->f5f8 = r2.at(4);
    h3 = 0xFC6B3509u;
    pt = ts4_handle_forward_88610A48(&t, &h, &h3);
    v = *pt;
    self->f600 = fn_88923458((void *)v.third, v, 0x10);
}
