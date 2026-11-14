/* Loader_DLL.xex 0x831786C0-0x83178780, executable version 0.0.0.3. */

typedef struct ts4l_rec60 {
    unsigned p0 : 12;
    unsigned id : 8;
    unsigned p1 : 12;
    unsigned p2 : 5;
    unsigned mode : 3;
    unsigned p3 : 24;
    unsigned hi : 6;
    unsigned fld : 26;
    unsigned pad[0x30 / 4 - 3];
    unsigned dirty;
    unsigned pad2[0x60 / 4 - 0x34 / 4];
} ts4l_rec60;

typedef struct ts4l_rec_table {
    unsigned count;
    unsigned flags;
    ts4l_rec60 *recs;
} ts4l_rec_table;

/* Update two bitfields of a 0x60-byte record, flagging it dirty on change. */
int ts4l_rec_set_fields_83178738(ts4l_rec_table *t, unsigned idx, unsigned a, unsigned b)
{
    ts4l_rec60 *r = &t->recs[idx];
    if (r->fld != a) {
        r->fld = a;
        r->dirty = 1;
    }
    if (r->mode != b) {
        r->mode = b;
        r->dirty = 1;
    }
    return 0;
}

/* Read three packed fields of a record (through its indirection when the
   table flag says so); zeroes the outputs when the record is not populated. */
int ts4l_rec_get_fields_831786C0(ts4l_rec_table *t, unsigned idx, unsigned *out)
{
    unsigned *r = (unsigned *)((unsigned char *)t->recs + idx * 0x60);
    unsigned *v = r;
    if (!(t->flags & 0x20000)) {
        v = ((unsigned **)r)[0x40 / 4];
    }
    if (!(v[0] & 0x00300000)) {
        out[0] = 0;
        out[1] = 0;
        out[2] = 0;
    } else {
        out[0] = r[0x15 + (v[4] >> 31)];
        out[1] = v[2] & 0x03ffffff;
        out[2] = ((unsigned char *)v)[4] & 7;
    }
    return 0;
}
