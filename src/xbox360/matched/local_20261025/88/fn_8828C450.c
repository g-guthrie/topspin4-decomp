unsigned int fn_8828C450(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10548);
    return ((v << 18) | (v >> 14)) & 0x00000007u;
}
