/* Swing_DLL.xex 0x8858BC98-0x8858BFCC, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif

extern int ts4_forward_8858C248(char *state);
extern void ts4_call_seq_fn_8858C9E8_8858C698(char *state);

/* Clear a block of cached state selected by the flag word at +8 (bit 0 = partial, bit 31 = full). */
int ts4_reset_state_by_flags_8858BC98(char *o)
{
    char *p = o + 0x10;
    u32 fl;
    ts4_forward_8858C248(p);
    fl = *(u32 *)(o + 8);
    if (fl & 1) {
        *(u32 *)(p + 0x4350) = 0;
        *(u32 *)(p + 0x4360) = 0;
        *(u32 *)(p + 0x4364) = 0;
    } else if (fl & 0x80000000) {
        *(u32 *)(p + 0x4348) = 0;
        *(u64 *)(p + 0x4350) = 0;
        *(u64 *)(p + 0x4358) = 0;
        *(u32 *)(p + 0x4368) = 0;
        *(u32 *)(p + 0x436c) = 0;
        *(u32 *)(p + 0x4370) = 0;
        *(u32 *)(p + 0x4374) = 0;
        *(u8 *)(p + 0x4378) = 0;
        *(u32 *)(p + 0x4364) = 0;
    }
    return 0;
}

/* Same shape for the neighbouring state block. */
int ts4_reset_state_by_flags_8858BF48(char *o)
{
    char *p = o + 0x14;
    u32 fl;
    ts4_call_seq_fn_8858C9E8_8858C698(p);
    fl = *(u32 *)(o + 8);
    if (fl & 1) {
        *(u8 *)(p + 0x2ffc) = 0;
        *(u32 *)(p + 0x2ff8) = 0;
        *(u32 *)(p + 0x2ff0) = 0;
        *(u32 *)(p + 0x2fec) = 0;
    } else if (fl & 0x80000000) {
        *(u32 *)(p + 0x2ff4) = 0;
        *(u32 *)(p + 0x2ffc) = 0;
        *(u32 *)(p + 0x3000) = 0;
        *(u32 *)(p + 0x3004) = 0;
        *(u32 *)(p + 0x3008) = 0;
        *(u32 *)(p + 0x2fec) = 0;
        *(u32 *)(p + 0x2ff0) = 0;
        *(u32 *)(p + 0x2ff8) = 0;
    }
    return 0;
}
