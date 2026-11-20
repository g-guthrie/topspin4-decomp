struct HP08Hdr { int rel; int count; };
struct HP08El { float f0; float f4; };

void ts4_fill_f4_886616D0(struct HP08Hdr *h)
{
    float k = 1.0f;
    int n = h->count;
    int i = 0;
    int off;
    if (n >= 4) {
        int lim = n - 3;
        off = 0;
        do {
            ((struct HP08El *)((char *)h + (off + h->rel)))->f4 = k;
            ((struct HP08El *)((char *)h + (off + 8 + h->rel)))->f4 = k;
            ((struct HP08El *)((char *)h + (off + 16 + h->rel)))->f4 = k;
            ((struct HP08El *)((char *)h + (off + 24 + h->rel)))->f4 = k;
            off += 32;
            i += 4;
        } while (i < lim);
    }
    if (i < n) {
        int cnt = n - i;
        off = i * 8;
        do {
            ((struct HP08El *)((char *)h + (off + h->rel)))->f4 = k;
            off += 8;
        } while (--cnt != 0);
    }
}
