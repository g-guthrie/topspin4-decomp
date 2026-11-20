/* CX50: constructors, Swing_DLL.xex 0x889C7180 and 0x889C53E0. */
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

extern void fn_88617D88(void *self);
extern void ts4_object_finalize(void *p);
extern char lbl_880D7590[];
extern u32 lbl_88D458F8;

#define VW(o, off) (*(volatile u32 *)((u8 *)(o) + (off)))

/* 0x889C7180: singleton constructor */
void *ts4_cx50_ctor_889C7180(void *self)
{
    fn_88617D88(self);
    VW(self, 0x1c) = 0;
    VW(self, 0) = (u32)lbl_880D7590;
    VW(self, 0x20) = 0;
    VW(self, 0x24) = 0;
    W(self, 0x28) = 0;
    W(self, 0x2c) = 0;
    W(self, 0x30) = 0;
    W(self, 0x34) = 0;
    lbl_88D458F8 = (u32)self;
    W(self, 0x38) = 0;
    ts4_object_finalize((u8 *)self + 0x24);
    ts4_object_finalize((u8 *)self + 0x30);
    return self;
}
