/* Loader_DLL.xex 0x832A3D18-0x832A3DC8, executable version 0.0.0.3. */
/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Loader_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedIncrement)
#endif

ts4_word fn_83288588();
ts4_word fn_83288C90();
ts4_word fn_83289370();
ts4_word fn_83289A58();
ts4_word fn_832A3C88();

/* Loader_DLL.xex 0x832A3D18: if_get u32@0x80, fn_83288588, u32@0x0, fn_832A3C88, interlocked_inc, u32@0xa4 */
ts4_word ts4l_if_get_u32_off80_832A3D18(ts4_word a0, ts4_word a1)
{
    ts4_word p14;
    ts4_word p15;
    ts4_word p16;
    ts4_word p17;
    ts4_word t2;
    ts4_word t6;
    ts4_word t9;
    ts4_word t12;
    ts4_word t13;
    ts4_word t10;
    ts4_word t7;
    ts4_word t3;

    t2 = fn_83288588((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)));
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((a0 + 796)));
        t6 = fn_83288C90((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 164)));
        *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t6;
        if ((ts4_word)t6 != 0) {
            t9 = fn_83289370((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 160)));
            *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)t9;
            if ((ts4_word)t9 != 0) {
                t12 = fn_83289A58((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 172)));
                *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)t12;
                p14 = (ts4_word)t12;
                if ((ts4_word)t12 == 0) {
                    t13 = fn_832A3C88((ts4_word)a0, (ts4_word)a1);
                    p14 = (ts4_word)t13;
                }
                p15 = (ts4_word)p14;
            } else {
                t10 = fn_832A3C88((ts4_word)a0, (ts4_word)a1);
                p15 = (ts4_word)t10;
            }
            p16 = (ts4_word)p15;
        } else {
            t7 = fn_832A3C88((ts4_word)a0, (ts4_word)a1);
            p16 = (ts4_word)t7;
        }
        p17 = (ts4_word)p16;
    } else {
        t3 = fn_832A3C88((ts4_word)a0, (ts4_word)a1);
        p17 = (ts4_word)t3;
    }
    return p17;
}
