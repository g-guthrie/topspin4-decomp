/* Swing_DLL.xex 0x883FAFA0-0x883FB008, 0x883FB158-0x883FB18C, executable version 0.0.0.3. */
typedef struct Ts4Ob2Ent { unsigned int id; unsigned int val; } Ts4Ob2Ent;
typedef struct Ts4Ob2Pool { char pad0[8]; unsigned int cap; unsigned int count; unsigned int serial; Ts4Ob2Ent *arr; } Ts4Ob2Pool;

#ifdef _MSC_VER
__declspec(noinline)
#endif
int ts4_pool_push_883FAFA0(Ts4Ob2Pool *o, unsigned int v)
{
    if (o->count < o->cap) {
        o->arr[o->count].val = v;
        o->arr[o->count].id = o->serial;
        o->count++;
        o->serial++;
        return o->arr[o->count - 1].id;
    }
    return 0;
}

int ts4_pool_push_883FB158(char *o, unsigned int v, int *out)
{
    int r = ts4_pool_push_883FAFA0((Ts4Ob2Pool *)(o + 8), v);
    if (out != 0)
        *out = r;
    return 0;
}
