unsigned int fn_8828C308(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 10548);
    return ((v << 28) | (v >> 4)) & 0x00000007u;
}
