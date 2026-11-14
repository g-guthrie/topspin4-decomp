/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l3b_stereo_pair_831C2BE8.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
#ifdef _MSC_VER
#define TS4_INLINE static __forceinline
#else
#define TS4_INLINE static inline
#endif

typedef struct { char pad[0x8c]; int x8c; int x90; int x94; int x98; int x9c; } Ts4lStereoCfg;

TS4_INLINE void ts4_average_pair(short *p, short *q)
{
    short m = (short)((*p + *q) / 2);
    *p = m;
    *q = m;
}

/* Swing_DLL.xex 0x885C4970 */
void ts4_stereo_split_offset_885C4970(Ts4lStereoCfg *o, int mode, short a, short b, int off, short *p, short *q)
{
    if (b >= a) {
        *p = off;
        *q = (short)(off * 2);
    } else {
        *p = (short)((a - b) / 2 + off);
        *q = (short)((a + b) / 2 + off);
    }
    if (mode == 1) {
        if (o->x8c == 1 && o->x9c == 0)
            ts4_average_pair(p, q);
    } else {
        if (o->x8c == 1 && o->x94 == 0)
            ts4_average_pair(p, q);
    }
}

