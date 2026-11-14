/* SM1: like the direct flag setters, but the validating callee is a virtual call through the vtable. */
typedef struct Ts4VFlagged { int (**vt)(struct Ts4VFlagged *, unsigned); } Ts4VFlagged;
#define SET_VFLAG(NAME, OFF, SLOT) \
    int NAME(Ts4VFlagged *t, unsigned enable) { \
        int r; \
        if (enable) { \
            if (*((unsigned char *)t + OFF) != 0) return 0; \
            r = t->vt[SLOT / 4](t, enable); \
            if (r != 0) return r; \
            *((unsigned char *)t + OFF) = 1; \
            return 0; \
        } \
        r = t->vt[SLOT / 4](t, 0); \
        if (r != 0) return r; \
        *((unsigned char *)t + OFF) = 0; \
        return 0; \
    }

/* Swing_DLL.xex 0x88377F78 */
SET_VFLAG(ts4_set_state_flag_virtual_88377F78, 0x110, 0x0)
/* Swing_DLL.xex 0x88387B48 */
SET_VFLAG(ts4_set_state_flag_virtual_88387B48, 0x120, 0x0)
