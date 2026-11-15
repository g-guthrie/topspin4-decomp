/* CX50: byte-stream string writer, Swing_DLL.xex 0x889C6AE8. */
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"
#pragma clang diagnostic ignored "-Wint-to-void-pointer-cast"
#pragma clang diagnostic ignored "-Wpointer-to-int-cast"
#pragma clang diagnostic ignored "-Wvoid-pointer-to-int-cast"
#pragma clang diagnostic ignored "-Wincompatible-library-redeclaration"
#endif
typedef unsigned char u8;
typedef unsigned int u32;
#define W(o, off) (*(u32 *)((u8 *)(o) + (off)))

extern unsigned int strlen(const char *s);
extern void *memcpy(void *d, const void *s, unsigned int n);
extern u32 ts4_if_call_seq_u32_off4_889C6550(u32 a0, int a1);
extern void fn_889C67F0(void *stream, u32 *v);

/* 0x889C6AE8: write a length-prefixed string */
void ts4_cx50_write_str_889C6AE8(u32 a0, const char *s)
{
    u32 len = strlen(s);
    u32 t1, t2, t3, tmp;
    tmp = len;
    fn_889C67F0((void *)a0, &tmp);
    ts4_if_call_seq_u32_off4_889C6550(a0, (int)(len + W(a0, 8)));
    memcpy((void *)(W(a0, 0) + W(a0, 8)), s, len);
    t1 = W(a0, 8);
    t2 = W(a0, 0);
    W(a0, 8) = len + t1;
    t3 = W(t2, 0);
    W(t2, 0) = t3 + len;
}
