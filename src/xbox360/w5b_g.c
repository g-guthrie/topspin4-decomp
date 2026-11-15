/* W5B batch G */
typedef struct W5gElem { unsigned char pad00[0x10]; float key; unsigned char pad14[0x28 - 0x14]; } W5gElem;  /* 40 B */
typedef struct W5gDef {
    unsigned char pad00[0x0c];
    unsigned short id;          /* +0x0c */
    unsigned char pad0e[0x14 - 0x0e];
    float scale;                /* +0x14 */
    unsigned char pad18[0x70 - 0x18];
    int rel;                    /* +0x70, self-relative to &rel */
    unsigned count;             /* +0x74 */
} W5gDef;
typedef struct W5gLink { unsigned char pad00[8]; W5gDef *def; } W5gLink;
typedef struct W5gInst {
    unsigned char pad00[4];
    W5gLink *link;
    unsigned char pad08[0x14 - 0x08];
    float v14;
    unsigned char pad18[0x24 - 0x18];
    float v24;
    unsigned char pad28[0x6c - 0x28];
    unsigned *tag;
} W5gInst;
typedef struct W5gOwner {
    unsigned char pad00[0x18];
    float base;
    unsigned char pad1c[0x5c - 0x1c];
    W5gInst **inst;
} W5gOwner;
typedef struct W5gSelf { unsigned char pad00[0x2c]; W5gOwner *owner; } W5gSelf;

extern int fn_886C66C0(W5gOwner *o);

int ts4_last_key_offset_886CD2E0(W5gSelf *self)
{
    W5gOwner *ow = self->owner;
    int r = -1;
    W5gInst *in = ow->inst[fn_886C66C0(ow)];
    unsigned n;
    if (in->link->def->id != 0xffff && *in->tag != 0xc222a5e0u && (n = in->link->def->count) >= 2) {
        int *h = &in->link->def->rel;
        W5gElem *e = (W5gElem *)((char *)h + (n * 40 + *h));
        r = (int)((e[-1].key - in->v14) * (in->link->def->scale - 1.0f) + in->v24 - ow->base);
    }
    return r;
}
