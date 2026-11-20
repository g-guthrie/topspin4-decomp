/* Loader_DLL.xex 0x830A02B0-0x8347F928, executable version 0.0.0.3.
 * Small thunks and accessors (same code as the Swing_DLL.xex copies). */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
typedef struct __declspec(passinreg) __vector4 { float v[4]; } __vector4;
__vector4 __vxor(__vector4 a, __vector4 b);
#pragma intrinsic(__vxor)
extern double fabs(double x);
#pragma intrinsic(fabs)
#else
typedef unsigned long long ts4l_u64;
typedef struct __vector4 { float v[4]; } __vector4;
#define __vxor(a, b) ((void)(b), (a))
#include <math.h>
#endif
typedef unsigned int u32;
typedef unsigned long ts4l_word;

#ifndef _MSC_VER
#define memcpy ts4l_host_memcpy
#endif
ts4l_word memcpy();
void fn_83162DF0(void *object);
void fn_8340BD08(ts4l_u64 *out);
void fn_831AF940(int a, int b, int c, int d);
ts4l_word fn_83430B48();
ts4l_word fn_83477E40();
ts4l_word fn_833F25C8();
ts4l_word fn_833F26A0();
ts4l_word fn_833F2000();
ts4l_word fn_833F1F08();

/* Calls fn on each of count elements spaced stride bytes apart. */
void ts4l_call_for_each_strided_830A02B0(char *p, u32 stride, int count, void (*fn)(void *))
{
    int i;
    for (i = count - 1; i >= 0; --i) {
        fn(p);
        p += stride;
    }
}

__vector4 ts4l_vec_xor_830B62D0(__vector4 a, __vector4 b) { return __vxor(a, b); }

double ts4l_fabs_830D5D60(double x) { return fabs(x); }

double ts4l_fabs_830D5D68(double x) { return fabs(x); }

void ts4l_destroy_field0_83162EC0(char *p) { if (*(void **)p) fn_83162DF0(*(void **)p); }

ts4l_u64 ts4l_call_with_out_u64_return_it_83173850(void)
{
    ts4l_u64 v;
    fn_8340BD08(&v);
    return v;
}

void ts4l_call_with_u16_fields_83186510(char *p, int b) { fn_831AF940(*(unsigned short *)(p + 6), *(unsigned short *)(p + 4), b, 0); }

int ts4l_is_id_165_to_167_831CC988(unsigned short x)
{
    return x == 0x165 || x == 0x166 || x == 0x167;
}

int ts4l_is_id_165_to_167_832676F0(unsigned short x)
{
    return x == 0x165 || x == 0x166 || x == 0x167;
}

ts4l_word ts4l_if_tail_833F27D8(ts4l_word a0, ts4l_word a1, ts4l_word a2, int a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    if ((int)a3 != 101 && (int)a3 != 69) {
        if ((int)a3 == 102) {
            return fn_833F25C8((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a4, (ts4l_word)a6, (ts4l_word)a6);
        }
        if ((int)a3 != 97 && (int)a3 != 65) {
            return fn_833F26A0((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a4, (ts4l_word)a5, (ts4l_word)a6);
        }
        return fn_833F2000((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a4, (ts4l_word)a5, (ts4l_word)a6);
    }
    return fn_833F1F08((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a4, (ts4l_word)a5, (ts4l_word)a6);
}

ts4l_word ts4l_if_call_seq_u32_off10_834385B0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    int t1;
    ts4l_word t2;
    ts4l_word t5;
    ts4l_word t6;
    ts4l_word t7;
    ts4l_word t9;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 16);
    p4 = (ts4l_word)a3;
    if ((int)t1 != 0) {
        t2 = fn_83430B48();
        p4 = (ts4l_word)t2;
    }
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 96);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 100);
    t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 104);
    t9 = memcpy((ts4l_word)((((int)t5 * (int)a1) + ((int)t6 * (int)a2)) + (*(ts4l_word *)((char *)(ts4l_word)(a0) + 32))), (ts4l_word)p4, (ts4l_word)(t7 << 4));
    return t9;
}

ts4l_word ts4l_if_call_seq_u32_off10_8347F8C8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    int t1;
    ts4l_word t2;
    ts4l_word t5;
    ts4l_word t6;
    ts4l_word t7;
    ts4l_word t9;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 16);
    p4 = (ts4l_word)a3;
    if ((int)t1 != 0) {
        t2 = fn_83477E40();
        p4 = (ts4l_word)t2;
    }
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 96);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 100);
    t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 104);
    t9 = memcpy((ts4l_word)((((int)t5 * (int)a1) + ((int)t6 * (int)a2)) + (*(ts4l_word *)((char *)(ts4l_word)(a0) + 32))), (ts4l_word)p4, (ts4l_word)(t7 << 4));
    return t9;
}
