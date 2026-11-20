/* Swing_DLL.xex 0x8831D7E0: reserves the pass's memory with fn_8832EDB0: the base size (+0xD8), then (stride * max(rowsA, rowsB) + 4) * 4
 * when extra (+0x4C) is set, then calls the optional reserve callback (+0xF8) on the sub-object (+0x1C). agAE: /Oc. */
typedef struct Budget Budget;
typedef struct Sizes { char pad[0x4ac]; int rowsA; int rowsB; char pad4b4[8]; int stride; } Sizes;
typedef struct Pass Pass;
typedef int (*ReserveFn)(void *self, Budget *b);
struct Pass {
    char pad[0x14]; Sizes *sizes; char pad18[4]; char sub[0x4c - 0x1c]; void *extra; char pad50[0xd8 - 0x50];
    unsigned int baseSize; char padDc[0xf8 - 0xdc]; ReserveFn reserve;
};
int fn_8832EDB0(Budget *b, int kind, int align, unsigned int size);
int fn_8831D7E0(Pass *p, Budget *b)
{
    int hr;
    fn_8832EDB0(b, 0, 0x4000, p->baseSize);
    if (p->extra) {
        fn_8832EDB0(b, 0, 0x4000, (p->sizes->stride * (p->sizes->rowsB < p->sizes->rowsA ? p->sizes->rowsA : p->sizes->rowsB) + 4) * 4);
    }
    if (p->reserve) {
        hr = p->reserve(p->sub, b);
        if (hr) return hr;
    }
    return 0;
}
