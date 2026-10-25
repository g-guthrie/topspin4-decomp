unsigned int fn_8828BE60(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 12024);
    return ((v << 11) | (v >> 21)) & 0x00000007u;
}
