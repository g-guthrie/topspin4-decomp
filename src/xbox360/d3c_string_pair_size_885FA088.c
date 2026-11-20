/* Swing_DLL.xex 0x885FA088-0x885FAC38, executable version 0.0.0.3. */
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif

typedef struct Ts4StrPairA {
    int a, b, c, d;
    const char *first;
    const char *second;
} Ts4StrPairA;

typedef struct Ts4StrPairB {
    int a, b, c;
    const char *first;
    const char *second;
} Ts4StrPairB;

/* Storage size of an optional string including its two byte overhead. */
static unsigned int ts4_str_storage_size(const char *s)
{
    return s ? (strlen(s) & ~0u) + 2 : 2;
}

/* Serialized size of a record holding two optional strings (strings at +0x10/+0x14). */
unsigned int ts4_str_pair_a_size_885FA088(Ts4StrPairA *p)
{
    unsigned int n1 = ts4_str_storage_size(p->first);
    return ts4_str_storage_size(p->second) + n1 + 0xc;
}

/* Same, strings at +0xc/+0x10. */
unsigned int ts4_str_pair_b_size_885FABB0(Ts4StrPairB *p)
{
    unsigned int n1 = ts4_str_storage_size(p->first);
    return ts4_str_storage_size(p->second) + n1 + 0xc;
}
