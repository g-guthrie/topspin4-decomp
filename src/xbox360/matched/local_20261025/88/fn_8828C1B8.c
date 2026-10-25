unsigned int fn_8828C1B8(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10680);
    return ((v << 22) | (v >> 10)) & 0x00000001u;
}
