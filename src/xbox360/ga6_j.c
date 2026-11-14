/*
 * GA6: gameplay node binding, scoped worker call and singleton construction.
 */
typedef unsigned int ts4_word;

void fn_886DBF40(void *a, ts4_word b, void *c, ts4_word d, int e, ts4_word f);

struct Ga6Flagged {
    char pad_00[0x2D];
    unsigned char flag_2d;     /* +0x2D */
};
struct Ga6CfgSub {
    char pad_00[0x40];
    ts4_word w40;              /* +0x40 */
};
struct Ga6Cfg0 {
    char pad_00[0x10];
    struct Ga6CfgSub *sub;     /* +0x10 */
    char pad_14[0x278];
    ts4_word w28c;             /* +0x28C */
};
struct Ga6RefRec {
    char pad_00[0xC];
    char *rec;                 /* +0x0C */
};
struct Ga6Node {
    char pad_00[0x20];
    struct Ga6Cfg0 *cfg0;      /* +0x20 */
    char pad_24[4];
    struct Ga6RefRec *ref;     /* +0x28 */
};
struct Ga6SlotRef {
    ts4_word pad_00;
    ts4_word *slot;            /* +0x04 */
    char pad_08[0x64];
    struct Ga6Flagged *flagged;/* +0x6C */
};

/* If the node's config block is the node's own embedded block, clear the flag on the partner object; then
 * forward the partner's slot to the worker. */
void ga6_forward_node_slot_886DC858(struct Ga6Node *self, struct Ga6SlotRef *partner)
{
    if ((char *)self->cfg0 + 0x30 == (char *)self) {
        struct Ga6Flagged *flagged = partner->flagged;
        if (flagged)
            flagged->flag_2d = 0;
    }
    fn_886DBF40(partner->slot + 1, partner->slot[1], self->ref->rec + 0x60, self->cfg0->sub->w40, -1,
                self->cfg0->w28c);
}

extern char lbl_880F37A0[];          /* vtable */
extern void *lbl_88D45AF0;          /* singleton instance pointer */

/* Singleton constructor: zero all state, set the 'enabled' byte at +0x44 and publish the instance. */
struct Ga6Sub28 { ts4_word w; };
static struct Ga6Sub28 *ga6_sub28_init(struct Ga6Sub28 *sub)
{
    sub->w = 0;
    return sub;
}
struct Ga6Singleton {
    void *vtbl;                /* +0x00 */
    ts4_word w04, w08, w0c, w10, w14, w18, w1c, w20, w24;
    struct Ga6Sub28 sub28;     /* +0x28 */
    unsigned char b2c, b2d;    /* +0x2C, +0x2D */
    char pad_2e[2];
    ts4_word w30, w34, w38, w3c;
    ts4_word w40;              /* +0x40 */
    unsigned char enabled;     /* +0x44 */
    char pad_45[3];
    ts4_word w48;              /* +0x48 */
};
