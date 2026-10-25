unsigned int fn_8828C4B8(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10548);
    return ((v << 9) | (v >> 23)) & 0x00000007u;
}
