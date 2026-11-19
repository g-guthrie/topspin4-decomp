/* Swing_DLL.xex 0x886F1798 / 0x886F1810 / 0x886F1888: return the resource id of one of a layer's bound sources
   (via its virtual getter), or the empty id {0, 0xFFFFF, 0} when the slot is unbound. */
struct Ts4ResId {
    int a; int id; int b;
    Ts4ResId() { a = 0; b = 0; id = 0xFFFFF; }
};
struct Ts4IdSrc {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual Ts4ResId get_id();
};
struct Ts4IdLayer {
    char pad[0x10];
    Ts4IdSrc *src_b;   /* +0x10 */
    char pad14[4];
    Ts4IdSrc *src_a;   /* +0x18 */
    char pad1c[4];
    Ts4IdSrc *src_c;   /* +0x20 */
};
/* C++ only for the by-value Ts4ResId (non-trivial constructor); extern "C" keeps the config names. */
#pragma warning(disable: 4190)
extern "C" Ts4ResId ts4_layer_src_a_id_886F1798(Ts4IdLayer *l) { Ts4IdSrc *s = l->src_a; if (s) return s->get_id(); Ts4ResId r; return r; }
extern "C" Ts4ResId ts4_layer_src_b_id_886F1810(Ts4IdLayer *l) { Ts4IdSrc *s = l->src_b; if (s) return s->get_id(); Ts4ResId r; return r; }
extern "C" Ts4ResId ts4_layer_src_c_id_886F1888(Ts4IdLayer *l) { Ts4IdSrc *s = l->src_c; if (s) return s->get_id(); Ts4ResId r; return r; }
