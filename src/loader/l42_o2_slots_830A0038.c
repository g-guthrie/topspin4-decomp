/* Loader_DLL.xex 0x830A0038-0x830A7990, executable version 0.0.0.3. */
typedef struct Ent { unsigned key; unsigned val; } Ent;
typedef struct Tab { Ent e[32]; int count; } Tab;

Ent *ts4l_tab_find_830A0038(Tab *t, unsigned key)
{
    Ent *r = 0;
    Ent *p;
    Ent *end = t->e + t->count;
    for (p = t->e; p != end; p++) {
        if (p->key == key) {
            r = p;
            break;
        }
    }
    return r;
}

Ent *ts4l_tab_alloc_830A0078(Tab *t)
{
    Ent *r = 0;
    int n = t->count;
    if (n < 32) {
        r = &t->e[n];
        t->count = n + 1;
    }
    return r;
}

typedef struct Rec { char b[0x14c]; } Rec;
typedef struct Pool { Rec r[32]; int count; } Pool;
Rec *ts4l_pool_alloc_830A01E8(Pool *t)
{
    Rec *r = 0;
    int n = t->count;
    if (n < 32) {
        r = &t->r[n];
        t->count = n + 1;
    }
    return r;
}

int ts4l_kind_size_830A7990(int *o)
{
    int r = 0;
    int k = o[1];
    if (k == 8 || k == 9)
        r = 4;
    else if (k == 10)
        r = 24;
    return r;
}
