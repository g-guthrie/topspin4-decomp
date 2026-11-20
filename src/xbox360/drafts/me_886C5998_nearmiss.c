/* agentB 2026-11-18 pass 2: still 6 off (plain and LTCG). Unnamed channel, t-first, key local (u16/int/unsigned), block-local channel,
 * Range/KeyTable locals, explicit (k*2+k)*8 and (k+k*2)*8 byte index with pads 0-9: always 6. */
/* NEAR MISS (6 instructions): register numbering of the channel pointer (r11 in the game, r7 here)
 * and the key*3 add operand order. Tried named locals for keys/base/key pointer and operand_order_pad. */
/* 0x886C5998: samples a channel: interpolates the keyed range [lo, hi] of the channel's current key
 * by the channel's blend fraction and returns it relative to the clip's base value. */
typedef struct Range { float lo; float hi; } Range;
typedef struct Key { char p[0xc]; Range range; char p2[0x18 - 0x14]; } Key;
typedef struct KeyTable { char p[8]; Key *keys; } KeyTable;
typedef struct Channel { char p[0xc]; unsigned short key; char p2[0x10 - 0xe]; float t; } Channel;
typedef struct Clip { char p[0x48]; float base; } Clip;
typedef struct Sampler { Clip *clip; char p[4]; KeyTable *table; char p2[0x30 - 0xc]; Channel *channels[1]; } Sampler;
static __inline float lerp_range(Range *r, float t) { return (r->hi - r->lo) * t + r->lo; }
void f(Sampler *s, int i, float *out)
{
    float base = s->clip->base;
    Channel *c = s->channels[i];
    *out = lerp_range(&s->table->keys[c->key].range, c->t) - base;
}
