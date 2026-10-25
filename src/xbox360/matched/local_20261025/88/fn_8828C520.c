unsigned int fn_8828C520(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10548);
    return ((v << 6) | (v >> 26)) & 0x00000007u;
}
