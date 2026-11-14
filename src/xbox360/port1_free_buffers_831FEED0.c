/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l15_free_buffers_831FEED0.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Free the three owned buffers of a record (offsets 0, 0xc, 0x14) and clear the record. */
typedef struct { void *a; int p1, p2; void *b; int p3; void *c; } Ts4lBufRecord;

extern void ts4_forward_with_const_248C8000_885BE200(void *);

/* Swing_DLL.xex 0x885D90C8 */
void ts4_free_buffers_885D90C8(Ts4lBufRecord *p)
{
    int i;

    if (p->a) {
        ts4_forward_with_const_248C8000_885BE200(p->a);
        p->a = 0;
    }
    if (p->b) {
        ts4_forward_with_const_248C8000_885BE200(p->b);
        p->b = 0;
    }
    if (p->c) {
        ts4_forward_with_const_248C8000_885BE200(p->c);
        p->c = 0;
    }
    for (i = 0; i < 6; i++)
        ((int *)p)[i] = 0;
}

