unsigned int fn_8828BCD0(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 12024);
    return ((v << 27) | (v >> 5)) & 0x00000007u;
}
