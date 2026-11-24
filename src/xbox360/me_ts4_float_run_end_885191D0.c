/* 0x885191D0: Advances i until i == end or data[i] != data[i+1] and returns it: the end of a run of equal floats in {data, count}. */
/* Matched on /Oc (agAH). The stop test cast to char inside the while condition gives the li/extsb/cmpwi; a char local is 2 off (extsb destination register). */
typedef struct FloatArray { float *data; int count; } FloatArray;
int fn_885191D0(int i, FloatArray *a, int end)
{
    while (!(char)(i == end || a->data[i] != a->data[i + 1]))
        i++;
    return i;
}
