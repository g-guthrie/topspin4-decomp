/*
 * GA2: small gameplay helpers, Swing_DLL.xex 0x886601F0..0x8867B608.
 * Field names are roles inferred from the access pattern; unknown regions are padding.
 */
#include "ts4_vector.h"

typedef unsigned char ga2_u8;
typedef unsigned int ga2_u32;

extern float g_ts4_event_value; /* 0.0f */

/* Self-relative record: the first word is the byte offset from the record to its payload. */
struct Ga2Rel24 {
    int rel;
    ga2_u8 pad_04[0x08];
    int value_0c;
    ga2_u8 pad_10[0x14];
    int value_24;
};
struct Ga2Owner08 {
    ga2_u8 pad_00[8];
    char *data;
};

/* 0x8866A018: sum of two ints read through a self-relative record at data+0x24. */
int ts4_ga2_rel_record_sum_8866A018(struct Ga2Owner08 *self)
{
    char *p = self->data + 0x24;
    struct Ga2Rel24 *r = (struct Ga2Rel24 *)(p + *(int *)p);
    return r->value_24 + r->value_0c;
}

struct Ga2PlayerCtl694 {
    ga2_u8 pad_00[0x694];
    float f694, f698, f69c, f6a0;
};
struct Ga2Game74 {
    ga2_u8 pad_00[0x74];
    struct Ga2PlayerCtl694 *player;
};
struct Ga2Owner08b {
    ga2_u8 pad_00[8];
    struct Ga2Game74 *game;
    ga2_u8 pad_0c[0x0c];
    int field_18;
};

