/* 0x885641A8: calls every non-null function pointer in [p, end) (initterm shape) */
/* Matched on /Oc /Os (agAH).  */
typedef void (*PVFV)(void);
void fn_885641A8(PVFV *p, PVFV *end)
{
    for (; p < end; p++) {
        if (*p)
            (*p)();
    }
}
