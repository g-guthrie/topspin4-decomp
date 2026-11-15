/*
 * DRAFT (not part of the matching build). PR2.
 * Swing_DLL.xex fn_886345E0 (0x886345E0, size 0x1094): the module manager state machine that switches
 * Parts (scheduler module sets). Called once per frame; `this` is the ModuleManager object.
 *
 * Byte match: no. fn_check: 1025 of 1061 instructions differ (candidate 0x1084 bytes; about 380 differ after
 * normalising stack offsets and register numbers). The control flow and call sequence are the original's;
 * the frame layout, register allocation and block order are not (not attempted beyond one compile:
 * 0x1094 bytes, 8 states, 18 saved registers).
 * fn_equiv: EQUIVALENT, 3162 valid trials of 3439, block coverage 98% (190/193)
 *   (work/equiv/pr2_886345E0.json, --trials 4000).
 *
 * What it does (state at this+0x2c; engine = [0x88D45B1C]; listener = this+0x50, the CLoadingManager,
 * vtable 0x880DB408; req = this+0x4c, the ModuleManager XData record; desc = this+0x44, the new module's
 * ModuleList record, stride 0xA4, hash at +0x90):
 *   5 idle: if req->next (+0x18, @NextModule) differs from the running module (this+0x1c ->+4) or
 *     req->force (+0x2a) is set, find the record in req+0xc (self-relative array). Then: req->busy (+0x28) = 1,
 *     prev_desc = desc, desc = found, req->prev (+0x1c) = previous hash, create the loading context
 *     (this+0x28) with the resource pointers desc+0x2c/+0x38/+0x60, the phase processor this+0x20 from desc,
 *     listener slot 10, listener slot 14 mode 0 (shows S4Loading), state 0.
 *   0 unload: wait until the frame counter [0x88D493A8] >= 60, listener slot 13 says the loading screen is up
 *     and ctx+0x18 is ready; listener slot 17 mode 0; pop and delete the old modules (this+0x54..+0x58);
 *     listener slot 14 mode 2; exit the old module set (on a worker thread when engine+0x24d and desc+0xA1),
 *     wait for *this+0x30; delete it; listener slot 17 mode 1, slot 11; state 1. engine+0x278 = 6.
 *   1 load: wait for ctx+0x20 and the old module's flag 0x893C846D; listener slot 15; slot 17 mode 2 (the
 *     part's data is loaded: CLoadingManager copies match settings, e.g. fn_888E6FF8 for InGame); build the
 *     new module set from the scheduler (this+0x34) and the service desc+0x9C, keys 0xE93DDFF8/0x4A6AA315;
 *     listener slot 16; processor = desc+0x28 config; state 2.
 *   2 init: run the new module set's Init (slot 4) with ctx+0x30, wait for *this+0x30; scheduler Exit; slot 17
 *     mode 3; state 3.
 *   3: wait for ctx+0x24 and flag 0x7F2E277D; slot 17 mode 4; engine+0x278 = 7; processor = desc+0x50 config;
 *     state 4.
 *   4 start: wait for ctx+0x28, flag 0x996A9DB7, at least desc+0x70 frames ([0x88D493A4]) and, if desc+0x74,
 *     fn_88943390; delete the processor, free the context, state 5, engine+0x278 = 2, listener slot 12 (the
 *     part has started), req->busy = 0, running module +8 = 1; for InGame call fn_888DB268.
 * Each wait that fails runs one Update of the current processor and returns (next frame retries).
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline __attribute__((unused))
#endif
typedef struct Tri { u32 a, b, c; } Tri;
typedef struct H16 { u32 w[4]; } H16;
typedef struct Str { char *p; u32 a, b; } Str;

#define PART_INGAME 0x1DCA7285u

/* Generic virtual object: slot 0 = deleting destructor, 1 = clone/addref, 2 = Update, 4 = Init, 5 = Exit. */
typedef struct VObj VObj;
typedef struct VObjVt {
    void (*destroy)(VObj *o, int flags);   /* +0x00 */
    VObj *(*slot1)(VObj *o);               /* +0x04 */
    void (*update)(VObj *o);               /* +0x08 */
    void *slot3;                           /* +0x0c */
    void (*init)(VObj *o, Tri t);          /* +0x10 */
    void (*exit)(VObj *o);                 /* +0x14 */
} VObjVt;
struct VObj { VObjVt *vt; u32 id_hash; u8 done; };

