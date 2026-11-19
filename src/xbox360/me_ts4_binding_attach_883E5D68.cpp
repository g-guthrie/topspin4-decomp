/* 0x883E5D68: Stores source (+0x10), sink (+0xc) and owner (+8) in the binding, sets sink->owner, then calls the sink virtual at slot 3 with source->param; returns 0. */
/* Matched on /Oc /Os (agAH). C++ (/Os): a virtual call loads the vtable slot before the argument; the C function-pointer form and /Oc are 2-4 off. The function itself is a free extern "C" function. */
struct Source { int unk0; void *param; };
class Sink {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Attach(void *param);
    int unk4;
    void *owner;
};
struct Binding { char pad[8]; void *owner; Sink *sink; Source *source; };
extern "C" int fn_883E5D68(Binding *b, void *owner, Source *source, Sink *sink)
{
    b->source = source;
    b->sink = sink;
    b->owner = owner;
    sink->owner = owner;
    b->sink->Attach(b->source->param);
    return 0;
}
