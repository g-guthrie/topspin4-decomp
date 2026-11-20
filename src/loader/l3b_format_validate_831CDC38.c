/* Loader_DLL.xex 0x831CDC38-0x832689A0, executable version 0.0.0.3.
 * Validate a PCM format description (rate, channels, channel mask, bit depths). */

typedef struct { unsigned rate, ch, mask, bitsA, bytesB; int kind; } Ts4lPcmFmt;

int ts4l_validate_format_831CDC38(void *unused, const Ts4lPcmFmt *f)
{
    unsigned mask;
    unsigned bits;
    (void)unused;
    if (f->rate == 0 || f->rate > 0x5dc00)
        return 0;
    if (f->ch == 0 || f->ch > 0x20)
        return 0;
    mask = f->mask;
    if (mask != 0) {
        unsigned cnt = 0;
        while (mask != 0) {
            if (mask & 1)
                cnt++;
            mask >>= 1;
        }
        if (f->ch != cnt)
            return 0;
    }
    if (f->bitsA == 0)
        return 0;
    if (f->bytesB == 0)
        return 0;
    bits = f->bytesB << 3;
    if (bits < f->bitsA)
        return 0;
    if (f->kind != 0 && f->kind != 1)
        return 0;
    if (f->kind == 1) {
        if (bits != f->bitsA)
            return 0;
        if (f->bitsA > 0x40)
            return 0;
        if ((f->bitsA & 31) != 0)
            return 0;
    } else if (f->kind == 0) {
        if (f->bitsA > 0x20)
            return 0;
    } else {
        return 0;
    }
    return 1;
}

int ts4l_validate_format_832689A0(void *unused, const Ts4lPcmFmt *f)
{
    unsigned mask;
    unsigned bits;
    (void)unused;
    if (f->rate == 0 || f->rate > 0x5dc00)
        return 0;
    if (f->ch == 0 || f->ch > 0x20)
        return 0;
    mask = f->mask;
    if (mask != 0) {
        unsigned cnt = 0;
        while (mask != 0) {
            if (mask & 1)
                cnt++;
            mask >>= 1;
        }
        if (f->ch != cnt)
            return 0;
    }
    if (f->bitsA == 0)
        return 0;
    if (f->bytesB == 0)
        return 0;
    bits = f->bytesB << 3;
    if (bits < f->bitsA)
        return 0;
    if (f->kind != 0 && f->kind != 1)
        return 0;
    if (f->kind == 1) {
        if (bits != f->bitsA)
            return 0;
        if (f->bitsA > 0x40)
            return 0;
        if ((f->bitsA & 31) != 0)
            return 0;
    } else if (f->kind == 0) {
        if (f->bitsA > 0x20)
            return 0;
    } else {
        return 0;
    }
    return 1;
}
