/* 0x8837AA88: returns how many of the list items are not ready (ts4_get_ready_flag_883332F0), counting skipped items as not ready */
/* Near miss (agAH): /Oc, 2 off at +0x24: the target initialises the i*4 offset register before the skip-array base (li r29 before addi r28). Declaration order, nested ifs, pointer forms and an inline accessor do not move it. */
typedef struct Item Item;
extern void ts4_get_ready_flag_883332F0(Item *it, unsigned char *ready);
typedef struct L { char p[8]; int count; Item **items; unsigned char skip[1]; } L;
int fn_8837AA88(void *self, L *l)
{
    int ready = 0, i;
    for (i = 0; i < l->count; i++) {
        unsigned char r;
        ts4_get_ready_flag_883332F0(l->items[i], &r);
        if (!l->skip[i] && r)
            ready++;
    }
    return l->count - ready;
}
