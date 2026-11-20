/* Swing_DLL.xex 0x88446228-0x884462AC, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4VwPacked { u32 v : 24; u32 f : 8; } Ts4VwPacked;
typedef struct Ts4VwPackedVec { Ts4VwPacked *base; int size; int cap; } Ts4VwPackedVec;
typedef struct Ts4VwBag { char pad[4]; Ts4VwPackedVec vec; } Ts4VwBag;
void fn_8841C678(Ts4VwPackedVec *v, int elem_size);
void ts4_push_packed_88446228(Ts4VwBag *b, u32 value)
{
    Ts4VwPackedVec *v = &b->vec;
    Ts4VwPacked *p;
    int idx;
    if (v->size == (v->cap & 0x3fffffff))
        fn_8841C678(v, 4);
    idx = v->size;
    p = v->base + idx;
    v->size = idx + 1;
    p->f = 0;
    p->v = value;
}
