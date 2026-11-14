/* Loader_DLL.xex 0x833F9CD8-0x833F9D60, executable version 0.0.0.3. */
/* MSVC CRT _getbuf: give a stdio stream a 4096-byte buffer, or fall back to its one-char buffer when allocation fails. */
typedef unsigned long ts4l_u32;

typedef struct {
    char *ptr;
    int cnt;
    char *base;
    ts4l_u32 flag;
    ts4l_u32 file;
    ts4l_u32 charbuf;
    int bufsiz;
} Ts4lFile;

extern int lbl_83543A4C;
extern void *fn_833E73F8(ts4l_u32 size);

void *ts4l_crt_getbuf_833F9CD8(Ts4lFile *f)
{
    void *b;
    ++lbl_83543A4C;
    b = fn_833E73F8(4096);
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
