unsigned int fn_8828BFD8(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 12028);
    return ((v << 2) | (v >> 30)) & 0x00000001u;
}
