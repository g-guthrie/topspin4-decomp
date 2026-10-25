unsigned int fn_8828BDF0(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 12024);
    return ((v << 24) | (v >> 8)) & 0x0000001Fu;
}
