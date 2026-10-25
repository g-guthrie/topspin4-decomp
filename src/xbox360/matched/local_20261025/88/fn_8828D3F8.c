unsigned int fn_8828D3F8(void *p) {
    unsigned int v = *(unsigned int *)((unsigned char *)p + 12028);
    return ((v << 9) | (v >> 23)) & 0x0000007Fu;
}
