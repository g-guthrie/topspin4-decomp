/* Swing_DLL.xex 0x884B7AE0-0x884B7B8C, 0x884BA0C0-0x884BA16C, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4VwKv { u32 a; u32 b; } Ts4VwKv;
typedef struct Ts4VwKvVec { Ts4VwKv *base; int size; int cap; } Ts4VwKvVec;
typedef struct Ts4VwKvOwner { char pad[8]; Ts4VwKvVec vec; } Ts4VwKvOwner;
void fn_8841C678(Ts4VwKvVec *v, int elem_size);
void ts4_add_kv_884B7AE0(Ts4VwKvOwner *o, u32 a, int b)
{
    Ts4VwKv kv;
    Ts4VwKvVec *v;
    int i;
    int n = o->vec.size;
    for (i = 0; i < n; i++) {
        if ((int)o->vec.base[i].b == b)
            return;
    }
    kv.a = a;
    kv.b = b;
    v = &o->vec;
    if (v->size == (v->cap & 0x3fffffff))
        fn_8841C678(v, 8);
    v->base[v->size] = kv;
    v->size++;
}

void ts4_add_kv_884BA0C0(Ts4VwKvOwner *o, u32 a, int b)
{
    Ts4VwKv kv;
    Ts4VwKvVec *v;
    int i;
    int n = o->vec.size;
    for (i = 0; i < n; i++) {
        if ((int)o->vec.base[i].b == b)
            return;
    }
    kv.a = a;
    kv.b = b;
    v = &o->vec;
    if (v->size == (v->cap & 0x3fffffff))
        fn_8841C678(v, 8);
    v->base[v->size] = kv;
    v->size++;
}
