/* Loader_DLL.xex 0x830DEA58-0x83158BF8, executable version 0.0.0.3. */

unsigned long long ts4l_make_bit_mask64_830DEA58(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

unsigned long long ts4l_make_bit_mask64_830E10D8(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

unsigned int ts4l_update_flags64_830F7EA8(char * a3, int a4)
{
    unsigned int t0;
    unsigned int t1;
    t0 = *(unsigned int *)(a3 + 512);
    *(unsigned int *)(a3 + (t0 << 4)) = 4;
    *(unsigned long long *)((a3 + (t0 << 4)) + 8) = (long long)(a4);
    t1 = *(unsigned int *)(a3 + 512);
    *(unsigned int *)(a3 + 512) = (t1 + (unsigned int)(1));
    return t1;
}

unsigned int ts4l_update_flags64_830FAF60(char * a3)
{
    unsigned long long t0;
    t0 = *(unsigned long long *)(a3 + 8);
    return ((unsigned int)(t0) & 0xFFFFFFFFU);
}

unsigned int ts4l_update_flags64_830FAFB0(char * a3)
{
    unsigned long long t0;
    t0 = *(unsigned long long *)(a3 + 8);
    return ((unsigned int)(t0) & 0xFFFFFFFFU);
}

unsigned int ts4l_field_op_830FBB58(unsigned int a3)
{
    return ((a3 & 0xFFFFU) << 3);
}

unsigned int ts4l_field_op_83114360(char * a3, unsigned int a4)
{
    unsigned int t0;
    t0 = *(volatile unsigned int *)(a3 + 4);
    return ((a4 << 2) + t0);
}

unsigned int ts4l_field_op_831143A0(char * a3, unsigned int a4)
{
    unsigned int t0;
    t0 = *(volatile unsigned int *)(a3 + 4);
    return ((a4 << 3) + t0);
}

extern char lbl_830009E0[];
extern char lbl_830009E8[];
float ts4l_float_op_8311ADF8(char * a3, char * a4, float fa1)
{
    float t0;
    float t1;
    float t2;
    float t3;
    t0 = *(float *)(a4 + 4);
    t1 = *(float *)(a3 + 4);
    t2 = *(float *)lbl_830009E0;
    t3 = *(float *)lbl_830009E8;
    return ((((((t1 * (t2 - fa1)) + (t0 * fa1)) * (t2 - fa1)) * fa1) * t3) + ((fa1 * fa1) * fa1));
}

unsigned int ts4l_field_op_8311CF58(char * a3, unsigned int a4)
{
    unsigned int t0;
    t0 = *(volatile unsigned int *)(a3 + 4);
    return ((a4 << 2) + t0);
}

unsigned int ts4l_field_op_8311E760(char * a3, unsigned int a4)
{
    unsigned int t0;
    t0 = *(volatile unsigned int *)(a3 + 4);
    return ((a4 << 2) + t0);
}

float ts4l_float_op_83122F58(char * a3)
{
    float t0;
    float t1;
    t0 = *(float *)(a3 + 4);
    t1 = *(float *)a3;
    return ((t1 * t1) + (t0 * t0));
}

float ts4l_float_op_83122F70(char * a3, char * a4)
{
    float t0;
    float t1;
    float t2;
    float t3;
    t0 = *(float *)a4;
    t1 = *(float *)a3;
    t2 = *(float *)(a3 + 4);
    t3 = *(float *)(a4 + 4);
    return ((t2 * t3) + (t1 * t0));
}

unsigned int ts4l_field_op_8313F310(char * a3, unsigned int a4)
{
    unsigned int t0;
    t0 = *(volatile unsigned int *)(a3 + 4);
    return ((a4 << 2) + t0);
}

unsigned int ts4l_field_op_83141D10(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    t0 = *(volatile unsigned int *)(a3 + 8);
    t1 = *(volatile unsigned int *)(((char *)(unsigned long)((a4 << 2)) + t0));
    t2 = *(volatile unsigned int *)((char *)(unsigned long)(t1) + 4);
    return t2;
}

unsigned int ts4l_field_op_831431E8(char * a3, unsigned int a4)
{
    unsigned int t0;
    t0 = *(volatile unsigned int *)(a3 + 4);
    return ((a4 << 2) + t0);
}

unsigned int ts4l_field_op_831452F0(char * a3, unsigned int a4)
{
    unsigned int t0;
    t0 = *(volatile unsigned int *)(a3 + 4);
    return ((a4 << 2) + t0);
}

extern char lbl_83003F10[];
unsigned int ts4l_field_op_8314C590(unsigned int a3)
{
    unsigned int t0;
    t0 = *(unsigned int *)(((char *)lbl_83003F10 + ((a3 & 0x3U) << 2)));
    return t0;
}

int ts4l_forward_call_8314C8B8(char * a3, unsigned int a4, char * a5, unsigned int a6, unsigned int a7, unsigned int a8)
{
    unsigned int t0;
    unsigned int t1;
    *(unsigned int *)a5 = 1;
    t0 = *(unsigned int *)a3;
    t1 = *(unsigned int *)((char *)(unsigned long)(t0) + 216);
    return ((int (*)())(unsigned long)(t1))(a3, a4, a6, a7, a8);
}

extern char lbl_835312BC[];
unsigned int ts4l_forward_call_8314DA50(unsigned int a3, unsigned int a4)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    t0 = *(volatile unsigned int *)lbl_835312BC;
    if (!t0) {
        return a3;
    }
    t1 = *(volatile unsigned int *)(char *)(unsigned long)(t0);
    t2 = *(volatile unsigned int *)((char *)(unsigned long)(t1) + 16);
    return (unsigned int)(((int (*)())(unsigned long)(t2))(t0, a3, a4));
}

extern char lbl_835312BC[];
unsigned int ts4l_forward_call_8314E128(unsigned int a3)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    t0 = *(volatile unsigned int *)lbl_835312BC;
    if (!t0) {
        return 0x8000FFFFU;
    }
    t1 = *(volatile unsigned int *)(char *)(unsigned long)(t0);
    t2 = *(volatile unsigned int *)((char *)(unsigned long)(t1) + 20);
    return (unsigned int)(((int (*)())(unsigned long)(t2))(t0, a3));
}

