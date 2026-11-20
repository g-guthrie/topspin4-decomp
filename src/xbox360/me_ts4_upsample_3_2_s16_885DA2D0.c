/* Swing_DLL.xex 0x885DA2D0: 16-bit PCM 2:3 upsampler, outputs a, (a*2+b)/3-weighted taps (0x1555/0xaab Q13) between input pairs.
 * Leaf; /O1. The final pair is written through *o++ then *o with the last sample in a local. */
void fn_885DA2D0(const short *in, int n, short *out)
{
    int i = 0;
    short *o;
    int last;
    out[0] = in[0];
    o = out + 1;
    for (; i < n - 3; i += 2) {
        int a = in[i], b = in[i + 1], c = in[i + 2];
        *o++ = (short)((a * 0x1555 + b * 0xaab) / 8192);
        *o++ = (short)b;
        *o++ = (short)((c * 0x1555 + b * 0xaab) / 8192);
    }
    last = in[n - 1];
    *o++ = (short)((in[n - 2] * 0x1555 + last * 0xaab) / 8192);
    *o = (short)last;
}
