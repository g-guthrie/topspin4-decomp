/* 0x886BBD20: binds every child of an owner's lists to it (owner + shared context), then runs each child's init. */
typedef struct Ctx { char _0[0x64]; void *res; char *tables; } Ctx;
typedef struct Owner Owner;
typedef struct ElA { char _0[0x18]; Ctx *ctx; Owner *owner; void *buf; char _24[0x2C]; } ElA;
typedef struct ElB { char _0[0x1C]; Ctx *ctx; Owner *owner; char _24[0x18C]; } ElB;
struct ElC { virtual void v0(); virtual void update(); char _4[0x40]; Ctx *ctx; Owner *owner; char _4c[0x384]; };
typedef struct ElD { int _0; Ctx *ctx; int _8; char sub[0xC]; int busy; char _1c[0x20]; } ElD;
typedef struct ElE { int _0; Ctx *ctx; int _8; char sub[0x24]; int busy; char _34[0x278]; } ElE;
typedef struct Lists {
    char _0[0xC]; ElB *b_begin; ElB *b_end; char _14[0x10]; ElD *d_begin; ElD *d_end; char _2c[0x10];
    ElE *e_begin; ElE *e_end; char _44[0x10]; ElA *a_begin; ElA *a_end; char _5c[0x1C]; ElC *c_begin; int c_count;
} Lists;
struct Owner { char _0[0x1C]; Ctx *ctx; char _20[8]; char *base; char _2c[0x38]; Lists *lists; };
extern "C" {
void ts4_init_886AD030(ElA *e);
void fn_886BB828(ElB *e);
void fn_8826D088(void *sub, ElD *e, char *table, void *res);
void fn_8826C198(void *sub, ElE *e, char *table, void *res);
}
extern "C" void ts4_owner_bind_children(Owner *self)
{
    ElA *a, *ae; ElB *b, *be; ElC *c, *ce; ElD *d, *de; ElE *e, *ee; char *t;
    a = self->lists->a_begin;
    a[0].buf = self->base + 0x400;
    a[1].buf = self->base + 0x940;
    for (ae = self->lists->a_end, a = self->lists->a_begin; a != ae; a++) {
        a->owner = self; a->ctx = self->ctx; ts4_init_886AD030(a);
    }
    for (be = self->lists->b_end, b = self->lists->b_begin; b != be; b++) {
        b->owner = self; b->ctx = self->ctx; fn_886BB828(b);
    }
    for (c = self->lists->c_begin, ce = c + self->lists->c_count; c != ce; c++) {
        c->owner = self; c->ctx = self->ctx; c->update();
    }
    t = self->ctx->tables + 0x2C;
    for (de = self->lists->d_end, d = self->lists->d_begin; d != de; d++) {
        d->ctx = self->ctx; fn_8826D088(d->sub, d, t, d->ctx->res); d->busy = 0;
    }
    t = self->ctx->tables + 0x38;
    for (ee = self->lists->e_end, e = self->lists->e_begin; e != ee; e++) {
        e->ctx = self->ctx; fn_8826C198(e->sub, e, t, e->ctx->res); e->busy = 0;
    }
}
