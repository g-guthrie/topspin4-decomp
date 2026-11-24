/* nearmiss: ~65 off (fn_check_ltcg /Oc --auto-context). Init of the object at Player+0x70 (called from
   fn_886BBEA8 as fn(player->0x70, player)); stores this+0x1c = player. The target builds a stack temp
   {u8 1,0,0; int 0,0} at sp-0x40 and copies it in; grouping the +0x38 stores into inline helpers fixed the tail.
   Remaining: my builds spill the constant 2 (+0x10) and other zeros to stack slots, and the store order differs
   (target +0x10 after the +0x34 byte stores, +0x78/+0x40 after +0xB3C). Blocker: the layout of the temp and its
   type (likely a shared sub-object type with its own copy/ctor, not yet identified); also conflicts with
   Ts4ShotContext +0x0 player in shot.h, so the class attribution needs resolving first. Swing_DLL.xex 0x886734E8. */
#include "include/ts4/ts4.h"

typedef struct MvFlags { unsigned char a, b, c; int d, e; } MvFlags;
typedef struct MvSub20 { char pad0[0x18]; unsigned char b18, b19; } MvSub20;
typedef struct MvSub240 {
    char pad0[0xbc];
    unsigned char bbc, bbd; char padbe[2];
    unsigned int fc0; char padc4[4];
    unsigned char bc8, bc9, bca; char padcb;
    int fcc;
    unsigned char bd0; char padd1[3];
    unsigned int fd4;
    char padd8[0x18];
    unsigned char bf0;
} MvSub240;
typedef struct MvWorld { char pad0[0x20]; MvSub20 s20; char pad[0x240 - 0x20 - sizeof(MvSub20)]; MvSub240 s240; } MvWorld;
typedef struct MvTgt { char pad0[0x2e]; unsigned char b2e; } MvTgt;
typedef struct MvCtx {
    char pad0[0x10];
    int f10, f14, f18;
    struct Ts4Player *player;   /* +0x1c */
    int f20, f24;
    MvTgt *f28;
    void *f2c, *f30;
    MvSub20 *f34;
    MvSub240 *f38;
    unsigned char b3c; char pad3d[3];
    int f40, f44, f48, f4c, f50, f54, f58;
    char pad5c[0x14];
    int f70;
    unsigned char b74, b75; char pad76[2];
    unsigned int f78;
    int f7c;
    unsigned char b80; char pad81[3];
    int f84;
} MvCtx;

static void mv_g1(MvSub240 *s) { s->bc8 = 0; s->bc9 = 0; s->bca = 0; s->fcc = 0; }
static void mv_g2(MvSub240 *s) { s->bd0 = 0; s->fd4 = 0; }
void ts4_move_ctx_init_886734E8(MvCtx *self, struct Ts4Player *p)
{
    MvFlags fl;
    self->player = p;
    fl.a = 1; fl.b = 0; fl.c = 0; fl.d = 0; fl.e = 0;
    self->f28 = (MvTgt *)((char *)p->f_030 + 0x2e0);
    self->f2c = self->f30 = *(char **)((char *)p->f_01c + 0x6c) + 0xb10;
    self->f34 = &((MvWorld *)p->world)->s20;
    self->f38 = &((MvWorld *)p->world)->s240;
    self->f38->bf0 = fl.a;
    self->f10 = 2;
    self->f34->b18 = fl.b;
    self->f34->b19 = fl.c;
    self->f20 = fl.d;
    self->f24 = fl.e;
    self->f50 = 0; self->f54 = 0; self->f58 = 0; self->f70 = 0; self->f14 = 0;
    self->b75 = 0; self->b74 = 0; self->b3c = 0;
    self->f78 = 0x968230B3;
    self->f40 = 0x7FFFFFFF;
    self->b80 = 0; self->f7c = 0; self->f84 = 0; self->f4c = 0; self->f48 = 0; self->f44 = 0; self->f18 = 0;
    self->f38->bbc = 0;
    self->f38->bbd = 0;
    self->f38->fc0 = 0x968230B3;
    mv_g1(self->f38);
    mv_g2(self->f38);
    self->f38->fd4 = 0x968230B3;
    self->f28->b2e = 0;
}
