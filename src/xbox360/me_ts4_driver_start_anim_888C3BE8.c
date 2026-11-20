/* Swing_DLL.xex 0x888C3BE8: Starts the driven animation: value, dirty/done flags, three enable bytes, special-mode byte, and the pending hash picked from kind (shared set=1 tail).
 * /Oc. The null guards are signed (cmpwi), so they are written as (int) tests; the hash if/else-if falls into one 'set = 1' store. */
typedef struct Anim { unsigned char pad[0x40]; int value; unsigned char pad44[0x55 - 0x44]; unsigned char dirty; unsigned char done; } Anim;
typedef struct Flags3 { unsigned char a, b, c; } Flags3;
typedef struct Pending { unsigned int hash; unsigned char pad4[0x18 - 4]; unsigned char set; unsigned char special; } Pending;
typedef struct Driver {
    unsigned char pad[0x1c];
    Anim *anim;        /* 0x1c */
    Flags3 *flags;     /* 0x20 */
    unsigned char pad24[4];
    Pending *pending;  /* 0x28 */
} Driver;

void fn_888C3BE8(Driver *d, int value, unsigned int kind, unsigned int mode)
{
    Anim *a = d->anim;
    if ((int)a == 0 || (int)d->flags == 0) return;
    a->value = value;
    d->anim->dirty = 1;
    d->anim->done = 0;
    d->flags->c = 1;
    d->flags->a = 1;
    d->flags->b = 1;
    d->pending->special = mode == 0xFE701924;
    if (kind == 0xF5BF4F97)
        d->pending->hash = 0x3583143C;
    else if (kind == 0x4DD88F5A)
        d->pending->hash = 0xDDDB885D;
    d->pending->set = 1;
}
