/* Swing_DLL.xex 0x88518AC0 / 0x88518B08: remove-at helpers for {data, count} arrays
 * (same object, auto_03_88518978_text.obj; neither has a direct caller in the image).
 *
 * 0x88518B08 takes (index, array, end): removes element `index`, then decrements the
 * entries [index, end). 0x88518AC0 is its float twin and keeps the same three-argument
 * shape; the third argument is unused there. Evidence: with two parameters the address
 * add comes out `add r9,r10(offset),r9(data)`; any third parameter gives the target's
 * `add r9,r9(data),r10(offset)` (parameter count changes commutative operand order,
 * see regalloc.md C1). Matched /Oc. */
typedef struct Ts4FloatArray { float *data; int count; } Ts4FloatArray;
typedef struct Ts4IntArray { int *data; int count; } Ts4IntArray;

void ts4_float_array_remove_at_88518AC0(int index, Ts4FloatArray *a, int end)
{
    int i;
    (void)end;
    a->count--;
    for (i = index; i < a->count; i++)
        a->data[i] = a->data[i + 1];
}

void ts4_int_array_remove_at_shift_88518B08(int index, Ts4IntArray *a, int end)
{
    int i;
    a->count--;
    for (i = index; i < a->count; i++)
        a->data[i] = a->data[i + 1];
    for (i = index; i < end; i++)
        a->data[i]--;
}
