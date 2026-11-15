/* 0x8868E950 (draft, 25 instructions off): two-level threshold lookup in relative-offset tables.
 * Open: the target materialises the table pointer (addi) and reloads its offset for begin after end;
 * ours folds the offset load and shares it. Typed/volatile reads of the offset did not change that. */
typedef struct Entry { float key; float value; } Entry;
typedef struct Row { int offset; unsigned int count; int pad; float limit; } Row;
typedef struct Table { int offset; unsigned int count; } Table;
typedef struct Data { char p[0x824]; Table rows; } Data;
typedef struct Mid { char p[0x6c]; Data *data; } Mid;
typedef struct Obj { char p[0x44]; Mid *mid; } Obj;
extern const float lbl_8814B440;
static __inline Row *rows_begin(Table *t) { Row *r = 0; if (t->offset != -1) r = (Row *)((char *)t + t->offset); return r; }
static __inline Row *rows_end(Table *t) { Row *r = 0; if (t->offset != -1) r = (Row *)((char *)t + (t->count * 16 + t->offset)); return r; }
static __inline Entry *ent_begin(Row *t) { Entry *r = 0; if (t->offset != -1) r = (Entry *)((char *)t + t->offset); return r; }
static __inline Entry *ent_end(Row *t) { Entry *r = 0; if (t->offset != -1) r = (Entry *)((char *)t + (t->count * 8 + t->offset)); return r; }
static __inline Row *find_row(Table *t, float y)
{
    Row *end = rows_end(t);
    Row *it = rows_begin(t);
    for (; it != end; it++) {
        if (y <= it->limit)
            return it;
    }
    return end;
}
float ts4_lookup_threshold_grid_8868E950(Obj *o, float x, float y)
{
    float res = lbl_8814B440;
    Row *r = find_row(&o->mid->data->rows, y);
    if (r != 0) {
        Entry *e = ent_begin(r);
        Entry *ee = ent_end(r);
        for (; e != ee; e++) {
            if (x <= e->key)
                return e->value;
        }
    }
    return res;
}
