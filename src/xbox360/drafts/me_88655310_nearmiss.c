/* NEAR MISS (1 instruction): `add r3,r11,r10` (pos + data) is emitted as (data, pos); no source
 * form, helper or pad count flips it (operands loaded straight off the parameter). */
/* 0x88655310: writes `n` bytes into a circular byte buffer at the write cursor, wrapping to the
 * start when the tail is too short, and advances the cursor (back to 0 at the exact end). */
typedef struct Ring { unsigned char *data; unsigned int size; unsigned int pad; unsigned int pos; } Ring;
void *memcpy(void *d, const void *s, unsigned int n);
void ts4_ring_write_88655310(Ring *r, const unsigned char *src, unsigned int n)
{
    unsigned int room = r->size - r->pos;
    if (n <= room) {
        unsigned int pos = r->pos + n;
        memcpy(r->data + r->pos, src, n);
        r->pos = (pos == r->size) ? 0 : pos;
    } else {
        memcpy(r->data + r->pos, src, room);
        n -= room;
        memcpy(r->data, src + room, n);
        r->pos = n;
    }
}
