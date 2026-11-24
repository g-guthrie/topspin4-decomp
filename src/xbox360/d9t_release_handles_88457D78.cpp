/* Swing_DLL.xex 0x88457D78-0x8845A694, executable version 0.0.0.3. */
struct Ts4Mgr88457D78 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void release(unsigned h, int arg);
};
struct Ts4Res88457D78 {
    virtual void destroy(int flag);
    char pad[0x4];
    Ts4Mgr88457D78 *mgr;
    char pad2[0x10];
    unsigned short handles[8];
};
extern "C" void ts4_release_handles_88457D78(Ts4Res88457D78 *r, int arg)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (r->handles[i] != 0xFFFF) {
            r->mgr->release(r->handles[i], arg);
        }
    }
    if (r != 0) {
        r->destroy(1);
    }
}
struct Ts4Mgr88458F60 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void release(unsigned h, int arg);
};
struct Ts4Res88458F60 {
    virtual void destroy(int flag);
    char pad[0x4];
    Ts4Mgr88458F60 *mgr;
    unsigned short handles[3];
};
extern "C" void ts4_release_handles_88458F60(Ts4Res88458F60 *r, int arg)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (r->handles[i] != 0xFFFF) {
            r->mgr->release(r->handles[i], arg);
        }
    }
    if (r != 0) {
        r->destroy(1);
    }
}
struct Ts4Mgr8845A620 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void release(unsigned h, int arg);
};
struct Ts4Res8845A620 {
    virtual void destroy(int flag);
    char pad[0x4];
    Ts4Mgr8845A620 *mgr;
    unsigned short handles[3];
};
extern "C" void ts4_release_handles_8845A620(Ts4Res8845A620 *r, int arg)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (r->handles[i] != 0xFFFF) {
            r->mgr->release(r->handles[i], arg);
        }
    }
    if (r != 0) {
        r->destroy(1);
    }
}
