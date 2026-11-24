/* PR3 DRAFT: CFileSystemPackArchive constructor (not compiled into the build).
 *
 * 0x88626840 (0xb4) ts4_pack_archive_ctor_88626840 - 15 instructions differ: only the order in which the
 *   constants (vtable lis/addi, the name string, -1, 3) are materialised at the top; every store is in target
 *   order and the dead `addi r11,r31,0x64` is reproduced by the sub-object helper. Tried: non-volatile vtable
 *   and name stores first. fn_equiv: EQUIVALENT, 152 valid trials, 100% coverage.
 *
 * What it does: base file-system constructor (fn_8861B128), vtable 0x880F8440, clears the flags at +0x24/+0x25,
 * +0x28, the base stream +0x2C, +0x40, name +0x44 = empty string (lbl_880D1F0C); the in-memory block at +0x64:
 * flag +0x64 = 0, +0x68 = -1, +0x70 = 3, image vector +0x7C..+0x84 = 0, more flags and words to +0x9E; then
 * InitializeCriticalSection(+0x48) (the lock taken by 0x88613EB8).
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifndef _MSC_VER
#define __forceinline inline
#define __inline inline
#endif
extern char lbl_880F8440[];
extern char lbl_880D1F0C[];
void fn_8861B128(void *o);
void RtlInitializeCriticalSection(void *cs);

typedef struct MemImage { u8 *data; int size; } MemImage;
typedef struct PackArchive {
    void *vt;            /* 0x00 */
    char pad04[0x20];
    u8 f24;              /* 0x24 */
    u8 track_pos;        /* 0x25 */
    u32 f28;             /* 0x28 */
    void *base;          /* 0x2c */
    char pad30[4];
    int data_start;      /* 0x34 */
    void *fat;           /* 0x38 ? */
    void *f3c;           /* 0x3c FAT table */
    int last_pos;        /* 0x40 */
    const char *name;    /* 0x44 */
    u32 cs[7];           /* 0x48 */
    struct Sub64 {
        u8 in_memory;        /* 0x64 */
        u8 pad65[3];
        int f68;             /* 0x68 */
        u8 f6c;              /* 0x6c */
        u8 pad6d[3];
        int f70;             /* 0x70 */
        u32 f74;
        u8 f78;              /* 0x78 */
        u8 pad79[3];
        struct Vec3 { MemImage *image; u32 f80; u32 f84; } v;     /* 0x7c */
        u8 f88;
        u8 f89;
        u8 pad8a[2];
        u32 f8c;
        u32 f90;
        u32 f94;
        u32 f98;
        u8 f9c;
        u8 pad9d;
        u8 f9e;
    } sub;
} PackArchive;
static __inline void vec_init(volatile struct Vec3 *v) { v->image = 0; v->f80 = 0; v->f84 = 0; }
static __inline void sub_init(volatile struct Sub64 *s)
{
    s->in_memory = 0;
    s->f6c = 0;
    s->f78 = 0;
    s->f68 = -1;
    s->f70 = 3;
    vec_init(&s->v);
    s->f88 = 0;
    s->f89 = 0;
    s->f8c = 0;
    s->f90 = 0;
    s->f94 = 0;
    s->f98 = 0;
    s->f9c = 0;
    s->f9e = 0;
}

PackArchive *ts4_pack_archive_ctor_88626840(PackArchive *o)
{
    volatile PackArchive *v = o;
    fn_8861B128(o);
    v->f24 = 0;
    v->track_pos = 0;
    v->f28 = 0;
    v->vt = lbl_880F8440;
    v->base = 0;
    v->last_pos = 0;
    v->name = lbl_880D1F0C;
    sub_init(&o->sub);
    RtlInitializeCriticalSection(o->cs);
    return o;
}
