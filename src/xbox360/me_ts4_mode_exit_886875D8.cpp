/* 0x886875D8: leaves the mode: hides the HUD, releases the 0x470600F5 registration if the registry holds it,
   resets the controller, stops the timer, clears the body flags and timers and stops the registry's animation.
   Matched in C++ (ME agentB, 2026-11-18): the registry lookup is an inline member with its own key local, and the
   release key is a second local declared outside the if (separate stack slots 0x50/0x54); the two virtuals are
   real members (slots 7 and 13). The zero written to +0xE00 is the 0.0f constant at 0x8814B440. */
typedef unsigned int u32;
typedef struct Registry Registry;
extern "C" unsigned char fn_8826ACB8(void *set, const u32 *id);
extern "C" void ts4_registry_release_8866DD78(Registry *r, const u32 *id);
extern "C" void fn_8866C248(void *p);
extern "C" void ts4_if_call_seq_u32_off1c_88678468(void *a, u32 b);

struct Ts4ModeObj {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void reset();   /* slot 7 (+0x1C) */
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
    virtual void stop();    /* slot 13 (+0x34) */
};
typedef struct Hud { char p[0xd2]; unsigned char hidden; } Hud;
typedef struct Body {
    char p[0x90]; int t0; int p0; int t1; int p1; int t2;
    char q[0x23c - 0xa4]; unsigned char b23c; char r[0x424 - 0x23d]; unsigned char b424; char s[0x47e - 0x425]; unsigned char b47e;
    char t[0x6f0 - 0x47f]; unsigned char b6f0, b6f1; char u[0xe00 - 0x6f2]; float fe00;
} Body;
struct Registry {
    char p[0x10]; unsigned char locked; char q[0x3f]; Ts4ModeObj *anim; char r[0x20]; Body *body; char s[8]; Hud *hud; char t[0x10]; char set[1];
    bool contains(u32 key) { u32 id = key; return fn_8826ACB8(set, &id) != 0; }
};
typedef struct Mode {
    void *vt; char p[0x18]; Registry *reg; Body *aux; void *timer; unsigned char armed; char q[3]; u32 *pending; void *queue;
    char r[0x10]; Ts4ModeObj *ctl;
} Mode;
extern "C" const float lbl_8814B440; /* 0.0f */

extern "C" void ts4_mode_exit_886875D8(Mode *m)
{
    Registry *reg;
    m->reg->hud->hidden = 1;
    reg = m->reg;
    u32 id2;
    if (reg->contains(0x470600F5)) {
        id2 = 0x470600F5;
        ts4_registry_release_8866DD78(reg, &id2);
    }
    if (!m->reg->locked)
        m->reg->body->b47e = 0;
    m->ctl->reset();
    fn_8866C248(m->timer);
    m->aux->b424 = 0;
    m->aux->b23c = 0;
    if (*m->pending) {
        ts4_if_call_seq_u32_off1c_88678468(m->queue, *m->pending);
        *m->pending = 0;
    }
    {
        Registry *r = m->reg;
        m->armed = 0;
        r->body->t0 = 0x7FFFFFFF;
        r->body->t1 = 0x7FFFFFFF;
        r->body->t2 = 0x7FFFFFFF;
    }
    m->reg->anim->stop();
    m->reg->body->fe00 = lbl_8814B440;
    m->reg->body->b6f1 = 0;
    m->reg->body->b6f0 = 0;
}
