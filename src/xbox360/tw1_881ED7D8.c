/* Swing_DLL.xex 0x881ED7D8: drop the reference held by each of n 0x18-byte records (handle at +4; twin ts4_str_release_each_881E2DA0 with stride 4, handle at +0) */
typedef unsigned int u32;
#include "fam4_refstr.h"

typedef struct Ts4StrEnt { u32 a; char *h; u32 pad[4]; } Ts4StrEnt;

void ts4_str_release_each_881ED7D8(Ts4StrEnt *p, u32 n)
{
    while (n != 0) {
        Ts4StrEnt *cur = p;
        n--;
        p++;
        ts4_str_release(cur->h);
    }
}
