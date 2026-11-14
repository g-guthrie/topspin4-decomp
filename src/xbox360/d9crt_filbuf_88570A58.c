/* Swing_DLL.xex 0x88570A58-0x88570C04, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _filbuf. */
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
    char osfile;
    char pad[0x48 - 5];
} IoInfo;
extern IoInfo lbl_88C313B0;
extern IoInfo *lbl_88D4E000[];
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);
extern void ts4_crt_getbuf_885776D8(Ts4File *f);
extern int ts4_if_call_seq_u32_off10_8856C3E0(Ts4File *f);
extern int fn_88568650(int fh, char *buf, u32 count);

int ts4_crt_filbuf_88570A58(Ts4File *str)
{
    u32 *e;
    int fh;
    IoInfo *io;
    if (str == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return -1;
    }
    if (!(str->flag & 0x83) || (str->flag & 0x40))
        return -1;
    if (str->flag & 2) {
        str->flag |= 0x20;
        return -1;
    }
    str->flag |= 1;
    if (!(str->flag & 0x10C))
        ts4_crt_getbuf_885776D8(str);
    else
        str->ptr = str->base;
    str->cnt = fn_88568650(ts4_if_call_seq_u32_off10_8856C3E0(str), str->base, str->bufsiz);
    if (str->cnt == 0 || str->cnt == -1) {
        str->flag |= str->cnt ? 0x20 : 0x10;
        str->cnt = 0;
        return -1;
    }
    if (!(str->flag & 0x82)) {
        fh = ts4_if_call_seq_u32_off10_8856C3E0(str);
        if (fh == -1 || ts4_if_call_seq_u32_off10_8856C3E0(str) == -2)
            io = &lbl_88C313B0;
        else
            io = lbl_88D4E000[ts4_if_call_seq_u32_off10_8856C3E0(str) >> 5] + (ts4_if_call_seq_u32_off10_8856C3E0(str) & 31);
        if ((io->osfile & 0x82) == 0x82)
            str->flag |= 0x2000;
    }
    if (str->bufsiz == 0x200 && (str->flag & 8) && !(str->flag & 0x400))
        str->bufsiz = 0x1000;
    str->cnt--;
    return 0xFF & *str->ptr++;
}
