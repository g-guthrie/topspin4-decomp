/* Engine core (eng): timestamp helpers. LTCG route, /Oc, context src/xbox360/pp1_pool_primer.c. */
typedef unsigned int u32;
typedef unsigned long long u64;
extern u32 ts4_get_u32__imp_KeTimeStampBundle_8857B830(void);
/* Swing_DLL.xex 0x882783F0: ticks elapsed since `start` on the 32-bit timestamp counter, allowing one wrap. */
u64 ts4_ticks_since_882783F0(u64 start)
{
    u64 now = ts4_get_u32__imp_KeTimeStampBundle_8857B830();
    if (now < start)
        return now - start + 0xffffffffu;
    return now - start;
}
