/* W11D batch A: small plain-route functions */

/* ---- 0x886C3938: clear a 4-byte vector (begin==end copy), zero w04, tail-call clear-four ---- */
typedef struct W11dVec4 { unsigned int *begin; unsigned int *end; } W11dVec4;
typedef struct W11dHold { unsigned char pad00[4]; unsigned int w04; W11dVec4 v08; } W11dHold;
extern void ts4_clear_four_vectors_886C3820(void *self);
static unsigned int *w11d_copy4(unsigned int *src, unsigned int *src_end, unsigned int *dest)
{
    int n = (int)((char *)src_end - (char *)src) >> 2;
    for (; n > 0; --n) {
        *dest = *src;
        ++src;
        ++dest;
    }
    return dest;
}
/* Swing_DLL.xex 0x886C3938 */
void ts4_clear_vec_then_four_886C3938(W11dHold *self)
{
    W11dVec4 *a = &self->v08;
    a->end = w11d_copy4(a->end, a->end, a->begin);
    self->w04 = 0;
    ts4_clear_four_vectors_886C3820(self);
}

/* ---- 0x8869FE10: ring of 0x41c-byte entries; clear the newest entry's flag, release its buffer, pop the rest ---- */
typedef unsigned int w11d_u32;
typedef unsigned char w11d_u8;
struct W11dSub { unsigned char pad00[4]; w11d_u8 flag; unsigned char pad05[0x1b]; w11d_u32 ptr; };
struct W11dEnt { unsigned char pad00[0x34]; struct W11dSub sub; unsigned char pad58[0x41c - 0x58]; };
struct W11dRing { unsigned char pad00[8]; w11d_u32 head; int count; };
extern void ts4_loop_call_seq_u32_off0_88691888(w11d_u32 a0, w11d_u32 a1);
extern w11d_u32 ts4_call_seq_u32_off8_8869FD88(struct W11dRing *self);
static __inline struct W11dEnt *w11d_ent(struct W11dRing *r, w11d_u32 i) { return (struct W11dEnt *)((char *)r + i * 0x41c); }
static __inline struct W11dSub *w11d_sub(struct W11dEnt *e) { return &e->sub; }
/* Swing_DLL.xex 0x8869FE10 */
void ts4_discard_pending_8869FE10(struct W11dRing *self)
{
    if (self->count > 0) {
        w11d_u32 idx = (w11d_u32)self->count + self->head;
        struct W11dSub *s = w11d_sub(w11d_ent(self, (idx + 9) % 10));
        s->flag = 0;
        ts4_loop_call_seq_u32_off0_88691888((w11d_u32)(unsigned long)self + 0x20, s->ptr + 0x20);
        if (self->head < idx) {
            w11d_u32 n = idx - self->head;
            do { ts4_call_seq_u32_off8_8869FD88(self); } while (--n != 0);
        }
    }
}

/* ---- 0x8864EF60: position += vec3 (loads of the three vector lanes ordered x, z, y; the dead locals fix the fadds operand order) ---- */
struct W11dPos { unsigned char pad00[0x30]; float x, y, z; };
struct W11dV3 { float x, y, z; };
static __inline void w11d_addf(float *p, float v) { *p = *p + v; }
/* Swing_DLL.xex 0x8864EF60 */
void ts4_add_vec3_8864EF60(struct W11dPos *o, const struct W11dV3 *v)
{
    int pd0 = 0, pd1 = 0, pd2 = 0;
    float vx = v->x; float vz = v->z; float vy = v->y;
    w11d_addf(&o->x, vx); w11d_addf(&o->y, vy); w11d_addf(&o->z, vz);
    (void)pd0; (void)pd1; (void)pd2;
}
