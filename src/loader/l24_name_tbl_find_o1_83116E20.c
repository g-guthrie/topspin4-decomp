/* Loader_DLL.xex 0x83116E20-0x8313F928, executable version 0.0.0.3. */

typedef struct ts4l_name_rec { int name; int a; int b; } ts4l_name_rec;
typedef struct ts4l_name_tbl { ts4l_name_rec *arr; int cap; int count; } ts4l_name_tbl;

/* Zero-on-match comparison (string-compare style) against the record name. */
extern int fn_833E4108(void *key, int name);

/* Linear search of a table of 12-byte records; returns the matching index or -1. */
int ts4l_name_tbl_find_83116E20(ts4l_name_tbl *t, void *key)
{
    int i;
    ts4l_name_rec *p;
    for (i = 0; i < t->count; i++) {
        p = t->arr;
        if (!fn_833E4108(key, p[i].name))
            return i;
    }
    return -1;
}

int ts4l_name_tbl_find_83116E88(ts4l_name_tbl *t, void *key)
{
    int i;
    ts4l_name_rec *p;
    for (i = 0; i < t->count; i++) {
        p = t->arr;
        if (!fn_833E4108(key, p[i].name))
            return i;
    }
    return -1;
}

int ts4l_name_tbl_find_8311D1C0(ts4l_name_tbl *t, void *key)
{
    int i;
    ts4l_name_rec *p;
    for (i = 0; i < t->count; i++) {
        p = t->arr;
        if (!fn_833E4108(key, p[i].name))
            return i;
    }
    return -1;
}

int ts4l_name_tbl_find_8311E7C0(ts4l_name_tbl *t, void *key)
{
    int i;
    ts4l_name_rec *p;
    for (i = 0; i < t->count; i++) {
        p = t->arr;
        if (!fn_833E4108(key, p[i].name))
            return i;
    }
    return -1;
}

int ts4l_name_tbl_find_8313F928(ts4l_name_tbl *t, void *key)
{
    int i;
    ts4l_name_rec *p;
    for (i = 0; i < t->count; i++) {
        p = t->arr;
        if (!fn_833E4108(key, p[i].name))
            return i;
    }
    return -1;
}

int ts4l_name_tbl_find_83145588(ts4l_name_tbl *t, void *key)
{
    int i;
    ts4l_name_rec *p;
    for (i = 0; i < t->count; i++) {
        p = t->arr;
        if (!fn_833E4108(key, p[i].name))
            return i;
    }
    return -1;
}

