/* CX36: keyed removal that notifies the session first, Swing_DLL.xex 0x88933198. */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *fn_88562DC0(void *dst, const void *src, u32 n);
typedef struct Cx36El { u8 pad[4]; int key; } Cx36El;
typedef struct Cx36V { Cx36El **first; Cx36El **last; } Cx36V;
typedef struct Cx36Own { u8 pad[4]; Cx36V v; } Cx36Own;
typedef struct Cx36Sess { void **vt; } Cx36Sess;
extern Cx36Sess *g_ts4_session_context;
typedef void (*Cx36NotifyFn)(Cx36Sess *s, Cx36El *e);

/* 0x88933198: find the element with the given key, tell the session, erase it; true when found */
u32 ts4_remove_notify_by_key_88933198(Cx36Own *o, int key)
{
    Cx36V *v = &o->v;
    Cx36El **end = o->v.last;
    Cx36El **p;
    for (p = o->v.first; p != end; p++) {
        if (key == (*p)->key) {
            Cx36El *e = *p;
            Cx36El **q;
            ((Cx36NotifyFn)g_ts4_session_context->vt[26])(g_ts4_session_context, e);
            q = p + 1;
            if (q != v->last)
                fn_88562DC0(p, q, (u32)((char *)v->last - (char *)q));
            v->last--;
            return 1;
        }
    }
    return 0;
}
