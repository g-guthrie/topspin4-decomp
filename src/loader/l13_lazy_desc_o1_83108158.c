/* Loader_DLL.xex 0x83108158-0x8310CB80, executable version 0.0.0.3.
   Lazily initialised global descriptor accessors (guard bit, init, flag out). */
#ifdef _MSC_VER
extern void *memset(void *, int, unsigned);
#pragma intrinsic(memset)
#else
#include <string.h>
#endif
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef struct {
    int f0; int f4; int f8; int fc; void *f10; int f14; int f18; int f1c; int f20; void *f24; ts4_u64 f28;
} Desc;

extern Desc lbl_8353015C;
extern unsigned lbl_8353018C;
extern char lbl_830012B4[];
extern int ts4l_if_call_seq_lbl_83530144_831080F8(int *p);
extern void fn_83102548(void);
extern Desc lbl_83530360;
extern unsigned lbl_83530390;
extern char lbl_83001324[];
extern int ts4l_if_call_seq_lbl_83530348_83108E48(int *p);
extern void fn_83103F70(void);
extern Desc lbl_835303AC;
extern unsigned lbl_835303DC;
extern char lbl_83001340[];
extern int ts4l_if_call_seq_lbl_83530394_83108F80(int *p);
extern void fn_83104050(void);
extern Desc lbl_83530B50;
extern unsigned lbl_83530B80;
extern char lbl_830018C0[];
extern int ts4l_if_call_seq_lbl_835303E0_831095C0(int *p);
extern void fn_831036F0(void);

Desc *ts4l_lazy_desc_83108158(int *flag)
{
    if ((lbl_8353018C & 1) == 0) {
        lbl_8353018C |= 1;
        lbl_8353015C.f4 = 0;
        lbl_8353015C.f8 = 0x4;
        lbl_8353015C.fc = 0;
        lbl_8353015C.f10 = lbl_830012B4;
        lbl_8353015C.f14 = 0x3;
        lbl_8353015C.f18 = ts4l_if_call_seq_lbl_83530144_831080F8(flag);
        lbl_8353015C.f1c = 0;
        lbl_8353015C.f20 = 0;
        lbl_8353015C.f24 = (void *)fn_83102548;
        memset(&lbl_8353015C.f28, 0, 8);
    }
    *flag = 1;
    return &lbl_8353015C;
}

Desc *ts4l_lazy_desc_83108EC8(int *flag)
{
    if ((lbl_83530390 & 1) == 0) {
        lbl_83530390 |= 1;
        lbl_83530360.f4 = 0;
        lbl_83530360.f8 = 0xa8;
        lbl_83530360.fc = 0;
        lbl_83530360.f10 = lbl_83001324;
        lbl_83530360.f14 = 0x8;
        lbl_83530360.f18 = ts4l_if_call_seq_lbl_83530348_83108E48(flag);
        lbl_83530360.f1c = 0;
        lbl_83530360.f20 = 0;
        lbl_83530360.f24 = (void *)fn_83103F70;
        memset(&lbl_83530360.f28, 0, 8);
    }
    *flag = 1;
    return &lbl_83530360;
}

Desc *ts4l_lazy_desc_83108FF0(int *flag)
{
    if ((lbl_835303DC & 1) == 0) {
        lbl_835303DC |= 1;
        lbl_835303AC.f4 = 0;
        lbl_835303AC.f8 = 0xa8;
        lbl_835303AC.fc = 0;
        lbl_835303AC.f10 = lbl_83001340;
        lbl_835303AC.f14 = 0x4;
        lbl_835303AC.f18 = ts4l_if_call_seq_lbl_83530394_83108F80(flag);
        lbl_835303AC.f1c = 0;
        lbl_835303AC.f20 = 0;
        lbl_835303AC.f24 = (void *)fn_83104050;
        memset(&lbl_835303AC.f28, 0, 8);
    }
    *flag = 1;
    return &lbl_835303AC;
}

Desc *ts4l_lazy_desc_8310CB80(int *flag)
{
    if ((lbl_83530B80 & 1) == 0) {
        lbl_83530B80 |= 1;
        lbl_83530B50.f4 = 0;
        lbl_83530B50.f8 = 0x4;
        lbl_83530B50.fc = 0;
        lbl_83530B50.f10 = lbl_830018C0;
        lbl_83530B50.f14 = 0x5;
        lbl_83530B50.f18 = ts4l_if_call_seq_lbl_835303E0_831095C0(flag);
        lbl_83530B50.f1c = 0;
        lbl_83530B50.f20 = 0;
        lbl_83530B50.f24 = (void *)fn_831036F0;
        memset(&lbl_83530B50.f28, 0, 8);
    }
    *flag = 1;
    return &lbl_83530B50;
}
