/* W8A batch A: small gameplay functions (plain route, /Oc) */

/* 0x886B4B80: find the table record whose id equals the owner's id, remember it, and hand its value on. */
typedef struct W8aE4B80 { char pad[0xc]; int id; int val; } W8aE4B80;
typedef struct W8aH4B80 { int rel; int count; } W8aH4B80;
typedef struct W8aT4B80 { char pad[0x44]; W8aH4B80 h; } W8aT4B80;
typedef struct W8aP4B80 { char pad[0x40]; W8aT4B80 *t; } W8aP4B80;
typedef struct W8aS4B80 { char pad[0x14]; int id; char p2[0x48 - 0x18]; W8aP4B80 *p48; char p3[0x7c - 0x4c]; W8aE4B80 *found; } W8aS4B80;
void fn_886B4700(W8aS4B80 *s, int v);
void ts4_find_entry_by_id_886B4B80(W8aS4B80 *s)
{
    W8aH4B80 *h;
    W8aE4B80 *found;
    int i, n;
    int id = s->id;
    s->found = 0;
    h = &s->p48->t->h;
    found = 0;
    n = h->count;
    for (i = 0; i < n; i++) {
        W8aE4B80 *e = (W8aE4B80 *)((char *)h + (i * 0x20 + h->rel));
        if (e->id == id) { found = e; break; }
    }
    s->found = found;
    fn_886B4700(s, found->val);
}

/* 0x8864DA90: read an 8-byte header from the socket; on success log it and advance the state. */
typedef struct W8aN4DA90 { char pad[4]; int sock; } W8aN4DA90;
typedef struct W8aS4DA90 { char pad[4]; int f4; int f8; char pc[1]; unsigned char fd; char pe[2]; int f10; char p2[0x28 - 0x14]; W8aN4DA90 *p28; } W8aS4DA90;
extern unsigned ts4_tailcall_NetDll_recv_884F0318(int s, void *buf, int len, int flags);
extern char lbl_88D42FF8[];
void fn_88604E50(void *fmt, unsigned long long v);
unsigned char ts4_recv_header_8864DA90(W8aS4DA90 *s)
{
    unsigned long long buf = 0;
    if (ts4_tailcall_NetDll_recv_884F0318(s->p28->sock, &buf, 8, 0) != 8) {
        s->f4 = 0;
        s->f8 = 2;
        s->fd = 1;
        return 0;
    }
    fn_88604E50(lbl_88D42FF8, buf);
    s->f4 = 2;
    s->f10 = 0;
    return 1;
}
