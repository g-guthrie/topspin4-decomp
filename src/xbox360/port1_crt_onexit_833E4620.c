/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l33_crt_onexit_833E4620.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Statically linked MSVC CRT: onexit table (_onexit body and __onexitinit). */
typedef unsigned long ts4_u32;
typedef void (*Ts4lPvfv)(void);

extern Ts4lPvfv *lbl_88D4E10C; /* __onexitend */
extern Ts4lPvfv *lbl_88D4E110; /* __onexitbegin */
extern ts4_u32 fn_833F5008(void *p);
extern void *fn_8856C298(ts4_u32 num, ts4_u32 size);

/* Swing_DLL.xex 0x88563308 */
int ts4_crt_onexitinit_88563308(void)
{
    Ts4lPvfv *p;

    p = (Ts4lPvfv *)fn_8856C298(32, sizeof(Ts4lPvfv));
    lbl_88D4E110 = p;
    lbl_88D4E10C = p;
    if (p == 0)
        return 24;
    *p = 0;
    return 0;
}

