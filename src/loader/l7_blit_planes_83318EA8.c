/* Loader_DLL.xex 0x83318EA8-0x83319118, executable version 0.0.0.3. */
typedef void (*Blit1Fn)(int, int, int, int, int, int, int, int, int, int, int);
typedef void (*Blit2Fn)(int, int, int, int, int, int, int, int, int, int, int, int);

typedef struct Surf {
    char pad0[0xa4];
    int a4;
    int a8;
    int ac;
    int b0;
    char pad1[4];
    int b8;
    char pad2[8];
    int c4;
    char pad3[4];
    int cc;
    int d0;
    char pad4[8];
    int dc;
    int e0;
    char pad5[0xec0 - 0xe4];
    int ec0;
    int ec4;
    int ec8;
    char pad6[0x3b0c - 0xecc];
    int f3b0c;
    char pad7[0x3e2c - 0x3b10];
    Blit2Fn blit2;
    Blit1Fn blit1;
    char pad8[0x50c8 - 0x3e34];
    int f50c8;
    int f50cc;
} Surf;

void ts4l_blit_planes_83318EA8(Surf *s, int x)
{
    int m;
    if (s->f50c8 != 0 && s->f50cc == 0) {
        if (s->f3b0c != s->cc)
            return;
        s->blit1(0, s->cc + s->ec0, 0, s->ac >> 1, s->dc, 1, 1, s->a4, s->b8, s->cc * 2, 0);
        s->blit2(0, s->d0 + s->ec4, s->d0 + s->ec8, 0, s->b0 >> 1, s->e0, 1, 1, s->a8, s->c4, s->d0 * 2,
                 s->f50c8 == 0);
        s->blit1(0, s->ec0, 0, s->ac >> 1, s->dc, 1, 1, s->a4, s->b8, s->cc * 2, s->f50c8 == 0);
        s->blit2(0, s->ec4, s->ec8, 0, s->b0 >> 1, s->e0, 1, 1, s->a8, s->c4, s->d0 * 2, s->f50c8 == 0);
        return;
    }
    m = (s->f50c8 != 0) ? x : 0;
    s->blit1(0, (s->cc >> 1) * m + s->ec0, 0, s->ac, s->dc, 1, 1, s->a4, s->b8, s->cc, s->f50c8 == 0);
    s->blit2(0, s->ec4 + (s->d0 >> 1) * m, s->ec8 + (s->d0 >> 1) * m, 0, s->b0, s->e0, 1, 1, s->a8, s->c4,
             s->d0, s->f50c8 == 0);
}
