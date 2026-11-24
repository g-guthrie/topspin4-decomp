/* Loader_DLL.xex 0x8320E040-0x83210E14, executable version 0.0.0.3. */
/* Validate an allocation-style request (non-zero size/count, power-of-two alignment
 * defaulting to 1) and forward it to the worker. */
extern int fn_8320DD38();
extern int fn_83210C48();
typedef struct { unsigned align; int e; unsigned size; unsigned count; } Ts4lRequest;

int ts4l_validate_request_8320E040(int a, int b, int c, int d, int e, unsigned align, unsigned size, unsigned count)
{
    Ts4lRequest r;
    unsigned al = align;

    if (align == 0)
        al = 1;
    r.e = e;
    r.align = al;
    r.size = size;
    r.count = count;
    if (size == 0)
        goto fail;
    if (count == 0)
        goto fail;
    if ((al & (al - 1)) != 0)
        goto fail;
    goto call;
fail:
    return 0;
call:
    return fn_8320DD38(a, b, c, d, &r, 0);
}

int ts4l_validate_request_83210D98(int a, int b, int c, int e, unsigned align, unsigned size, unsigned count)
{
    Ts4lRequest r;
    unsigned al = align;

    if (align == 0)
        al = 1;
    r.e = e;
    r.align = al;
    r.size = size;
    r.count = count;
    if (size == 0)
        goto fail;
    if (count == 0)
        goto fail;
    if ((al & (al - 1)) != 0)
        goto fail;
    goto call;
fail:
    return 0;
call:
    return fn_83210C48(a, b, c, &r, 0);
}
