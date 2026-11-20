/* 0x883E7C98: reads a u16 entry count and a u16 string-pool size from a stream (883194F0), allocates 8-byte entries and the pool, reads each entry's u32 at +4 and the pool, points each entry at its NUL-terminated name; third parameter unused; 0x2C on allocation failure */
/* Matched on /O1 plain and LTCG (agX, v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039A20[];
typedef struct Ent { char *name; int val; } Ent;
void *ts4_tailcall_fn_88315C60_88316068(void *heap, unsigned int size, const char *file, int line, int flags);
int fn_883194F0(void *stream, void *dst, unsigned int size, unsigned int count, int a);

int fn_883E7C98(Ent **out, int *count, int unused, void *stream)
{
    unsigned short n, len;
    Ent *e;
    char *p;
    int i, r;
    (void)unused;
    r = fn_883194F0(stream, &n, 2, 1, 0);
    if (r)
        return r;
    e = (Ent *)ts4_tailcall_fn_88315C60_88316068(lbl_88B3302C->heap, n * 8, lbl_88039A20, 0x7f, 0);
    if (!e)
        return 0x2c;
    r = fn_883194F0(stream, &len, 2, 1, 0);
    if (r)
        return r;
    p = (char *)ts4_tailcall_fn_88315C60_88316068(lbl_88B3302C->heap, len, lbl_88039A20, 0x88, 0);
    if (!p)
        return 0x2c;
    for (i = 0; i < n; i++) {
        r = fn_883194F0(stream, &e[i].val, 4, 1, 0);
        if (r)
            return r;
    }
    r = fn_883194F0(stream, p, 1, len, 0);
    if (r)
        return r;
    for (i = 0; i < n; i++) {
        e[i].name = p;
        while (*p++)
            ;
    }
    *out = e;
    *count = n;
    return 0;
}
