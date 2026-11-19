/* 0x885E3B70: Removes element index from a pointer array {?, count (+4), data (+8)}: when index < count, decrements count and shifts the tail down one slot with memcpy. */
/* Matched on /Oc (agAH). data pointer read into a local after the count decrement (reading a->data twice in the call swaps r9/r10). */
void *memcpy(void *dst, const void *src, unsigned int n);
typedef struct PtrArray { int unk0; unsigned int count; void **data; } PtrArray;
void fn_885E3B70(PtrArray *a, unsigned int index)
{
    if (index < a->count) {
        void **data;
        a->count--;
        data = a->data;
        memcpy(&data[index], &data[index + 1], (a->count - index) * sizeof(void *));
    }
}
