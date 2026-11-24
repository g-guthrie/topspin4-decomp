/* Swing_DLL.xex 0x884937E8-0x884937E8, executable version 0.0.0.3. */
struct Ts4RcCounted {
    virtual void *destroy(int flags);
    unsigned short live;
    short refs;
};
struct Ts4Sec { void *vt; void *pad; void *f8; };
struct Ts4Full : Ts4RcCounted, Ts4Sec { };
extern "C" {
void ts4_clear_pointer_slot_8846B2F8(void *owner, void *pointer);
void ts4_release_thunk_884937E8(Ts4Sec *s)
{
    Ts4Full *b;
    Ts4Sec *back = ((char *)s - 8 != 0) ? s : 0;
    ts4_clear_pointer_slot_8846B2F8(s->f8, back);
    b = (Ts4Full *)((char *)s - 8);
    if (b->live != 0) {
        if (--b->refs == 0)
            b->destroy(1);
    }
}
}
