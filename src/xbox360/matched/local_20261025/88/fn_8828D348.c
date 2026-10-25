unsigned int fn_8828D348(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10560);
    return ((v << 29) | (v >> 3)) & 0x00000001u;
}
