/* 0x888F56E0: commit a pending state change (next != cur, or flag dirty): special-case state 0x1DCA7285, clear dirty, shift prev<-cur<-next, recompute (agAY). Plain /Oc; flag is tested as an int handle (cmpwi). */
typedef unsigned char u8;
typedef struct Flag { u8 pad[0xc]; u8 dirty; } Flag;
typedef struct St {
    u8 pad[0x1c]; Flag *flag; unsigned *next; unsigned *cur; unsigned *prev; u8 sub[4];
} St;
unsigned ts4_loop_get_u32_off8_881878A0(void *p);
void ts4_reltbl_store_computed_byte_888F5650(St *o);
void ts4_state_commit_next_888F56E0(St *o)
{
    unsigned n;
    if ((int)o->flag == 0) return;
    {
    if (*o->next == *o->cur && !o->flag->dirty) return;
    n = *o->next;
    if (n == 0x1DCA7285) ts4_loop_get_u32_off8_881878A0(o->sub);
    o->flag->dirty = 0;
    *o->prev = *o->cur;
    *o->cur = *o->next;
    ts4_reltbl_store_computed_byte_888F5650(o);
    }
}
