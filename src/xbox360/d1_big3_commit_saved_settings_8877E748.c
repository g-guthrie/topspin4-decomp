/* Swing_DLL.xex 0x8877E748-0x8877E8E4, executable version 0.0.0.3. */
#if defined(_MSC_VER)
#define TS4_FORCEINLINE __forceinline
#else
#define TS4_FORCEINLINE inline __attribute__((always_inline))
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Block {
    u32 a;
    u32 b;
    u32 c;
    u16 d[6];
    u32 e;
    float f;
    u8 g[5];
    u8 pad;
    u16 h;
} Block;

typedef struct Settings {
    u8 reserved[0x144];
    Block current;
    Block saved;
} Settings;

typedef struct Service {
    void **vtbl;
} Service;

extern Service *ts4_find_service(u32 id);

static TS4_FORCEINLINE void copy_block(Block *d, const Block *r)
{
    d->a = r->a;
    d->b = r->b;
    d->c = r->c;
    d->d[0] = r->d[0];
    d->d[1] = r->d[1];
    d->d[2] = r->d[2];
    d->d[3] = r->d[3];
    d->d[4] = r->d[4];
    d->d[5] = r->d[5];
    d->e = r->e;
    d->f = r->f;
    d->g[0] = r->g[0];
    d->g[1] = r->g[1];
    d->g[2] = r->g[2];
    d->g[3] = r->g[3];
    d->g[4] = r->g[4];
    d->h = r->h;
}

u32 ts4_commit_saved_settings_8877E748(void)
{
    Service *service = ts4_find_service(0x8C5A4922);
    Settings *s = ((Settings *(*)(Service *, int))service->vtbl[0x4c / 4])(service, 0);

    copy_block(&s->current, &s->saved);
    return 0;
}

u32 ts4_stash_current_settings_8877E818(void)
{
    Service *service = ts4_find_service(0x8C5A4922);
    Settings *s = ((Settings *(*)(Service *, int))service->vtbl[0x4c / 4])(service, 0);

    copy_block(&s->saved, &s->current);
    return 0;
}
