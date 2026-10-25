unsigned int fn_8828C380(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10548);
    return ((v << 25) | (v >> 7)) & 0x00000001u;
}
