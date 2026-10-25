unsigned int fn_8828CD68(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10544);
    return ((v << 12) | (v >> 20)) & 0x0000000Fu;
}
