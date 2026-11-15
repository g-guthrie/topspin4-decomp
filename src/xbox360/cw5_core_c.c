/* Swing_DLL.xex game core 0x8818C6C0-0x8819C000: hand-written, second batch. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned int cw5_uptr;
#else
typedef unsigned long cw5_uptr;
#endif
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

char *fn_8819B5F8(char **self, u32 newlen);
void *fn_88562DC0(void *, void *, u32);
u32 fn_881992A8(u32, void *);
u32 fn_88198CE0(u32);
void ts4_string_unshare_8819B308(char **self);
char *ts4_wide_to_narrow_copy_88199DC0(char *dst, int cap, const unsigned short *src);

/* 0x8819B208: assign a narrow string from a wide C string (empty or null unshares) */
char **ts4_string_assign_from_wide_8819B208(char **self, const unsigned short *src)
{
    if (src != 0) {
        int n = 0;
        if (src[0] != 0) {
            const unsigned short *p = src;
            do { p++; n++; } while (*p != 0);
            if (n > 0) {
                char *buf = fn_8819B5F8(self, n);
                ts4_wide_to_narrow_copy_88199DC0(buf, n, src);
                ((int *)*self)[-3] = n;
                (*self)[n] = 0;
                return self;
            }
        }
    }
    ts4_string_unshare_8819B308(self);
    return self;
}

/* 0x8819B448: assign n bytes (source may lie inside the string itself) */
void ts4_string_assign_range_8819B448(char **self, char *from, int n)
{
    if (n == 0) {
        ts4_string_unshare_8819B308(self);
    } else {
        u32 off = from - *self;
        u32 len = ((u32 *)*self)[-3];
        char *nb = fn_8819B5F8(self, n);
        if (!(off > len))
            fn_88562DC0(nb, nb + off, n);
        else
            memcpy(nb, from, n);
        ((u32 *)*self)[-3] = n;
        (*self)[n] = 0;
    }
}

/* shared sub-object: vtable plus a handle released through ts4_if_get_u32_lbl_88C32048_8857A1E0 */
struct cw5_handle_sub { void *vt; void *h; };
extern char lbl_880DCF20[], lbl_880DCF30[], lbl_880DD088[];
void ts4_if_get_u32_lbl_88C32048_8857A1E0(void *);
static void cw5_handle_sub_dtor(struct cw5_handle_sub *sub)
{
    sub->vt = lbl_880DCF20;
    if (sub->h) {
        ts4_if_get_u32_lbl_88C32048_8857A1E0(sub->h);
        sub->h = 0;
    }
}

/* 0x88197A28: destructor: release the object at 0x7C, sub-object at 0xA0 */
struct cw5_dtor_a { void *vt; u8 pad[0x6c]; u32 f70; u32 pad74[2]; u32 f7c; u8 pad80[0x10]; u32 f90; u8 pad94[8]; u32 f9c; struct cw5_handle_sub sub; };
extern char lbl_880DD528[];
void ts4_if_call_seq_u32_lbl_88D45B38_88199880(u32, u32, u32, u32);
void ts4_cw5_obj_dtor_88197A28(struct cw5_dtor_a *self)
{
    self->vt = lbl_880DD528;
    if (self->f7c) {
        ts4_if_call_seq_u32_lbl_88D45B38_88199880(self->f7c, self->f90, self->f9c, self->f70);
        self->f7c = 0;
    }
    cw5_handle_sub_dtor(&self->sub);
    self->vt = lbl_880DD088;
}

/* 0x88197F90: constructor with a critical-section holder at 0x98 */
struct cw5_cs_holder { void *vt; u32 f4; u8 cs[0x1c]; };
struct cw5_cs_obj2 { void *vt; u8 pad[0x78]; u32 f7c, f80, f84, f88, f8c, f90, f94; struct cw5_cs_holder h; };
extern char lbl_880DD640[];
void fn_88197E10(void *);
cw5_uptr RtlInitializeCriticalSection(cw5_uptr);
static void cw5_cs_holder_init(struct cw5_cs_holder *h)
{
    h->vt = lbl_880DCF30;
    h->f4 = 0;
    RtlInitializeCriticalSection((cw5_uptr)&h->cs);
}
struct cw5_cs_obj2 *ts4_cs_obj_ctor_88197F90(struct cw5_cs_obj2 *self)
{
    fn_88197E10(self);
    self->f7c = 0;
    self->f90 = 0x10;
    self->f94 = 0x10;
    self->vt = lbl_880DD640;
    self->f80 = 0;
    self->f84 = 0;
    self->f88 = 0;
    self->f8c = 0;
    cw5_cs_holder_init(&self->h);
    return self;
}


/* 0x8819AC38: build a narrow string from a wide C string with the default owner */
extern u32 lbl_88D3E414;
u32 fn_8819A9D8(void);
char **fn_8819C128(char **, const unsigned short *, int, u32);
char **ts4_string_from_wide_default_owner_8819AC38(char **self, const unsigned short *src)
{
    u32 def = lbl_88D3E414;
    u32 owner;
    int n;
    if (def != 0)
        owner = def;
    else
        owner = fn_8819A9D8();
    n = 0;
    if (src != 0) {
        unsigned short c = src[0];
        const unsigned short *p = src;
        if (c != 0) {
            do { p++; n++; } while (*p != 0);
        }
    }
    fn_8819C128(self, src, n, owner);
    return self;
}

