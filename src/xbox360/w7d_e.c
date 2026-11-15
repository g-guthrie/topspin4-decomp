/* W7D: lookup-and-pick (LTCG route, /Oc). */
typedef unsigned int w3_u32;
struct W3Rec { int rel; int v4; };
struct W3Ent { char pad[4]; w3_u32 v4; char pad2[0x50 - 8]; w3_u32 v50; };
struct W3Tgt { char pad[0x5c0]; w3_u32 v5c0; };
struct W3Mode { char pad[0x2c]; int mode; };
struct W3Obj8 { char pad[0x4c]; struct W3Mode *m; char pad2[0x74 - 0x50]; struct W3Tgt *t; };
struct W3Tbl { char pad[0x18]; int a18; char pad2[0x70 - 0x1c]; struct W3Rec h70; };
struct W3B1c { char pad[0x20]; w3_u32 key; };
struct W3Dst { char pad[0x54]; w3_u32 v54; };
struct W3Self {
    char pad[8];
    struct W3Obj8 *p8;
    char pad2[0x18 - 0xc];
    struct W3Ent *cur;
    struct W3B1c *p1c;
    char pad3[0x28 - 0x20];
    struct W3Dst *dst;
    struct W3Tbl *tbl;
};
extern struct W3Ent *fn_8826C400(void *tbl, w3_u32 *key);
extern struct W3Ent *fn_8826C478(void *tbl, w3_u32 *key);

/* Swing_DLL.xex 0x88671350: three dead locals only advance the symbol numbering (OP1 padding form). */
void ts4_pick_entry_88671350(struct W3Self *self)
{
    int w7d_p0 = 0, w7d_p1 = 0, w7d_p2 = 0;
    int mode = self->p8->m->mode;
    w3_u32 key = self->p1c->key;
    struct W3Rec *h;
    struct W3Ent *e;
    if (mode == 2) {
        e = fn_8826C400(&self->tbl->a18, &key);
        if (e) {
            key = e->v4;
            if (key == 0x1796e383u)
                self->p8->t->v5c0 = 0x1110721au;
            else
                self->p8->t->v5c0 = 0x2ce33943u;
        }
    }
    h = &self->tbl->h70;
    e = fn_8826C478(h, &key);
    if (e)
        self->cur = e;
    else
        self->cur = (struct W3Ent *)((char *)h + h->rel);
    self->dst->v54 = self->cur->v50;
    (void)w7d_p0; (void)w7d_p1; (void)w7d_p2;
}
