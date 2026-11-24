/* Swing_DLL.xex 0x884A2C90-0x884A2D40, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4VwWordVec { u32 *base; int size; int cap; } Ts4VwWordVec;
typedef struct Ts4VwHolder { char pad[0x78]; Ts4VwWordVec vec; } Ts4VwHolder;
void fn_8841C678(Ts4VwWordVec *v, int elem_size);
static int ts4_find_word(Ts4VwWordVec *v, u32 key)
{
    int n = v->size;
    int i;
    u32 *p;
    for (i = 0; i < n; i++) {
        p = v->base + i;
        if (*p == key)
            return i;
    }

    return -1;
}
void ts4_add_word_884A2C90(Ts4VwHolder *h, u32 key)
{
    Ts4VwWordVec *v = &h->vec;
    if (ts4_find_word(v, key) < 0) {
        v = &h->vec;

        if (v->size == (v->cap & 0x3fffffff))
            fn_8841C678(v, 4);
        v->base[v->size] = key;
        v->size++;
    }
}
