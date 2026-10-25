unsigned int fn_8828C7F0(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10568);
    return ((v << 17) | (v >> 15)) & 0x00000001u;
}
