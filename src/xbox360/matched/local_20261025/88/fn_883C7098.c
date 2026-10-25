unsigned int fn_883C7098(const void *p) {
    unsigned int x = *(const unsigned short *)((const unsigned char *)p + 100);
    return ((x << 27) | (x >> 5)) & 0x00000001u;
}
