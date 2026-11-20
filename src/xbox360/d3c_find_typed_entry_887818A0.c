/* Swing_DLL.xex 0x887818A0-0x88781A4C, executable version 0.0.0.3. */
typedef unsigned int u32;

#ifdef _MSC_VER
#define TS4_FI static __forceinline
#else
#define TS4_FI static inline
#endif

typedef struct Ts4TableOwner {
    char pad[0xa0];
    char *table;
} Ts4TableOwner;

extern Ts4TableOwner *lbl_88D45A60;

/* Self-relative array of 8-byte entries {offset to payload, type hash}: begin / end. */
TS4_FI char *ts4_rel_table_begin(char *b)
{
    char *r = 0;
    int off = *(int *)b;
    if (off != -1) r = b + off;
    return r;
}

TS4_FI char *ts4_rel_table_end(char *b)
{
    char *r = 0;
    int off = *(int *)b;
    if (off != -1) r = b + off + ((u32 *)b)[1] * 8;
    return r;
}

/* Find the payload of the entry with type hash HASH whose first word equals *key; returns payload + 4. */
#define TS4_FIND_TYPED_ENTRY(NAME, HASH) \
    void *NAME(u32 *key) \
    { \
        char *base = lbl_88D45A60->table; \
        char *it = ts4_rel_table_begin(base), *end = ts4_rel_table_end(base); \
        for (; it != end; it += 8) { \
            if (((u32 *)it)[1] == HASH) { \
                char *ent = it + *(int *)it; \
                if (*key == *(u32 *)ent) return ent + 4; \
            } \
        } \
        return 0; \
    }

TS4_FIND_TYPED_ENTRY(ts4_find_typed_entry_887818A0, 0x7FB7203A) /* 0x887818A0 */
TS4_FIND_TYPED_ENTRY(ts4_find_typed_entry_88781930, 0x2F808AC0) /* 0x88781930 */
TS4_FIND_TYPED_ENTRY(ts4_find_typed_entry_887819C0, 0x3F4A0FF8) /* 0x887819C0 */
