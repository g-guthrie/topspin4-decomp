/* Swing_DLL.xex 0x88617668-0x886176F0, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;

#ifdef _MSC_VER
#define TS4_FI static __forceinline
#else
#define TS4_FI static inline
#endif

typedef struct Ts4PairTableOwner {
    char pad[0x30];
    char *table;
} Ts4PairTableOwner;

/* Self-relative array of 4-byte entries {u16 a, u16 b}: begin / end. */
TS4_FI char *ts4_rel_pair_table_begin(char *b)
{
    char *r = 0;
    int off = *(int *)b;
    if (off != -1) r = b + off;
    return r;
}

TS4_FI char *ts4_rel_pair_table_end(char *b)
{
    char *r = 0;
    int off = *(int *)b;
    if (off != -1) r = b + off + ((u32 *)b)[1] * 4;
    return r;
}

/* Look KEY up in either column of the pair table: a match in the first column yields the second
   value, a match in the second column yields KEY itself. */
u32 ts4_rel_pair_table_lookup_88617668(Ts4PairTableOwner *o, u16 key, u16 *out)
{
    char *base = o->table;
    char *it = ts4_rel_pair_table_begin(base), *end = ts4_rel_pair_table_end(base);
    for (; it != end; it += 4) {
        if (((u16 *)it)[0] == key) { *out = ((u16 *)it)[1]; return 1; }
        if (((u16 *)it)[1] == key) { *out = key; return 1; }
    }
    return 0;
}
