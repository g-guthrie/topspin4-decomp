/* 0x88518AC0: Removes element index from a float array {data, count}: decrements count, then shifts data[index+1..count] down one slot. */
/* Near miss (agAH): 1 off: target add r9,r9(data),r10(offset); every index form tried (a[i], i[a], pointer + offset, byte offsets either side, a while loop) gives add r9,r10,r9. */
typedef struct FloatArray { float *data; int count; } FloatArray;
void fn_88518AC0(int index, FloatArray *a)
{
    int i;
    a->count--;
    for (i = index; i < a->count; i++)
        a->data[i] = a->data[i + 1];
}
