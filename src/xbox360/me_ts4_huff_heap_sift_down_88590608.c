/* Swing_DLL.xex 0x88590608: Huffman builder heap: sift node k down by symbol frequency (zlib pqdownheap without the depth tie-break)
 * /O1; short heap indices, heap at +0x99C, heap length at +0x251C */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct HuffState {
    u8 pad[0x990];
    u16 *freq;          /* +0x990 */
    u8 pad994[0x99C - 0x994];
    short heap[0xDC0];  /* +0x99C */
    short heapLen;      /* +0x251C */
} HuffState;

/* Restore the min-heap property by sifting node k down (by frequency). */
void fn_88590608(HuffState *s, short k)
{
    short v = s->heap[k];
    short j = k << 1;
    while (j <= s->heapLen) {
        if (j < s->heapLen && s->freq[s->heap[j]] > s->freq[s->heap[j + 1]])
            j++;
        if (s->freq[v] <= s->freq[s->heap[j]])
            break;
        s->heap[k] = s->heap[j];
        k = j;
        j <<= 1;
    }
    s->heap[k] = v;
}
