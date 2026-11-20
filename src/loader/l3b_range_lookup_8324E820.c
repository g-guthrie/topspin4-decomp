/* Loader_DLL.xex 0x8324E820-0x83250280, executable version 0.0.0.3.
 * Range lookup: find the list node whose [base, base+size) holds a 64-bit key. */

#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
typedef struct Rg { int pad; unsigned size; ts4l_u64 base; } Rg;
typedef struct Nd { Rg *rng; int pad; struct Nd *next; } Nd;
typedef struct { char pad[0x8]; Nd *head; } Lst;
typedef struct { char pad[0x10]; Lst *lst; } In;
typedef struct { char pad[0x2c]; In *in; } Obj;
int ts4l_find_range_node_8324E820(Obj *o, ts4l_u64 key, Nd **found, int *flag)
{
    Nd *n;
    *flag = 0;
    *found = 0;
    for (n = o->in->lst->head; n != 0; n = n->next) {
        ts4l_u64 base = n->rng->base;
        if (!(base > key)) {
            ts4l_u64 end = base + n->rng->size;
            if (key < end) {
                *flag = 1;
                *found = n;
                return 0;
            }
            if (base < key)
                return 0;
        }
    }
    return 0;
}

int ts4l_find_range_node_83250280(Obj *o, ts4l_u64 key, Nd **found, int *flag)
{
    Nd *n;
    *flag = 0;
    *found = 0;
    for (n = o->in->lst->head; n != 0; n = n->next) {
        ts4l_u64 base = n->rng->base;
        if (!(base > key)) {
            ts4l_u64 end = base + n->rng->size;
            if (key < end) {
                *flag = 1;
                *found = n;
                return 0;
            }
            if (base < key)
                return 0;
        }
    }
    return 0;
}
