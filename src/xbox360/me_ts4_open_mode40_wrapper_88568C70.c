/* 0x88568C70: Calls fn_88575408(a, b, 0x40, c, &result, 0) and returns result, or -1 when the call fails. The shape looks like a C runtime open wrapper (share mode 0x40); 88575590 is the sibling that passes flag 1. */
/* Matched on /Oc /Os (agAH). Built /Os (2 off on /Oc). */
int fn_88575408(void *a, void *b, int mode, void *c, int *out, int flags);
int fn_88568C70(void *a, void *b, void *c)
{
    int result;
    if (fn_88575408(a, b, 0x40, c, &result, 0) != 0)
        return -1;
    return result;
}
