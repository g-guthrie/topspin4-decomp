/* Loader_DLL.xex 0x831005B8-0x83100650, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
struct HNode { u32 hash; const u16 *name; u32 pad8; struct HNode *next; };
extern int fn_833E4108(const u16 *a, const u16 *b);

struct HNode *ts4l_hash_find_831005B8(struct HNode **table, const u16 *key)
{
    const u16 *p = key;
    u32 h;
    u32 c = *p;
    struct HNode *n;
    h = 0;
    while (c != 0) {
        h = h * 33 + c;
        c = *++p;
    }
    for (n = table[h % 27]; n != 0; n = n->next) {
        if (n->hash == h && fn_833E4108(n->name, key) == 0) return n;
    }
    return 0;
}
