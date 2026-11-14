/* Swing_DLL.xex 0x88321048-0x88321164, executable version 0.0.0.3. */
typedef struct Ts4Node88321048 { struct Ts4Node88321048 *next; char pad[0x18]; unsigned val; } Ts4Node88321048;
typedef struct Ts4Owner88321048 { char pad0[0x1cc]; Ts4Node88321048 sentinel; } Ts4Owner88321048;
int ts4_get_nth_88321048(Ts4Owner88321048 *o, int idx, unsigned *out)
{
    int i;
    Ts4Node88321048 *s;
    Ts4Node88321048 *n;
    if (out == 0) { return 0x25; }
    i = idx;
    s = &o->sentinel;
    if (idx < 0) { return 0x25; }
    n = s->next;
    if (n == s) { return 0x25; }
    for (; i > 0; --i) {
        n = n->next;
        if (n == s) { return 0x25; }
    }
    if (n == 0) { return 0x25; }
    *out = n->val;
    return 0;
}
typedef struct Ts4Node883210A8 { struct Ts4Node883210A8 *next; char pad[0x24]; unsigned val; } Ts4Node883210A8;
typedef struct Ts4Owner883210A8 { char pad0[0x160]; Ts4Node883210A8 sentinel; } Ts4Owner883210A8;
int ts4_get_nth_883210A8(Ts4Owner883210A8 *o, int idx, unsigned *out)
{
    int i;
    Ts4Node883210A8 *s;
    Ts4Node883210A8 *n;
    if (out == 0) { return 0x25; }
    i = idx;
    s = &o->sentinel;
    if (idx < 0) { return 0x25; }
    n = s->next;
    if (n == s) { return 0x25; }
    for (; i > 0; --i) {
        n = n->next;
        if (n == s) { return 0x25; }
    }
    if (n == 0) { return 0x25; }
    *out = n->val;
    return 0;
}
typedef struct Ts4Node88321108 { struct Ts4Node88321108 *next; char pad[0x14]; unsigned val; } Ts4Node88321108;
typedef struct Ts4Owner88321108 { char pad0[0x24c]; Ts4Node88321108 sentinel; } Ts4Owner88321108;
int ts4_get_nth_88321108(Ts4Owner88321108 *o, int idx, unsigned *out)
{
    int i;
    Ts4Node88321108 *s;
    Ts4Node88321108 *n;
    if (out == 0) { return 0x25; }
    i = idx;
    s = &o->sentinel;
    if (idx < 0) { return 0x25; }
    n = s->next;
    if (n == s) { return 0x25; }
    for (; i > 0; --i) {
        n = n->next;
        if (n == s) { return 0x25; }
    }
    if (n == 0) { return 0x25; }
    *out = n->val;
    return 0;
}
