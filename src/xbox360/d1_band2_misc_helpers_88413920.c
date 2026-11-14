/* Swing_DLL.xex 0x884138F0-0x88424750, executable version 0.0.0.3. */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

typedef struct Ts4RefObject {
    void (**vtable)(struct Ts4RefObject *, int);
    ts4_u32 reserved[4];
    int ref_count;
} Ts4RefObject;

typedef struct Ts4ListNode {
    struct Ts4ListNode *unused;
    struct Ts4ListNode *next;
} Ts4ListNode;

typedef struct Ts4Sum0C {
    ts4_u32 unused;
    struct Ts4Sum0C *next;
    ts4_u32 pad;
    int value;
} Ts4Sum0C;

typedef struct Ts4Sum14 {
    ts4_u32 unused;
    struct Ts4Sum14 *next;
    ts4_u32 pad[3];
    int value;
} Ts4Sum14;

typedef struct Ts4Sum1C {
    ts4_u32 unused;
    struct Ts4Sum1C *next;
    ts4_u32 pad[5];
    int value;
} Ts4Sum1C;

typedef union Ts4Word32 {
    float f;
    ts4_u32 u;
    ts4_u8 b[4];
} Ts4Word32;

float ts4_swap_float_bytes_884138F0(float value)
{
    Ts4Word32 in, out;
    in.f = value;
    out.b[0] = in.b[3];
    out.b[1] = in.b[2];
    out.b[2] = in.b[1];
    out.b[3] = in.b[0];
    return out.f;
}

ts4_u32 ts4_swap_u32_bytes_88413920(ts4_u32 value)
{
    Ts4Word32 out;
    const ts4_u8 *in = (const ts4_u8 *)&value;
    out.b[0] = in[3];
    out.b[1] = in[2];
    out.b[2] = in[1];
    out.b[3] = in[0];
    return out.u;
}

void ts4_release_ref_object_88419DE8(Ts4RefObject *object)
{
    if (--object->ref_count == 0) {
        object->vtable[4](object, 1);
    }
}

int ts4_count_list_nodes_8841EAE0(const Ts4ListNode *node)
{
    int count = 0;
    while (node != 0) {
        count++;
        node = node->next;
    }
    return count;
}

int ts4_sum_list_field_0C_8841EB40(const Ts4Sum0C *node)
{
    const Ts4Sum0C *next = node->next;
    int total = node->value;
    while (next != 0) {
        total += next->value;
        next = next->next;
    }
    return total;
}

int ts4_sum_list_field_14_8841EB80(const Ts4Sum14 *node)
{
    const Ts4Sum14 *next = node->next;
    int total = node->value;
    while (next != 0) {
        total += next->value;
        next = next->next;
    }
    return total;
}

int ts4_sum_list_field_1C_8841ECE0(const Ts4Sum1C *node)
{
    const Ts4Sum1C *next = node->next;
    int total = node->value;
    while (next != 0) {
        total += next->value;
        next = next->next;
    }
    return total;
}

int ts4_scaled_size_88431D18(int total, const ts4_u8 *info)
{
    int x = info[1];
    int y = info[0];
    return ((total - x) * y + 7) / 8 + x * 4;
}
