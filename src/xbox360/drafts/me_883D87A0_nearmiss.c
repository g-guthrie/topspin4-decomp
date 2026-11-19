typedef struct Kids { char pad[0x1c]; int n; void **items; } Kids;
typedef struct Node { char pad[0xa8]; Kids *kids; } Node;
unsigned char fn_883CC0E8(Node *n);
unsigned char ts4_get_u32_off18_883DC630(void *e);
unsigned char ts4_if_get_u32_offa8_883C6F08(Node *n, int i);
int fn_883C7278(Node *n);
int ts4_tailcall_fn_883DD558_883DE178(void *e, Node *n);
int fn_883DD7D8(void *e, Node *n, int a);
void fn_883C6F70(Node *n, int i, int a);
int fn_883D87A0(void *self, Node *node)
{
    int i;
    int r;
    (void)self;
    if (fn_883CC0E8(node)) {
        for (i = 0; i < node->kids->n; i++) {
            if (ts4_get_u32_off18_883DC630(node->kids->items[i]) && ts4_if_get_u32_offa8_883C6F08(node, i)
                && fn_883C7278(node) == 0) {
                r = ts4_tailcall_fn_883DD558_883DE178(node->kids->items[i], node);
                if (r)
                    return r;
                r = fn_883DD7D8(node->kids->items[i], node, 1);
                if (r)
                    return r;
                fn_883C6F70(node, i, 0);
            }
        }
    }
    return 0;
}
