/* Twin of 0x881E2DA0 (ts4_str_release_each_881E2DA0 in src/xbox360/cw8_core_c.c). Slots are 8 bytes. */
#include "fam4_refstr.h"
typedef unsigned int u32;
typedef struct Cw8StrSlot { char *s; u32 pad; } Cw8StrSlot;

void ts4_str_release_each_8820ADD8(Cw8StrSlot *p, u32 n)
{
    while (n != 0) {
        Cw8StrSlot *cur = p;
        n--;
        p++;
        ts4_str_release(cur->s);
    }
}
