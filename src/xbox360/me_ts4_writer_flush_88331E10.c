/* Swing_DLL.xex 0x88331E10: flushes the buffered bytes cur..end (+0x1C/+0x18) to the file (+0x10) through fn_8838DCD0 in chunks of
 * at most 0x4000, then resets both to base (+0x14). Skipped when flags bit 0 is set. agAE: /Oc. */
typedef struct Writer {
    char pad[0xc]; unsigned int flags; void *file; char *base; char *end; char *cur;
} Writer;
int fn_8838DCD0(void *file, const void *data, unsigned int size, unsigned int *written);
int fn_88331E10(Writer *w)
{
    unsigned int written = 0;
    unsigned int left = w->end - w->cur;
    int hr;
    if (!(w->flags & 1) && left) {
        do {
            hr = fn_8838DCD0(w->file, w->cur, left > 0x4000 ? 0x4000 : left, &written);
            if (hr) return hr;
            left -= written;
            w->cur += written;
        } while (left);
        w->end = w->base;
        w->cur = w->base;
    }
    return 0;
}
