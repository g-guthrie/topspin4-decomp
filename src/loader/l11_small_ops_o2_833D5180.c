/* Loader_DLL.xex 0x833D5180-0x833DBC30, executable version 0.0.0.3. */

void ts4l_update_bit_range_mask_833D5180(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFF8FFFFU) | (((a5 << 16) | (a5 >> 16)) & 0x70000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

extern int fn_830B3558();
int ts4l_forward_call_833D53C8(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
    return fn_830B3558(a3, a4, a5, a6, a7, (0x8000000000000000ULL >> (unsigned long long)((((((unsigned int)(95) - a4) * (unsigned int)(21846)) >> 16) + (unsigned int)(32)))));
}

extern int fn_830AE288();
int ts4l_forward_call_833D53F0(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return fn_830AE288(a3, a4, a5, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
}

unsigned long long ts4l_make_bit_mask64_833D7148(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

unsigned long long ts4l_make_bit_mask64_833D71A0(unsigned int a3)
{
    return (0x8000000000000000ULL >> (unsigned long long)((a3 + (unsigned int)(32))));
}

void ts4l_update_bit_range_mask_833D78A0(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFFE3FFU) | (((a5 << 10) | (a5 >> 22)) & 0x1C00U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_833D78E0(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFF1FFFU) | (((a5 << 13) | (a5 >> 19)) & 0xE000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_833D7980(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFF8FFFFU) | (((a5 << 16) | (a5 >> 16)) & 0x70000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

extern int fn_830B3558();
int ts4l_forward_call_833D7C00(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
    return fn_830B3558(a3, a4, a5, a6, a7, (0x8000000000000000ULL >> (unsigned long long)((((((unsigned int)(95) - a4) * (unsigned int)(21846)) >> 16) + (unsigned int)(32)))));
}

extern int fn_830AE288();
int ts4l_forward_call_833D7C28(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return fn_830AE288(a3, a4, a5, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
}

unsigned long long ts4l_make_bit_mask64_833DB8E0(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

unsigned long long ts4l_make_bit_mask64_833DB938(unsigned int a3)
{
    return (0x8000000000000000ULL >> (unsigned long long)((a3 + (unsigned int)(32))));
}

void ts4l_update_bit_range_mask_833DB968(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFFE3FFU) | (((a5 << 10) | (a5 >> 22)) & 0x1C00U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_833DB9A8(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFF1FFFU) | (((a5 << 13) | (a5 >> 19)) & 0xE000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_833DB9E8(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFF8FFFFU) | (((a5 << 16) | (a5 >> 16)) & 0x70000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

extern int fn_830AE288();
int ts4l_forward_call_833DBC30(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return fn_830AE288(a3, a4, a5, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
}
