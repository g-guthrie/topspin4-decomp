/* Swing_DLL.xex 0x88329D20: looks name up through fn_88329188(table, name, -1, ...) in the shared table (+0x34) when flags has 0x10,
 * otherwise in the local table (+0x28); 0x25 on a null name, 0xA when the table is missing. agAE: /Oc. */
typedef struct Table Table;
typedef struct Loader { char pad[0x28]; Table *local; char pad2c[0x34 - 0x2c]; Table *shared; } Loader;
int fn_88329188(Table *t, const char *name, int index, void *a, void *b, void *c);
int fn_88329D20(Loader *l, unsigned int flags, const char *name, void *a, void *unused, void *b, void *c)
{
    Table *t;
    int hr;
    if (!name) return 0x25;
    if (flags & 0x10) {
        t = l->shared;
        if (!t) return 0xa;
        hr = fn_88329188(t, name, -1, a, b, c);
        if (hr) return hr;
    } else {
        t = l->local;
        if (!t) return 0xa;
        hr = fn_88329188(t, name, -1, a, b, c);
        if (hr) return hr;
    }
    return 0;
}
