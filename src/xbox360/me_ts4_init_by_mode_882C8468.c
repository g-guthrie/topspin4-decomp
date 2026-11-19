/* 0x882C8468: mode 0/1: allocates 64 KB (fn_88888668, attrs 0x24810000; E_OUTOFMEMORY on failure) and initialises via fn_882CDA20(t, src, mode == 1), kind 1; mode 2: fn_882DD5F0(0x400), stores *src at +0x10, kind 2; else E_FAIL */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct T { char pad[0xc]; int kind; void *handle; void *mem; } T;
int fn_882DD5F0(unsigned int flags);
void *fn_88888668(unsigned int size, unsigned int attrs);
int fn_882CDA20(T *t, void **src, int second);
int ts4_init_by_mode_882C8468(T *t, void **src, unsigned int mode)
{
    int r;
    if (mode == 0 || mode == 1) {
        t->mem = fn_88888668(0x10000, 0x24810000);
        if (!t->mem)
            return (int)0x8007000E;
        r = fn_882CDA20(t, src, mode == 1);
        if (r < 0)
            return r;
        t->kind = 1;
        return 0;
    }
    if (mode == 2) {
        r = fn_882DD5F0(0x400);
        if (r < 0)
            return r;
        t->handle = *src;
        t->kind = 2;
        return 0;
    }
    return (int)0x80004005;
}
