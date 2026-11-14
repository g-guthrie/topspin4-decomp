/* R1: hash-keyed flag setters (range 0x88640000-0x88698000). */
typedef unsigned char r1_u8;
typedef unsigned int r1_u32;

struct R1FlagBlock {
    r1_u8 pad0[0xb0];
    r1_u8 flag[12];            /* +0xb0..+0xbb one byte per named option */
};

struct R1FlagOwner {
    r1_u8 pad0[0x38];
    struct R1FlagBlock *flags; /* +0x38 */
};

/* Swing_DLL.xex 0x8865B118: set the option byte selected by a crc32 name hash (names unknown). */
void ts4_flag_block_set_by_hash_8865B118(struct R1FlagOwner *self, r1_u32 name_hash, r1_u8 value)
{
    switch (name_hash) {
    case 0x835f1984u: self->flags->flag[0x5] = value; break;
    case 0x6661de14u: self->flags->flag[0x3] = value; break;
    case 0x141d93ddu: self->flags->flag[0xa] = value; break;
    case 0x2edde6b8u: self->flags->flag[0xb] = value; break;
    case 0x31541bebu: self->flags->flag[0x1] = value; break;
    case 0x7580cf94u: self->flags->flag[0x0] = value; break;
    case 0x7e04871fu: self->flags->flag[0x2] = value; break;
    case 0x9c8c2318u: self->flags->flag[0x9] = value; break;
    case 0x84a6da86u: self->flags->flag[0x4] = value; break;
    case 0x912faaa2u: self->flags->flag[0x8] = value; break;
    case 0xb1cc94c4u: self->flags->flag[0x6] = value; break;
    case 0xd9347a7fu: self->flags->flag[0x7] = value; break;
    default: break;
    }
}
