/* Swing_DLL.xex 0x88623FA0-0x8862402C, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;

#ifdef _MSC_VER
#define TS4_FI static __forceinline
#else
#define TS4_FI static inline
#endif

extern u8 fn_886328B0(char *entry);

/* Self-relative array of 8-byte entries: begin / end. */
TS4_FI char *ts4_rel_table8_begin(char *b)
{
    char *r = 0;
    int off = *(int *)b;
    if (off != -1) r = b + off;
    return r;
}

TS4_FI char *ts4_rel_table8_end(char *b)
{
    char *r = 0;
    int off = *(int *)b;
    if (off != -1) r = b + off + ((u32 *)b)[1] * 8;
    return r;
}

/* Visit the 8-byte entries in order until the visitor returns 1; returns the last visitor result (0 if empty). */
u8 ts4_rel_table_visit_until_88623FA0(char *table)
{
    u8 r = 0;
    char *end = ts4_rel_table8_end(table), *it = ts4_rel_table8_begin(table);
    for (; it != end; it += 8) {
        r = fn_886328B0(it);
        if (r == 1) break;
    }
    return r;
}
