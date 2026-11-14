/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l1b_v_o1_830AAC58.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

extern char __imp_KeDebugMonitorData[];
extern char fn_830DC2C0[];
extern char fn_830DCFE8[];
extern char fn_830DD088[];
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif

ts4_word ts4_call_seq_u32_off10_884F3428();
ts4_word fn_884F3458();

/* Swing_DLL.xex 0x884F2050 */
void ts4_if_call_seq_fn_830FCCD0_884F2050(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[4];
    int t1;
    unsigned char t2;

    loc50[0] = (ts4_word)2;
    t1 = fn_884F3458((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 >= 0) {
        t2 = *(unsigned char *)((char *)(ts4_word)(a1) + 0);
        if ((int)(t2 & 0x40) != 0) {
            ts4_call_seq_u32_off10_884F3428((ts4_word)a0, (ts4_word)a2);
        }
    }
    return;
}

