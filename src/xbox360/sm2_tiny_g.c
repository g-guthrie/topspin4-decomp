/* SM2: bitfield setters, constructors that store a vtable, reset helpers. */
typedef unsigned long long ts4_u64;

extern char lbl_880C84C0[];
extern char lbl_880F4340[];
extern char lbl_880C0FEC[];
extern char lbl_880C0F8C[];
extern char lbl_8803DE18[];
extern char lbl_880898DC[];
extern char lbl_88084C94[];
extern char lbl_88089D90[];
extern float lbl_88001A68;
extern float lbl_88001A20;
extern float g_ts4_script_constants[];
extern char lbl_880D75FC[];

/* 24-byte record whose first word holds three 3-bit fields (MSB-first allocation) */
typedef struct ts4_slot_rec {
    unsigned pad : 13;
    unsigned f1 : 3;
    unsigned f2 : 3;
    unsigned f3 : 3;
    unsigned rest : 10;
    unsigned w[5];
} ts4_slot_rec;

/* set field N of slot i + 0x30 and mark slot i + 0x20 in the 64-bit mask at +0x18 */
#define SET_SLOT_FIELD(NAME, FIELD) \
    void NAME(char *p, int i, int v) \
    { \
        ((ts4_slot_rec *)p)[i + 0x30].FIELD = v; \
        *(ts4_u64 *)(p + 0x18) |= ((ts4_u64)1 << 63) >> (unsigned)(i + 0x20); \
    }
SET_SLOT_FIELD(ts4_set_slot_f1_886EC368, f1)
SET_SLOT_FIELD(ts4_set_slot_f2_886EC3A8, f2)
SET_SLOT_FIELD(ts4_set_slot_f3_886EC3E8, f3)

/* advance a ring cursor by n, wrapping at base + size */
void ts4_ring_advance_88604680(char *p, unsigned n)
{
    unsigned end = *(unsigned *)(p + 4) + *(unsigned *)(p + 0x10);
    unsigned pos = n + *(unsigned *)(p + 0xc);
    *(unsigned *)(p + 0xc) = pos;
    if (pos >= end) *(unsigned *)(p + 0xc) = pos - *(unsigned *)(p + 0x10);
    *(unsigned *)(p + 0x14) += n;
}
/* CRC32 (reflected, init all ones, final complement) over a byte buffer */
unsigned ts4_crc32_88606410(const unsigned char *data, unsigned len)
{
    unsigned crc = 0xffffffffu;
    const unsigned *table = (const unsigned *)lbl_880C84C0;
    while (len--) crc = table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
    return ~crc;
}