extern char lbl_835312C4[];
unsigned int ts4l_forward_call_8314E160(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    t0 = *(volatile unsigned int *)lbl_835312C4;
    if (!t0) {
        return 0x8000FFFFU;
    }
    t1 = *(volatile unsigned int *)(char *)(unsigned long)(t0);
    t2 = *(volatile unsigned int *)((char *)(unsigned long)(t1) + 216);
    return (unsigned int)(((int (*)())(unsigned long)(t2))(t0, a3, a4, a5, a6));
}

unsigned long long ts4l_make_bit_mask64_83158A00(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

unsigned long long ts4l_make_bit_mask64_83158A58(unsigned int a3)
{
    return (0x8000000000000000ULL >> (unsigned long long)((a3 + (unsigned int)(32))));
}

void ts4l_update_bit_range_mask_83158A88(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24))));
    *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24)))) = ((t0 & 0xFFFFE3FFU) | (((a5 << 10) | (a5 >> 22)) & 0x1C00U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_83158AC0(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24))));
    *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24)))) = ((t0 & 0xFFFF1FFFU) | (((a5 << 13) | (a5 >> 19)) & 0xE000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_83158AF8(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24))));
    *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24)))) = ((t0 & 0xFFF8FFFFU) | (((a5 << 16) | (a5 >> 16)) & 0x70000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_83158B30(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1164);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1164) = ((t0 & 0xFE7FFFFFU) | (((a5 << 23) | (a5 >> 9)) & 0x1800000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_83158BB8(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1172);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1172) = ((t0 & 0xFFFFFFE7U) | (((a5 << 3) | (a5 >> 29)) & 0x18U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_83158BF8(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1168);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1168) = ((t0 & 0xF83FFFFFU) | (((a5 << 22) | (a5 >> 10)) & 0x7C00000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}
