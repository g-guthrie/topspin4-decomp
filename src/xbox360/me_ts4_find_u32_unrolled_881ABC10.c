/* Swing_DLL.xex 0x881ABC10: std::find over u32 (4x unrolled trip loop, then a count switch).
 * Leaf; sibling 88165170 differs only in the tail compare (draft). */
const unsigned int *fn_881ABC10(const unsigned int *first, const unsigned int *last, const unsigned int *val)
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
        if (*first == *val) return first;
        ++first;
    case 2:
        if (*first == *val) return first;
        ++first;
    case 1:
        if (*first == *val) return first;
        ++first;
    case 0:
    default:
        return last;
    }
}
