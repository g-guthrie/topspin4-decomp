unsigned int fn_8828CCE8(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10540);
    return ((v << 12) | (v >> 20)) & 0x0000000Fu;
}
