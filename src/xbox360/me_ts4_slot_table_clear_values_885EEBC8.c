/* 0x885EEBC8: Clears a table of 12-byte slots {slots (+0), count (+4), used (+0x10)}: used = 0, then the word at +4 of every slot is zeroed; count is re-read each pass. */
/* Matched on /Oc (agAH). Plain index loop over t->slots[i].value. */
typedef struct Slot { int key; int value; int extra; } Slot;
typedef struct SlotTable { Slot *slots; int count; int unk8; int unkc; int used; } SlotTable;
void fn_885EEBC8(SlotTable *t)
{
    int i;
    t->used = 0;
    for (i = 0; i < t->count; i++)
        t->slots[i].value = 0;
}
