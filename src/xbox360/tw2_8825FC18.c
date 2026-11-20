/* Twin of 0x88233FE0 (ts4_clear_rec3c_vectors_88233FE0 in src/xbox360/cw16_core_b.c). 0x24-byte records, vbegin at +8, vend at +0xc. */
/* CW16 part b: game core loaders/resources (0x88229BD8-0x88258E50), range helpers. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CW16_INL static __forceinline
typedef unsigned int Cw16Up;
#else
#define CW16_INL static inline
typedef unsigned long Cw16Up;
#endif

extern void *fn_88562DC0(void *dst, const void *src, u32 n);
typedef struct Cw16Rec24 { u8 pad[8]; char *vbegin; char *vend; u8 pad2[0x24 - 0x10]; } Cw16Rec24;
CW16_INL char *cw16_copy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        u32 n = (u32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}

void ts4_clear_rec3c_vectors_8825FC18(Cw16Rec24 *first, Cw16Rec24 *last)
{
    if (first != last) {
        do {
            first->vend = cw16_copy(first->vend, first->vend, first->vbegin);
            first++;
        } while (first != last);
    }
}
