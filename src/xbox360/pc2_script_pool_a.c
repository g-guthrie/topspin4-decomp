/*
 * PC2 family: small functions that read the script float-constant pool
 * g_ts4_script_constants (0x880D0F70). The pool is declared per translation
 * unit as a static copy; indexing it as K[n] reproduces the original
 * `addi rX, REFLO pool; lfs fN, n*4(rX)` access form.
 */
static const float g_ts4_script_constants[668] = {1.0f};
#define K g_ts4_script_constants

#ifdef _MSC_VER
extern float __fres(float);
#pragma intrinsic(__fres)
#else
static float __fres(float x) { return 1.0f / x; }
#endif

/* Float zero constant used by the original code. */
extern float lbl_8814B440;
/* Float 3.0-style constant used in one select. */
extern float lbl_8814B45C;
/* Returns the float of fn_8861E598 (called with a sub-object and two constants). */
extern float fn_8861E598(void *obj, float a, float b);

#define FP(p, o) (*(float *)((char *)(p) + (o)))
#define IP(p, o) (*(int *)((char *)(p) + (o)))
#define UP(p, o) (*(unsigned *)((char *)(p) + (o)))
#define PP(p, o) (*(void **)((char *)(p) + (o)))
#define BP(p, o) (*(unsigned char *)((char *)(p) + (o)))

/* Swing_DLL.xex 0x886EBBC8: clamp *value to the range [0, const0]. */
void ts4_clamp_float_to_unit_886EBBC8(int unused, float *value)
{
    float v = *value;
    (void)unused;
    *value = v < lbl_8814B440 ? lbl_8814B440 : (v > K[0] ? K[0] : v);
}

typedef struct Ts4PoolRangeInner { char pad[0x14]; float scale; } Ts4PoolRangeInner;
typedef struct Ts4PoolRangeMid { char pad[8]; Ts4PoolRangeInner *inner; } Ts4PoolRangeMid;
typedef struct Ts4PoolRange {
    char pad0[4];
    Ts4PoolRangeMid *mid;
    char pad1[0xc];
    float src_origin;
    char pad2[0xc];
    float dst_origin;
} Ts4PoolRange;

/* Swing_DLL.xex 0x886CBCB0: inverse range map: (x - dst_origin) / (scale - 1) + src_origin, using a refined reciprocal estimate. */
float ts4_range_remap_886CBCB0(Ts4PoolRange *o, float x)
{
    float d = o->mid->inner->scale - K[0];
    float r = __fres(d);
    r = (K[0] - r * d + K[0]) * r;
    return r * (x - o->dst_origin) + o->src_origin;
}

/* Swing_DLL.xex 0x886D13C8: same inverse range map as 0x886CBCB0 in a sibling class. */
float ts4_range_remap_886D13C8(Ts4PoolRange *o, float x)
{
    float d = o->mid->inner->scale - K[0];
    float r = __fres(d);
    r = (K[0] - r * d + K[0]) * r;
    return r * (x - o->dst_origin) + o->src_origin;
}

/* Swing_DLL.xex 0x886CBCF0: forward range map applied to both components of a 2-float pair, in place. */
void ts4_range_map_pair_886CBCF0(Ts4PoolRange *o, float *p)
{
    float a = o->src_origin;
    float x = p[0];
    float y = p[1];
    float t = o->dst_origin;
    float k = o->mid->inner->scale - K[0];
    p[0] = (x - a) * k + t;
    p[1] = (y - a) * k + t;
}

/* Swing_DLL.xex 0x8866CD58: set two hash words on the child at +0x74 and pool const 0 on the child at +0x78. */
void ts4_set_hashes_and_const0_8866CD58(void *o)
{
    UP(PP(PP(o, 0x1c), 0x74), 0x38c) = 0xaac53e41;
    UP(PP(PP(o, 0x1c), 0x74), 0x390) = 0xf22e0cbd;
    FP(PP(PP(o, 0x1c), 0x78), 0x41c) = K[0];
}

/* Swing_DLL.xex 0x8867EB38: return whether fn_8861E598(sub-object+0xb4, 0, const0) is below x. */
unsigned char ts4_lookup_below_8867EB38(void *o, float x)
{
    return fn_8861E598((char *)PP(PP(o, 4), 0x44) + 0xb4, lbl_8814B440, K[0]) < x;
}

/* Swing_DLL.xex 0x886EC4B8: pack a vec3 scaled by pool constant 73 into three 10-bit fields (z high, y, x low). */
void ts4_pack_vec3_10bit_886EC4B8(float *v, int *out)
{
    float s = K[73];
    int a, b, c;
    a = (int)(v[1] * s);
    b = (int)(v[0] * s);
    c = (int)(v[2] * s);
    *out = ((0x400 - c) << 10) - a;
    *out = (*out << 10) - b;
}

/* Swing_DLL.xex 0x88679748: seed hashes, const0, max-int limits on the child at +0x74, clear field 0x40. */
void ts4_init_limits_and_hashes_88679748(void *o)
{
    void *p = PP(o, 0x1c);
    UP(PP(p, 0x74), 0x38c) = 0xaac53e41;
    UP(PP(PP(o, 0x1c), 0x74), 0x390) = 0xf22e0cbd;
    FP(PP(PP(o, 0x1c), 0x78), 0x41c) = K[0];
    p = PP(o, 0x1c);
    IP(PP(p, 0x74), 0x90) = 0x7fffffff;
    IP(PP(p, 0x74), 0x98) = 0x7fffffff;
    IP(PP(p, 0x74), 0xa0) = 0x7fffffff;
    IP(o, 0x40) = 0;
}

/* Swing_DLL.xex 0x8866D868: reset a pending-state record from the flag at child+0x327. */
void ts4_reset_pending_state_8866D868(void *o)
{
    void *q;
    IP(PP(o, 0x24), 0) = 0x7fffffff;
    q = PP(o, 0x20);
    IP(o, 0x2c) = BP(PP(q, 0x30), 0x327) ? 2 : 1;
    FP(PP(o, 0x24), 0xbc) = BP(PP(PP(o, 0x20), 0x30), 0x327) ? K[0] : lbl_8814B440;
    IP(PP(o, 0x24), 0xb4) = 0;
    IP(o, 0x30) = -1;
}

typedef struct Ts4PoolPair { int p0; int kind; int sub; } Ts4PoolPair;
typedef struct Ts4PoolSlot { char p[0x30]; void *target; char q[0xc]; Ts4PoolPair *pair; } Ts4PoolSlot;
typedef struct Ts4PoolHolder { char p[4]; Ts4PoolSlot *slot; } Ts4PoolHolder;

/* Swing_DLL.xex 0x8865C790: pick a float constant by (kind, sub) pair and store it at target+0x330. */
void ts4_select_pair_const_8865C790(Ts4PoolHolder *o)
{
    Ts4PoolSlot *a = o->slot;
    float f = K[0];
    Ts4PoolPair *r = a->pair;
    if (r->kind == 3) {
        if (r->sub != 3 && r->sub == 5) {
            FP(a->target, 0x330) = K[170];
            return;
        }
    } else if (r->kind == 6) {
        if (r->sub == 3) {
            f = lbl_8814B45C;
            goto done;
        }
        if (r->sub == 5)
            f = K[19];
    }
done:
    FP(a->target, 0x330) = f;
}
