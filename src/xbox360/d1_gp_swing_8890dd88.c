/* Swing_DLL.xex gameplay data-flow graph node kernel.
 *
 * A graph instance keeps its float register file at instance+0x14.  A node
 * entry is {relative offset to record, type hash}; the kernel receives the
 * entry and reads the record at entry + entry[0].
 */

typedef struct GpGraph {
    int pad0[5];
    float *regs;
} GpGraph;

/* Swing_DLL.xex 0x8890DD88: CONST node, regs[slot] = literal. */
void gp_swing_node_const(GpGraph *graph, int *entry)
{
    int *rec = (int *)((char *)entry + entry[0]);

    graph->regs[rec[0]] = ((float *)rec)[1];
}
