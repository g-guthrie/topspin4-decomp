#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif
typedef struct T { unsigned char b0, b1; char pad[2]; float scale; u64 pos; char pad2[0x10]; void *data; unsigned int f24; } T;
extern unsigned int lbl_88039744, lbl_88039748, lbl_8803974C;
unsigned int fn_883E6978(unsigned char a, unsigned int dflt, unsigned int k, u64 pos, unsigned int z, void *data, struct T *t, unsigned int f24, unsigned int z2, float scale);
unsigned int fn_883FBC58(T *t, unsigned int dflt, unsigned int sel)
{
    unsigned int k;
    if (!t->data || !t->b1 || !t->b0)
        return dflt;
    switch (sel) {
    case 0: k = lbl_8803974C; break;
    case 1: k = lbl_88039748; break;
    case 2: k = lbl_88039744; break;
    default: k = 0; break;
    }
    return fn_883E6978(1, dflt, k, t->pos, 0, t->data, t, t->f24, 0, t->scale);
}
