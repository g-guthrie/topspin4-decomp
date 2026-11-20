/* Loader_DLL.xex 0x832A2280-0x832A2384, executable version 0.0.0.3. */
typedef void (*L29Fn)(void *, int, int, int, int, int, int, int, int, int, int, int);
typedef void (*L29Fn11)(void *, int, int, int, int, int, int, int, int, int, int);
typedef struct L29G { char pad[0x5764]; void *f5764; } L29G;
typedef struct L29C {
    char pad0[0x4a]; unsigned short f4a; unsigned short f4c;
    char pad1[0x56 - 0x4e]; unsigned short f56; unsigned short f58;
    char pad2[0x558 - 0x5a]; int f558;
} L29C;
typedef struct L29S {
    char pad0[0xa4]; int fa4; int fa8; char pada[0xb8 - 0xac]; int fb8;
    char padb[0xc4 - 0xbc]; int fc4; char padc[0xdc - 0xc8]; int fdc; int fe0;
    char pad1[0xec0 - 0xe4]; int fec0; int fec4; int fec8;
    char pad2[0xf6c - 0xecc]; int ff6c;
    char pad3[0x3e2c - 0xf70]; L29Fn f3e2c; L29Fn11 f3e30;
    char pad4[0x3e70 - 0x3e34]; L29C c;
    char pad5[0x6070 - 0x3e70 - sizeof(L29C)]; L29G *f6070;
} L29S;

extern int fn_83515340(L29S *s, L29C *c, int a);
extern int ts4_tailcall_fn_83515340_83515D58(L29S *s, L29C *c, int a);

#define L29_BODY(NAME, CALL) \
int NAME(L29S *s, int a) \
{ \
    L29C *c = &s->c; \
    int ret; \
    if (c != 0) { \
        ret = CALL(s, c, a); \
        if (s->ff6c == 0) { \
            s->f3e30(s->f6070->f5764, (c->f4a >> 1) * c->f558 + s->fec0, 0, c->f56, s->fdc, 1, 1, s->fa4, s->fb8, c->f4a, 0); \
            s->f3e2c(s->f6070->f5764, s->fec4 + (c->f4c >> 1) * c->f558, s->fec8 + (c->f4c >> 1) * c->f558, 0, c->f58, s->fe0, 1, 1, s->fa8, s->fc4, c->f4c, 0); \
        } \
        return ret; \
    } \
    return -9; \
}

L29_BODY(ts4l_blit_planes_832A2280, fn_83515340)
L29_BODY(ts4l_blit_planes_832A25A0, ts4_tailcall_fn_83515340_83515D58)
