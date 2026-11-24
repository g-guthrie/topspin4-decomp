/* Loader_DLL.xex 0x831FEED0-0x83272DA0, executable version 0.0.0.3. */
/* Free the three owned buffers of a record (offsets 0, 0xc, 0x14) and clear the record. */
extern void ts4_tailcall_fn_8340D830_831BB278(void *);
extern void ts4_tailcall_fn_8340D830_832522A8(void *);
typedef struct { void *a; int p1, p2; void *b; int p3; void *c; } Ts4lBufRecord;

void ts4l_free_buffers_831FEED0(Ts4lBufRecord *p)
{
    int i;

    if (p->a) {
        ts4_tailcall_fn_8340D830_831BB278(p->a);
        p->a = 0;
    }
    if (p->b) {
        ts4_tailcall_fn_8340D830_831BB278(p->b);
        p->b = 0;
    }
    if (p->c) {
        ts4_tailcall_fn_8340D830_831BB278(p->c);
        p->c = 0;
    }
    for (i = 0; i < 6; i++)
        ((int *)p)[i] = 0;
}

void ts4l_free_buffers_83272D18(Ts4lBufRecord *p)
{
    int i;

    if (p->a) {
        ts4_tailcall_fn_8340D830_832522A8(p->a);
        p->a = 0;
    }
    if (p->b) {
        ts4_tailcall_fn_8340D830_832522A8(p->b);
        p->b = 0;
    }
    if (p->c) {
        ts4_tailcall_fn_8340D830_832522A8(p->c);
        p->c = 0;
    }
    for (i = 0; i < 6; i++)
        ((int *)p)[i] = 0;
}
