/* 0x883A3C10: For id 0..0x7e and mode kind 9: sets state->enabled[id] (+0x260 + 4*id) = 1, and for id 2 also clears +0x464; returns 1, else 0. */
/* Matched on /Oc (agAH). int id with an unsigned range check (cmplwi) and a signed == 2 test (cmpwi). */
typedef struct Mode { int kind; } Mode;
typedef struct State { char pad[0x260]; int enabled[0x7f]; char pad45c[0x464 - 0x45c]; int x464; } State;
typedef struct Ctl { Mode *mode; State *state; } Ctl;
int fn_883A3C10(Ctl *c, int id)
{
    if ((unsigned int)id > 0x7e)
        return 0;
    if (c->mode->kind != 9)
        return 0;
    c->state->enabled[id] = 1;
    if (id == 2)
        c->state->x464 = 0;
    return 1;
}
