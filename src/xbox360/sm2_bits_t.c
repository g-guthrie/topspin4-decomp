/* SM2: bitfield setters on 24-byte records plus a small vec4 accumulate. */
typedef unsigned long long ts4_u64;

/* record layout (MSB-first bitfields): word0 has a 2-bit field at bit 7; word1 has 5-bit fields at bits 0 and 5;
   word2 has a 2-bit field at bit 27 and a 1-bit field at bit 29 */
typedef struct ts4_rec24 {
    unsigned pad0 : 7;
    unsigned fa : 2;
    unsigned rest0 : 23;
    unsigned fc : 5;
    unsigned fb : 5;
    unsigned rest1 : 22;
    unsigned pad2 : 27;
    unsigned fe : 2;
    unsigned ff : 1;
    unsigned rest2 : 2;
    unsigned w3, w4, w5;
} ts4_rec24;

#define SET_REC_FIELD(NAME, BASE, FIELD) \
    void NAME(char *p, int i, int v) \
    { \
        ((ts4_rec24 *)(p + (BASE)))[i].FIELD = v; \
        *(ts4_u64 *)(p + 0x18) |= ((ts4_u64)1 << 63) >> (unsigned)(i + 0x20); \
    }
SET_REC_FIELD(ts4_set_rec_fa_886EC2D0, 0x48c, fa)
SET_REC_FIELD(ts4_set_rec_fb_886EC240, 0x48c, fb)
SET_REC_FIELD(ts4_set_rec_fc_886EC1F8, 0x48c, fc)
SET_REC_FIELD(ts4_set_rec_ff_886EC1B0, 0x48c, ff)
SET_REC_FIELD(ts4_set_rec_fe_886EC288, 0x48c, fe)

static void ts4_add_float(float *d, const float *s) { float t = *s; *d = t + *d; }
