/* CX33: net/lobby helpers (Swing_DLL.xex 0x8890xxxx - 0x8891xxxx). */
typedef unsigned char u8;
typedef unsigned int u32;

/* ---- pending-item queue ---- */
typedef struct Cx33Queue { u32 *first; u32 *last; } Cx33Queue;
typedef struct Cx33Pend { u8 pad[0x20]; Cx33Queue q; u8 pad28[0x38 - 0x28]; u8 b38; } Cx33Pend;
extern void ts4_vec_erase_one_881AAE10(Cx33Queue *q, u32 *it);
extern void fn_88908070(Cx33Pend *p, u32 item);

/* 0x88908258: when armed, pop the first queued item and process it */
void ts4_pending_pop_first_88908258(Cx33Pend *p)
{
    if (p->b38 == 1) {
        Cx33Queue *q = &p->q;
        u32 *it = q->first;
        if (it != q->last) {
            u32 item = *it;
            ts4_vec_erase_one_881AAE10(q, it);
            fn_88908070(p, item);
        }
    }
}

