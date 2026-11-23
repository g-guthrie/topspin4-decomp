/* q5s_cont: 16-byte key equality (LTCG route, /Oc). Type: Ts4Key16 in include/ts4/containers.h. */
#include "include/ts4/ts4.h"

#ifdef _MSC_VER
extern int memcmp(const void *, const void *, unsigned int);
#pragma intrinsic(memcmp)
#else
#include <string.h>
#endif

/* size == 0 on both: pointer identity; both sized: equal sizes and equal 16 inline bytes. */
unsigned char ts4_key16_equal_8818A210(const Ts4Key16 *a, const Ts4Key16 *b)
{
    if (a->size == 0) {
        if (b->size == 0)
            return a->u.ptr == b->u.ptr;
    } else if (b->size != 0 && a->size == b->size && memcmp(a->u.bytes, b->u.bytes, 16) == 0) {
        return 1;
    }
    return 0;
}
