/* 0x885610E8: Flood-fills the half-edge mesh from start: pops an edge, marks every edge of its face loop visited, and pushes each unvisited twin, using a 1024-entry stack buffer that grows into pool storage (freed, kind 0x17, if it grew). */
/* Matched on /Oc (agAH). Inline-storage stack: init count, capFlags, then data; pop written as data[count - 1] then count--. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Edge { unsigned short unk0; unsigned short twin; unsigned short next; unsigned short visited; } Edge;
typedef struct EdgeStack { Edge **data; int count; int capFlags; } EdgeStack;
typedef struct EdgeStack1024 { EdgeStack s; Edge *storage[0x400]; } EdgeStack1024;
typedef struct Mesh { int unk0; Edge *edges; } Mesh;
void fn_8841C678(EdgeStack *b, unsigned int elemSize);

static __forceinline void EdgeStack_Push(EdgeStack *s, Edge *e)
{
    if (s->count == (s->capFlags & 0x3FFFFFFF))
        fn_8841C678(s, sizeof(Edge *));
    s->data[s->count] = e;
    s->count++;
}

static __forceinline void EdgeStack_Free(EdgeStack *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Edge *), 0x17);
    }
}

void fn_885610E8(Mesh *m, Edge *start)
{
    Edge *base = m->edges;
    EdgeStack1024 st;
    st.storage[0] = start;
    st.s.count = 1;
    st.s.capFlags = (int)0x80000400;
    st.s.data = st.storage;
    do {
        Edge *e = st.s.data[st.s.count - 1];
        Edge *p;
        st.s.count--;
        p = e;
        do {
            p = &base[p->next];
            p->visited = 1;
        } while (p != e);
        p = e;
        do {
            Edge *twin;
            p = &base[p->next];
            twin = &base[p->twin];
            if (twin->visited == 0)
                EdgeStack_Push(&st.s, twin);
        } while (p != e);
    } while (st.s.count != 0);
    EdgeStack_Free(&st.s);
}
