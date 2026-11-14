/* Swing_DLL.xex 0x886182D0-0x88618364, executable version 0.0.0.3. */
typedef unsigned int u32;
struct ts4_sized { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual u32 size_of(void *p); };
extern "C" {
extern u32 lbl_88D45B38;
void *fn_88613268(u32 heap, u32 n, int a, int b, int c);
ts4_sized *fn_8860D360(u32 heap, void *p);
void ts4_registry_dispatch_888860A0(void *p);
#ifdef _MSC_VER
void *memcpy(void *, const void *, unsigned long);
#endif
void *ts4_clone_block_886182D0(void *p, u32 n)
{
    void *out = 0;
    if (n != 0)
        out = fn_88613268(lbl_88D45B38, n, 1, 0, 0);
    if (p != 0) {
        u32 sz = fn_8860D360(lbl_88D45B38, p)->size_of(p);
        u32 m;
        if (n >= sz) m = sz; else m = n;
        memcpy(out, p, m);
        ts4_registry_dispatch_888860A0(p);
    }
    return out;
}
}
