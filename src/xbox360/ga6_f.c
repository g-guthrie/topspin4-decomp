/*
 * GA6: gameplay object helpers (checks, copies, vector pool updates).
 */
#include "ts4_vector.h"

typedef unsigned int ts4_word;

void fn_886C7500(void *self);
void fn_886E2410(void *self);
void fn_886DBF40(void *a, ts4_word b, void *c, ts4_word d, int e, ts4_word f);
void ts4_init_state_8864A920(void *obj, ts4_word a, ts4_word b, void *owner);
void fn_8864A770(void *obj, ts4_word a, void *b, ts4_word c);
void fn_8864A5E8(void *obj);
void ts4_if_call_seq_u32_off40_8864A8A8(void *obj);
void ts4_layout_refresh_886D3A00(void *list, void *item, int a, ts4_word b, int c);
void ts4_r2_swing_ring_release_entry_886DC9C0(void *owner, ts4_word item);
void fn_886CDFD8(void *self);
extern char lbl_880FC650[];
extern float g_ts4_event_value;

struct Ga6Limits { char pad_00[0x3FC]; ts4_word limit; };
struct Ga6Stats { char pad_00[0x14]; struct Ga6Limits *limits; };
struct Ga6Owner4 {
    char pad_00[4];
    struct Ga6Stats *stats;    /* +0x04 */
};
/* If the counter exceeds the limit, run the two cleanup steps. */
struct Ga6Counter4 {
    char pad_00[4];
    struct { char pad[0x14]; struct Ga6Limits *limits; char pad2[0x5F8 - 0x18]; ts4_word *counter; } *ctx;
};
void ga6_check_counter_886E2508(struct Ga6Counter4 *self)
{
    if (*self->ctx->counter > self->ctx->limits->limit) {
        fn_886C7500(self);
        fn_886E2410(self);
    }
}

/* Copy the first vector of 64-byte matrix src to dst for every {src, dst} pair in the list. */
struct Ga6CopyPair { ts4_word src, dst, pad[2]; };
struct Ga6CopyList {
    char pad_00[0x38];
    struct Ga6CopyPair *pairs; /* +0x38 */
    ts4_word count;            /* +0x3C */
    char *matrices;            /* +0x40 */
};
void ga6_copy_matrix_rows_886E6420(struct Ga6CopyList *self)
{
    ts4_word i;
    for (i = 0; i < self->count; i++) {
        struct Ga6CopyPair *pair = &self->pairs[i];
        char *base = self->matrices;
        *(__vector4 *)(base + pair->dst * 64) = *(__vector4 *)(base + pair->src * 64);
    }
}

/* ---- 886DC858: clear a back-pointer flag when the node is the list head, then forward the node's slot ---- */
struct Ga6Flagged { char pad_00[0x2D]; unsigned char flag_2d; };
struct Ga6SlotOwner { char pad_00[4]; ts4_word *slots; char pad_08[0x64]; struct Ga6Flagged *flagged; /* +0x6C */ };
struct Ga6Cfg { char pad_00[0x40]; ts4_word w40; };
struct Ga6Cfg0 { char pad_00[0x10]; struct Ga6Cfg *cfg; char pad_14[0x278]; ts4_word w28c; };
struct Ga6Node {
    char pad_00[0x20];
    struct Ga6Cfg0 *cfg0;      /* +0x20 */
    char pad_24[4];
    struct { char pad[0xC]; char *rec; } *ref; /* +0x28 */
};
