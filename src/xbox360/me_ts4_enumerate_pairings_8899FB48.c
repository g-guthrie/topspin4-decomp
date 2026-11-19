/* Swing_DLL.xex 0x8899FB48: recursive pairing enumeration: with 2 or fewer players hands the result to 8899D230 and counts 1; otherwise pairs players[0] with each later player in turn (swap into slot 1), recurses on the rest and swaps back, summing the counts.
 * /Oc. Plain for loop with a swap before and after the recursive call; matched first try. */
typedef struct PairingSink PairingSink;
void fn_8899D230(PairingSink *sink, void *ctx, int round);

int fn_8899FB48(int *players, int count, PairingSink *sink, void *ctx, int round)
{
    int total;
    int i;
    int t;
    if (count <= 2) {
        fn_8899D230(sink, ctx, round);
        return 1;
    }
    total = fn_8899FB48(players + 2, count - 2, sink, ctx, round);
    for (i = 2; i < count; i++) {
        t = players[1]; players[1] = players[i]; players[i] = t;
        total += fn_8899FB48(players + 2, count - 2, sink, ctx, round);
        t = players[1]; players[1] = players[i]; players[i] = t;
    }
    return total;
}
