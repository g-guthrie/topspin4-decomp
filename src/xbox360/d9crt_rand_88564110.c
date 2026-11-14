/* Swing_DLL.xex 0x88564110-0x88564150, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: rand. */
typedef unsigned int u32;
typedef struct Ptd {
    u32 pad[5];
    u32 holdrand;
} Ptd;
extern Ptd *ts4_if_call_seq_fn_8856CD88_8856CE60(void);

int ts4_crt_rand_88564110(void)
{
    Ptd *ptd = ts4_if_call_seq_fn_8856CD88_8856CE60();
    return ((ptd->holdrand = ptd->holdrand * 214013 + 2531011) >> 16) & 0x7FFF;
}
