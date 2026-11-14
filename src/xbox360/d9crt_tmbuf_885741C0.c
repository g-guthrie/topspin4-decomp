/* Swing_DLL.xex 0x885741C0-0x8857422C, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: per-thread tm buffer accessor (_getptd based). */
typedef unsigned int u32;
typedef struct Ptd {
    u32 pad[0x44 / 4];
    void *tmbuf;
} Ptd;
extern Ptd *fn_8856CD88(void);
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void *ts4_crt_nh_malloc_88565258(u32 size);

void *ts4_crt_tmbuf_885741C0(void)
{
    Ptd *ptd = fn_8856CD88();
    if (ptd == 0) {
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = 12;
        return 0;
    }
    if (ptd->tmbuf == 0 && (ptd->tmbuf = ts4_crt_nh_malloc_88565258(0x24)) == 0) {
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = 12;
        return 0;
    }
    return ptd->tmbuf;
}
