/* Loader_DLL.xex 0x8310D948-0x8310E444, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Desc {
    u32 w0;
    const void *name;
    const void *name2;
    u32 z;
    void *f3;
    void *f2;
    void *f1;
    u32 obj;
    u32 s0;
    u32 s1;
};
#ifdef _MSC_VER
void *memset(void *p, int c, unsigned n);
#else
#include <string.h>
#endif
extern long fn_8310D108(struct Desc *d, void *target);
extern const char lbl_83000B6C[];
extern const char lbl_83000AE8[];
extern char lbl_8352F7B8[];
extern void ts4l_if_call_seq_u32_off4_83105B30(void);
extern void ts4l_if_call_seq_fn_83120518_83105AB8(void);
extern void ts4_tailcall_fn_831282D0_83100110(void);
extern const char lbl_83000C18[];
extern const char lbl_83000B24[];
extern char lbl_8352F7D4[];
extern void ts4_if_call_seq_fn_83120540_83105D78(void);
extern void fn_83105CF8(void);
extern void ts4_tailcall_fn_83127EE0_83100240(void);
extern const char lbl_83000C58[];
extern char lbl_8352F7DC[];
extern void ts4_if_call_seq_fn_83120540_83105E20(void);
extern void ts4l_if_call_seq_fn_83120518_83105DA8(void);
extern void ts4_tailcall_fn_83129008_83100260(void);
extern const char lbl_83000D30[];
extern const char lbl_83000CEC[];
extern char lbl_8352F800[];
extern void ts4_if_call_seq_fn_831225B8_831061B0(void);
extern void ts4l_if_call_seq_fn_83120518_83106138(void);
extern void ts4_tailcall_fn_83136960_831003D8(void);

long ts4l_register_class_8310D948(void)
{
    struct Desc d;
    long hr;
    memset(&d, 0, sizeof(d));
    d.name = lbl_83000B6C;
    d.name2 = lbl_83000AE8;
    d.z = 0;
    d.f2 = (void *)ts4l_if_call_seq_fn_83120518_83105AB8;
    d.f1 = (void *)ts4l_if_call_seq_u32_off4_83105B30;
    d.f3 = (void *)ts4_tailcall_fn_831282D0_83100110;
    d.s0 = 0;
    d.obj = 0;
    d.s1 = 0;
    hr = fn_8310D108(&d, lbl_8352F7B8);
    return hr < 0 ? hr : 0;
}

long ts4l_register_class_8310DDB0(void)
{
    struct Desc d;
    long hr;
    memset(&d, 0, sizeof(d));
    d.name = lbl_83000C18;
    d.name2 = lbl_83000B24;
    d.z = 0;
    d.f2 = (void *)fn_83105CF8;
    d.f1 = (void *)ts4_if_call_seq_fn_83120540_83105D78;
    d.f3 = (void *)ts4_tailcall_fn_83127EE0_83100240;
    d.s0 = 0;
    d.obj = 0;
    d.s1 = 0;
    hr = fn_8310D108(&d, lbl_8352F7D4);
    return hr < 0 ? hr : 0;
}

long ts4l_register_class_8310DF18(void)
{
    struct Desc d;
    long hr;
    memset(&d, 0, sizeof(d));
    d.name = lbl_83000C58;
    d.name2 = lbl_83000AE8;
    d.z = 0;
    d.f2 = (void *)ts4l_if_call_seq_fn_83120518_83105DA8;
    d.f1 = (void *)ts4_if_call_seq_fn_83120540_83105E20;
    d.f3 = (void *)ts4_tailcall_fn_83129008_83100260;
    d.s0 = 0;
    d.obj = 0;
    d.s1 = 0;
    hr = fn_8310D108(&d, lbl_8352F7DC);
    return hr < 0 ? hr : 0;
}

long ts4l_register_class_8310E3A8(void)
{
    struct Desc d;
    long hr;
    memset(&d, 0, sizeof(d));
    d.name = lbl_83000D30;
    d.name2 = lbl_83000CEC;
    d.z = 0;
    d.f2 = (void *)ts4l_if_call_seq_fn_83120518_83106138;
    d.f1 = (void *)ts4_if_call_seq_fn_831225B8_831061B0;
    d.f3 = (void *)ts4_tailcall_fn_83136960_831003D8;
    d.s0 = 0;
    d.obj = 0;
    d.s1 = 0;
    hr = fn_8310D108(&d, lbl_8352F800);
    return hr < 0 ? hr : 0;
}
