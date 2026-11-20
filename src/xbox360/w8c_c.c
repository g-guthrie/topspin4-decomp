/* W8C: 0x88655F98, store one byte into the j-th entry of the i-th record of a self-relative table, only when the
 * owner reports ready and the key matches. One dead local shifts the operand order of the first add. */
struct M1Rec { int rel; unsigned count; unsigned char pad[0x1c - 8]; };
struct M1X { unsigned char pad[0x48]; int rel; unsigned count; };
struct M1Sub;
struct M1Vt { unsigned char pad[0x30]; unsigned char (*f30)(struct M1Sub *); unsigned char pad34[0x4c - 0x34]; struct M1X *(*f4c)(struct M1Sub *, int); };
struct M1Sub { struct M1Vt *vt; };
struct M1O { unsigned char pad[0x1c]; struct M1Sub sub; unsigned char pad20[0x78 - 0x20]; unsigned w78; };
void ts4_set_table_byte_88655F98(struct M1O *self, int i, unsigned j, unsigned char v, unsigned k)
{
    int pad0 = 0;
    struct M1Sub *s = &self->sub;
    (void)pad0;
    if (s->vt->f30(s)) {
        if (self->w78 == k) {
            struct M1X *x = s->vt->f4c(s, 0);
            if (i < 4 && (unsigned)i < x->count) {
                int *h = &x->rel;
                struct M1Rec *r = (struct M1Rec *)((char *)h + (i * 0x1c + *h));
                if (j < r->count) {
                    unsigned char *q = (unsigned char *)r + r->rel;
                    q[j] = v;
                }
            }
        }
    }
}
