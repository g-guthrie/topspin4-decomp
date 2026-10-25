unsigned int fn_8828D378(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10560);
    return ((v << 30) | (v >> 2)) & 0x00000001u;
}
