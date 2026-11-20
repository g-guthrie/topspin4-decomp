// SM2: null-guarded virtual calls through a member object pointer (C++ so the compiler emits its
// zero-extended `this` for virtual dispatch). Slots follow the vtable byte offsets / 4.
struct Ts4VObj {
    virtual int v0(int a);
    virtual int v1();
    virtual int v2();
    virtual int v3(int a, int b);
    virtual int v4(int a, int b);
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
};

struct Ts4VObjV {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

#define VCALL_VOID(NAME, OFF, CALL) \
    struct NAME##_holder { char pad[OFF]; Ts4VObj *m; }; \
    extern "C" void NAME(NAME##_holder *h) \
    { \
        if (h->m) h->m->CALL; \
    }
#define VCALL_VOIDV(NAME, OFF, CALL) \
    struct NAME##_holder { char pad[OFF]; Ts4VObjV *m; }; \
    extern "C" void NAME(NAME##_holder *h) \
    { \
        if (h->m) h->m->CALL; \
    }

VCALL_VOID(ts4_vcall_obj_slot11_88463598, 0x10, v11())
VCALL_VOID(ts4_vcall_obj_slot12_884635C0, 0x10, v12())
VCALL_VOID(ts4_vcall_obj_slot13_884635E8, 0x10, v13())
VCALL_VOID(ts4_vcall_obj_slot5_884C9208, 0x18, v5())

struct ts4_vcall_holder_884C91E0 { char pad[0x18]; Ts4VObj *m; };
extern "C" int ts4_vcall_obj_slot3_or_zero_884C91E0(ts4_vcall_holder_884C91E0 *h)
{
    if (h->m) return h->m->v3(0, 0);
    return 0;
}
