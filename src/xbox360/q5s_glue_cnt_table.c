/* Countdown tables: arrays of {id, next id, count} records. When the current
 * id matches a record, mode 1 counts the record down, and a record at zero
 * advances the current id to its successor. Three copies in the image.
 * Matched byte-exact on the LTCG route (/Oc, pool primer context). */

typedef unsigned int ts4_u32;

typedef struct TS4CountdownEntry {
    ts4_u32 id;      /* +0x0 id this record applies to */
    ts4_u32 next_id; /* +0x4 id to switch to once the count reaches zero */
    int count;       /* +0x8 remaining count */
} TS4CountdownEntry;

/* Returning the address keeps the clrrwi copy of the entry pointer that the
 * target uses for the decrement. */
static __inline int *ts4_countdown_count_ptr(TS4CountdownEntry *e)
{
    return &e->count;
}

/* 0x88922EA8 */
void ts4_countdown_table_step_88922EA8(ts4_u32 *cur, TS4CountdownEntry *e, ts4_u32 n, int mode)
{
    ts4_u32 i;
    if (e == 0)
        return;
    if (n == 0)
        return;
    for (i = 0; i < n; i++, e++) {
        if (*cur == e->id) {
            if (mode == 1 && e->count > 0)
                --*ts4_countdown_count_ptr(e);
            if (e->count == 0)
                *cur = e->next_id;
        }
    }
}

/* 0x88922F10: signed variant; the current id is read once before the loop. */
void ts4_countdown_table_step_cached_88922F10(int *cur, TS4CountdownEntry *e, ts4_u32 n, int mode)
{
    int c = *cur;
    ts4_u32 i;
    if (e == 0)
        return;
    if (n == 0)
        return;
    for (i = 0; i < n; i++, e++) {
        if (c == (int)e->id) {
            if (mode == 1 && e->count > 0)
                --*ts4_countdown_count_ptr(e);
            if (e->count == 0)
                *cur = (int)e->next_id;
        }
    }
}

/* 0x88925320: identical body to 0x88922EA8. */
void ts4_countdown_table_step_88925320(ts4_u32 *cur, TS4CountdownEntry *e, ts4_u32 n, int mode)
{
    ts4_u32 i;
    if (e == 0)
        return;
    if (n == 0)
        return;
    for (i = 0; i < n; i++, e++) {
        if (*cur == e->id) {
            if (mode == 1 && e->count > 0)
                --*ts4_countdown_count_ptr(e);
            if (e->count == 0)
                *cur = e->next_id;
        }
    }
}
