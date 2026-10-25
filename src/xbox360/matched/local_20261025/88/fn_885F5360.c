unsigned int fn_885F5360(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 16);
    return ((v << 29) | (v >> 3)) & 0x0000FFFFu;
}
