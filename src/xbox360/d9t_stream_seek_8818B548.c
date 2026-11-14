/* Swing_DLL.xex 0x8818B548-0x8818B58C, executable version 0.0.0.3. */
typedef struct Ts4Stream { char pad[0x14]; int pos; int pad2; int size; } Ts4Stream;
int ts4_stream_seek_8818B548(Ts4Stream *s, int off, unsigned whence)
{
    int base = s->pos;
    int r = off;
    if (whence == 0) {
    } else if (whence == 1 || whence == 2) {
        if (whence == 2) base = s->size;
        r = base + off;
    } else {
        r = -1;
    }
    if (r >= 0) {
        s->pos = r;
        return r;
    }
    return -1;
}
