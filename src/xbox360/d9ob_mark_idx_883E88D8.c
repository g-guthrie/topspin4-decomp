/* Swing_DLL.xex 0x883E88D8-0x883E8930, executable version 0.0.0.3. */
typedef struct Ts4Ob2It { int a; int b; int c; int idx; } Ts4Ob2It;
typedef struct Ts4Ob2Mk { char pad0[0xc]; Ts4Ob2It *items; unsigned int n; } Ts4Ob2Mk;

int ts4_mark_883E88D8(Ts4Ob2Mk *o, int unused, int *arr, int limit)
{
    unsigned int i;
    int idx;
    (void)unused;
    for (i = 0; i < o->n; i++) {
        idx = o->items[i].idx;
        if (idx >= limit)
            return 0x21;
        arr[idx] = 1;
    }
    return 0;
}
