/* Swing_DLL.xex 0x8817E3C0-0x8817E3C0, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Payload { u32 a, b, c; } Payload;
typedef struct Node { struct Node *next; struct Node *prev; Payload value; } Node;
typedef struct List { Node *head; } List;
extern Node *ts4_if_call_seq_u32_lbl_88D45B38_8817F480(List *list, u32 count);
/* Allocates a node, copies the 12-byte payload into it and links it before the sentinel. */
Node *ts4_list_insert_before_head_8817E3C0(List *self, const Payload *item)
{
    Node *head = self->head;
    Node *node = ts4_if_call_seq_u32_lbl_88D45B38_8817F480(self, 1);
    Payload *slot = &node->value;
    if (slot) {
        *slot = *item;
    }
    {
        Node *last = head->prev;
        node->next = head;
        node->prev = last;
        last->next = node;
        head->prev = node;
    }
    return node;
}
