/* Swing_DLL.xex game core 0x8818C6C0-0x8819C000 (CW29): constructors over lock holders. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
#ifdef _MSC_VER
typedef unsigned int cx_uptr;
#else
typedef unsigned long cx_uptr;
#endif

cx_uptr RtlInitializeCriticalSection(cx_uptr);
struct cx_holder { void *vt; u32 f4; u8 cs[0x1c]; };
extern char lbl_880DCF30[];
void *fn_8818A3E0(void *);
void ts4_if_get_RtlEnterCriticalSection_8818A4C8(void *, void *);

/* 0x88195260: constructor of a three-pool manager: three lock holders with their sizing fields, two pools primed */
struct cx_mgr {
    struct cx_holder a; u32 f24, f28, f2c, f30, f34, f38, f3c, f40;
    struct cx_holder b; u32 f68, f6c, f70, f74, f78;
    struct cx_holder c; u32 fa0, fa4, fa8, fac, fb0, fb4, fb8, fbc, fc0, fc4, fc8, fcc, fd0;
};
static void cx_holder_init(struct cx_holder *h)
{
    h->f4 = 0;
    h->vt = lbl_880DCF30;
    RtlInitializeCriticalSection((cx_uptr)h->cs);
}
struct cx_mgr *ts4_pool_mgr_ctor_88195260(struct cx_mgr *self)
{
    cx_holder_init(&self->a);
    self->f24 = 0;
    self->f28 = 0;
    self->f34 = 0;
    self->f38 = 0;
    self->f3c = 0;
    self->f40 = 0;
    self->f30 = 10;
    self->f2c = 12;
    cx_holder_init(&self->b);
    self->f68 = 0;
    self->f6c = 0;
    self->f70 = 0x8c;
    self->f74 = 100;
    self->f78 = 0;
    cx_holder_init(&self->c);
    self->fa0 = 0;
    self->fa4 = 0;
    self->fa8 = 0x38;
    self->fac = 100;
    self->fb0 = 0;
    self->fb4 = 0;
    self->fb8 = 0;
    self->fc4 = 0;
    self->fc8 = 0;
    self->fcc = 0;
    self->fd0 = 0;
    self->fc0 = 10;
    self->fbc = 12;
    ts4_if_get_RtlEnterCriticalSection_8818A4C8(&self->b, fn_8818A3E0(&self->b));
    ts4_if_get_RtlEnterCriticalSection_8818A4C8(&self->c, fn_8818A3E0(&self->c));
    return self;
}
