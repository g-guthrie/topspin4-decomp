typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039750[];
typedef struct Range { void *owner; int index; int count; } Range;
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
int fn_883E52E0(Range *r, Range *src);
static void range_init(Range *r)
{
    r->owner = 0;
    r->index = -1;
    r->count = 0;
}
int fn_883E6438(void *owner, Range **out, Range *src)
{
    Range *r;
    int e;
    if (!out)
        return 0x25;
    r = (Range *)fn_88315C60(lbl_88B3302C->heap, 0xc, lbl_88039750, 0x280, 0, 0);
    if (r)
        range_init(r);
    else
        r = 0;
    *out = r;
    if (!r)
        return 0x2c;
    r->owner = owner;
    if (src && src->owner != owner)
        return 0x21;
    e = fn_883E52E0(r, src);
    if (e)
        return e;
    return e;
}
