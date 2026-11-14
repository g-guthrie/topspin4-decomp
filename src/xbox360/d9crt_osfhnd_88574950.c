/* Swing_DLL.xex 0x88574950-0x88574B24, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _set_osfhnd, _free_osfhnd, _get_osfhandle. */
typedef unsigned int u32;
typedef struct IoInfo {
    int osfhnd;
    unsigned char osfile;
    char pad[0x48 - 5];
} IoInfo;
extern u32 lbl_88D4DFE4;
extern IoInfo *lbl_88D4E000[];
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern u32 *ts4_if_call_seq_fn_8856CD88_88567F10(void);
extern void fn_8856D2C0(void);

#define PIOINFO(i) (lbl_88D4E000[(i) >> 5] + ((i) & 31))

int ts4_crt_set_osfhnd_88574950(int fh, int value)
{
    u32 *e;
    u32 *d;
    if (fh >= 0 && (u32)fh < lbl_88D4DFE4 && PIOINFO(fh)->osfhnd == -1) {
        PIOINFO(fh)->osfhnd = value;
        return 0;
    }
    e = ts4_if_call_seq_fn_8856CD88_88567ED8();
    *e = 9;
    d = ts4_if_call_seq_fn_8856CD88_88567F10();
    *d = 0;
    return -1;
}

int ts4_crt_free_osfhnd_885749D8(int fh)
{
    u32 *e;
    u32 *d;
    if (fh >= 0 && (u32)fh < lbl_88D4DFE4 && (PIOINFO(fh)->osfile & 1) && PIOINFO(fh)->osfhnd != -1) {
        PIOINFO(fh)->osfhnd = -1;
        return 0;
    }
    e = ts4_if_call_seq_fn_8856CD88_88567ED8();
    *e = 9;
    d = ts4_if_call_seq_fn_8856CD88_88567F10();
    *d = 0;
    return -1;
}

int ts4_crt_get_osfhandle_88574A70(int fh)
{
    u32 *e;
    u32 *d;
    if (fh == -2) {
        d = ts4_if_call_seq_fn_8856CD88_88567F10();
        *d = 0;
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 9;
        return -1;
    }
    {
        int ok = !!(fh >= 0 && (u32)fh < lbl_88D4DFE4);
        if (!ok) {
            d = ts4_if_call_seq_fn_8856CD88_88567F10();
            *d = 0;
            e = ts4_if_call_seq_fn_8856CD88_88567ED8();
            *e = 9;
            fn_8856D2C0();
            return -1;
        }
    }
    {
        int ok = !!(PIOINFO(fh)->osfile & 1);
        if (!ok) {
            d = ts4_if_call_seq_fn_8856CD88_88567F10();
            *d = 0;
            e = ts4_if_call_seq_fn_8856CD88_88567ED8();
            *e = 9;
            fn_8856D2C0();
            return -1;
        }
    }
    return PIOINFO(fh)->osfhnd;
}
