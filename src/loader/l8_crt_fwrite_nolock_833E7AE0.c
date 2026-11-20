/* Loader_DLL.xex 0x833E7AE0-0x833E7D44, executable version 0.0.0.3. */
/* Library routine: CRT _fwrite_nolock (stdout/stderr go to the debug output). */

typedef unsigned int ts4l_size_t;

typedef struct ts4l_file {
    char *ptr;
    int cnt;
    char *base;
    int flag;
    int file;
    int charbuf;
    int bufsiz;
    char *tmpfname;
} ts4l_file;

extern char lbl_8352C3D0[];

ts4l_file *fn_833F0488(void);
int *fn_833E9F90(void);
void fn_833E9D50(void);
void *fn_833E3AD0(void *dst, const void *src, ts4l_size_t n);
int fn_833F8280(ts4l_file *stream);
int fn_833F0888(ts4l_file *stream);
int fn_833F88C0(int fd, const void *buf, ts4l_size_t n);
int fn_833E8F20(int c, ts4l_file *stream);
void fn_8340F288(const char *s);

ts4l_size_t ts4l_fwrite_nolock_833E7AE0(const void *buffer, ts4l_size_t size,
                                        ts4l_size_t count, ts4l_file *stream)
{
    const char *data;
    ts4l_size_t total;
    ts4l_size_t left;
    ts4l_size_t bufsize;
    ts4l_size_t nbytes;
    int written;
    int cnt;
    char tmp[256];

    if (size == 0 || count == 0)
        return 0;
    if (stream == 0) {
        *fn_833E9F90() = 22;
        fn_833E9D50();
        return 0;
    }
    if (buffer == 0) {
        *fn_833E9F90() = 22;
        fn_833E9D50();
        return 0;
    }
    if (count > 0xffffffffu / size) {
        *fn_833E9F90() = 22;
        fn_833E9D50();
        return 0;
    }
    data = (const char *)buffer;
    total = size * count;
    left = total;
    if (stream == fn_833F0488() + 1 || stream == fn_833F0488() + 2) {
        while (left != 0) {
            nbytes = left < 0xff ? left : 0xff;
            fn_833E3AD0(tmp, data, nbytes);
            tmp[nbytes] = 0;
            fn_8340F288(tmp);
            left -= nbytes;
        }
        return count;
    }
    if (stream->flag & 0x10c)
        bufsize = stream->bufsiz;
    else
        bufsize = 0x1000;
    while (left != 0) {
        if ((stream->flag & 0x108) && (cnt = stream->cnt) != 0) {
            if (cnt < 0) {
                stream->flag |= 0x20;
                return (total - left) / size;
            }
            nbytes = left < (ts4l_size_t)cnt ? left : (ts4l_size_t)cnt;
            fn_833E3AD0(stream->ptr, data, nbytes);
            stream->ptr += nbytes;
            left -= nbytes;
            stream->cnt -= nbytes;
            data += nbytes;
        } else if (left >= bufsize) {
            if (stream->flag & 0x108) {
                if (fn_833F8280(stream) != 0)
                    return (total - left) / size;
            }
            if (bufsize != 0)
                nbytes = left - left % bufsize;
            else
                nbytes = left;
            written = fn_833F88C0(fn_833F0888(stream), data, nbytes);
            if (written == -1) {
                stream->flag |= 0x20;
                return (total - left) / size;
            }
            {
                ts4l_size_t n = (ts4l_size_t)written > nbytes ? nbytes : (ts4l_size_t)written;
                left -= n;
                data += n;
            }
            if ((ts4l_size_t)written < nbytes) {
                stream->flag |= 0x20;
                return (total - left) / size;
            }
        } else {
            if (fn_833E8F20(*data, stream) == -1)
                return (total - left) / size;
            data++;
            left--;
            {
                int b = stream->bufsiz;
                bufsize = b > 0 ? b : 1;
            }
        }
    }
    return count;
}
