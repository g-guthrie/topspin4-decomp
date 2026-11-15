/*
 * DRAFT (not byte-matched): message-box worker thread, frontend-map section 1.3 ("other XN_SYS_UI loops").
 *
 * 0x88885820 (0x258) thread body that shows one system message box and waits for it to go away.
 *   job+0x34 is a cookie copied into the current thread's info record (fn_88883CD0(0) +0x4/+0xC); when
 *   non-zero the heap at [0x88D45B38] gets +0x20 = 0.  job+0x38 is the request:
 *     +0x0C result record {+0 done byte, +4 pressed button, +0xC cancelled}, +0x10 title, +0x14 text,
 *     +0x18 type (0 -> 1 button, 1/2 -> 2 buttons), +0x1C focus button, +0x20 XMB flags,
 *     +0x24 "any user" byte, +0x28 pad index, +0x2C completion callback(req), +0x30/+0x34 button strings
 *     (copied into the global array 0x88D4BD1C that is passed as the button list).
 *   Steps: create an event for an XOVERLAPPED (fn_8857B6D8 = CreateEvent), create an XN_SYS listener,
 *   clear result+4/+0xC, pick the user (0xFF = any, or the pad record's +0x10, -1 when the pad has no
 *   record), call XamShowMessageBoxUI (fn_8857A6D0) REPEATEDLY until it returns ERROR_IO_PENDING (0x3E5),
 *   block in XGetOverlappedResult(&ov, 0, TRUE) (fn_8857A130), close the event, wait for XN_SYS_UI to go
 *   to non-zero and then back from 1, close the listener, set result+0xC = 1 when the result was
 *   ERROR_CANCELLED (0x4C7), call the callback, set result+0 = 1, job+0x30 = 0, job+0x40 = 1 and exit the
 *   thread (ts4_tailcall_fn_885827E0_88563110(0)).
 *   Port note: the XamShowMessageBoxUI retry loop spins forever if the call never returns
 *   ERROR_IO_PENDING, and both XN_SYS_UI waits spin until the notification arrives.
 *   14 instructions off: the original re-loads the callback through a forwarded copy (clrrwi r11,r11,0
 *   before mtctr), which shifts the tail by one instruction.  Reading the request through a local
 *   (`r = job->req; if (r->on_done) req_of(job)->on_done(r);`) gives the clrrwi and the exact size, but
 *   swaps r29/r30 (19 off).  Tried: inline accessors in several places, u32 casts, 0..6 dead locals,
 *   250 permutations of declarations and the setup stores.
 * fn_equiv (work/equiv/pr2_88885820.json): EQUIVALENT, 210 valid trials, 90% block coverage.
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
#ifndef _MSC_VER
#define __emit(x) ((void)(x))
#endif
typedef struct XOverlapped { u32 internal_low; u32 internal_high; u32 internal_context; void *event; void *completion; u32 context; u32 extended_error; } XOverlapped;
typedef struct MsgResult { u8 done; u8 pad1[3]; u32 button; u8 pad8[4]; u32 cancelled; } MsgResult;
typedef struct MsgBoxReq MsgBoxReq;
struct MsgBoxReq {
    u8 pad[0xc]; MsgResult *result; const u16 *title; const u16 *text; u32 type; u8 focus; u8 pad1d[3];
    u32 flags; u8 any_user; u8 pad25[3]; int pad_index; void (*on_done)(struct MsgBoxReq *r); const u16 *button0; const u16 *button1;
};
typedef struct ThreadInfo { u8 pad[4]; u32 f4; u8 pad8[4]; u32 fc; } ThreadInfo;
typedef struct Heap { u8 pad[0x20]; u8 b20; } Heap;
typedef struct MsgBoxJob { u8 pad[0x30]; u8 running; u8 pad31[3]; u32 cookie; MsgBoxReq *req; u8 pad3c[4]; u8 finished; } MsgBoxJob;
typedef struct PadObj { u8 pad[0x10]; u32 user; } PadObj;
typedef struct ModList ModList;
typedef struct Engine { u8 pad[0x234]; ModList *modules; } Engine;
#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif
extern Heap *lbl_88D45B38;
extern Engine *lbl_88D45B1C;
extern const u16 *lbl_88D4BD1C[2];
extern ThreadInfo *fn_88883CD0(u32 off);
extern void *fn_8857B6D8(void *a, u32 b, u32 c, void *d);
extern void *ts4_tailcall_XamNotifyCreateListener_8857A988(u32 areas);
extern PadObj *ts4_pad_record_find_88614938(ModList *m, int pad);
extern u32 fn_8857A6D0(u32 user, const u16 *title, const u16 *text, u32 count, const u16 **buttons, u32 focus, u32 flags, u32 *result, XOverlapped *ov);
extern u32 fn_8857A130(XOverlapped *ov, u32 *bytes, u32 wait);
extern u32 ts4_if_get_u32_lbl_88C32048_8857A1E0(void *h);
extern int XNotifyGetNext(void *listener, u32 id, u32 *out_id, int *out_param);
extern void ts4_tailcall_fn_885827E0_88563110(u32 code);

u32 ts4_message_box_thread_88885820(MsgBoxJob *job)
{
    u32 cookie = job->cookie;
    Heap *heap = lbl_88D45B38;
    ThreadInfo *ti = fn_88883CD0(0);
    u32 counts[3];
    XOverlapped ov;
    void *l;
    u32 user;
    u32 res;
    u32 id;
    int param;
    if (ti) {
        ti->fc = cookie;
        ti->f4 = cookie;
    }
    if (cookie)
        heap->b20 = 0;
    lbl_88D4BD1C[0] = job->req->button0;
    counts[0] = 1;
    counts[1] = 2;
    counts[2] = 2;
    lbl_88D4BD1C[1] = job->req->button1;
    memset(&ov, 0, sizeof(ov));
    ov.event = fn_8857B6D8(0, 0, 0, 0);
    l = ts4_tailcall_XamNotifyCreateListener_8857A988(1);
    user = 0xff;
    job->req->result->button = 0;
    job->req->result->cancelled = 0;
    if (job->req->any_user == 0) {
        PadObj *p = ts4_pad_record_find_88614938(lbl_88D45B1C->modules, job->req->pad_index);
        if (p)
            user = p->user;
        else
            user = 0xffffffff;
    }
    do {
        MsgBoxReq *r = job->req;
        res = fn_8857A6D0(user, r->title, r->text, counts[r->type], lbl_88D4BD1C, r->focus, r->flags, &r->result->button, &ov);
    } while (res != 0x3e5);
    res = fn_8857A130(&ov, 0, 1);
    ts4_if_get_u32_lbl_88C32048_8857A1E0(ov.event);
    do {
        while (!XNotifyGetNext(l, 9, &id, &param))
            __emit(0x7ffffb78);
    } while (param == 0);
    do {
        while (!XNotifyGetNext(l, 9, &id, &param))
            __emit(0x7ffffb78);
    } while (param == 1);
    ts4_if_get_u32_lbl_88C32048_8857A1E0(l);
    if (res == 0x4c7)
        job->req->result->cancelled = 1;
    if (job->req->on_done)
        job->req->on_done(job->req);
    job->req->result->done = 1;
    job->running = 0;
    job->finished = 1;
    ts4_tailcall_fn_885827E0_88563110(0);
    return 0;
}
