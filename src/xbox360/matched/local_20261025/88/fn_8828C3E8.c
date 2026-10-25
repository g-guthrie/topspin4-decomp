unsigned int fn_8828C3E8(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10548);
    return ((v << 21) | (v >> 11)) & 0x00000007u;
}
