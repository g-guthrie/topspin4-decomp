/* 0x882B0290: index of the 16-bit level (scaled by 1/65535) of eight nearest to x, by squared distance */
/* Matched on /O1 (agAH). /O1 (/Oc unrolls the loop); 1/65535 literal for the 0x88001B00 constant. */
int fn_882B0290(const unsigned short *levels, float x)
{
    int best = 0, i;
    float d, bd = (x - (float)levels[0] * (1.0f / 65535.0f)) * (x - (float)levels[0] * (1.0f / 65535.0f));
    for (i = 1; i < 8; i++) {
        d = (x - (float)levels[i] * (1.0f / 65535.0f)) * (x - (float)levels[i] * (1.0f / 65535.0f));
        if (d < bd) {
            bd = d;
            best = i;
        }
    }
    return best;
}
