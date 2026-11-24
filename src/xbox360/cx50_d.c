/* CX50: byte-stream reader/writer helpers, Swing_DLL.xex 0x889C6280.
   Stream object: +0 buffer (word 0 = size), +8 read/write position. */
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
#define B(o, off) (*(u8 *)((u8 *)(o) + (off)))

/* 0x889C6280: read four raw bytes into *dst */
void ts4_cx50_read4_889C6280(u32 a0, u32 a1)
{
    u32 t1, t2;
    int t3;
    u8 t4, t5, t6, t7;
    t2 = W(a0, 8);
    t1 = W(a0, 0);
    t3 = W(t1, 0);
    if ((int)t2 >= t3) {
        return;
    }
    t4 = B(t1, t2);
    t5 = B(t1 + t2, 1);
    t6 = B(t1 + t2, 2);
    t7 = B(t2 + t1, 3);
    B(a1, 0) = t4;
    W(a0, 8) = t2 + 4;
    B(a1, 1) = t5;
    B(a1, 2) = t6;
    B(a1, 3) = t7;
}
