/* Q5: post a gameplay event when the tracked id changes (Top Spin 4, Xbox 360, Swing_DLL.xex). */
typedef unsigned int u32;
typedef unsigned char u8;

/* One-word id. The struct copy of the current id keeps the target's load order (current id, then *id). */
typedef struct Q5EvId { u32 v; } Q5EvId;
/* Event record handed to fn_888CC9D8 (0x30 bytes). */
typedef struct Q5Event {
    u32 a;          /* +0x00 */
    u32 hash;       /* +0x04 event type hash */
    Q5EvId id;      /* +0x08 */
    int c;          /* +0x0c */
    u32 d;          /* +0x10 */
    int e;          /* +0x14 */
    float f0, f1, f2; /* +0x18 */
    u8 b;           /* +0x24 */
    u32 g;          /* +0x28 */
    float w;        /* +0x2c */
} Q5Event;
typedef struct Q5EvState { char p000[0x26c]; u32 hash; /* +0x26c */ } Q5EvState;
typedef struct Q5EvOwner {
    char p000[0x1c];
    void *handler;      /* +0x1c */
    char p020[0x40];
    Q5EvState *state;   /* +0x60 */
    char p064[0xcc];
    Q5EvId cur;         /* +0x130 */
    char p134[7];
    u8 busy;            /* +0x13b */
    char p13c[4];
    u8 enabled;         /* +0x140 */
} Q5EvOwner;
extern float g_ts4_event_value;
extern const float g_ts4_script_constants[];
extern void fn_888CC9D8(Q5EvOwner *o, Q5Event *e);

/* 0x888D7230: when the owner has a handler, is enabled, is in state 0x39A2A9F0 and not busy, and *id differs
 * from the current id, post event 0x4AA6A6E3 for *id. */
void ts4_post_event_4aa6a6e3_888D7230(Q5EvOwner *o, Q5EvId *id)
{
    Q5Event e;
    Q5EvId cur;
    if (o->handler && o->enabled && o->state->hash == 0x39A2A9F0u && !o->busy) {
        cur = o->cur;
        if (id->v != cur.v) {
            e.id.v = id->v;
            e.a = 0;
            e.f0 = g_ts4_event_value;
            e.c = -1;
            e.f1 = g_ts4_event_value;
            e.d = 0;
            e.f2 = g_ts4_event_value;
            e.e = -1;
            e.w = g_ts4_script_constants[0];
            e.b = 0;
            e.g = 0;
            e.hash = 0x4AA6A6E3u;
            fn_888CC9D8(o, &e);
        }
    }
}
