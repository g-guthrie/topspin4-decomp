/* Swing_DLL.xex 0x8859D240-0x8859D2C8, executable version 0.0.0.3. */
typedef unsigned int u32;

typedef struct Ts4Iface {
    void **vtbl;
} Ts4Iface;

typedef struct Ts4Locked {
    char pad[0x2c];
    Ts4Iface lock;
} Ts4Locked;

typedef struct Ts4Query {
    char pad0[8];
    u32 wide;
    char pad1[0x28];
    Ts4Locked *locked;
    char pad2[0x58];
    Ts4Iface *service;
} Ts4Query;

typedef void (*Ts4LockFn)(Ts4Iface *);
typedef u32 (*Ts4QueryFn)(Ts4Iface *, u32);

/* Take the lock of the owned object, ask the service for a value (0x800 when the wide flag is set,
   0x400 otherwise), release the lock and return the value. */
u32 ts4_locked_query_8859D240(Ts4Query *o)
{
    u32 r;
    ((Ts4LockFn)o->locked->lock.vtbl[2])(&o->locked->lock);
    r = ((Ts4QueryFn)o->service->vtbl[0x34 / 4])(o->service, o->wide ? 0x800 : 0x400);
    ((Ts4LockFn)o->locked->lock.vtbl[5])(&o->locked->lock);
    return r;
}
