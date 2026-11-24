/* DA1: member copy through nested inline sub-object helpers (LTCG route, /Oc, pp1_pool_primer.c last).
 * The dead `addi r10,r11,0x9d0` is the address of the copied 16-byte member: the outer helper takes it and passes
 * two derived addresses (&v->hi, &v->lo) to an inner copy helper. Notes: docs/agents/near-misses/DA1.md.
 */

extern const float g_ts4_event_value;

/* Swing_DLL.xex 0x8865ADD0: ts4_copy_v2_8865ADD0 */
typedef struct Da1V2_8865ADD0 { float x, y; } Da1V2_8865ADD0;
typedef struct Da1V4_8865ADD0 { Da1V2_8865ADD0 lo, hi; } Da1V4_8865ADD0;
typedef struct Da1O_8865ADD0 {
    char pad[0x9d0]; Da1V4_8865ADD0 v;
    char pad2[0xcc0 - 0x9e0]; unsigned char bcc0;
    char pad3[0xde8 - 0xcc1]; float fde8; unsigned char bdec;
} Da1O_8865ADD0;
typedef struct Da1Mid_8865ADD0 { char pad[0x74]; Da1O_8865ADD0 *o; } Da1Mid_8865ADD0;
typedef struct Da1S_8865ADD0 { char pad[0x1c]; Da1Mid_8865ADD0 *p; } Da1S_8865ADD0;
static __inline void da1_v2_copy_8865ADD0(Da1V2_8865ADD0 *d, const Da1V2_8865ADD0 *s) { d->x = s->x; d->y = s->y; }
static __inline void da1_v4_hold_8865ADD0(Da1V4_8865ADD0 *v) { da1_v2_copy_8865ADD0(&v->hi, &v->lo); }
void ts4_copy_v2_8865ADD0(Da1S_8865ADD0 *s)
{
    Da1O_8865ADD0 *o = s->p->o;
    unsigned char armed = o->bcc0;
    da1_v4_hold_8865ADD0(&o->v);
    if (armed != 0) {
        o->bdec = 1;
        o->fde8 = g_ts4_event_value;
    }
}
