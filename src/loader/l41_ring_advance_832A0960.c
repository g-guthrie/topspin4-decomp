/* Loader_DLL.xex 0x832A0960-0x832A09E4, executable version 0.0.0.3. */
int ts4l_ring_advance_832A0960(unsigned char *buf, int n, int idx)
{
    int count = 0;
    int last = idx - 1;
    if (last < 0) last = n - 1;
    if ((buf[last] & ~1U) != 0) {
        buf[last] &= 1;
        while (buf[idx] == 1) {
            buf[idx] = 0;
            last = idx;
            idx = (idx + 1) % n;
            count++;
        }
        buf[last] = 2;
    }
    return count;
}
