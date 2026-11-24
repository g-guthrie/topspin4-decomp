/* Swing_DLL.xex 0x884E6480-0x884E7030, executable version 0.0.0.3. */
/* Listener hub: take the owner lock, forward one virtual notification to every
   registered listener, stamp the owner and release the lock. */
extern "C" {
void fn_88472530(void *owner);
void RtlLeaveCriticalSection(void *cs);
}
struct Listener {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void on8(int a, int b, int c, int d);
    virtual void s9(); virtual void s10();
    virtual void on11(int a, int b, int c, int d);
    virtual void s12();
    virtual void on13(int a, int b, int c, int d);
};
struct Owner { char pad[0x20]; long long stamp; };
struct Hub {
    char pad0[8];
    Listener **list;
    int count;
    int pad1;
    Owner *owner;
};
#define BCAST(NAME, SLOT) \
extern "C" void NAME(Hub *self, int a, int b, int c, int d) \
{ \
    int i; \
    Owner *o; \
    fn_88472530(self->owner); \
    for (i = 0; i < self->count; ++i) \
        self->list[i]->SLOT(a, b, c, d); \
    o = self->owner; \
    o->stamp = -1; \
    RtlLeaveCriticalSection(o); \
}
/* Swing_DLL.xex 0x884E6480 */
BCAST(ts4_broadcast_884E6480, on8)
/* Swing_DLL.xex 0x884E6F10 */
BCAST(ts4_broadcast_884E6F10, on11)
/* Swing_DLL.xex 0x884E6FA0 */
BCAST(ts4_broadcast_884E6FA0, on13)

/* Five-argument notifications. */
struct Listener5 {
    virtual void s0();
    virtual void on1(int a, int b, int c, int d, int e);
    virtual void on2(int a, int b, int c, int d, int e);
    virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8();
    virtual void on9(int a, int b, int c, int d, int e);
};
struct Hub5 {
    char pad0[8];
    Listener5 **list;
    int count;
    int pad1;
    Owner *owner;
};
#define BCAST5(NAME, SLOT) \
extern "C" void NAME(Hub5 *self, int a, int b, int c, int d, int e) \
{ \
    int i; \
    Owner *o; \
    fn_88472530(self->owner); \
    for (i = 0; i < self->count; ++i) \
        self->list[i]->SLOT(a, b, c, d, e); \
    o = self->owner; \
    o->stamp = -1; \
    RtlLeaveCriticalSection(o); \
}
/* Swing_DLL.xex 0x884E6070 */
BCAST5(ts4_broadcast5_884E6070, on1)
/* Swing_DLL.xex 0x884E6108 */
BCAST5(ts4_broadcast5_884E6108, on2)
/* Swing_DLL.xex 0x884E6510 */
BCAST5(ts4_broadcast5_884E6510, on9)

/* Notification carrying three floats. */
struct ListenerF {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5();
    virtual void on6(int a, int b, int c, float x, float y, float z, int e);
};
struct HubF {
    char pad0[8];
    ListenerF **list;
    int count;
    int pad1;
    Owner *owner;
};
/* Swing_DLL.xex 0x884E6338 */
extern "C" void ts4_broadcast_floats_884E6338(HubF *self, int a, int b, int c, float x, float y, float z, int e)
{
    int i;
    Owner *o;
    fn_88472530(self->owner);
    for (i = 0; i < self->count; ++i)
        self->list[i]->on6(a, b, c, x, y, z, e);
    o = self->owner;
    o->stamp = -1;
    RtlLeaveCriticalSection(o);
}
