unsigned int fn_8828C420(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10548);
    return ((v << 15) | (v >> 17)) & 0x00000007u;
}
