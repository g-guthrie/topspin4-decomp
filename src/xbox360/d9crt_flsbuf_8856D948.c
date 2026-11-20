/* Swing_DLL.xex 0x8856D948-0x8856DB1C, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _flsbuf. */
typedef unsigned int u32;
typedef struct Ts4File {
    char *ptr;
    int cnt;
    char *base;
    int flag;
    int file;
    int charbuf;
    int bufsiz;
    int tmpfname;
} Ts4File;
typedef struct IoInfo {
    int osfhnd;
    unsigned char osfile;
    char pad[0x48 - 5];
} IoInfo;
extern IoInfo lbl_88C313B0;
extern IoInfo *lbl_88D4E000[];
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern Ts4File *ts4_addr_lbl_88C30DA8_88567BC8(void);
extern int ts4_if_call_seq_u32_off10_8856C3E0(Ts4File *f);
extern int ts4_runtime_type_code_none(int fh);
extern void ts4_crt_getbuf_885776D8(Ts4File *f);
extern int fn_88568A40(int fh, const void *buf, int count);
extern long long fn_885747D0(int fh, long long off, int whence);

#ifdef _MSC_VER
static __forceinline u32 *set_errno(int v)
#else
static u32 *set_errno(int v)
#endif
{
    u32 *p = ts4_if_call_seq_fn_8856CD88_88567ED8();
    *p = v;
    return p;
}

int ts4_crt_flsbuf_8856D948(int ch, Ts4File *str)
{
    int fh;
    int charcount;
    int written;
    IoInfo *io;

    fh = ts4_if_call_seq_u32_off10_8856C3E0(str);
    if (!(str->flag & 0x82)) {
        set_errno(9);
        str->flag |= 0x20;
        return -1;
    }
    if (str->flag & 0x40) {
        set_errno(34);
        str->flag |= 0x20;
        return -1;
    }
    if (str->flag & 1) {
        str->cnt = 0;
        if (!(str->flag & 0x10)) {
            str->flag |= 0x20;
            return -1;
        }
        str->ptr = str->base;
        str->flag &= ~1;
    }
    written = 0;
    str->cnt = 0;
    str->flag = (str->flag & ~0x10) | 2;
    if (!(str->flag & 0x10c)) {
        if ((str != ts4_addr_lbl_88C30DA8_88567BC8() + 1 && str != ts4_addr_lbl_88C30DA8_88567BC8() + 2) || !ts4_runtime_type_code_none(fh))
            ts4_crt_getbuf_885776D8(str);
    }
    if (str->flag & 0x108) {
        charcount = (int)(str->ptr - str->base);
        str->ptr = str->base + 1;
        str->cnt = str->bufsiz - 1;
        if (charcount > 0) {
            written = fn_88568A40(fh, str->base, charcount);
        } else {
            if (fh == -1 || fh == -2)
                io = &lbl_88C313B0;
            else
                io = lbl_88D4E000[fh >> 5] + (fh & 31);
            if (io->osfile & 0x20) {
                if (fn_885747D0(fh, 0, 2) == -1) {
                    str->flag |= 0x20;
                    return -1;
                }
            }
        }
        *str->base = (char)ch;
    } else {
        charcount = 1;
        written = fn_88568A40(fh, &ch, 1);
    }
    if (written != charcount) {
        str->flag |= 0x20;
        return -1;
    }
    return ch & 0xFF;
}
