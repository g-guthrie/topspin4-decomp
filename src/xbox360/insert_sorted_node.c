typedef struct Ts4Node {
    struct Ts4Node *next;
    struct Ts4Node *previous;
    unsigned char reserved[8];
    unsigned int value;
} Ts4Node;

typedef struct Ts4NodeList {
    unsigned char reserved[0x2C];
    Ts4Node sentinel;
} Ts4NodeList;

/* Swing_DLL.xex 0x8857CB00. */
void ts4_insert_sorted_node(Ts4NodeList *list, Ts4Node *node)
{
    Ts4Node *current = list->sentinel.next;
    Ts4Node *sentinel = &list->sentinel;

    if (current == sentinel || list->sentinel.previous->value <= node->value) {
        current = sentinel->previous;
        node->next = sentinel;
        node->previous = current;
        current->next = node;
        sentinel->previous = node;
        return;
    }

    do {
        if (node->value <= current->value) {
            Ts4Node *previous = current->previous;

            node->next = current;
            node->previous = previous;
            previous->next = node;
            current->previous = node;
            return;
        }
        current = current->next;
    } while (current != sentinel);
}
