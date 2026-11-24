/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x888868E0: clear the active flag, set the global mode to 4, move the tail list.
 * Body unchanged from the equivalent-tier source named below (Q5S sweep, 2026-11-24): byte-exact now, see
 * work/specs/Q5S/sweep_888868E0.json for route and flags. */
/* from eq_q5_gameplay_small.c */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Q5TailList { u32 head; } Q5TailList;
typedef struct Q5TailOwner {
    char pad0[8];
    u8 active;          /* +0x08 */
    char pad9[7];
    Q5TailList tail;    /* +0x10 */
} Q5TailOwner;
extern u32 lbl_88C6A45C;
extern void ts4_vec204_move_tail_881B9148(Q5TailList *list);

void ts4_deactivate_move_tail_888868E0(Q5TailOwner *self)
{
    self->active = 0;
    lbl_88C6A45C = 4;
    ts4_vec204_move_tail_881B9148(&self->tail);
}
