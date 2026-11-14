/* Loader_DLL.xex 0x8310DB80-0x831106A0, executable version 0.0.0.3. */
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
extern const char lbl_83000BC4[];
extern const char lbl_83000B80[];
extern char lbl_8352F7C8[];
extern void ts4_call_seq_fn_83120540_831001A8(void);
extern void ts4l_if_call_seq_fn_83120518_831099C8(void);
extern void ts4_fn_831001D0(void);
extern const char lbl_83000D9C[];
extern const char lbl_83000B24[];
extern char lbl_8352F808[];
extern void ts4_call_seq_fn_83120540_83100418(void);
extern void ts4l_if_call_seq_fn_83120518_83109D50(void);
extern void ts4_tailcall_fn_83122478_83100440(void);
extern const char lbl_83000EE0[];
extern const char lbl_83000E34[];
extern char lbl_8352F834[];
extern void ts4l_if_call_seq_fn_8315C668_8310A340(void);
extern void ts4l_if_call_seq_fn_83120518_8310A2C8(void);
extern void ts4_fn_83100538(void);
extern const char lbl_83000C80[];
extern const char lbl_83000AE8[];
extern char lbl_8352F7E4[];
extern void ts4_if_call_seq_fn_83107F08_8310F0A0(void);
extern void fn_8310F010(void);
extern void ts4_tailcall_fn_83134FD8_831002A8(void);

long ts4l_register_class_8310DB80(void)
{
    struct Desc d;
    long hr;
    memset(&d, 0, sizeof(d));
    d.name = lbl_83000BC4;
    d.name2 = lbl_83000B80;
    d.z = 0;
    d.f2 = (void *)ts4l_if_call_seq_fn_83120518_831099C8;
    d.f1 = (void *)ts4_call_seq_fn_83120540_831001A8;
    d.f3 = (void *)ts4_fn_831001D0;
    d.s0 = 0;
    d.obj = 0;
    d.s1 = 0;
    hr = fn_8310D108(&d, lbl_8352F7C8);
    return hr < 0 ? hr : 0;
}

long ts4l_register_class_8310E698(void)
{
    struct Desc d;
    long hr;
    memset(&d, 0, sizeof(d));
    d.name = lbl_83000D9C;
    d.name2 = lbl_83000B24;
    d.z = 0;
    d.f2 = (void *)ts4l_if_call_seq_fn_83120518_83109D50;
    d.f1 = (void *)ts4_call_seq_fn_83120540_83100418;
    d.f3 = (void *)ts4_tailcall_fn_83122478_83100440;
    d.s0 = 0;
    d.obj = 0;
    d.s1 = 0;
    hr = fn_8310D108(&d, lbl_8352F808);
    return hr < 0 ? hr : 0;
}

long ts4l_register_class_8310EDD8(void)
{
    struct Desc d;
    long hr;
    memset(&d, 0, sizeof(d));
    d.name = lbl_83000EE0;
    d.name2 = lbl_83000E34;
    d.z = 0;
    d.f2 = (void *)ts4l_if_call_seq_fn_83120518_8310A2C8;
    d.f1 = (void *)ts4l_if_call_seq_fn_8315C668_8310A340;
    d.f3 = (void *)ts4_fn_83100538;
    d.s0 = 0;
    d.obj = 0;
    d.s1 = 0;
    hr = fn_8310D108(&d, lbl_8352F834);
    return hr < 0 ? hr : 0;
}

long ts4l_register_class_831106A0(void)
{
    struct Desc d;
    long hr;
    memset(&d, 0, sizeof(d));
    d.name = lbl_83000C80;
    d.name2 = lbl_83000AE8;
    d.z = 0;
    d.f2 = (void *)fn_8310F010;
    d.f1 = (void *)ts4_if_call_seq_fn_83107F08_8310F0A0;
    d.f3 = (void *)ts4_tailcall_fn_83134FD8_831002A8;
    d.s0 = 0;
    d.obj = 0;
    d.s1 = 0;
    hr = fn_8310D108(&d, lbl_8352F7E4);
    return hr < 0 ? hr : 0;
}
