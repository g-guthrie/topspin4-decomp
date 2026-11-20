/* SM1 /O1 batch: configuration-struct bitfield setters that also set a dirty bit in a 64-bit mask.
 * Compiled with /O1 (register reuse and in-order stores match the original). */
typedef unsigned int u32;
typedef unsigned long long u64;
#define W(p, o) (*(u32 *)((char *)(p) + (o)))

/* Swing_DLL.xex 0x8828BB28 */
void ts4_cfg_set_w_2948_8828BB28(char *p, u32 v) {
    W(p,0x2948) = (W(p,0x2948) & 0xfffffff8u) | (v & 0x7u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x40ULL;
    }
}
/* Swing_DLL.xex 0x8828BB58 */
void ts4_cfg_set_w_2948_8828BB58(char *p, u32 v) {
    W(p,0x2948) = (W(p,0x2948) & 0xfffff807u) | ((v << 3) & 0x7f8u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x40ULL;
    }
}
/* Swing_DLL.xex 0x8828C050 */
void ts4_cfg_set_w_293c_8828C050(char *p, u32 v) {
    W(p,0x293c) = (W(p,0x293c) & 0xfffffff8u) | (v & 0x7u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x200ULL;
    }
}
/* Swing_DLL.xex 0x8828C190 */
void ts4_cfg_set_w_29b8_8828C190(char *p, u32 v) {
    W(p,0x29b8) = (W(p,0x29b8) & 0xfffffbffu) | ((v << 10) & 0x400u);
    { u64 *q = (u64 *)(p + 0x20);
      *q |= 0x2000000000ULL;
    }
}
/* Swing_DLL.xex 0x8828C2B0 */
void ts4_cfg_set_w_2934_8828C2B0(char *p, u32 v) {
    W(p,0x2934) = (W(p,0x2934) & 0xfffffffbu) | ((v << 2) & 0x4u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x800ULL;
    }
}
/* Swing_DLL.xex 0x8828C390 */
void ts4_cfg_set_w_2934_8828C390(char *p, u32 v) {
    W(p,0x2934) = (W(p,0x2934) & 0xfffff8ffu) | ((v << 8) & 0x700u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x800ULL;
    }
}
/* Swing_DLL.xex 0x8828C430 */
void ts4_cfg_set_w_2934_8828C430(char *p, u32 v) {
    W(p,0x2934) = (W(p,0x2934) & 0xfffe3fffu) | ((v << 14) & 0x1c000u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x800ULL;
    }
}
/* Swing_DLL.xex 0x8828C460 */
void ts4_cfg_set_w_2934_8828C460(char *p, u32 v) {
    W(p,0x2934) = (W(p,0x2934) & 0xff8fffffu) | ((v << 20) & 0x700000u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x800ULL;
    }
}
/* Swing_DLL.xex 0x8828C500 */
void ts4_cfg_set_w_2934_8828C500(char *p, u32 v) {
    W(p,0x2934) = (W(p,0x2934) & 0xe3ffffffu) | ((v << 26) & 0x1c000000u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x800ULL;
    }
}
/* Swing_DLL.xex 0x8828C530 */
void ts4_cfg_set_b_2903_8828C530(char *p, char v) {
    *(char *)((char *)p + 0x2903) = v;
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x10000000ULL;
    }
}
/* Swing_DLL.xex 0x8828C550 */
void ts4_cfg_set_b_2902_8828C550(char *p, char v) {
    *(char *)((char *)p + 0x2902) = v;
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x10000000ULL;
    }
}
/* Swing_DLL.xex 0x8828C570 */
void ts4_cfg_set_b_2901_8828C570(char *p, char v) {
    *(char *)((char *)p + 0x2901) = v;
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x10000000ULL;
    }
}
/* Swing_DLL.xex 0x8828C590 */
void ts4_cfg_set_b_28ff_8828C590(char *p, char v) {
    *(char *)((char *)p + 0x28ff) = v;
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x20000000ULL;
    }
}
/* Swing_DLL.xex 0x8828C5B0 */
void ts4_cfg_set_b_28fe_8828C5B0(char *p, char v) {
    *(char *)((char *)p + 0x28fe) = v;
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x20000000ULL;
    }
}
/* Swing_DLL.xex 0x8828C5D0 */
void ts4_cfg_set_b_28fd_8828C5D0(char *p, char v) {
    *(char *)((char *)p + 0x28fd) = v;
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x20000000ULL;
    }
}
/* Swing_DLL.xex 0x8828C7D0 */
void ts4_cfg_set_w_2948_8828C7D0(char *p, u32 v) {
    W(p,0x2948) = (W(p,0x2948) & 0xffff7fffu) | ((v << 15) & 0x8000u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x40ULL;
    }
}
/* Swing_DLL.xex 0x8828C800 */
void ts4_cfg_set_w_2a00_8828C800(char *p, u32 v) {
    W(p,0x2a00) = (unsigned short)v;
    { u64 *q = (u64 *)(p + 0x20);
      *q |= 0x80000ULL;
    }
}
/* Swing_DLL.xex 0x8828CA38 */
void ts4_cfg_set_w_292c_8828CA38(char *p, u32 v) {
    W(p,0x292c) = (W(p,0x292c) & 0xfffffff0u) | v;
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x2000ULL;
    }
}
/* Swing_DLL.xex 0x8828CA58 */
void ts4_cfg_set_w_292c_8828CA58(char *p, u32 v) {
    W(p,0x292c) = (W(p,0x292c) & 0xffffff0fu) | (v << 4);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x2000ULL;
    }
}
/* Swing_DLL.xex 0x8828CA80 */
void ts4_cfg_set_w_292c_8828CA80(char *p, u32 v) {
    W(p,0x292c) = (W(p,0x292c) & 0xfffff0ffu) | (v << 8);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x2000ULL;
    }
}
/* Swing_DLL.xex 0x8828CAA8 */
void ts4_cfg_set_w_292c_8828CAA8(char *p, u32 v) {
    W(p,0x292c) = (W(p,0x292c) & 0xffff0fffu) | (v << 12);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x2000ULL;
    }
}
/* Swing_DLL.xex 0x8828CAF8 */
void ts4_cfg_set_w_292c_8828CAF8(char *p, u32 v) {
    W(p,0x292c) = (W(p,0x292c) & 0xff0fffffu) | (v << 20);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x2000ULL;
    }
}
/* Swing_DLL.xex 0x8828CB20 */
void ts4_cfg_set_w_292c_8828CB20(char *p, u32 v) {
    W(p,0x292c) = (W(p,0x292c) & 0xf0ffffffu) | (v << 24);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x2000ULL;
    }
}
/* Swing_DLL.xex 0x8828CB48 */
void ts4_cfg_set_w_292c_8828CB48(char *p, u32 v) {
    W(p,0x292c) = (W(p,0x292c) & 0xfffffffu) | ((v << 28) & 0xf0000000u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x2000ULL;
    }
}
/* Swing_DLL.xex 0x8828CB68 */
void ts4_cfg_set_w_2930_8828CB68(char *p, u32 v) {
    W(p,0x2930) = (W(p,0x2930) & 0xfffffff0u) | v;
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x1000ULL;
    }
}
/* Swing_DLL.xex 0x8828CB88 */
void ts4_cfg_set_w_2930_8828CB88(char *p, u32 v) {
    W(p,0x2930) = (W(p,0x2930) & 0xffffff0fu) | (v << 4);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x1000ULL;
    }
}
/* Swing_DLL.xex 0x8828CBB0 */
void ts4_cfg_set_w_2930_8828CBB0(char *p, u32 v) {
    W(p,0x2930) = (W(p,0x2930) & 0xfffff0ffu) | (v << 8);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x1000ULL;
    }
}
/* Swing_DLL.xex 0x8828CBD8 */
void ts4_cfg_set_w_2930_8828CBD8(char *p, u32 v) {
    W(p,0x2930) = (W(p,0x2930) & 0xffff0fffu) | (v << 12);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x1000ULL;
    }
}
/* Swing_DLL.xex 0x8828CC28 */
void ts4_cfg_set_w_2930_8828CC28(char *p, u32 v) {
    W(p,0x2930) = (W(p,0x2930) & 0xff0fffffu) | (v << 20);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x1000ULL;
    }
}
/* Swing_DLL.xex 0x8828CC50 */
void ts4_cfg_set_w_2930_8828CC50(char *p, u32 v) {
    W(p,0x2930) = (W(p,0x2930) & 0xf0ffffffu) | (v << 24);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x1000ULL;
    }
}
/* Swing_DLL.xex 0x8828CC78 */
void ts4_cfg_set_w_2930_8828CC78(char *p, u32 v) {
    W(p,0x2930) = (W(p,0x2930) & 0xfffffffu) | ((v << 28) & 0xf0000000u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x1000ULL;
    }
}
/* Swing_DLL.xex 0x8828D048 */
void ts4_cfg_set_f_2980_8828D048(char *p, u32 v) {
    *(float *)((char *)p + 0x2980) = *(float *)&v;
    { u64 *q = (u64 *)(p + 0x18);
      *q |= 0x800000000000ULL;
    }
}
/* Swing_DLL.xex 0x8828D080 */
void ts4_cfg_set_f_297c_8828D080(char *p, u32 v) {
    *(float *)((char *)p + 0x297c) = *(float *)&v;
    { u64 *q = (u64 *)(p + 0x18);
      *q |= 0x1000000000000ULL;
    }
}
/* Swing_DLL.xex 0x8828D0B8 */
void ts4_cfg_set_w_2978_8828D0B8(char *p, u32 v) {
    W(p,0x2978) = (W(p,0x2978) & 0xfffffffcu) | (v & 0x3u);
    { u64 *q = (u64 *)(p + 0x18);
      *q |= 0x2000000000000ULL;
    }
}
/* Swing_DLL.xex 0x8828D0F0 */
void ts4_cfg_set_w_29c0_8828D0F0(char *p, u32 v) {
    W(p,0x29c0) = (W(p,0x29c0) & 0xfffffffeu) | (v & 0x1u);
    { u64 *q = (u64 *)(p + 0x20);
      *q |= 0x800000000ULL;
    }
}
/* Swing_DLL.xex 0x8828D128 */
void ts4_cfg_set_w_2948_8828D128(char *p, u32 v) {
    W(p,0x2948) = (W(p,0x2948) & 0xffdfffffu) | ((v << 21) & 0x200000u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x40ULL;
    }
}
/* Swing_DLL.xex 0x8828D158 */
void ts4_cfg_set_w_28d8_8828D158(char *p, u32 v) {
    W(p,0x28d8) = v;
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x4000000000ULL;
    }
}
/* Swing_DLL.xex 0x8828D180 */
void ts4_cfg_set_w_293c_8828D180(char *p, u32 v) {
    W(p,0x293c) = (W(p,0x293c) & 0xffffffefu) | ((v << 4) & 0x10u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x200ULL;
    }
}
/* Swing_DLL.xex 0x8828D1B0 */
void ts4_cfg_set_w_293c_8828D1B0(char *p, u32 v) {
    W(p,0x293c) = (W(p,0x293c) & 0xffffffu) | ((v << 24) & 0xff000000u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x200ULL;
    }
}
/* Swing_DLL.xex 0x8828D1D8 */
void ts4_cfg_set_f_29cc_8828D1D8(char *p, u32 v) {
    *(float *)((char *)p + 0x29cc) = *(float *)&v;
    { u64 *q = (u64 *)(p + 0x20);
      *q |= 0x100000000ULL;
    }
}
/* Swing_DLL.xex 0x8828D208 */
void ts4_cfg_set_f_29c4_8828D208(char *p, u32 v) {
    *(float *)((char *)p + 0x29c4) = *(float *)&v;
    { u64 *q = (u64 *)(p + 0x20);
      *q |= 0x400000000ULL;
    }
}
/* Swing_DLL.xex 0x8828D238 */
void ts4_cfg_set_f_29d0_8828D238(char *p, u32 v) {
    *(float *)((char *)p + 0x29d0) = *(float *)&v;
    { u64 *q = (u64 *)(p + 0x20);
      *q |= 0x80000000ULL;
    }
}
/* Swing_DLL.xex 0x8828D260 */
void ts4_cfg_set_f_29c8_8828D260(char *p, u32 v) {
    *(float *)((char *)p + 0x29c8) = *(float *)&v;
    { u64 *q = (u64 *)(p + 0x20);
      *q |= 0x200000000ULL;
    }
}
/* Swing_DLL.xex 0x8828D290 */
void ts4_cfg_set_w_2efc_8828D290(char *p, u32 v) {
    W(p,0x2efc) = (W(p,0x2efc) & 0xff8fffffu) | ((v << 20) & 0x700000u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x20000ULL;
    }
}
/* Swing_DLL.xex 0x8828D328 */
void ts4_cfg_set_w_2940_8828D328(char *p, u32 v) {
    W(p,0x2940) = (W(p,0x2940) & 0xfffffff7u) | ((v << 3) & 0x8u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x100ULL;
    }
}
/* Swing_DLL.xex 0x8828D358 */
void ts4_cfg_set_w_2940_8828D358(char *p, u32 v) {
    W(p,0x2940) = (W(p,0x2940) & 0xfffffffbu) | ((v << 2) & 0x4u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x100ULL;
    }
}
/* Swing_DLL.xex 0x8828D388 */
void ts4_cfg_set_w_2940_8828D388(char *p, u32 v) {
    W(p,0x2940) = (W(p,0x2940) & 0xffffffdfu) | ((v << 5) & 0x20u);
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x100ULL;
    }
}
/* Swing_DLL.xex 0x8828D3B8 */
void ts4_cfg_set_b_2942_8828D3B8(char *p, char v) {
    *(char *)((char *)p + 0x2942) = v;
    { u64 *q = (u64 *)(p + 0x10);
      *q |= 0x100ULL;
    }
}
