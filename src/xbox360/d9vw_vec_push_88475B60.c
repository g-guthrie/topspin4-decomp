/* Swing_DLL.xex 0x88475B60-0x88475BF4, 0x8847ED38-0x8847EE24, 0x8848C010-0x8848C09C, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif
void fn_8841C678(void *v, int elem_size);
typedef struct Ts4VwEnt { u32 key; u32 pad; u64 val; } Ts4VwEnt;
typedef struct Ts4VwVec { Ts4VwEnt *base; int size; int cap; } Ts4VwVec;
typedef struct Ts4VwOwner { char pad[0x74]; Ts4VwVec vec; } Ts4VwOwner;
void ts4_add_unique_88475B60(Ts4VwOwner *o, u32 key, u64 val)
{
    int i;
    Ts4VwVec *v;
    Ts4VwEnt *e;
    int idx;
    for (i = 0; i < o->vec.size; i++) {
        if (o->vec.base[i].key == key)
            return;
    }
    v = &o->vec;
    if (v->size == (v->cap & 0x3fffffff))
        fn_8841C678(v, 0x10);
    idx = v->size;
    e = v->base + idx;
    v->size = idx + 1;
    e->key = key;
    e->val = val;
}

typedef struct Ts4VwBytes { u8 *base; int size; } Ts4VwBytes;
typedef struct Ts4VwShorts { u16 *base; int size; int cap; } Ts4VwShorts;
void ts4_collect_used_indices_8848C010(Ts4VwBytes *src, Ts4VwShorts *out)
{
    int i;
    for (i = 0; i < src->size; i++) {
        if (src->base[i] != 0xff) {
            u16 idx = (u16)i;
            if (out->size == (out->cap & 0x3fffffff))
                fn_8841C678(out, 2);
            out->base[out->size] = idx;
            out->size++;
        }
    }
}

typedef struct Ts4VwPtrVec { void **base; int size; int cap; } Ts4VwPtrVec;
typedef struct Ts4VwReg8 { char pad[8]; Ts4VwPtrVec vec; } Ts4VwReg8;
typedef struct Ts4VwReg2c { char pad[0x2c]; Ts4VwPtrVec vec; } Ts4VwReg2c;
void ts4_if_get_u16_off4_88475AE8(void *item);
#define TS4_VW_PUSH(v, x) \
    do { \
        if ((v)->size == ((v)->cap & 0x3fffffff)) \
            fn_8841C678((v), 4); \
        (v)->base[(v)->size] = (x); \
        (v)->size++; \
    } while (0)
