/* Loader_DLL.xex 0x833FB560-0x833FB7D4, executable version 0.0.0.3. */
/* Library routine: CRT _fgetwc_nolock (UTF-16, multibyte text and binary reads). */

typedef int ts4l_wint;
typedef unsigned short ts4l_wchar;

typedef struct ts4l_file {
    unsigned char *ptr;
    int cnt;
    char *base;
    int flag;
    int file;
    int charbuf;
    int bufsiz;
    char *tmpfname;
} ts4l_file;

typedef struct ts4l_ioinfo {
    char pad0[4];
    unsigned char osfile;
    char pad1[0x23];
    unsigned char textmode;
    char pad2[0x1f];
} ts4l_ioinfo;

extern ts4l_ioinfo lbl_8352C658;
extern ts4l_ioinfo *lbl_8354B980[];

int *fn_833E9F90(void);
int fn_833F0888(ts4l_file *stream);
int fn_833FA6D0(ts4l_file *stream);
int fn_833FA1D0(int c);
int fn_833FA420(ts4l_wchar *dst, const char *mb, unsigned int n);
int fn_833FAA30(int c, ts4l_file *stream);
int fn_83409698(ts4l_file *stream);

#define TS4L_PIOINFO(i) (lbl_8354B980[(i) >> 5] + ((i) & 31))
#define TS4L_PIOINFO_SAFE(i) ((((i) != -1) && ((i) != -2)) ? TS4L_PIOINFO(i) : &lbl_8352C658)
#define TS4L_GETC(s) (--(s)->cnt >= 0 ? 0xff & *(s)->ptr++ : fn_833FA6D0(s))

ts4l_wint ts4l_fgetwc_nolock_833FB560(ts4l_file *stream)
{
    ts4l_wchar wch;
    int ch;
    int size;
    char mbc[4];

    if (!(stream->flag & 0x40) && (TS4L_PIOINFO_SAFE(fn_833F0888(stream))->textmode & 0xfe)) {
        char *pch = (char *)&wch;
        if ((ch = TS4L_GETC(stream)) == -1)
            return -1;
        pch[0] = (char)ch;
        if ((ch = TS4L_GETC(stream)) == -1)
            return -1;
        pch[1] = (char)ch;
        return wch;
    }
    if (!(stream->flag & 0x40) && (TS4L_PIOINFO_SAFE(fn_833F0888(stream))->osfile & 0x80)) {
        size = 1;
        if ((ch = TS4L_GETC(stream)) == -1)
            return -1;
        mbc[0] = (char)ch;
        if (fn_833FA1D0((unsigned char)mbc[0])) {
            if ((ch = TS4L_GETC(stream)) == -1) {
                fn_833FAA30(mbc[0], stream);
                return -1;
            }
            mbc[1] = (char)ch;
            size = 2;
        }
        if (fn_833FA420(&wch, mbc, size) == -1) {
            *fn_833E9F90() = 42;
            return -1;
        }
        return wch;
    }
    stream->cnt -= 2;
    if (stream->cnt >= 0) {
        ts4l_wchar v = *(ts4l_wchar *)stream->ptr;
        stream->ptr += 2;
        return v;
    }
    return (ts4l_wchar)fn_83409698(stream);
}
