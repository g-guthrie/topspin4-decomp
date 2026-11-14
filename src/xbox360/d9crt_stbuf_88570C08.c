/* Swing_DLL.xex 0x88570C08-0x88570CF4, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _stbuf. */
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
extern int lbl_88D2E540;
extern void *lbl_88D2E744[2];
extern int ts4_if_call_seq_u32_off10_8856C3E0(Ts4File *f);
extern int ts4_runtime_type_code_none(int fh);
extern Ts4File *ts4_addr_lbl_88C30DA8_88567BC8(void);
extern void *ts4_crt_nh_malloc_88565258(u32 size);

int ts4_crt_stbuf_88570C08(Ts4File *str)
{
    int index;
    if (!ts4_runtime_type_code_none(ts4_if_call_seq_u32_off10_8856C3E0(str)))
        return 0;
    if (str == ts4_addr_lbl_88C30DA8_88567BC8() + 1)
        index = 0;
    else if (str == ts4_addr_lbl_88C30DA8_88567BC8() + 2)
        index = 1;
    else
        return 0;
    ++lbl_88D2E540;
    if (str->flag & 0x10C)
        return 0;
    if (lbl_88D2E744[index] == 0 && (lbl_88D2E744[index] = ts4_crt_nh_malloc_88565258(0x1000)) == 0) {
        str->ptr = str->base = (char *)&str->charbuf;
        str->cnt = str->bufsiz = 2;
    } else {
        str->ptr = str->base = (char *)lbl_88D2E744[index];
        str->cnt = str->bufsiz = 0x1000;
    }
    str->flag |= 0x1102;
    return 1;
}
