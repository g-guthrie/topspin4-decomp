/* 0x883E3D40: counts the selected slots (mask bits 0x10..0x80), offsets a copy of the descriptor by the owner origin, copies it into each selected slot (or slot 0 when none) and only the x field into the others, then forwards it to the sink (88317C68); 0x25 for a null descriptor */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Desc { int x; int p4; int y; char pad[0x44 - 0xc]; unsigned int mask; int last; } Desc;
typedef struct T { char pad0[0xc]; int x; int y; Desc slots[4]; void *sink; } T;
void fn_8857ACB8(void *dst, const void *src, unsigned int n);
int ts4_lookup_then_forward_88317C68(void *h, Desc *d);

int fn_883E3D40(T *t, const Desc *d)
{
    int n, i, r;
    Desc tmp;
    n = 0;
    if (!d)
        return 0x25;
    for (i = 0; i < 4; i++)
        if (d->mask & (0x10 << i))
            n++;
    tmp = *d;
    tmp.x += t->x;
    tmp.y += t->y;
    tmp.last = 0;
    for (i = 0; i < 4; i++) {
        unsigned int bit = 0x10 << i;
        if (!(d->mask & bit) && (n || i)) {
            t->slots[i].x = tmp.x;
        } else {
            fn_8857ACB8(&t->slots[i], &tmp, sizeof(tmp));
            t->slots[i].mask = (t->slots[i].mask & ~0xf0u) | bit;
        }
    }
    if (t->sink) {
        r = ts4_lookup_then_forward_88317C68(t->sink, &tmp);
        if (r)
            return r;
    }
    return 0;
}
