/* Swing_DLL.xex 0x88728350: Swing_DLL.xex 0x88728350: On the global game (lbl_88D45AD4): clears the pending flag, resets the sub-block at +0xEC (8825DE40), dispatches and clears the handle at +0x1D24 (object at handle-4), empties the byte vector at +0x15650.
 * /Oc. The handle is an int (cmpwi); access it through a Sub *s local so +0xEC stays in r31. */
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Sub {
    char pad0[0x1fc - 0xec];
    int pending;                /* 0x110 (game 0x1fc) */
    char pad114[4];
    unsigned char pending_flag; /* 0x118 */
    char pad119[0x1c38 - 0x119];
    int handle;                 /* 0x1c38 (game 0x1d24) */
    int handle_aux;             /* 0x1c3c */
} Sub;
typedef struct Game {
    char pad0[0xec];
    Sub sub;                    /* 0xec */
    char pad1d2c[0x15650 - 0x1d2c];
    ByteVec data;               /* 0x15650 */
} Game;
extern Game *lbl_88D45AD4;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void fn_8825DE40(Sub *s);
void ts4_registry_dispatch_888860A0(void *obj);
static __inline char *copy_bytes(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
void fn_88728350(void)
{
    Game *g = lbl_88D45AD4;
    Sub *s;
    ByteVec *v;
    if (g->sub.pending) {
        g->sub.pending = 0;
        g->sub.pending_flag = 0;
    }
    s = &g->sub;
    fn_8825DE40(s);
    if (s->handle) {
        ts4_registry_dispatch_888860A0((void *)(s->handle - 4));
        s->handle = 0;
        s->handle_aux = 0;
    }
    v = &g->data;
    v->last = copy_bytes(v->last, v->last, v->first);
}
