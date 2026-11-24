/* Swing_DLL.xex 0x886F3868-0x886F38F0, executable version 0.0.0.3. */
typedef unsigned int u32;

#ifdef _MSC_VER
#define TS4_FI static __forceinline
#else
#define TS4_FI static inline
#endif

typedef struct Ts4TableHolder {
    char pad[0xc];
    char *container;
} Ts4TableHolder;

typedef struct Ts4TableOwner {
    char pad[0x34];
    Ts4TableHolder *holder;
} Ts4TableOwner;

typedef struct Ts4TableModule {
    char pad[0x40];
    void *active;
} Ts4TableModule;

extern Ts4TableModule *lbl_88D45A70;

/* Self-relative array of 16-byte entries: begin / end. */
TS4_FI char *ts4_rel_table16_begin(char *b)
{
    char *r = 0;
    int off = *(int *)b;
    if (off != -1) r = b + off;
    return r;
}

TS4_FI char *ts4_rel_table16_end(char *b)
{
    char *r = 0;
    int off = *(int *)b;
    if (off != -1) r = b + off + ((u32 *)b)[1] * 16;
    return r;
}

/* Find the 16-byte entry whose key word at +0xc equals KEY, or 0. */
void *ts4_rel_table_find_by_key_886F3868(Ts4TableOwner *o, u32 key)
{
    Ts4TableHolder *in = o->holder;
    if (in) {
        if (lbl_88D45A70->active) {
            char *cont = in->container;
            if (cont) {
                char *base = cont + 8;
                char *it = ts4_rel_table16_begin(base), *end = ts4_rel_table16_end(base);
                for (; it != end; it += 16) if (*(u32 *)(it + 0xc) == key) return it;
            }
        }
    }
    return 0;
}
