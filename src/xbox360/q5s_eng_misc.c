/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex): engine-core leaf functions (q5s eng).
 * Route: LTCG (/GL + /LTCG, /Oc), context src/xbox360/pp1_pool_primer.c.
 * Spec: work/specs/Q5S/q5s_eng_misc.json.
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_88C4589D;                            /* global mode flag (19 readers) */
extern char *fn_88563500(const char *s, int c);    /* CRT strchr */

/* Object owned by a menu/select state: the timeout fields reset by slot 7 of vtable 0x880F61D0. */
typedef struct Ts4SelectTimer {
    u8 pad0[0x48c];
    u32 elapsed;                                   /* +0x48C cleared */
    u8 pad490[4];
    u32 timeout_ms;                                /* +0x494 500 or 7000 */
    u8 pad498[4];
    u8 armed;                                      /* +0x49C set to 1 */
} Ts4SelectTimer;

typedef struct Ts4SelectState {
    u8 pad0[4];
    Ts4SelectTimer *timer;                         /* +0x04 */
} Ts4SelectState;

/* Swing_DLL.xex 0x8863A5B0 (vtable 0x880F61D0 slot 7): re-arm the timer; 500 ms when lbl_88C4589D is
 * clear, 7000 ms otherwise. Note the `if (!flag)` sense: `if (flag)` gives the inverted block order. */
void ts4_reset_select_timeout_8863A5B0(Ts4SelectState *self)
{
    Ts4SelectTimer *t = self->timer;
    if (!lbl_88C4589D)
        t->timeout_ms = 500;
    else
        t->timeout_ms = 7000;
    t->armed = 1;
    t->elapsed = 0;
}

/* Memory stream (vtable 0x880F7D28, ts4_membuf_*). */
typedef struct Ts4MemStream {
    u8 pad0[0x14];
    u32 pos;                                       /* +0x14 */
    u32 size;                                      /* +0x18 */
} Ts4MemStream;

/* Swing_DLL.xex 0x8860EE20: seek. whence 0 = relative, 1 = from end (size - off), 2 = absolute.
 * Returns the new position. */
u32 ts4_membuf_seek_8860EE20(Ts4MemStream *s, u32 off, u32 whence)
{
    switch (whence) {
    case 0: s->pos += off; break;
    case 1: s->pos = s->size - off; break;
    case 2: s->pos = off; break;
    }
    return s->pos;
}

/* Swing_DLL.xex 0x88605CF0: index of the first `c` in `s` at or after `start`, or -1. */
int ts4_str_find_char_from_88605CF0(const char *s, char c, int start)
{
    int r = -1;
    const char *p = fn_88563500(s + start, c);
    if (p != 0)
        r = p - s;
    return r;
}

extern u32 lbl_880C8040[];                         /* 256-entry CRC table (not the zlib table at 0x880C84C0) */

/* Swing_DLL.xex 0x88605438: table CRC of a C string, initial value ~0, final complement; a null string
 * gives 0xFFFFFFFF. The `const u8 *p = s` copy gives the target's `mr r9,r3`, and the for loop over *p
 * keeps the CRC in one register across the null test. */
u32 ts4_str_crc_88605438(const char *s)
{
    u32 crc = 0;
    if (s != 0) {
        const u8 *p = (const u8 *)s;
        crc = 0xFFFFFFFF;
        for (; *p; p++)
            crc = lbl_880C8040[(crc ^ *p) & 0xff] ^ (crc >> 8);
    }
    return ~crc;
}
