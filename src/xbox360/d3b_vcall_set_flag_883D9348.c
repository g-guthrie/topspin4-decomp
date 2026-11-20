/* Swing_DLL.xex 0x883D9348-0x884005A0, executable version 0.0.0.3. */
typedef struct Obj { void **vtbl; } Obj;

/* Calls a virtual method with the requested state and records it in a byte flag when it succeeds. */
#define VCALL_FLAG(NAME, FLAG, SLOT) \
int NAME(Obj *self, unsigned on) \
{ \
    int r; \
    if (on) { \
        if (*((unsigned char *)self + FLAG) == 0) { \
            r = ((int (*)(Obj *, unsigned))self->vtbl[(SLOT) / 4])(self, on); \
            if (r != 0) return r; \
            *((unsigned char *)self + FLAG) = 1; \
        } \
    } else { \
        r = ((int (*)(Obj *, unsigned))self->vtbl[(SLOT) / 4])(self, 0); \
        if (r != 0) return r; \
        *((unsigned char *)self + FLAG) = 0; \
    } \
    return 0; \
}

VCALL_FLAG(ts4_vcall_set_flag_883D9348, 0x10, 0x4c)
VCALL_FLAG(ts4_vcall_set_flag_883DB780, 0x4, 0x0)
VCALL_FLAG(ts4_vcall_set_flag_883DCEE0, 0x10, 0x0)
VCALL_FLAG(ts4_vcall_set_flag_883DCFE8, 0x14, 0x0)
VCALL_FLAG(ts4_vcall_set_flag_883DFCD8, 0x10, 0x54)
VCALL_FLAG(ts4_vcall_set_flag_883E48B0, 0x4, 0x18)
VCALL_FLAG(ts4_vcall_set_flag_883E4958, 0x4, 0x5c)
VCALL_FLAG(ts4_vcall_set_flag_883E76A0, 0x8, 0x24)
VCALL_FLAG(ts4_vcall_set_flag_883E7750, 0xc, 0x0)
VCALL_FLAG(ts4_vcall_set_flag_883E8270, 0x8, 0x2c)
VCALL_FLAG(ts4_vcall_set_flag_883EDE70, 0x10, 0x44)
VCALL_FLAG(ts4_vcall_set_flag_883EE918, 0x10, 0x2c)
VCALL_FLAG(ts4_vcall_set_flag_883F6200, 0x8, 0xe0)
VCALL_FLAG(ts4_vcall_set_flag_883F9FD0, 0x10, 0x3c)
VCALL_FLAG(ts4_vcall_set_flag_883FB0D0, 0x4, 0x14)
VCALL_FLAG(ts4_vcall_set_flag_884004D0, 0x8, 0x0)
