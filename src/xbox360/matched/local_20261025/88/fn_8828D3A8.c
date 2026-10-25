unsigned int fn_8828D3A8(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10560);
    return ((v << 27) | (v >> 5)) & 0x00000001u;
}
