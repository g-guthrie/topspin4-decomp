/* Swing_DLL.xex 0x8899FAE8: copy six owner settings (+0x42c..+0x440) into the session state config block (+0x2d8), then post event 0xA0BDE62E on the state+0x1bc event slot.
 * /Oc. The context is a local; the config stores go through a SessionConfig pointer and the event through an EventSlot pointer, which keeps ctx in r10 and the state in r11. */
typedef struct EventSlot { unsigned char f0; unsigned char pending; unsigned char pad[2]; unsigned int hash; unsigned int value; } EventSlot;
typedef struct SessionConfig { int settings[4]; int pad4; int extra[2]; } SessionConfig;
typedef struct SessionState {
    char pad[0x1bc]; EventSlot event;
    char pad3[0x2d8 - 0x1c8]; SessionConfig cfg;
} SessionState;
typedef struct SessionContext { char pad[0x3c]; SessionState *state; } SessionContext;
typedef struct SessionOwner { char pad[0x42c]; int settings[4]; int extra[2]; } SessionOwner;
extern SessionContext *g_ts4_session_context;

void fn_8899FAE8(SessionOwner *o)
{
    SessionContext *ctx = g_ts4_session_context;
    SessionConfig *cfg = &ctx->state->cfg;
    EventSlot *ev;
    cfg->settings[0] = o->settings[0];
    cfg->settings[1] = o->settings[1];
    cfg->settings[2] = o->settings[2];
    cfg->settings[3] = o->settings[3];
    cfg->extra[0] = o->extra[0];
    cfg->extra[1] = o->extra[1];
    ev = &ctx->state->event;
    ev->hash = 0xA0BDE62E;
    ev->value = 1;
    ev->pending = 1;
}
