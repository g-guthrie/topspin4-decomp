/* Swing_DLL.xex 0x8865FEC0-0x8865FF8C, executable version 0.0.0.3. */

typedef unsigned int u32;

typedef struct Ts4RingSlot {
    unsigned char reserved0[0x39];
    unsigned char active;
    unsigned char reserved1[6];
} Ts4RingSlot;

typedef struct Ts4Ring {
    unsigned char reserved0[0x10];
    u32 start;
    u32 count;
    unsigned char reserved1[0x71];
    unsigned char slots[20][0x30];
} Ts4Ring;

void ts4_ring_trim_active_span_8865FEC0(Ts4Ring *ring)
{
    unsigned char found = 0;
    u32 first = 0;
    u32 last = 0;
    u32 end = ring->start + ring->count;
    u32 index = ring->start;

    for (; index < end; index++) {
        if (ring->slots[index % 20][0] != 0) {
            if (!found) {
                found = 1;
                first = index;
            }
            last = index;
        }
    }
    if (found) {
        ring->count = last - first + 1;
        ring->start = first % 20;
    } else {
        ring->start = 0;
        ring->count = 0;
    }
}
