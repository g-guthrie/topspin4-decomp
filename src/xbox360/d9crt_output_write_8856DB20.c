/* Swing_DLL.xex 0x8856DB20-0x8856DC84, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: printf engine write_char and write_string. */
typedef unsigned int u32;
typedef struct Ts4File {
    char *ptr;
    int cnt;
    char *base;
    u32 flag;
    u32 file;
    u32 charbuf;
    int bufsiz;
} Ts4File;
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern int fn_8856D948(int ch, Ts4File *f);

#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_crt_write_char_8856DB20(char ch, Ts4File *f, int *pnum)
{
    int r;
    if (!(f->flag & 0x40) || f->base != 0) {
        if (--f->cnt >= 0)
            r = (unsigned char)(*f->ptr++ = ch);
        else
            r = fn_8856D948((int)ch, f);
        if (r == -1) {
            *pnum = -1;
            return;
        }
    }
    ++*pnum;
}

void ts4_crt_write_string_8856DBB8(const char *string, int len, Ts4File *f, int *pnum)
{
    int save_errno = *(int *)ts4_if_call_seq_fn_8856CD88_88567ED8();
    if ((f->flag & 0x40) && f->base == 0) {
        *pnum += len;
        return;
    }
    *ts4_if_call_seq_fn_8856CD88_88567ED8() = 0;
    while (len-- > 0) {
        ts4_crt_write_char_8856DB20(*string++, f, pnum);
        if (*pnum == -1) {
            if (*(int *)ts4_if_call_seq_fn_8856CD88_88567ED8() == 42)
                ts4_crt_write_char_8856DB20('?', f, pnum);
            else
                break;
        }
    }
    if (*(int *)ts4_if_call_seq_fn_8856CD88_88567ED8() == 0)
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = save_errno;
}
