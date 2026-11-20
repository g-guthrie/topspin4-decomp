/* Swing_DLL.xex 0x8849F7B0-0x8849F848, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef struct Ts4VwByteVec { u8 *base; int size; int cap; } Ts4VwByteVec;
void fn_8841C678(Ts4VwByteVec *v, int elem_size);
int ts4_alloc_slot_8849F7B0(Ts4VwByteVec *v, int value)
{
    int i;
    int n = v->size;
    u8 b;
    for (i = n - 1; i >= 0; i--) {
        if (v->base[i] == 0xff) {
            v->base[i] = value;
            return i;
        }
    }
    b = (u8)value;
    if (n == (v->cap & 0x3fffffff))
        fn_8841C678(v, 1);
    v->base[v->size] = b;
    v->size++;
    return v->size - 1;
}
