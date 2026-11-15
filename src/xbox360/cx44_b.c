/* CX44 part b: functions with a divide (need /Oc), Pam Display renderer 0x886E8000-0x88700000. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX44_INL static __forceinline
#pragma intrinsic(memcmp)
extern int memcmp(const void *, const void *, unsigned int);
#else
#include <string.h>
#define CX44_INL static inline
#endif

typedef struct Cx44Vec { char *first; char *last; } Cx44Vec;

/* 0x886ED758: wrap index a (1-based) into the ring of 0x8c-byte records, -1 when the list is off */
int ts4_wrap_index_886ED758(char *s, int a)
{
    if (*(u8 *)(s + 0x1c) != 0) {
        int n = (*(int *)(s + 0x40) - *(int *)(s + 0x3c)) / 0x8c - 1;
        return (a - 1) % n + 1;
    }
    return -1;
}

/* 0x886EDC28: two vectors of 12-byte records are equal */
u8 ts4_rec12_vec_equal_886EDC28(Cx44Vec *a, Cx44Vec *b)
{
    char *bf = b->first;
    char *al = a->last;
    char *bl = b->last;
    char *af = a->first;
    int na = (al - af) / 12;
    int nb = (bl - bf) / 12;
    if (na != nb) return 0;
    return memcmp(af, bf, na * 12) == 0;
}
