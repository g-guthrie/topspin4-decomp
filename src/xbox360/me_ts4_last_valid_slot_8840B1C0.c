/* 0x8840B1C0: Returns the highest index whose slot id is in [0, limit) and whose enabled flag (if any) is set, or -1; with no slot table it returns min(count, limit) - 1. */
/* Matched on /Oc /O2 (agAH). Plain backward for loop with a combined && condition; the null-table path as a ternary min. Matches /Oc and /O2. */
int fn_8840B1C0(const short *slots, const unsigned char *enabled, unsigned int limit, int count)
{
    int i;
    if (slots == 0) {
        int last = (int)limit - 1;
        int n = count - 1;
        return n < last ? n : last;
    }
    for (i = count - 1; i >= 0; i--) {
        int v = slots[i];
        if (v >= 0 && (unsigned int)v < limit && (enabled == 0 || enabled[i] != 0))
            return i;
    }
    return -1;
}
