/* 0x883D1378: reads the kind-2 entry count from the database (+0x14) into +0x30, allocates the name pointer table (+0x2C) and fills it with a copy of each entry's name (at most 0x3FF chars) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns 0x2C when an allocation fails. */
typedef struct Mgr { int p0; void *heap; } Mgr;
extern Mgr *lbl_88B3302C;
extern char lbl_880391A8[];
typedef struct T { char pad[0x14]; void *db; char p18[0x2C - 0x18]; void **names; int count; } T;
int ts4_if_call_seq_fn_88309DB8_88308DC0(void *db, int kind, int *count);
void *ts4_tailcall_fn_88315C60_88316068(void *heap, unsigned int size, const char *file, int line, int flags);
int ts4_if_call_seq_fn_88309DB8_88308E18(void *db, int kind, int index, int *id);
int ts4_if_call_seq_fn_88309DB8_88308E60(void *db, int id, int a, char *buf, int max, int *len);
void *fn_883299F0(const char *s);
int ts4_load_name_table_883D1378(T *t)
{
    int *count = &t->count;
    int i, r, id, len;
    char name[0x400];
    r = ts4_if_call_seq_fn_88309DB8_88308DC0(t->db, 2, count);
    if (r) return r;
    if (*count) {
        t->names = (void **)ts4_tailcall_fn_88315C60_88316068(lbl_88B3302C->heap, *count * 4, lbl_880391A8, 0x404, 0);
        if (!t->names) return 0x2c;
    }
    for (i = 0; i < *count; ++i) {
        r = ts4_if_call_seq_fn_88309DB8_88308E18(t->db, 2, i, &id);
        if (r) return r;
        r = ts4_if_call_seq_fn_88309DB8_88308E60(t->db, id, 0, name, 0x3ff, &len);
        if (r) return r;
        name[0x3ff] = 0;
        t->names[i] = fn_883299F0(name);
        if (!t->names[i]) return 0x2c;
    }
    return 0;
}