/* One ModuleList/Module record (stride 0xA4) of the scheduler config. */
typedef struct ModuleDesc {
    u8 pad[0x28];
    u8 proc_b[0x28];         /* +0x28 processor config for the load phase */
    u8 proc_c[0x10];         /* +0x50 processor config for the start phase */
    u8 pad60[0x10];
    u32 min_frames;          /* +0x70 minimum frames in the final phase */
    u8 wait_extra;           /* +0x74 also wait for fn_88943390 */
    u8 pad75[0x1b];
    u32 hash;                /* +0x90 crc32 of the module (Part) name */
    int name_rel;            /* +0x94 self-relative name string */
    u8 pad98[4];
    u32 service;             /* +0x9c */
    u8 pada0;
    u8 threaded;             /* +0xa1 run on a worker thread when engine+0x24d */
    u8 pada2[2];
} ModuleDesc;
typedef struct ModuleListArr { int rel; u32 count; } ModuleListArr;
/* ModuleManager XData record (this+0x4c), passed to the listener as "req". */
typedef struct ModReq {
    u8 pad[0xc];
    ModuleListArr list;      /* +0x0c */
    u8 pad14[4];
    u32 next;                /* +0x18 @NextModule */
    u32 prev;                /* +0x1c previous module hash (written here) */
    u8 pad20[8];
    u8 busy;                 /* +0x28 a switch is in progress */
    u8 pad29;
    u8 force;                /* +0x2a switch even if next == current */
} ModReq;
/* Loading context created per switch (this+0x28). */
typedef struct LoadCtx {
    u8 pad[4];
    void *event;             /* +0x04 */
    u8 pad8[4];
    u32 fc;                  /* +0x0c */
    u32 f10;                 /* +0x10 passed to the listener as 5th argument */
    u8 pad14[4];
    void *prev_res_a;        /* +0x18 */
    void *prev_res_b;        /* +0x1c */
    void *res_a;             /* +0x20 desc+0x2c */
    void *res_b;             /* +0x24 desc+0x38 */
    void *res_c;             /* +0x28 desc+0x60 */
    VObj *module;            /* +0x2c */
    Tri module_handle;       /* +0x30 */
    u8 *done_flag;           /* +0x3c */
} LoadCtx;
/* Listener = CLoadingManager (vtable 0x880DB408), slots 10..17. */
typedef struct Listener Listener;
typedef struct ListenerVt {
    u8 pad[0x28];
    void (*begin)(Listener *l, ModReq *r, ModuleDesc *d);                           /* +0x28 slot 10 */
    void (*old_unloaded)(Listener *l, ModReq *r, ModuleDesc *d);                    /* +0x2c slot 11 */
    void (*started)(Listener *l, ModReq *r, ModuleDesc *d);                         /* +0x30 slot 12 */
    u8 (*screen_ready)(Listener *l);                                                /* +0x34 slot 13 */
    void (*loading_screen)(Listener *l, ModReq *r, ModuleDesc *d, int mode, u32 x); /* +0x38 slot 14 */
    void (*data_ready)(Listener *l, ModReq *r, ModuleDesc *d);                      /* +0x3c slot 15 */
    void (*modules_built)(Listener *l, ModReq *r, ModuleDesc *d);                   /* +0x40 slot 16 */
    void (*phase)(Listener *l, ModReq *r, ModuleDesc *d, int mode, u32 x);          /* +0x44 slot 17 */
} ListenerVt;
struct Listener { ListenerVt *vt; };
typedef struct Scheduler Scheduler;
typedef struct SchedulerVt {
    u8 pad[0x14];
    void (*exit)(Scheduler *s);                                              /* +0x14 */
    u8 pad18[0x10];
    Tri *(*handle)(Tri *out, Scheduler *s);                                  /* +0x28 */
    u8 pad2c[0xc];
    void (*load)(Scheduler *s, const char *name, void *svc, u32 a, u32 b, u32 c, u32 d); /* +0x38 */
} SchedulerVt;
struct Scheduler { SchedulerVt *vt; };
typedef struct Sub64 { u8 pad[0x44]; ModuleDesc *desc; u8 pad48[4]; ModReq *req; } Sub64;
typedef struct ModuleManager {
    u8 pad[0x1c];
    VObj *current;           /* +0x1c module set of the running part */
    VObj *processor;         /* +0x20 CModuleProcessor for the current phase */
    void *thread_name;       /* +0x24 */
    LoadCtx *ctx;            /* +0x28 */
    int state;               /* +0x2c 0..5 */
    u8 *done_flag;           /* +0x30 */
    Scheduler *scheduler;    /* +0x34 */
    u8 pad38[0xc];
    ModuleDesc *desc;        /* +0x44 new module */
    ModuleDesc *prev_desc;   /* +0x48 old module */
    ModReq *req;             /* +0x4c */
    Listener *listener;      /* +0x50 */
    VObj **old_begin;        /* +0x54 modules still to tear down */
    VObj **old_end;          /* +0x58 */
    u8 pad5c[4];
    Sub64 *owner60;          /* +0x60 */
    Sub64 *sub64;            /* +0x64 */
    int unload_step;         /* +0x68 0 waiting, 1 unloading, 2 unloaded */
} ModuleManager;
typedef struct Timing { u32 registry; u8 pad[0x24]; float t28; } Timing;
typedef struct Engine { u8 pad[0x224]; VObj *fs; u8 pad228[0x25]; u8 threads; u8 pad24e[0x2a]; u32 state; u32 f27c; u8 pad280[0x24]; u8 *f2a4; } Engine;
typedef struct ResOwner ResOwner;
typedef struct ResData { u8 pad[4]; ResOwner *owner; } ResData;
typedef struct ResHandle { ResData *p; } ResHandle;
typedef struct ResOwnerVt { u8 pad[0x58]; void (*release)(ResOwner *o, ResHandle *h); } ResOwnerVt;
struct ResOwner { ResOwnerVt *vt; };
typedef struct Rec5 { u32 a, b, c, d, key, hash; } Rec5;

