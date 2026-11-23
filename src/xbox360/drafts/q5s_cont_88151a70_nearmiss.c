/* nearmiss: 19 off (plain /Oc) after perm_auto (best 19); loop base should be this+0x3c and the stb goes via r10+4; blocker: missing type for the 0x88151A70 block object (field layout behind +0x3c not known). */
#include "include/ts4/ts4.h"
#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
#else
#include <string.h>
#endif
typedef struct Blk {
    unsigned int w[9];          /* +0x00 */
    int f24;                    /* +0x24 */
    int f28;                    /* +0x28 */
    int f2c;
    unsigned long long f30;     /* +0x30 */
    unsigned int f38;
    unsigned int f3c;
    unsigned int slots[8];      /* +0x40 */
    unsigned char f60;
    unsigned char buf[0x80];    /* +0x61 */
} Blk;
Blk *ts4_blk_init_88151A70(Blk *b)
{
    int i;
    b->w[0] = 0; b->w[1] = 0; b->w[2] = 0; b->w[3] = 0; b->w[4] = 0;
    b->w[5] = 0; b->w[6] = 0; b->w[7] = 0; b->w[8] = 0;
    b->f38 = 0;
    b->f3c = 0;
    b->f30 = 0;
    b->f24 = 2;
    b->f28 = 1;
    for (i = 0; i < 8; i++)
        b->slots[i] = 0;
    b->f60 = 0;
    memset(b->buf, 0, sizeof(b->buf));
    return b;
}
