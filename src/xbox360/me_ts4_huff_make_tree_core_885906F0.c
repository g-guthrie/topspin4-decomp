/* Swing_DLL.xex 0x885906F0: make_tree core: heapify, merge the two rarest nodes until one is left, then make_len
 * /O1 LTCG with the sift-down, make_len and count_len units as context (the target keeps the state in r3 across the calls). */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct HuffNode { u16 left; u16 right; } HuffNode;

typedef struct HuffState {
    u8 pad[0x990];
    u16 *freq;              /* +0x990 */
    u16 *sorted;            /* +0x994: output cursor for leaves in heap order */
    u8 *len;                /* +0x998 */
    short heap[0x2BE];      /* +0x99C, 1-based */
    HuffNode nodes[0x577];  /* +0xF18 */
    u16 lenCount[17];       /* +0x24F4 */
    int numSymbols;         /* +0x2518 */
    short heapLen;          /* +0x251C */
    signed char depth;      /* +0x251E */
} HuffState;

void fn_88590608(HuffState *s, short k);
void fn_885904C8(HuffState *s, short root);

/* make_tree core: heapify, repeatedly merge the two rarest nodes, then compute the code lengths. */
void fn_885906F0(HuffState *s, short avail, u16 *freq, u16 *codes)
{
    short i, j, k;
    for (i = s->heapLen >> 1; i >= 1; i--)
        fn_88590608(s, i);
    s->sorted = codes;
    do {
        i = s->heap[1];
        if (i < s->numSymbols)
            *s->sorted++ = i;
        s->heap[1] = s->heap[s->heapLen--];
        fn_88590608(s, 1);
        j = s->heap[1];
        if (j < s->numSymbols)
            *s->sorted++ = j;
        k = avail++;
        freq[k] = freq[i] + freq[j];
        s->heap[1] = k;
        fn_88590608(s, 1);
        s->nodes[k].left = i;
        s->nodes[k].right = j;
    } while (s->heapLen > 1);
    s->sorted = codes;
    fn_885904C8(s, k);
}