extern Engine *lbl_88D45B1C;
extern Timing lbl_88D45B20;
extern void *lbl_88D45B3C;
extern void *lbl_88D45B08;
extern u32 lbl_88D493A4;     /* frame counter of the final phase */
extern u32 lbl_88D493A8;     /* frame counter of the unload phase */
extern u32 lbl_88D493AC;     /* desc->min_frames */
extern u8 lbl_88D493B0;      /* desc->wait_extra */
extern u8 lbl_88D493B1;
extern double g_ts4_script_constants[];
extern const char lbl_880C1320[];
extern const char lbl_880F75CC[];

extern u32 ts4_get_u32__imp_KeTimeStampBundle_8857B830(void);
extern void ts4_if_call_seq_lbl_880DAE20_8862CB00(void);
extern void ts4_loop_call_seq_u32_off2c_88618158(void *o, u32 a, u32 b);
extern void ts4_owner_update_item_flags_88612820(void *o, u32 a, u32 b);
extern void ts4_init_sub_record_8861B630(Engine *e);
extern LoadCtx *ts4_if_call_seq_u32_lbl_88D45B38_88282450(void);
extern VObj *ts4_if_get_u32_off0_88611C00(void *cfg);
extern void ts4_start_named_thread_88633470(LoadCtx *c, void *name);
extern void fn_88617B58(ModuleManager *m, VObj ***list);
extern void fn_8861EBB8(Sub64 *s);
extern void fn_88172DC8(void *o, Rec5 *r, u32 n);
extern void fn_88172E58(void *o, Rec5 *r, u32 n);
extern u8 fn_8862CC90(void *res);
extern void ts4_if_call_seq_NtSetEvent_8857C1F8(void *ev);
extern float ts4_get_scaled_timestamp_88883BA0(void);
extern u8 fn_8862CB68(ModuleDesc *d, u32 flag);
extern void fn_8861ECF8(ModuleDesc *d, u32 v);
extern void ts4_owner_apply_entry_flags_886128B0(void *o, u32 a, u32 b, u32 c);
extern void fn_8861EDB8(ModuleManager *m);
extern void fn_88633528(ModuleManager *m, ModuleDesc *d);
extern void fn_88633680(ModuleDesc *d);
extern void *ts4_find_service(u32 id);
extern H16 *ts4_handle_forward_88610A48(H16 *out, void *in, u32 *key);
extern u32 *ts4_handle_release_881506A0(void *out, H16 *in);
extern VObj *fn_8816D220(u32 registry, u32 key);
extern void ts4_loop_call_seq_u32_offc_8860BD70(LoadCtx *c);
extern void ts4_tsu_cleanup_end(LoadCtx *c);
extern void ts4_owner_remove_flagged_items_88612998(void *o);
extern void ts4_if_call_seq_u32_off28_88617AF8(Sub64 *s);
extern u8 fn_88943390(void);
extern void fn_8862D380(u8 *p, ResData *v);
extern void ts4_vector_erase_range_88150310(void *v, u32 a, u32 b);
extern void fn_888DB268(void);
extern void ts4_assign_formatted_text(Str *dst, const char *text);
extern void ts4_destroy_owned_object(void *p);

