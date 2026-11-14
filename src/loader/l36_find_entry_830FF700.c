/* Loader_DLL.xex 0x830FF700-0x830FF78C, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Ent { u32 pad0; u32 key; u32 pad[10]; };
struct Blk { char pad[0x1c]; struct Ent *ents; u32 count; u32 pad2; struct Blk *next; };

long ts4l_find_entry_830FF700(struct Blk *b, u32 key, struct Ent **out)
{
    struct Ent *e;
    u32 i, n;
    if (out == 0) return 0x80070057;
    *out = 0;
    if (b == 0) return 0x80070057;
    do {
        e = b->ents;
        if (e != 0) {
            n = b->count;
            for (i = 0; i < n; i++) {
                if (key == e[i].key) { *out = (struct Ent *)((char *)e + i * 0x30); return 0; }
            }
        }
        b = b->next;
    } while (b != 0);
    return 0x80300007;
}
