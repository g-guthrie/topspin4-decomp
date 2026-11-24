/* 0x883D8EC8: state flags: 4 with the stored error, 4 if any child's slot-14 query fails, else 8 if playing, plus 2 if queued or 1 otherwise (0x25 for a null out) */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; } Link;
typedef struct Item Item;
typedef struct ItemVt { void *f[14]; int (*query)(Item *it, int *out); } ItemVt;
struct Item { ItemVt *vt; Link link; };
typedef struct Kids { int p0; Link head; } Kids;
typedef struct T {
    char pad0[0x20];
    short playing;
    short queued;
    int err;
    Kids *kids;
} T;

int fn_883D8EC8(T *t, unsigned int *st)
{
    Link *n;
    if (!st)
        return 0x25;
    *st = 0;
    if (t->err) {
        *st = 4;
        return t->err;
    }
    if (t->kids) {
        for (n = t->kids->head.next; n != (t->kids ? &t->kids->head : 0); n = n->next) {
            Item *it = n ? (Item *)((char *)n - 4) : 0;
            int tmp;
            int r = it->vt->query(it, &tmp);
            if (r) {
                *st = 4;
                return r;
            }
        }
    }
    if (t->playing > 0)
        *st |= 8;
    if (t->queued > 0)
        *st |= 2;
    else
        *st |= 1;
    return 0;
}
