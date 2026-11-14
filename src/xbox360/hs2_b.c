/* HS2 hand-decompiled functions, group B (Swing_DLL.xex 0x8841xxxx-0x8842xxxx). */

typedef struct Hs2Inner Hs2Inner;

/* ---- signed value readers ---- */

typedef struct Hs2Reader {
    int pad0;
    int pad4;
    void *inner;
} Hs2Reader;

int fn_8841DDB0(void *inner, unsigned char *negative);

/* ---- chunk list element lookup ---- */

typedef struct Hs2Chunk20 {
    int pad0;
    struct Hs2Chunk20 *next;
    int pad8, padc;
    char *data;
    int count;
} Hs2Chunk20;

/* Finds element idx (relative to the end of the chunk chain) and returns its address, 20-byte elements. */
void *ts4_chunk_elem20_8841EBA8(Hs2Chunk20 *head, int idx)
{
    Hs2Chunk20 *n;
    int total = head->count;
    int off;
    for (n = head->next; n; n = n->next)
        total += n->count;
    n = head;
    off = idx - total;
    do {
        off += n->count;
        if (off >= 0)
            return n->data + off * 20;
        n = n->next;
    } while (n);
    return head->data;
}

typedef struct Hs2Chunk24 {
    int pad0;
    struct Hs2Chunk24 *next;
    int pad8, padc, pad10, pad14;
    char *data;
    int count;
} Hs2Chunk24;

/* Same lookup with 24-byte elements. */
void *ts4_chunk_elem24_8841ED08(Hs2Chunk24 *head, int idx)
{
    Hs2Chunk24 *n;
    int total = head->count;
    int off;
    for (n = head->next; n; n = n->next)
        total += n->count;
    n = head;
    off = idx - total;
    do {
        off += n->count;
        if (off >= 0)
            return n->data + off * 24;
        n = n->next;
    } while (n);
    return head->data;
}

/* ---- string helpers ---- */

typedef struct Hs2Str {
    const unsigned char *data;
    int len; /* includes the terminator */
} Hs2Str;

/* Stores 1 in *out when haystack ends with needle, else 0. */
void ts4_str_ends_with_884219C8(unsigned char *out, const Hs2Str *haystack, const Hs2Str *needle)
{
    int nlen = needle->len - 1;
    int hlen = haystack->len - 1;
    int off;
    int i;
    if (hlen < nlen) {
        *out = 0;
        return;
    }
    off = haystack->len - needle->len;
    for (i = 0; i < nlen; i++) {
        if (haystack->data[off + i] != needle->data[i]) {
            *out = 0;
            return;
        }
    }
    *out = 1;
}

/* ---- open-addressed hash lookup ---- */

typedef struct Hs2HashTable {
    int *slots;
    int pad4;
    int mask;
} Hs2HashTable;

