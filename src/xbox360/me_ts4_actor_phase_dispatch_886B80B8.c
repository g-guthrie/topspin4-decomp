/* 0x886B80B8: waits until the actor's timer reaches 240 (fast actor with an idle body that has a target) or 90
 * frames, then runs the handler for the current phase (0..3; phase 4 does nothing). */
typedef struct Ts4RelHdr { int self_off; } Ts4RelHdr;
typedef struct Ts4StateRec { char p[0xc]; int pending; char p2[0x24 - 0x10]; int queued; } Ts4StateRec;
typedef struct Ts4Body { char p[0x99]; unsigned char busy; char p2[0xb4 - 0x9a]; Ts4RelHdr states; char p3[0x340 - 0xb8]; void *target; } Ts4Body;
typedef struct Ts4Timer { char p[0x310]; int elapsed; } Ts4Timer;
typedef struct Ts4Flags { char p[4]; unsigned char fast; } Ts4Flags;
typedef struct Ts4Actor { char p[0x30]; Ts4Timer *timer; char p2[0x44 - 0x34]; Ts4Body *body; char p3[0x58 - 0x48]; Ts4Flags *flags; } Ts4Actor;
typedef struct Ts4Ent { char p[0x48]; Ts4Actor *actor; } Ts4Ent;
typedef struct Ts4Owner { char p[8]; Ts4Ent *ent; } Ts4Owner;
typedef struct Ts4Idle { char p[0x1c]; Ts4Owner *owner; unsigned phase; } Ts4Idle;
void fn_88682800(Ts4Idle *s);
void fn_886B7F68(Ts4Idle *s);
void fn_886825A0(Ts4Idle *s);
void fn_88682350(Ts4Idle *s);
static __inline Ts4StateRec *rel_rec(Ts4RelHdr *h) { return (Ts4StateRec *)((char *)h + h->self_off); }
static __inline Ts4StateRec *state_rec(Ts4Body *b) { return rel_rec(&b->states); }
static __inline unsigned char is_idle(Ts4Idle *s)
{
    Ts4Body *b = s->owner->ent->actor->body;
    return state_rec(b)->pending == 0 && state_rec(s->owner->ent->actor->body)->queued == 0 && s->owner->ent->actor->body->busy == 0;
}
static __inline unsigned char has_target(Ts4Idle *s)
{
    return is_idle(s) && s->owner->ent->actor->body->target != 0;
}
void ts4_actor_phase_dispatch(Ts4Idle *s)
{
    unsigned char fast = s->owner->ent->actor->flags->fast;
    unsigned char t = has_target(s);
    int limit;
    if (fast && t) limit = 240; else limit = 90;
    {
        unsigned char waiting = s->owner->ent->actor->timer->elapsed < limit;
        if (waiting) return;
    }
    switch (s->phase) {
    case 0: fn_88682800(s); break;
    case 1: fn_886B7F68(s); break;
    case 2: fn_886825A0(s); break;
    case 3: fn_88682350(s); break;
    case 4: return;
    }
}
