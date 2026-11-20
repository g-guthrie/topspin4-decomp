/* CW8 part d: log helper, scoped hook, global field swaps. Built with /Oc. */
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wtautological-pointer-compare"
#endif
#include "fam4_refstr.h"
#ifdef _MSC_VER
typedef char *ts4_va_list;
#define TS4_VA_START(ap, v) __va_start(&ap, v)
#else
#include <stdarg.h>
typedef va_list ts4_va_list;
#define TS4_VA_START(ap, v) va_start(ap, v)
#endif
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned int cw8_uptr;
#else
typedef unsigned long cw8_uptr;
#endif

typedef struct Cw8LogVt { void *s[4]; void *(*get)(void *); } Cw8LogVt;
typedef struct Cw8LogSvc { const Cw8LogVt *vt; } Cw8LogSvc;
typedef struct Cw8Logger Cw8LoggerT;
struct Cw8Logger { void *hook; u32 pad4[3]; void *enabled; void (*emit)(struct Cw8Logger *, char *); };
typedef struct Cw8Logger Cw8Logger;

extern Cw8LogSvc *lbl_88D3E418;
extern Cw8Logger lbl_88D4886C;
extern Cw8LogSvc *ts4_if_get_u32_lbl_88D45B38_8819A938(void);
extern void fn_8819C000(char **out, const char *fmt, ts4_va_list ap);

/* 0x881E4EC0: format into a temporary string on the default allocator, hand it to the logger hook, release it */
void ts4_log_format_881E4EC0(const char *fmt, ...)
{
    char *text;
    char *out;
    ts4_va_list ap;
    Cw8LogSvc *svc = lbl_88D3E418;
    if (svc == 0)
        svc = ts4_if_get_u32_lbl_88D45B38_8819A938();
    text = (char *)svc->vt->get(svc) + 0x10;
    TS4_VA_START(ap, fmt);
    fn_8819C000(&text, fmt, ap);
    out = *(char *volatile *)&text;
    if (lbl_88D4886C.enabled != 0 || lbl_88D4886C.hook != 0)
        lbl_88D4886C.emit(&lbl_88D4886C, out);
    ts4_str_release(out);
}

typedef void (*Cw8Hook)(void);
extern void ts4_if_call_seq_fn_881991A0_881E39E0(void);
extern void ts4_if_call_seq_fn_885651F8_88813510(void);
extern Cw8Hook lbl_88C6A10C;
extern void *lbl_88D459EC;
extern void *lbl_88D41FC0;
extern void ts4_if_addr_lbl_880E17D8_88836040(void *arg);

/* 0x881E3D40: run the callee with the scoped hook and context installed (context defaults to the global one), then restore both */
void ts4_with_hook_881E3D40(void *ctx, void *arg)
{
    Cw8Hook prev_hook = lbl_88C6A10C;
    void *prev_ctx = lbl_88D459EC;
    if (ctx == 0)
        ctx = lbl_88D41FC0;
    lbl_88C6A10C = ts4_if_call_seq_fn_881991A0_881E39E0 != 0 ? ts4_if_call_seq_fn_881991A0_881E39E0 : ts4_if_call_seq_fn_885651F8_88813510;
    lbl_88D459EC = ctx;
    ts4_if_addr_lbl_880E17D8_88836040(arg);
    lbl_88D459EC = prev_ctx;
    lbl_88C6A10C = prev_hook != 0 ? prev_hook : ts4_if_call_seq_fn_885651F8_88813510;
}

typedef struct Cw8Globals { u8 pada8[0xac]; u32 fac; u32 fb0; u32 fb4; float fb8; } Cw8Globals;
typedef struct Cw8Saved { u32 f0; u32 f4; u32 f8; float fc; } Cw8Saved;
typedef struct Cw8SrcA { u8 pad[0x6cc]; u32 f6cc; void *f6d0; u8 pad6d4[8]; u32 f6dc; float f6e0; } Cw8SrcA;
typedef struct Cw8SrcB { u8 pad[8]; u32 f8; void *fc; u32 f10; u32 f14; float f18; } Cw8SrcB;
extern Cw8Globals *lbl_88D41FC4;
extern void *fn_881CFD48(void *p);

/* 0x881E3DD0: save the four global fields into out and install the ones from src (resolving the pointer field) */
Cw8Saved *ts4_globals_swap_a_881E3DD0(Cw8Saved *out, Cw8SrcA *src)
{
    Cw8Globals *g = lbl_88D41FC4;
    void *p;
    out->f0 = g->fb0;
    out->f4 = g->fac;
    out->f8 = g->fb4;
    out->fc = g->fb8;
    g->fb0 = src->f6cc;
    p = src->f6d0;
    if (p != 0) {
        p = fn_881CFD48(p);
        g = lbl_88D41FC4;
    } else {
        p = 0;
    }
    g->fac = (u32)(cw8_uptr)p;
    g->fb4 = src->f6dc;
    g->fb8 = src->f6e0;
    return out;
}

/* 0x881E3E50: same as 0x881E3DD0 with the source record laid out compactly */
Cw8Saved *ts4_globals_swap_b_881E3E50(Cw8Saved *out, Cw8SrcB *src)
{
    Cw8Globals *g = lbl_88D41FC4;
    void *p;
    out->f0 = g->fb0;
    out->f4 = g->fac;
    out->f8 = g->fb4;
    out->fc = g->fb8;
    g->fb0 = src->f8;
    p = src->fc;
    if ((long)p != 0) {
        p = fn_881CFD48(p);
        g = lbl_88D41FC4;
    } else {
        p = 0;
    }
    g->fac = (u32)(cw8_uptr)p;
    g->fb4 = src->f14;
    g->fb8 = src->f18;
    return out;
}
