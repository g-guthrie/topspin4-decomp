/* Twin of 0x889C0998 (ts4_nonzero_mask_889C0998 in src/xbox360/w2c_misc.c). */
#include "w2c_types.h"
extern unsigned long ts4_if_call_seq_u32_off44_8864BB40(unsigned long a, unsigned long b);

int ts4_nonzero_mask_889BFA88(unsigned long a, unsigned long b)
{
    return 0 != ts4_if_call_seq_u32_off44_8864BB40(a, b) ? -1 : 0;
}
