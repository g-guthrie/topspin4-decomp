/* Swing_DLL.xex 0x88322CA8: resolves a handle (type bits 28-31, index bits 16-27, sequence in the low 16 bits) to its 0x1A8-byte pool entry
 * via fn_88309D38; 0x24 bad type or index, 0x51 empty pool, 0xB stale sequence (0x24 when off by at most 1). agAE: /Oc. */
typedef struct Entry { char pad[0x50]; unsigned int handle; char pad54[0x1a8 - 0x54]; } Entry;
typedef struct Pool { char pad[0x130]; int count; Entry *entries; } Pool;
int fn_88309D38(unsigned int type, Pool **pool);
int fn_88322CA8(unsigned int h, Entry **out)
{
    int index = (h >> 16) & 0xfff;
    unsigned int seq = h & 0xffff;
    Pool *p;
    Entry *e;
    if (!out) return 0x25;
    *out = 0;
    if (fn_88309D38(h >> 28, &p)) return 0x24;
    if (!p->entries) return 0x51;
    if (index >= p->count) return 0x24;
    e = &p->entries[index];
    if (seq && e->handle != h)
        return ((e->handle & 0xffff) - seq < 2) ? 0x24 : 0xb;
    *out = e;
    return 0;
}
