/* 0x8876DE20: renderer: store an enable byte (+0x54) and a word twice (+0x4C, +0x50), and copy a 16-byte vector to +0x60 when enabled */
/* Matched on /Oc (LTCG) (agAL). LTCG route, first try; the vector is a passinreg __vector4 struct (lvx128/stvx128 copy). */
typedef struct __declspec(passinreg) __vector4 { float v[4]; } __vector4;
typedef struct ParamBlock { unsigned char pad[0x4c]; unsigned int a; unsigned int b; unsigned char enable; unsigned char pad55[0x60 - 0x55]; __vector4 value; } ParamBlock;

void ts4_param_block_set_8876DE20(ParamBlock *p, unsigned char enable, unsigned int v, const __vector4 *c)
{
    p->enable = enable;
    p->a = v;
    p->b = v;
    if (enable)
        p->value = *c;
}
