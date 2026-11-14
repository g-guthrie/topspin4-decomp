/*
 * GP1 draft (near match): fn_8868E950, 51 instructions differ. The original loads the relative-array
 * offset twice (once for begin, once for end) and builds end before begin for the row table but
 * begin before end for the column table; this version produces the same results.
 */
/* GP1: crowd gain table lookup (WP1). */

extern float lbl_8814B440; /* 0.0f */

/* Self-relative array header: offset == -1 means empty, otherwise the elements
   start `offset` bytes after the header. */
struct Gp1RelHeader {
    int offset;
    int count;
};

struct Gp1GainColumn {
    float key;   /* +0x0: upper bound on the first input */
    float gain;  /* +0x4 */
};

struct Gp1GainRow {
    struct Gp1RelHeader columns; /* +0x00, element stride 8 (Gp1GainColumn) */
    unsigned char pad0[0xc - 0x8];
    float level_limit;           /* +0x0c: upper bound on the second input */
};

struct Gp1GainTableOwner {
    unsigned char pad0[0x824];
    struct Gp1RelHeader rows;    /* +0x824, element stride 0x10 (Gp1GainRow) */
};

struct Gp1CrowdData {
    unsigned char pad0[0x6c];
    struct Gp1GainTableOwner *table; /* +0x6c */
};

struct Gp1CrowdReaction {
    unsigned char pad0[0x44];
    struct Gp1CrowdData *data;       /* +0x44 */
};

/* Swing_DLL.xex 0x8868E950: two-dimensional step lookup in the crowd gain table:
   first row whose level_limit >= level, then first column whose key >= ratio; 0 when none. */
float ts4_crowd_gain_lookup_8868E950(struct Gp1CrowdReaction *self, float ratio, float level)
{
    struct Gp1RelHeader *rows;
    struct Gp1GainRow *row_end;
    struct Gp1GainRow *row_begin;
    struct Gp1GainRow *row;
    struct Gp1GainColumn *column_end;
    struct Gp1GainColumn *column_begin;
    struct Gp1RelHeader *columns;
    float result;

    row_end = 0;
    rows = &self->data->table->rows;
    result = lbl_8814B440;
    if (rows->offset != -1) {
        row_end = (struct Gp1GainRow *)((char *)rows + (rows->count * 16 + rows->offset));
    }
    row_begin = 0;
    if (rows->offset != -1) {
        row_begin = (struct Gp1GainRow *)((char *)rows + rows->offset);
    }
    row = row_begin;
    while (row != row_end) {
        if (level <= row->level_limit) {
            row_end = row;
            break;
        }
        row++;
    }
    if (row_end == 0) {
        return result;
    }
    columns = &row_end->columns;
    column_begin = 0;
    if (columns->offset != -1) {
        column_begin = (struct Gp1GainColumn *)((char *)columns + columns->offset);
    }
    column_end = 0;
    if (columns->offset != -1) {
        column_end = (struct Gp1GainColumn *)((char *)columns + (columns->count * 8 + columns->offset));
    }
    while (column_begin != column_end) {
        if (ratio <= column_begin->key) {
            return column_begin->gain;
        }
        column_begin++;
    }
    return result;
}
