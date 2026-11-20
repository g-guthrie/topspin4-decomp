/* 0x88451948: ORs mask[from] into mask[node], then recurses into every edge that ends at node (src becomes the new node; depth+1 is passed through unused). */
/* Matched on /Oc (agAH). An edge pointer local keeps dst in r5 for the call. */
typedef struct Edge { int src; int dst; } Edge;
typedef struct Graph { char p0[0x110]; unsigned int mask[0x1e24 / 4 - 0x44]; Edge *edges; int nedges; } Graph;
void fn_88451948(Graph *g, int node, int from, int depth)
{
    int i;
    g->mask[node] |= g->mask[from];
    for (i = 0; i < g->nedges; i++) {
        Edge *e = &g->edges[i];
        if (e->dst == node)
            fn_88451948(g, e->src, e->dst, depth + 1);
    }
}
