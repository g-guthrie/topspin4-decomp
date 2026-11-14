/*
 * DRAFT (not part of the matching build). GP0 / WP0.
 * Swing_DLL.xex fn_88611760 (0x88611760, size 0x3A4): CModuleProcessor "Run",
 * vtable slot 2 of the CModuleProcessor instance vtable 0x880F8C44.
 *
 * This is the function that actually calls the per-frame Update slot of the
 * module objects. Everything that the scheduler runs per frame (including the
 * gameplay modules) goes through the inner call
 *        module->vtbl[2](module)            // at 0x88611914 / 0x88611AA0
 * Which modules, in which order, and how often is DATA: the config record at
 * processor+0x24 comes from SystemData:/SystemData/Scheduler/... (CoreTech
 * _Xenon.bin), so the order cannot be recovered from code alone.
 *
 * Evidence: disassembly of fn_88611760 (tools/fn_asm.py), hash 0xC89FA93B ==
 * crc32("Xenon"), the vtable dump of ts4_keyed_item_list_add_unique_8861E648's
 * factory (fn_882859D8 -> ctor ts4_if_call_seq_fn_88617D88_88625DA0 -> vtable 0x880F8C44).
 * Does not match byte-exactly (not attempted: 18-register prologue, relative
 * XData arrays and threaded branches); behaviour is believed correct.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Module;                                   /* any scheduler module / service object */
struct ModuleVtbl {
    void (*dtor)(struct Module *);               /* [0] */
    void (*slot1)(struct Module *);              /* [1] noop (886063A0) for most classes */
    void (*update)(struct Module *);             /* [2] per-frame Update; noop for 28-byte module shells */
    void *clone_assign;                          /* [3] fn_88628098 for every class */
    void *init;                                  /* [4] Init: base init fn_88627EC0 then class setup */
    void *exit;                                  /* [5] Exit: undo Init */
    void *slots_6_9[4];                          /* [6]=fn_8860C0B8 [7]=noop [8]=fn_88608320 [9]=noop */
};
struct Module {
    const struct ModuleVtbl *vtbl;
    u32 id_hash;                                 /* +4 */
    u8 running;                                  /* +8: set to 1 for the duration of an Update call */
};

/* One element (stride 0x40) of the relative-offset arrays in the scheduler config. */
struct SchedulerModuleEntry {
    u32 service_hash;       /* +0x00 crc32 of the module/service name, resolved by ts4_find_service */
    u32 platform_hash;      /* +0x04 0 (all) or 0xC89FA93B ("Xenon"): entry is skipped otherwise */
    struct Module *cached;  /* +0x08 resolved instance (written back after first lookup) */
    u8 threaded;            /* +0x0C run on a worker thread when engine->threaded_modules */
    u8 pad[0x23];
    int repeat_count;       /* +0x30 number of Update calls per scheduled frame */
    int frame_divisor;      /* +0x34 entry runs when engine->frame_counter % divisor == 0 */
    u8 tail[8];
};

/* relative-offset array header used by XData packed structs: { int rel_offset(-1 = null); int count; } */
struct RelArray { int rel_offset; int count; };

struct SchedulerConfig {            /* processor->config (+0x24) */
    struct RelArray stage_list;     /* +0x00 array #1: entries may be threaded */
    struct RelArray main_list;      /* +0x0C array #2: sequential entries (struct stride 0x40) */
    int outer_repeat;               /* +0x18 whole-list repetitions per run */
    int period;                     /* +0x1C run only when engine->frame_counter % period == 0 */
};

struct Engine { /* *(void **)0x88D45B1C */
    u8 u_00[0x24c];
    u8 threaded_modules;            /* +0x24C */
    u8 u_24d[0x22];
    int frame_counter;              /* +0x270 */
    int u_274;
    int engine_state;               /* +0x278: 2/3/4 = scene (re)load states */
};
extern struct Engine *g_engine;

struct Module *ts4_find_service(u32 hash);

struct ModuleProcessor {
    const void *vtbl;
    u8 u_04[4];
    u8 enabled;                     /* +0x08 */
    u8 u_09[0x13];
    u8 pending_start;               /* +0x1C */
    int mode;                       /* +0x20 */
    struct SchedulerConfig *config; /* +0x24 */
    void *thread_slots;             /* +0x28 vector of 0x24-byte worker-thread slots */
};

static void run_entry(struct Module **cached, u32 hash, int engine_state, int pending_start,
                      int repeat, int divisor, int frame)
{
    struct Module *m = *cached;
    if (m == 0) {
        /* In engine states 2/3/4 the lookup is only allowed once pending_start is cleared. */
        if (!((engine_state == 2 || engine_state == 3 || engine_state == 4) && !pending_start)) {
            m = ts4_find_service(hash);
            *cached = m;
        }
    }
    if (m != 0 && frame % divisor == 0) {
        u8 saved = m->running;
        int i;
        m->running = 1;
        for (i = 0; i < repeat; i++) {
            m->vtbl->update(m);          /* <-- per-frame Update virtual */
        }
        m->running = saved;
    }
}

/* fn_88611760 */
void module_processor_run(struct ModuleProcessor *p)
{
    int outer, frame;

    if (!p->enabled) return;
    frame = g_engine->frame_counter;
    if (frame % p->config->period != 0) return;

    for (outer = 0; outer < p->config->outer_repeat; outer++) {
        /* array #1 (stage_list): for each entry whose platform tag is 0 or "Xenon":
         *   - threaded entries (engine->threaded_modules) are handed to a worker-thread slot
         *     (event set with fn_8857C1F8, completion awaited with fn_8857A128(.., -1) unless
         *     processor->mode == 0 (uncertain));
         *   - other entries run run_entry(...). */
        /* array #2 (main_list): same, always sequential (non threaded). */
    }
    if (p->pending_start && (g_engine->engine_state == 2 || g_engine->engine_state == 4)) {
        p->pending_start = 0;
    }
}
