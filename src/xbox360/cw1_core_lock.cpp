/* CW1: scoped virtual-call wrappers (Swing_DLL.xex 0x88151560). */
typedef unsigned int u32;

struct Cw1Guard {
    virtual void slot0();
    virtual void enter();
    virtual void leave();
};

struct Cw1Shared {
    char pad0[8];
    Cw1Guard guard;
};

struct Cw1Owner {
    char pad0[0x1c];
    Cw1Shared *shared;
};

extern "C" void ts4_loop_get_u32_off8_8861DDB0(Cw1Shared *shared, u32 key);

/* Swing_DLL.xex 0x88151560: run the shared object's update under its guard. */
extern "C" void ts4_guarded_update_88151560(Cw1Owner *self, u32 key)
{
    Cw1Guard *guard = &self->shared->guard;
    guard->enter();
    ts4_loop_get_u32_off8_8861DDB0(self->shared, key);
    guard->leave();
}
