/* 0x8861A370: Returns the first of the 20 0x210-byte session slots at +0x490 that is live (handle set, open flag, active non-zero) and whose handle equals the given one, or 0. */
/* Matched on /Oc (agAH). End pointer computed first and compared end != s; result kept in a variable with break (li r3,0 up front). */
typedef struct Session {
    void *handle;
    unsigned char open;
    char pad5[0x204 - 5];
    int active;
    char pad208[0x210 - 0x208];
} Session;
typedef struct SessionTable { char pad[0x490]; Session sessions[20]; } SessionTable;
static __forceinline unsigned char Session_IsLive(Session *s)
{
    return s->handle != 0 && s->open && s->active != 0;
}
Session *fn_8861A370(SessionTable *t, void *handle)
{
    Session *end = t->sessions + 20;
    Session *s = t->sessions;
    Session *found = 0;
    for (; end != s; s++) {
        if (Session_IsLive(s) && handle == s->handle) {
            found = s;
            break;
        }
    }
    return found;
}
