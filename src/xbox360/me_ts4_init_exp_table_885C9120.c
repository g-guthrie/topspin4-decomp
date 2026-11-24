/* 0x885C9120: One-time init of a 256-entry table at lbl_88D2F7A0: entry i = ((i & 31) + 32) << (((signed char)i >> 5) + 15), a 3-bit-exponent / 5-bit-mantissa decode table; sets lbl_88D2FBA0 and returns 0. */
/* Matched on /Oc (agAH). Plain loop; the (signed char) cast gives the extsb/srawi. */
extern int lbl_88D2FBA0;
extern unsigned int lbl_88D2F7A0[256];
int fn_885C9120(void)
{
    int i;
    if (lbl_88D2FBA0 == 0) {
        for (i = 0; i < 256; i++)
            lbl_88D2F7A0[i] = ((i & 31) + 32) << (((signed char)i >> 5) + 15);
        lbl_88D2FBA0 = 1;
    }
    return 0;
}
