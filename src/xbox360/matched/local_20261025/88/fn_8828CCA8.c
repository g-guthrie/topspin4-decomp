unsigned int fn_8828CCA8(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10540);
    return ((v << 28) | (v >> 4)) & 0x0000000Fu;
}
