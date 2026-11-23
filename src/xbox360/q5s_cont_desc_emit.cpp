/* q5s_cont: fill a {size, hash, value} descriptor and pass it to virtual slot 0x48 (LTCG route, /Oc).
 * Called from gameplay (e.g. 886A84C0); the descriptor's meaning is not identified yet, so names stay generic.
 * The tag argument must be a one-member struct by value: a plain unsigned int changes register allocation. */
#include "include/ts4/ts4.h"

struct DescTag {
    unsigned int v;
};
static inline DescTag desc_tag(unsigned int v)
{
    DescTag t;
    t.v = v;
    return t;
}
struct Desc {
    unsigned int size;
    unsigned int hash;
    unsigned int value;
};
struct DescSource {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void emit(Desc *d, DescTag tag); /* +0x48 */
    virtual unsigned int value();             /* +0x4C */
};

extern "C" void ts4_desc_emit_88172D50(DescSource *self, Desc *d)
{
    d->size = 0x10;
    d->value = self->value();
    d->hash = 0xAD8438E7;
    self->emit(d, desc_tag(0));
}

extern "C" void ts4_desc_emit_88172DC8(DescSource *self, Desc *d, bool flag)
{
    d->size = 0x14;
    d->value = self->value();
    d->hash = 0x0D7D6E3F;
    if (flag)
        self->emit(d, desc_tag(0xDEC70121));
    self->emit(d, desc_tag(0));
}

extern "C" void ts4_desc_emit_88172EE8(DescSource *self, Desc *d)
{
    d->size = 0x18;
    d->value = self->value();
    d->hash = 0x8AB953A9;
    self->emit(d, desc_tag(0));
}

extern "C" void ts4_desc_emit_88172E58(DescSource *self, Desc *d, bool flag)
{
    d->size = 0x14;
    d->value = self->value();
    d->hash = 0xA6A78ACF;
    if (flag)
        self->emit(d, desc_tag(0xDEC70121));
    self->emit(d, desc_tag(0));
}
