/* Swing_DLL.xex 0x8816C258: destructor body: destroy the four member arrays in reverse order (20 slots, 25 slot pairs via 8816C208, 20 records, 5 owned blocks via 8816C198).
 * /Oc. Each reverse array destroy is an inline (first, count): p = first + count; while (--count >= 0) { --p; ... }. */
typedef struct Vec { unsigned int *first; unsigned int *last; unsigned int *end; } Vec;
typedef struct Slot20 { unsigned int a; unsigned int b; Vec items; } Slot20;
typedef struct Slot28 { unsigned int a; unsigned int b; Vec items; unsigned int c; unsigned int d; } Slot28;
typedef struct Slots2 { Slot20 slots[2]; unsigned int pad[2]; } Slots2;
typedef struct Owned3 { unsigned char body[0x64]; } Owned3;
typedef struct SlotTables { unsigned int head; Owned3 owned[5]; Slot28 recs[20]; Slots2 pairs[25]; Slot20 slots[20]; } SlotTables;
void ts4_destroy_owned_object(void *obj);
void ts4_destroy_slots2_8816C208(Slots2 *s);
void ts4_destroy_owned_3_8816C198(Owned3 *o);

static __inline void vec_free(Vec *v)
{
    if (v->first) ts4_destroy_owned_object(v->first);
}

static __inline void slot20_destroy_n(Slot20 *first, int count)
{
    Slot20 *p = first + count;
    while (--count >= 0) {
        --p;
        vec_free(&p->items);
    }
}

static __inline void slot28_destroy_n(Slot28 *first, int count)
{
    Slot28 *p = first + count;
    while (--count >= 0) {
        --p;
        vec_free(&p->items);
    }
}

static __inline void slots2_destroy_n(Slots2 *first, int count)
{
    Slots2 *p = first + count;
    while (--count >= 0) {
        --p;
        ts4_destroy_slots2_8816C208(p);
    }
}

static __inline void owned3_destroy_n(Owned3 *first, int count)
{
    Owned3 *p = first + count;
    while (--count >= 0) {
        --p;
        ts4_destroy_owned_3_8816C198(p);
    }
}

void fn_8816C258(SlotTables *t)
{
    slot20_destroy_n(t->slots, 20);
    slots2_destroy_n(t->pairs, 25);
    slot28_destroy_n(t->recs, 20);
    owned3_destroy_n(t->owned, 5);
}
