/* Swing_DLL.xex 0x8899F7F8: in mode 0x0D257AF3 (state+0x280), adjust a running timer (+0x9c, ms) by seconds*1000.
 * /Oc. The dead cmpwi r4,0 comes from a sign split (subtract for positive, add the negation otherwise) that folds to one subtract. */
typedef struct SessionState { char pad[0x280]; unsigned int modeHash; } SessionState;
typedef struct SessionContext { char pad[0x3c]; SessionState *state; } SessionContext;
typedef struct Timer { char pad[0x9c]; unsigned int remainingMs; } Timer;
extern SessionContext *g_ts4_session_context;

void fn_8899F7F8(Timer *t, int seconds)
{
    if (g_ts4_session_context->state->modeHash == 0x0D257AF3 && t->remainingMs)
    {
        if (seconds > 0)
            t->remainingMs -= seconds * 1000;
        else
            t->remainingMs += -seconds * 1000;
    }
}
