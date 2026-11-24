/* nearmiss: 3 off (plain /Oc); cmplw operand order in the unrolled switch cases differs; blocker: perm_auto run (700s) found nothing below baseline 3; needs a compare-operand-order probe. */
#include "include/ts4/ts4.h"
const unsigned int *ts4_find_u32_88165170(const unsigned int *first, const unsigned int *last, const unsigned int *val)
{
    int trip = (last - first) >> 2;
    for (; trip > 0; --trip) {
        if (*first == *val) return first;
        ++first;
        if (*first == *val) return first;
        ++first;
        if (*first == *val) return first;
        ++first;
        if (*first == *val) return first;
        ++first;
    }
    switch (last - first) {
    case 3:
        if (*val == *first) return first;
        ++first;
    case 2:
        if (*val == *first) return first;
        ++first;
    case 1:
        if (*val == *first) return first;
    case 0:
    default:
        return last;
    }
}
