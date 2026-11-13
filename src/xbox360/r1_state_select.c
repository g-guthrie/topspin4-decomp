/* R1: match-state hash classification (range 0x88640000-0x88698000). */
typedef unsigned char r1_u8;
typedef unsigned int r1_u32;

struct R1HashPair {
    r1_u8 pad0[0x74];
    r1_u32 hash_a;     /* +0x74 */
    r1_u32 hash_b;     /* +0x78 */
};

struct R1ModeSink {
    r1_u8 pad0[0x320];
    r1_u32 mode_hash;          /* +0x320 */
};

struct R1ModeSelector {
    r1_u8 pad0[0x30];
    struct R1ModeSink *sink;   /* +0x30 */
    r1_u8 pad1[0x40 - 0x34];
    struct R1HashPair *pair;   /* +0x40 */
};

/* Swing_DLL.xex 0x8866E128: pick the sink mode hash from the two crc32 hashes of the pair (a decision table, names unknown). */
void ts4_mode_selector_pick_hash_8866E128(struct R1ModeSelector *self)
{
    r1_u32 a = self->pair->hash_a;
    r1_u32 b = self->pair->hash_b;
    r1_u32 result = 0xaac53e41u;
    r1_u8 a_is_2 = (a == 0x6e4978e4u);
    r1_u8 a_is_1 = (a == 0x1f62ddf9u);
    r1_u8 a_is_3 = (a == 0x7cb2e8c3u);

    if (b == 0x1692c170u || b == 0xbb2e88d5u) {
        if (a_is_2) {
            result = 0x51374b6bu;
        } else if (a_is_1 || a_is_3) {
            result = 0xc1df4081u;
        }
    } else if (b == 0xfcf5d20du || b == 0x3e48523eu || b == 0x93458b98u) {
        if (a_is_2) {
            result = 0xc1df4081u;
        }
    } else if (b == 0x1c30353fu || b == 0xf7683059u) {
        result = 0xc1df4081u;
    }
    self->sink->mode_hash = result;
}
