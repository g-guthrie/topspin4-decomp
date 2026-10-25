unsigned int fn_8828CD88(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10544);
    return ((v << 4) | (v >> 28)) & 0x0000000Fu;
}
