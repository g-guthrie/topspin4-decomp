/*
 * 0x88655310: Ts4ByteRing::Write - copies `n` bytes into a circular byte buffer at the write cursor,
 * wrapping to the start when the tail is too short, and advances the cursor (back to 0 when the
 * write ends exactly at the buffer end).
 *
 * Layout from the loads: data +0x00, size +0x04, (unused here) +0x08, write cursor +0x0C.
 *
 * Codegen: must be a C++ member. The free-function C form (drafts/me_88655310_nearmiss.c) is 1 off:
 * `add r3,r11,r10` (cursor + data) comes out with the operands swapped; the this-relative member
 * form emits the target order.
 */
#ifdef _MSC_VER
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);
#else
#include <string.h>
#endif

struct Ts4ByteRing {
    unsigned char *data;  /* +0x00 */
    unsigned int size;    /* +0x04 */
    unsigned int unk08;   /* +0x08 */
    unsigned int pos;     /* +0x0C */
    void Write(const unsigned char *src, unsigned int n);
};

void Ts4ByteRing::Write(const unsigned char *src, unsigned int n)
{
    unsigned int room = size - pos;
    if (n <= room) {
        unsigned int end = pos + n;
        memcpy(data + pos, src, n);
        pos = (end == size) ? 0 : end;
    } else {
        memcpy(data + pos, src, room);
        n -= room;
        memcpy(data, src + room, n);
        pos = n;
    }
}
