/* agAR near-miss, 2 off: target stores f18 before li r11,-1 (plain /Oc, LTCG ctx=[] and .cpp all same). */

typedef unsigned int u32; typedef unsigned char u8;
typedef struct Str { u32 a, b, c; } Str;
typedef struct T { u32 f0, f4, f8; Str s; u32 f18, f1c, f20, f24, f28, f2c; int f30, f34; u8 f38; } T;
extern void fn_8816D1A8(Str *s);
T *fn_888FA078(T *t)
{
    t->f0 = 0; t->f4 = 0; t->f8 = 0;
    fn_8816D1A8(&t->s);
    t->f18 = 0; t->f1c = 0; t->f20 = 0; t->f24 = 0; t->f2c = 0; t->f28 = 0xFFFFF; t->f30 = -1; t->f34 = -1; t->f38 = 0;
    return t;
}
