/* Swing_DLL.xex 0x883BDB48-0x8841EF68, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;

extern void *lbl_8803DA3C[];

struct ts4_limit_state {
    void **vtable;
    u32 pos;
    u32 limit;
    u32 count;
    u32 flag;
};

/* Initialises a state record with its vtable, an unbounded limit and a count of one. */
void ts4_init_limit_state_8841B550(struct ts4_limit_state *s)
{
    s->vtable = lbl_8803DA3C;
    s->flag = 1;
    s->count = 0;
    s->pos = 0;
    s->limit = 0x7fffffff;
}

/* Walks to the last node of a chain and writes whether its value is non-zero. */
void ts4_last_node_nonzero_8841EF38(u8 *out, int *node)
{
    int next = node[1];
    while (next) {
        node = (int *)(long)next;
        next = node[1];
    }
    *out = node[3] != 0;
}
