/* Swing_DLL.xex 0x885983D0-0x88598458, executable version 0.0.0.3. */
typedef unsigned int u32;

/* Map a sample rate in Hz to a small rate-class code; unknown rates map to 8. */
u32 ts4_sample_rate_code_885983D0(void *unused, u32 rate)
{
    (void)unused;
    if (rate == 0x566d) return 3;
    if (rate == 0xab63) return 6;
    if (rate == 0xbb80) return 7;
    if (rate == 0x2bf2) return 1;
    if (rate == 0x7dfa) return 5;
    if (rate == 0x5dc0) return 4;
    if (rate == 0x3efd) return 2;
    return rate != 0x203a ? 8 : 0;
}
