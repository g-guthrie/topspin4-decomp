/* Swing_DLL.xex 0x88590420: Huffman builder: recursive walk counting leaves per depth (lengths above 16 are clamped to 16)
 * /O1; depth is a signed char member, node index a short */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct HuffNode { u16 left; u16 right; } HuffNode;

typedef struct HuffState {
    u8 pad[0x990];
    u16 *freq;              /* +0x990 */
    u16 *sorted;            /* +0x994: output cursor for leaves in heap order */
    u8 pad998[4];
    short heap[0x2BE];      /* +0x99C, 1-based */
    HuffNode nodes[0x577];  /* +0xF18 */
    u16 lenCount[17];       /* +0x24F4 */
    int numSymbols;         /* +0x2518 */
    short heapLen;          /* +0x251C */
    signed char depth;      /* +0x251E */
} HuffState;

/* Count code lengths: walk the tree, bumping the length histogram (capped at 16) at each leaf. */
void fn_88590420(HuffState *s, short node)
{
    if (node < s->numSymbols) {
        int d = s->depth;
        if (d >= 16)
            d = 16;
        s->lenCount[d]++;
    } else {
        s->depth++;
        fn_88590420(s, s->nodes[node].left);
        fn_88590420(s, s->nodes[node].right);
        s->depth--;
    }
}
