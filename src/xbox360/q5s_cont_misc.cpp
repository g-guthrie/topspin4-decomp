/* q5s_cont: small engine-core helpers (LTCG route, /Oc). Types: include/ts4/containers.h. */
#include "include/ts4/ts4.h"
#ifdef _MSC_VER
extern "C" int memcmp(const void *, const void *, unsigned int);
#pragma intrinsic(memcmp)
#else
#include <string.h>
#endif

/* std::min returning a reference: the operands are spilled to the stack and the result reloaded. */
template <class T> inline const T &ts4_min(const T &a, const T &b) { return b < a ? b : a; }

/* ---- Three-way compare of two byte ranges (basic_string::compare shape: memcmp of the shorter
 * length, then the lengths decide). The inlined memcmp intrinsic gives the byte loop. ---- */
extern "C" int ts4_range_compare_8816B238(const char *b1, const char *e1, const char *b2, const char *e2)
{
    int len1 = e1 - b1;
    int len2 = e2 - b2;
    int r = memcmp(b1, b2, ts4_min(len1, len2));
    if (r != 0)
        return r;
    if (len1 < len2)
        return -1;
    return len1 > len2;
}

/* ---- Narrow string copy-construct with an explicit string manager: share the source data when it is
 * not locked (refs >= 0) and uses the same manager, otherwise start from the manager's nil string and
 * copy the characters. ---- */
struct Ts4StrMgr {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual Ts4StrHdr *GetNilString(); /* +0x10 */
};
struct Ts4Str;
extern "C" Ts4StrHdr *ts4_if_get_u32_offc_8819B6C0(Ts4StrHdr *h); /* CloneData */
extern "C" void ts4_string_assign_range_8819B448(Ts4Str *self, const char *s, int n);
struct Ts4Str : Ts4String {
    Ts4StrHdr *hdr() const { return (Ts4StrHdr *)data - 1; }
    int length() const { return hdr()->length; }
};

extern "C" Ts4Str *ts4_string_copy_mgr_8819AFC8(Ts4Str *self, const Ts4Str *src, Ts4StrMgr *mgr)
{
    Ts4StrHdr *h = src->hdr();
    if (h->refs >= 0 && h->alloc == mgr) {
        self->data = (char *)(ts4_if_get_u32_offc_8819B6C0(h) + 1);
    } else {
        self->data = (char *)(mgr->GetNilString() + 1);
        ts4_string_assign_range_8819B448(self, src->data, src->length());
    }
    return self;
}

/* ---- {size, hash, value} descriptor sent twice through virtual slot 0x48 (tags 0xDEC70121, then 0);
 * same family as q5s_cont_desc_emit.cpp. The tag must be a one-member struct by value. ---- */
struct DescTag2 {
    unsigned int v;
};
struct Desc2 {
    unsigned int size;
    unsigned int hash;
    unsigned int value;
};
struct DescSource2 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void emit(Desc2 *d, DescTag2 tag); /* +0x48 */
    virtual unsigned int value();               /* +0x4C */
};

extern "C" void ts4_desc_emit_881811A8(DescSource2 *self, Desc2 *d)
{
    d->size = 0x14;
    d->value = self->value();
    d->hash = 0xC6629A55u;
    DescTag2 k1 = {0xDEC70121u};
    self->emit(d, k1);
    DescTag2 k0 = {0};
    self->emit(d, k0);
}
