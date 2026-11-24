/* W5A: lerp between two keys */
typedef struct W5aKeyArr {
    unsigned char pad00[0x04];
    unsigned char hdr4[4];
    int rel;                    /* +0x08 */
} W5aKeyArr;
typedef struct W5aKeyArr2 {
    unsigned char pad00[0x04];
    unsigned count;             /* +0x04 */
    unsigned char pad08[0x14 - 0x08];
    float blend;                /* +0x14 */
} W5aKeyArr2;
typedef struct W5aKey { float a, b; } W5aKey;

float ts4_key_lerp_88670318(W5aKeyArr *o, W5aKeyArr2 *p, float t)
{
    int *hdr = &o->rel;
    unsigned n = p->count;
    W5aKey *e = (W5aKey *)((char *)hdr + (n * 8 + *hdr));
    W5aKey *q = (W5aKey *)o;
    float a, b;
    if (n != 0)
        q = (W5aKey *)((char *)e - 8);
    a = (e->b - e->a) * t + e->a;
    b = (q->b - q->a) * t + q->a;
    return (b - a) * p->blend + a;
}
