/* CX36: session-notifying removals and message forwarding, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *fn_88562DC0(void *dst, const void *src, u32 n);
typedef struct Cx36Sess { void **vt; } Cx36Sess;
extern Cx36Sess *g_ts4_session_context;

/* 0x88932AF8: remove (after notifying the session) every element whose flag at +0x48 is set */
typedef struct Cx36Fl { u8 pad[0x48]; u8 b48; } Cx36Fl;
typedef struct Cx36FlV { Cx36Fl **first; Cx36Fl **last; } Cx36FlV;
typedef struct Cx36FlOwner { u8 pad[0x10]; Cx36FlV v; } Cx36FlOwner;
typedef void (*Cx36NfFn)(Cx36Sess *s, Cx36Fl *e);
void ts4_remove_flagged_88932AF8(Cx36FlOwner *o)
{
    Cx36FlV *v = &o->v;
    Cx36Fl **p = v->first;
    Cx36Fl **q;
    if (p == o->v.last)
        return;
    q = p + 1;
    do {
        Cx36Fl *e = *p;
        if (e->b48) {
            ((Cx36NfFn)g_ts4_session_context->vt[28])(g_ts4_session_context, e);
            if (q != v->last)
                fn_88562DC0(p, q, (u32)((char *)v->last - (char *)q));
            v->last--;
        } else {
            q++;
            p++;
        }
    } while (p != o->v.last);
}

/* 0x889313E8: find the first element accepted by the predicate (slot 4), notify the session and erase it; returns its position */
typedef struct Cx36Ac { void **vt; } Cx36Ac;
typedef struct Cx36AcEl { u32 w0; } Cx36AcEl;
typedef struct Cx36AcV { Cx36AcEl **first; Cx36AcEl **last; } Cx36AcV;
typedef struct Cx36AcOwner { u8 pad[4]; Cx36AcV v; } Cx36AcOwner;
typedef u8 (*Cx36PredFn)(Cx36Ac *a, Cx36AcEl *e);
typedef void (*Cx36NfFn2)(Cx36Sess *s, Cx36AcEl *e);
Cx36AcEl **ts4_erase_first_accepted_889313E8(Cx36AcOwner *o, Cx36Ac *a)
{
    Cx36AcEl **end = o->v.last;
    Cx36AcV *v = &o->v;
    Cx36AcEl **p = v->first;
    for (; p != end; p++) {
        Cx36AcEl *e = *p;
        if (((Cx36PredFn)a->vt[4])(a, e)) {
            Cx36AcEl **q;
            ((Cx36NfFn2)g_ts4_session_context->vt[26])(g_ts4_session_context, e);
            q = p + 1;
            if (q != v->last)
                fn_88562DC0(p, q, (u32)((char *)v->last - (char *)q));
            v->last--;
            return p;
        }
    }
    return end;
}
