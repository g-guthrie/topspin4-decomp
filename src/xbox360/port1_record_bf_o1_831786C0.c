/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l9_record_bf_o1_831786C0.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
typedef struct ts4_rec60 {
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
} ts4_rec60;

typedef struct ts4_rec_table {
    unsigned count;
    unsigned flags;
    ts4_rec60 *recs;
} ts4_rec_table;

/* Update two bitfields of a 0x60-byte record, flagging it dirty on change. */



/* Swing_DLL.xex 0x8859B360 */
int ts4_rec_set_fields_8859B360(ts4_rec_table *t, unsigned idx, unsigned a, unsigned b)
{
    ts4_rec60 *r = &t->recs[idx];
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

