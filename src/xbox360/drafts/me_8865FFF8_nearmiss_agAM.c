/* agAM: 1 off (plain /Oc), down from 12. Uses the sub-struct pointer &holder->target->blend and an fp_contract(off) ease inline. The final fadds operands come out f11,f13 where the target has f13,f11. */
/* near-miss: 12 off (register numbering r8/r9 for holder/target); fp_contract(off) splits the fmadds */
/* ME: ease a 0..1 blend toward a flag (pick.py throughput). Swing_DLL.xex 0x8865FFF8 */
extern float g_ts4_script_constants[];
#define TS4_ONE (g_ts4_script_constants[0])            /* 1.0f */
#define TS4_EASE (g_ts4_script_constants[0x2AC / 4])   /* 0.1f */

struct Ts4BlendTarget { unsigned char pad_000[0x4F0]; float blend; /* +0x4F0 */ };
struct Ts4BlendHolder { unsigned char pad_00[0x78]; struct Ts4BlendTarget *target; /* +0x78 */ };
struct Ts4RelFlags { int rel; /* +0x00: back-offset to the flag block */ };
struct Ts4BlendState {
    unsigned char pad_00[0x18];
    struct Ts4BlendHolder *holder;   /* +0x18 */
    unsigned char pad_1c[4];
    unsigned char *flags;            /* +0x20 */
};

#pragma fp_contract(off)
static __inline void ease(float *b, float g){ *b = *b + (g - *b) * TS4_EASE; }
void f(struct Ts4BlendState *self){ float *bl=&self->holder->target->blend; struct Ts4RelFlags *r=(struct Ts4RelFlags *)(self->flags+0x10); float goal; if (*((unsigned char*)r - r->rel + 0x10)) goal=TS4_ONE; else goal=0.0f; ease(bl, goal); }