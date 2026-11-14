/* Swing_DLL.xex 0x883E5800-0x883E588C, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned long long u64;
struct Ts4W7Source {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5();
    virtual int query(void *a, char *b);
};
struct Ts4W7Size {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual u64 size();
};
struct Ts4W7Obj {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5();
    virtual int query(void *a, char *b);
    Ts4W7Size *sizer;
    char padc[4];
    u32 f10;
    char pad14[4];
    u64 limit;
    char pad20[0x10];
    char f30[4];
    char flag;
};
extern "C" {
int ts4_query_limit_883E5800(Ts4W7Obj *o)
{
    int r = o->query(o->f30, &o->flag);
    if (r != 0)
        return r;
    if (o->f10 == 0) {
        if (o->sizer->size() > o->limit)
            o->flag = 1;
    }
    return 0;
}
}