INL u8 run_threaded(ModuleDesc *d)
{
    if (lbl_88D45B1C->threads && d->threaded)
        return 1;
    return 0;
}
INL void update_processor(ModuleManager *m)
{
    if (m->processor != 0)
        m->processor->vt->update(m->processor);
}
INL void delete_processor(ModuleManager *m)
{
    if (m->processor != 0) {
        m->processor->vt->exit(m->processor);
        if (m->processor != 0)
            m->processor->vt->destroy(m->processor, 1);
    }
}
INL u8 res_ready(void *r)
{
    if (r == 0)
        return 1;
    return fn_8862CC90(r);
}
INL void tag_reload(void)
{
    if (lbl_88D493B1) {
        u8 *p = lbl_88D45B1C->f2a4;
        if (p != 0)
            p[0x14d0] = 1;
    }
}
INL void notify_phase(ModuleManager *m, int mode)
{
    Listener *l = m->listener;
    if (l != 0)
        l->vt->phase(l, m->req, m->desc, mode, m->ctx->f10);
}

/* 0x886345E0: module manager state machine (Part switching), run once per frame. */
void ts4_module_manager_update_886345E0(ModuleManager *m)
{
    int st = m->state;
    if (st == 5) {
        /* idle: look for a new @NextModule */
        ModReq *req = m->req;
        u32 next = req->next;
        ModuleDesc *end;
        ModuleDesc *d;
        ModuleDesc *prev;
        LoadCtx *ctx;
        lbl_88D45B20.t28 = (float)ts4_get_u32__imp_KeTimeStampBundle_8857B830() * *(float *)((char *)g_ts4_script_constants + 0x80);
        if (m->current != 0 && next == m->current->id_hash && req->force != 1)
            return;
        end = 0;
        if (req->list.rel != -1)
            end = (ModuleDesc *)((char *)&req->list + (req->list.count * 0xa4 + req->list.rel));
        d = 0;
        if (req->list.rel != -1)
            d = (ModuleDesc *)((char *)&req->list + req->list.rel);
        for (;;) {
            if (end == d)
                return;
            if (next == d->hash)
                break;
            d++;
        }
        tag_reload();
        m->req->busy = 1;
        ts4_if_call_seq_lbl_880DAE20_8862CB00();
        prev = m->desc;
        m->desc = d;
        m->prev_desc = prev;
        if (lbl_88D45B3C != 0) {
            u32 from = prev != 0 ? prev->hash : lbl_88D45B1C->f27c;
            if (m->owner60 == 0)
                ts4_loop_call_seq_u32_off2c_88618158(lbl_88D45B3C, from, next);
            else
                ts4_owner_update_item_flags_88612820(lbl_88D45B3C, m->owner60->desc->hash, next);
        }
        m->req->prev = m->prev_desc != 0 ? m->prev_desc->hash : 0;
        ts4_init_sub_record_8861B630(lbl_88D45B1C);
        ctx = ts4_if_call_seq_u32_lbl_88D45B38_88282450();
        m->ctx = ctx;
        ctx->module = m->current;
        m->ctx->done_flag = m->done_flag;
        if (m->listener != 0)
            m->listener->vt->begin(m->listener, m->req, m->desc);
        if (m->prev_desc != 0) {
            m->ctx->prev_res_a = (u8 *)m->prev_desc + 4;
            m->ctx->prev_res_b = (u8 *)m->prev_desc + 0x10;
        }
        m->ctx->res_a = (u8 *)d + 0x2c;
        m->ctx->res_b = (u8 *)d + 0x38;
        m->ctx->res_c = (u8 *)d + 0x60;
        lbl_88D493AC = d->min_frames;
        lbl_88D493B0 = d->wait_extra;
        m->processor = ts4_if_get_u32_off0_88611C00(d);
        if (m->processor != 0)
            m->processor->vt->update(m->processor);
        *m->done_flag = 0;
        if (run_threaded(m->desc))
            ts4_start_named_thread_88633470(m->ctx, m->thread_name);
        m->state = 0;
        fn_88617B58(m, &m->old_begin);
        if (m->sub64 != 0)
            fn_8861EBB8(m->sub64);
        m->unload_step = 0;
        if (m->listener != 0)
            m->listener->vt->loading_screen(m->listener, m->req, m->desc, 0, m->ctx->f10);
        lbl_88D493A8 = 0;
        return;
    }
    if (st == 0) {
        /* unload the old part once the loading screen is up */
        if (m->prev_desc != 0) {
            Rec5 r;
            r.a = 0;
            r.b = 0;
            r.c = 0;
            r.d = 0;
            r.key = 0xE93DDFF8;
            r.hash = m->prev_desc->hash;
            if (lbl_88D45B08 != 0)
                fn_88172DC8(lbl_88D45B08, &r, 1);
        }
        if (m->unload_step == 0) {
            if (lbl_88D493A8 >= 60 && (m->listener == 0 || m->listener->vt->screen_ready(m->listener)) &&
                res_ready(m->ctx->prev_res_a)) {
                m->unload_step = 1;
                m->state = 0;
                notify_phase(m, 0);
            } else {
                lbl_88D493A8++;
                (m->current != 0 ? m->current : m->processor)->vt->update(m->current != 0 ? m->current : m->processor);
            }
        }
        if (m->unload_step != 1 && m->unload_step != 2)
            return;
        lbl_88D45B1C->state = 6;
        if (m->old_begin != m->old_end) {
            VObj *o = m->old_end[-1];
            if (o != 0) {
                o->vt->exit(o);
                o->vt->destroy(o, 1);
            }
            m->old_end--;
            m->processor->vt->update(m->processor);
            return;
        }
        if (m->unload_step == 1) {
            m->unload_step = 2;
            if (m->listener != 0)
                m->listener->vt->loading_screen(m->listener, m->req, m->desc, 2, m->ctx->f10);
            if (!run_threaded(m->desc)) {
                VObj *mod = m->ctx->module;
                if (mod != 0)
                    mod->vt->exit(mod);
                *m->done_flag = 1;
            } else {
                ts4_if_call_seq_NtSetEvent_8857C1F8(m->ctx->event);
            }
        }
        if (*m->done_flag == 0) {
            m->processor->vt->update(m->processor);
            return;
        }
        if (m->current != 0)
            m->current->vt->destroy(m->current, 1);
        {
            float t = ts4_get_scaled_timestamp_88883BA0();
            m->current = 0;
            m->ctx->module = 0;
            lbl_88D45B20.t28 = t;
        }
        *m->done_flag = 0;
        m->state = 1;
        notify_phase(m, 1);
        if (m->listener != 0)
            m->listener->vt->old_unloaded(m->listener, m->req, m->desc);
        return;
    }
    if (st == 1) {
        Tri s58;   /* sp+0x58 scratch shared by several out-parameters, as in the original */
        /* load the new part's data, then build its module set */
        lbl_88D45B1C->state = 6;
        if (!res_ready(m->ctx->res_a))
            goto wait;
        if (m->prev_desc != 0 && !fn_8862CB68(m->prev_desc, 0x893C846D))
            goto wait;
        tag_reload();
        lbl_88D45B20.t28 = ts4_get_scaled_timestamp_88883BA0();
        if (m->listener != 0)
            m->listener->vt->data_ready(m->listener, m->req, m->desc);
        if (m->prev_desc != 0) {
            fn_8862CB68(m->prev_desc, 0x893C846D);
            fn_8861ECF8(m->prev_desc, 0);
        }
        if (lbl_88D45B3C != 0) {
            if (m->owner60 != 0) {
                u32 *from;
                if (m->prev_desc != 0) {
                    from = &m->prev_desc->hash;
                } else {
                    s58.a = lbl_88D45B1C->f27c;
                    from = &s58.a;
                }
                ts4_owner_apply_entry_flags_886128B0(lbl_88D45B3C, m->owner60->desc->hash, *from, m->desc->hash);
            } else if (m->desc != 0) {
                ts4_owner_apply_entry_flags_886128B0(lbl_88D45B3C, m->desc->hash, lbl_88D45B1C->f27c, lbl_88D45B1C->f27c);
            }
        }
        fn_8861EDB8(m);
        m->state = 2;
        notify_phase(m, 2);
        fn_88633528(m, m->desc);
        fn_8861ECF8(m->desc, 1);
        fn_88633680(m->desc);
        m->listener->vt->modules_built(m->listener, m->req, m->desc);
        {
            void *svc = ts4_find_service(m->desc->service);
            int *rel = &m->desc->name_rel;
            const char *name = *rel != -1 ? (const char *)rel + *rel : lbl_880C1320;
            Tri h;
            H16 ha, hb;
            u32 k1, k2;
            u32 reg;
            u32 *key;
            VObj *obj;
            m->scheduler->vt->load(m->scheduler, name, svc, 0, 0, 0, 0);
            h.a = 0;
            h.b = 0xFFFFF;
            h.c = 0;
            h = *m->scheduler->vt->handle(&s58, m->scheduler);
            k1 = 0xE93DDFF8;
            k2 = 0x4A6AA315;
            ts4_handle_forward_88610A48(&hb, ts4_handle_forward_88610A48(&ha, &h, &k1), &k2);
            reg = lbl_88D45B20.registry;
            key = ts4_handle_release_881506A0(&s58, &hb);
            obj = fn_8816D220(reg, *key);
            m->current = obj != 0 ? obj->vt->slot1(obj) : 0;
            m->ctx->module = m->current;
            m->ctx->module_handle = *(Tri *)&hb;
        }
        fn_88617B58(m, &m->old_begin);
        *m->done_flag = 0;
        delete_processor(m);
        m->processor = ts4_if_get_u32_off0_88611C00(m->desc->proc_b);
        m->sub64 = 0;
        if (run_threaded(m->desc))
            ts4_if_call_seq_NtSetEvent_8857C1F8(m->ctx->event);
        return;
    }
    if (st == 2) {
        /* initialise the new module set */
        lbl_88D45B1C->state = 6;
        if (!run_threaded(m->desc)) {
            LoadCtx *c = m->ctx;
            if (c->module != 0)
                c->module->vt->init(c->module, c->module_handle);
            *m->done_flag = 1;
        }
        if (*m->done_flag == 0 || m->old_begin != m->old_end)
            goto run_processor;
        lbl_88D45B20.t28 = ts4_get_scaled_timestamp_88883BA0();
        m->scheduler->vt->exit(m->scheduler);
        *m->done_flag = 0;
        m->state = 3;
        notify_phase(m, 3);
        return;
    }
    if (st == 3) {
        lbl_88D45B1C->state = 6;
        if (!res_ready(m->ctx->res_b))
            goto wait;
        if (!fn_8862CB68(m->desc, 0x7F2E277D))
            goto wait;
        if (m->sub64 != 0 && !fn_8862CB68(m->sub64->desc, 0x7F2E277D))
            goto wait;
        lbl_88D45B20.t28 = ts4_get_scaled_timestamp_88883BA0();
        m->state = 4;
        lbl_88D493A4 = 0;
        notify_phase(m, 4);
        *m->done_flag = 0;
        ts4_if_call_seq_NtSetEvent_8857C1F8(m->ctx->event);
        lbl_88D45B1C->state = 7;
        delete_processor(m);
        m->processor = ts4_if_get_u32_off0_88611C00(m->desc->proc_c);
        fn_8862CB68(m->desc, 0x7F2E277D);
        if (m->sub64 != 0)
            fn_8862CB68(m->sub64->desc, 0x7F2E277D);
        return;
    }
    if (st == 4) {
        LoadCtx *c;
        lbl_88D45B1C->state = 6;
        if (m->processor != 0 && !res_ready(m->ctx->res_c))
            goto wait;
        if (!fn_8862CB68(m->desc, 0x996A9DB7))
            goto wait;
        if (m->sub64 != 0 && !fn_8862CB68(m->sub64->desc, 0x996A9DB7))
            goto wait;
        if (lbl_88D493AC >= lbl_88D493A4)
            goto count;
        if (lbl_88D493B0 && !fn_88943390())
            goto count;
        if (m->processor != 0) {
            m->processor->vt->exit(m->processor);
            if (m->processor != 0)
                m->processor->vt->destroy(m->processor, 1);
            m->processor = 0;
        }
        lbl_88D45B20.t28 = ts4_get_scaled_timestamp_88883BA0();
        c = m->ctx;
        m->state = 5;
        if (c != 0) {
            if (c->fc != 0)
                ts4_loop_call_seq_u32_offc_8860BD70(c);
            ts4_tsu_cleanup_end(c);
        }
        m->ctx = 0;
        lbl_88D45B1C->state = 2;
        if (lbl_88D45B3C != 0 && m->owner60 == 0)
            ts4_owner_remove_flagged_items_88612998(lbl_88D45B3C);
        if (m->listener != 0) {
            m->listener->vt->started(m->listener, m->req, m->desc);
            if (m->desc != 0) {
                Rec5 r;
                r.a = 0;
                r.b = 0;
                r.c = 0;
                r.d = 0;
                r.key = 0xE93DDFF8;
                r.hash = m->desc->hash;
                if (lbl_88D45B08 != 0)
                    fn_88172E58(lbl_88D45B08, &r, 1);
            }
            if (m->sub64 != 0)
                ts4_if_call_seq_u32_off28_88617AF8(m->sub64);
        }
        if (lbl_88D493B1 && lbl_88D45B1C->f2a4 != 0) {
            /* hot-reload of the debug data file lbl_880F75CC */
            VObj *fs;
            ResHandle res;
            lbl_88D45B1C->f2a4[0x14d0] = 0;
            res.p = 0;
            fs = lbl_88D45B1C->fs;
            if (((u8 (*)(VObj *, const char *))((void **)fs->vt)[0x44 / 4])(fs, lbl_880F75CC)) {
                Str s;
                ts4_assign_formatted_text(&s, lbl_880F75CC);
                ((void (*)(VObj *, Str *))((void **)fs->vt)[0x3c / 4])(fs, &s);
                ts4_destroy_owned_object(s.p);
            }
            {
                Str s;
                ResHandle tmp;
                ts4_assign_formatted_text(&s, lbl_880F75CC);
                res = *((ResHandle *(*)(ResHandle *, VObj *, Str *, u32, u32))((void **)fs->vt)[0x34 / 4])(&tmp, fs, &s, 3, 0);
                ts4_destroy_owned_object(s.p);
            }
            fn_8862D380(lbl_88D45B1C->f2a4, res.p);
            ts4_vector_erase_range_88150310(lbl_88D45B1C->f2a4 + 0x14c4, *(u32 *)(lbl_88D45B1C->f2a4 + 0x14c4),
                                            *(u32 *)(lbl_88D45B1C->f2a4 + 0x14c8));
            lbl_88D493B1 = 0;
            res.p->owner->vt->release(res.p->owner, &res);
        }
        m->req->busy = 0;
        m->current->done = 1;
        fn_8862CB68(m->desc, 0x996A9DB7);
        if (m->sub64 != 0) {
            fn_8862CB68(m->sub64->desc, 0x996A9DB7);
            if (m->sub64->req->next == PART_INGAME)
                fn_888DB268();
        } else if (m->req->next == PART_INGAME) {
            fn_888DB268();
        }
        return;
count:
        update_processor(m);
        lbl_88D493A4++;
        return;
    }
wait:
    update_processor(m);
    return;
run_processor:
    update_processor(m);
}
