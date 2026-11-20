/* 0x886CEA10: selects entry idx: the entry's frame (truncated) is stepped back past the state's last two frames,
 * published to the host (dirty flag + frame), the entry's slot id is looked up (12-byte records) and stored in the
 * state, then fn_886CE700 (host system +0x68, slot id, state) is run. */
typedef struct Entry { char p[0xe]; unsigned short slot; char p2[0x18 - 0x10]; float frame; } Entry;
typedef struct SlotRec { int id; int a, b; } SlotRec;
typedef struct SlotTable { char p[0x14]; SlotRec *recs; } SlotTable;
typedef struct State { char p[0x400]; int last_frame; int prev_frame; char p2[0x448 - 0x408]; int slot_id; } State;
typedef struct Host { char p[0x10]; char *sys; char p2[0x5f8 - 0x14]; int *frame_out; unsigned char *dirty; } Host;
typedef struct Player {
    Host *host; SlotTable *slots; char p8[4]; State *state; char p10[0x30 - 0x10];
    Entry *entries[2]; int current;
} Player;
void fn_886CE700(void *sys, int slot_id, State *st);
void ts4_player_select_entry(Player *self, int idx)
{
    Entry *e;
    int frame, id;
    self->current = idx;
    e = self->entries[idx];
    frame = (int)e->frame;
    if (self->state->prev_frame == frame) frame--;
    if (self->state->last_frame == frame) frame--;
    *self->host->dirty = 1;
    *self->host->frame_out = frame;
    id = self->slots->recs[e->slot].id;
    self->state->slot_id = id;
    fn_886CE700(self->host->sys + 0x68, id, self->state);
}
