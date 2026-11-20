/* Swing_DLL.xex 0x885B3E78-0x885B3F18, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
struct Entry { u32 key; u16 sub; u16 pad; u32 f8; u32 fc; };
extern char lbl_880935A0[];

struct Entry *ts4_find_table_entry_885B3E78(void *unused, int a, int b, u32 key, u32 sub)
{
    struct Entry *tab;
    u32 n, i;
    (void)unused;
    if (b != 0) {
        if (a != 0) {
            tab = (struct Entry *)(lbl_880935A0 + 0x2240);
            n = 0xb;
        } else {
            tab = (struct Entry *)(lbl_880935A0 + 0x17d8);
            n = 0x16;
        }
    } else {
        tab = (struct Entry *)lbl_880935A0;
        n = 0x1e;
    }
    for (i = 0; i < n; i++) {
        if (tab[i].key == key && tab[i].sub == sub) {
            if (tab[i].fc != 0 && tab[i].f8 != 0) return &tab[i];
            return 0;
        }
    }
    return 0;
}
