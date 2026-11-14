/* Family SWB2 (jump-table switch). */
typedef struct Node {
    char pad0[0xc];
    unsigned char kind;      /* 0x0c */
    unsigned char sub;       /* 0x0d */
    char pad1[2];
    unsigned short flags;    /* 0x10 */
} Node;

int fn_884262F8(Node *n);
void *ts4_get_u32_off4_88426130(Node *n);
int ts4_sum_list_field_1C_8841ECE0(void *list);
Node *fn_8841ED08(void *list, int index);

int ts4_node_measure_884CED50(Node *n, unsigned int kind, int arg)
{
    int result = -1;
    int f;

    switch (kind) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
    case 24: case 31:
        result = fn_884262F8(n);
        break;
    case 20: case 21: case 22: case 26: case 27: case 28: case 29: case 30:
        result = arg;
        break;
    case 19:
        result = ts4_node_measure_884CED50(n, n->sub, arg);
        break;
    case 25: {
        int best = 1;
        void *list = ts4_get_u32_off4_88426130(n);
        int i = 0;
        while (i < ts4_sum_list_field_1C_8841ECE0(list)) {
            Node *child = fn_8841ED08(list, i);
            int r = ts4_node_measure_884CED50(child, child->kind, arg);
            if (r > best) best = r;
            i++;
        }
        result = best;
        break;
    }
    case 23:
        break;
    }
    f = n->flags & 0x180;
    if (f != 0) {
        int m = (f == 0x100) ? 0x10 : 8;
        if (m > result) result = m;
    }
    return result;
}
