/* FAM6 hand matches (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).

   - 0x8827D1F8: a three-way value update. The jump-free compare chain only
     comes out of a real `switch`, and the virtual call needs a C++ object.
   - 0x88999BA8: copies an address record into a stream. MSVC copies a
     one-word struct argument with `clrrwi rX,rY,0`, so the IN_ADDR-style
     value is passed as a struct read from memory, not as a reloaded word. */
typedef unsigned long ts4_word;

extern "C" {
struct ts4_in_addr { ts4_word s_addr; };
ts4_word fn_88939040(ts4_word stream, ts4_word data, ts4_word size);
ts4_word ts4_memset(ts4_word dst, ts4_word value, ts4_word size);
ts4_word ts4_tailcall_NetDll_XNetInAddrToXnAddr_884EFEE8(ts4_in_addr ina, ts4_word xnaddr, ts4_word xnkid);
}

/* Swing_DLL.xex 0x8827D1F8 */
struct ts4_value_owner_8827D1F8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ts4_word limit();
    char pad[0x48];
    ts4_word value;
    ts4_word ts4_apply_value_8827D1F8(ts4_word delta, ts4_word mode);
};
ts4_word ts4_value_owner_8827D1F8::ts4_apply_value_8827D1F8(ts4_word delta, ts4_word mode)
{
    switch (mode) {
    case 0: value += delta; break;
    case 1: value = limit() - delta; break;
    case 2: value = delta; break;
    }
    return value;
}

/* Swing_DLL.xex 0x88999BA8 */
struct ts4_net_peer_88999BA8 {
    ts4_word ts4_write_peer_address_88999BA8(ts4_word stream);
};
ts4_word ts4_net_peer_88999BA8::ts4_write_peer_address_88999BA8(ts4_word stream)
{
    ts4_word self = (ts4_word)this;
    ts4_word xnaddr[10];

    if (((ts4_in_addr *)((char *)self + 8))->s_addr != 0) {
        ts4_tailcall_NetDll_XNetInAddrToXnAddr_884EFEE8(*(ts4_in_addr *)((char *)self + 8), (ts4_word)&xnaddr[0], 0);
    } else {
        ts4_memset((ts4_word)&xnaddr[0], 0, 36);
    }
    fn_88939040(stream, (ts4_word)&xnaddr[0], 36);
    return fn_88939040(stream, self + 6, 2);
}
