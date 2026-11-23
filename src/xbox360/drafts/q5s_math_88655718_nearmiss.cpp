/* nearmiss: 2 off; blocker: flag byte register r9 (target) vs r11 (ours) in the Q5sHandle by-value return; depends on the unmatched handle class (ctor/dtor shape) of the resource Load virtual at vtable+0x30; perm_auto no gain. */
struct Q5sKey;
struct Q5sHandle {
    int v;
    Q5sHandle() : v(0) {}
    Q5sHandle(const Q5sHandle &o) : v(o.v) {}
    Q5sHandle &operator=(const Q5sHandle &o) { v = o.v; return *this; }
};
struct Q5sLoader {
    virtual void f00(); virtual void f04(); virtual void f08(); virtual void f0c();
    virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1c();
    virtual void f20(); virtual void f24(); virtual void f28(); virtual void f2c();
    virtual Q5sHandle Load(Q5sKey *key, int kind, int a, int b);
};
struct Q5sSys { char pad[0x220]; Q5sLoader *loader; };
extern "C" Q5sSys *lbl_88D45B1C;
extern "C" Q5sLoader *lbl_88D45B2C;
extern "C" Q5sHandle fn_88655718(const unsigned char *flag, Q5sKey *key)
{
    Q5sHandle h;
    if (*flag)
        h = lbl_88D45B1C->loader->Load(key, 3, -1, 0);
    else if (lbl_88D45B2C)
        h = lbl_88D45B2C->Load(key, 3, -1, 0);
    return h;
}
