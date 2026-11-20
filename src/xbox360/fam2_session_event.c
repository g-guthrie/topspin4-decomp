/* FAM2: session-context event posts.  Each writes an event slot inside the
 * session's state block (g_ts4_session_context->+0x3c): the event hash, its
 * value, then raises the slot's pending flag. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Ts4EventSlot {
    u8 f0;
    u8 pending;
    u8 pad[2];
    u32 hash;
    u32 value;
} Ts4EventSlot;

typedef struct Ts4SessionCtx {
    u8 pad[0x3c];
    char *state;
} Ts4SessionCtx;

extern Ts4SessionCtx *g_ts4_session_context;

#define TS4_SESSION_EVENT_POST(A, OFF, HASH) \
void ts4_session_event_post_##A(void) \
{ \
    Ts4EventSlot *s = (Ts4EventSlot *)(g_ts4_session_context->state + OFF); \
    s->hash = HASH; \
    s->value = 1; \
    s->pending = 1; \
}

#define TS4_SESSION_EVENT_POST_VALUE(A, OFF, HASH) \
void ts4_session_event_post_value_##A(void *self, u32 unused, u32 value) \
{ \
    Ts4EventSlot *s = (Ts4EventSlot *)(g_ts4_session_context->state + OFF); \
    (void)self; \
    (void)unused; \
    s->hash = HASH; \
    s->value = value; \
    s->pending = 1; \
}

#define TS4_EVENT_SLOT(OFF) ((Ts4EventSlot *)(g_ts4_session_context->state + (OFF)))

/* Post a constant value. */
#define TS4_SESSION_EVENT_POST_K(A, OFF, HASH, VAL) \
void ts4_session_event_post_k_##A(void) \
{ \
    Ts4EventSlot *s = TS4_EVENT_SLOT(OFF); \
    s->hash = HASH; \
    s->value = VAL; \
    s->pending = 1; \
}

/* Post a constant value only when the third argument is non-zero. */
#define TS4_SESSION_EVENT_POST_IF(A, OFF, HASH, VAL) \
void ts4_session_event_post_if_##A(void *self, u32 unused, int cond) \
{ \
    (void)self; \
    (void)unused; \
    if (cond) { \
        Ts4EventSlot *s = TS4_EVENT_SLOT(OFF); \
        s->hash = HASH; \
        s->value = VAL; \
        s->pending = 1; \
    } \
}

/* Post the source object's word at FIELD. */
#define TS4_SESSION_EVENT_POST_FIELD(A, OFF, HASH, FIELD) \
void ts4_session_event_post_field_##A(void *self, const char *src) \
{ \
    Ts4EventSlot *s = TS4_EVENT_SLOT(OFF); \
    (void)self; \
    s->hash = HASH; \
    s->value = *(const u32 *)(src + FIELD); \
    s->pending = 1; \
}

TS4_SESSION_EVENT_POST(88934DA0, 0x44, 0xA0BDE62E)
TS4_SESSION_EVENT_POST(8899F588, 0x80, 0x7FAFB4B6)
TS4_SESSION_EVENT_POST(8899FE40, 0x260, 0xA0BDE62E)
TS4_SESSION_EVENT_POST(889A1CB0, 0x44, 0xA0BDE62E)
TS4_SESSION_EVENT_POST_VALUE(88934E00, 0x5c, 0x9C1C9375)
TS4_SESSION_EVENT_POST_VALUE(889987C8, 0x5c, 0x9C1C9375)
TS4_SESSION_EVENT_POST_VALUE(889A1D10, 0x5c, 0x9C1C9375)
TS4_SESSION_EVENT_POST_K(88934D70, 0x44, 0x9C1C9375, 0)
TS4_SESSION_EVENT_POST_K(889A1C80, 0x44, 0x9C1C9375, 0)
TS4_SESSION_EVENT_POST_K(88998400, 0x80, 0x9C1C9375, 0)
TS4_SESSION_EVENT_POST_IF(88934DC8, 0x68, 0x9C1C9375, 0)
TS4_SESSION_EVENT_POST_IF(88998460, 0x68, 0x9C1C9375, 0)
TS4_SESSION_EVENT_POST_IF(889A1CD8, 0x68, 0x9C1C9375, 0)
TS4_SESSION_EVENT_POST_FIELD(88998498, 0xbc, 0x9C1C9375, 0x14)
TS4_SESSION_EVENT_POST_FIELD(889A1BF8, 0x18c, 0x9C1C9375, 0xdbc)
