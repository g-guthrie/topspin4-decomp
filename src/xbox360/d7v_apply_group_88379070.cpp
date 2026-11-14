/* Swing_DLL.xex 0x88379070-0x883790F8, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Ts4V6Child {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37();
    virtual void apply(u32 key);
    virtual int check(u32 key);
};
struct Ts4V6Group {
    char pad[0x18];
    Ts4V6Child *owner;
    char pad1c[0x7C - 0x1C];
    int count;
    Ts4V6Child *items[1];
};
extern "C" {
int fn_883AD0D0(Ts4V6Group *g, u32 key);
void ts4_apply_group_88379070(Ts4V6Group *g, u32 key)
{
    int i;
    if (fn_883AD0D0(g, key) == 0 && g->owner->check(key) == 0) {
        for (i = 0; i < g->count; ++i)
            g->items[i]->apply(key & ~7u);
    }
}
}
