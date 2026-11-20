/* Loader_DLL.xex 0x8310D708-0x8310D7A4, executable version 0.0.0.3. */
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
extern const char lbl_83085F70[];
extern const char lbl_83000AE8[];
extern char lbl_8352F7AC[];
extern void ts4l_if_call_seq_u32_off4_83105930(void);
extern void ts4_tailcall_fn_83129268_83100000(void);
extern void fn_831058B0(void);
extern long fn_8310D108(struct Desc *d, void *target);

long ts4l_register_class_8310D708(void)
{
    struct Desc d;
    long hr;
    memset(&d, 0, sizeof(d));
    d.name = lbl_83085F70;
    d.name2 = lbl_83000AE8;
    d.z = 0;
    d.f2 = (void *)fn_831058B0;
    d.f1 = (void *)ts4l_if_call_seq_u32_off4_83105930;
    d.f3 = (void *)ts4_tailcall_fn_83129268_83100000;
    d.s0 = 0;
    d.obj = 0;
    d.s1 = 0;
    hr = fn_8310D108(&d, lbl_8352F7AC);
    return hr < 0 ? hr : 0;
}
