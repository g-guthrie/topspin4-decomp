/* Loader_DLL.xex 0x83483328-0x834833D4, 0x8343BFE8-0x8343C094, executable version 0.0.0.3. */
typedef unsigned long u32;
extern int fn_83482E10(void *c, u32 a, u32 b, u32 one);
extern void fn_833E3AD0(void *dst, const void *src, u32 n);
extern void fn_83477DB0(void *c, void *out);
extern void fn_83478180(void *c, void *out);
typedef struct { char p0[0x10]; int f10; char p1[4]; int f18; char p2[0x3c - 0x1c]; u32 f3c; u32 f40; char p3[0x4c - 0x44]; u32 f4c; char p4[0x68 - 0x50]; u32 f68; char p5[0x80 - 0x6c]; char *f80; u32 f84; } Ts4lC;
void ts4l_fetch_rows_83483328(Ts4lC *c, u32 a, u32 b, void *out)
{
    u32 x = c->f40 + a;
    u32 y = c->f4c + b;
    int r = fn_83482E10(c, x, y, 1);
    if (r >= 0) {
        fn_833E3AD0(out, c->f80 + ((c->f3c - c->f84) << 4), c->f68 << 4);
        if (c->f18 != 0) fn_83477DB0(c, out);
        if (c->f10 != 0) fn_83478180(c, out);
    }
}

extern int fn_8343BAD0(void *c, u32 a, u32 b, u32 one);
extern void fn_83430AB8(void *c, void *out);
extern void fn_83430E88(void *c, void *out);
void ts4l_fetch_rows_8343BFE8(Ts4lC *c, u32 a, u32 b, void *out)
{
    u32 x = c->f40 + a;
    u32 y = c->f4c + b;
    int r = fn_8343BAD0(c, x, y, 1);
    if (r >= 0) {
        fn_833E3AD0(out, c->f80 + ((c->f3c - c->f84) << 4), c->f68 << 4);
        if (c->f18 != 0) fn_83430AB8(c, out);
        if (c->f10 != 0) fn_83430E88(c, out);
    }
}
