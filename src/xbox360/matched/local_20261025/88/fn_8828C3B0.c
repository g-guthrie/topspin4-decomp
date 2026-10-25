unsigned int fn_8828C3B0(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10548);
    return ((v << 24) | (v >> 8)) & 0x00000007u;
}
