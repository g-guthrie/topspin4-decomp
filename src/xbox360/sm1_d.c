/* SM1 batch d: small helpers (default /O2). */
typedef unsigned int u32;
typedef unsigned long long u64;

/* Swing_DLL.xex 0x8827D780: forward to the object at +0x14, remapping the mode 0->1, 1->2, 2->0 */
extern int fn_8856C948(void *, int, int);
typedef struct Ts4Holder14 { char pad[0x14]; void *inner; } Ts4Holder14;
int ts4_forward_remapped_mode_8827D780(Ts4Holder14 *t, int a, int mode) {
    int m = 1;
    if (mode == 2) m = 0;
    else if (mode == 1) m = 2;
    return fn_8856C948(t->inner, a, m);
}

/* 0x882C3B08: map a four-character-code-like value to an error code, otherwise pass it through */
u32 ts4_map_code_882C3B08(u32 x) {
    u32 d = x - 0x36314C41u;
    if (d != 0) {
        if (d != 0x5df) return x;
        return 0x28280086;
    }
    return 0x0800004A;
}

/* 0x883B19B0 / 0x883B19E0: clamp every float of an array to at most / at least a bound */
void ts4_clamp_floats_max_883B19B0(float *a, float x, u32 n) { u32 i; for (i = 0; i < n; i++) if (a[i] > x) a[i] = x; }
void ts4_clamp_floats_min_883B19E0(float *a, float x, u32 n) { u32 i; for (i = 0; i < n; i++) if (a[i] < x) a[i] = x; }

/* 0x883FF790: true for states 0, 2 and 3 */
typedef struct Ts4State18 { char pad[0x18]; int state; } Ts4State18;
unsigned char ts4_state_is_0_2_or_3_883FF790(Ts4State18 *p) { int s = p->state; return s == 2 || s == 0 || s == 3; }

/* 0x8834B260: store a float into one of two slots of the object that contains this secondary base */
int ts4_set_float_by_index_adj1c_8834B260(char *t, u32 idx, float x) {
    char *p = t ? t - 0x1c : 0;
    switch (idx) {
    case 0: *(float *)(p + 0x144) = x; break;
    case 1: *(float *)(p + 0x13c) = x; break;
    }
    return 0;
}

/* 0x88381958 */
int ts4_get_u32_off2A0_adj1c_88381958(char *t, u32 *out) { char *p = t ? t - 0x1c : 0; if (out == 0) return 0x25; *out = *(u32 *)(p + 0x2a0); return 0; }

/* 0x883BAC18: little-endian u32 from bytes 0xE..0x11 of the buffer pointed to by the first field */
u32 ts4_read_le32_at_0xE_883BAC18(unsigned char **t) { unsigned char *b = *t; return ((((u32)b[0x11] << 8 | b[0x10]) << 8 | b[0xf]) << 8) | b[0xe]; }
