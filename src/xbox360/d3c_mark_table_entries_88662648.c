/* Swing_DLL.xex 0x88662648-0x886626D8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;

#ifdef _MSC_VER
#define TS4_FI static __forceinline
#else
#define TS4_FI static inline
#endif

typedef struct Ts4Module {
    char pad[0x74];
    char *state;
} Ts4Module;

typedef struct Ts4Owner {
    char pad[4];
    Ts4Module *module;
} Ts4Owner;

/* Self-relative array header {offset to first entry, entry count}. */
typedef struct Ts4RelArray {
    int off;
    u32 count;
} Ts4RelArray;

typedef struct Ts4RelArrayHolder {
    char pad[0xc];
    Ts4RelArray arr;
} Ts4RelArrayHolder;

TS4_FI char *ts4_rel_array8_begin(Ts4RelArray *c)
{
    char *r = 0;
    if (c->off != -1) r = (char *)c + c->off;
    return r;
}

TS4_FI char *ts4_rel_array8_end(Ts4RelArray *c)
{
    char *r = 0;
    if (c->off != -1) r = (char *)c + c->off + c->count * 8;
    return r;
}

/* When the module has a selected item, flag each 8-byte table entry whose key is 0xf578057a. */
u8 ts4_mark_table_entries_88662648(Ts4Owner *o)
{
    char *m = o->module->state;
    u8 ok = (*(int *)(m + 0xbc8) + 1) != 0;
    Ts4RelArrayHolder *cs;
    char *end, *it;
    if (!ok) return ok;
    cs = (Ts4RelArrayHolder *)(m + 0x40c);
    end = ts4_rel_array8_end(&cs->arr);
    it = ts4_rel_array8_begin(&cs->arr);
    for (; it != end; it += 8) *(u8 *)(it + 4) = (0xf578057a == *(u32 *)it);
    return ok;
}
