/* Loader_DLL.xex 0x833E43D8-0x833E4494, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _vswscanf_helper. */
typedef unsigned long ts4l_u32;
extern ts4l_u32 *ts4_if_call_seq_fn_833E8350_833E9F90(void);
extern void fn_833E9D50(ts4l_u32 *e);
extern ts4l_u32 ts4_loop_get_u16_off0_833E1C00(const unsigned short *s);

typedef struct Ts4lFile {
    char *ptr;
    int cnt;
    char *base;
    int flag;
    int file;
    int charbuf;
    int bufsiz;
    char *tmpfname;
} Ts4lFile;

int ts4l_crt_vswscanf_helper_833E43D8(int (*inputfn)(Ts4lFile *, const unsigned short *, void *, void *),
                                      const unsigned short *string, const unsigned short *format,
                                      void *plocinfo, void *arglist)
{
    Ts4lFile str = {0};
    Ts4lFile *infile = &str;
    ts4l_u32 count = ts4_loop_get_u16_off0_833E1C00(string);
    ts4l_u32 *e;
    int ok;

    ok = !!(string != 0);
    if (!ok) {
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return -1;
    }
    ok = !!(format != 0);
    if (!ok) {
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return -1;
    }
    infile->flag = 0x49;
    infile->ptr = infile->base = (char *)string;
    if (count > 0x3fffffff)
        infile->cnt = 0x7fffffff;
    else
        infile->cnt = (int)(count * 2);
    return inputfn(infile, format, plocinfo, arglist);
}
