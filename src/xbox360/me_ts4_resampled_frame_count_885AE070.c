/* 0x885AE070: Converts a positive frame count for the resampler: doubled when +0x13c is set, else scaled as (multiplier * frames - offset) / divisor + 1 when +0x144 is set; otherwise returns it unchanged. */
/* Matched on /Oc (agAH). Single result variable with an if / else-if chain (mr r3,r4 up front). */
typedef struct Resampler {
    char pad[0x13c];
    int doubled;
    char pad140[4];
    int scaled;
    int divisor;
    int multiplier;
    char pad150[4];
    int offset;
} Resampler;
int fn_885AE070(Resampler *r, int frames)
{
    int out = frames;
    if (r->doubled != 0 && out > 0)
        out = out * 2;
    else if (r->scaled != 0 && out > 0)
        out = (r->multiplier * out - r->offset) / r->divisor + 1;
    return out;
}
