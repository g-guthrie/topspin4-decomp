unsigned int fn_8828BC40(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 12028);
    return ((v << 1) | (v >> 31)) & 0x00000001u;
}