/* 0x8818E3F0: run fn_8818E480(fn_8818EA28(...)) under the optional critical section at 0x20 */
struct cw5_locked { u8 pad[4]; u32 f4; u8 pad8[0xc]; int f14; u8 cs_holder[0x20]; };
u32 fn_8818EA28(void *, u32);
u32 fn_8818E480(void *, u32, u32);
cw5_uptr RtlEnterCriticalSection(cw5_uptr);
cw5_uptr RtlLeaveCriticalSection(cw5_uptr);
u32 ts4_locked_call_8818E3F0(struct cw5_locked *self, u32 a, u32 b)
{
    int f14 = self->f14;
    u8 *sub = self->cs_holder;
    int locked = 0;
    u32 saved, r;
    if (f14 == -1) {
        RtlEnterCriticalSection((cw5_uptr)(sub + 8));
        locked = 1;
    }
    saved = fn_88198CE0(self->f4);
    r = fn_8818E480(self, fn_8818EA28(self, a), b);
    fn_88198CE0(saved);
    if (locked != 0 && f14 == -1)
        RtlLeaveCriticalSection((cw5_uptr)(sub + 8));
    return r;
}

/* 0x8819BB70: strip leading characters that are in the set at lbl_880E1930 */
extern char lbl_880E1930[];
char **fn_8819BCC0(char **, const char *);
char *fn_88563500(const char *, int);
char **ts4_string_trim_leading_8819BB70(char **self)
{
    char **r = fn_8819BCC0(self, lbl_880E1930);
    unsigned char *p = (unsigned char *)*r;
    if (*p != 0) {
        do {
            if (fn_88563500(lbl_880E1930, (signed char)*p) == 0) break;
            p++;
        } while (*p != 0);
    }
    if ((char *)p != *r) {
        int off = (char *)p - *r;
        int len;
        char *nb = fn_8819B5F8(r, ((int *)*r)[-3]);
        len = ((int *)*r)[-3] - off;
        fn_88562DC0(nb, nb + off, len + 1);
        ((int *)*r)[-3] = len;
        (*r)[len] = 0;
    }
    return r;
}

/* 0x8819BC18: strip a trailing run of backslashes */
char **ts4_string_trim_trailing_backslashes_8819BC18(char **self)
{
    char *start = *self;
    char *p = start;
    char *run = 0;
    int c = (signed char)*start;
    while (c != 0) {
        if (c == '\\') {
            if (run == 0) run = p;
        } else {
            run = 0;
        }
        p++;
        c = (signed char)*p;
    }
    if (run != 0) {
        int n = run - start;
        fn_8819B5F8(self, n);
        ((int *)*self)[-3] = n;
        (*self)[n] = 0;
    }
    return self;
}

/* 0x88199C08: clone a counted block (0x10-byte header + count * element) through the owner's slot 1, preserving field 8 */
struct cw5_blk { u32 f0; u32 elem_size; u32 f8; };
struct cw5_blk_vt { void *s0; struct cw5_blk *(*alloc)(void *self, u32 a, u32 count); };
struct cw5_blk_owner { struct cw5_blk_vt *vt; u8 pad[0x18]; u32 f1c; };
struct cw5_blk *ts4_block_clone_88199C08(struct cw5_blk_owner *self, struct cw5_blk *src, u32 a, u32 count)
{
    u32 saved = fn_88198CE0(self->f1c);
    u32 total = src->elem_size * count + 0x10;
    struct cw5_blk *nb = self->vt->alloc(self, a, count);
    u32 keep = nb->f8;
    memcpy(nb, src, total);
    nb->f8 = keep;
    fn_881992A8(0, src);
    fn_88198CE0(saved);
    return nb;
}

/* 0x88196A60: run fn_8857BBB0 on the handle at 0x10; returns its result or 0 (sets error 3 at 0x18) */
extern u32 lbl_88D3E3A4;
struct cw5_runner { u8 pad[0x10]; u32 h; u32 pad14; u32 err; };
u32 fn_8857BA40(u32, u32, u32, u32);
int fn_8857BBB0(u32, u32, u32, u32 *, void *);
u32 ts4_runner_exec_88196A60(struct cw5_runner *self, u32 a, u32 b, u32 c)
{
    u32 saved = fn_88198CE0(lbl_88D3E3A4);
    u32 out;
    u32 res;
    struct { u32 w[5]; } args;
    if (b == 0) {
        fn_88198CE0(saved);
        return 0;
    }
    if ((int)c == -1)
        c = fn_8857BA40(self->h, 0, 0, 1);
    args.w[1] = 0;
    args.w[2] = c;
    args.w[0] = 0;
    args.w[3] = 0;
    args.w[4] = 0;
    if (fn_8857BBB0(self->h, a, b, &out, &args) == 0) {
        self->err = 3;
        fn_88198CE0(saved);
        return 0;
    }
    res = out;
    fn_88198CE0(saved);
    return res;
}
