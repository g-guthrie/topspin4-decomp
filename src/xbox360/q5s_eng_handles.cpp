/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex): handle/reference getters returned by hidden pointer (q5s eng).
 * Route: LTCG (/Oc), context src/xbox360/pp1_pool_primer.c. Spec: work/specs/Q5S/q5s_eng_handles.json.
 *
 * Each return type is a small class with a constructor, so cl returns it through the hidden r3 pointer
 * and runs the constructor stores first.
 */
typedef unsigned char u8;
typedef unsigned int u32;

/* ---- 0x8860A488: resolve a key through the source's provider (vtable slot 15, +0x3C) ---- */

struct Ts4Ref {
    u32 v;
    Ts4Ref() : v(0) {}
};

struct Ts4RefSource;

struct Ts4RefProvider {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void Resolve(const Ts4RefSource *src, u32 key, Ts4Ref *out) = 0;   /* slot 15 (+0x3C) */
};

struct Ts4RefSource {
    Ts4RefProvider *prov;                          /* +0x00 */
    u32 f4;
    u32 f8;
    u32 key;                                       /* +0x0C */
};

/* Swing_DLL.xex 0x8860A488 */
extern "C" Ts4Ref ts4_resolve_ref_via_provider_8860A488(const Ts4RefSource *src)
{
    Ts4Ref r;
    src->prov->Resolve(src, src->key, &r);
    return r;
}

/* ---- 0x8860B368 / 0x88611148: {owner sub-object, id[idx], 0} handle ---- */

/* u32 vector view {begin, end}. size() must read end into a local before begin: that gives the target's
 * load order (end first) and the clrrwi copy of begin used by the later begin[i]. */
struct Ts4IdVec {
    u32 *begin;
    u32 *end;
    u32 size() const { u32 *e = end; u32 *b = begin; return e - b; }
    const u32 &at(u32 i) const { return begin[i]; }
};

struct Ts4IdHandle {
    u8 *obj;                                       /* +0x00 */
    u32 id;                                        /* +0x04 0xFFFFF = none */
    u32 x;                                         /* +0x08 */
    Ts4IdHandle() { obj = 0; x = 0; id = 0xFFFFF; }
};

struct Ts4IdSourceA {
    u32 f0;
    u8 *owner;                                     /* +0x04 */
    Ts4IdVec ids;                                  /* +0x08 */
};

/* Swing_DLL.xex 0x8860B368: handle to owner+0x60 with ids[idx] (id stays 0xFFFFF when out of range). */
extern "C" Ts4IdHandle ts4_make_id_handle_8860B368(const Ts4IdSourceA *s, u32 idx)
{
    Ts4IdHandle h;
    if (s->owner != 0) {
        h.obj = s->owner + 0x60;
        if (idx < s->ids.size())
            h.id = s->ids.at(idx);
    }
    return h;
}

struct Ts4IdSourceB {
    u32 f0;
    u8 *owner;                                     /* +0x04 */
    u8 pad8[0xc];
    Ts4IdVec ids;                                  /* +0x14 */
};

/* Swing_DLL.xex 0x88611148: same as 0x8860B368 for owner+0x58 and ids at +0x14. */
extern "C" Ts4IdHandle ts4_make_id_handle_88611148(const Ts4IdSourceB *s, u32 idx)
{
    Ts4IdHandle h;
    if (s->owner != 0) {
        h.obj = s->owner + 0x58;
        if (idx < s->ids.size())
            h.id = s->ids.at(idx);
    }
    return h;
}
