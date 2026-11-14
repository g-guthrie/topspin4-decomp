/* Swing_DLL.xex 0x883D0A48-0x883D0ACC, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4X2Key { char pad[0x3c]; u32 id; } Ts4X2Key;
typedef struct Ts4X2Node {
    struct Ts4X2Node *next;
    struct Ts4X2Node *prev;
    u32 f8;
    Ts4X2Key *key;
} Ts4X2Node;
typedef struct Ts4X2Node2 {
    struct Ts4X2Node2 *next;
    struct Ts4X2Node2 *prev;
    u32 f8;
    Ts4X2Key *owner;
} Ts4X2Node2;
int fn_883E07F8(Ts4X2Node2 *node, int arg);

int ts4_unlink_matching_883D0A48(char *base, u32 id)
{
    Ts4X2Node2 *head = (Ts4X2Node2 *)(base + 0x8054);
    Ts4X2Node2 *node = head->next;
    Ts4X2Node2 *cur;
    int r;
    while (node != head) {
        cur = node;
        node = node->next;
        if (cur->owner->id == id) {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur->prev = cur;
            cur->next = cur;
            cur->f8 = 0;
            r = fn_883E07F8(cur, 0);
            if (r != 0)
                return r;
        }
    }
    return 0;
}
