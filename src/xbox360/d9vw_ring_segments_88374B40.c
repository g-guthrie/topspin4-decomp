/* Swing_DLL.xex 0x88374B40-0x88374BD4, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4VwRing { char pad[0x2a0]; u32 size; u32 data; } Ts4VwRing;
int ts4_ring_segments_88374B40(char *iface, u32 pos, u32 len, u32 *p1, u32 *l1, u32 *p2, u32 *l2)
{
    Ts4VwRing *r = iface != 0 ? (Ts4VwRing *)(iface - 0x1c) : 0;
    u32 off = pos % r->size;
    if (off + len > r->size) {
        *p1 = r->data + off;
        *l1 = r->data;
        *p2 = r->size - off;
        *l2 = len + off - r->size;
        return 0;
    }
    *p1 = r->data + off;
    *l1 = 0;
    *p2 = len;
    *l2 = 0;
    return 0;
}
