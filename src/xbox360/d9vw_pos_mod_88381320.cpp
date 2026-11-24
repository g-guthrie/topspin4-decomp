/* Swing_DLL.xex 0x88381320-0x883813B4, executable version 0.0.0.3. */
typedef unsigned int u32;
#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif
struct Ts4VwInfo { u32 a; u32 b[3]; };
extern "C" void *memset(void *, int, unsigned);
#ifdef _MSC_VER
#pragma intrinsic(memset)
#endif
struct Ts4VwSrc {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24();
    virtual void get_info(Ts4VwInfo *i);
};
struct Ts4VwObj { char pad[0x2ac]; Ts4VwSrc *src; char pad2[0x2d8 - 0x2b0]; u32 div; };
extern "C" {
int ts4_pos_mod_88381320(Ts4VwObj *o, u32 *out)
{
    Ts4VwInfo info;
    info.a = 0;
    memset(info.b, 0, 12);
    if (out == 0)
        return 0x25;
    o->src->get_info(&info);
    *out = (u32)(*(u64 *)&info.b[1] % o->div);
    return 0;
}
}
