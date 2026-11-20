struct W10nS;
typedef unsigned char (*W10nBool)(struct W10nS *);
typedef struct W10nX *(*W10nGet)(struct W10nS *, int);
struct W10nVt { unsigned char pad[0x30]; W10nBool f30; unsigned char pad34[0x4c - 0x34]; W10nGet f4c; };
struct W10nS { struct W10nVt *vt; };
struct W10nH { int rel; unsigned cnt; };
struct W10nX { unsigned char pad[0x30]; struct W10nH h; };
struct W10nO { unsigned char pad[0x1c]; struct W10nS sub; unsigned char pad20[0x78 - 0x20]; unsigned w78; };
void ts4_counter_inc_saturate_886567A8(struct W10nO *o, unsigned idx)
{
    if (o->sub.vt->f30(&o->sub) && o->w78 == 0) {
        struct W10nH *h = &o->sub.vt->f4c(&o->sub, 0)->h;
        if (idx < h->cnt) {
            unsigned *e = (unsigned *)((char *)h + (idx * 4 + h->rel));
            unsigned v = *e;
            if (0xffffffffu - v >= 1)
                *e = v + 1;
            else
                *e = 0xffffffffu;
        }
    }
}

struct W10uS;
typedef unsigned char (*W10uBool)(struct W10uS *);
typedef struct W10uX *(*W10uGet)(struct W10uS *, int);
struct W10uVt { unsigned char pad[0x30]; W10uBool f30; unsigned char pad34[0x4c - 0x34]; W10uGet f4c; };
struct W10uS { struct W10uVt *vt; };
struct W10uH { int rel; unsigned cnt; };
struct W10uRec { unsigned char pad[0xc]; struct W10uH h; unsigned char pad14[0x1c - 0x14]; };
struct W10uA { int rel; };
struct W10uX { unsigned char pad[0x48]; struct W10uA a48; unsigned cnt4c; };
struct W10uO { unsigned char pad[0x1c]; struct W10uS sub; unsigned char pad20[0x78 - 0x20]; unsigned w78; };
void ts4_counter_inc16_saturate_88655DF0(struct W10uO *o, int side, unsigned idx)
{
    if (o->sub.vt->f30(&o->sub) && o->w78 == 0) {
        struct W10uX *x = o->sub.vt->f4c(&o->sub, 0);
        if (side < 4 && (unsigned)side < x->cnt4c) {
            struct W10uA *a = &x->a48;
            struct W10uRec *rec = (struct W10uRec *)((char *)a + (side * 0x1c + a->rel));
            struct W10uH *h = &rec->h;
            if (idx < h->cnt) {
                unsigned short *e = (unsigned short *)((char *)h + (idx * 2 + h->rel));
                int v = *e;
                if (0xffff - v >= 1)
                    *e = v + 1;
                else
                    *e = 0xffff;
            }
        }
    }
}
