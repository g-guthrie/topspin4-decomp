/* CX36: session record writers and lookup helpers, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* ---- session context ---- */
typedef struct Cx36Rec3c { u8 pad[0x51]; u8 b51; u8 pad2[2]; u32 w54; u32 w58; } Cx36Rec3c;
typedef struct Cx36Sess { void **vt; u8 pad[0x38]; Cx36Rec3c *p3c; } Cx36Sess;
extern Cx36Sess *g_ts4_session_context;
typedef void (*Cx36SFn)(Cx36Sess *s);
typedef struct Cx36Flag2c { u8 pad[0x2c]; u8 b2c; } Cx36Flag2c;
typedef struct Cx36Req { u8 pad[8]; u32 w8; u8 pad2[8]; u8 b14; } Cx36Req;

#if 0 /* near miss, not byte-identical */
/* 0x88934E28: map the legacy code to the new one, then publish it in the session record */
void ts4_session_publish_code_88934E28(Cx36Flag2c *o, Cx36Req *m)
{
    volatile Cx36Rec3c *r;
    ((Cx36SFn)g_ts4_session_context->vt[13])(g_ts4_session_context);
    if (m->w8 == 0xA0BDE62E)
        m->w8 = 0x9C1C9375;
    {
        Cx36Sess *g = g_ts4_session_context;
        r = g->p3c;
    }
    r->w54 = m->w8;
    r->w58 = (u32)-1;
    r->b51 = 1;
    o->b2c = 0;
}
#endif

#if 0 /* near miss, not byte-identical */
/* 0x88934EA8: publish the request's code in the session record when its flag is set */
void ts4_session_publish_code_88934EA8(Cx36Flag2c *o, Cx36Req *m)
{
    ((Cx36SFn)g_ts4_session_context->vt[13])(g_ts4_session_context);
    if (m->b14) {
        volatile Cx36Rec3c *r = g_ts4_session_context->p3c;
        r->w54 = m->w8;
        r->w58 = 1;
        r->b51 = 1;
        o->b2c = 0;
    } else
        o->b2c = 0;
}
#endif

/* ---- 0x88924FA0 / 0x889251F0: choose an anchor for a range from the owner's kind hash ---- */
typedef struct Cx36V3 { u32 a, b, c; } Cx36V3;
typedef struct Cx36Kind { u8 pad[0x14]; u32 hash; } Cx36Kind;
typedef struct Cx36A { u8 pad[0xc]; char *w0c; u32 **p10; } Cx36A;
typedef struct Cx36Anch { u8 pad[0xc]; Cx36Kind *kind; Cx36A *inner; } Cx36Anch;
typedef struct Cx36AnchSrc { u8 pad[8]; u32 w8; } Cx36AnchSrc;
#define CX36_ANCHOR(ADDR) \
void ts4_range_anchor_##ADDR(Cx36Anch *o, Cx36AnchSrc *src, u32 base, Cx36V3 *out) \
{ \
    u32 a = (u32)(unsigned long)(o->inner->w0c + 0x28); \
    if (o->kind->hash == 0x59C2372B) {  \
        out->b = 0xFFFFF;  \
    } else {  \
        out->b = base + 4;  \
        if (o->kind->hash == 0x96AA70A8)  \
            a = (*o->inner->p10)[1];  \
    }  \
    out->a = a;  \
    out->c = src->w8;  \
}
CX36_ANCHOR(88924FA0)
CX36_ANCHOR(889251F0)
