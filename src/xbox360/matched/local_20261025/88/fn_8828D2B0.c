unsigned int fn_8828D2B0(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 12028);
    return ((v << 12) | (v >> 20)) & 0x00000007u;
}
