/* Loader_DLL.xex 0x833E4620-0x833E473C, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: onexit table (_onexit body and __onexitinit). */
typedef unsigned long ts4l_u32;
typedef void (*Ts4lPvfv)(void);
extern Ts4lPvfv *lbl_8354BA8C; /* __onexitend */
extern Ts4lPvfv *lbl_8354BA90; /* __onexitbegin */
extern ts4l_u32 fn_833F5008(void *p);
extern void *fn_833F4F18(void *p, ts4l_u32 size);
extern void *fn_833F5060(ts4l_u32 num, ts4l_u32 size);

Ts4lPvfv ts4l_crt_onexit_833E4620(Ts4lPvfv func)
{
    Ts4lPvfv *end = lbl_8354BA8C;
    Ts4lPvfv *begin = lbl_8354BA90;
    ts4l_u32 len, need, oldsize, newsize;
    Ts4lPvfv *p;

    if (end >= begin) {
        len = (ts4l_u32)((char *)end - (char *)begin);
        need = len + sizeof(Ts4lPvfv);
        if (need >= sizeof(Ts4lPvfv)) {
            oldsize = fn_833F5008(begin);
            if (oldsize >= need)
                goto store;
            newsize = oldsize + (oldsize < 0x800 ? oldsize : 0x800);
            p = 0;
            if (newsize >= oldsize)
                p = (Ts4lPvfv *)fn_833F4F18(begin, newsize);
            if (p == 0) {
                newsize = oldsize + 16;
                if (newsize >= oldsize) {
                    p = (Ts4lPvfv *)fn_833F4F18(begin, newsize);
                    if (p != 0)
                        goto grown;
                }
                return 0;
            }
grown:
            lbl_8354BA90 = p;
            end = p + ((long)len >> 2);
store:
            *end = func;
            lbl_8354BA8C = end + 1;
            return func;
        }
    }
    return 0;
}

int ts4l_crt_onexitinit_833E46E8(void)
{
    Ts4lPvfv *p;

    p = (Ts4lPvfv *)fn_833F5060(32, sizeof(Ts4lPvfv));
    lbl_8354BA90 = p;
    lbl_8354BA8C = p;
    if (p == 0)
        return 24;
    *p = 0;
    return 0;
}
