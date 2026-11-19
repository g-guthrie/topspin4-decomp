/* Swing_DLL.xex 0x8899FA00: slot taken/released: adjust used/free counters at session state+0x27c, write label lbl_880D1DF8 (taken) or lbl_880D1E00 into the 16-byte entry label, post event 0xA0BDE62E on the state+0x1bc event slot.
 * /Oc. Counters read into locals, adjusted, then stored; the event post goes through an EventSlot pointer (same layout as fam2_session_event.c) so the state reload reuses r11. */
typedef struct EventSlot { unsigned char f0; unsigned char pending; unsigned char pad[2]; unsigned int hash; unsigned int value; } EventSlot;
typedef struct SlotCounters { char pad[0x48]; int used; int free; } SlotCounters;
typedef struct SessionState {
    char pad[0x1bc]; EventSlot event;
    char pad3[0x27c - 0x1c8]; SlotCounters slots;
} SessionState;
typedef struct SessionContext { char pad[0x3c]; SessionState *state; } SessionContext;
typedef struct SlotEntry { char pad[0x54]; char label[16]; char pad2[0xd8 - 0x64]; } SlotEntry;
typedef struct SlotTable { int off; } SlotTable;
typedef struct SlotOwner { char pad[0xac]; SlotTable *table; } SlotOwner;
extern SessionContext *g_ts4_session_context;
extern const char lbl_880D1DF8[];
extern const char lbl_880D1E00[];
unsigned int strlen(const char *s);
void *ts4_memset(void *dst, int c, unsigned int n);
void *memcpy(void *dst, const void *src, unsigned int n);

void fn_8899FA00(SlotOwner *o, int index, unsigned char taken)
{
    SlotCounters *c = &g_ts4_session_context->state->slots;
    const char *label;
    char *dst;
    EventSlot *ev;
    {
        int used = c->used;
        int free = c->free;
        if (taken == 1) {
            used++;
            free--;
        } else {
            used--;
            free++;
        }
        c->used = used;
        c->free = free;
    }
    if (taken == 1)
        label = lbl_880D1DF8;
    else
        label = lbl_880D1E00;
    dst = ((SlotEntry *)((char *)o->table + o->table->off))[index].label;
    ts4_memset(dst, 0, 16);
    memcpy(dst, label, (int)strlen(label) + 1);
    ev = &g_ts4_session_context->state->event;
    ev->hash = 0xA0BDE62E;
    ev->value = 1;
    ev->pending = 1;
}
