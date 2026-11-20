/* Near-miss for Swing_DLL.xex 0x88165170 (u32 find, 4x unrolled, /Oc): 3 off.
 * Head loop matches. In the count switch the target loads *val then *first and does cmplw first,val;
 * writing *val == *first gets the loads right but swaps the cmplw operands, *first == *val swaps the loads. */
const unsigned int *fn_88165170(const unsigned int *first, const unsigned int *last, const unsigned int *val)
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
        ++first;
    case 0:
    default:
        return last;
    }
}
