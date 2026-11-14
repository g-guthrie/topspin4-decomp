/* Loader_DLL.xex 0x830A0ED0-0x830A12F0, executable version 0.0.0.3. */
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
struct Out { u32 v[4]; };
#ifdef _MSC_VER
void *memset(void *p, int c, unsigned n);
#else
#include <string.h>
#endif
extern const char lbl_83085F84[];
extern long fn_8310D108(struct Desc *d, struct Out *out);
extern const char lbl_83084C80[];
extern void ts4l_create_obj_830A0F70(void);
extern void ts4_if_get_u32_off0_830A0FE8(void);
extern void ts4_get_u32_off0_830A5CE0(void);
extern const char lbl_83084CA8[];
extern void fn_830A11B8(void);
extern void ts4_if_get_u32_off0_830A1220(void);
extern const char lbl_83084CD4[];
extern void ts4l_create_obj_830A1328(void);
extern void ts4_if_get_u32_off0_830A13A0(void);

long ts4l_register_class_830A0ED0(void)
{
    struct Out out;
    struct Desc d;
    long hr;
    memset(&d, 0, sizeof(d));
    d.name = lbl_83084C80;
    d.name2 = lbl_83085F84;
    d.f2 = (void *)ts4l_create_obj_830A0F70;
    d.f1 = (void *)ts4_if_get_u32_off0_830A0FE8;
    d.f3 = (void *)ts4_get_u32_off0_830A5CE0;
    d.s0 = 0;
    d.obj = 0;
    hr = fn_8310D108(&d, &out);
    return hr < 0 ? hr : 0;
}

long ts4l_register_class_830A1118(void)
{
    struct Out out;
    struct Desc d;
    long hr;
    memset(&d, 0, sizeof(d));
    d.name = lbl_83084CA8;
    d.name2 = lbl_83085F84;
    d.f2 = (void *)fn_830A11B8;
    d.f1 = (void *)ts4_if_get_u32_off0_830A1220;
    d.f3 = (void *)ts4_get_u32_off0_830A5CE0;
    d.s0 = 0;
    d.obj = 0;
    hr = fn_8310D108(&d, &out);
    return hr < 0 ? hr : 0;
}

long ts4l_register_class_830A1288(void)
{
    struct Out out;
    struct Desc d;
    long hr;
    memset(&d, 0, sizeof(d));
    d.name = lbl_83084CD4;
    d.name2 = lbl_83085F84;
    d.f2 = (void *)ts4l_create_obj_830A1328;
    d.f1 = (void *)ts4_if_get_u32_off0_830A13A0;
    d.f3 = (void *)ts4_get_u32_off0_830A5CE0;
    d.s0 = 0;
    d.obj = 0;
    hr = fn_8310D108(&d, &out);
    return hr < 0 ? hr : 0;
}
