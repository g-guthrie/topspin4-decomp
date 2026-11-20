/* SM4: linear searches over small tables embedded in loaded blocks. */
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
typedef struct { unsigned key; int val; } Ts4Ent8;
struct Ts4BlkHdr { int off; int cnt; };
struct Ts4BlkOwner { char pad[0xc]; char *blk; };

/* entries start at hdr + off (absent when off == -1) and are 8 bytes each */
INL Ts4Ent8 *ent_begin(struct Ts4BlkHdr *h) { Ts4Ent8 *r = 0; if (h->off != -1) r = (Ts4Ent8 *)(h->off + (char *)h); return r; }
INL Ts4Ent8 *ent_end(struct Ts4BlkHdr *h) { Ts4Ent8 *r = 0; if (h->off != -1) r = (Ts4Ent8 *)(h->off + h->cnt * 8 + (char *)h); return r; }

/* find the 8-byte entry with the given key in the table of the block at +0xc */
#define FIND_ENT(NAME, HOFF) \
    Ts4Ent8 *NAME(struct Ts4BlkOwner *o, unsigned key) \
    { \
        Ts4Ent8 *p = ent_begin((struct Ts4BlkHdr *)(o->blk + (HOFF))); \
        Ts4Ent8 *e = ent_end((struct Ts4BlkHdr *)(o->blk + (HOFF))); \
        for (; p != e; p++) if (key == p->key) return p; \
        return 0; \
    }
FIND_ENT(ts4_find_block_entry_886EF460, 8)
FIND_ENT(ts4_find_block_entry_886EF7A0, 0x20)
FIND_ENT(ts4_find_block_entry_886EF808, 0x14)
FIND_ENT(ts4_find_block_entry_886EF870, 8)
