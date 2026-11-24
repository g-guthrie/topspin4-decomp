/*
 * 0x888907A0 (pres): constructor of the shared handle object with vtable 0x880DCE3C (base vtable 0x88089574,
 * whose store is dead and removed). Base ctor sets the reference count at +6 to 1; the derived ctor sets the
 * byte at +0xC and acquires a handle from the manager service (g+0x224, slot 10) with (a, 1, 0). The handle
 * comes back by value (sret) and is a class with its own zeroing ctor, which is what places the `id = 0`
 * store. Only caller: 88189B60 (unmatched). Records of this class are released by 0x88890CB0.
 * Matches only as a real C++ class (a C body with a hand-written vtable store is 15 off; a by-value handle in C
 * is 5 off). LTCG route, decorated name ??0Ts4SharedHandle880DCE3C@@QAA@I@Z.
 */
typedef unsigned int u32;

struct Ts4WorldHandleId {
    u32 id;
    Ts4WorldHandleId() : id(0) {}
};

struct Ts4WorldHandleService {
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual Ts4WorldHandleId Acquire(u32 a, u32 b, u32 c); /* slot 10 (+0x28) V 888907A0 */
};

struct Ts4WorldHandleRegistry {
    char pad_000[0x224];
    Ts4WorldHandleService *service;              /* +0x224 V 888907A0 */
};
extern "C" Ts4WorldHandleRegistry *lbl_88D45B1C;

struct Ts4SharedBase88089574 {
    short shared;                                /* +0x04 */
    short refs;                                  /* +0x06 V 888907A0 88890CB0 */
    Ts4SharedBase88089574() { refs = 1; }
    virtual ~Ts4SharedBase88089574();
};

struct Ts4SharedHandle880DCE3C : Ts4SharedBase88089574 {
    Ts4WorldHandleId handle;                     /* +0x08 V 888907A0 */
    unsigned char active;                        /* +0x0C V 888907A0 */
    Ts4SharedHandle880DCE3C(u32 a);
    virtual ~Ts4SharedHandle880DCE3C();
};

Ts4SharedHandle880DCE3C::Ts4SharedHandle880DCE3C(u32 a)
{
    active = 1;
    handle = lbl_88D45B1C->service->Acquire(a, 1, 0);
}
