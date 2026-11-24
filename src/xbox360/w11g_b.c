typedef struct Hdr { int rel; unsigned cnt; } Hdr;
typedef struct Ent { char p[0x14]; unsigned a; unsigned b; char q[0x28 - 0x1c]; } Ent;
typedef struct Q { char p[0x70]; } Q;
typedef struct P { char p[0x18]; Q *q; } P;
typedef struct M { char p[0x34]; P *m; } M;
extern Hdr *fn_88265938(void *);
int ts4_has_pair_886C7F10(M *self, int unused, unsigned *k1, unsigned *k2)
{
    Ent *begin, *end, *e;
    Hdr *h;
    int r = 0;
    h = fn_88265938((char *)self->m->q + 0x70);
    (void)unused;
    if (h != 0) {
        end = 0;
        if (h->rel != -1) end = (Ent *)((char *)h + (h->rel + h->cnt * 0x28));
        begin = 0;
        if (h->rel != -1) begin = (Ent *)((char *)h + h->rel);
        for (e = begin; e != end; e++) {
            if (e->a == *k1) {
                if (e->b == *(volatile unsigned *)k2) { r = 1; break; }
            }
        }
    }
    return r;
}
