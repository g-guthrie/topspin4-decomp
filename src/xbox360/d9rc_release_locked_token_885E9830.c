/* Swing_DLL.xex 0x885E9830-0x885E98B8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef long long s64;
struct Ts4Lock { char pad[0x20]; s64 owner; };
struct Ts4Tok { int state; short live; u16 half; };
extern struct Ts4Lock *lbl_88D3CB48;
void fn_88472530(struct Ts4Lock *l);
void RtlLeaveCriticalSection(struct Ts4Lock *l);

void ts4_release_locked_token_885E9830(struct Ts4Tok *t)
{
    struct Ts4Lock *l;
    if (t->state != -0x2f) {
        l = lbl_88D3CB48;
        fn_88472530(l);
        t->live = t->live - 1;
        t->half = t->half >> 1;
        if (t->live == 0)
            t->state = -0xf;
        l->owner = -1;
        RtlLeaveCriticalSection(l);
    }
}

void ts4_release_locked_token_885E98B8(struct Ts4Tok *t)
{
    struct Ts4Lock *l;
    if (t->state != -0x2f) {
        l = lbl_88D3CB48;
        fn_88472530(l);
        t->live = t->live - 1;
        t->half = t->half >> 1;
        if (t->live == 0)
            t->state = -0xf;
        l->owner = -1;
        RtlLeaveCriticalSection(l);
    }
}
