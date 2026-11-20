/* 0x88941AC8: find the 0x2C-byte entry of a self-relative table whose word at +0x24 equals key; 0 when absent */
/* Matched on /Oc (agAL). Plain route; agAH found/break result local. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Hdr { int off; int cnt; } Hdr;
typedef struct Entry44 {
    u8 pad00[0x24];
    int key;        /* +0x24 */
    u32 pad28;
} Entry44;
extern void *ts4_offset_array_end44_88160B30(Hdr *h);

Entry44 *ts4_find_entry44_by_key_88941AC8(int key, Hdr *h)
{
    Entry44 *result = 0;
    Entry44 *e = 0;
    Entry44 *end;
    if (h->off != -1)
        e = (Entry44 *)((char *)h + h->off);
    end = (Entry44 *)ts4_offset_array_end44_88160B30(h);
    for (; e != end; e++) {
        if (key == e->key) {
            result = e;
            break;
        }
    }
    return result;
}
