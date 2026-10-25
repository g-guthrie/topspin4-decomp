unsigned int fn_8828D318(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 12028);
    return ((v << 15) | (v >> 17)) & 0x00000007u;
}
