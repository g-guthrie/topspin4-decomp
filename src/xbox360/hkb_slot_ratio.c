/* HKB: plain-route functions from the W11F batch (slot-mark setter, threshold ratio), /Oc. */

typedef struct HkbRel { int rel; unsigned w4, w8, wc, w10; } HkbRel;
typedef struct HkbDom { unsigned char pad[0x48]; HkbRel h; } HkbDom;
typedef struct HkbMid {
    unsigned char pad[0x44];
    HkbDom *dom;
} HkbMid;
typedef struct HkbVt { void (*slot[16])(void *self); } HkbVt;
typedef struct HkbObj { HkbVt *vt; HkbMid *mid; } HkbObj;

/* Swing_DLL.xex 0x88678170 */
void ts4_set_slot_marks_88678170(HkbObj *s)
{
    HkbRel *h = &s->mid->dom->h;
    { unsigned *p = &h->w10; *p = 0x23BAED9Eu; }
    h->wc = 0;
    ((HkbRel *)((char *)h + h->rel))->rel = 0;
    ((HkbRel *)((char *)h + h->rel))->w8 = 0;
    ((HkbRel *)((char *)h + h->rel))->w4 = 0x317C51B7u;
    ((HkbRel *)((char *)h + h->rel))->wc = 0xA2EDA1E7u;
    s->vt->slot[15](s);
}

typedef struct HkbCfg { unsigned char pad[0x654]; float x; float y; } HkbCfg;
typedef struct HkbCfgMid { unsigned char pad[0x74]; HkbCfg *cfg; } HkbCfgMid;
typedef struct HkbThr { unsigned char pad[0x98]; float thr; } HkbThr;
typedef struct HkbRatio {
    unsigned char pad[0xc];
    HkbThr *t;
    unsigned char pad2[0x24 - 0x10];
    HkbCfgMid *m;
    unsigned char pad3[0xf8 - 0x28];
    int a;
    int b;
} HkbRatio;

/* Swing_DLL.xex 0x8865B3B0 */
int ts4_ratio_above_threshold_8865B3B0(HkbRatio *s)
{
    int r = 0;
    float sum = (float)(s->a + s->b);
    if (s->m->cfg->y > s->m->cfg->x) {
        if ((float)s->a / sum >= s->t->thr)
            r = 1;
    } else if (s->m->cfg->y < s->m->cfg->x) {
        if ((float)s->b / sum >= s->t->thr)
            r = 1;
    }
    return r;
}
