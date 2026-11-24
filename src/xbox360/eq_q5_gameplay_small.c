/* Q5 gameplay small functions closed by the equivalence route (fn_equiv).
 * See work/specs/Q5/eq_q5_gameplay_small.json and its .equiv.json evidence. */
typedef unsigned int u32;
typedef unsigned char u8;

/* ---- 0x888868E0: clear the active flag, set the global mode to 4, move the tail list.
 * Not byte-matched: the target reuses r11 for both the 0 and 4 constants. */
typedef struct Q5TailList { u32 head; } Q5TailList;
typedef struct Q5TailOwner {
    char pad0[8];
    u8 active;          /* +0x08 */
    char pad9[7];
    Q5TailList tail;    /* +0x10 */
} Q5TailOwner;
extern u32 lbl_88C6A45C;
extern void ts4_vec204_move_tail_881B9148(Q5TailList *list);

/* Swing_DLL.xex 0x888868E0 */
/* byte-gap: 4 off; target reuses r11 for both the 0 and 4 constants */
void ts4_deactivate_move_tail_888868E0(Q5TailOwner *self)
{
    self->active = 0;
    lbl_88C6A45C = 4;
    ts4_vec204_move_tail_881B9148(&self->tail);
}

/* ---- 0x8865C2D8: clear the two dirty bytes of a record header and
 * snapshot the current values of the record it points at (relative offset). */
typedef struct Q5RecBody {
    char pad0[0xc];
    u32 cur_a;          /* +0x0c */
    char pad10[4];
    u32 prev_a;         /* +0x14 */
    char pad18[0xc];
    u32 cur_b;          /* +0x24 */
    char pad28[4];
    u32 prev_b;         /* +0x2c */
} Q5RecBody;
typedef struct Q5RecHdr {
    int body_off;       /* +0x00, relative to the header */
    char pad4[0xe];
    u8 dirty_a;         /* +0x12 */
    u8 dirty_b;         /* +0x13 */
} Q5RecHdr;
typedef struct Q5RecData { char pad0[0x24]; Q5RecHdr hdr; } Q5RecData;
typedef struct Q5RecOwner { char pad0[8]; Q5RecData *data; } Q5RecOwner;

/* Swing_DLL.xex 0x8865C2D8 */
/* byte-gap: 9 off; reason not recorded */
void ts4_rec_clear_dirty_snapshot_8865C2D8(Q5RecOwner *self)
{
    Q5RecHdr *h = &self->data->hdr;
    Q5RecBody *b = (Q5RecBody *)((char *)h + h->body_off);
    h->dirty_a = 0;
    h->dirty_b = 0;
    b->prev_a = b->cur_a;
    b->prev_b = b->cur_b;
}
