/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l8_crt_fwrite_nolock_833E7AE0.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Library routine: CRT _fwrite_nolock (stdout/stderr go to the debug output). */

typedef unsigned int ts4_size_t;

typedef struct ts4_file {
    char *ptr;
    int cnt;
    char *base;
    int flag;
    int file;
    int charbuf;
    int bufsiz;
    char *tmpfname;
} ts4_file;

extern char lbl_8352C3D0[];

ts4_file *ts4_addr_lbl_88C30DA8_88567BC8(void);
int *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
void fn_8856D2C0(void);
#ifdef _MSC_VER
void *memcpy(void *dst, const void *src, ts4_size_t n);
#else
#include <string.h>
#endif
int fn_88566B48(ts4_file *stream);
int ts4_if_call_seq_u32_off10_8856C3E0(ts4_file *stream);
int fn_88568A40(int fd, const void *buf, ts4_size_t n);
int fn_8856D948(int c, ts4_file *stream);
void ts4_call_seq_RtlInitAnsiString_88582148(const char *s);

/* Swing_DLL.xex 0x88565CE0 */
ts4_size_t ts4_fwrite_nolock_88565CE0(const void *buffer, ts4_size_t size,
                                        ts4_size_t count, ts4_file *stream)
{
    const char *data;
    ts4_size_t total;
    ts4_size_t left;
    ts4_size_t bufsize;
    ts4_size_t nbytes;
    int written;
    int cnt;
    char tmp[256];

    if (size == 0 || count == 0)
        return 0;
    if (stream == 0) {
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = 22;
        fn_8856D2C0();
        return 0;
    }
    if (buffer == 0) {
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = 22;
        fn_8856D2C0();
        return 0;
    }
    if (count > 0xffffffffu / size) {
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = 22;
        fn_8856D2C0();
        return 0;
    }
    data = (const char *)buffer;
    total = size * count;
    left = total;
    if (stream == ts4_addr_lbl_88C30DA8_88567BC8() + 1 || stream == ts4_addr_lbl_88C30DA8_88567BC8() + 2) {
        while (left != 0) {
            nbytes = left < 0xff ? left : 0xff;
            memcpy(tmp, data, nbytes);
            tmp[nbytes] = 0;
            ts4_call_seq_RtlInitAnsiString_88582148(tmp);
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
            nbytes = left < (ts4_size_t)cnt ? left : (ts4_size_t)cnt;
            memcpy(stream->ptr, data, nbytes);
            stream->ptr += nbytes;
            left -= nbytes;
            stream->cnt -= nbytes;
            data += nbytes;
        } else if (left >= bufsize) {
            if (stream->flag & 0x108) {
                if (fn_88566B48(stream) != 0)
                    return (total - left) / size;
            }
            if (bufsize != 0)
                nbytes = left - left % bufsize;
            else
                nbytes = left;
            written = fn_88568A40(ts4_if_call_seq_u32_off10_8856C3E0(stream), data, nbytes);
            if (written == -1) {
                stream->flag |= 0x20;
                return (total - left) / size;
            }
            {
                ts4_size_t n = (ts4_size_t)written > nbytes ? nbytes : (ts4_size_t)written;
                left -= n;
                data += n;
            }
            if ((ts4_size_t)written < nbytes) {
                stream->flag |= 0x20;
                return (total - left) / size;
            }
        } else {
            if (fn_8856D948(*data, stream) == -1)
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

