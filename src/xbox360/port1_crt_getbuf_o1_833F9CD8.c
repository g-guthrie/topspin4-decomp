/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l25_crt_getbuf_o1_833F9CD8.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* MSVC CRT _getbuf: give a stdio stream a 4096-byte buffer, or fall back to its one-char buffer when allocation fails. */
typedef unsigned long ts4_u32;

typedef struct {
    char *ptr;
    int cnt;
    char *base;
    ts4_u32 flag;
    ts4_u32 file;
    ts4_u32 charbuf;
    int bufsiz;
} Ts4lFile;

extern int lbl_88D2E540;
extern void *ts4_crt_nh_malloc_88565258(ts4_u32 size);

/* Swing_DLL.xex 0x885776D8 */
void *ts4_crt_getbuf_885776D8(Ts4lFile *f)
{
    void *b;
    ++lbl_88D2E540;
    b = ts4_crt_nh_malloc_88565258(4096);
    f->base = (char *)b;
    if (b != 0) {
        f->flag |= 8;
        f->bufsiz = 4096;
    } else {
        f->flag |= 4;
        f->base = (char *)&f->charbuf;
        f->bufsiz = 2;
    }
    f->ptr = f->base;
    f->cnt = 0;
    return b;
}

