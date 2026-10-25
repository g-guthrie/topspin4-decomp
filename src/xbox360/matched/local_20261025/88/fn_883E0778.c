unsigned int fn_883E0778(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 0);
    return ((v << 28) | (v >> 4)) & 0x00000007u;
}
