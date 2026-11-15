/* W11A: small gameplay functions (re-sweep). */

/* 0x886C7CA0: reset eight slot ids to -1 and clear the flag (sub-object helper keeps the register order). */
struct W11aSlots { int w[8]; unsigned char flag; };
struct W11aSlotOwner { char pad[0x178]; struct W11aSlots s; };
struct W11aSlotMid { char pad[0x14]; struct W11aSlotOwner *p14; };
struct W11aSlotRoot { char pad[8]; struct W11aSlotMid *p8; };

static __inline void w11a_slots_reset(struct W11aSlots *s)
{
    s->w[0] = -1; s->w[1] = -1; s->w[2] = -1; s->w[3] = -1;
    s->w[4] = -1; s->w[5] = -1; s->w[6] = -1; s->w[7] = -1;
    s->flag = 0;
}

void ts4_reset_slots_886C7CA0(struct W11aSlotRoot *o)
{
    w11a_slots_reset(&o->p8->p14->s);
}

/* 0x88669EF0: sum of one entry from each of two self-relative tables (12-byte stride). */
struct W11aHdr { int rel; };
struct W11aPair { struct W11aHdr a; char pad[0x14]; struct W11aHdr b; };
struct W11aTabOwner { char pad[0x24]; struct W11aHdr hdr; };
struct W11aTabRoot { char pad[8]; struct W11aTabOwner *p8; };

static __inline int *w11a_ent(struct W11aHdr *h, int i)
{
    return (int *)((char *)h + (i * 12 + h->rel));
}

int ts4_sum_two_tables_88669EF0(struct W11aTabRoot *o, int idx)
{
    int pd0 = 0; int pd1 = 0; int pd2 = 0; int pd3 = 0;
    struct W11aHdr *h = &o->p8->hdr;
    struct W11aPair *x = (struct W11aPair *)((char *)h + h->rel);
    int *a = w11a_ent(&x->a, idx);
    int *b;
    {
        int q0 = 0; int q1 = 0; int q2 = 0; int q3 = 0; int q4 = 0; int q5 = 0; int q6 = 0;
        struct W11aHdr *hb = &x->b;
        b = (int *)((char *)hb + (idx * 12 + hb->rel));
        (void)q0; (void)q1; (void)q2; (void)q3; (void)q4; (void)q5; (void)q6;
    }
    (void)pd0; (void)pd1; (void)pd2; (void)pd3;
    return *b + *a;
}

/* 0x88677480: initialise the ids of a self-relative record, flag the sibling object, then tail-call virtual slot 15. */
struct W11aRecHdr { int rel; int w4; int w8; int wc; int w10; };
struct W11aRecDom { char pad[0x48]; struct W11aRecHdr hdr; };
struct W11aRecFlag { char pad[0x37c]; unsigned char flag; };
struct W11aRecMid { char pad[0x44]; struct W11aRecDom *dom; char pad2[4]; struct W11aRecFlag *other; };
struct W11aRecObj { void **vtbl; struct W11aRecMid *mid; };
struct W11aRec { int w0; int w4; int w8; int wc; };

void ts4_init_rel_record_88677480(struct W11aRecObj *self)
{
    struct W11aRecHdr *h = &self->mid->dom->hdr;
    { int *p = &h->w10; *p = 0x23baed9e; }
    h->wc = 0;
    ((struct W11aRec *)((char *)h + h->rel))->w0 = 0;
    ((struct W11aRec *)((char *)h + h->rel))->w8 = 0;
    ((struct W11aRec *)((char *)h + h->rel))->w4 = 0x317c51b7;
    ((struct W11aRec *)((char *)h + h->rel))->wc = 0xa2eda1e7;
    self->mid->other->flag = 1;
    ((void (*)(struct W11aRecObj *))self->vtbl[15])(self);
}

/* 0x886CC408: when the flag is set and the lock byte is clear, claim the first free 0x80-byte slot of a
 * self-relative array (handle 0 -> 0x7445A27F) and store the float and key into it. The handle store goes
 * through its own block-local pointer so it stays first in source order. */
struct W11aSlotEnt { char pad[0x44]; unsigned h44; char pad2[0x5c - 0x48]; unsigned w5c; float f60; char pad3[0x80 - 0x64]; };
struct W11aSlotRel { int off; int count; };
struct W11aSlotTab { char pad[0x49c]; struct W11aSlotRel rel; };
struct W11aSlotFlags { char pad[0x1c]; unsigned char a; unsigned char b; };
struct W11aSlotCfg { char pad[0x34]; struct W11aSlotFlags *c; };
struct W11aSlotMgr { char pad[0x10]; struct W11aSlotCfg *cfg; struct W11aSlotTab *tab; };
struct W11aSlotHost { char pad[0x1c]; struct W11aSlotMgr *mgr; };

void ts4_claim_slot_886CC408(struct W11aSlotHost *self, unsigned k, float v)
{
    int ok = self->mgr->cfg->c->a != 0 && self->mgr->cfg->c->b == 0;
    if ((unsigned char)ok) {
        struct W11aSlotRel *r = &self->mgr->tab->rel;
        struct W11aSlotEnt *e, *end;
        e = 0;
        if (r->off != -1) e = (struct W11aSlotEnt *)((char *)r + r->off);
        end = 0;
        if (r->off != -1) end = (struct W11aSlotEnt *)((char *)r + (r->count * 0x80 + r->off));
        for (; e != end; e++) {
            if (e->h44 == 0) {
                { unsigned *hp = &e->h44; *hp = 0x7445A27F; }
                e->f60 = v;
                e->w5c = k;
                return;
            }
        }
    }
}

/* 0x8864A848: forward the 12-byte handle through ts4_handle_forward_88150770 with id 0xebfaeca9, read the int32
 * from the result (ts4_gp0_xdata_get_int32_88163D18) and hand its address on to fn_8864A770. */
typedef unsigned long w11a_word;
typedef struct W11aArgs3 { w11a_word w[3]; } W11aArgs3;
w11a_word ts4_handle_forward_88150770();
w11a_word ts4_gp0_xdata_get_int32_88163D18();
void fn_8864A770(w11a_word a0, w11a_word a1, w11a_word a2, w11a_word a3);

void ts4_call_xdata_8864A848(w11a_word a0, w11a_word a1, W11aArgs3 sp1, w11a_word a3)
{
    w11a_word loc50[1];
    w11a_word loc54[1];
    w11a_word loc58[3];
    loc50[0] = 0xebfaeca9u;
    loc54[0] = ts4_gp0_xdata_get_int32_88163D18(ts4_handle_forward_88150770((w11a_word)(w11a_word)&loc58[0], (w11a_word)(w11a_word)&sp1, (w11a_word)(w11a_word)&loc50[0]));
    fn_8864A770(a0, a1, (w11a_word)(w11a_word)&loc54[0], a3);
}
