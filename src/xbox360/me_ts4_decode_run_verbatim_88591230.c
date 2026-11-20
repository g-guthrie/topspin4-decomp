/* Swing_DLL.xex 0x88591230: decode a run: positions below 257 through fn_88590BF8 (records the new position), the rest through fn_88590EB8
 * /O1 */
typedef unsigned char u8;
typedef struct Decoder { u8 pad[0x2EB8]; int position; } Decoder;

int fn_88590BF8(Decoder *d, int pos, int count);
int fn_88590EB8(Decoder *d, int pos, int count);

/* Decode the first 257 positions with the start-up decoder, the rest with the main one. */
int fn_88591230(Decoder *d, int pos, int count)
{
    if (pos < 0x101) {
        int n = 0x101 - pos;
        int newPos;
        if (n >= count)
            n = count;
        newPos = fn_88590BF8(d, pos, n);
        d->position = newPos;
        count += pos - newPos;
        pos = newPos;
        if (count <= 0)
            return count;
    }
    return fn_88590EB8(d, pos, count);
}
