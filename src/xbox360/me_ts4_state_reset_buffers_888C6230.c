/* 0x888C6230: resets a gameplay state block: zeroes two counters and a flag, and when the output slot at +0x30 exists,
 * empties the byte and 8-byte record vectors of the sub-object and zeroes the seven output slots. */

typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u32 a; u16 b; u8 c, d; } E8;
typedef struct { E8 *first, *last; } EV;
typedef struct { char *first, *last; } BV;
extern void *fn_88562DC0(void *d, const void *s, u32 n);
typedef struct { char pad[0x1c]; BV bytes; char p2[0x48-0x24]; EV recs; } Sub;
typedef struct {
    char pad[0x20]; Sub *sub; char p24[4]; u32 *p28; u32 *p2c; u32 *p30; u32 *p34; u32 f38; u32 f3c;
    u32 *p40; u32 *p44; char p48[4]; u32 *p4c; char p50[0x16d-0x50]; u8 b16d;
} O;
extern char *fn_881A9BE8(char *first, char *last, char *dest);
static void bv_clear(BV *v) { v->last = fn_881A9BE8(v->last, v->last, v->first); }
static E8 *e8_erase(EV *v, E8 *dst, E8 *first) {
    int n = v->last - first; E8 *p = dst; E8 *s = first;
    while (n > 0) { p->a = s->a; p->b = s->b; p->c = s->c; p->d = s->d; n--; p++; s++; }
    v->last = p; return dst;
}
static void ev_clear(EV *v) { e8_erase(v, v->first, v->last); }
void ts4_state_reset_buffers_888C6230(O *o) {
    o->f38 = 0;
    o->f3c = 0;
    o->b16d = 0;
    if (o->p30) {
        bv_clear(&o->sub->bytes);
        ev_clear(&o->sub->recs);
        *o->p30 = 0;
        *o->p34 = 0;
        *o->p4c = 0;
        *o->p28 = 0;
        *o->p2c = 0;
        *o->p40 = 0;
        *o->p44 = 0;
    }
}
