/* CX36: small net/lobby/scheduler/front-end helpers, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX36_INL static __forceinline
#else
#define CX36_INL static inline
#endif

typedef struct Cx36W8 { u32 w0; u32 w4; int w8; } Cx36W8;

/* 0x88923318: is the word at +8 zero */
u8 ts4_is_w8_zero_88923318(Cx36W8 *o)
{
    return 0 == o->w8;
}

/* 0x88931120: u16 difference is positive */
int ts4_u16_diff_gt_88931120(u16 *a, u16 *b)
{
    return (short)(*a - *b) > 0;
}

/* 0x88931E28: u16 difference is not positive */
int ts4_u16_diff_le_88931E28(u16 *a, u16 *b)
{
    return (short)(*a - *b) <= 0;
}

/* ---- session context writers ---- */
typedef struct Cx36Sess3c { u8 pad[0x81]; u8 b81; u8 pad2[2]; u32 w84; u32 w88; } Cx36Sess3c;
typedef struct Cx36Sess { u8 pad[0x3c]; Cx36Sess3c *p3c; } Cx36Sess;
extern Cx36Sess *g_ts4_session_context;
typedef struct Cx36Flag2c { u8 pad[0x2c]; u8 b2c; } Cx36Flag2c;

#if 0 /* near miss, not byte-identical */
/* 0x88934D40: set the flag at +0x2c and prime the session record with a fixed code */
void ts4_session_prime_88934D40(Cx36Flag2c *o)
{
    Cx36Sess3c *s;
    o->b2c = 1;
    s = g_ts4_session_context->p3c;
    s->w84 = 0xA0BDE62E;
    s->w88 = 1;
    s->b81 = 1;
}
#endif

/* 0x889340B0: forward a message to the handler registered for its channel */
typedef struct Cx36Handler { void **vt; } Cx36Handler;
typedef struct Cx36Disp { u8 pad[4]; Cx36Handler **tab; } Cx36Disp;
typedef struct Cx36Chan { u8 pad[0x42c]; u32 w42c; u32 chan; } Cx36Chan;
typedef void (*Cx36HFn)(Cx36Handler *h, void *a);
void ts4_dispatch_to_channel_889340B0(Cx36Disp *d, Cx36Chan *m)
{
    Cx36Handler *h = d->tab[m->chan];
    if (h)
        ((Cx36HFn)h->vt[7])(h, &m->w42c);
}

/* 0x88932290: ordered less-than on (w4, w8) pairs */
typedef struct Cx36Key { u32 w0; u32 w4; u32 w8; } Cx36Key;
u8 ts4_key_less_88932290(Cx36Key *a, Cx36Key *b)
{
    u32 r = a->w4 < b->w4 || (a->w4 == b->w4 && a->w8 < b->w8);
    return (u8)r;
}

/* 0x889232D0: index of the entry whose id-1 equals key, or -1 */
typedef struct Cx36Ent12 { u32 id; u32 b; u32 c; } Cx36Ent12;
typedef struct Cx36EntOwner { u8 pad[8]; Cx36Ent12 e[1]; } Cx36EntOwner;
int ts4_find_entry_by_id_889232D0(Cx36EntOwner *o, u32 n, int key)
{
    u32 i;
    int r = -1;
    for (i = 0; i < n; i++) {
        if ((int)(o->e[i].id - 1) == key) {
            r = i;
            break;
        }
    }
    return r;
}

/* 0x889231E8: self-relative record with hash 0xFCF73E23 whose kind is 2, 3 or 0x58 */
typedef struct Cx36Rel { int off; u32 hash; } Cx36Rel;
u8 ts4_is_known_kind_889231E8(Cx36Rel *o)
{
    u32 r;
    if (o->hash == 0xFCF73E23) {
        u16 k = *(u16 *)((char *)o + o->off + 4);
        r = (k == 3 || k == 2 || k == 0x58);
    } else
        r = 0;
    return (u8)r;
}

#if 0 /* near miss, not byte-identical */
/* 0x88922F78: kind of a self-relative record with one of five known hashes, else 0 */
u16 ts4_known_hash_kind_88922F78(Cx36Rel *o)
{
    u16 r = 0;
    u32 h = o->hash;
    if (h == 0xFCF73E23 || h == 0x5559D5D6 || h == 0xC952E870 || h == 0x67860A08 || h == 0x5EFAFFB9)
        r = *(u16 *)((char *)o + o->off + 4);
    return r;
}
#endif
