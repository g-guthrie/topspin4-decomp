/* Loader_DLL.xex 0x831C6BC8-0x83261728, executable version 0.0.0.3. */
/* Release a nine-word record: free the attached buffer, then clear the record. */
extern void ts4_tailcall_fn_8340D830_831BB278(void *);
extern void ts4_tailcall_fn_8340D830_832522A8(void *);
typedef struct { void *buf; int w[8]; } Ts4lRecord9;

void ts4l_release_clear_831C6BC8(Ts4lRecord9 *p)
{
    int i;

    if (p) {
        ts4_tailcall_fn_8340D830_831BB278(p->buf);
        for (i = 0; i < 9; i++)
            ((int *)p)[i] = 0;
    }
}

void ts4l_release_clear_832616D8(Ts4lRecord9 *p)
{
    int i;

    if (p) {
        ts4_tailcall_fn_8340D830_832522A8(p->buf);
        for (i = 0; i < 9; i++)
            ((int *)p)[i] = 0;
    }
}
