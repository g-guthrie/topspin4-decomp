/* CX50: nested-vector key search, Swing_DLL.xex 0x889C70A0. */
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"
#pragma clang diagnostic ignored "-Wpointer-to-int-cast"
#endif
typedef unsigned char u8;
typedef unsigned int u32;
#define W(o, off) (*(u32 *)((u8 *)(o) + (off)))
#ifdef _MSC_VER
#define FI static __forceinline
#else
#define FI static inline
#endif
FI u8 has(u8 *obj, u32 *key)
{
    u8 *ie = (u8 *)W(obj, 0xc);
    u8 *it = (u8 *)W(obj, 8);
    for (; it != ie; it += 0x28) {
        if (*key == W(it, 0)) return 1;
    }
    return 0;
}
/* 0x889C70A0: does any entry list contain the key */
u32 ts4_cx50_has_key_889C70A0(u8 *self, u32 *key)
{
    u32 *end = (u32 *)W(self, 0x28);
    u32 *p = (u32 *)W(self, 0x24);
    for (; p != end; p++) {
        if (has((u8 *)*p, key)) return 1;
    }
    return 0;
}
