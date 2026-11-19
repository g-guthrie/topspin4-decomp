/* Swing_DLL.xex 0x885904C8: make_len: histogram code lengths, force the Kraft sum to 2^16, assign lengths to the sorted leaves
 * /O1 LTCG with the count_len unit as context (the target keeps the state in r9 across the call). */
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

void fn_88590420(HuffState *s, short node);

/* make_len: histogram code lengths, force the Kraft sum to 2^16 by lengthening codes, then assign lengths in sorted order. */
void fn_885904C8(HuffState *s, short root)
{
    u8 i;
    u16 cum;
    short k;
    for (i = 0; i <= 16; i++)
        s->lenCount[i] = 0;
    fn_88590420(s, root);
    cum = 0;
    for (i = 16; i > 0; i--)
        cum += s->lenCount[i] << (16 - i);
    while (cum != 0) {
        s->lenCount[16]--;
        for (i = 15; i > 0; i--) {
            if (s->lenCount[i] != 0) {
                s->lenCount[i]--;
                s->lenCount[i + 1] += 2;
                break;
            }
        }
        cum--;
    }
    for (i = 16; i > 0; i--) {
        k = s->lenCount[i];
        while (--k >= 0)
            s->len[*s->sorted++] = i;
    }
}
