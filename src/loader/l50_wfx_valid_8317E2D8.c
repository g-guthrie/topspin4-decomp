/* Loader_DLL.xex 0x8317E2D8-0x8317E3A4 and copy, executable version 0.0.0.3. */
typedef struct a4_wfx {
    unsigned short tag;
    unsigned short channels;
    unsigned long rate;
    unsigned long avg;
    unsigned short align;
    unsigned short bits;
    unsigned short cb;
    unsigned short valid;
} a4_wfx;

int ts4l_wfx_valid_8317E2D8(const a4_wfx *w)
{
    unsigned short bits;
    unsigned short v;
    int ok;
    ok = 1;
    bits = w->bits;
    if (bits != 8 && bits != 16 && bits != 24 && bits != 32) {
        ok = 0;
    }
    if (w->tag == 0xfffe) {
        v = w->valid;
        if (v != 0 && v != 8 && v != 16 && v != 20 && v != 24 && v != 32) {
            ok = 0;
        }
        if (v > bits) {
            ok = 0;
        }
    }
    if (w->align != (w->channels * bits) / 8) {
        ok = 0;
    }
    if (w->avg != w->rate * w->align) {
        ok = 0;
    }
    return ok;
}

int ts4l_wfx_valid_831A2EC8(const a4_wfx *w)
{
    unsigned short bits;
    unsigned short v;
    int ok;
    ok = 1;
    bits = w->bits;
    if (bits != 8 && bits != 16 && bits != 24 && bits != 32) {
        ok = 0;
    }
    if (w->tag == 0xfffe) {
        v = w->valid;
        if (v != 0 && v != 8 && v != 16 && v != 20 && v != 24 && v != 32) {
            ok = 0;
        }
        if (v > bits) {
            ok = 0;
        }
    }
    if (w->align != (w->channels * bits) / 8) {
        ok = 0;
    }
    if (w->avg != w->rate * w->align) {
        ok = 0;
    }
    return ok;
}
