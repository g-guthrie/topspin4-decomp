/* W10A: sets four marker words in a self-relative record, then vslot 15 (Swing_DLL.xex 0x88677870). LTCG route. */
typedef struct A7Rel { int rel; unsigned w4, w8, wc, w10; } A7Rel;
typedef struct A7P4c { unsigned char pad[0x37c]; unsigned char b37c; } A7P4c;
typedef struct A7P44 { unsigned char pad[0x48]; A7Rel h; } A7P44;
typedef struct A7P4 { unsigned char pad[0x44]; A7P44 *p44; unsigned char pad2[0x4c - 0x48]; A7P4c *p4c; } A7P4;
typedef struct A7Vt { void (*slot[16])(void *self); } A7Vt;
typedef struct A7O { A7Vt *vt; A7P4 *p4; } A7O;
void ts4_set_slot_marks_88677870(A7O *s)
{
    A7Rel *h = &s->p4->p44->h;
    { unsigned *p = &h->w10; *p = 0x23BAED9Eu; }
    h->wc = 0;
    ((A7Rel *)((char *)h + h->rel))->rel = 0;
    ((A7Rel *)((char *)h + h->rel))->w8 = 0;
    ((A7Rel *)((char *)h + h->rel))->w4 = 0x317C51B7u;
    ((A7Rel *)((char *)h + h->rel))->wc = 0xA2EDA1E7u;
    s->vt->slot[15](s);
    s->p4->p4c->b37c = 1;
}
