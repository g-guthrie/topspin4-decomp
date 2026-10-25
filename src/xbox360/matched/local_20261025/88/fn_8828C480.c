unsigned int fn_8828C480(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10548);
    return ((v << 12) | (v >> 20)) & 0x00000007u;
}
