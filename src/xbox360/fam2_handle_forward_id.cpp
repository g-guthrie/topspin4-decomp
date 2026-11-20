/* Family FAM2: handle forwarder written as a C++ virtual call (Swing_DLL.xex 0x88611560).
   Initialises the result to the null handle {0, 0xFFFFF, 0} and unconditionally asks the source's
   object (virtual slot 4, vtable +0x10) to fill it, passing the source handle and its id.
   The member-call form is needed for the vtable to be loaded before the id argument. */
typedef unsigned int u32;
struct Ts4HandleObj;
struct Ts4HandleRefCpp { Ts4HandleObj *obj; u32 id; u32 extra; };
struct Ts4HandleObj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void resolve(Ts4HandleRefCpp *src, u32 id, Ts4HandleRefCpp *out);
};
extern "C" Ts4HandleRefCpp *ts4_handle_forward_id_88611560(Ts4HandleRefCpp *out, Ts4HandleRefCpp *src);
extern "C" Ts4HandleRefCpp *ts4_handle_forward_id_88611560(Ts4HandleRefCpp *out, Ts4HandleRefCpp *src)
{
    out->obj = 0;
    out->extra = 0;
    out->id = 0xFFFFF;
    src->obj->resolve(src, src->id, out);
    return out;
}
