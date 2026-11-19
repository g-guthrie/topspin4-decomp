/* 0x88405558: Returns the index of value in the short list of count entries, checking list[value] first as a fast path; returns -1 if absent. */
/* Matched on /Oc (agAH). Index kept as short (extsh after each increment). */
short fn_88405558(short value, short count, const short *list)
{
    short i;
    if (value < count && list[value] == value)
        return value;
    for (i = 0; i < count; i++) {
        if (list[i] == value)
            return i;
    }
    return -1;
}
