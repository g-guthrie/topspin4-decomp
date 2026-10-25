unsigned int fn_88606DF0(const void *p) {
    unsigned int x = *(const unsigned short *)((const unsigned char *)p + 138);
    return ((x << 18) | (x >> 14)) & 0x00000001u;
}
