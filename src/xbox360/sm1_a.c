/* SM1 batch a: tiny leaf accessors, setters, and tail-call thunks. */
#include "ts4_vector.h"

#ifdef _MSC_VER
extern float __fsqrts(float);
#pragma intrinsic(__fsqrts)
#else
static float __fsqrts(float x) { return x; }
#endif

typedef unsigned long long u64;
typedef unsigned int u32;

/* Swing_DLL.xex 0x881A7618 */
float ts4_fsqrts_881A7618(float x) { return __fsqrts(x); }

/* 0x883FFAC8, 0x883FFAD0 */
u64 ts4_get_u64_off38_883FFAC8(char *p) { return *(u64 *)(p + 0x38); }
u64 ts4_get_u64_off18_883FFAD0(char *p) { return *(u64 *)(p + 0x18); }

/* float read from an int-typed field reinterpreted as float */
#define FGET(NAME, ADDR, OFF) \
    float NAME(void *unused, char *p) { u32 v = *(u32 *)(p + OFF); (void)unused; return *(float *)&v; }
#define FSET(NAME, ADDR, OFF) \
    void NAME(void *unused, char *p, float *src) { float f = *src; (void)unused; *(u32 *)(p + OFF) = *(u32 *)&f; }
FGET(ts4_get_float_off28_881F0B30, 0x881F0B30, 0x28)
FGET(ts4_get_float_off2C_881F0B58, 0x881F0B58, 0x2c)
FGET(ts4_get_float_off30_881F0B80, 0x881F0B80, 0x30)
FGET(ts4_get_float_off34_881F0BA8, 0x881F0BA8, 0x34)
FGET(ts4_get_float_off38_881F0BD0, 0x881F0BD0, 0x38)
FSET(ts4_set_float_off28_881F0B40, 0x881F0B40, 0x28)
FSET(ts4_set_float_off2C_881F0B68, 0x881F0B68, 0x2c)
FSET(ts4_set_float_off30_881F0B90, 0x881F0B90, 0x30)
FSET(ts4_set_float_off34_881F0BB8, 0x881F0BB8, 0x34)
FSET(ts4_set_float_off38_881F0BE0, 0x881F0BE0, 0x38)

/* float field returned as raw bits */
#define FBITS(NAME, ADDR, OFF) \
    u32 NAME(char *p) { float f = *(float *)(p + OFF); return *(u32 *)&f; }
FBITS(ts4_get_float_bits_off2A54_8828C7C0, 0x8828C7C0, 0x2a54)
FBITS(ts4_get_float_bits_off2F24_8828C978, 0x8828C978, 0x2f24)
FBITS(ts4_get_float_bits_off2F28_8828C9D0, 0x8828C9D0, 0x2f28)
FBITS(ts4_get_float_bits_off2F2C_8828CA28, 0x8828CA28, 0x2f2c)
FBITS(ts4_get_float_bits_off2980_8828D070, 0x8828D070, 0x2980)
FBITS(ts4_get_float_bits_off297C_8828D0A8, 0x8828D0A8, 0x297c)

/* one-bit flag stores */
typedef struct { char pad[0x20]; unsigned short a : 15; unsigned short b : 1; } ts4_h20;
void ts4_set_bit_h20_881F5A58(ts4_h20 *p, unsigned short v) { p->b = v; }
typedef struct { char pad[0x7c]; unsigned char a : 3; unsigned char b : 1; unsigned char c : 4; unsigned char d : 1; unsigned char e : 1; unsigned char f : 6; } ts4_f7c;
void ts4_set_flag_7c_881DB970(ts4_f7c *p, unsigned char v) { p->b = v; }
void ts4_set_flag_7d_881DB988(ts4_f7c *p, unsigned char v) { p->e = v; }

typedef struct { int pad[2]; int *begin; int *end; } ts4_range;
#define RSIZE(NAME, ADDR, MUL) \
    int NAME(ts4_range *r) { int n = (int)(r->end - r->begin); return n * MUL; }
RSIZE(ts4_range_size_x16_88174980, 0x88174980, 16)
RSIZE(ts4_range_size_x4_88176198, 0x88176198, 4)
RSIZE(ts4_range_size_x8_88176A88, 0x88176A88, 8)
