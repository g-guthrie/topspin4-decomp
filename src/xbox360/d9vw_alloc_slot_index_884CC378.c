/* Swing_DLL.xex 0x884CC378-0x884CC3FC, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4VwSlot { u32 data; int next; } Ts4VwSlot;
typedef struct Ts4VwSlotPool { Ts4VwSlot *base; int size; int cap; char pad[0xc]; int free_head; } Ts4VwSlotPool;
void fn_8841C678(Ts4VwSlotPool *v, int elem_size);
int ts4_alloc_slot_index_884CC378(Ts4VwSlotPool *p)
{
    int idx = p->free_head;
    if (idx != -1) {
        p->free_head = p->base[idx].next;
        return idx;
    }
    idx = p->size;
    if (idx == (p->cap & 0x3fffffff))
        fn_8841C678(p, 8);
    p->size++;
    return idx;
}
