unsigned int fn_8828CCC8(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10540);
    return ((v << 20) | (v >> 12)) & 0x0000000Fu;
}
