typedef struct Buf { char pad[0x30]; unsigned int *cur; } Buf;
unsigned int *ts4_buf_reserve_words_882911D0(Buf *b, unsigned int words);
void *memset(void *d, int c, unsigned long n);
void *memcpy(void *d, const void *s, unsigned long n);
int fn_882A2EE8(Buf *b, unsigned int reg, const void *data, unsigned int count)
{
    unsigned int base = reg & ~3u;
    unsigned int pre = (reg - base) * 4;
    unsigned int total = (((reg + count + 3) & ~3u) - base) * 4;
    unsigned int post = total - count * 4 - pre;
    unsigned int *p = ts4_buf_reserve_words_882911D0(b, total + 1);
    if (!p)
        return 0;
    *++p = ((base + 0x1000) << 2) | ((total - 1) << 16);
    if (pre) {
        memset(p + 1, 0, pre * 4);
        p += pre;
    }
    memcpy(p + 1, data, count * 16);
    p += count * 4;
    if (post) {
        memset(p + 1, 0, post * 4);
        p += post;
    }
    b->cur = p;
    return 1;
}
