/* 0x888D51B0: copies two 0x2d-byte records (11 words + a byte, copied field by field) into the first and second
 * slots of the self-relative data block at o->hdr+0xc. */

typedef unsigned int u32; typedef unsigned char u8;
typedef struct { u32 w[11]; u8 b; } Rec;
typedef struct { Rec a; Rec b; } Data;
typedef struct { char p[0xc]; int rel; } Hdr;
typedef struct { char p[0x24]; Hdr *hdr; } O;
static Data *data(O *o) { int *r = &o->hdr->rel; return (Data *)((char *)r + *r); }
static void rcopy(Rec *d, const Rec *s) {
    d->w[0] = s->w[0]; d->w[1] = s->w[1]; d->w[2] = s->w[2]; d->w[3] = s->w[3]; d->w[4] = s->w[4]; d->w[5] = s->w[5];
    d->w[6] = s->w[6]; d->w[7] = s->w[7]; d->w[8] = s->w[8]; d->w[9] = s->w[9]; d->w[10] = s->w[10]; d->b = s->b;
}
void ts4_data_set_rec_pair_888D51B0(O *o, const Rec *a, const Rec *b) {
    rcopy(&data(o)->a, a);
    rcopy(&data(o)->b, b);
}
