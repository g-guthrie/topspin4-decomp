/*
 * DRAFT (not part of the matching build). PR1, wave PR1.
 * 0x887CAE50 CRenderHardwareInterface_Xenon::Init (0x694 B, virtual), docs/renderer-map.md section 2.1.
 *
 * Status: plain route, 396 instructions differ (candidate 0x69C B); same call sequence and the same 57
 * relocations. Not tuned: a first full reading. Known differences: the XData default/getter selects are
 * written as ?: (the target branches the same way but allocates differently); the reference increment at the
 * end is an mfmsr / mtmsrd r13 / lwarx / stwcx. / mtmsrd sequence in the target (XDK interlocked increment
 * with interrupts masked), written here as _InterlockedIncrement.
 *
 * Call: Init(this, Pr1Handle12 args) with `args` the 12-byte XData node handle of the module, passed by value
 * in r4/r5 and stored at this+0x170.
 * Order of operations:
 *  1. base Init fn_88627EC0(this, args); this->args = args.
 *  2. hand-over: p = *(engine singleton 0x88D45B1C + 0x2CC); if set call p->+0x2AE0 (when non-null) and take
 *     existing = p->+0x2AD8 (an already created D3D device).
 *  3. D3DPRESENT_PARAMETERS on the stack (0x7C B, zeroed) from XData: node = args/0x90136F64, bb =
 *     node/0x623CC12C. BackBufferFormat: name string (bb key 0xD91677E9; through the XData object's slot
 *     0x50, or when engine+0x276 is set from an int: 0x14/0x16/other -> three built-in names), CRC32 of the
 *     name (fn_88608590(0, s)) looked up in the 6-entry {hash, format} table at 0x88C6C404, default
 *     0x18280186. Then (default when the key is absent, i.e. ref offset == 0xFFFFF):
 *     BackBufferCount bb/0x44186B66 (1), EnableAutoDepthStencil 0x27463AE7 (1), AutoDepthStencilFormat
 *     0x50182F1E (0x2D200196), SwapEffect 0xD54CBE48 (1), DisableAutoBackBuffer = (0xF51D02D7 == 1),
 *     DisableAutoFrontBuffer = (0x54966111 == 1), FrontBufferFormat bb/0x6B631DAE (0x28280186),
 *     MultiSampleQuality 0xE86ED732 (0), Flags 0xCAC46EBE (0), PresentationInterval 0x13777CB2 (0x80000000).
 *  4. XGetVideoMode: widescreen -> 1280x720 and Flags = 0, else 1088x816. this+0x64/+0x68 = size,
 *     +0x6C = aspect (float), +0x84 = widescreen, +0x86 = (video standard == 3), +0x85 = 1, +0x110 = 1.
 *  5. ring buffers at this+0x118 {flags 0, 0x40000, primary, 0x500000, secondary, 0x50 segments}; both
 *     buffers from fn_8857B048(size, ~0, 0x20, 0x20000404); copied into pp+0x48.
 *  6. if this->device (+0x114) exists, release it through vtable slot 5. If this+0x16D is set, the two
 *     DisableAuto*Buffer flags are cleared.
 *  7. existing device: KeCertMonitorData callback (+4, arg 1) when present; under the device lock +0x3B34
 *     set the owner thread +0x2A88 (fn_8857C8C8) and clear bit 1 of +0x2ABE; ring re-initialisation
 *     0x88292B88(dev, &pp.ring); on success BlockUntilIdle and the video-mode set (0x882A26D8 around
 *     0x882A2430(dev, &pp)); this->device = dev; dev->refcount (+0x3C)++.
 *     otherwise: Direct3D_CreateDevice 0x88296D48(&pp, &this->device).
 *  8. this->pp (+0x8C) = pp (0x7C B); +0x88 = 0; +0x150 = 0; init the critical section +0x134;
 *     fn_887C8C68(this).
 * fn_equiv: see the PR1 report (work/equiv/pr1_887CAE50.json).
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
#ifdef _MSC_VER
#define INL static __forceinline
long _InterlockedIncrement(long volatile *p);
#pragma intrinsic(_InterlockedIncrement)
#else
#define INL static inline
static long _InterlockedIncrement(long volatile *p) { return ++*p; }
#endif
typedef struct Pr1Handle12 { u32 a, b, c; } Pr1Handle12;
typedef struct Pr1Handle16 { u32 a, b, c, d; } Pr1Handle16;
typedef struct Pr1XObj { void **vt; } Pr1XObj;
typedef struct Pr1XRef { Pr1XObj *target; u32 offset; } Pr1XRef;   /* offset 0xFFFFF = key not present */
typedef struct Pr1RingParams { u32 flags; u32 primary_size; void *primary; u32 secondary_size; void *secondary; u32 segments; } Pr1RingParams;
/* D3DPRESENT_PARAMETERS, 0x7C bytes */
typedef struct Pr1PresentParams {
    u32 width;              /* +0x00 */
    u32 height;             /* +0x04 */
    u32 bb_format;          /* +0x08 */
    u32 bb_count;           /* +0x0C */
    u32 ms_type;            /* +0x10 */
    u32 ms_quality;         /* +0x14 */
    u32 swap_effect;        /* +0x18 */
    u32 p1c, p20;
    u32 auto_depth;         /* +0x24 */
    u32 depth_format;       /* +0x28 */
    u32 flags;              /* +0x2C */
    u32 p30;
    u32 interval;           /* +0x34 */
    u32 no_auto_bb;         /* +0x38 */
    u32 no_auto_fb;         /* +0x3C */
    u32 fb_format;          /* +0x40 */
    u32 p44;
    Pr1RingParams ring;     /* +0x48 */
    u32 p60[7];
} Pr1PresentParams;
typedef struct Pr1VideoMode { u32 width, height, interlaced, widescreen, hidef, refresh, standard, p1c[5]; } Pr1VideoMode;
typedef struct Pr1FmtName { u32 hash; u32 format; } Pr1FmtName;
typedef struct Pr1RHI {
    void **vt;
    u8 p4[0x60];
    u32 width;              /* +0x64 */
    u32 height;             /* +0x68 */
    float aspect;           /* +0x6C */
    u8 p70[0x14];
    u8 widescreen;          /* +0x84 */
    u8 b85;
    u8 pal;                 /* +0x86 (video standard 3) */
    u8 p87;
    u8 b88;
    u8 p89[3];
    Pr1PresentParams pp;    /* +0x8C */
    u32 own_targets;        /* +0x108 (see renderer-map 1.3) */
    u32 p10c;
    u32 b110;
    char *device;           /* +0x114 */
    Pr1RingParams ring;     /* +0x118 */
    u32 p130;
    u8 cs[0x1c];            /* +0x134 critical section */
    u32 p150;
    u8 lock[0x18];          /* +0x154 */
    u8 p16c;
    u8 keep_auto_buffers;   /* +0x16D */
    u8 p16e[2];
    Pr1Handle12 args;       /* +0x170 */
} Pr1RHI;
extern char *lbl_88D45B1C;
extern char lbl_880EA5B4[], lbl_880EA5C4[], lbl_880EA5D4[];
extern Pr1FmtName lbl_88C6C404[6];
extern void **__imp_KeCertMonitorData;
extern void fn_88627EC0(Pr1RHI *self, Pr1Handle12 args);
extern Pr1Handle16 *ts4_handle_forward_88610A48(Pr1Handle16 *out, void *node, u32 *key);
extern Pr1XRef *ts4_handle_forward_88150770(Pr1XRef *out, void *node, u32 *key);
extern int ts4_gp0_xdata_get_int32_88163D18(Pr1XRef *r);
extern u32 ts4_if_get_u32_off0_8816CE90(Pr1XRef *r);
extern u32 ts4_gp0_xdata_get_bool_88163C60(Pr1XRef *r);
extern u32 fn_88608590(u32 seed, const char *s);
extern void ts4_memset(void *p, int v, u32 n);
extern void XGetVideoMode(Pr1VideoMode *vm);
extern void *fn_8857B048(u32 size, u32 max_addr, u32 align, u32 flags);
extern u32 fn_8857C8C8(void);
extern void RtlEnterCriticalSection(void *cs);
extern void RtlLeaveCriticalSection(void *cs);
extern void RtlInitializeCriticalSection(void *cs);
extern int fn_88292B88(char *dev, Pr1RingParams *ring);
extern void fn_88292A78(char *dev);
extern void ts4_loop_call_seq_KeGetCurrentProcessType_882A26D8(char *dev);
extern int fn_882A2430(char *dev, Pr1PresentParams *pp);
extern void fn_88296D48(Pr1PresentParams *pp, char **out_dev);
extern void fn_887C8C68(Pr1RHI *self);
extern void *memcpy(void *, const void *, unsigned long);
#define PR1_MISSING 0xFFFFF
INL Pr1XRef *pr1_xd(Pr1XRef *r, void *node, u32 key)
{
    u32 k = key;
    return ts4_handle_forward_88150770(r, node, &k);
}
void ts4_rhi_xenon_init_887CAE50(Pr1RHI *self, Pr1Handle12 args)
{
    Pr1Handle16 root, bb;
    Pr1XRef r, *pr;
    Pr1PresentParams pp = {0};
    Pr1VideoMode vm;
    char *handover;
    char *existing = 0;
    const char *fmt_name;
    u32 h, i, w, ht;
    u32 key;
    fn_88627EC0(self, args);                                   /* base-class Init */
    self->args = args;
    /* 1. device hand-over: an engine-provided pointer (engine singleton +0x2CC) */
    handover = *(char **)(lbl_88D45B1C + 0x2cc);
    if (handover != 0) {
        void (*cb)(void) = *(void (**)(void))(handover + 0x2ae0);
        if (cb != 0) cb();
        existing = *(char **)(handover + 0x2ad8);
    }
    /* 2. present parameters from XData */
    key = 0x90136F64; ts4_handle_forward_88610A48(&root, &args, &key);
    key = 0x623CC12C; ts4_handle_forward_88610A48(&bb, &root, &key);
    pr1_xd(&r, &bb, 0xD91677E9);
    if (*(u8 *)(lbl_88D45B1C + 0x276) == 0) {
        fmt_name = ((const char *(*)(Pr1XObj *, Pr1XRef *, u32, u32))r.target->vt[0x50 / 4])(r.target, &r, r.offset, 1);
    } else {
        int v = ts4_gp0_xdata_get_int32_88163D18(&r);
        if (v == 0x14) fmt_name = lbl_880EA5B4;
        else if (v == 0x16) fmt_name = lbl_880EA5D4;
        else fmt_name = lbl_880EA5C4;
    }
    h = fn_88608590(0, fmt_name);                              /* CRC32 of "D3DFMT_..." */
    {
        u8 found = 0;
        for (i = 0; i < 6; i++) {
            if (lbl_88C6C404[i].hash == h) {
                found = 1;
                pp.bb_format = lbl_88C6C404[i].format;
                break;
            }
        }
        if (!found) pp.bb_format = 0x18280186;                 /* A8R8G8B8 */
    }
    pr = pr1_xd(&r, &bb, 0x44186B66);
    pp.bb_count = pr->offset == PR1_MISSING ? 1 : ts4_if_get_u32_off0_8816CE90(pr);
    pr = pr1_xd(&r, &root, 0x27463AE7);
    pp.auto_depth = pr->offset == PR1_MISSING ? 1 : (u8)ts4_gp0_xdata_get_bool_88163C60(pr);
    pr = pr1_xd(&r, &root, 0x50182F1E);
    pp.depth_format = pr->offset == PR1_MISSING ? 0x2D200196 : (u32)ts4_gp0_xdata_get_int32_88163D18(pr);
    pr = pr1_xd(&r, &root, 0xD54CBE48);
    pp.swap_effect = pr->offset == PR1_MISSING ? 1 : (u32)ts4_gp0_xdata_get_int32_88163D18(pr);
    pr = pr1_xd(&r, &root, 0xF51D02D7);
    pp.no_auto_bb = (pr->offset == PR1_MISSING ? 1 : ts4_if_get_u32_off0_8816CE90(pr)) == 1;
    pr = pr1_xd(&r, &root, 0x54966111);
    pp.no_auto_fb = (pr->offset == PR1_MISSING ? 1 : ts4_if_get_u32_off0_8816CE90(pr)) == 1;
    pr = pr1_xd(&r, &bb, 0x6B631DAE);
    pp.fb_format = pr->offset == PR1_MISSING ? 0x28280186 : (u32)ts4_gp0_xdata_get_int32_88163D18(pr);
    pp.ms_type = 0;
    pr = pr1_xd(&r, &root, 0xE86ED732);
    pp.ms_quality = pr->offset == PR1_MISSING ? 0 : (u32)ts4_gp0_xdata_get_int32_88163D18(pr);
    pr = pr1_xd(&r, &root, 0xCAC46EBE);
    pp.flags = pr->offset == PR1_MISSING ? 0 : (u32)ts4_gp0_xdata_get_int32_88163D18(pr);
    pr = pr1_xd(&r, &root, 0x13777CB2);
    pp.interval = pr->offset == PR1_MISSING ? 0x80000000 : ts4_if_get_u32_off0_8816CE90(pr);
    pp.p1c = 0;
    pp.p20 = 0;
    pp.p30 = 0;
    /* 3. video mode: 1280x720 on a widescreen mode, else 1088x816 */
    ts4_memset(&vm, 0, sizeof(vm));
    XGetVideoMode(&vm);
    self->b110 = 1;
    self->b85 = 1;
    if (vm.widescreen != 0) {
        w = 1280;
        pp.flags = 0;
        ht = 720;
    } else {
        w = 1088;
        ht = 816;
    }
    pp.width = w;
    pp.height = ht;
    self->width = w;
    self->height = ht;
    self->aspect = (float)w / (float)ht;
    self->widescreen = vm.widescreen != 0;
    self->pal = vm.standard == 3;
    /* 4. ring buffers: primary 0x40000 B, secondary 0x500000 B, 0x50 segments (physical allocations) */
    self->ring.flags = 0;
    self->ring.primary_size = 0x40000;
    self->ring.primary = fn_8857B048(0x40000, 0xFFFFFFFF, 0x20, 0x20000404);
    self->ring.secondary_size = 0x500000;
    self->ring.secondary = fn_8857B048(0x500000, 0xFFFFFFFF, 0x20, 0x20000404);
    self->ring.segments = *(u16 *)&self->ring.secondary_size;
    pp.ring = self->ring;
    if (self->device != 0) ((void (*)(Pr1RHI *))self->vt[5])(self);   /* release the previous device */
    {
        u32 keep = self->keep_auto_buffers == 0;
        pp.no_auto_bb &= keep;
        pp.no_auto_fb &= keep;
    }
    if (existing != 0) {
        /* branch A: adopt the device created by the previous module; only re-point it at the new ring */
        void **cert = (void **)*__imp_KeCertMonitorData;
        if (cert != 0 && cert[1] != 0) ((void (*)(u32))cert[1])(1);
        RtlEnterCriticalSection(existing + 0x3b34);
        *(u32 *)(existing + 0x2a88) = fn_8857C8C8();           /* owning thread */
        *(u8 *)(existing + 0x2abe) &= ~2;
        RtlLeaveCriticalSection(existing + 0x3b34);
        if (fn_88292B88(existing, &pp.ring) == 0) {
            fn_88292A78(existing);                             /* BlockUntilIdle */
            ts4_loop_call_seq_KeGetCurrentProcessType_882A26D8(existing);
            if (fn_882A2430(existing, &pp) == 0) ts4_loop_call_seq_KeGetCurrentProcessType_882A26D8(existing);
        }
        self->device = existing;
        /* the target inlines an mfmsr/mtmsrd-bracketed lwarx/stwcx. increment here */
        _InterlockedIncrement((long volatile *)(existing + 0x3c));
    } else {
        /* branch B: Direct3D_CreateDevice */
        fn_88296D48(&pp, &self->device);
    }
    memcpy(&self->pp, &pp, 0x7c);
    self->b88 = 0;
    self->p150 = 0;
    RtlInitializeCriticalSection(self->cs);
    fn_887C8C68(self);
}
