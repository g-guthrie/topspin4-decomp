/* Swing_DLL.xex 0x883296A0-0x8840F200, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

/* Bounded byte copy that stops after copying the terminator. */
void ts4_copy_bytes_until_nul_883296A0(char *dst, const char *src, int n)
{
    u8 c;
    do {
        if (n-- == 0) {
            return;
        }
        c = (u8)*src++;
        *dst++ = (char)c;
    } while (c != 0);
}

/* Length of a 16-bit string in elements. */
int ts4_wide_length_883766B0(const u16 *s)
{
    const u16 *p = s;
    while (*p != 0) {
        p++;
    }
    return (int)(p - s);
}

/* Bounded 16-bit copy that stops after copying the terminator. */
void ts4_copy_wide_until_nul_883766D8(u16 *dst, const u16 *src, int n)
{
    u16 c;
    do {
        if (n-- == 0) {
            return;
        }
        c = *src++;
        *dst++ = c;
    } while (c != 0);
}

extern float lbl_88001A68;
extern float lbl_88001A20;
extern float lbl_88001B04;
extern float lbl_880023D4;
extern u32 fn_8832F960(char *obj, float value);

/* Writes the same constant into two float slots of the containing object (this - 0x1c). */
u32 ts4_reset_two_floats_88343D60(char *obj)
{
    char *base = obj ? obj - 0x1c : 0;
    float v = lbl_88001A68;
    *(float *)(base + 0x14c) = v;
    *(float *)(base + 0x148) = v;
    return 0;
}

typedef u32 (*ts4_float_vfn)(void *, float);

/* Forwards a float read from the child object to virtual slot 14. */
u32 ts4_forward_child_float_883ACE70(char *obj)
{
    char *child = *(char **)(obj + 0x10);
    if (!child) {
        return 0;
    }
    return ((ts4_float_vfn)(*(void ***)obj)[14])(obj, *(float *)(child + 0xb4));
}

/* Clamps a value into a fixed range, stores it and forwards it. */
u32 ts4_clamp_store_forward_88330450(char *obj, float v)
{
    if (v < lbl_88001A20) {
        v = lbl_88001A20;
    } else if (v > lbl_88001A68) {
        v = lbl_88001A68;
    }
    *(float *)(obj + 0x40) = v;
    return fn_8832F960(obj, v);
}
