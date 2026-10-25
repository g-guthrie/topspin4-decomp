unsigned int fn_8828CD48(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10544);
    return ((v << 20) | (v >> 12)) & 0x0000000Fu;
}
